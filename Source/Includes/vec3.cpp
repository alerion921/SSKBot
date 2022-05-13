//#include "default_includes.h"
#include "vec3.h"

namespace VectorSSE
{

Vector3SP::Vector3SP()
{
	ssevalue = _mm_setzero_ps();
}

Vector3SP::Vector3SP( const float * lpfloat)
{
	ssevalue = _mm_load_ps(lpfloat);
}

Vector3SP::Vector3SP( const D3DVECTOR& vec )
{
	ssevalue = _mm_setr_ps(vec.x, vec.y, vec.z, 0.0f);
}

Vector3SP::Vector3SP( float x, float y, float z )
{
	ssevalue = _mm_setr_ps(x, y, z, 0.0f);
}

Vector3SP::Vector3SP(__m128 m)
{	
	ssevalue = m;						
}
Vector3SP::Vector3SP(float m)
{	
	ssevalue = _mm_set_ps1(m);			
}
Vector3SP::Vector3SP(double m)
{	
	ssevalue = _mm_set_ps1(float(m));	
}

Vector3SP& Vector3SP::operator = (float value)	
{	
	ssevalue = _mm_set_ps1(value); 
	return *this;	
}
Vector3SP& Vector3SP::operator = (double value)
{	
	ssevalue = _mm_set_ps1((float)value); 
	return *this;	
}
Vector3SP& Vector3SP::operator = (const Vector3SP &v)	
{	
	ssevalue = v.ssevalue; 
	return *this;	
}
Vector3SP& Vector3SP::operator = (const __m128 &v)	
{	
	ssevalue = v; 
	return *this;	
}

Vector3SP& Vector3SP::operator+=( const Vector3SP& vec )
{
	this->ssevalue = _mm_add_ps(this->ssevalue, vec.ssevalue);
	return *this;
}

Vector3SP& Vector3SP::operator-=( const Vector3SP& vec )
{
	this->ssevalue = _mm_sub_ps(this->ssevalue, vec.ssevalue);
	return *this;
}

Vector3SP& Vector3SP::operator*=( float value )
{
	__m128 t = _mm_set_ps1(value);
	this->ssevalue = _mm_mul_ps(this->ssevalue, t);
	return *this;
}

Vector3SP& Vector3SP::operator/=( float value )
{
	__m128 t = _mm_set_ps1(value);
	this->ssevalue = _mm_div_ps(this->ssevalue, t);
	return *this;
}

//Vector3SP Vector3SP::operator+() const
//{
//	return ssevalue;
//}

//Vector3SP Vector3SP::operator-() const
//{
//	Vector3SP temp;
//	temp.x = -x;
//	temp.y = -y;
//	temp.z = -z;
//	return temp;
//}

Vector3SP operator+( const Vector3SP& vec1, const Vector3SP& vec2)
{
	return _mm_add_ps(vec1.ssevalue, vec2.ssevalue);
}
Vector3SP operator-( const Vector3SP& vec1, const Vector3SP& vec2)
{
	return _mm_sub_ps(vec1.ssevalue, vec2.ssevalue);
}

Vector3SP Vector3SP::operator*( float value ) const
{
	__m128 t;
	t = _mm_set_ps1(value);
	return _mm_mul_ps(this->ssevalue, t);
}

Vector3SP Vector3SP::operator/( float value ) const
{
	__m128 t;
	t = _mm_set_ps1(value);
	return _mm_div_ps(this->ssevalue, t);
}

bool Vector3SP::operator==( const Vector3SP& vec ) const
{
	__m128 t = _mm_cmpeq_ps(this->ssevalue, vec.ssevalue);
	int* p = (int*)&t;

	return (p[0] == -1) && (p[1] == -1) && (p[2] == -1);
}

bool Vector3SP::operator!=( const Vector3SP& vec ) const
{
	__m128 t = _mm_cmpeq_ps(this->ssevalue, vec.ssevalue);
	int* p = (int*)&t;

	return (p[0] != -1) || (p[1] != -1) || (p[2] != -1);
}

Vector3SP operator*( float value, const Vector3SP& vec )
{
	__m128 t;
	t = _mm_set_ps1(value);
	return _mm_mul_ps(t, vec.ssevalue);
}

__m128 Vector3SP::add_horizontal(const __m128 &v)
{
	return _mm_add_ss(v, _mm_add_ss(_mm_shuffle_ps(v, v, 1), _mm_shuffle_ps(v, v, 2)));
}

float Vector3SP::VecLength()
{
	__m128 x2 = _mm_mul_ps(ssevalue, ssevalue);
	__m128 horz_add = add_horizontal(x2);
	__m128 result = _mm_sqrt_ss(horz_add);

	return ((float*)&result)[0];
}

float Vector3SP::DotProduct( const Vector3SP& vec)
{
	__m128 xx = _mm_mul_ps(ssevalue, vec.ssevalue);
	__m128 horz_add = add_horizontal(xx);

	return ((float*)&horz_add)[0];
}

Vector3SP Vector3SP::CrossProduct( const Vector3SP& vec) const
{
	// 0 z y x -> 0 x z y
	__m128 v1 = _mm_shuffle_ps(ssevalue, ssevalue, _MM_SHUFFLE(3, 0, 2, 1));
	// 0 z y x -> 0 y x z
	__m128 v2 = _mm_shuffle_ps(vec.ssevalue, vec.ssevalue, _MM_SHUFFLE(3, 1, 0, 2));
	// 0 z y x -> 0 y x z
	__m128 v3 = _mm_shuffle_ps(ssevalue, ssevalue, _MM_SHUFFLE(3, 1, 0, 2));
	// 0 z y x -> 0 x z y
	__m128 v4 = _mm_shuffle_ps(vec.ssevalue, vec.ssevalue, _MM_SHUFFLE(3, 0, 2, 1));
	
	__m128 x1 = _mm_mul_ps(v1, v2);
	__m128 x2 = _mm_mul_ps(v3, v4);
	
	__m128 result = _mm_sub_ps(x1, x2);

	return result;
}

Vector3SP Vector3SP::Normalize()
{
	__m128 x2 = _mm_mul_ps(ssevalue, ssevalue);
	__m128 horz_add = add_horizontal(x2);
	__m128 len = _mm_sqrt_ss(horz_add);
	__m128 packlen = _mm_shuffle_ps(len, len, _MM_SHUFFLE(0, 0, 0, 0));

	__m128 result = _mm_div_ps(ssevalue, packlen);

	return result;
}
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
Vector3DP::Vector3DP()
{
	ssevalue1 = ssevalue2 = _mm_setzero_pd();
}

Vector3DP::Vector3DP( const float * lpfloat)
{
	ssevalue1 = _mm_setr_pd(lpfloat[0], lpfloat[1]);
	ssevalue2 = _mm_setr_pd(lpfloat[2], 0.0);
}

Vector3DP::Vector3DP( const D3DVECTOR& vec )
{
	ssevalue1 = _mm_setr_pd(vec.x, vec.y);
	ssevalue2 = _mm_setr_pd(vec.z, 0.0);
}

Vector3DP::Vector3DP( double x, double y, double z )
{
	ssevalue1 = _mm_setr_pd(x, y);
	ssevalue2 = _mm_setr_pd(z, 0.0);
}

Vector3DP::Vector3DP(__m128d m1, __m128d m2)
{	
	ssevalue1 = m1;
	ssevalue2 = m2;
}

Vector3DP::Vector3DP(double m)
{	
	ssevalue1 = ssevalue2 = _mm_set1_pd(m);	
}

Vector3DP& Vector3DP::operator = (const Vector3DP &v)	
{	
	ssevalue1 = v.ssevalue1; 
	ssevalue2 = v.ssevalue2; 
	return *this;	
}

Vector3DP& Vector3DP::operator+=( const Vector3DP& vec )
{
	this->ssevalue1 = _mm_add_pd(this->ssevalue1, vec.ssevalue1);
	this->ssevalue2 = _mm_add_pd(this->ssevalue2, vec.ssevalue2);
	return *this;
}

Vector3DP& Vector3DP::operator-=( const Vector3DP& vec )
{
	this->ssevalue1 = _mm_sub_pd(this->ssevalue1, vec.ssevalue1);
	this->ssevalue2 = _mm_sub_pd(this->ssevalue2, vec.ssevalue2);
	return *this;
}

Vector3DP& Vector3DP::operator+=( const D3DVECTOR& vec )
{
	__m128d x1 = _mm_setr_pd(vec.x, vec.y);
	__m128d x2 = _mm_setr_pd(vec.z, 0.0);

	this->ssevalue1 = _mm_add_pd(this->ssevalue1, x1);
	this->ssevalue2 = _mm_add_pd(this->ssevalue2, x2);
	
	return *this;
}

Vector3DP& Vector3DP::operator-=( const D3DVECTOR& vec )
{
	__m128d x1 = _mm_setr_pd(vec.x, vec.y);
	__m128d x2 = _mm_setr_pd(vec.z, 0.0);

	this->ssevalue1 = _mm_sub_pd(this->ssevalue1, x1);
	this->ssevalue2 = _mm_sub_pd(this->ssevalue2, x2);

	return *this;
}

Vector3DP& Vector3DP::operator*=( double value )
{
	__m128d t = _mm_set1_pd(value);
	this->ssevalue1 = _mm_mul_pd(this->ssevalue1, t);
	this->ssevalue2 = _mm_mul_pd(this->ssevalue2, t);
	return *this;
}

Vector3DP& Vector3DP::operator/=( double value )
{
	__m128d t = _mm_set1_pd(value);
	this->ssevalue1 = _mm_div_pd(this->ssevalue1, t);
	this->ssevalue2 = _mm_div_pd(this->ssevalue2, t);
	return *this;
}

//Vector3DP Vector3DP::operator+() const
//{
//	return ssevalue1;
//}

//Vector3DP Vector3DP::operator-() const
//{
//	Vector3DP temp;
//	temp.x = -x;
//	temp.y = -y;
//	temp.z = -z;
//	return temp;
//}

Vector3DP operator+( const Vector3DP& vec1, const Vector3DP& vec2)
{
	Vector3DP tmp(	_mm_add_pd(vec1.ssevalue1, vec2.ssevalue1),
					_mm_add_pd(vec1.ssevalue2, vec2.ssevalue2));
	return tmp;
}
Vector3DP operator-( const Vector3DP& vec1, const Vector3DP& vec2)
{
	Vector3DP tmp(	_mm_sub_pd(vec1.ssevalue1, vec2.ssevalue1),
					_mm_sub_pd(vec1.ssevalue2, vec2.ssevalue2));
	return tmp;
}

Vector3DP Vector3DP::operator*( double value ) const
{
	__m128d t = _mm_set1_pd(value);
	Vector3DP tmp(_mm_mul_pd(this->ssevalue1, t), _mm_mul_pd(this->ssevalue2, t));
	
	return tmp;
}

Vector3DP Vector3DP::operator/( double value ) const
{
	__m128d t = _mm_set1_pd(value);
	Vector3DP tmp(_mm_div_pd(this->ssevalue1, t), _mm_div_pd(this->ssevalue2, t));
	return tmp;
}

//bool Vector3DP::operator==( const Vector3DP& vec ) const
//{
//	__m128d t = _mm_cmpeq_pd(this->ssevalue1, vec.ssevalue1);
//	int* p = (int*)&t;
//
//	return (p[0] == -1) && (p[1] == -1) && (p[2] == -1);
//}
//
//bool Vector3DP::operator!=( const Vector3DP& vec ) const
//{
//	__m128 t = _mm_cmpeq_pd(this->ssevalue1, vec.ssevalue1);
//	int* p = (int*)&t;
//
//	return (p[0] != -1) || (p[1] != -1) || (p[2] != -1);
//}

Vector3DP operator*( double value, const Vector3DP& vec )
{
	__m128d t = _mm_set1_pd(value);
	Vector3DP tmp(_mm_mul_pd(t, vec.ssevalue1), _mm_mul_pd(t, vec.ssevalue2));
	return tmp;
}

__m128d Vector3DP::add_horizontal(const __m128d *v) const
{
	__m128d x1 = _mm_add_sd(v[0], _mm_shuffle_pd(v[0], v[0], 1));
	x1 = _mm_add_sd(x1, v[1]);
	return x1;
}

double Vector3DP::VecLength()
{
	__m128d x2[] = {_mm_mul_pd(ssevalue1, ssevalue1), _mm_mul_pd(ssevalue2, ssevalue2)};
	
	__m128d horz_add = add_horizontal(x2);
	__m128d result = _mm_sqrt_sd(horz_add, horz_add);

	return ((double*)&result)[0];
}

double Vector3DP::DotProduct( const Vector3DP& vec)
{
	__m128d xx[] = {_mm_mul_pd(ssevalue1, vec.ssevalue1), _mm_mul_pd(ssevalue2, vec.ssevalue2)};
	__m128d horz_add = add_horizontal(xx);

	return ((double*)&horz_add)[0];
}

Vector3DP Vector3DP::CrossProduct( const Vector3DP& vec) const
{
	//  v.x = pV1->y * pV2->z - pV1->z * pV2->y;
	//	v.y = pV1->z * pV2->x - pV1->x * pV2->z;
	//	v.z = pV1->x * pV2->y - pV1->y * pV2->x;

	__m128d v1 = _mm_shuffle_pd(ssevalue1, ssevalue2, _MM_SHUFFLE2(0, 1));
	__m128d v2 = _mm_shuffle_pd(vec.ssevalue2, vec.ssevalue1, _MM_SHUFFLE2(0, 0));
	__m128d v3 = _mm_shuffle_pd(ssevalue2, ssevalue1, _MM_SHUFFLE2(0, 0));
	__m128d v4 = _mm_shuffle_pd(vec.ssevalue1, vec.ssevalue2, _MM_SHUFFLE2(0, 1));
	__m128d v5 = _mm_shuffle_pd(ssevalue1, ssevalue2, _MM_SHUFFLE2(1, 0));
	__m128d v6 = _mm_shuffle_pd(vec.ssevalue1, vec.ssevalue2, _MM_SHUFFLE2(1, 1));
	__m128d v7 = _mm_shuffle_pd(ssevalue1, ssevalue2, _MM_SHUFFLE2(1, 1));
	__m128d v8 = _mm_shuffle_pd(vec.ssevalue1, vec.ssevalue2, _MM_SHUFFLE2(1, 0));

	__m128d x11 = _mm_mul_pd(v1, v2);
	__m128d x12 = _mm_mul_pd(v3, v4);
	__m128d x21 = _mm_mul_pd(v5, v6);
	__m128d x22 = _mm_mul_pd(v7, v8);

	__m128d result1 = _mm_sub_pd(x11, x12);
	__m128d result2 = _mm_sub_pd(x21, x22);

	return Vector3DP(result1, result2);
}

Vector3DP Vector3DP::Normalize() const
{
	__m128d x2[] = {_mm_mul_pd(ssevalue1, ssevalue1), _mm_mul_pd(ssevalue2, ssevalue2)};
	__m128d horz_add = add_horizontal(x2);
	__m128d len = _mm_sqrt_sd(horz_add, horz_add);
	__m128d packlen = _mm_shuffle_pd(len, len, _MM_SHUFFLE2(0, 0));

	Vector3DP result(_mm_div_pd(ssevalue1, packlen), _mm_div_pd(ssevalue2, packlen));

	return result;
}

Vector3DP& Vector3DP::Normalized()
{
	__m128d x2[] = {_mm_mul_pd(ssevalue1, ssevalue1), _mm_mul_pd(ssevalue2, ssevalue2)};
	__m128d horz_add = add_horizontal(x2);
	__m128d len = _mm_sqrt_sd(horz_add, horz_add);
	__m128d packlen = _mm_shuffle_pd(len, len, _MM_SHUFFLE2(0, 0));

	ssevalue1 = _mm_div_pd(ssevalue1, packlen);
	ssevalue2 = _mm_div_pd(ssevalue2, packlen);

	return *this;
}

Vector3DP::operator D3DVECTOR() const
{
	__m128 x1 = _mm_cvtpd_ps(ssevalue1);
	__m128 x2 = _mm_cvtpd_ps(ssevalue2);
	
	D3DVECTOR r;
	_mm_store_ss(&r.x, x1);
	x1 = _mm_shuffle_ps(x1, x1, _MM_SHUFFLE(3, 3, 3, 1));
	_mm_store_ss(&r.y, x1);
	_mm_store_ss(&r.z, x2);

	return r;
}

}
