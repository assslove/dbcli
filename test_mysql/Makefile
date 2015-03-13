
CC = g++
CXXFLAGS = -g -Wall
LIBS = -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl
INC = -I/usr/include/mysql

all : mysqlcli 

mysqlcli: mysqlcli.o
	$(CC)  -o $@ $< $(CXXFLAGS) $(INC) $(LIBS) 
mysqlcli.o : mysqlcli.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS) $(INC) $(LIBS) 

clean:
	rm -rf *.o mysqlcli
