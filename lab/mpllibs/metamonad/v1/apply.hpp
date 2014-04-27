#ifndef MPLLIBS_METAMONAD_V1_APPLY_HPP
#define MPLLIBS_METAMONAD_V1_APPLY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/apply.hpp>
#include <mpllibs/metamonad/v1/impl/define_td_metafunction_eval_arg.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

// For BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#include <boost/mpl/apply.hpp>

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/cat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <
        class F,
        BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, class T)
      >
      struct apply :
        F::type::template apply<
          BOOST_PP_ENUM(
            BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
            MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG,
            ~
          )
        >
      {};

      #ifdef MPLLIBS_APPLY_CASE
      #  error MPLLIBS_APPLY_CASE already defined
      #endif
      #define MPLLIBS_APPLY_CASE(z, n, unused) \
        template <class F BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n,class T)>\
        struct \
          apply< \
            F BOOST_PP_COMMA_IF(n) \
            BOOST_PP_ENUM_PARAMS(n, T) \
            BOOST_PP_COMMA_IF( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n) \
            ) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
              boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > : \
          F::type::template apply< \
            BOOST_PP_ENUM(n, MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG, ~) \
          > \
        {};

      BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_APPLY_CASE, ~)

      #undef MPLLIBS_APPLY_CASE
    }
  }
}

#endif

