#ifndef NatureOfCodeCocos2DX_IPhysicsRepresentationBase_h
#define NatureOfCodeCocos2DX_IPhysicsRepresentationBase_h



#include "../Implementations/Force.h"



namespace Aurora {
	namespace Physics {

		/*!
		 * \class IPhysicsRepresentationBase
		 *
		 * \brief Use this to add physics data to an object and add support for physics calculations to perform calculations on the data. A more detailed physics data implementation than the IPhysicsForceRepresentationBase.
		 *
		 * \author Adrian Simionescu
		 * \date February 2015
		 */
		template<typename Type>
		class IPhysicsRepresentationBase : public IPhysicsBase<Type>
		{
		protected:
			std::shared_ptr<Physics::Force<Type>> objectPhysics;
			virtual void init() override
			{
				this->objectPhysics = std::make_shared<Physics::Force<Type>>();
			}
		public:
			IPhysicsRepresentationBase();
			virtual ~IPhysicsRepresentationBase();

			IPhysicsRepresentationBase(const IPhysicsRepresentationBase &value);
			IPhysicsRepresentationBase(IPhysicsRepresentationBase &&value);
			IPhysicsRepresentationBase &operator=(IPhysicsRepresentationBase && value);
			IPhysicsRepresentationBase& operator=(const IPhysicsRepresentationBase& value);

			std::shared_ptr<Physics::Force<Type>> ObjectPhysics() const {
				if (this->objectPhysics == nullptr)
					throw std::bad_function_call(Aurora::Errors::ErrorMessages::PhysicsForceEmptyObject.c_str());

				return objectPhysics;
			}
			template<typename T>
			void ObjectPhysics(T &&value) { 
				
				objectPhysics = std::forward<T>(value); 
			}

			

		};

		

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif