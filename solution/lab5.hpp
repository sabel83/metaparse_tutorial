#ifndef LAB5_HPP
#define LAB5_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/pair.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>

struct beginning_and_end
{
  typedef beginning_and_end type;

  template <class S>
  struct apply :
    boost::mpl::pair<
      typename boost::mpl::front<S>::type,
      typename boost::mpl::back<S>::type
    >
  {};
};

#endif

