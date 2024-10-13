NAME = megaphone

SRC = megaphone.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

.PHONY: build clean
build: $(NAME)

clean:
	rm -rf $(NAME)

