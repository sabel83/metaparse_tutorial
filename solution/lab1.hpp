#ifndef LAB1_HPP
#define LAB1_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xpressive/xpressive.hpp>

boost::xpressive::sregex

  // ""
    regex_ = boost::xpressive::sregex::compile("")

  // "a"
  , regex_a = boost::xpressive::sregex::compile("a")

  // "abc"
  , regex_abc = boost::xpressive::sregex::compile("abc")

  // "b*"
  , regex_b_ = boost::xpressive::sregex::compile("b*")

  // "ab*"
  , regex_ab_ = boost::xpressive::sregex::compile("ab*")

  // "b*c"
  , regex_b_c = boost::xpressive::sregex::compile("b*c")

  // "ab*c"
  , regex_ab_c = boost::xpressive::sregex::compile("ab*c")

  // "a.*c"
  , regex_a__c = boost::xpressive::sregex::compile("a.*c")

  // "a1*c"
  , regex_a1_c = boost::xpressive::sregex::compile("a1*c")

  // "(abc)*"
  , regex__abc__ = boost::xpressive::sregex::compile("(abc)*")

  ;

#endif

