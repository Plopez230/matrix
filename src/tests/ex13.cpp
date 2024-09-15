/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:07:24 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 19:03:25 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cassert>

void test_rank();

int main()
{
    test_rank();

    return 0;
}

void test_rank()
{
    double elements_1[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    double elements_2[] = {1.0, 2.0, 0.0, 0.0, 2.0, 4.0, 0.0, 0.0, -1.0, 2.0,
        1.0, 1.0};
    double elements_3[] = {8.0, 5.0, -2.0, 4.0, 7.0, 20.0, 7.0, 6.0, 1.0, 21.0,
        18.0, 7.0};

    Matrix<double> mat_1(elements_1, 3, 3);
    Matrix<double> mat_2(elements_2, 3, 4);
    Matrix<double> mat_3(elements_3, 4, 3);

    assert(mat_1.rank() == 3);
    assert(mat_2.rank() == 2);
    assert(mat_3.rank() == 3);

    std::cout << "Test rank passed." << std::endl;
}
