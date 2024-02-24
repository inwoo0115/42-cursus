#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& obj);
  ScalarConverter& operator=(const ScalarConverter& obj);
  ~ScalarConverter();

 public:
  static void convert(std::string data);
};

#endif