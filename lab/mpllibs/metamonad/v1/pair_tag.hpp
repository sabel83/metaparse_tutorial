#ifndef MPLLIBS_METAMONAD_V1_PAIR_TAG_HPP
#define MPLLIBS_METAMONAD_V1_PAIR_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/pair_tag.hpp>
#include <mpllibs/metamonad/v1/tmp_tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      struct pair_tag : tmp_tag<pair_tag> {};
    }
  }
}

#endif

