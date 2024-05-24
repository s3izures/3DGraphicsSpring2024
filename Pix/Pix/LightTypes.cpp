#include "LightTypes.h"
#include "Camera.h"
#include "MaterialManager.h"

X::Color DirectionalLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();

    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    Vector3 dirToLight = -mDirection;
    float dot = MathHelper::Dot(dirToLight, normal);
    X::Color colorDiffuse = mDiffuse * X::Math::Max(dot, 0.0f) * mm->GetMaterialDiffuse();

    Vector3 dirToEye = MathHelper::Normalize(camera->getPosition() - position);
    Vector3 half = MathHelper::Normalize(dirToLight + dirToEye);
    float fallOff = pow(MathHelper::Dot(half, normal), mm->GetMaterialShininess());
    X::Color colorSpecular = mSpecular * X::Math::Max(fallOff,0.0f) * mm->GetMaterialSpecular();

    return colorAmbient + colorDiffuse + colorSpecular;
}

void DirectionalLight::SetDirection(const Vector3& direction)
{
    mDirection = direction;
}

X::Color PointLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();


    Vector3 dirToLight = mPosition - position;
    float distToLight = MathHelper::Magnitude(dirToLight);
    dirToLight /= distToLight;

    float attenuation = 1.0f / (mAttenConstant + (mAttenLinear * distToLight) + (mAttenQuadratic * distToLight * distToLight));
    float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    float dot = MathHelper::Dot(dirToLight, normal);
    X::Color colorDiffuse = mDiffuse * X::Math::Max(dot, 0.0f) * mm->GetMaterialDiffuse() * iL;

    Vector3 dirToEye = MathHelper::Normalize(camera->getPosition() - position);
    Vector3 half = MathHelper::Normalize(dirToLight + dirToEye);
    float fallOff = pow(MathHelper::Dot(half, normal), mm->GetMaterialShininess());
    X::Color colorSpecular = mSpecular * X::Math::Max(fallOff, 0.0f) * mm->GetMaterialSpecular() * iL;

    return colorAmbient + colorDiffuse + colorSpecular;
}

void PointLight::SetPosition(const Vector3& position)
{
    mPosition = position;
}

void PointLight::SetAttenuation(float constant, float linear, float quadratic)
{
    mAttenConstant = constant;
    mAttenLinear = linear;
    mAttenQuadratic = quadratic;
}
