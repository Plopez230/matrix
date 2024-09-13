/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:17:59 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 01:40:35 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "matrix.hpp"

void test_add();
void test_subtract();
void test_scale();

int main() {
    test_add();
    test_subtract();
    test_scale();
    return 0;
}

void test_add() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {4, 3, 2, 1};
    int expected_values[] = {5, 5, 5, 5};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> expected(expected_values, 2, 2);

    A.add(B);

    assert(A == expected);
    std::cout << "Test add passed." << std::endl;
}

void test_subtract() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {4, 3, 2, 1};
    int expected_values[] = {-3, -1, 1, 3};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> expected(expected_values, 2, 2);

    A.subtract(B);

    assert(A == expected);
    std::cout << "Test subtract passed." << std::endl;
}

void test_scale() {
    int values_a[] = {1, 2, 3, 4};
    int expected_values[] = {2, 4, 6, 8};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> expected(expected_values, 2, 2);

    A.scale(2);

    assert(A == expected);
    std::cout << "Test scale passed." << std::endl;
}
