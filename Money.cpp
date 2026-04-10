#include "Money.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace {
long long packMoney(const LongLong &h) {
  return (static_cast<long long>(h.getHigh()) << 32) |
         (h.getLow() & 0xFFFFFFFF);
}

long long getTotalKopecks(const Money &m) {
  return packMoney(m.getHryvnias()) * 100 + m.getKopecks();
}

Money fromTotalKopecks(long long total) {
  long long h = total / 100;
  int k = total % 100;
  if (k < 0) {
    h -= 1;
    k += 100;
  }
  return Money(LongLong(h >> 32, h & 0xFFFFFFFF),
               static_cast<unsigned char>(k));
}
} // namespace

Money::Money() : hryvnias(LongLong(0, 0)), kopecks(0) {}
Money::Money(const LongLong &h, unsigned char k) : hryvnias(h), kopecks(k) {
  if (kopecks >= 100) {
    long additionalHryvnias = kopecks / 100;
    kopecks %= 100;
    long long curH = packMoney(hryvnias) + additionalHryvnias;
    hryvnias = LongLong(curH >> 32, curH & 0xFFFFFFFF);
  }
}
Money::Money(const Money &other)
    : hryvnias(other.hryvnias), kopecks(other.kopecks) {}

LongLong Money::getHryvnias() const { return hryvnias; }
unsigned char Money::getKopecks() const { return kopecks; }
void Money::setHryvnias(const LongLong &h) { hryvnias = h; }
void Money::setKopecks(unsigned char k) {
  kopecks = k;
  if (kopecks >= 100) {
    long additionalHryvnias = kopecks / 100;
    kopecks %= 100;
    long long curH = packMoney(hryvnias) + additionalHryvnias;
    hryvnias = LongLong(curH >> 32, curH & 0xFFFFFFFF);
  }
}

void Money::Read() {
  long long h;
  unsigned int k;
  std::cout << "Введіть гривні (повне число): ";
  std::cin >> h;
  std::cout << "Введіть копійки: ";
  std::cin >> k;

  hryvnias = LongLong(h >> 32, h & 0xFFFFFFFF);
  setKopecks(static_cast<unsigned char>(k));
}

void Money::Display() const { std::cout << toString() << std::endl; }

std::string Money::toString() const {
  std::ostringstream oss;
  long long h_val = packMoney(hryvnias);
  oss << h_val << "," << std::setfill('0') << std::setw(2)
      << (unsigned int)kopecks;
  return oss.str();
}

Money Money::operator+(const Money &other) const {
  return fromTotalKopecks(getTotalKopecks(*this) + getTotalKopecks(other));
}

Money Money::operator-(const Money &other) const {
  return fromTotalKopecks(getTotalKopecks(*this) - getTotalKopecks(other));
}

Money Money::operator*(double x) const {
  long double tk = static_cast<long double>(getTotalKopecks(*this)) * x;
  return fromTotalKopecks(static_cast<long long>(std::round(tk)));
}

Money Money::operator/(double x) const {
  if (x == 0)
    throw std::invalid_argument("Ділення на нуль");
  long double tk = static_cast<long double>(getTotalKopecks(*this)) / x;
  return fromTotalKopecks(static_cast<long long>(std::round(tk)));
}

double Money::operator/(const Money &other) const {
  long long otherTk = getTotalKopecks(other);
  if (otherTk == 0)
    throw std::invalid_argument("Ділення на нуль при діленні сум");
  return static_cast<double>(getTotalKopecks(*this)) / otherTk;
}

bool Money::operator==(const Money &other) const {
  return getTotalKopecks(*this) == getTotalKopecks(other);
}
bool Money::operator!=(const Money &other) const {
  return getTotalKopecks(*this) != getTotalKopecks(other);
}
bool Money::operator<(const Money &other) const {
  return getTotalKopecks(*this) < getTotalKopecks(other);
}
bool Money::operator>(const Money &other) const {
  return getTotalKopecks(*this) > getTotalKopecks(other);
}
bool Money::operator<=(const Money &other) const {
  return getTotalKopecks(*this) <= getTotalKopecks(other);
}
bool Money::operator>=(const Money &other) const {
  return getTotalKopecks(*this) >= getTotalKopecks(other);
}
