#include "Rational.h"
#include <cmath>
#include <numeric>
#include <sstream>
#include <stdexcept>

int Object::counter = 0;

static int calculate_gcd(int a, int b) {
  a = std::abs(a);
  b = std::abs(b);
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void Rational::simplify() {
  int g = calculate_gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;
  if (denominator < 0) { // знаменник завжди додатній
    numerator = -numerator;
    denominator = -denominator;
  }
}

Rational::Rational() : numerator(0), denominator(1) {}
Rational::Rational(int a, int b) : numerator(a), denominator(b) {
  if (b == 0)
    throw std::invalid_argument("Denominator cannot be zero");
  simplify();
}
Rational::Rational(const Rational &other)
    : Object(other), numerator(other.numerator),
      denominator(other.denominator) {}

int Rational::getNumerator() const { return numerator; }
int Rational::getDenominator() const { return denominator; }
void Rational::setNumerator(int a) {
  numerator = a;
  simplify();
}
void Rational::setDenominator(int b) {
  if (b == 0)
    throw std::invalid_argument("Denominator cannot be zero");
  denominator = b;
  simplify();
}

void Rational::Init(int a, int b) {
  if (b == 0)
    throw std::invalid_argument("Denominator cannot be zero");
  numerator = a;
  denominator = b;
  simplify();
}
void Rational::Read() {
  int a, b;
  std::cout << "Enter numerator: ";
  std::cin >> a;
  std::cout << "Enter denominator: ";
  std::cin >> b;
  Init(a, b);
}
void Rational::Display() const {
  std::cout << numerator << "/" << denominator << std::endl;
}
std::string Rational::toString() const {
  std::ostringstream oss;
  oss << numerator << "/" << denominator;
  return oss.str();
}

Rational &Rational::operator=(const Rational &other) {
  if (this != &other) {
    Object::operator=(other);
    numerator = other.numerator;
    denominator = other.denominator;
  }
  return *this;
}

Rational Rational::operator+(const Rational &other) const {
  return Rational(numerator * other.denominator + other.numerator * denominator,
                  denominator * other.denominator);
}
Rational Rational::operator-(const Rational &other) const {
  return Rational(numerator * other.denominator - other.numerator * denominator,
                  denominator * other.denominator);
}
Rational Rational::operator*(const Rational &other) const {
  return Rational(numerator * other.numerator, denominator * other.denominator);
}
Rational Rational::operator/(const Rational &other) const {
  if (other.numerator == 0)
    throw std::invalid_argument("Division by zero");
  return Rational(numerator * other.denominator, denominator * other.numerator);
}

bool Rational::operator==(const Rational &other) const {
  return numerator == other.numerator && denominator == other.denominator;
}
bool Rational::operator!=(const Rational &other) const {
  return !(*this == other);
}
bool Rational::operator<(const Rational &other) const {
  return numerator * other.denominator < other.numerator * denominator;
}
bool Rational::operator>(const Rational &other) const {
  return numerator * other.denominator > other.numerator * denominator;
}

Rational &Rational::operator++() {
  numerator += denominator;
  simplify();
  return *this;
}
Rational Rational::operator++(int) {
  Rational temp(*this);
  ++(*this);
  return temp;
}
Rational &Rational::operator--() {
  numerator -= denominator;
  simplify();
  return *this;
}
Rational Rational::operator--(int) {
  Rational temp(*this);
  --(*this);
  return temp;
}

Rational::operator std::string() const { return toString(); }
