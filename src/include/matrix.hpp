/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:51:29 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 00:11:58 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

template <typename K>
class Matrix
{
    K   *elements;
    int shape[2];

public:
    Matrix(K *elements, int rows, int columns);
    Matrix(const Matrix &o);
    ~Matrix();

    const K     get_element(int row, int column) const;
    void        set_element(K element, int row, int column);
    
    const int   *get_shape() const;
    int         is_square() const;
    void        print() const;
    void        reshape(int rows, int columns);
};

# include "matrix.tpp"

// ex00.tpp

template <typename K>
Matrix<K> add(Matrix<K> a, Matrix<K> b);

template <typename K>
Matrix<K> subtract(Matrix<K> a, Matrix<K> b);

template <typename K>
Matrix<K> scale(Matrix<K> a, K scalar);

# include "../ex00.tpp"


#endif
