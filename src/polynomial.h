/**
 *  \file polynomial.h
 *  Class for univariate sparse Polynomial
 *
 **/
#ifndef SYMENGINE_POLYNOMIALS_H
#define SYMENGINE_POLYNOMIALS_H

#include "monomials.h"
#include "dict.h"
#include "basic.h"
#include "integer.h"

namespace SymEngine {
//! Polynomial Class
class Polynomial : public Basic{
public:
    //! `degree` : Degree of Polynomial
    //! `var_` : Variable of the uni-variate Polynomial
    //! `dict_` : holds the Polynomial
    // Polynomial x**2 + 2*x + 1 has dict_ = {{0, 1}, {1, 2}, {2, 1}} with var_ = "x" 
    int degree;
    std::string var_;
    map_uint_mpz dict_;
public:
    IMPLEMENT_TYPEID(POLYNOMIAL)
    //! Constructor of Polynomial class
    Polynomial(const std::string &var, map_uint_mpz&& dict);
    //! \return true if canonical
    bool is_canonical(const int &degree, map_uint_mpz&& dict);
    //! \return size of the hash
    std::size_t __hash__() const;
    /*! Equality comparator
     * \param o - Object to be compared with
     * \return whether the 2 objects are equal
     * */
    bool __eq__(const Basic &o) const;
    int compare(const Basic &o) const;

    /*! Creates appropriate instance (i.e Symbol, Integer,
    * Mul, Pow, Polynomial) depending on the size of dictionary `d`.
    */
    static RCP<const Basic> from_dict(const std::string &var, map_uint_mpz &&d);
    /*!
    * Adds coef*var_**n to the dict_
    */
    static void dict_add_term(map_uint_mpz &d,
            const mpz_class &coef, const uint &n);
    //! Differentiates w.r.t symbol `x`
    //virtual RCP<const Basic> diff(const RCP<const Symbol> &x) const;
    //! Evaluates the Polynomial at value x
    mpz_class eval(const int &x) const;
    //! Evaluates the Polynomial at value 2**x
    mpz_class eval_bit(const int &x) const;

    //! \return `true` if `0`
    bool is_zero() const;
    //! \return `true` if `1`
    bool is_one() const;
    //! \return `true` if `-1`    
    bool is_minus_one() const;
    //! \return `true` if integer  
    bool is_integer() const;
    //! \return `true` if symbol 
    bool is_symbol() const;
    //! \return `true` if mul   
    bool is_mul() const;
    //! \return `true` if pow    
    bool is_pow() const;

    virtual vec_basic get_args() const {return {};}

    virtual void accept(Visitor &v) const;

}; //Polynomial

//! Adding two Polynomials a and b
RCP<const Polynomial> add_poly(const Polynomial &a, const Polynomial &b);
//! Negative of a Polynomial
RCP<const Polynomial> neg_poly(const Polynomial &a);
//! Subtracting two Polynomials a and b
RCP<const Polynomial> sub_poly(const Polynomial &a, const Polynomial &b);
//! Multiplying two Polynomials a and b
RCP<const Polynomial> mul_poly(const Polynomial &a, const Polynomial &b);

inline RCP<const Polynomial> polynomial(std::string i, map_uint_mpz&& dict)
{
    return rcp(new Polynomial(i, std::move(dict)));
}

}  //SymEngine

#endif
