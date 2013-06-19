#ifndef TMP_TEST_HPP
#define TMP_TEST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/type_traits/is_same.hpp>

#include <iostream>

#ifdef REMOVE_BRACKET
  #error REMOVE_BRACKET already defined
#endif
#define REMOVE_BRACKET(...) __VA_ARGS__

#ifdef TEST_SAME
  #error TEST_SAME already defined
#endif
#define TEST_SAME(A, B) \
  (test_same<REMOVE_BRACKET A, REMOVE_BRACKET B>(#A, #B, __FILE__, __LINE__))

template <class A, class B>
bool test_same(
  const char* a_,
  const char* b_,
  const char* fn_,
  unsigned int line_
)
{
  const bool ok = boost::is_same<A, B>::type::value;
  if (!ok)
  {
    std::cout
      << fn_ << ":" << line_ << " ERROR: " << a_ << " != " << b_ << std::endl;
  }
  return ok;
}

#endif

