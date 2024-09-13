/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:23:11 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 00:05:18 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "matrix.hpp"

void test_constructor();
void test_constructor_copy();
void test_get_element();
void test_set_element();
void test_get_shape();
void test_is_square();
void test_print();
void test_reget_shape();
void test_exceptions();

int main()
{
    test_constructor();
    test_constructor_copy();
    test_get_element();
    test_set_element();
    test_get_shape();
    test_is_square();
    test_print();
    test_reget_shape();
    test_exceptions();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

void test_constructor()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);
    assert(m.get_element(0, 0) == 1);
    assert(m.get_element(0, 1) == 2);
    assert(m.get_element(1, 0) == 3);
    assert(m.get_element(1, 1) == 4);
}

void test_constructor_copy()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m1(elements, 2, 2);
    Matrix<int> m2(m1);

    assert(m2.get_element(0, 0) == 1);
    assert(m2.get_element(0, 1) == 2);
    assert(m2.get_element(1, 0) == 3);
    assert(m2.get_element(1, 1) == 4);
}

void test_get_element()
{
    int elements[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m(elements, 2, 3);

    assert(m.get_element(0, 0) == 1);
    assert(m.get_element(1, 2) == 6);
}

void test_set_element()
{
    int elements[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m(elements, 2, 3);

    m.set_element(10, 0, 1); // Changing element at (0, 1) from 2 to 10
    assert(m.get_element(0, 1) == 10);

    m.set_element(20, 1, 2); // Changing element at (1, 2) from 6 to 20
    assert(m.get_element(1, 2) == 20);
}

void test_get_shape()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    const int* shape = m.get_shape();
    assert(shape[0] == 2); // Rows
    assert(shape[1] == 2); // Columns
}

void test_is_square()
{
    int elements1[] = {1, 2, 3, 4};
    Matrix<int> m1(elements1, 2, 2); // Square matrix
    assert(m1.is_square() == 1);

    int elements2[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m2(elements2, 2, 3); // Non-square matrix
    assert(m2.is_square() == 0);
}

void test_print()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    std::cout << "Expected output:\n1 2\n3 4\nActual output:\n";
    m.print(); // Should print the matrix in a readable format
}

void test_reget_shape()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    m.reshape(1, 4); // Reshaping from 2x2 to 1x4
    assert(m.get_element(0, 0) == 1);
    assert(m.get_element(0, 3) == 4);

    const int* shape = m.get_shape();
    assert(shape[0] == 1); // Rows
    assert(shape[1] == 4); // Columns
}

void test_exceptions()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    // Testing out-of-range access
    try {
        m.get_element(3, 3); // Should throw an exception
        assert(false); // Should not reach this line
    } catch (const std::out_of_range& e) {
        assert(true); // Exception was correctly thrown
    }

    // Testing invalid reshape
    try {
        m.reshape(1, 3); // Invalid reshape, should throw an exception
        assert(false); // Should not reach this line
    } catch (const std::invalid_argument& e) {
        assert(true); // Exception was correctly thrown
    }
}
