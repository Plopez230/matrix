/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:28:28 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/29 00:47:39 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_TPP
# define EX03_TPP

# include "matrix.hpp"

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 * 
 * where n is the length of the vector
 */
template <typename K>
K Vector<K>::dot(const Vector<K> &v) const
{
    const int *this_shape = this->get_shape();
    const int *v_shape = v.get_shape();
    if (this_shape[0] != v_shape[0]) {
        throw std::invalid_argument(
            "The vectors must have the same dimensions.");
    }

    K result;
    for (int x = 0; x < this_shape[0]; x++)
    {
        result += this->get_element(x) * v.get_element(x);
    }

    return result;
}

#endif
