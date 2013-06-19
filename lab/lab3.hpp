#ifndef LAB3_HPP
#define LAB3_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xpressive/xpressive.hpp>

/*
 * Elements to build the regular expressions from
 */

// Empty regular expression
struct r_empty;

// Matches any character (.)
struct r_dot;

// Matches repetitions (E*)
template <class E>
struct r_star;

// Concatenates two regular expressions (AB)
template <class A, class B>
struct r_concat;

// Matches one specific character (C)
template <class C>
struct r_char;

#endif

