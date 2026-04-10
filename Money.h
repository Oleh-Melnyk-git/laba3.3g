#ifndef MONEY_H
#define MONEY_H

#include "LongLong.h"
#include <iostream>
#include <string>

class Money {
private:
  LongLong hryvnias;     // гривні
  unsigned char kopecks; // копійки
public:
  // Конструктори
  Money();
  Money(const LongLong &h, unsigned char k);
  Money(const Money &other);

  // Методи доступу
  LongLong getHryvnias() const;
  unsigned char getKopecks() const;
  void setHryvnias(const LongLong &h);
  void setKopecks(unsigned char k);

  // Основні методи
  void Read();
  void Display() const;
  std::string toString() const;

  // Арифметичні оператори
  Money operator+(const Money &other) const;
  Money operator-(const Money &other) const;
  Money operator*(double x) const;
  Money operator/(double x) const;
  double operator/(const Money &other)
      const; // ділення сум повертає дробове число (разовість)

  // Порівняння
  bool operator==(const Money &other) const;
  bool operator!=(const Money &other) const;
  bool operator<(const Money &other) const;
  bool operator>(const Money &other) const;
  bool operator<=(const Money &other) const;
  bool operator>=(const Money &other) const;
};

#endif
