/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:27:34 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 03:34:20 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX09_TPP
# define EX09_TPP

# include "matrix.hpp"

template <typename K>
Matrix<K> Matrix<K>::transpose() const
{
    Matrix<K> result = this->reshape(
        this->get_shape()[1], this->get_shape()[0]);

    for (int x = 0; x < this->get_shape()[0]; x++)
    {
        for (int y = 0; y < this->get_shape()[1]; y++)
        {
            result.set_element(
                this->get_element(x, y),
                y, x
            );
        }
    }

    return result;
}

#endif
