/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:04:40 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 02:59:35 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <vector>
#include "matrix.hpp"

void test_linear_combination();
void test_linear_combination_unexpected_result();
void test_linear_combination_invalid_size();
void test_linear_combination_invalid_dimensions();
void test_linear_combination_empty_matrices();

int main() {
    test_linear_combination();
    test_linear_combination_unexpected_result();
    test_linear_combination_invalid_size();
    test_linear_combination_invalid_dimensions();
    test_linear_combination_empty_matrices();
    
    return 0;
}

void test_linear_combination() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {5, 6, 7, 8};
    int values_c[] = {9, 10, 11, 12};
    int expected_values[] = {1*2 + 5*3 + 9*4,
                            2*2 + 6*3 + 10*4,
                            3*2 + 7*3 + 11*4,
                            4*2 + 8*3 + 12*4};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> C(values_c, 2, 2);
    Matrix<int> expected(expected_values, 2, 2);

    // cpp11
    std::vector<Matrix<int>> matrices = {A, B, C};
    std::vector<int> scalars = {2, 3, 4};

    Matrix<int> result = linear_combination(matrices, scalars);

    assert(result == expected);
    std::cout << "Test linear combination passed." << std::endl;
}

void test_linear_combination_unexpected_result() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {5, 6, 7, 8};
    int values_c[] = {9, 10, 11, 12};
    int incorrect_values[] = {1*2 + 5*3 + 9*4,
                            2*2 + 6*3 + 10*4,
                            3*2 + 7*3 + 11*4,
                            4*2 + 8*3 + 12*4 + 1};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> C(values_c, 2, 2);
    Matrix<int> incorrect(incorrect_values, 2, 2);

    std::vector<Matrix<int>> matrices = {A, B, C};
    std::vector<int> scalars = {2, 3, 4};

    Matrix<int> result = linear_combination(matrices, scalars);

    assert(!(result == incorrect));
    std::cout <<
        "Test linear combination unexpected result passed: "
        << "Result does not match incorrect matrix." << std::endl;
}

void test_linear_combination_invalid_size() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {5, 6, 7, 8};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);

    std::vector<Matrix<int>> matrices = {A, B};
    std::vector<int> scalars = {2};

    try {
        Matrix<int> result = linear_combination(matrices, scalars);
        std::cerr <<
            "Test linear combination invalid size failed: No exception thrown."
            << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout <<
            "Test linear combination invalid size passed: "
            << e.what() << std::endl;
    }
}

void test_linear_combination_invalid_dimensions() {
    int values_a[] = {1, 2, 3, 4};
    int values_b[] = {5, 6, 7, 8};
    int values_c[] = {9, 10};

    Matrix<int> A(values_a, 2, 2);
    Matrix<int> B(values_b, 2, 2);
    Matrix<int> C(values_c, 1, 2);

    std::vector<Matrix<int>> matrices = {A, B, C};
    std::vector<int> scalars = {2, 3, 4};

    try {
        Matrix<int> result = linear_combination(matrices, scalars);
        std::cerr <<
            "Test linear combination invalid dimensions failed: " 
            << "No exception thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Test linear combination invalid dimensions passed: "
            << e.what() << std::endl;
    }
}

void test_linear_combination_empty_matrices() {
    std::vector<Matrix<int>> matrices;
    std::vector<int> scalars;

    try {
        Matrix<int> result = linear_combination(matrices, scalars);
        std::cerr << "Test linear combination empty matrices failed: " 
            << "No exception thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Test linear combination empty matrices passed: "
            << e.what() << std::endl;
    }
}
