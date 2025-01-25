NAME = references

SRC = main.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra
CXXFLAGS += -g3
# CXXFLAGS += -Werror
CXXFLAGS += -std=c++98

CPPFLAGS = -I.

.PHONY: build clean run log
build: $(NAME)

run: build
	./$(NAME)

log: build
	./$(NAME) >log

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

.PHONY: b r
b: build
r: run
