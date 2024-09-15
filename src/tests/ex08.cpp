/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:13:08 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 03:23:22 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_trace();
void test_trace_invalid();

int main()
{
    test_trace();
    test_trace_invalid();

    return 0;
}

void test_trace()
{
    double elements_1[] = {1.0, 0.0, 0.0, 1.0};
    double elements_2[] = {2.0, -5.0, 0.0, 4.0, 3.0, 7.0, -2.0, 3.0, 4.0};
    double elements_3[] = {-2.0, -8.0, 4.0, 1.0, -23.0, 4.0, 0.0, 6.0, 4.0};

    Matrix<double> mat_1(elements_1, 2, 2);
    Matrix<double> mat_2(elements_2, 3, 3);
    Matrix<double> mat_3(elements_3, 3, 3);

    double exp_1 = 2.0;
    double exp_2 = 9.0;
    double exp_3 = -21.0;

    assert(compare(exp_1, mat_1.trace()));
    assert(compare(exp_2, mat_2.trace()));
    assert(compare(exp_3, mat_3.trace()));

    std::cout << "Test trace passed." << std::endl;
}

void test_trace_invalid()
{
    double elements_1[] = {1.0, 0.0, 0.0, 1.0};

    Matrix<double> mat_1(elements_1, 4, 1);

    try
    {
        mat_1.trace();
    }
    catch(const std::exception& e)
    {
        std::cout << "Test trace invalid passed: " << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test trace invalid failed.");
}
