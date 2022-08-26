NAME = vector_test
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
SRCS = ./srcs/vector/vector_main.cpp

all: $(NAME)

%.o: %.cpp
	$(CXX) -D NAMESPACE=std $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

std: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

ft: $(OBJS)
	$(CXX) -D NAMESPACE=ft $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
