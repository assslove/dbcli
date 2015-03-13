
CC = g++
CXXFLAGS = -g -Wall -fPIC -shared -DENABLE_SQL
LIBS = -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl -lnanc
INC = -I/usr/include/mysql 
INSTALL_DIR = /usr/local/include/dbcli
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all : libdbcli.so

libdbcli.so: $(OBJS)
	$(CC) -shared -o $@ $(OBJS) $(LIBS) $(INC)

%.o : %.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS) $(LIBS) $(INC)

clean:
	rm -rf *.o mysqlcli

install:
	sudo cp -r libdbcli.so /usr/local/lib
	sudo rm -rf $(INSTALL_DIR)
	sudo mkdir $(INSTALL_DIR)
	sudo cp -r *.h $(INSTALL_DIR)
