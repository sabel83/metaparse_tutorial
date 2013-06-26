# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

GEN_TOC = tools/gen_toc
DST = html
TOC ?= generate

PNG_SRC = $(wildcard gfx/*.png)
PNG_DST = $(patsubst gfx/%,html/%, $(PNG_SRC))

ifeq ($(TOC), generate)
  TOC_STYLE = pandoc_html
else
  TOC_STYLE = none
endif

html : $(DST)/index.html

$(PNG_DST) : html/% : gfx/%
	cp $< $@

$(DST)/index.html : README.md $(PNG_DST)
	$(GEN_TOC) -i $< -o - -t $(TOC_STYLE) \
	| grep -v secure.travis-ci.org \
        | sed 's/^[#] /% /' \
	| sed 's/https:\/\/raw\.github\.com\/sabel83\/metaparse_tutorial\/master\/gfx\///' \
	| pandoc --from markdown --to html -c style.css -o $@

clean :
	-rm $(DST)/index.html $(PNG_DST)

