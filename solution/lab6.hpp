#ifndef LAB6_HPP
#define LAB6_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <lab3.hpp>

#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/foldl.hpp>
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/xpressive/xpressive.hpp>

#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/char.hpp>

/*
 * Semantic actions
 */

struct build_char_
{
  typedef build_char_ type;

  template <class C>
  using apply = r_char<C>;
};

template <class RegExp, char Repeat>
struct build_unary_item_impl;

template <class RegExp>
struct build_unary_item_impl<RegExp, '*'> : r_star<RegExp> {};

template <class RegExp>
struct build_unary_item_impl<RegExp, 'x'> : RegExp {};

struct build_unary_item
{
  typedef build_unary_item type;

  template <class S>
  using apply =
    build_unary_item_impl<
      boost::mpl::front<S>,
      boost::mpl::back<S>::type::value
    >;
};

struct build_reg_exp
{
  typedef build_reg_exp type;

  template <class NewExp, class OldExp>
  using apply = r_concat<OldExp, NewExp>;
};

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

struct reg_exp;

typedef mpllibs::metaparse::always<mpllibs::metaparse::lit_c<'.'>, r_dot> any;

typedef
  mpllibs::metaparse::transform<
    mpllibs::metaparse::one_of<
      mpllibs::metaparse::letter,
      mpllibs::metaparse::digit
    >,
    build_char_
  >
  char_;

typedef
  mpllibs::metaparse::middle_of<
    mpllibs::metaparse::lit_c<'('>,
    reg_exp,
    mpllibs::metaparse::lit_c<')'>
  >
  bracket_exp;

typedef mpllibs::metaparse::one_of<any, bracket_exp, char_> item;

typedef
  mpllibs::metaparse::transform<
    mpllibs::metaparse::sequence<
      item,
      mpllibs::metaparse::one_of<
        mpllibs::metaparse::lit_c<'*'>,
        mpllibs::metaparse::return_<boost::mpl::char_<'x'>>
      >
    >,
    build_unary_item
  >
  unary_item;

struct reg_exp :
  mpllibs::metaparse::foldl<unary_item, r_empty, build_reg_exp>
{};

typedef mpllibs::metaparse::build_parser<reg_exp> regex_parser;

#ifdef REGEX
  #error REGEX already defined
#endif
#define REGEX(s) (regex_parser::apply<MPLLIBS_STRING((s))>::type::run())

#endif

