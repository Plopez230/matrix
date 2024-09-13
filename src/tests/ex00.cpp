/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:17:59 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 01:13:53 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "matrix.hpp"

template <typename K>
bool matrix_equality(const Matrix<K>& a, const Matrix<K>& b);
void test_add();
void test_subtract();
void test_scale();

int main() {
    test_add();
    test_subtract();
    test_scale();
    return 0;
}

template <typename K>
bool matrix_equality(const Matrix<K>& a, const Matrix<K>& b) {
    const int *a_shape = a.get_shape();
    const int *b_shape = b.get_shape();

    if (a_shape[0] != b_shape[0] || a_shape[1] != b_shape[1])
    {
        return false;
    }

    for (int i = 0; i < a_shape[0]; ++i)
    {
        for (int j = 0; j < a_shape[1]; ++j)
        {
            if (a.get_element(i, j) != b.get_element(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

void test_add() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {4, 3, 2, 1};
    int expected_values[] = {5, 5, 5, 5};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> expected(expected_values, 2, 2);

    A.add(B);

    assert(matrix_equality(A, expected));
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

    assert(matrix_equality(A, expected));
    std::cout << "Test subtract passed." << std::endl;
}

void test_scale() {
    int values_a[] = {1, 2, 3, 4};
    int expected_values[] = {2, 4, 6, 8};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> expected(expected_values, 2, 2);

    A.scale(2);

    assert(matrix_equality(A, expected));
    std::cout << "Test scale passed." << std::endl;
}
