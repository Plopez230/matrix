/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:58:50 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 17:55:16 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX11_TPP
# define EX11_TPP

# include "matrix.hpp"

// https://www.matesfacil.com/calculadoras/matrices/calculadora-online-determinantes-matrices-2x2-3x3-4x4-matriz.html
// https://www.youtube.com/watch?v=Ip3X9LOh2dk

template <typename K>
Matrix<K> submatrix(const Matrix<K> &m, int n)
{
    K elements[9];
    Matrix<K> result(elements, 3, 3);

    for (int row = 0; row < 4; row ++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (row == 0 || col == n)
            {
                continue;
            }

            int target_row = row - 1;
            int target_col = col - (col > n);

            result.set_element(
                m.get_element(row, col),
                target_row, target_col
            );
        }
    }

    return result;
}

template <typename K>
K rule_of_sarrus(const Matrix<K> &m)
{
    return m.get_element(0, 0) * m.get_element(1, 1) * m.get_element(2, 2)
        + m.get_element(1, 0) * m.get_element(2, 1) * m.get_element(0, 2)
        + m.get_element(2, 0) * m.get_element(0, 1) * m.get_element(1, 2)
        - m.get_element(0, 2) * m.get_element(1, 1) * m.get_element(2, 0)
        - m.get_element(1, 2) * m.get_element(2, 1) * m.get_element(0, 0)
        - m.get_element(2, 2) * m.get_element(0, 1) * m.get_element(1, 0);
}

template <typename K>
K Matrix<K>::determinant() const
{
    if (!this->is_square())
    {
        throw std::invalid_argument(
            "The matrix must be square.");
    }

    if (this->get_shape()[0] == 1)
    {
        return this->get_element(0, 0);
    }

    if (this->get_shape()[0] == 2)
    {
        return this->get_element(0, 0) * this->get_element(1, 1)
            - this->get_element(0, 1) * this->get_element(1, 0);
    }
    
    if (this->get_shape()[0] == 3)
    {
        return rule_of_sarrus(*this);
    }

    if (this->get_shape()[0] == 4)
    {
        return this->get_element(0, 0) * rule_of_sarrus(submatrix(*this, 0))
            - this->get_element(0, 1) * rule_of_sarrus(submatrix(*this, 1))
            + this->get_element(0, 2) * rule_of_sarrus(submatrix(*this, 2))
            - this->get_element(0, 3) * rule_of_sarrus(submatrix(*this, 3));
    }
    
    throw std::invalid_argument(
        "Determinant not implemented for matrices larger than 4x4.");
}

#endif
