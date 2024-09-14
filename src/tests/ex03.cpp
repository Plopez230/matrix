/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:57:34 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 16:44:10 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "matrix.hpp"

void test_dot();
void test_dot_invalid_size();

int main()
{
    test_dot();
    test_dot_invalid_size();

    return 0;
}

void test_dot() {
    double values_u[] = {1, 2, 3, 4};
    double values_v[] = {5, 6, 7, 8};
    double expected = 70.0;

    Vector<double> U(values_u, 4);
    Vector<double> V(values_v, 4);

    double result;

    result = U.dot(V);
    assert(result == expected);
    std::cout << "Test dot passed." << std::endl;
}

void test_dot_invalid_size() {
    double values_u[] = {1, 2, 3, 4};
    double values_v[] = {5, 6, 7};

    Vector<double> U(values_u, 4);
    Vector<double> V(values_v, 3);

    try
    {
        U.dot(V);
        std::cerr <<
            "Test dot invalid size failed: No exception thrown."
            << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout <<
            "Test dot invalid size passed: "
            << e.what() << std::endl;
    }
}
