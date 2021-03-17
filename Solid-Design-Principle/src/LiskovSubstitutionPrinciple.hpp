/*
 * Description -
 *
 * @authors Suhail.m (suhail.m@greyorange.com)
 * @date    2021-03-17 19:08:20
 *
 */

#include <iostream>

template <class T>
class Rectangle {
 protected:
  T _width;
  T _height;

 public:
  Rectangle(T height, T width) : _width(width), _height(height) {}
  virtual void setWidth(const T& width) { _width = width; }
  virtual void setHeight(const T& height) { _height = height; }
  T getWidth() { return _width; }
  T getHeight() { return _height; }
  T area() const { return _width * _height; }
};

/* Here Setter methods will break the substitution principle for any operation where the derived type could be substituted inplace of Base  */

template <class T>
class Square : public Rectangle<T> {
 public:
  Square(T a) : Rectangle<T>(a, a) {}
  void setWidth(const T& width) override { this->_width = this->_height = width; }
  void setHeight(const T& height) override { this->_height = this->_width = height; }
};
