
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++98 -g

# Executable name
TARGET = main

COVFLAGS = --coverage -O0 

# Source files
SRCS = DemoMain.cpp ChatHistoryIterator.cpp CtrlCat.cpp Dogorithm.cpp LogMessageCommand.cpp SendMessageCommand.cpp Users.cpp User1.cpp User2.cpp User3.cpp Message.cpp DeliveredState.cpp ReadState.cpp SentState.cpp  
OBJS = $(SRCS:.cpp=.o)

# Build rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

coverage: clean
	$(CXX) $(CXXFLAGS) $(COVFLAGS) $(SRCS) -o $(TARGET)
	./$(TARGET)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory=out

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.gcov coverage.info
	rm -rf out

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)



