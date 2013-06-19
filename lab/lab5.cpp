// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <lab5.hpp>

#include <tmp_test.hpp>

#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/pair.hpp>
#include <boost/mpl/char.hpp>

int main()
{
  using boost::is_same;
  using boost::mpl::pair;
  using boost::mpl::char_;

  return
    (
         true

/*      && TEST_SAME(
        (pair<char_<'a'>, char_<'a'>>),
        (beginning_and_end::type::apply<MPLLIBS_STRING("a")>::type)
      )*/

/*      && TEST_SAME(
        (pair<char_<'a'>, char_<'b'>>),
        (beginning_and_end::type::apply<MPLLIBS_STRING("ab")>::type)
      )*/

/*      && TEST_SAME(
        (pair<char_<'H'>, char_<'o'>>),
        (beginning_and_end::type::apply<MPLLIBS_STRING("Hello")>::type)
      )*/
    ) ? 0 : 1;
}


