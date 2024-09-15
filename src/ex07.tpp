/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:06:29 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 03:03:34 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX07_TPP
# define EX07_TPP

# include "matrix.hpp"

template <typename K>
Vector<K> Matrix<K>::mul_vec(const Vector<K> &v)
{
    const int *this_shape = this->get_shape();
    const int *v_shape = v.get_shape();

    if (this_shape[1] != v_shape[0])
    {
        throw std::invalid_argument(
            "Invalid shape.");
    }

    K elements[v_shape[0]];

    for (int x = 0; x < v_shape[0]; x++)
    {
        elements[x] = 0;
        for (int y = 0; y < v_shape[0]; y++)
        {
            elements[x] += this->get_element(y, x) * v.get_element(y);
        }
    }

    Vector<K> result(elements, v_shape[0]);

    return result;
}

template <typename K>
Matrix<K> Matrix<K>::mul_mat(const Matrix<K> &mat)
{
    const int *this_shape = this->get_shape();
    const int *m_shape = mat.get_shape();

    if (this_shape[1] != m_shape[0])
    {
        throw std::invalid_argument(
            "Invalid shape.");
    }

    K elements[this_shape[0] * m_shape[1]];
    Matrix<K> result(elements, this_shape[0], m_shape[1]);

    for (int m = 0; m < this_shape[0]; m++)
    {
        for (int p = 0; p < m_shape[1]; p++)
        {
            K element = 0;
            
            for (int n = 0; n < m_shape[0]; n++)
            {
                element += this->get_element(m, n) * mat.get_element(n, p);
            }
            
            result.set_element(element, m, p);
        }
    }

    return result;
}

#endif
