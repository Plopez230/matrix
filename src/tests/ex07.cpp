/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:54:05 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 03:01:28 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_mul_vec();
void test_mul_vec_invalid();
void test_mul_mat();
void test_mul_mat_invalid();

int main()
{
    test_mul_vec();
    test_mul_vec_invalid();
    test_mul_mat();
    test_mul_mat_invalid();

    return 0;
}

void test_mul_vec()
{
    double mat_elements_1[] = {1.0, 0.0, 0.0, 1.0};
    double mat_elements_2[] = {2.0, 0.0, 0.0, 2.0};
    double mat_elements_3[] = {2.0, -2.0, -2.0, 2.0};
    double vec_elements_1[] = {4.0, 2.0};
    double expected_1[] = {4.0, 2.0};
    double expected_2[] = {8.0, 4.0};
    double expected_3[] = {4.0, -4.0};

    Matrix<double> mat_1(mat_elements_1, 2, 2);
    Matrix<double> mat_2(mat_elements_2, 2, 2);
    Matrix<double> mat_3(mat_elements_3, 2, 2);

    Vector<double> vec_1(vec_elements_1, 2);

    Vector<double> exp_1(expected_1, 2);
    Vector<double> exp_2(expected_2, 2);
    Vector<double> exp_3(expected_3, 2);

    assert(exp_1 == mat_1.mul_vec(vec_1));
    assert(exp_2 == mat_2.mul_vec(vec_1));
    assert(exp_3 == mat_3.mul_vec(vec_1));

    std::cout << "Test mul vec passed." << std::endl;
}

void test_mul_vec_invalid()
{
    double mat_elements_1[] = {1.0, 0.0, 0.0, 1.0};
    double vec_elements_1[] = {4.0};

    Matrix<double> mat_1(mat_elements_1, 2, 2);

    Vector<double> vec_1(vec_elements_1, 1);

    try
    {
        mat_1.mul_vec(vec_1);
    }
    catch(const std::exception& e)
    {
        std::cout << "Test mul vec invalid passed: " << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test mul vec invalid failed.");
}

void test_mul_mat()
{
    double elements_1[] = {1.0, 0.0, 0.0, 1.0};
    double elements_2[] = {2.0, 1.0, 4.0, 2.0};
    double elements_3[] = {3.0, -5.0, 6.0, 8.0};
    double elements_4[] = {1.0, 2.0, -1.0, 0.0, -3.0, -1.0};
    double elements_5[] = {2.0, 0.0, 1.0, -5.0, 2.0, 3.0};

    double expected_1[] = {1.0, 0.0, 0.0, 1.0};
    double expected_2[] = {2.0, 1.0, 4.0, 2.0};
    double expected_3[] = {-14.0, -7.0, 44.0, 22.0};
    double expected_4[] = {-8.0, 4.0, 7.0, -2.0, 0.0, -1.0, -1.0, -2.0, -6.0};

    Matrix<double> mat_1(elements_1, 2, 2);
    Matrix<double> mat_2(elements_2, 2, 2);
    Matrix<double> mat_3(elements_3, 2, 2);
    Matrix<double> mat_4(elements_4, 3, 2);
    Matrix<double> mat_5(elements_5, 2, 3);

    Matrix<double> exp_1(expected_1, 2, 2);
    Matrix<double> exp_2(expected_2, 2, 2);
    Matrix<double> exp_3(expected_3, 2, 2);
    Matrix<double> exp_4(expected_4, 3, 3);

    assert(exp_1 == mat_1.mul_mat(mat_1));
    assert(exp_2 == mat_1.mul_mat(mat_2));
    assert(exp_3 == mat_3.mul_mat(mat_2));
    assert(exp_4 == mat_4.mul_mat(mat_5));

    std::cout << "Test mul mat passed." << std::endl;
}

void test_mul_mat_invalid()
{
    double elements_1[] = {1.0, 0.0, 0.0, 1.0};
    double elements_2[] = {2.0, 1.0, 4.0, 2.0};

    Matrix<double> mat_1(elements_1, 2, 2);
    Matrix<double> mat_2(elements_2, 4, 1);

    try
    {
        mat_1.mul_mat(mat_2);
    }
    catch(const std::exception& e)
    {
        std::cout << "Test mul mat invalid passed: " << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test mul mat invalid failed.");
}
