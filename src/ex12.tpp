/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:10:13 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/29 01:17:54 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX12_TPP
# define EX12_TPP

# include "matrix.hpp"

/**
 * Time complexity: O(n * m)
 * Space complexity: O(1)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
Matrix<K> augmented_matrix(const Matrix<K> &m)
{
    int rows = m.get_shape()[0];
    int cols = rows * 2;
    K zero = (K) 0.0;
    K one = (K) 1.0;

    K elements[rows * cols];
    Matrix<K> augmented(elements, rows, cols);

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < rows; col++)
        {
            augmented.set_element(m.get_element(row, col), row, col);
            augmented.set_element(zero, row, col + rows);
        }
        augmented.set_element(one, row, row + rows);
    }

    return augmented;
}

/**
 * Time complexity: O(n * m)
 * Space complexity: O(1)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
Matrix<K> right_matrix(const Matrix<K> &m)
{
    int rows = m.get_shape()[0];
    int cols = rows;

    K elements[rows * cols];
    Matrix<K> n(elements, rows, cols);

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            n.set_element(m.get_element(row, col + rows), row, col);
        }
    }

    return n;
}

/**
 * Time complexity: O(m² * n)
 * Space complexity: O(1)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
Matrix<K> Matrix<K>::inverse() const
{
    K zero = (K) 0.0;

    // A matrix has inverse only if its determinant is not 0
    if (compare(this->determinant(), zero))
    {
        throw std::invalid_argument(
            "The determinant of the matrix is not 0");
    }
    
    Matrix<K> augmented = augmented_matrix(*this);
    Matrix<K> row_echelon = augmented.row_echelon();
    Matrix<K> right = right_matrix(row_echelon);

    return right;
}

#endif
