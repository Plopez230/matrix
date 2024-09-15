/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopez-b <plopez-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:51:29 by plopez-b          #+#    #+#             */
/*   Updated: 2024/09/15 18:06:26 by plopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>

template<typename K>
class Vector;

template <typename K>
class Matrix
{
protected:

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
    int         is_vector() const;
    void        print() const;
    Matrix<K>   reshape(int rows, int columns) const;
    Vector<K>   reshape(int rows) const;
    bool        operator==(const Matrix &m) const;

    // ex00.tpp
    void        add(const Matrix<K> &m);
    void        subtract(const Matrix<K> &m);
    void        scale(K scalar);

    // ex04.tpp
    K           norm_1() const;
    K           norm() const;
    K           norm_inf() const;

    // ex07.tpp
    Vector<K>   mul_vec(const Vector<K> &v);
    Matrix<K>   mul_mat(const Matrix<K> &m);

    // ex08.tpp
    K           trace() const;

    // ex09.tpp
    Matrix<K>   transpose() const;

    // ex10.tpp
    Matrix<K>   row_echelon() const;

    // ex11.tpp
    K           determinant() const;

    // ex12.tpp
    Matrix<K>   inverse() const;

    // ex13.tpp
    unsigned int rank() const;
};

template <typename K>
class Vector: public Matrix<K>
{
public:

    // vector.tpp
    Vector();
    Vector(K *elements, int rows);
    Vector(const Vector &o);
    Vector &operator=(const Vector &o);
    ~Vector();
    K           get_element(int row) const;
    void        set_element(const K &element, int row);

    // ex03.tpp
    K           dot(const Vector<K> &v) const;
};

// ex01.tpp
template<typename K>
Matrix<K> linear_combination(const std::vector<Matrix<K> > &matrices,
    const std::vector<K> &scalars);

// ex02.tpp
template<typename K>
Matrix<K> lerp(const Matrix<K> &u, const Matrix<K> &v, K t);

// ex05.tpp
template <typename K>
K angle_cos(const Vector<K> &u, const Vector<K> &v);

// ex06.tpp
template <typename K>
Vector<K> cross_product(const Vector<K> &u, const Vector<K> &v);

# include "matrix.tpp"
# include "vector.tpp"
# include "ex00.tpp"
# include "ex01.tpp"
# include "ex02.tpp"
# include "ex03.tpp"
# include "ex04.tpp"
# include "ex05.tpp"
# include "ex06.tpp"
# include "ex07.tpp"
# include "ex08.tpp"
# include "ex09.tpp"
# include "ex10.tpp"
# include "ex11.tpp"
# include "ex12.tpp"
# include "ex13.tpp"

#endif
