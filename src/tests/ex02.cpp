/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:34 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 16:44:53 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "matrix.hpp"

void test_lerp();
void test_lerp_invalid_size();

int main()
{
    test_lerp();
    test_lerp_invalid_size();

    return 0;
}

void test_lerp() {
    double values_u[] = {1, 2, 3, 4};
    double values_v[] = {5, 6, 7, 8};
    double expected_t0[] = {1, 2, 3, 4};
    double expected_t05[] = {3, 4, 5, 6};
    double expected_t1[] = {5, 6, 7, 8};
    double expected_t2[] = {9, 10, 11, 12};

    Matrix<double> U(values_u, 2, 2);
    Matrix<double> V(values_v, 2, 2);
    Matrix<double> expected0(expected_t0, 2, 2);
    Matrix<double> expected05(expected_t05, 2, 2);
    Matrix<double> expected1(expected_t1, 2, 2);
    Matrix<double> expected2(expected_t2, 2, 2);

    Matrix<double> result;

    result = lerp(U, V, 0.0);
    assert(result == expected0);
    std::cout << "Test lerp t=0 passed." << std::endl;

    result = lerp(U, V, 0.5);
    assert(result == expected05);
    std::cout << "Test lerp t=0.5 passed." << std::endl;

    result = lerp(U, V, 1.0);
    assert(result == expected1);
    std::cout << "Test lerp t=1 passed." << std::endl;

    result = lerp(U, V, 2.0);
    assert(result == expected2);
    std::cout << "Test lerp t=2 passed." << std::endl;
}

void test_lerp_invalid_size() {
    double values_u[] = {1, 2, 3, 4};
    double values_v[] = {5, 6, 7};

    Vector<double> U(values_u, 4);
    Vector<double> V(values_v, 3);

    try
    {
        lerp(U, V, 0.5);
        std::cerr <<
            "Test lerp invalid size failed: No exception thrown."
            << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout <<
            "Test lerp invalid size passed: "
            << e.what() << std::endl;
    }
}
