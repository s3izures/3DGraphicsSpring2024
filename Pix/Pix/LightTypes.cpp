#include "LightTypes.h"
#include "Camera.h"

X::Color DirectionalLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    X::Color colorAmbient = mAmbient;
    Vector3 dirToLight = -mDirection;
    float dot = MathHelper::Dot(dirToLight, normal);
    X::Color colorDiffuse = mDiffuse * X::Math::Max(dot, 0.0f);

    Vector3 dirToEye = MathHelper::Normalize(camera->getPosition() - position);
    Vector3 half = MathHelper::Normalize(dirToLight + dirToEye);
    float fallOff = pow(MathHelper::Dot(half, normal), 10.0f);
    X::Color colorSpecular = mSpecular * X::Math::Max(fallOff,0.0f);

    return colorAmbient + colorDiffuse + colorSpecular;
}

void DirectionalLight::SetDirection(const Vector3& direction)
{
    mDirection = direction;
}
