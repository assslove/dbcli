# 用于创建proxy
TARGET=dbserv
PROTO=libdbproto.a
INC = -I/usr/local/include/libnanc -I/usr/local/include/libnanc++ -I/usr/local/include/dbcli/ -I/usr/include/mysql -I./proto/lib
LIBS = -L/usr/local/lib -L./proto/lib/ -lxml2 -lnanc -lnanc++ -ldbcli -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl -lprotobuf -ldbproto `pkg-config --cflags --libs glib-2.0`
CXXFLAGS = -g -Wall -D_GNU_SOURCE  -DENABLE_TRACE_LOG
SRCS = $(wildcard *.cpp ./proto/lib/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
CC = g++

all : $(TARGET) $(PROTO)

$(TARGET) : $(OBJS)
	$(CC)  -o $(TARGET) $(OBJS) $(CXXFLAGS) $(INC) $(LIBS)

$(PROTO) :
	./gen.sh
	make -R ./proto/lib

$(OBJS) : %.o : %.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS) $(INC) $(LIBS) 

clean:
	rm -f $(OBJS)  $(TARGET)
