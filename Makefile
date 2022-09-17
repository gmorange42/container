STD_NAME = std_container
FT_NAME = ft_container
STD_42_NAME = std_42_container
FT_42_NAME = ft_42_container
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

STD_SRCS = tests/ft_main.cpp

FT_SRCS = tests/std_main.cpp

STD_42_SRCS = tests/ft_42_main.cpp

FT_42_SRCS = tests/std_42_main.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

STD_OBJS = $(STD_SRCS:.cpp=.o)

FT_OBJS = $(FT_SRCS:.cpp=.o)

STD_42_OBJS = $(STD_42_SRCS:.cpp=.o)

FT_42_OBJS = $(FT_42_SRCS:.cpp=.o)

all: $(STD_NAME) $(FT_NAME) $(STD_42_NAME) $(FT_42_NAME)

$(STD_NAME): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(FT_NAME): $(FT_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(STD_42_NAME): $(STD_42_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(FT_42_NAME): $(FT_42_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

diff: all
	./$(STD_NAME) > std
	./$(FT_NAME) > ft
	-diff std ft > res
	echo -n $0
	cat res
	[ -s res ] && echo " KO" || echo " OK"
	rm std
	rm ft
	rm res

diff_42: all
	./$(STD_42_NAME) 42 > std_42
	./$(FT_42_NAME) 42 > ft_42
	-diff std_42 ft_42 > res
	echo -n $0
	cat res
	[ -s res ] && echo " KO" || echo " OK"
	rm std_42
	rm ft_42
	rm res

clean:
	rm -rf $(STD_OBJS)
	rm -rf $(FT_OBJS)
	rm -rf $(STD_42_OBJS)
	rm -rf $(FT_42_OBJS)

fclean: clean
	rm -rf $(STD_NAME)
	rm -rf $(FT_NAME)
	rm -rf $(STD_42_NAME)
	rm -rf $(FT_42_NAME)

re: fclean all

.PHONY: all clean fclean re
