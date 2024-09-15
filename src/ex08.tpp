/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:10:34 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 06:34:01 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX08_TPP
# define EX08_TPP

# include "matrix.hpp"

// https://es.wikipedia.org/wiki/Traza_(%C3%A1lgebra_lineal)

template <typename K>
K Matrix<K>::trace() const
{
    if (!this->is_square())
    {
        throw std::invalid_argument("The matrix is not square.");
    }

    K result = 0;

    for (int i = 0; i < this->get_shape()[0]; i++)
    {
        result += this->get_element(i, i);
    }

    return result;
}

#endif
