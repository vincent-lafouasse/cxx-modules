NAME = phone_book

SRC = PhoneBook.cpp Contact.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

CPPFLAGS = -I.

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRC) -o $(NAME)

.PHONY: build clean
build: $(NAME)

clean:
	rm -rf $(NAME)

