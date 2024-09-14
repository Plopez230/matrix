/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:24:57 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 20:50:21 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include "matrix.hpp"

void test_norm_1_vector();
void test_norm_vector();
void test_norm_inf_vector();
void test_norm_1_matrix();
void test_norm_matrix();
void test_norm_inf_matrix();

int main()
{
    test_norm_1_vector();
    test_norm_vector();
    test_norm_inf_vector();
    test_norm_1_matrix();
    test_norm_matrix();
    test_norm_inf_matrix();

    return 0;
}

void test_norm_1_vector()
{
    double elements_1[] = {0.0, 0.0, 0.0};
    double elements_2[] = {1.0, 2.0, 3.0};
    double elements_3[] = {-1.0, -2.0};

    Vector<double> vec_1(elements_1, 3);
    Vector<double> vec_2(elements_2, 3);
    Vector<double> vec_3(elements_3, 2);

    assert(vec_1.norm_1() == 0.0);
    assert(vec_2.norm_1() == 6.0);
    assert(vec_3.norm_1() == 3.0);
    std::cout << "Test norm 1 vector passed." << std::endl;
}

void test_norm_vector()
{
    double elements_1[] = {0.0, 0.0, 0.0};
    double elements_2[] = {1.0, 2.0, 3.0};
    double elements_3[] = {-1.0, -2.0};

    Vector<double> vec_1(elements_1, 3);
    Vector<double> vec_2(elements_2, 3);
    Vector<double> vec_3(elements_3, 2);

    assert(compare(vec_1.norm(), 0.0));
    assert(compare(vec_2.norm(), 3.74165738));
    assert(compare(vec_3.norm(), 2.236067977));
    std::cout << "Test norm vector passed." << std::endl;
}

void test_norm_inf_vector()
{
    double elements_1[] = {0.0, 0.0, 0.0};
    double elements_2[] = {1.0, 2.0, 3.0};
    double elements_3[] = {-1.0, -2.0};

    Vector<double> vec_1(elements_1, 3);
    Vector<double> vec_2(elements_2, 3);
    Vector<double> vec_3(elements_3, 2);

    assert(compare(vec_1.norm_inf(), 0.0));
    assert(compare(vec_2.norm_inf(), 3.0));
    assert(compare(vec_3.norm_inf(), 2.0));
    std::cout << "Test norm inf vector passed." << std::endl;
}

void test_norm_1_matrix()
{
    double elements_1[] = {1.0, -7.0, -2.0, -3.0};

    Matrix<double> mat_1(elements_1, 2, 2);

    assert(compare(mat_1.norm_1(), 10.0));
    std::cout << "Test norm 1 matrix passed." << std::endl;
}

void test_norm_matrix()
{
    double elements_1[] = {1.0, -7.0, -2.0, -3.0};

    Matrix<double> mat_1(elements_1, 2, 2);
    
    assert(compare(mat_1.norm(), 7.93725393));
    std::cout << "Test norm matrix passed." << std::endl;
}

void test_norm_inf_matrix()
{
    double elements_1[] = {1.0, -7.0, -2.0, -3.0};

    Matrix<double> mat_1(elements_1, 2, 2);
    
    assert(compare(mat_1.norm_inf(), 8.0));
    std::cout << "Test norm inf matrix passed." << std::endl;
}
