# Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

INCLUDES += .
CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -ansi
CXXFLAGS += -std=c++0x

# We need it for dependency file generation
CXXFLAGS += -MMD
CXXFLAGS += -MP

TEST = regex_test.o

CPPS = $(wildcard *.cpp)
OBJECTS = $(CPPS:.cpp=.o)
EXECS = $(filter-out $(TEST:.o=), $(OBJECTS:.o=))
DEPS = $(OBJECTS:.o=.d)

test : build
	$(foreach e, $(EXECS), ./$(e) &&) true

build : $(EXECS)

$(OBJECTS) : %.o : %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(foreach i, $(INCLUDES), -I$(i) ) $<
	sed -i -e '1s,\($*\)\.o[ :]*,\1.o $*.d: ,' $*.d

$(EXECS) : % : %.o $(TEST)
	$(CXX) -o $@ $< $(TEST)

clean :
	-rm $(EXECS) $(OBJECTS) $(DEPS)

all : clean build

-include $(DEPS)

