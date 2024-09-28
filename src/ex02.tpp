/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:53:19 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/29 00:44:21 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_TPP
# define EX02_TPP

# include "matrix.hpp"

/**
 * Time complexity: O(n * m)
 * Space complexity: O(n * m)
 * 
 * where n is the number of rows in the matrix and m is the number of columns
 */
template<typename K>
Matrix<K> lerp(const Matrix<K> &u, const Matrix<K> &v, K t)
{
    const int *u_shape = u.get_shape();
    const int *v_shape = v.get_shape();
    if (u_shape[0] != v_shape[0] || u_shape[1] != v_shape[1]) {
        throw std::invalid_argument(
            "The matrices must have the same dimensions.");
    }

    Matrix<K> difference(v);
    Matrix<K> result(u);

    difference.subtract(u);
    difference.scale(t);
    result.add(difference);

    return result;
}

#endif
