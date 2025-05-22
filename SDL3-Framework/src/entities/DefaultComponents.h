#pragma once

struct Transform
{
	float x, y;
	float width, height;

	Transform();
	Transform(float x, float y, float width, float height);
};

struct Velocity
{
	float dx, dy;

	Velocity();
	Velocity(float dx, float dy);
};