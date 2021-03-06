#ifndef MPLLIBS_METAPARSE_V1_TOKEN_HPP
#define MPLLIBS_METAPARSE_V1_TOKEN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/space.hpp>
#include <mpllibs/metaparse/v1/any.hpp>
#include <mpllibs/metaparse/v1/first_of.hpp>

#include <boost/mpl/void.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class P>
      struct token : first_of<P, any<space> > {};
    }
  }
}

#endif

