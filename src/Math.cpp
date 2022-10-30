#include "Math.h"

namespace Brix::Math {
    // Vector2 functions
    Vector2  Vector2::operator+(const Vector2& right) const {
        return Vector2(x + right.x, y + right.y); 
    } 

    Vector2  Vector2::operator-(const Vector2& right) const {
        return Vector2(x - right.x, y - right.y); 
    } 

    Vector2  Vector2::operator*(float right) const {
        return Vector2(x * right, y * right); 
    } 

    Vector2  Vector2::operator/(float right) const {
        if(Brix::Math::isNearZero(right)) {
            throw std::runtime_error("Math error: Attempted to divide by zero\n");
        }
        return Vector2(x / right, y / right); 
    } 

    Vector2& Vector2:: operator+=(const Vector2& right) {
        x += right.x; 
        y += right.y; 
        return *this; 
    } 

    Vector2& Vector2:: operator-=(const Vector2& right) {
        x -= right.x; 
        y -= right.y; 
        return *this; 
    } 

    Vector2& Vector2:: operator*=(float right) {
        x *= right; 
        y *= right; 
        return *this; 
    } 

    Vector2& Vector2:: operator/=(float right) {
        if(Brix::Math::isNearZero(right)) {
            throw std::runtime_error("Math error: Attempted to divide by zero\n");
        }
        x /= right; 
        y /= right; 
        return *this; 
    } 

    float Vector2::length() const{
        return sqrt(x*x + y*y); 
    } 

    void Vector2::normalize(){
        float length = this->length(); 
        (*this) /= length;
    } 

    Vector2 Vector2::normalize(const Vector2& vec){
        Vector2 temp = vec; 
        temp.normalize(); 
        return temp; 
    } 

    double Vector2::distance(const Vector2& a, const Vector2& b){
        return (a - b).length(); 
    } 

    double Vector2::manhattanDistance(const Vector2& a, const Vector2& b){
        return fabs(a.x - b.x) + fabs(a.y - b.y); 
    } 

    Vector2 Vector2::abs(const Vector2& v) {
        return Vector2(fabs(v.x), fabs(v.y)); 
    } 

    Vector2 Vector2::floor(const Vector2& v) {
        return Vector2(::floor(v.x), ::floor(v.y)); 
    } 

    Vector2 Vector2::fmod(const Vector2& v, float val) {
        return Vector2(::fmod(v.x, val), ::fmod(v.y, val)); 
    } 

    float Vector2::dot(const Vector2& left, const Vector2& right){
        return (left.x * right.x + left.y * right.y); 
    } 

    float Vector2::cross(const Vector2& left, const Vector2& right){
        return (left.x * right.y - left.y * right.x); 
    } 

    double Vector2::facing(const Vector2& a, const Vector2& b){
        return atan2(b.y - a.y, b.x - a.x); 
    } 

    Vector2 Vector2::polar(double radius, double angle){
        return Vector2(radius * cos(angle), radius * sin(angle)); 
    } 

    Vector2 Vector2::vectorOnDir(Vector2 start, double distance, double direction_angle){
        return start + Vector2::polar(distance, direction_angle); 
    } 

    Vector2 Vector2::rotate(const Vector2& point, const Vector2& origin, double angle){
        double angleRadian = Brix::Math::toRadians(angle); 
        Vector2 rotateMatX = Vector2(cos(angleRadian), -sin(angleRadian)); 
        Vector2 rotateMatY = Vector2(sin(angleRadian), cos(angleRadian)); 
    }

    Vector2 Vector2::lerp(const Vector2& a, const Vector2& b, float f){
        return a + (b - a) * f; 
    } 

    Vector2 Vector2::reflect(const Vector2& v, const Vector2& n){
        return v - n * 2.0f * Vector2::dot(v, n); 
    } 

    const Vector2 Vector2::zero(0.0f, 0.0f);
    const Vector2 Vector2::unitX(1.0f, 0.0f);
    const Vector2 Vector2::unitY(0.0f, 1.0f);
    const Vector2 Vector2::negUnitX(-1.0f, 0.0f);
    const Vector2 Vector2::negUnitY(0.0f, -1.0f);





    // Vector3 functions
    Vector3  Vector3::operator+(const Vector3& right) const {
        return Vector3(x + right.x, y + right.y, z + right.z); 
    } 

    Vector3  Vector3::operator-(const Vector3& right) const {
        return Vector3(x - right.x, y - right.y, z - right.z); 
    } 

    Vector3  Vector3::operator*(float right) const {
        return Vector3(x * right, y * right, z * right); 
    } 

    Vector3  Vector3::operator/(float right) const {
        if(Brix::Math::isNearZero(right)) {
            throw std::runtime_error("Math error: Attempted to divide by zero\n");
        }
        return Vector3(x / right, y / right, z / right); 
    } 

    Vector3& Vector3:: operator+=(const Vector3& right) {
        x += right.x; 
        y += right.y; 
        z += right.z;
        return *this; 
    } 

    Vector3& Vector3:: operator-=(const Vector3& right) {
        x -= right.x; 
        y -= right.y; 
        z -= right.z; 
        return *this; 
    } 

    Vector3& Vector3:: operator*=(float right) {
        x *= right; 
        y *= right; 
        z *= right; 
        return *this; 
    } 

    Vector3& Vector3:: operator/=(float right) {
        if(Brix::Math::isNearZero(right)) {
            throw std::runtime_error("Math error: Attempted to divide by zero\n");
        }
        x /= right; 
        y /= right; 
        z /= right; 
        return *this; 
    } 

    float Vector3::length() const{
        return sqrt(x*x + y*y + z*z); 
    } 

    void Vector3::normalize(){
        float length = this->length(); 
        (*this) /= length; 
    } 

    Vector3 Vector3::normalize(const Vector3& vec){
        Vector3 temp = vec; 
        temp.normalize(); 
        return temp; 
    } 

    double Vector3::distance(const Vector3& a, const Vector3& b){
        return (a - b).length(); 
    } 

    double Vector3::manhattanDistance(const Vector3& a, const Vector3& b){
        return fabs(a.x - b.x) + fabs(a.y - b.y) + fabs(a.z - b.z); 
    } 

    Vector3 Vector3::abs(const Vector3& v) {
        return Vector3(fabs(v.x), fabs(v.y), fabs(v.z)); 
    } 

    Vector3 Vector3::floor(const Vector3& v) {
        return Vector3(::floor(v.x), ::floor(v.y), ::floor(v.z)); 
    } 

    Vector3 Vector3::fmod(const Vector3& v, float val) {
        return Vector3(::fmod(v.x, val), ::fmod(v.y, val), ::fmod(v.z, val)); 
    } 

    float Vector3::dot(const Vector3& left, const Vector3& right){
        return (left.x*right.x + left.y*right.y + left.z*right.z); 
    } 

    Vector3 Vector3::cross(const Vector3& left, const Vector3& right){
        Vector3 temp; 
        temp.x = left.y*right.z - left.z*right.y; 
        temp.y = left.z*right.x - left.x*right.z; 
        temp.z = left.x*right.y - left.y*right.x; 
        return temp; 
    } 

    double Vector3::facing(const Vector3& a, const Vector3& b){
        // return atan2(b.y - a.y, b.x - a.x); 
    } 

    Vector3 Vector3::polar(double radius, double angle){
        // return Vector2(radius * cos(angle), radius * sin(angle)); 
    } 

    Vector3 Vector3::vectorOnDir(Vector3 start, double distance, double direction_angle){
        // return start + Vector2::polar(distance, direction_angle); 
    } 

    Vector3 Vector3::rotate(const Vector3& point, const Vector3& origin, double angle){
        // double angleRadian = Brix::Math::toRadians(angle); 
        // Vector2 rotateMatX = Vector2(cos(angleRadian), -sin(angleRadian)); 
        // Vector2 rotateMatY = Vector2(sin(angleRadian), cos(angleRadian)); 
    }

    Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float f){
        return a + (b - a) * f; 
    } 

    Vector3 Vector3::reflect(const Vector3& v, const Vector3& n){
        return v - n * 2.0f * Vector3::dot(v, n); 
    } 

    Vector3 Vector3::project(const Vector3& a, const Vector3& b) {
        return a - b * Vector3::dot(a, b); 
    }

    Vector3 Vector3::saturate(const Vector3& v) {
        float x = Brix::Math::saturate(v.x); 
        float y = Brix::Math::saturate(v.y); 
        float z = Brix::Math::saturate(v.z); 
        return Vector3(x, y, z); 
    } 

    Vector3 Vector3::smoothstep(const Vector3& a, const Vector3& b, float amount) {
        float scaled_amount = amount * amount * (3 - 2 * amount); 
        return Vector3::lerp(a, b, scaled_amount);
    } 

    Vector3 Vector3::smootherstep(const Vector3& a, const Vector3& b, float amount) {
        float scaled_amount = amount*amount*amount*(amount*(amount*6 - 15) + 10);
        return Vector3::lerp(a, b, scaled_amount);
    } 

    const Vector3 Vector3::zero(0.0f, 0.0f, 0.0f); 
    const Vector3 Vector3::unitX(1.0f, 0.0f, 0.0f); 
    const Vector3 Vector3::unitY(0.0f, 1.0f, 0.0f); 
    const Vector3 Vector3::unitZ(0.0f, 0.0f, 1.0f); 
    const Vector3 Vector3::negUnitX(-1.0f, 0.0f, 0.0f); 
    const Vector3 Vector3::negUnitY(0.0f, -1.0f, 0.0f); 
    const Vector3 Vector3::negUnitZ(0.0f, 0.0f, -1.0f);
    const Vector3 Vector3::Infinity(Brix::Math::Infinity, Brix::Math::Infinity, Brix::Math::Infinity);
    const Vector3 Vector3::negInfinity(Brix::Math::negInfinity, Brix::Math::negInfinity, Brix::Math::negInfinity); 






    // Matrix2 functions
    Matrix2 Matrix2::operator*(const Matrix2& right) {
        float mat[2][2]; 
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                mat[i][j] = Vector2::dot(rows[i], right.cols[j]);    
            }
        }
        return Matrix2(mat); 
    } 

    Vector2 Matrix2::operator*(const Vector2& right) {
        Vector2 result; 
        result.x = Vector2::dot(rows[0], right); 
        result.y = Vector2::dot(rows[1], right); 
        return result; 
    } 

    Matrix2& Matrix2::operator*=(const Matrix2& right) {
        *this = *this * right; 
        return *this; 
    } 

    Matrix2 Matrix2::transpose(const Matrix2& mat) {
        float resultMatArr[2][2]; 
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                resultMatArr[i][j] = mat.mat[j][i]; 
            }
        }
        return Matrix2(resultMatArr); 
    } 

    float Matrix2::det(const Matrix2& m) {
        return (m.mat[0][0] * m.mat[1][1] - m.mat[0][1] * m.mat[1][0]); 
    } 

    Matrix2 Matrix2::inverse(const Matrix2& mat) {
        float det = Matrix2::det(mat); 
        if(Brix::Math::isNearZero(det)) {
            throw std::runtime_error("Matrix does not have any inverse."); 
        }
        float fac = 1.0 / det; 
        float resultMat[2][2] = {
            fac * mat.mat[1][1], -fac * mat.mat[0][1],
            -fac * mat.mat[1][0], fac * mat.mat[0][0]
        }; 
        return Matrix2(resultMat); 
    }

    Matrix2 Matrix2::createRotationMat(float theta) {
        float matArr[2][2] = {
            cos(theta), -sin(theta),
            sin(theta), cos(theta)
        };
        return Matrix2(matArr); 
    }

    float m2Zero[2][2] = {
        0.0f, 0.0f, 
        0.0f, 0.0f
    }; 
    float m2Identity[2][2] = {
        1.0f, 0.0f, 
        0.0f, 1.0f
    }; 
    const Matrix2 Matrix2::zero(m2Zero);
    const Matrix2 Matrix2::Identity(m2Identity);





    // Matrix3 functions
    Matrix3 Matrix3::operator*(const Matrix3& right) {
        float resultMat[3][3]; 
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                resultMat[i][j] = Vector3::dot(rows[i], right.cols[j]);    
            }
        }
        return Matrix3(resultMat); 
    } 

    Vector3 Matrix3::operator*(const Vector3& right) {
        Vector3 result; 
        result.x = Vector3::dot(rows[0], right); 
        result.y = Vector3::dot(rows[1], right); 
        result.z = Vector3::dot(rows[2], right); 
        return result; 
    } 

    Matrix3& Matrix3::operator*=(const Matrix3& right) {
        *this = *this * right; 
        return *this; 
    } 

    Matrix3 Matrix3::transpose(const Matrix3& mat) {
        float resultMat[3][3]; 
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                resultMat[i][j] = mat.mat[j][i]; 
            }
        }
        return Matrix3(resultMat); 
    } 

    Matrix2 Matrix3::substractRowCol(const Matrix3& mat, int substractRow, int substractCol) {
        float resultMat[2][2];
        int row, col;  
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if(i != substractRow && j != substractRow) {
                    resultMat[row][col++] = mat.mat[i][j];
                    if(col == 2) row++; col = 0;  
                }
            }
        }
        return Matrix2(resultMat); 
    }

    float Matrix3::det(const Matrix3& m) {
        return (m.mat[0][0] * Matrix2::det(Matrix3::substractRowCol(m, 0, 0))
        + m.mat[0][1] * Matrix2::det(Matrix3::substractRowCol(m, 0, 1))
        + m.mat[0][2] * Matrix2::det(Matrix3::substractRowCol(m, 0, 2))); 
        // return (m.mat[0][0] * (m.mat[1][1] * m.mat[2][2] - m.mat[1][2] * m.mat[2][1])
        // + m.mat[0][1] * (m.mat[1][2] * m.mat[2][0] - m.mat[1][0] * m.mat[2][2]) 
        // + m.mat[0][2] * (m.mat[1][0] * m.mat[2][1] - m.mat[1][1] * m.mat[2][0]));
    } 

    Matrix3 Matrix3::inverse(const Matrix3& mat) {
        float det = Matrix3::det(mat); 
        if(Brix::Math::isNearZero(det)) {
            throw std::runtime_error("Matrix does not have any inverse."); 
        }
        float fac = 1.0 / det; 
        float resultMat[3][3]; 
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                float sign = ((i + j) % 2 == 0) ? 1 : -1; 
                resultMat[i][j] = sign * fac * Matrix2::det(Matrix3::substractRowCol(mat, i, j));
            }
        }
        return Matrix3(resultMat); 
    }

    Matrix3 Matrix3::createScaleMat(float xScale, float yScale) {
        float resultMat[3][3] = {
            { xScale, 0.0f, 0.0f },
            { 0.0f, yScale, 0.0f },
            { 0.0f, 0.0f, 1.0f }
        };
        return Matrix3(resultMat); 
    } 

    Matrix3 Matrix3::createScaleMat(const Vector2& scaleVec) {
        return createScaleMat(scaleVec.x, scaleVec.y); 
    } 

    Matrix3 Matrix3::createScaleMat(float scale) {
        return createScaleMat(scale, scale);
    } 

    Matrix3 Matrix3::createRotationMatX(float theta) {
        float resultMat[3][3] =
        {
            { 1.0f, 0.0f, 0.0f },
            { 0.0f, cos(theta), -sin(theta) },
            { 0.0f, sin(theta), cos(theta) },
        };
        return Matrix3(resultMat);
    } 

    Matrix3 Matrix3::createRotationMatY(float theta) {
        float resultMat[3][3] =
        {
            { cos(theta), 0.0f, sin(theta) },
            { 0.0f, 1.0f, 0.0f },
            { -sin(theta), 0.0f, cos(theta) },
        };
        return Matrix3(resultMat);
    } 

    Matrix3 Matrix3::createRotationMatZ(float theta) {
        float resultMat[3][3] =
        {
            { cos(theta), -sin(theta), 0.0f },
            { sin(theta), cos(theta), 0.0f },
            { 0.0f, 0.0f, 1.0f },
        };
        return Matrix3(resultMat);
    } 

    Matrix3 Matrix3::createTranslationMat(const Vector2& transVec) {

    } 

    static float m3Zero[3][3] = {
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f }
    };
    static float m3Identity[3][3] = {
        { 1.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f }
    };
    const Matrix3 Matrix3::zero(m3Zero); 
    const Matrix3 Matrix3::Identity(m3Identity);







    // Vector 4 functions
    Vector4 Vector4::operator+(const Vector4& right) const {
        return Vector4(x + right.x, y + right.y, z + right.z, w + right.w); 
    } 

    Vector4 Vector4::operator-(const Vector4& right) const {
        return Vector4(x - right.x, y - right.y, z - right.z, w - right.w); 
    } 

    Vector4 Vector4::operator*(float right) const {
        return Vector4(x * right, y * right, z * right, w * right); 
    } 

    Vector4  Vector4::operator/(float right) const {
        if(Brix::Math::isNearZero(right)) {
            throw std::runtime_error("Math error: Attempted to divide by zero\n");
        }
        return Vector4(x / right, y / right, z / right, w / right); 
    } 

    Vector4 Vector4::operator*(const Matrix4& right) const {
        Vector4 result; 
        result.x = Vector4::dot((*this), right.cols[0]);
        result.y = Vector4::dot((*this), right.cols[1]);
        result.z = Vector4::dot((*this), right.cols[2]);
        result.w = Vector4::dot((*this), right.cols[3]);
        return result; 
    }

    Vector4& Vector4:: operator+=(const Vector4& right) {
        x += right.x; 
        y += right.y; 
        z += right.z;
        w += right.w; 
        return *this; 
    } 

    Vector4& Vector4:: operator-=(const Vector4& right) {
        x -= right.x; 
        y -= right.y; 
        z -= right.z; 
        w -= right.w;
        return *this; 
    } 

    Vector4& Vector4:: operator*=(float right) {
        x *= right; 
        y *= right; 
        z *= right; 
        w *= right; 
        return *this; 
    } 

    Vector4& Vector4:: operator/=(float right) {
        if(Brix::Math::isNearZero(right)) {
            throw std::runtime_error("Math error: Attempted to divide by zero\n");
        }
        x /= right; 
        y /= right; 
        z /= right; 
        w /= right; 
        return *this; 
    } 

    float Vector4::length() const{
        return sqrt(x*x + y*y + z*z + w*w); 
    } 

    void Vector4::normalize(){
        float w = this->w; 
        // float length = this->length(); 
        (*this) /= w; 
    } 

    Vector4 Vector4::normalize(const Vector4& vec) {
        Vector4 res = vec; 
        res.normalize(); 
        return res; 
    }

    float Vector4::dot(const Vector4& left, const Vector4& right){
        return (left.x*right.x + left.y*right.y + left.z*right.z + left.w*right.w); 
    } 

    Vector3 Vector4::toVector3(const Vector4& vec) {
        return Vector3(vec.x, vec.y, vec.z); 
    }

    Vector4 Vector4::fromVector3(const Vector3& vec) {
        return Vector4(vec.x, vec.y, vec.z, 1);
    } 





    // Matrix 4 functions
    std::ostream& operator<<(std::ostream& ostream, const Matrix4& m) {
        for(size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++)
            {
                ostream << m.mat[i][j] << " "; 
            }
            ostream << "\n";
        }
    }; 

    Matrix4 Matrix4::operator*(const Matrix4& right) {
        float resultMat[4][4]; 
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                resultMat[i][j] = Vector4::dot(rows[i], right.cols[j]);
            }
        }
        return Matrix4(resultMat); 
    } 

    Matrix4& Matrix4::operator*=(const Matrix4& right) {
        *this = *this * right; 
        return *this; 
    } 

    Vector4 Matrix4::operator*(const Vector4& right) {
        Vector4 result; 
        result.x = Vector4::dot(this->rows[0], right); 
        result.y = Vector4::dot(this->rows[1], right); 
        result.z = Vector4::dot(this->rows[2], right); 
        result.w = Vector4::dot(this->rows[3], right);
        return result;  
    } 

    void Matrix4::invert() {

    }

    Vector4 Matrix4::getTranslation() const {
        return Vector4(mat[3][0], mat[3][1], mat[3][2], mat[3][3]); 
    } 

    Vector4 Matrix4::getXAxis() const {
        return Vector4::normalize(rows[0]);
    } 

    Vector4 Matrix4::getYAxis() const {
        return Vector4::normalize(rows[1]);
    } 

    Vector4 Matrix4::getZAxis() const {
        return Vector4::normalize(rows[2]);
    } 

    Vector3 Matrix4::getScale() const {
        Vector3 scaleVec; 
        scaleVec.x = this->cols[0].length(); 
        scaleVec.y = this->cols[1].length(); 
        scaleVec.z = this->cols[2].length(); 
        return scaleVec; 
    } 

    Matrix4 Matrix4::transpose(const Matrix4& mat) {
        float matrixVals[4][4]; 
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                matrixVals[i][j] = mat.mat[j][i]; 
            }
        }
        return Matrix4(matrixVals);
    } 

    Matrix4 Matrix4::createScale(float xScale, float yScale, float zScale) {
        float temp[4][4] =
        {
            { xScale, 0.0f, 0.0f, 0.0f },
            { 0.0f, yScale, 0.0f, 0.0f },
            { 0.0f, 0.0f, zScale, 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f }
        };
        return Matrix4(temp);
    } 

    Matrix4 Matrix4::createScale(const Vector3& scaleVector) {
        return Matrix4::createScale(scaleVector.x, scaleVector.y, scaleVector.z); 
    } 

    Matrix4 Matrix4::createScale(float scale) {
        return Matrix4::createScale(scale, scale, scale); 
    } 

    Matrix4 Matrix4::createRotationX(float theta) {
        float temp[4][4] =
        {
            { 1.0f, 0.0f, 0.0f , 0.0f },
            { 0.0f, cos(theta), sin(theta), 0.0f },
            { 0.0f, -sin(theta), cos(theta), 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f },
        };
        return Matrix4(temp);
    } 

    Matrix4 Matrix4::createRotationY(float theta) {
        float temp[4][4] =
        {
            { cos(theta), 0.0f, -sin(theta), 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { sin(theta), 0.0f, cos(theta), 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f },
        };
        return Matrix4(temp);
    } 

    Matrix4 Matrix4::createRotationZ(float theta) {
        float temp[4][4] =
        {
            { cos(theta), sin(theta), 0.0f, 0.0f },
            { -sin(theta), cos(theta), 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f },
        };
        return Matrix4(temp);
    } 

    Matrix4 Matrix4::createTranslation(const Vector3& trans) {
        float temp[4][4] =
        {
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { trans.x, trans.y, trans.z, 1.0f }
        };
        return Matrix4(temp);
    } 

    Matrix4 Matrix4::createLookAt(const Vector3& eye, const Vector3& target, const Vector3& up) {

    } 

    Matrix4 Matrix4::createOrtho(float width, float height, float near, float far) {

    } 

    Matrix4 Matrix4::createPerspectiveFOV(float fovV, float width, float height, float near, float far) {

    } 

    Matrix4 Matrix4::createSimpleViewProj(float width, float height) {

    } 

    Matrix4 Matrix4::createFromQuaternion(const class Quaternion& q) {

    } 
    static float m4Identity[4][4] = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f },
    };
    const Matrix4 Matrix4::Identity(m4Identity);
}