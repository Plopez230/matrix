/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:22:18 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/29 00:51:42 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX06_TPP
# define EX06_TPP

# include "matrix.hpp"

// https://en.wikipedia.org/wiki/Dot_product

/**
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
template <typename K>
Vector<K> cross_product(const Vector<K> &u, const Vector<K> &v)
{
    const int *u_shape = u.get_shape();
    if (u_shape[0] != 3)
    {
        throw std::invalid_argument(
            "The vectors must be 3 dimensional.");
    }

    const int *v_shape = v.get_shape();
    if (v_shape[0] != 3)
    {
        throw std::invalid_argument(
            "The vectors must be 3 dimensional.");
    }

    K elements[3];

    elements[0] = u.get_element(1) * v.get_element(2)
        - u.get_element(2) * v.get_element(1);
    elements[1] = u.get_element(2) * v.get_element(0)
        - u.get_element(0) * v.get_element(2);
    elements[2] = u.get_element(0) * v.get_element(1)
        - u.get_element(1) * v.get_element(0);

    Vector<K> result (elements, 3);

    return result;
}

#endif
