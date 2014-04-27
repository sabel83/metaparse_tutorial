#ifndef MPLLIBS_METAPARSE_V1_IMPL_ACCEPTED_KEYWORD_TAG_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_ACCEPTED_KEYWORD_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        struct accepted_keyword_tag :
          metamonad::tmp_tag<accepted_keyword_tag>
        {};
      }
    }
  }
}

#endif

