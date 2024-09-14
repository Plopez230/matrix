/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:28:28 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 16:39:18 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_TPP
# define EX03_TPP

# include "matrix.hpp"

template <typename K>
K Vector<K>::dot(const Vector<K> &v)
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
