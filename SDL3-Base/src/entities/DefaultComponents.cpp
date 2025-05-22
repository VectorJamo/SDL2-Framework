#include "DefaultComponents.h"

Transform::Transform()
{
}

Transform::Transform(float x, float y, float width, float height)
	:x(x), y(y), width(width), height(height)
{
}

Velocity::Velocity()
{
}

Velocity::Velocity(float dx, float dy)
	:dx(dx), dy(dy)
{
}
