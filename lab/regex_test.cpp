// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <regex_test.hpp>

#include <iostream>

namespace
{
  bool contains(const boost::xpressive::sregex& re_, const std::string& s_)
  {
    boost::xpressive::smatch w;
    return regex_search(s_, w, re_);
  }

  bool test_regex(
    const boost::xpressive::sregex& re_,
    const std::string& sre_,
    const std::string& s_
  )
  {
    using boost::xpressive::sregex;

    const bool matches = contains(re_, s_);
    const bool ref_matches = contains(sregex::compile(sre_), s_);
    const bool success = matches == ref_matches;

    std::cout
      << "  \"" << s_ << "\": " << (matches ? "matches" : "does not match")
      << (success ? "" : " <---------------- ERROR")
      << std::endl;

    return success;
  }

  bool fold_test_regex(
    const boost::xpressive::sregex& re_,
    const std::string& sre_
  )
  {
    return true;
  }

  template <class T, class... Ts>
  bool fold_test_regex(
    const boost::xpressive::sregex& re_,
    const std::string& sre_,
    T t_,
    Ts... ts_
  )
  {
    const bool r_this = test_regex(re_, sre_, t_);
    const bool r_remaining = fold_test_regex(re_, sre_, ts_...);
    return r_this && r_remaining;
  }
  
  
  template <class T, class... Ts>
  bool and_(T t_, Ts... ts_) { return t_ && and_(ts_...); }
}

bool all_tests(
  const boost::xpressive::sregex& re_,
  const std::string& sre_
)
{
  std::cout << "REGEX \"" << sre_ << "\"" << std::endl;
  return
    fold_test_regex(
        re_
      , sre_
      , ""
      , "a"
      , "ac"
      , "bac"
      , "abc"
      , "abbbbc"
      , "a1111c"
      , "abcabcabcabc"
    );
}

