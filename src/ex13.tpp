/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:07:21 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/29 01:23:36 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX13_TPP
# define EX13_TPP

# include "matrix.hpp"

/**
 * Time complexity: O(m)
 * Space complexity: O(1)
 * 
 * where m is the number of columns
 */
template <typename K>
int is_linearly_independent(const Matrix<K> &m, int row)
{
    K zero = (K) 0.0;

    for (int col = 0; col < m.get_shape()[1]; col++)
    {
        K element = m.get_element(row, col);
        if (!compare(zero, element))
            return 1;
    }

    return 0;
}

/**
 * Time complexity: O(m² * n)
 * Space complexity: O(n * m)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
unsigned int Matrix<K>::rank() const
{
    Matrix<K> row_echelon = this->row_echelon();
    unsigned int rank = 0;

    for (int row = 0; row < this->get_shape()[0]; row++)
    {
        if (is_linearly_independent(row_echelon, row))
            rank++;
    }

    return rank;
}

#endif
