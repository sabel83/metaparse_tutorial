#ifndef MPLLIBS_METAPARSE_V1_UTIL_IS_DIGIT_HPP
#define MPLLIBS_METAPARSE_V1_UTIL_IS_DIGIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/util/in_range.hpp>

#include <boost/mpl/char.hpp>
#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <class C = boost::mpl::na>
        struct is_digit :
          in_range<boost::mpl::char_<'0'>, boost::mpl::char_<'9'> >::apply<C>
        {};

        template <>
        struct is_digit<boost::mpl::na>
        {
          typedef is_digit type;

          template <class C = boost::mpl::na>
          struct apply : is_digit<C> {};
        };
      }
    }
  }
}

#endif

