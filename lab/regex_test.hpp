#ifndef REGEX_TEST_HPP
#define REGEX_TEST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xpressive/xpressive.hpp>
#include <string>

bool all_tests(
  const boost::xpressive::sregex& re_,
  const std::string& sre_
);

#endif

