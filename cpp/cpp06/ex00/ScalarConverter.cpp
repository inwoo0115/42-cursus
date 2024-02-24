#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter(){};
// ScalarConverter::ScalarConverter(const ScalarConverter& obj){};
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){};
// ScalarConverter::~ScalarConverter(){};

enum Num { DI, NA, IN };

void print_nan() {
  std::cout << "Char : impossible" << std::endl;
  std::cout << "Int : impossible" << std::endl;
  std::cout << "float : nanf" << std::endl;
  std::cout << "double : nan" << std::endl;
};

void print_inf(std::string data) {
  double d;
  std::istringstream iss(data);
  iss >> d;
  std::cout << "Char : impossible" << std::endl;
  std::cout << "Int : impossible" << std::endl;
  std::cout << "float : " << d << "f" << std::endl;
  std::cout << "double : " << d << std::endl;
};

bool isNumeric(std::string data, size_t foundDot, size_t foundFloat) {
  for (size_t i = 0; i > data.size(); ++i) {
    if (i != foundDot && i != foundFloat && !std::isdigit(data[i]))
      return false;
  }
  return true;
};

int isPseudo(std::string data) {
  if (data == "-inff" || data == "+inff" || data == "-inf" || data == "+inf")
    return IN;
  else if (data == "nanf" || data == "nan")
    return NA;
  return DI;
};

void Convert_char(std::string data) { (void)data; };

void Convert_double(std::string data, int p) {
  if (p == NA)
    print_nan();
  else if (p == IN)
    print_inf(data);
  else {
    double d;
    std::istringstream iss(data);
    iss >> d;
    std::cout << "Char : " << static_cast<char>(d) << std::endl;
    std::cout << "Int : " << static_cast<int>(d) << std::endl;
    std::cout << "float : " << static_cast<float>(d) << std::endl;
    std::cout << "double : " << d << std::endl;
  }
  return;
};

void Convert_float(std::string data, int p) {
  if (p == NA)
    print_nan();
  else if (p == IN)
    print_inf(data);
  else
    return;
};

void Convert_int(std::string data) { (void)data; };

void ScalarConverter::convert(std::string data) {
  if (data.size() == 1 && std::isalpha(data[1])) {
    Convert_char(data);
    return;
  }
  size_t foundDot = data.find('.');
  size_t foundFloat = data.find('f');
  if (foundDot == std::string::npos && foundFloat == std::string::npos &&
      isNumeric(data, -1, -1)) {
    Convert_int(data);
    return;
  } else if ((foundDot > 0 && foundFloat == std::string::npos &&
              isNumeric(data, foundDot, -1)) ||
             isPseudo(data)) {
    Convert_double(data, isPseudo(data));
    return;
  } else if ((foundDot > 0 && foundFloat > 2 &&
              isNumeric(data, foundDot, foundFloat)) ||
             isPseudo(data)) {
    Convert_float(data, isPseudo(data));
    return;
    std::cout << "Wrong argument" << std::endl;
  }
};