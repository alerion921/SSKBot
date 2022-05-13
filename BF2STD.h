#include <string>
using namespace std;

//BF2 STD Library
namespace dice
{
	namespace std
	{
		class string
		{
		public:

			enum
			{
				_BUF_SIZE = 16 / sizeof (char) < 1 ? 1 : 16 / sizeof(char),
				_ALLOC_MASK = sizeof (char) <= 1 ? 15 : sizeof (char) <= 2 ? 7 : sizeof (char) <= 4 ? 3 : sizeof (char) <= 8 ? 1 : 0,
			};

			string() : _Alval(allocator<char>::template rebind<char>::other())
			{
				_Tidy();
			}

			string(const char* _Ptr) : _Alval(allocator<char>::template rebind<char>::other())
			{
				_Tidy();
				assign(_Ptr, char_traits<char>::length(_Ptr));
			}

			~string()
			{
				_Tidy(true);
			}

			const char* c_str() const
			{
				return (_Myptr());
			}

			const char* _Myptr() const
			{
				return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
			}

			void  _Tidy(bool _Built = false, allocator<char>::size_type _Newsize = 0)
			{
				if (!_Built)
				{
				}
				else if (_BUF_SIZE <= _Myres)
				{
					char* _Ptr = _Bx._Ptr;

					if (0 < _Newsize)
						copy(_Bx._Buf, _Ptr, _Newsize);

					_Alval.deallocate(_Ptr, _Myres + 1);
				}

				_Myres = _BUF_SIZE - 1;
				_Eos(_Newsize);
			}

			string& assign(const char* _Ptr, allocator<char>::size_type _Count)
			{
				if (_Grow(_Count))
				{
					copy((char*)_Myptr(), _Ptr, _Count);
					_Eos(_Count);
				}

				return (*this);
			}

			bool _Grow(allocator<char>::size_type _Newsize, bool _Trim = false)
			{
				if (max_size() < _Newsize)
				{
					//_Xlength_error("string too long");	
				}

				if (_Myres < _Newsize)
				{
					_Copy(_Newsize, _Mysize);
				}
				else if (_Trim && _Newsize < _BUF_SIZE)
				{
					_Tidy(true, _Newsize < _Mysize ? _Newsize : _Mysize);
				}
				else if (_Newsize == 0)
				{
					_Eos(0);
				}

				return (0 < _Newsize);
			}

			allocator<char>::size_type max_size() const
			{
				return (_Alval.max_size() <= 1 ? 1 : _Alval.max_size() - 1);
			}

			static char* copy(char* _First1, const char* _First2, size_t _Count)
			{
			return ((char *)_CSTD memcpy(_First1, _First2, _Count));
			}

			void _Copy(allocator<char>::size_type _Newsize, allocator<char>::size_type _Oldlen)
			{
				allocator<char>::size_type _Newres = _Newsize | _ALLOC_MASK;

				if (max_size() < _Newres)
				{
					_Newres = _Newsize;
				}
				else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
				{
					_Newres = _Myres + _Myres / 2;
				}

				char *_Ptr = 0;

				_TRY_BEGIN
					_Ptr = _Alval.allocate(_Newres + 1);
				_CATCH_ALL
					_Newres = _Newsize;
				_TRY_BEGIN
					_Ptr = _Alval.allocate(_Newres + 1);
				_CATCH_ALL
					_Tidy(true);
				_RERAISE;
				_CATCH_END
					_CATCH_END

				if (0 < _Oldlen)
					copy(_Ptr, _Myptr(), _Oldlen);

				_Tidy(true);
				_Bx._Ptr = _Ptr;
				_Myres = _Newres;
				_Eos(_Oldlen);
			}

			void _Eos(allocator<char>::size_type _Newsize)
			{
				char_traits<char>::assign((char)_Myptr()[_Mysize = _Newsize], char());
			}

			bool _Inside(const char* _Ptr)
			{
				if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
					return false;

				return true;
			}

		protected:

			allocator<char>::template rebind<char>::other _Alval;

			union _Bxty
			{
				char _Buf[_BUF_SIZE];
				char* _Ptr;
			} _Bx;

			allocator<char>::size_type _Mysize;
			allocator<char>::size_type _Myres;
		};

		template <class T, class Y>
		struct map
		{
			struct iterator
			{
				friend struct map;

				struct node
				{
					friend struct map;

				protected:
					node* _Left;
					node* _Parent;
					node* _Right;
				public:
					T first;
					Y second;
				protected:
					char _Unknown0;
					char _isHead;
				};

			protected:
				node* _Ptr;
			public:
				iterator(node* _Node) : _Ptr(_Node) { }

				bool operator == (const iterator& it) { return _Ptr == it._Ptr; }
				bool operator != (const iterator& it) { return _Ptr != it._Ptr; }

				node* operator ->()
				{
					return _Ptr;
				}

				node operator *()
				{
					return *_Ptr;
				}

				iterator& operator++(int)
				{
					node* _Node = _Ptr->_Right;

					if (!_Node->_isHead)
					{
						while (!_Node->_Left->_isHead)
							_Node = _Node->_Left;
					}
					else {
						while (!(_Node = _Ptr->_Parent)->_isHead && _Ptr == _Node->_Right)
							_Ptr = _Node;
					}

					_Ptr = _Node;
					return *this;
				}
			};
		protected:
			char _Unknown0[4];
			iterator _Head;
			unsigned long _Size;
		public:

			iterator begin()
			{
				return iterator(_Head._Ptr->_Left);
			}

			iterator end()
			{
				return iterator(_Head._Ptr);
			}

			unsigned long size()
			{
				return _Size;
			}
		};

		template <class T>
		struct list
		{
			struct iterator
			{
				class node
				{
					friend struct list;
				protected:
					node* _Left;
					node* _Right;
				public:
					T _Data;
				};

				friend struct list;

			protected:
				node* _Ptr;
			public:

				iterator(node* _Node) : _Ptr(_Node) { }

				bool operator == (const iterator& it) { return _Ptr == it._Ptr; }
				bool operator != (const iterator& it) { return _Ptr != it._Ptr; }

				node* operator ->()
				{
					return _Ptr;
				}

				T& operator *()
				{
					return _Ptr->_Data;
				}

				iterator& operator++(int)
				{
					_Ptr = _Ptr->_Right;
					return *this;
				}
			};

		protected:
			char _Unknown0[4];
			iterator _Head;
			unsigned long _Size;
		public:
			iterator begin()
			{
				return iterator(_Head._Ptr->_Right);
			}

			iterator end()
			{
				return iterator(_Head._Ptr);
			}

			unsigned long size()
			{
				return _Size;
			}
		};

		template <class T>
		struct vector
		{
			void* unk0;
			void* unk1;
			void* unk2;
			void* unk3;
		};
	};
};

namespace hfe
{
	namespace world
	{
		enum VehicleCategory : int
		{
			VCLand = 0,
			VCSea = 1,
			VCAir = 2,
			VCHelicopter = 3,
			VCNoVehicleCategory = 4,
		};

		enum VehicleType : int
		{
			VTTank = 0,
			VTAPC = 1,
			VTHelicopter = 2,
			VTJeep = 3,
			VTPlane = 4,
			VTAntiAir = 5,
			VTSea = 6,
		};

		enum PlayerKit : int
		{
			KTSpecialOps = 0,
			KTSniper = 1,
			KTAssult = 2,
			KTSuport = 3,
			KTEngineer = 4,
			KTMedic = 5,
			KTAntiTank = 6,
		};

		enum TargetSystem : int
		{
			TSNone = 0,
			TSHeatSeeking = 1,
			TSLaserGuided = 2,
			TSWireGuided = 3,
			TSTVGuided = 4,
			TSParabellic = 5,
		};

		enum ToolTipType
		{
		};
	}
}

namespace world
{
#define CID_IPLAYERCONTROLOBJECT	0xC4C5
#define CID_SOLDIER					0xC4D7

	namespace Object
	{
		enum : int
		{
			isRoot = 0x1, /* not sure */
			isVisible = 0x2,
			hasCollision = 0x100,
			isInGrid = 0x400,
			hasUpdate = 0x800,
			isSaveable = 0x2000,
			isInTweakMode = 0x10000,
		};
	}
	namespace ObjectTemplate
	{
		enum : int
		{
			Bundle = 0x9471,
			Camera = 0x9472,
			EffectBundle = 0x9474,
			Emitter = 0x9475,
			Engine = 0x9476,
			EntryPoint = 0x9477,
			FloatingBundle = 0x9478,
			Particle = 0x947B,
			RotationalBundle = 0x947D,
			SimpleObject = 0x947E,
			SpriteParticle = 0x9480,
			Spring = 0x9481,
			Wing = 0x9483,
			WheelEffectBundle = 0x9484,
			AirDraftEffectBundle = 0x9485,
			GroundEffectBundle = 0x9486,
			Decal = 0x9487,
			EnvMap = 0x9488,
			ForceObject = 0x9489,
			FreeCamera = 0x948B,
			OverheadCamera = 0x948C,
			Item = 0x9492,
			Soldier = 0x9493,
			Kit = 0x9496,
			MaskObject = 0x9497,
			ItemContainer = 0x9499,
			Flag = 0x949A,
			AnimatedBundle = 0x949C,
			AntennaObject = 0x949D,
			KitPart = 0x94A3,
			SupplyDepot = 0x94A4,
			ControlPoint = 0x94A5,
			LandingGear = 0x94AE,
			Obstacle = 0x94AF,
			AreaObject = 0x94B3,
			TargetObject = 0x94BE,
			LightSource = 0x94C7,
			Rotor = 0x94CB,
			SpriteParticleSystem = 0x94CF,
			MeshParticleSystem = 0x94D0,
			TrailSystem = 0x94D1,
			ParticleSystemEmitter = 0x94D2,
			GenericFireArm = 0x94D3,
			NonScreenAlignedParticleSystem = 0x9537,
			GenericProjectile = 0x9539,
			Ladder = 0x9C40,
			DynamicBundle = 0x9C41,
			RemoteControlledObject = 0x9C42,
			TurnableRemoteControlledObject = 0x9C43,
			AmbientEffectArea = 0x9C44,
			Trigger = 0x9C45,
			LadderContainer = 0x9C46,
			SupplyObject = 0x9C47,
			ZiplineContainer = 0x9C48,
			Zipline = 0x9C49,
			Triggerable = 0x9C4A,
			ZiplineRope = 0x9C4C,
			GrapplingHookRope = 0x9C4D,
			RopeLink = 0x9C4E,
			GrapplingHookRopeContainer = 0x9C4F,
			TriggerableTarget = 0x9C50,
			HookLink = 0x9C51,
			UAVVehicle = 0x9C53,
			DropVehicle = 0x9C54,
			PlayerControlObject = 0x0C4C2,
			DestroyableObject = 0x0C4D0,
			DestroyableWindowsBundle = 0x0C4DC,
			DestroyableWindow = 0x0C4DD,
			Parachute = 0x0C5A8,
		};
		enum : int
		{
			saveInSeparateFile = 0x1,
			createNotInGrid = 0x2,
			createInvisible = 0x4,
			createVisibleInEditor = 0x8,
			isNotSaveable = 0x10,
			templateHasBeenUsed = 0x20,
			createdInEditor = 0x80,
			isDestructable = 0x200,
			castsDynamicShadow = 0x800,
			hasRelativeOffset = 0x1000,
		};
	}
	namespace TemplateComponent
	{
		enum : int
		{
			SingleFireComp = 0x94DB,
			MultiFireComp = 0x94DC,
			LPFireComp = 0x94DD,
			ThrownFireComp = 0x94DE,
			ExplosivesFireComp = 0x94DF,
			DefaultAmmoComp = 0x94E0,
			SoldierDeviationComp = 0x94E1,
			SimpleDeviationComp = 0x94E2,
			SoldierBasedRecoilComp = 0x94E3,
			WeaponBasedRecoilComp = 0x94E4,
			DefaultZoomComp = 0x94E5,
			ToggleCameraComp = 0x94E6,
			DefaultSoundComp = 0x94E7,
			DefaultAnimationComp = 0x94E8,
			ThrownAnimationComp = 0x94E9,
			MultiFireArmTargetComp = 0x94EA,
			LPTargetComp = 0x94EB,
			SimpleTargetComp = 0x94EC,
			ReplenishingAmmoComp = 0x94ED,
			TargetDeviationComp = 0x94EE,
			SpawnObjectFireComp = 0x94EF,
			DefaultCollisionComp = 0x953A,
			DefaultDetonationComp = 0x953B,
			DefaultProjSoundComp = 0x953C,
			DefaultRicochetComp = 0x953D,
			DefaultPenetrateComp = 0x953E,
			SeekClosestTargetComp = 0x9540,
			FixedTargetComp = 0x9541,
			DefaultFollowComp = 0x9542,
			PreDestinedFollowComp = 0x9543,
			ReplenishCollisionComp = 0x9544,
			StickyCollisionComp = 0x9546,
			ReplenishDetonationComp = 0x9547,
			Armor = 0x0C4AA,
			Ability = 0x0C4B2,
			Radio = 0x0C4B6,
			Ik = 0x0C4CC,
			VehicleHud = 0x0C4EB,
			WeaponHud = 0x0C4EF,
			AbilityHud = 0x0C4F3,
			WarningHud = 0x0C4F7,
			HelpHud = 0x0C4FB,
			StrategicObject = 0x0C4FF,
			PostProcess = 0x0C503,
		};
	}
	namespace Networkable
	{
		enum : int
		{
			SimpleObject = 0x9858,
			RotationalBundle = 0x9859,
			FreeCamera = 0x985A,
			Soldier = 0x985B,
			Spring = 0x985C,
			Item = 0x985D,
			Kit = 0x985E,
			PlayerControlObject = 0x985F,
			ControlPoint = 0x9862,
			Engine = 0x9863,
			TargetObject = 0x986A,
			TriggerableTarget = 0x986C,
			GenericProjectile = 0x986D,
			OverheadCamera = 0x9871,
			DestroyableObject = 0x9876,
			DestroyableWindowsBundle = 0x9877,
		};
	}
}

namespace meme
{
	enum
	{
		EffectNode = 0x94A2C8,
		VariableEffectNode = 0x94A2E8,
		ShowEffectNode = 0x94A308,
		TransitionalEffectNode = 0x94A328,
		TransitionalShowEffectNode = 0x94A348,
		TransitionalHideEffectNode = 0x94A368,
		NormalToFocusEffectNode = 0x94A388,
		FocusEffectNode = 0x94A3A8,
		NotFocusEffectNode = 0x94A3C8,
		ExtendedNormalToFocusEffectNode = 0x94A3E8,
		FocusToPressedEffectNode = 0x94A408,
		ExtendedFocusToPressedEffectNode = 0x94A428,
	};
};
	enum ECCoreCE : int
	{
		ECCoreCEPostLoad = 0x3,
		ECCoreCEUpdateLoadStats = 0x4,
		ECCoreCEPreLoad = 0x5,
		ECCoreCEShutdownGame = 0x6,
		ECCoreCEResourcesLoaded = 0x7,
		ECCoreCEDebugTextHook = 0x8,
		ECCoreCECollectSystemInfo = 0x9,
		ECCoreCEStartPerformanceTest = 0xA,
		ECCoreCEStopPerformanceTest = 0xB,
		ECCoreCEReportPerformanceInfo = 0xC,
		ECCoreCEUnloadLevel = 0xD,
		ECCoreCEAbortLoadLevel = 0xE,
		ECCoreCEActivateApp = 0xF,
		ECCoreCEPeakWinMessages = 0x10,
	};

	enum ECGameGN : int
	{
		ECGameGNDestroyObject = 0x1,
		ECGameGNDestroyPlayer = 0x2,
		ECGameGNCreateObject = 0x3,
		ECGameGNCreatePlayer = 0x4,
		ECGameGNImmediateCreatePlayer = 0x5,
		ECGameGNPlayerSpawned = 0x6,
		ECGameGNSelectSpawnGroup = 0x7,
		ECGameGNPlayerDead = 0x8,
		ECGameGNEnterVehicle = 0x9,
		ECGameGNFreeCameraFire = 0xA,
		ECGameGNExitVehicle = 0xB,
	};

	enum ECNetworkNE : int
	{
		ECNetworkNEDataBlockReady = 0x1,
		ECNetworkNELoadComplete = 0x2,
		ECNetworkNEStartSimulation = 0x3,
		ECNetworkNEDatabaseComplete = 0x4,
		ECNetworkNEReset = 0x5,
		ECNetworkNESelectSpawnGroup = 0x6,
		ECNetworkNESelectTeam = 0x7,
		ECNetworkNESelectKit = 0x8,
		ECNetworkNEPlayerSpawned = 0x9,
		ECNetworkNEPlayerDead = 0xA,
		ECNetworkNEStringReceived = 0xB,
		ECNetworkNESuicide = 0xC,
		ECNetworkNERadioMessageReceived = 0xD,
		ECNetworkNETraceComplete = 0xE,
		ECNetworkNETraceFailed = 0xF,
		ECNetworkNETraceResourceConnect = 0x10,
		ECNetworkNENetworkableDestroyed = 0x11,
		ECNetworkNERemoteConsoleCommand = 0x12,
		ECNetworkNERemoteConsoleFeedback = 0x13,
		ECNetworkNEEndOfRoundGuard = 0x14,
	};

	enum ECHudHE
	{
		ECHudHECloseToControlPoint = 0x1,
		ECHudHEHudStateChanged = 0x2,
		ECHudHEMapZoomChanged = 0x9,
		ECHudHEMapStaticChanged = 0xA,
		ECHudHEHudDisable = 0x3,
		ECHudHEHudEnable = 0x4,
		ECHudHEInitLoadingScreen = 0x5,
		ECHudHEUpdateLoadingScreen = 0x6,
		ECHudHERemoveLoadingScreen = 0x8,
		ECHudHESquadIsFull = 0xB,
		ECHudHESquadIsPrivate = 0xC,
		ECHudHESquadCreationFailed = 0xD,
		ECHudHESquadCreationSuccess = 0xE,
		ECHudHESquadInvalidName = 0xF,
		ECHudHESquadInvitation = 0x10,
		ECHudHESquadJoinRequest = 0x11,
		ECHudHESquadJoinRequestDenied = 0x12,
		ECHudHESquadJoinRequestAccepted = 0x13,
		ECHudHEKickedFromSquad = 0x14,
		ECHudHELeftSquad = 0x15,
		ECHudHEJoinedSquad = 0x16,
		ECHudHESquadOrdersReceived = 0x17,
		ECHudHENewSquadLeader = 0x18,
		ECHudHESquadLeaderRequest = 0x19,
		ECHudHECommanderOrdersReceived = 0x1A,
		ECHudHECommanderOrdersSent = 0x1B,
		ECHudHERequestRecieved = 0x1D,
		ECHudHERequestSent = 0x1E,
		ECHudHESquadOrdersSent = 0x1C,
		ECHudHEUpdateHud = 0x1F,
		ECHudHEWeaponChanged = 0x20,
		ECHudHECommanderAccept = 0x21,
		ECHudHECommanderDecline = 0x22,
		ECHudHECommanderInvitation = 0x23,
		ECHudHESquadLeaderInvitation = 0x24,
		ECHudHECommanderResign = 0x25,
		ECHudHERankChange = 0x26,
		ECHudHEMedalReward = 0x27,
		ECHudHEUAV = 0x28,
		ECHudHESatellite = 0x29,
		ECHudHEArtillery = 0x2A,
		ECHudHEUnitSpotted = 0x2B,
		ECHudHEMissileLock = 0x2C,
		ECHudHENewUnlock = 0x2D,
		ECHudHECallForMedic = 0x2E,
		ECHudHECallForAmmo = 0x2F,
		ECHudHECallForRepair = 0x30,
		ECHudHECallForRevive = 0x31,
		ECHudHEAutoCallForRevive = 0x32,
		ECHudHERadioCall = 0x33,
		ECHudHEWasHit = 0x34,
		ECHudHEIsCloseToMine = 0x39,
		ECHudHENotCloseToMine = 0x3A,
		ECHudHEMutedByRemote = 0x3B,
		ECHudHETKOption = 0x3D,
		ECHudHETKResponse = 0x3E,
		ECHudHEControlPointTaken = 0x40,
		ECHudHEControlPointLost = 0x41,
		ECHudHEEnableHelpMessage = 0x42,
		ECHudHEEnableHelp = 0x43,
		ECHudHEKickBan = 0x44,
		ECHudHETicketBleed = 0x46,
		ECHudHETicketStateChanged = 0x47,
		ECHudHEBeginRound = 0x48,
		ECHudHEMapChangeComplete = 0x4C,
		ECHudHEMapZoomComplete = 0x4D,
		ECHudHEUAVVehicleDestroyed = 0x52,
	};