#pragma once
#include "XColors.h"

class MaterialManager
{
public:
	static MaterialManager* Get();
	void OnNewFrame();

	void SetMaterialAmbient(const X::Color& Color);
	void SetMaterialDiffuse(const X::Color& Color);
	void SetMaterialSpecular(const X::Color& Color);
	void SetMaterialEmissive(const X::Color& Color);
	void SetMaterialShininess(float s);

	const X::Color& GetMaterialAmbient() const;
	const X::Color& GetMaterialDiffuse() const;
	const X::Color& GetMaterialSpecular() const;
	const X::Color& GetMaterialEmissive() const;
	const float GetMaterialShininess() const;

private:
	X::Color mAmbient = X::Colors::White;
	X::Color mDiffuse = X::Colors::White;
	X::Color mSpecular = X::Colors::White;
	X::Color mEmissive = X::Colors::Black;
	float mShininess = 1.0f;
};

