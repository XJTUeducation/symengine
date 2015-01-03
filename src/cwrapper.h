#ifndef CWRAPPER_H
#define CWRAPPER_H

#include <gmp.h>

#ifdef __cplusplus
#include "basic.h"
#include "constants.h"
namespace CSymPy {
    class CWrapper {
        public:
            RCP<const Basic> ptr;
            CWrapper() {
                ptr = zero;
            }
    };
}
using CSymPy::CWrapper;

extern "C" {

#else
typedef struct CWrapper CWrapper;
#endif

//! basic is a pointer to a CWrapper which wraps the C++ class.
// A basic type should be initialized using the return value of basic_new(), before any
// function is called. Assignment should be done only by using basic_assign()
typedef CWrapper* basic;

//! Return a new basic instance.
basic basic_new();
//! Assign value of b to a.
void basic_assign(basic a, const basic b);
//! Free the C++ class wrapped by s.
void basic_free(basic s);

//! Assign to s, a symbol with string representation c.
void basic_symbol(basic s, char* c);

//! Assign to s, a long.
void basic_integer_si(basic s, long i);
//! Assign to s, a ulong.
void basic_integer_ui(basic s, unsigned long i);
//! Assign to s, a mpz_t.
void basic_integer_mpz(basic s, const mpz_t i);
//! Assign to s, an integer that has base 10 representation c.
void basic_integer_str(basic s, char* c);

//! Assign to s, a rational i/j. Returns 0 if either i or j is not an integer.
int basic_rational(basic s, const basic i, const basic j);
//! Assign to s, a rational i/j, where i and j are signed longs.
void basic_rational_si(basic s, long i, long j);
//! Assign to s, a rational i/j, where i and j are unsigned longs.
void basic_rational_ui(basic s, unsigned long i, unsigned long j);
//! Assign to s, a rational i, where is of type mpq_t.
void basic_rational_mpq(basic s, const mpq_t i);

//! Assigns s = a + b.
void basic_add(basic s, const basic a, const basic b);
//! Assigns s = a - b.
void basic_sub(basic s, const basic a, const basic b);
//! Assigns s = a * b.
void basic_mul(basic s, const basic a, const basic b);
//! Assigns s = a / b.
void basic_div(basic s, const basic a, const basic b);
//! Assigns s = a ^ b.
void basic_pow(basic s, const basic a, const basic b);
//! Assign to s, derivative of expr with respect to sym. Returns 0 if sym is not a symbol.
int basic_diff(basic s, const basic expr, const basic sym);
//! Assigns s = -a.
void basic_neg(basic s, const basic a);
//! Assigns s = abs(a).
void basic_abs(basic s, const basic a);
//! Expands the expr a and assigns to s.
void basic_expand(basic s, const basic a);

//! Returns a new char pointer to the string representation of s.
char* basic_str(const basic s);

//! Return 1 if s is an Integer, 0 if not.
int is_a_Integer(const basic s);
//! Return 1 if s is an Rational, 0 if not.
int is_a_Rational(const basic s);
//! Return 1 if s is an Symbol, 0 if not.
int is_a_Symbol(const basic s);

#ifdef __cplusplus
}
#endif
#endif
