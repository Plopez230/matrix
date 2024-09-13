/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:07:37 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 00:37:57 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_TPP
# define EX00_TPP

# include <iostream>
# include <cstring>

template <typename K>
Matrix<K> add(Matrix<K> a, Matrix<K> b)
{
    const int *a_shape = a.get_shape();
    const int *b_shape = b.get_shape();
    int rows = a_shape[0];
    int cols = a_shape[1];
    K result_elements[rows * cols];

    if (a_shape[0] != b_shape[0] || a_shape[1] != b_shape[1])
    {
        throw std::invalid_argument(
            "Matrix dimensions must match for addition.");
    }
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result_elements[i * cols + j] = a.get_element(i, j)
                + b.get_element(i, j);
        }
    }

    return Matrix<K>(result_elements, rows, cols);
}

template <typename K>
Matrix<K> subtract(Matrix<K> a, Matrix<K> b)
{
    const int *a_shape = a.get_shape();
    const int *b_shape = b.get_shape();
    int rows = a_shape[0];
    int cols = a_shape[1];
    K result_elements[rows * cols];
    
    if (a_shape[0] != b_shape[0] || a_shape[1] != b_shape[1])
    {
        throw std::invalid_argument(
            "Matrix dimensions must match for subtraction.");
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
        {
            result_elements[i * cols + j] = a.get_element(i, j)
                - b.get_element(i, j);
        }
    }

    return Matrix<K>(result_elements, rows, cols);
}

template <typename K>
Matrix<K> scale(Matrix<K> a, K scalar) {
    int rows = a.get_shape()[0];
    int cols = a.get_shape()[1];
    K result_elements[rows * cols];
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
        {
            result_elements[i * cols + j] = a.get_element(i, j)
                * scalar;
        }
    }

    return Matrix<K>(result_elements, rows, cols);
}

#endif
