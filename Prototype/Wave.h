#ifndef WAVE_H
#define WAVE_H
#include <vector>

#include "Shape.h"

class Wave {

 public:
      void add (Shape*);
      void print() const;

 private:
 	std::vector<Shape*> shapes;
 };

 #endif WAVE_H