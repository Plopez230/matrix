/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:27:28 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 03:39:38 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_transpose();

int main()
{
    test_transpose();

    return 0;
}

void test_transpose()
{
    double elements[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    double expected[] = {1.0, 3.0, 5.0, 2.0, 4.0, 6.0};

    Matrix<double> mat(elements, 3, 2);
    
    Matrix<double> exp(expected, 2, 3);

    assert(exp == mat.transpose());

    std::cout << "Test transpose passed." << std::endl;
}
