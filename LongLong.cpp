#include "LongLong.h"
#include <sstream>
#include <stdexcept>

namespace {
long long pack(long h, unsigned long l) {
  return (static_cast<long long>(h) << 32) | (l & 0xFFFFFFFF);
}
} // namespace

LongLong::LongLong() : high(0), low(0) {}
LongLong::LongLong(long h, unsigned long l) : high(h), low(l) {}
LongLong::LongLong(const LongLong &other) : high(other.high), low(other.low) {}

long LongLong::getHigh() const { return high; }
unsigned long LongLong::getLow() const { return low; }
void LongLong::setHigh(long h) { high = h; }
void LongLong::setLow(unsigned long l) { low = l; }

LongLong LongLong::operator+(const LongLong &other) const {
  long long res = pack(high, low) + pack(other.high, other.low);
  return LongLong(res >> 32, res & 0xFFFFFFFF);
}

LongLong LongLong::operator-(const LongLong &other) const {
  long long res = pack(high, low) - pack(other.high, other.low);
  return LongLong(res >> 32, res & 0xFFFFFFFF);
}

LongLong LongLong::operator*(const LongLong &other) const {
  long long res = pack(high, low) * pack(other.high, other.low);
  return LongLong(res >> 32, res & 0xFFFFFFFF);
}

LongLong LongLong::operator/(const LongLong &other) const {
  long long v2 = pack(other.high, other.low);
  if (v2 == 0)
    throw std::invalid_argument("Ділення на нуль (LongLong)");
  long long res = pack(high, low) / v2;
  return LongLong(res >> 32, res & 0xFFFFFFFF);
}

LongLong LongLong::operator%(const LongLong &other) const {
  long long v2 = pack(other.high, other.low);
  if (v2 == 0)
    throw std::invalid_argument("Ділення на нуль (LongLong)");
  long long res = pack(high, low) % v2;
  return LongLong(res >> 32, res & 0xFFFFFFFF);
}

bool LongLong::operator==(const LongLong &other) const {
  return pack(high, low) == pack(other.high, other.low);
}
bool LongLong::operator!=(const LongLong &other) const {
  return pack(high, low) != pack(other.high, other.low);
}
bool LongLong::operator<(const LongLong &other) const {
  return pack(high, low) < pack(other.high, other.low);
}
bool LongLong::operator>(const LongLong &other) const {
  return pack(high, low) > pack(other.high, other.low);
}
bool LongLong::operator<=(const LongLong &other) const {
  return pack(high, low) <= pack(other.high, other.low);
}
bool LongLong::operator>=(const LongLong &other) const {
  return pack(high, low) >= pack(other.high, other.low);
}

std::string LongLong::toString() const {
  std::ostringstream oss;
  oss << pack(high, low);
  return oss.str();
}
