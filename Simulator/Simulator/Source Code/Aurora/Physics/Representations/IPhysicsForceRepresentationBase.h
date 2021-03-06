#ifndef NatureOfCodeCocos2DX_IPhysicsForceRepresentationBase_h
#define NatureOfCodeCocos2DX_IPhysicsForceRepresentationBase_h



#include "../Implementations/Force.h"


namespace Aurora {
	namespace Physics {

		/*!
		 * \class IPhysicsForceRepresentationBase
		 *
		 * \brief Use this to add physics data to an object and add support for physics calculations to perform calculations on the data.
		 *
		 * \author Adrian Simionescu
		 * \date February 2015
		 */
		template<typename Type>
		class IPhysicsForceRepresentationBase
		{
			private:
			std::shared_ptr<Physics::Force<Type>> objectPhysics;
			

			void init();
			void init(const IPhysicsForceRepresentationBase &value);
		public:
#pragma region Constructors and Assigments operators
			IPhysicsForceRepresentationBase();
			virtual ~IPhysicsForceRepresentationBase();
			IPhysicsForceRepresentationBase(const IPhysicsForceRepresentationBase &value);
			IPhysicsForceRepresentationBase(IPhysicsForceRepresentationBase &&value);
			IPhysicsForceRepresentationBase &operator=(IPhysicsForceRepresentationBase && value);
			IPhysicsForceRepresentationBase& operator=(const IPhysicsForceRepresentationBase& value);
#pragma endregion

			

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