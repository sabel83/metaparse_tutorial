#ifndef MPLLIBS_METAPARSE_LIT_HPP
#define MPLLIBS_METAPARSE_LIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/push_back.hpp>

#include <string>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      template <class C>
      struct literal_expected
      {
        typedef literal_expected type;

        static std::string get_value()
        {
          return std::string("Expected: ") + C::type::value;
        }
      };
    }
  
    template <class C>
    struct lit :
      accept_when<
        one_char,
        typename boost::mpl::lambda<
          boost::mpl::equal_to<boost::mpl::_1, C>
        >::type,
        mpllibs::metaparse::errors::literal_expected<C>
      >
    {};
  }
}

#endif


