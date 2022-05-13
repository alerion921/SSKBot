#ifndef _VECTOR3_SSE_
#define _VECTOR3_SSE_
#include <d3dx9math.h>
#include <emmintrin.h>
#include <xmmintrin.h>
#include <mmintrin.h>

namespace VectorSSE
{

#pragma warning(disable:4201)
//_declspec(align(16))
class Vector3SP
{
public:
	__m128 ssevalue;

	Vector3SP();
	Vector3SP( const float * lpfloat);
	Vector3SP( const D3DVECTOR& vec);
	Vector3SP( float x, float y, float z );

	Vector3SP(__m128 m);
	Vector3SP(float m);
	Vector3SP(double m);

	// casting
	operator __m128 () const		{	return ssevalue;			}
	operator float* ()				{	return (float*)&ssevalue;	}
	operator const float* () const	{	return (float*)&ssevalue;	}

	// assignment operators
	Vector3SP& operator += ( const Vector3SP& vec );
	Vector3SP& operator -= ( const Vector3SP& vec );
	Vector3SP& operator *= ( float value);
	Vector3SP& operator /= ( float value);

	Vector3SP& operator = (float value);
	Vector3SP& operator = (double value);
	Vector3SP& operator = (const Vector3SP &v);
	Vector3SP& operator = (const __m128 &v);

	// unary operators
	//Vector3SP operator + () const;
	//Vector3SP operator - () const;

	// binary operators
	friend Vector3SP operator + ( const Vector3SP& vec1, const Vector3SP& vec2);
	friend Vector3SP operator - ( const Vector3SP& vec1, const Vector3SP& vec2);
	Vector3SP operator * ( float value) const;
	Vector3SP operator / ( float value) const;

	friend Vector3SP operator * ( float value, const Vector3SP& vec);

	bool operator == ( const Vector3SP& vec) const;
	bool operator != ( const Vector3SP& vec) const;

	__m128 add_horizontal(const __m128 &v);
	float VecLength();
	float DotProduct( const Vector3SP& vec);
	Vector3SP CrossProduct( const Vector3SP& vec) const;

	Vector3SP Normalize();
};

//_declspec(align(16))
class Vector3DP
{
public:
	__m128d ssevalue1;
	__m128d ssevalue2;

	Vector3DP();
	Vector3DP( const float * lpfloat);
	Vector3DP( const D3DVECTOR& vec);
	Vector3DP( double x, double y, double z );

	Vector3DP(__m128d m1, __m128d m2);
	Vector3DP(double m);

	// casting
	operator double* ()				{	return (double*)&ssevalue1;	}
	operator const double* () const	{	return (double*)&ssevalue1;	}
	operator D3DVECTOR () const;

	// assignment operators
	Vector3DP& operator += ( const Vector3DP& vec );
	Vector3DP& operator -= ( const Vector3DP& vec );
	Vector3DP& operator += ( const D3DVECTOR& vec );
	Vector3DP& operator -= ( const D3DVECTOR& vec );
	Vector3DP& operator *= ( double value);
	Vector3DP& operator /= ( double value);

	Vector3DP& operator = (const Vector3DP &v);

	// binary operators
	friend Vector3DP operator + ( const Vector3DP& vec1, const Vector3DP& vec2);
	friend Vector3DP operator - ( const Vector3DP& vec1, const Vector3DP& vec2);
	Vector3DP operator * ( double value) const;
	Vector3DP operator / ( double value) const;

	friend Vector3DP operator * ( double value, const Vector3DP& vec);

//	bool operator == ( const Vector3DP& vec) const;
//	bool operator != ( const Vector3DP& vec) const;

	__m128d add_horizontal(const __m128d *v) const;
	double VecLength();
	double DotProduct( const Vector3DP& vec);
	Vector3DP CrossProduct( const Vector3DP& vec) const;

	Vector3DP Normalize() const;
	Vector3DP& Normalized();
};

#pragma warning(default:4201)
}

#endif
