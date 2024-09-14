/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:23:11 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 16:05:07 by plopez-b         ###   ########.fr       */
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
void test_is_vector();
void test_print();
void test_reshape_matrix_matrix();
void test_reshape_matrix_vector();
void test_equality_operator();
void test_exceptions();

int main()
{
    test_constructor();
    test_constructor_copy();
    test_get_element();
    test_set_element();
    test_get_shape();
    test_is_square();
    test_is_vector();
    test_print();
    test_reshape_matrix_matrix();
    test_reshape_matrix_vector();
    test_equality_operator();
    test_exceptions();

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
    std::cout << "Test constructor passed." << std::endl;
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
    std::cout << "Test constructor copy passed." << std::endl;
}

void test_get_element()
{
    int elements[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m(elements, 2, 3);

    assert(m.get_element(0, 0) == 1);
    assert(m.get_element(1, 2) == 6);
    std::cout << "Test get element passed." << std::endl;
}

void test_set_element()
{
    int elements[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m(elements, 2, 3);

    m.set_element(10, 0, 1);
    assert(m.get_element(0, 1) == 10);

    m.set_element(20, 1, 2);
    assert(m.get_element(1, 2) == 20);
    std::cout << "Test set element passed." << std::endl;
}

void test_get_shape()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    const int* shape = m.get_shape();
    assert(shape[0] == 2);
    assert(shape[1] == 2);
    std::cout << "Test get shape passed." << std::endl;
}

void test_is_square()
{
    int elements1[] = {1, 2, 3, 4};
    Matrix<int> m1(elements1, 2, 2);
    assert(m1.is_square() == 1);

    int elements2[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m2(elements2, 2, 3);
    assert(m2.is_square() == 0);
    std::cout << "Test is square passed." << std::endl;
}

void test_is_vector()
{
    int elements1[] = {1, 2, 3, 4};
    Matrix<int> m1(elements1, 4, 0);
    assert(m1.is_vector() == 1);

    int elements2[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m2(elements2, 2, 3);
    assert(m2.is_vector() == 0);
    std::cout << "Test is vector passed." << std::endl;
}

void test_print()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    std::cout << "Expected output:\n1 2\n3 4\nActual output:\n";
    m.print();
    std::cout << "Test print passed." << std::endl;
}

void test_reshape_matrix_matrix()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);
    Matrix<int> reshaped;

    reshaped = m.reshape(1, 4);
    assert(reshaped.get_element(0, 0) == 1);
    assert(reshaped.get_element(0, 3) == 4);

    const int* shape = reshaped.get_shape();
    assert(shape[0] == 1);
    assert(shape[1] == 4);
    std::cout << "Test reshape matrix to matrix passed." << std::endl;
}

void test_reshape_matrix_vector()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);
    Vector<int> reshaped;

    reshaped = m.reshape(4);
    assert(reshaped.get_element(0) == 1);
    assert(reshaped.get_element(3) == 4);

    const int* shape = reshaped.get_shape();
    assert(shape[0] == 4);
    assert(shape[1] == 1);
    std::cout << "Test reshape matrix to vector passed." << std::endl;
}

void test_equality_operator() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {1, 2, 3, 4};
    int values_c[] = {4, 3, 2, 1};
    
    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> C(values_c, 2, 2);
    Matrix<int> D(values_b, 1, 4);

    assert(A == B);
    assert(!(A == C));
    assert(!(A == D));
    std::cout << "Test equality operator passed." << std::endl;
}

void test_exceptions()
{
    int elements[] = {1, 2, 3, 4};
    Matrix<int> m(elements, 2, 2);

    try
    {
        m.get_element(3, 3);
        assert(false);
    }
    catch (const std::out_of_range& e)
    {
        assert(true);
    }

    try
    {
        m.reshape(1, 3);
        assert(false);
    }
    catch (const std::invalid_argument& e)
    {
        assert(true);
    }
    std::cout << "Test exceptions passed." << std::endl;
}
