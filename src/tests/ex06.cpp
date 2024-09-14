/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:22:16 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:51:54 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_cross_product();
void test_cross_product_invalid();

int main()
{
    test_cross_product();
    test_cross_product_invalid();

    return 0;
}

void test_cross_product()
{
    double elements_1[] = {0.0, 0.0, 1.0};
    double elements_2[] = {1.0, 0.0, 0.0};
    double elements_3[] = {1.0, 2.0, 3.0};
    double elements_4[] = {4.0, 5.0, 6.0};
    double elements_5[] = {4.0, 2.0, -3.0};
    double elements_6[] = {-2.0, -5.0, 16.0};

    double expected_1[] = {0.0, 1.0, 0.0};
    double expected_2[] = {-3.0, 6.0, -3.0};
    double expected_3[] = {17.0, -58.0, -16.0};

    Vector<double> vec1(elements_1, 3);
    Vector<double> vec2(elements_2, 3);
    Vector<double> vec3(elements_3, 3);
    Vector<double> vec4(elements_4, 3);
    Vector<double> vec5(elements_5, 3);
    Vector<double> vec6(elements_6, 3);

    Vector<double> exp1(expected_1, 3);
    Vector<double> exp2(expected_2, 3);
    Vector<double> exp3(expected_3, 3);

    assert(exp1 == cross_product(vec1, vec2));
    assert(exp2 == cross_product(vec3, vec4));
    assert(exp3 == cross_product(vec5, vec6));

    std::cout << "Test cross product passed." << std::endl;
}

void test_cross_product_invalid()
{
    double elements_1[] = {0.0, 0.0, 1.0};
    double elements_2[] = {1.0, 0.0, 0.0};


    Vector<double> vec1(elements_1, 3);
    Vector<double> vec2(elements_2, 2);

    try
    {
        cross_product(vec1, vec2);
    }
    catch(const std::exception& e)
    {
        std::cout << "Test cross product invalid passed." << std::endl;
        return;
    }
    throw std::invalid_argument("Test cross product invalid failed.");   
}
