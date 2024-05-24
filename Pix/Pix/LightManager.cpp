#include "LightManager.h"
#include "LightTypes.h"
#include "MaterialManager.h"

LightManager* LightManager::Get()
{
	static LightManager sInstance;
	return &sInstance;
}

void LightManager::OnNewFrame()
{
	mLights.clear();
	mAmbient = X::Colors::White;
	mDiffuse = X::Colors::White;
	mSpecular = X::Colors::White;
}

void LightManager::SetLightingAmbient(const X::Color& color)
{
	mAmbient = color;
}

void LightManager::SetLightingDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void LightManager::SetLightingSpecular(const X::Color& color)
{
	mSpecular = color;
}

void LightManager::AddDirectionalLight(const Vector3& direction)
{
	auto light = std::make_unique<DirectionalLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetDirection(direction);
	mLights.emplace_back(std::move(light));
}

void LightManager::AddPointLight(const Vector3& position, float c, float l, float q)
{
	auto light = std::make_unique<PointLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetPosition(position);
	light->SetAttenuation(c, l, q);
	mLights.emplace_back(std::move(light));
}

X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{
	X::Color color = MaterialManager::Get()->GetMaterialEmissive();
	for (auto& light : mLights)
	{
		color += light->ComputeLightColor(position, normal);
	}

	return color;
}
