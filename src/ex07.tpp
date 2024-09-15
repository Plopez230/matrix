/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:06:29 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 01:53:52 by plopez-b         ###   ########.fr       */
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

#endif
