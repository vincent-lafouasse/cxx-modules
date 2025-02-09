NAME = megaphone

SRCS = megaphone.cpp

CXX = c++
CXXFLAGS  = -Wall -Wextra -Werror
CXXFLAGS += -g3
CXXFLAGS += -std=c++98 -pedantic
CPPFLAGS  = -I. -MMD -MP

LDFLAGS =
LDLIBS =

OBJS := $(SRCS:%=build/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all
all: build

.PHONY: bonus
bonus: build

.PHONY: build
build: $(NAME)

.PHONY: run
run: build
	./$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# compiling stage
build/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: re
re: fclean build

.PHONY: clean
clean:
	rm -rf build/src

.PHONY: fclean
fclean: clean
	rm -rf build
	rm -rf $(NAME)

.PHONY: update
update: clean
	mkdir -p build
	bear  --output build/compile_commands.json -- make build

# aliases
.PHONY: b c u r
b: build
c: clean
u: update
r: run

-include $(DEPS)
