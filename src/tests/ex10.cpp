/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:55:34 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 06:16:14 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_row_echelon();

int main()
{
    test_row_echelon();

    return 0;
}

void test_row_echelon()
{
    double elements_1[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    double elements_2[] = {1.0, 2.0, 3.0, 4.0};
    double elements_3[] = {1.0, 2.0, 2.0, 4.0};
    double elements_4[] = {8.0, 5.0, -2.0, 4.0, 28.0, 4.0, 2.5, 20.0, 4.0, -4.0,
        8.0, 5.0, 1.0, 4.0, 17};

    double expected_1[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    double expected_2[] = {1.0, 0.0, 0.0, 1.0};
    double expected_3[] = {1.0, 2.0, 0.0, 0.0};
    double expected_4[] = {1.0, 0.625, 0.0, 0.0, -12.1666667, 0.0, 0.0, 1.0,
        0.0, -3.6666667, 0.0, 0.0, 0.0, 1.0, 29.5};

    Matrix<double> mat_1(elements_1, 3, 3);
    Matrix<double> mat_2(elements_2, 2, 2);
    Matrix<double> mat_3(elements_3, 2, 2);
    Matrix<double> mat_4(elements_4, 3, 5);

    Matrix<double> exp_1(expected_1, 3, 3);
    Matrix<double> exp_2(expected_2, 2, 2);
    Matrix<double> exp_3(expected_3, 2, 2);
    Matrix<double> exp_4(expected_4, 3, 5);

    assert(exp_1 == mat_1.row_echelon());
    assert(exp_2 == mat_2.row_echelon());
    assert(exp_3 == mat_3.row_echelon());
    assert(exp_4 == mat_4.row_echelon());

    std::cout << "Test row echelon passed." << std::endl;
}
