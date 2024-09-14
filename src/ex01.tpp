/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:53:19 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 02:56:50 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_TPP
# define EX01_TPP

# include "matrix.hpp"
# include <vector>

template<typename K>
Matrix<K> linear_combination(const std::vector<Matrix<K> > &matrices,
    const std::vector<K> &scalars)
{
    if (matrices.size() != scalars.size()) {
        throw std::invalid_argument(
            "The number of matrices must match the number of scalars.");
    }

    if (matrices.empty()) {
        throw std::invalid_argument(
            "Matrices vector must not be empty.");
    }

    int rows = matrices[0].get_shape()[0];
    int cols = matrices[0].get_shape()[1];
    for (unsigned int i = 0; i < matrices.size(); i++)
    {
        if (matrices[i].get_shape()[0] != rows
            || matrices[i].get_shape()[1] != cols)
        {
            throw std::invalid_argument(
                "All matrices must have the same dimensions.");
        }
    }

    std::vector<Matrix<K> > scaled(matrices);

    for (unsigned int i = 0; i < scaled.size(); i++)
    {
        scaled[i].scale(scalars[i]);
    }

    for (unsigned int i = 1; i < scaled.size(); i++)
    {
        scaled[0].add(scaled[i]);
    }

    return scaled[0];
}

#endif
