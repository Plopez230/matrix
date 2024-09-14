/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:52:56 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 19:33:06 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX04_TPP
# define EX04_TPP

# include <algorithm>
# include <cmath>
# include "matrix.hpp"

// https://bathmash.github.io/HELM/30_4_mtrx_norms-web/30_4_mtrx_norms-webse1.html

template <typename K>
K Matrix<K>::norm_1() const
{
    K result = 0;
    K sum = 0;

    for (int y = 0; y < this->shape[1]; y++)
    {
        sum = 0;
        for (int x = 0; x < this->shape[0]; x++)
        {
            sum += std::max(this->get_element(x, y), -this->get_element(x, y));
        }
        result = std::max(result, sum);
    }

    return result;
}

template <typename K>
K Matrix<K>::norm() const
{
    K result = 0;

    for (int x = 0; x < this->shape[0]; x++)
    {
        for (int y = 0; y < this->shape[1]; y++)
        {
            result += this->get_element(x, y) * this->get_element(x, y);
        }
    }

    return std::pow(result, 1.0 / 2.0);
}

template <typename K>
K Matrix<K>::norm_inf() const
{
    K result = 0;
    K sum = 0;

    for (int x = 0; x < this->shape[0]; x++)
    {
        result = std::max(result,
            std::max(this->elements[x], -this->elements[x]));
    }

    for (int x = 0; x < this->shape[0]; x++)
    {
        sum = 0;
        for (int y = 0; y < this->shape[1]; y++)
        {
            sum += std::max(this->get_element(x, y), -this->get_element(x, y));
        }
        result = std::max(sum, result);
    }

    return result;
}

#endif
