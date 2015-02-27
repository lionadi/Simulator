#include "PhysicsConstants.h"


namespace Aurora
{

	namespace Physics
	{
		const VECTOR2D<double> PhysicsConstants::EarthGravity = VECTOR2D<double>{ 0, -0.1 };
		const float PhysicsConstants::NormalSurfaceFrictionCoefficient = 0.05f;
		const std::string PhysicsConstants::Callbacks_NormalFrictionCalculations_FunctionName = "NormalFrictionCalculations";
		const std::string PhysicsConstants::Callbacks_NormalEarthGravityCalculations_FunctionName = "NormalEarthGravityCalculations";
		

	};

};
