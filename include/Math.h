#include <cmath>
#include <memory.h>
#include <limits>
#include <stdexcept>

class Vector2 {
public: 
    float x, y; 

    Vector2(): x(0.0f), y(0.0f) {}; 

    // What is explicit ? 
    explicit Vector2(float x, float y) : x(x), y(y) {}; 
    friend std::ostream& operator<<(const std::ostream& output, const Vector2& v);
    bool operator==(const Vector2& right); 

    Vector2 operator+(const Vector2& right) const; 
    Vector2 operator-(const Vector2& right) const; 
    Vector2 operator*(float right) const; 
    Vector2 operator/(float right) const; 

    Vector2& operator+=(const Vector2& right); 
    Vector2& operator-=(const Vector2& right); 
    Vector2& operator*=(float right); 
    Vector2& operator/=(float right); 

    float length() const; 
    void normalize(); 

    static Vector2 normalize(const Vector2& vec); 
    static double distance(const Vector2& a, const Vector2& b); 
    static double manhattanDistance(const Vector2& a, const Vector2& b); 
    static Vector2 abs(const Vector2& v); 
    static Vector2 floor(const Vector2& v); 
    static Vector2 fmod(const Vector2& v, float val); 
    static float dot(const Vector2& left, const Vector2& right); 
    static float cross(const Vector2& left, const Vector2& right); 
    static double facing(const Vector2& a, const Vector2& b); 
    static Vector2 polar(double distance, double angle); 
    static Vector2 vectorOnDir(Vector2 start, double distance, double direction_angle); 
    static Vector2 rotate(const Vector2& point, const Vector2& origin, double angle);
    static Vector2 lerp(const Vector2& a, const Vector2& b, float f); 
    static Vector2 reflect(const Vector2& v, const Vector2& n); 
    static Vector2 project(const Vector2& a, const Vector2& b); 
    static Vector2 saturate(const Vector2& v); 
    static Vector2 smoothstep(const Vector2& a, const Vector2& b, float amount); 
    static Vector2 smootherstep(const Vector2& a, const Vector2& b, float amount); 

    Vector2 projectToLine(const class Line& line) const; 
    double distanceToLine(const class Line& line) const; 
    static Vector2 transform(const Vector2& vec, const class Matrix3& mat, float w = 1.0f); 

    static const Vector2 zero; 
    static const Vector2 unitX; 
    static const Vector2 unitY; 
    static const Vector2 negUnitX; 
    static const Vector2 negUnitY; 
};


class Vector3
{
public:
    float x, y, z; 
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}; 

    explicit Vector3(float x, float y, float z) : x(x), y(y), z(z) {};
    friend std::ostream& operator<<(const std::ostream& output, const Vector3& v); 
    bool operator==(const Vector3& right); 

    Vector3 operator+(const Vector3& right) const; 
    Vector3 operator-(const Vector3& right) const; 
    Vector3 operator*(float right) const; 
    Vector3 operator/(float right) const;

    Vector3& operator+=(const Vector3& right); 
    Vector3& operator-=(const Vector3& right); 
    Vector3& operator*=(float right); 
    Vector3& operator/=(float right); 

    float length() const; 
    void normalize(); 

    static Vector3 normalize(const Vector3& vec); 
    static double distance(const Vector3& a, const Vector3& b); 
    static double manhattanDistance(const Vector3& a, const Vector3& b); 
    static Vector3 abs(const Vector3& v); 
    static Vector3 floor(const Vector3& v); 
    static Vector3 fmod(const Vector3& v, float val); 
    static float dot(const Vector3& left, const Vector3& right); 
    static Vector3 cross(const Vector3& left, const Vector3& right); 
    static double facing(const Vector3& a, const Vector3& b); 
    static Vector3 polar(double distance, double angle); 
    static Vector3 vectorOnDir(Vector3 start, double distance, double direction_angle); 
    static Vector3 rotate(const Vector3& point, const Vector3& origin, double angle);
    static Vector3 lerp(const Vector3& a, const Vector3& b, float f); 
    static Vector3 reflect(const Vector3& v, const Vector3& n); 
    static Vector3 project(const Vector3& a, const Vector3& b); 
    static Vector3 saturate(const Vector3& v); 
    static Vector3 smoothstep(const Vector3& a, const Vector3& b, float amount); 
    static Vector3 smootherstep(const Vector3& a, const Vector3& b, float amount); 

    static Vector3 transform(const Vector3& vec, const class Matrix4& mat, float w = 1.0f);
	static Vector3 transformWithPerspDiv(const Vector3& vec, const class Matrix4& mat, float w = 1.0f);
	static Vector3 transform(const Vector3& v, const class Quaternion& q);

    static const Vector3 zero; 
    static const Vector3 unitX; 
    static const Vector3 unitY; 
    static const Vector3 unitZ; 
    static const Vector3 negUnitX; 
    static const Vector3 negUnitY; 
    static const Vector3 negUnitZ;
    static const Vector3 Infinity;
	static const Vector3 negInfinity; 
};

class Matrix2
{
public:
    float mat[2][2]; 
    Vector2 rows[2]; 
    Vector2 cols[2]; 
    
    Matrix2(){
        *this = Matrix2::Identity; // default matrix is the identity matrix.  
    };

    explicit Matrix2(float mat[2][2]) {
        memcpy(this->mat, mat, 4 *sizeof(float)); 
        for (size_t i = 0; i < 2; i++)
        {
            rows[i] = Vector2(mat[i][0], mat[i][1]); 
            cols[i] = Vector2(mat[0][i], mat[1][i]); 
        }
    }

    Matrix2 operator*(const Matrix2& right); 
    Vector2 operator*(const Vector2& right); 

    Matrix2& operator*=(const Matrix2& right); 

    static Matrix2 transpose(const Matrix2& mat);
    static float det(const Matrix2& mat);
    static Matrix2 inverse(const Matrix2& mat);  

    static Matrix2 createRotationMat(float theta); // create rotation matrix from given angle

	static const Matrix2 zero;
	static const Matrix2 Identity;
};


class Matrix3
{
public:
    float mat[3][3]; 
    Vector3 rows[3]; 
    Vector3 cols[3]; 
    
    Matrix3(){
        *this = Matrix3::Identity; // default matrix is the identity matrix.  
    };

    explicit Matrix3(float mat[3][3]) {
        memcpy(this->mat, mat, 9 *sizeof(float)); 
        for (size_t i = 0; i < 3; i++)
        {
            rows[i] = Vector3(mat[i][0], mat[i][1], mat[i][2]); 
            cols[i] = Vector3(mat[0][i], mat[1][i], mat[2][i]); 
        }
    }

    Matrix3 operator*(const Matrix3& right); 
    Vector3 operator*(const Vector3& right); 

    Matrix3& operator*=(const Matrix3& right); 

    static Matrix3 transpose(const Matrix3& mat);

    // Substracts one row and column from the 3d matrix and converts it to 2d matrix. 
    static Matrix2 substractRowCol(const Matrix3& mat, int substractRow, int substractCol); 
    static float det(const Matrix3& mat);
    static Matrix3 inverse(const Matrix3& mat);  

    static Matrix3 createScaleMat(float xScale, float yScale); 
    static Matrix3 createScaleMat(const Vector2& scaleVec); 
    static Matrix3 createScaleMat(float scale); 
    static Matrix3 createRotationMatX(float theta); 
    static Matrix3 createRotationMatY(float theta); 
    static Matrix3 createRotationMatZ(float theta); 
    static Matrix3 createTranslationMat(const Vector2& transVec); 

    static const Matrix3 zero; 
	static const Matrix3 Identity;
};




// class Vector4
// {
// private:
//     float x, y, z, w; 
// public:
//     Vector4(float x, float y, float z, float w);
//     ~Vector4();
// };