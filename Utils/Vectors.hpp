#pragma once

// vec2_t Class container that stores all our variables and functions for using vec2_t. 
class vec2_t {
public:
	float x, y;

	vec2_t() {
		x = 0; y = 0;
	};
	vec2_t(float X, float Y) {
		x = X; y = Y;
	};
	inline vec2_t operator*(const float n) const {
		return vec2_t(x * n, y * n);
	}
	inline vec2_t operator+(const vec2_t& v) const {
		return vec2_t(x + v.x, y + v.y);
	}
	inline vec2_t operator-(const vec2_t& v) const {
		return vec2_t(x - v.x, y - v.y);
	}
	inline void operator+=(const vec2_t& v) {
		x += v.x;
		y += v.y;
	}
	inline void operator-=(const vec2_t& v) {
		x -= v.x;
		y -= v.y;
	}
	bool operator>(const vec2_t& v) const {
		return (v.x > x && v.y > y);
	}
	bool operator==(const vec2_t& v) const {
		return (v.x == x && v.y == y);
	}
	bool operator!=(const vec2_t& v) const {
		return (v.x != x || v.y != y);
	}
	inline float length() {
		return sqrt((x * x) + (y * y));
	}
};