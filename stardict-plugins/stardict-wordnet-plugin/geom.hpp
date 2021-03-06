#ifndef __GEOM_H__
#define __GEOM_H__

#include "utils.hpp"

template<class T>
struct point_t {
	T x; 
	T y;
	point_t(T ix, T iy): x(ix), y(iy) {}
};

template<class T>
struct tsize_t {
	T w; 
	T h;
	tsize_t(T iw, T ih): w(iw), h(ih) {}
};

template<class T>
struct rect_t {
	point_t<T> center;
	tsize_t<T> size;
	rect_t(T ix, T iy, T iw, T ih): center(ix, iy), size(iw, ih) {}
	bool overlay(const rect_t<T> & b) {
		return (2*tabs(this->center.x-b.center.x) < (this->size.w+b.size.w)) &&
			(2*tabs(this->center.y-b.center.y) < (this->size.h+b.size.h));
	}

	// 这个计算现在不准，呵呵，在我们的系统里面，其实不用准的
	T overlayarea(const rect_t<T> & b) {
		return (-tabs(this->center.x-b.center.x) + (this->size.w+b.size.w)/2)*
			(-tabs(this->center.y-b.center.y) + (this->size.h+b.size.h)/2);
	}
};

#endif // __GEOM_H__

