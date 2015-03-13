TARGET=libdbproto.a
CC = g++
CXXFLAGS = -g -Wall 
LIBS = -lprotobuf
INC = 
SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc, %.o, $(SRCS))

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -cr  $(TARGET) $(OBJS)

%.o : %.cc
	$(CC) -c -o $@ $< $(CXXFLAGS) $(LIBS) $(INC)

clean:
	rm -rf $(OBJS)
