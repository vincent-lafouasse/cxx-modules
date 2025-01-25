NAME = phone_book

SRC = main.cpp PhoneBook.cpp Contact.cpp Command.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra
# CXXFLAGS += -Werror
CXXFLAGS += -std=c++98

CPPFLAGS = -I.

.PHONY: build clean run
build: $(NAME)

run: build
	./$(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

