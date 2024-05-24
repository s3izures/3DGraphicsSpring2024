#pragma once
#include "Light.h"
class DirectionalLight : public Light
{
public:
	virtual X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) override;
	void SetDirection(const Vector3& direction);

private:
	Vector3 mDirection;
};

