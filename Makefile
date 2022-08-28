STD_NAME = std_container
FT_NAME = ft_container
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

STD_SRCS = srcs/std/vector_main.cpp \
srcs/std/allocator_test.cpp \
srcs/std/bidirect_it_test.cpp \
srcs/std/capacity_test.cpp \
srcs/std/constructor_test.cpp \
srcs/std/double_vector_test.cpp \
srcs/std/modifier_test.cpp \
srcs/std/operation_test.cpp \
srcs/std/relational_operators_test.cpp \
srcs/std/swap_test.cpp

FT_SRCS = srcs/ft/vector_main.cpp \
srcs/ft/allocator_test.cpp \
srcs/ft/bidirect_it_test.cpp \
srcs/ft/capacity_test.cpp \
srcs/ft/constructor_test.cpp \
srcs/ft/double_vector_test.cpp \
srcs/ft/modifier_test.cpp \
srcs/ft/operation_test.cpp \
srcs/ft/relational_operators_test.cpp \
srcs/ft/swap_test.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

STD_OBJS = $(STD_SRCS:.cpp=.o)

FT_OBJS = $(FT_SRCS:.cpp=.o)

all: $(STD_NAME) $(FT_NAME)

$(STD_NAME): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(FT_NAME): $(FT_OBJS)
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
clean:
	rm -rf $(STD_OBJS)
	rm -rf $(FT_OBJS)

fclean: clean
	rm -rf $(STD_NAME)
	rm -rf $(FT_NAME)

re: fclean all

.PHONY: all clean fclean re
