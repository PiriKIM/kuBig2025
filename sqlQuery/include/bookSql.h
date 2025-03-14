#pragma once

#include <stdio.h>
#include <string.h>
#include <mysql.h>
// sudo apt install libmysql++**
// dpkg -L libmysqlclient-dev | grep mysql.h
// cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// libmysqlclient.so    libmysqlclient.a

typedef struct{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;

enum menu
{
    SELECT,     // 0
    INSERT,     // 1
    DROP,       // 2
    ALTER,      // 3
    QUERY,      // 4
    EXIT        // 5
};

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);
