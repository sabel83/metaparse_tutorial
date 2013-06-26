#ifndef LAB3_HPP
#define LAB3_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xpressive/xpressive.hpp>

#include <boost/proto/deep_copy.hpp>

/*
 * Elements to build the regular expressions from
 */

#ifdef RUN
  #error RUN already defined
#endif
#define RUN(...) static decltype(__VA_ARGS__) run() { return (__VA_ARGS__); }

// Empty regular expression
struct r_empty
{
  typedef r_empty type;

  RUN(boost::xpressive::nil)
};

// Matches any character (.)
struct r_dot
{
  typedef r_dot type;

  RUN(boost::xpressive::_)
};

// Matches repetitions (E*)
template <class E>
struct r_star
{
  typedef r_star type;

  RUN(boost::proto::deep_copy(*E::type::run()))
};

// Concatenates two regular expressions (AB)
template <class A, class B>
struct r_concat
{
  typedef r_concat type;

  RUN(boost::proto::deep_copy(A::type::run() >> B::type::run()))
};

// Matches one specific character (C)
template <class C>
struct r_char
{
  typedef r_char type;

  RUN(boost::xpressive::as_xpr(C::type::value))
};

// Used by this header only
#undef RUN

#endif

