#include "Money.h"
#include <iostream>

int main() {
  Money m1, m2;
  double scalar;

  std::cout << "--- Перша сума (m1) ---" << std::endl;
  m1.Read();
  std::cout << "\n--- Друга сума (m2) ---" << std::endl;
  m2.Read();
  std::cout << "\nВведіть дробове число для множення/ділення: ";
  std::cin >> scalar;

  std::cout << "\nm1 = ";
  m1.Display();
  std::cout << "m2 = ";
  m2.Display();

  Money sum = m1 + m2;
  Money diff = m1 - m2;
  Money mul = m1 * scalar;
  Money divScalar = m1 / scalar;
  double divSums = m1 / m2;

  std::cout << "\nСума (m1 + m2): " << sum.toString() << std::endl;
  std::cout << "Різниця (m1 - m2): " << diff.toString() << std::endl;
  std::cout << "Множення (m1 * " << scalar << "): " << mul.toString()
            << std::endl;
  std::cout << "Ділення суми на число (m1 / " << scalar
            << "): " << divScalar.toString() << std::endl;
  std::cout << "Ділення суми на суму (m1 / m2): " << divSums << std::endl;

  std::cout << "\nПорівняння:" << std::endl;
  std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
  std::cout << "m1 != m2 : " << (m1 != m2) << std::endl;
  std::cout << "m1 < m2  : " << (m1 < m2) << std::endl;
  std::cout << "m1 > m2  : " << (m1 > m2) << std::endl;
  std::cout << "m1 <= m2 : " << (m1 <= m2) << std::endl;
  std::cout << "m1 >= m2 : " << (m1 >= m2) << std::endl;

  return 0;
}
