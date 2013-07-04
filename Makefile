# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

help :
	@echo "Supported targets:"
	@echo "  doc -> html README.md"
	@echo "  README.md"
	@echo "  html"
	@echo "  test"
	@echo "  clean"

doc : html README.md

README.md : doc/README.md
	doc/tools/gen_toc -i $< -o $@ -t github
.PHONY: README.md

html :
	$(MAKE) -C doc html
.PHONY: html


clean :
	$(MAKE) -C doc clean
	$(MAKE) -C lab clean

test :
	$(MAKE) -C lab test


