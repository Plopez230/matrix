/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:57:53 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 08:11:35 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_determinant();
void test_determinant_invalid();
void test_determinant_invalid_size();

int main()
{
    test_determinant();
    test_determinant_invalid();
    test_determinant_invalid_size();

    return 0;
}

void test_determinant()
{
    double elements_1[] = {1.0, -1.0, -1.0, 1.0};
    double elements_2[] = {2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0};
    double elements_3[] = {8.0, 5.0, -2.0, 4.0, 7.0, 20.0, 7.0, 6.0, 1.0};
    double elements_4[] = {8.0, 5.0, -2.0, 4.0, 4.0, 2.5, 20.0, 4.0, 8.0, 5.0,
        1.0, 4.0, 28.0, -4.0, 17.0, 1.0};

    Matrix<double> mat_1(elements_1, 2, 2);
    Matrix<double> mat_2(elements_2, 3, 3);
    Matrix<double> mat_3(elements_3, 3, 3);
    Matrix<double> mat_4(elements_4, 4, 4);

    assert(compare(0.0, mat_1.determinant()));
    assert(compare(8.0, mat_2.determinant()));
    assert(compare(-174.0, mat_3.determinant()));
    assert(compare(1032.0, mat_4.determinant()));

    std::cout << "Test determinant passed." << std::endl;
}

void test_determinant_invalid()
{
    double elements_1[] = {1.0, 0.0, 0.0, 1.0};

    Matrix<double> mat_1(elements_1, 4, 1);

    try
    {
        mat_1.determinant();
    }
    catch(const std::exception& e)
    {
        std::cout << "Test determinant invalid passed: "
            << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test determinant invalid failed.");
}

void test_determinant_invalid_size()
{
    double elements_1[] = {1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 0.0, 1.0, 0.0};

    Matrix<double> mat_1(elements_1, 5, 5);

    try
    {
        mat_1.determinant();
    }
    catch(const std::exception& e)
    {
        std::cout << "Test determinant invalid size passed: "
            << e.what() << std::endl;
        return;
    }
    
    throw std::invalid_argument("Test determinant invalid size failed.");
}
