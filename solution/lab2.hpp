#ifndef LAB2_HPP
#define LAB2_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xpressive/xpressive.hpp>

boost::xpressive::sregex

  // ""
    regex_ = boost::xpressive::sregex::compile("")

  // "a"
  , regex_a = boost::xpressive::as_xpr('a')

  // "abc"
  , regex_abc =
       boost::xpressive::as_xpr('a')
    >> boost::xpressive::as_xpr('b')
    >> boost::xpressive::as_xpr('c')

  // "b*"
  , regex_b_ = *boost::xpressive::as_xpr('b')

  // "ab*"
  , regex_ab_ = boost::xpressive::as_xpr('a') >> *boost::xpressive::as_xpr('b')

  // "b*c"
  , regex_b_c = *boost::xpressive::as_xpr('b') >> boost::xpressive::as_xpr('c')

  // "ab*c"
  , regex_ab_c =
       boost::xpressive::as_xpr('a')
    >> *boost::xpressive::as_xpr('b')
    >> boost::xpressive::as_xpr('c')

  // "a.*c"
  , regex_a__c =
       boost::xpressive::as_xpr('a')
    >> *boost::xpressive::_
    >> boost::xpressive::as_xpr('c')

  // "a1*c"
  , regex_a1_c =
       boost::xpressive::as_xpr('a')
    >> *boost::xpressive::as_xpr('1')
    >> boost::xpressive::as_xpr('c')

  // "(abc)*"
  , regex__abc__ =
    *(
         boost::xpressive::as_xpr('a')
      >> boost::xpressive::as_xpr('b')
      >> boost::xpressive::as_xpr('c')
    )

  ;

#endif

