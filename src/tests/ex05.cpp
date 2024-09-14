/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:18:02 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 20:50:30 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_angle_cos();
void test_angle_invalid_shape();
void test_angle_cos_0();

int main()
{
    test_angle_cos();
    test_angle_invalid_shape();
    test_angle_cos_0();

    return 0;
}

void test_angle_cos()
{
    double elements_1[] = {1.0, 0.0};
    double elements_2[] = {0.0, 1.0};
    double elements_3[] = {-1.0, 1.0};
    double elements_4[] = {1.0, -1.0};
    double elements_5[] = {2.0, 1.0};
    double elements_6[] = {4.0, 2.0};
    double elements_7[] = {1.0, 2.0, 3.0};
    double elements_8[] = {4.0, 5.0, 6.0};

    Vector<double> vec1(elements_1, 2);
    Vector<double> vec2(elements_2, 2);
    Vector<double> vec3(elements_3, 2);
    Vector<double> vec4(elements_4, 2);
    Vector<double> vec5(elements_5, 2);
    Vector<double> vec6(elements_6, 2);
    Vector<double> vec7(elements_7, 3);
    Vector<double> vec8(elements_8, 3);

    assert(compare(angle_cos(vec1, vec1), 1.0));
    assert(compare(angle_cos(vec1, vec2), 0.0));
    assert(compare(angle_cos(vec3, vec4), -1.0));
    assert(compare(angle_cos(vec5, vec6), 1.0));
    assert(compare(angle_cos(vec7, vec8), 0.974631846));

    std::cout << "Test angle cos passed." << std::endl;
}

void test_angle_invalid_shape()
{
    double elements_1[] = {0.0, 0.0};
    double elements_2[] = {0.0, 1.0, 2.0};

    Vector<double> vec1(elements_1, 2);
    Vector<double> vec2(elements_2, 3);

    try
    {
        angle_cos(vec1, vec2);
        std::cerr <<
            "Test angle cos invalid shape failed: No exception thrown."
            << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout <<
            "Test angle cos invalid shape passed: "
            << e.what() << std::endl;
        return;
    }
    throw std::invalid_argument("No exception thrown.");
}

void test_angle_cos_0()
{
    double elements_1[] = {0.0, 0.0};
    double elements_2[] = {0.0, 1.0};

    Vector<double> vec1(elements_1, 2);
    Vector<double> vec2(elements_2, 2);

    try
    {
        angle_cos(vec1, vec2);
        std::cerr <<
            "Test angle cos 0 failed: No exception thrown."
            << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout <<
            "Test angle cos 0 passed: "
            << e.what() << std::endl;
        return;
    }
    throw std::invalid_argument("No exception thrown.");
}
