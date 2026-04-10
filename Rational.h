#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Object {
protected:
  static int counter;

public:
  Object() { counter++; }
  Object(const Object &) { counter++; }
  virtual ~Object() { counter--; }
  static int getCounter() { return counter; }
};

class Rational : public Object {
private:
  int numerator;
  int denominator;
  void simplify(); // скорочення дробу
public:
  // Конструктори
  Rational();                      // без аргументів
  Rational(int a, int b);          // ініціалізація
  Rational(const Rational &other); // копіювання

  // Методи доступу
  int getNumerator() const;
  int getDenominator() const;
  void setNumerator(int a);
  void setDenominator(int b);

  // Основні методи
  void Init(int a, int b);
  void Read();
  void Display() const;
  std::string toString() const;

  // Перевантаження операторів
  Rational &operator=(const Rational &other);
  Rational operator+(const Rational &other) const;
  Rational operator-(const Rational &other) const;
  Rational operator*(const Rational &other) const;
  Rational operator/(const Rational &other) const;

  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;
  bool operator<(const Rational &other) const;
  bool operator>(const Rational &other) const;

  // Інкремент/декремент
  Rational &operator++();   // префікс
  Rational operator++(int); // постфікс
  Rational &operator--();   // префікс
  Rational operator--(int); // постфікс

  // Перетворення у рядок
  operator std::string() const;
};

#endif
