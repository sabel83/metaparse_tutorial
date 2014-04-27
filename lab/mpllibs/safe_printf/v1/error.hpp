#ifndef MPLLIBS_SAFE_PRINTF_V1_ERROR_HPP
#define MPLLIBS_SAFE_PRINTF_V1_ERROR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/fwd/error.hpp>

#include <string>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace v1
    {
      namespace error
      {
        struct no_percentage_char_expected
        {
          typedef no_percentage_char_expected type;

          static std::string get_value()
          {
            return "No % char expected";
          }
        };
      }
    }
  }
}

#endif

