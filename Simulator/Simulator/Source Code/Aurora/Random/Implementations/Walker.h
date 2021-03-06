#ifndef NatureOfCodeCocos2DX_Walker_h
#define NatureOfCodeCocos2DX_Walker_h

#include "..\BaseClasses\ObjectBase.h"
#include "..\..\Physics\PhysicsOperations.h"



namespace Aurora {
	namespace Random {
		using namespace Aurora::Math;
		using namespace Aurora::Math::DataTypes;
		using namespace Aurora::Physics;
		class Walker : public RandomBaseComplete, public IPhysicsImplementor<float>
		{

		private:
			Vector2D<float> position;
			Vector2D<float> target;
			Vector3DFloat perlinNoiseTime_PositionX;
			Vector3DFloat perlinNoiseTime_PositionY;
			Float probalitityFactor;

			void MoveWalkerTowardsTarget();
			
			void Constrain() final;

			void UniformCalculations() final;

			void GaussianCalculations() final;

			void PerlinNoiseCalculations() final;

			void NormalCalculations() final;

			virtual void init() override;
			virtual void init(const Walker &value);
			virtual void init(const mRECT<float> &areaSize, const Vector2D<float> &walkerStartPosition);

		public:
			Walker();
			Walker(const mRECT<float> &areaSize);
			Walker(const Walker &value);
			Walker(const mRECT<float> &areaSize, const Vector2D<float> &walkerStartPosition);
			~Walker();
			Walker(Walker &&value);
			Walker & operator=(Walker && value);
			Walker& operator=(const Walker& value);

			void SetTarget(const Vector2D<float> &target);
			const Vector2D<float> GetCurentPosition() const;
			void SetPosition(const Vector2D<float> &position);
			void SetProbalitiyFactor(Float probalitityFactor);

			

		};

		
		class IWalkerImplementor : public IObjectBaseBasic, public IPhysicsAccessPoint<float>
		{
		private:
			/*virtual void init() override;
			virtual void init(const mRECT &areaSize) = 0;
			virtual void init(const IWalker &value) = 0;*/
		public:
			//std::shared_ptr<Walker> WalkerObject = 0;
			IWalkerImplementor() = default;
			/*IWalker(const IWalker &value);
			IWalker(const mRECT &areaSize);*/
			virtual ~IWalkerImplementor() = default;
			/*IWalker(IWalker &&value);
			IWalker & operator=(IWalker && value);
			IWalker& operator=(const IWalker& value);*/
			virtual void Render() override;

			

			virtual void SetWalkerRandomNumberMode(RandomNumberMode randomNumberMode);
			virtual void RenderWalkerByPosition(const Vector2D<float> &position);
			virtual void SetWalkerTarget(const Vector2D<float> &target);
			virtual void StepWalker();

			virtual std::shared_ptr<Physics::Force<float>> AccessObjectPhysics() const override;

			

			

			//virtual void StepWalkerByTarget(const VECTOR2D &target) = 0;
		};

		

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif