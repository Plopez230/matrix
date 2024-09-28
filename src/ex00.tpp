/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:07:37 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/29 00:31:26 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_TPP
# define EX00_TPP

# include <iostream>
# include <cstring>

/**
 * Time complexity: O(n * m)
 * Space complexity: O(1)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
void Matrix<K>::add(const Matrix<K> &m)
{
    const int *m_shape = m.get_shape();
    const int *this_shape = this->get_shape();

    if (this_shape[0] != m_shape[0] || this_shape[1] != m_shape[1])
    {
        throw std::invalid_argument(
            "Matrix dimensions must match for addition.");
    }

    for (int i = 0; i < shape[0]; ++i)
    {
        for (int j = 0; j < shape[1]; ++j)
        {
            this->elements[i * shape[1] + j] += m.get_element(i, j);
        }
    }
}

/**
 * Time complexity: O(n * m)
 * Space complexity: O(1)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
void Matrix<K>::subtract(const Matrix<K> &m) {
    const int *m_shape = m.get_shape();
    const int *this_shape = this->get_shape();

    if (this_shape[0] != m_shape[0] || this_shape[1] != m_shape[1])
    {
        throw std::invalid_argument(
            "Matrix dimensions must match for subtraction.");
    }

    for (int i = 0; i < shape[0]; ++i)
    {
        for (int j = 0; j < shape[1]; ++j)
        {
            this->elements[i * shape[1] + j] -= m.get_element(i, j);
        }
    }
}

/**
 * Time complexity: O(n * m)
 * Space complexity: O(1)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template <typename K>
void Matrix<K>::scale(K scalar) {
    for (int i = 0; i < shape[0]; ++i)
    {
        for (int j = 0; j < shape[1]; ++j)
        {
            this->elements[i * shape[1] + j] *= scalar;
        }
    }
}

#endif
