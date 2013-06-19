// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <lab3.hpp>

#include <regex_test.hpp>

#include <boost/mpl/char.hpp>

int main()
{
  using namespace boost;

  return
    (
         true

//      && all_tests(r_empty::type::run(), "")

/*      && all_tests(
        r_concat<
          r_empty,
          r_char<mpl::char_<'a'>>
        >::type::run(),
        "a"
      )*/

/*      && all_tests(
        r_concat<
          r_concat<
            r_concat<
              r_empty,
              r_char<mpl::char_<'a'>>
            >,
            r_char<mpl::char_<'b'>>
          >,
          r_char<mpl::char_<'c'>>
        >::type::run(),
        "abc"
      )*/

/*      && all_tests(
        r_concat<
          r_empty,
          r_star<
            r_char<mpl::char_<'b'>>
          >
        >::type::run(),
        "b*"
      )*/

/*      && all_tests(
        r_concat<
          r_concat<
            r_empty,
            r_char<mpl::char_<'a'>>
          >,
          r_star<
            r_char<mpl::char_<'b'>>
          >
        >::type::run(),
        "ab*"
      )*/

/*      && all_tests(
        r_concat<
          r_concat<
            r_empty,
            r_star<
              r_char<mpl::char_<'b'>>
            >
          >,
          r_char<mpl::char_<'c'>>
        >::type::run(),
        "b*c"
      )*/

/*      && all_tests(
        r_concat<
          r_concat<
            r_concat<
              r_empty,
              r_char<mpl::char_<'a'>>
            >,
            r_star<
              r_char<mpl::char_<'b'>>
            >
          >,
          r_char<mpl::char_<'c'>>
        >::type::run(),
        "ab*c"
      )*/

/*      && all_tests(
        r_concat<
          r_concat<
            r_concat<
              r_empty,
              r_char<mpl::char_<'a'>>
            >,
            r_star<
              r_dot
            >
          >,
          r_char<mpl::char_<'c'>>
        >::type::run(),
        "a.*c"
      )*/

/*      && all_tests(
        r_concat<
          r_concat<
            r_concat<
              r_empty,
              r_char<mpl::char_<'a'>>
            >,
            r_star<
              r_char<mpl::char_<'1'>>
            >
          >,
          r_char<mpl::char_<'c'>>
        >::type::run(),
        "a1*c"
      )*/

/*      && all_tests(
        r_concat<
          r_empty,
          r_star<
            r_concat<
              r_concat<
                r_concat<
                  r_empty,
                  r_char<mpl::char_<'a'>>
                >,
                r_char<mpl::char_<'b'>>
              >,
              r_char<mpl::char_<'c'>>
            >
          >
        >::type::run(),
        "(abc)*"
      )*/

    ) ? 0 : 1;
}


