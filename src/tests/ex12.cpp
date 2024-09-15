/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:11:27 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 17:50:30 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_inverse();
void test_inverse_invalid();
void test_inverse_invalid_shape();
void test_inverse_invalid_size();

int main()
{
    test_inverse();
    test_inverse_invalid();
    test_inverse_invalid_shape();
    test_inverse_invalid_size();

    return 0;
}

void test_inverse()
{
    double elements_1[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    double elements_2[] = {2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0};
    double elements_3[] = {8.0, 5.0, -2.0, 4.0, 7.0, 20.0, 7.0, 6.0, 1.0};

    double expected_1[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    double expected_2[] = {0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5};
    double expected_3[] = {0.649425287, 0.097701149, -0.655172414, -0.781609195,
        -0.126436782, 0.965517241, 0.143678161, 0.074712644, -0.206896552};

    Matrix<double> mat_1(elements_1, 3, 3);
    Matrix<double> mat_2(elements_2, 3, 3);
    Matrix<double> mat_3(elements_3, 3, 3);

    Matrix<double> exp_1(expected_1, 3, 3);
    Matrix<double> exp_2(expected_2, 3, 3);
    Matrix<double> exp_3(expected_3, 3, 3);

    assert(mat_1.inverse() == exp_1);
    assert(mat_2.inverse() == exp_2);
    assert(mat_3.inverse() == exp_3);

    std::cout << "Test inverse passed." << std::endl;
}

void test_inverse_invalid()
{
    double elements_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    Matrix<double> mat_1(elements_1, 3, 3);

    try
    {
        mat_1.inverse();
    }
    catch(const std::exception& e)
    {
        std::cout << "Test inverse invalid passed: "
            << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test inverse invalid failed.");
}

void test_inverse_invalid_shape()
{
    double elements_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    Matrix<double> mat_1(elements_1, 9, 1);

    try
    {
        mat_1.inverse();
    }
    catch(const std::exception& e)
    {
        std::cout << "Test inverse invalid shape passed: "
            << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test inverse invalid shape failed.");
}

void test_inverse_invalid_size()
{
    double elements_1[25];

    Matrix<double> mat_1(elements_1, 5, 5);

    try
    {
        mat_1.inverse();
    }
    catch(const std::exception& e)
    {
        std::cout << "Test inverse invalid size passed: "
            << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test inverse invalid size failed.");
}
