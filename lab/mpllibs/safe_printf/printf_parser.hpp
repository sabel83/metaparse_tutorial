#ifndef MPLLIBS_SAFE_PRINTF_PRINTF_PARSER_HPP
#define MPLLIBS_SAFE_PRINTF_PRINTF_PARSER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/grammar/printf_grammar.hpp>

#include <mpllibs/metaparse/build_parser.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    typedef
      mpllibs::metaparse::build_parser<mpllibs::safe_printf::grammar::S>
      printf_parser;
  }
}

#endif

