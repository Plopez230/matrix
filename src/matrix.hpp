/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:51:29 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/14 03:11:58 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>

template <typename K>
class Matrix
{
    K   *elements;
    int shape[2];

public:

    // matrix.tpp
    Matrix();
    Matrix(K *elements, int rows, int columns);
    Matrix(const Matrix &o);
    Matrix &operator=(const Matrix &o);
    ~Matrix();
    const K     get_element(int row, int column) const;
    void        set_element(const K &element, int row, int column);
    const int   *get_shape() const;
    int         is_square() const;
    void        print() const;
    void        reshape(int rows, int columns);
    bool        operator==(const Matrix &m) const;

    // ex00.tpp
    void        add(const Matrix<K> &m);
    void        subtract(const Matrix<K> &m);
    void        scale(K scalar);
};

// ex01.tpp
template<typename K>
Matrix<K> linear_combination(const std::vector<Matrix<K> > &matrices,
    const std::vector<K> &scalars);

// ex02.tpp
template<typename K>
Matrix<K> lerp(const Matrix<K> &u, const Matrix<K> &v, K t);

# include "matrix.tpp"
# include "ex00.tpp"
# include "ex01.tpp"
# include "ex02.tpp"

#endif
