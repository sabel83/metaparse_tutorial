#ifndef LAB6_HPP
#define LAB6_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <lab3.hpp>

/*
 * Semantic actions
 */

struct build_char_;
struct build_unary_item;
struct build_reg_exp;

/*
 * The parser
 *
 * reg_exp ::= unary_item*
 * unary_item ::= item '*'?
 * item ::= any | bracket_exp | char_
 * any ::= '.'
 * bracket_exp ::= '(' reg_exp ')'
 * char_ ::= number | letter
 * number ::= '0'..'9'
 * letter ::= 'a'..'z' | 'A'..'Z'
 * 
 */


#ifdef REGEX
  #error REGEX already defined
#endif

#endif

