# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

GEN_TOC = tools/gen_toc
DST = html
TOC ?= generate

ifeq ($(TOC), generate)
  TOC_STYLE = pandoc_html
else
  TOC_STYLE = none
endif

html : $(DST)/index.html

$(DST)/index.html : README.md
	$(GEN_TOC) -i $< -o - -t $(TOC_STYLE) \
	| grep -v secure.travis-ci.org \
        | sed 's/^[#] /% /' \
	| sed 's/https:\/\/raw\.github\.com\/sabel83\/metaparse_tutorial\/master\/doc\/html\///' \
	| pandoc --from markdown --to html -c style.css -o $@

clean :
	-rm $(DST)/index.html

