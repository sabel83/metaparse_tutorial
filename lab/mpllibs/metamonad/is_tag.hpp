#ifndef MPLLIBS_METAMONAD_IS_TAG_HPP
#define MPLLIBS_METAMONAD_IS_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/is_same.hpp>

#include <boost/mpl/tag.hpp>
#include <boost/mpl/has_xxx.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      BOOST_MPL_HAS_XXX_TRAIT_DEF(type)
    }

    template <class T, class E = boost::mpl::na>
    struct is_tag :
      is_same<
        boost::mpl::tag<typename E::type>,
        // Tags coming from Boost.Mpl are not metaprogramming values
        if_<impl::has_type<T>, T, returns<T> >
      >
    {};

    template <class T>
    struct is_tag<T, boost::mpl::na> : tmp_value<is_tag<T, boost::mpl::na> >
    {
      template <class E>
      struct apply : is_tag<T, E> {};
    };
  }
}

#endif

