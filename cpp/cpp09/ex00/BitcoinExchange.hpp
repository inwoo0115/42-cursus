#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
 private:
  std::map<int, double> dataMap;
  BitcoinExchange(const BitcoinExchange& obj);
  BitcoinExchange operator=(const BitcoinExchange& obj);

 public:
  BitcoinExchange();
  ~BitcoinExchange();
  void readCsv();
  int checkDate(std::string line);
  double checkRate(std::string line);
  void readInput(const std::string file);
};

#endif