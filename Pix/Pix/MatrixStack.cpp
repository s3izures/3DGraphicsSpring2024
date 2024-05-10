#include "MatrixStack.h"

MatrixStack* MatrixStack::Get()
{
    static MatrixStack sInstance;
    return &sInstance;
}

void MatrixStack::OnNewFrame()
{
    mCombinedMatrix = Matrix4::Identity();
    mMatrices.clear();
}

void MatrixStack::PushTranslation(const Vector3& d)
{
    Matrix4 translationMat = Matrix4::Translation(d);
    mMatrices.push_back(translationMat);
    mCombinedMatrix = translationMat * mCombinedMatrix;
}

void MatrixStack::PushRotationX(float radians)
{
    Matrix4 rotMat = Matrix4::RotationX(radians);
    mMatrices.push_back(rotMat);
    mCombinedMatrix = rotMat * mCombinedMatrix;
}

void MatrixStack::PushRotationY(float radians)
{
    Matrix4 rotMat = Matrix4::RotationY(radians);
    mMatrices.push_back(rotMat);
    mCombinedMatrix = rotMat * mCombinedMatrix;
}

void MatrixStack::PushRotationZ(float radians)
{
    Matrix4 rotMat = Matrix4::RotationZ(radians);
    mMatrices.push_back(rotMat);
    mCombinedMatrix = rotMat * mCombinedMatrix;
}

void MatrixStack::PushScaling(const Vector3& s)
{
    Matrix4 scaleMat = Matrix4::Scaling(s);
    mMatrices.push_back(scaleMat);
    mCombinedMatrix = scaleMat * mCombinedMatrix;
}

void MatrixStack::PopMatrix()
{
    if (!mMatrices.empty())
    {
        Matrix4 matrix = mMatrices.back();
        mMatrices.pop_back();
        mCombinedMatrix = MathHelper::Inverse(matrix) * mCombinedMatrix;
    }
}

const Matrix4& MatrixStack::GetTransform() const
{
    return mCombinedMatrix;
}
