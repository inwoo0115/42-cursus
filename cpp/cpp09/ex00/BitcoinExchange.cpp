#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readCsv() {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    throw std::runtime_error("Error: Could not open the file.");
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line != "date,exchange_rate") {
      std::stringstream ss(line);
      std::string dateStr, rateStr;
      std::getline(ss, dateStr, ',');
      std::getline(ss, rateStr, ',');
      int date = checkDate(dateStr);
      if (date == -1) throw std::out_of_range("Error: Date is out of range.");
      double rate = checkRate(rateStr);
      if (rate == -1) throw std::out_of_range("Error: Rate is out of range.");
      dataMap[date] = rate;
    }
  }
  file.close();
}

int BitcoinExchange::checkDate(std::string line) {
  int year, month, day;
  std::stringstream ss(line);
  std::string data;
  std::getline(ss, data, '-');
  std::istringstream(data) >> year;
  if (year < 1 || year > 9999) return -1;
  std::getline(ss, data, '-');
  std::istringstream(data) >> month;
  if (month < 1 || month > 12) return -1;
  std::getline(ss, data, '-');
  std::istringstream(data) >> day;
  if (day < 1 || day > 31) return -1;
  if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
    return -1;
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    if (day > 29 && month == 2) return -1;
  } else if (day > 28 && month == 2)
    return -1;
  return (year * 1000 + month * 100 + day);
}

double BitcoinExchange::checkRate(std::string line) {
  char *ptr = NULL;
  double d = std::strtod(line.c_str(), &ptr);
  if (d == 0.0 && !std::isdigit(line[0])) return -1;
  if (*ptr && std::strcmp(ptr, "f")) return -1;
  if (d < 0) return -1;
  return static_cast<double>(d);
}

void BitcoinExchange::readInput(const std::string file) {
  std::ifstream input(file);
  if (!input.is_open()) {
    throw std::runtime_error("Error: Could not open the file.");
  }
  std::string line;
  while (std::getline(input, line)) {
    if (line != "date | value") {
      std::stringstream ss(line);
      std::string dateStr, bar, valueStr;
      std::getline(ss, dateStr, ' ');
      int date = checkDate(dateStr);
      if (date == -1) {
        std::cout << "Error: bad input => " << dateStr << std::endl;
        continue;
      }
      std::getline(ss, bar, ' ');
      if (bar != "|") {
        std::cout << "Wrong form" << std::endl;
        continue;
      }
      std::getline(ss, valueStr, ' ');
      double value = checkRate(valueStr);
      if (value == -1 || value > 1000) {
        std::cout << "Error: not a proper number" << std::endl;
        continue;
      }
      std::map<int, double>::iterator it;
      double rate;
      it = dataMap.find(date);
      if (it != dataMap.end())
        rate = dataMap[date] * value;
      else {
        it = dataMap.lower_bound(date);
        if (it == dataMap.begin()) {
          std::cout << "Error : invalid date" << std::endl;
          continue;
        }
        rate = it->second * value;
      }
      std::cout << dateStr << " => " << valueStr << " = " << rate << std::endl;
    }
  }
  input.close();
}
