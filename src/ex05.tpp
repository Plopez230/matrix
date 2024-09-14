/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:02:50 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 19:47:29 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX05_TPP
# define EX05_TPP

# include "matrix.hpp"

// Dot product: a.dot(b) = a.norm() * b.norm() * cos(theta)
// Find the cosine of the angle:
// cos(theta) = a.dot(b) / (a.norm() * b.norm())
// https://en.wikipedia.org/wiki/Dot_product

template <typename K>
K angle_cos(const Vector<K> &u, const Vector<K> &v)
{
    K u_norm = u.norm();
    if (u_norm == 0.0)
    {
        throw std::invalid_argument(
            "The vectors must not be 0.");
    }

    K v_norm = v.norm();
    if (v_norm == 0.0)
    {
        throw std::invalid_argument(
            "The vectors must not be 0.");
    }

    const int *u_shape = u.get_shape();
    const int *v_shape = v.get_shape();
    if (u_shape[0] != v_shape[0] || u_shape[1] != v_shape[1])
    {
        throw std::invalid_argument(
            "The vectors must have the same dimensions.");
    }

    K dot_product = u.dot(v);

    return dot_product / (u_norm * v_norm);
}

#endif
