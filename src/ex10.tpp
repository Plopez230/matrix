/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:56:19 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 06:19:01 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX10_TPP
# define EX10_TPP

# include "matrix.hpp"

// Gaussian elimination algorithm
// https://linearalgebra.math.umanitoba.ca/math1220/section-12.html

/**
 * O(n)
 */
template <typename K>
static int pivot(Matrix<K> &m, int row)
{
    int _pivot = 0;
    K zero = (K) 0.0;

    for (int col = 0; col < m.get_shape()[1]; col++)
    {
        if (compare(m.get_element(row, col), zero))
            _pivot ++;
        else
            break;
    }

    return _pivot;
}

/**
 * O(n)
 */
template <typename K>
static void swap_rows(Matrix<K> &m, int a, int b)
{
    for (int col = 0; col < m.get_shape()[1]; col++)
    {
        K tmp = m.get_element(a, col);
        m.set_element(m.get_element(b, col), a, col);
        m.set_element(tmp, b, col);
    }
}

/**
 * O(n)
 */
template <typename K>
static void multiply_row(Matrix<K> &m, int row, K n)
{
    for (int col = 0; col < m.get_shape()[1]; col++)
    {
        m.set_element(m.get_element(row, col) * n, row, col);
    }
}

/**
 * O(n)
 */
template <typename K>
static void add_multiple_of_row(Matrix<K> &m, int a, int b, K n)
{
    for (int col = 0; col < m.get_shape()[1]; col++)
    {
        m.set_element(
            m.get_element(b, col) * n + m.get_element(a, col), a, col);
    }
}

/**
 * O(n²)
 */
template <typename K>
static int first_nonzero_entry(Matrix<K> &m, int col, int top_row)
{
    for (int row = top_row; row < m.get_shape()[0]; row++)
    {
        int pivot_ = pivot(m, row);
        if (pivot_ == col)
            return row;
    }

    return m.get_shape()[0];
}

/**
 * O(n³)
 */
template <typename K>
Matrix<K> Matrix<K>::row_echelon() const
{
    Matrix<K> result(*this);
    K one = (K) 1.0;
    K zero = (K) 0.0;
    int top_row = 0;

    // We work on the columns of the matrix from left to right and change the
    // matrix in the following way:
    for (int col = 0; col < result.get_shape()[1]; col++)
    {
        // Start with the first column. If it has all entries equal to zero,
        // move on to the next column to the right.
        int row = first_nonzero_entry(result, col, top_row);
        if (row >= result.get_shape()[0])
        {
            continue;
        }
        else
        {
            // If the column has nonzero entries, interchange rows, if
            // necessary, to get a nonzero entry on top.
            K top_entry = result.get_element(row, col);
            if (row != top_row)
            {
                swap_rows(result, top_row, row);
            }

            // Change the top entry, if necessary, to make it a 1.
            if (!compare(one, top_entry))
            {
                multiply_row(
                    result, top_row, one / result.get_element(top_row, col));
            }

            // For any nonzero entry below the top one, use an elementary row
            // operation to change it to zero.
            for (int row_ = 0; row_ < result.get_shape()[0]; row_++)
            {
                if (row_ == top_row)
                    continue;
                    
                K entry = result.get_element(row_, col);
                if (!compare(zero, entry))
                {
                    add_multiple_of_row(
                        result, row_, top_row,
                        - result.get_element(row_, col));
                }
            }

            // Now consider the part of the matrix below the top row and to the
            // right of the column under consideration: if there are no such
            // rows or columns, stop since the procedure is finished. Otherwise,
            // carry out the same procedure on the new matrix.
            top_row ++;
        }
    }

    return result;
}

#endif
