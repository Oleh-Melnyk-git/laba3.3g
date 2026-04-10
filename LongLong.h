#ifndef LONGLONG_H
#define LONGLONG_H

#include <iostream>
#include <string>

class LongLong {
private:
  long high;         // старша частина
  unsigned long low; // молодша частина
public:
  // Конструктори
  LongLong();
  LongLong(long h, unsigned long l);
  LongLong(const LongLong &other);

  // Методи доступу
  long getHigh() const;
  unsigned long getLow() const;
  void setHigh(long h);
  void setLow(unsigned long l);

  // Арифметичні оператори
  LongLong operator+(const LongLong &other) const;
  LongLong operator-(const LongLong &other) const;
  LongLong operator*(const LongLong &other) const;
  LongLong operator/(const LongLong &other) const;
  LongLong operator%(const LongLong &other) const;

  // Порівняння
  bool operator==(const LongLong &other) const;
  bool operator!=(const LongLong &other) const;
  bool operator<(const LongLong &other) const;
  bool operator>(const LongLong &other) const;
  bool operator<=(const LongLong &other) const;
  bool operator>=(const LongLong &other) const;

  std::string toString() const;
};

#endif
