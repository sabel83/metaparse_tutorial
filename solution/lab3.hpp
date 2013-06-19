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
struct r_empty
{
  typedef r_empty type;

  static boost::xpressive::sregex run()
  {
    return boost::xpressive::sregex::compile("");
  }
};

// Matches any character (.)
struct r_dot
{
  typedef r_dot type;

  static auto run() -> decltype(boost::xpressive::_)
  {
    return boost::xpressive::_;
  }
};

// Matches repetitions (E*)
template <class E>
struct r_star
{
  typedef r_star type;

  static boost::xpressive::sregex run()
  {
    return *E::type::run();
  }
};

// Concatenates two regular expressions (AB)
template <class A, class B>
struct r_concat
{
  typedef r_concat type;

  static boost::xpressive::sregex run()
  {
    return A::type::run() >> B::type::run();
  }
};

// Matches one specific character (C)
template <class C>
struct r_char
{
  typedef r_char type;

  static boost::xpressive::sregex run()
  {
    return boost::xpressive::as_xpr(C::type::value);
  }
};

#endif

