#pragma once

#include <stdexcept>
#include <string>

template<typename T>
struct Vector1
{
    T x = 0;
    Vector1() = default;
    Vector1(T x) : x(x) { }
    float DistanceTo(Vector1<T>& other) const { return other.x - this->x; }
    std::string to_string() const { return std::to_string(this->x); }
    Vector1<T> operator+(Vector1<T>& other) const { return Vector1<T>(this->x + other.x); }
    Vector1<T> operator-(Vector1<T>& other) const { return Vector1<T>(this->x - other.x); }
    Vector1<T> operator*(Vector1<T>& other) const { return Vector1<T>(this->x * other.x); }
    Vector1<T> operator/(Vector1<T>& other) const { return Vector1<T>(this->x / other.x); }
    Vector1<T>& operator+=(Vector1<T>& other) { this->x += other.x; return *this; }
    Vector1<T>& operator-=(Vector1<T>& other) { this->x -= other.x; return *this; }
    Vector1<T>& operator*=(Vector1<T>& other) { this->x *= other.x; return *this; }
    Vector1<T>& operator/=(Vector1<T>& other) { this->x /= other.x; return *this; }
    Vector1<T> operator+(T other) const { return Vector1<T>(this->x + other); }
    Vector1<T> operator-(T other) const { return Vector1<T>(this->x - other); }
    Vector1<T> operator*(T other) const { return Vector1<T>(this->x * other); }
    Vector1<T> operator/(T other) const { return Vector1<T>(this->x / other); }
    Vector1<T>& operator+=(T other) { this->x += other; return *this; }
    Vector1<T>& operator-=(T other) { this->x -= other; return *this; }
    Vector1<T>& operator*=(T other) { this->x *= other; return *this; }
    Vector1<T>& operator/=(T other) { this->x /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

template<typename T>
struct Vector2 : public Vector1<T>
{
    T y = 0;
    Vector2() = default;
    Vector2(T x, T y) : Vector1<T>(x), y(y) { }
    float DistanceTo(Vector2<T>& other) const { return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2)); }
    std::string to_string() const { return Vector1<T>::to_string() + "," + std::to_string(y); }
    Vector2<T> operator+(Vector2<T>& other) const { return Vector2<T>(this->x + other.x, this->y + other.y); }
    Vector2<T> operator-(Vector2<T>& other) const { return Vector2<T>(this->x - other.x, this->y - other.y); }
    Vector2<T> operator*(Vector2<T>& other) const { return Vector2<T>(this->x * other.x, this->y * other.y); }
    Vector2<T> operator/(Vector2<T>& other) const { return Vector2<T>(this->x / other.x, this->y / other.y); }
    Vector2<T>& operator+=(Vector2<T>& other) { this->x += other.x; this->y += other.y; return *this; }
    Vector2<T>& operator-=(Vector2<T>& other) { this->x -= other.x; this->y -= other.y; return *this; }
    Vector2<T>& operator*=(Vector2<T>& other) { this->x *= other.x; this->y *= other.y; return *this; }
    Vector2<T>& operator/=(Vector2<T>& other) { this->x /= other.x; this->y /= other.y; return *this; }
    Vector2<T> operator+(T other) const { return Vector2<T>(this->x + other, this->y + other); }
    Vector2<T> operator-(T other) const { return Vector2<T>(this->x - other, this->y - other); }
    Vector2<T> operator*(T other) const { return Vector2<T>(this->x * other, this->y * other); }
    Vector2<T> operator/(T other) const { return Vector2<T>(this->x / other, this->y / other); }
    Vector2<T>& operator+=(T other) { this->x += other; this->y += other; return *this; }
    Vector2<T>& operator-=(T other) { this->x -= other; this->y -= other; return *this; }
    Vector2<T>& operator*=(T other) { this->x *= other; this->y *= other; return *this; }
    Vector2<T>& operator/=(T other) { this->x /= other; this->y /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

template<typename T>
struct Vector3 : public Vector2<T>
{
    T z = 0;
    Vector3() = default;
    Vector3(T x, T y, T z) : Vector2<T>(x, y), z(z) { }
    float DistanceTo(Vector3<T>& other) const { return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2)); }
    std::string to_string() const { return Vector2<T>::to_string() + "," + std::to_string(z); }
    Vector3<T> operator+(Vector3<T>& other) const { return Vector3<T>(this->x + other.x, this->y + other.y, this->z + other.z); }
    Vector3<T> operator-(Vector3<T>& other) const { return Vector3<T>(this->x - other.x, this->y - other.y, this->z - other.z); }
    Vector3<T> operator*(Vector3<T>& other) const { return Vector3<T>(this->x * other.x, this->y * other.y, this->z * other.z); }
    Vector3<T> operator/(Vector3<T>& other) const { return Vector3<T>(this->x / other.x, this->y / other.y, this->z / other.z); }
    Vector3<T>& operator+=(Vector3<T>& other) { this->x += other.x; this->y += other.y; this->z += other.z; return *this; }
    Vector3<T>& operator-=(Vector3<T>& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this; }
    Vector3<T>& operator*=(Vector3<T>& other) { this->x *= other.x; this->y *= other.y; this->z *= other.z; return *this; }
    Vector3<T>& operator/=(Vector3<T>& other) { this->x /= other.x; this->y /= other.y; this->z /= other.z; return *this; }
    Vector3<T> operator+(T other) const { return Vector3<T>(this->x + other, this->y + other, this->z + other); }
    Vector3<T> operator-(T other) const { return Vector3<T>(this->x - other, this->y - other, this->z - other); }
    Vector3<T> operator*(T other) const { return Vector3<T>(this->x * other, this->y * other, this->z * other); }
    Vector3<T> operator/(T other) const { return Vector3<T>(this->x / other, this->y / other, this->z / other); }
    Vector3<T>& operator+=(T other) { this->x += other; this->y += other; this->z += other; return *this; }
    Vector3<T>& operator-=(T other) { this->x -= other; this->y -= other; this->z -= other; return *this; }
    Vector3<T>& operator*=(T other) { this->x *= other; this->y *= other; this->z *= other; return *this; }
    Vector3<T>& operator/=(T other) { this->x /= other; this->y /= other; this->z /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
    //Returns in RADIANS
    Vector2<T> CalcAngleRad(Vector3<T> target)
    {
        Vector2<T> vec2;
        T dX = this->x - target.x;
        T dY = this->y - target.y;
        T dZ = this->z - target.z;
        double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
        vec2.x = ((T)atan2(dY, (float)distance) * (float)3.13810205 / (float)3.141592653589793);
        vec2.y = ((T)atan2(dZ, dX) * (float)3.13810205 / (float)3.141592653589793) + (float)1.569051027;
        return vec2;
    }
    //Returns in DEGREES
    Vector2<T> CalcAngleDeg(Vector3<T> target)
    {
        return CalcAngleRad(target) * (180.0 / 3.141592653589793238463);
    }
    //Also returns in Degrees
    Vector2<T> CalcAngle(Vector3<T> target) {
        return CalcAngleDeg(target);
    }
};

template<typename T>
struct Vector4 : public Vector3<T>
{
    T w = 0;
    Vector4() = default;
    Vector4(T x, T y, T z, T w) : Vector3<T>(x, y, z), w(w) { }
    float DistanceTo(Vector4<T>& other) const { return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2) + pow(other.w - this->w, 2)); }
    std::string to_string() const { return Vector3<T>::to_string() + "," + std::to_string(w); }
    Vector4<T> operator+(Vector4<T>& other) const { return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w); }
    Vector4<T> operator-(Vector4<T>& other) const { return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w); }
    Vector4<T> operator*(Vector4<T>& other) const { return Vector4(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w); }
    Vector4<T> operator/(Vector4<T>& other) const { return Vector4(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w); }
    Vector4<T>& operator+=(Vector4<T>& other) { this->x += other.x; this->y += other.y; this->z += other.z; this->w += other.w; return *this; }
    Vector4<T>& operator-=(Vector4<T>& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; this->w -= other.w; return *this; }
    Vector4<T>& operator*=(Vector4<T>& other) { this->x *= other.x; this->y *= other.y; this->z *= other.z; this->w *= other.w; return *this; }
    Vector4<T>& operator/=(Vector4<T>& other) { this->x /= other.x; this->y /= other.y; this->z /= other.z; this->w /= other.w; return *this; }
    Vector4<T> operator+(T other) const { return Vector4<T>(this->x + other, this->y + other, this->z + other, this->w + other); }
    Vector4<T> operator-(T other) const { return Vector4<T>(this->x - other, this->y - other, this->z - other, this->w - other); }
    Vector4<T> operator*(T other) const { return Vector4<T>(this->x * other, this->y * other, this->z * other, this->w * other); }
    Vector4<T> operator/(T other) const { return Vector4<T>(this->x / other, this->y / other, this->z / other, this->w / other); }
    Vector4<T>& operator+=(T other) { this->x += other; this->y += other; this->z += other; this->w += other; return *this; }
    Vector4<T>& operator-=(T other) { this->x -= other; this->y -= other; this->z -= other; this->w -= other; return *this; }
    Vector4<T>& operator*=(T other) { this->x *= other; this->y *= other; this->z *= other; this->w *= other; return *this; }
    Vector4<T>& operator/=(T other) { this->x /= other; this->y /= other; this->z /= other; this->w /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

struct RectangleArea : public Vector4<float> {
    RectangleArea() : RectangleArea(0, 0) {};
    RectangleArea(float x, float y) : RectangleArea(Vector2<float>(x, y)) {};
    RectangleArea(Vector2<float> vec2) : RectangleArea(vec2, Vector2<float>(vec2.x + 1000, vec2.y + 1000)) {};
    RectangleArea(Vector2<float> position, Vector2<float> size) : RectangleArea(position.x, position.y, size.x, size.y) {};
    RectangleArea(float x, float y, float w, float h) : Vector4<float>(x, x + w, y, y + h) {};
};