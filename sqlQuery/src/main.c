#include "bookSql.h"

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "1017";
    char *db = "mydb";
    int port = 3306;
    int choice;
    
    //DB 연결
    conn = mysql_init(NULL);
    if(mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
    printf("MySQL 연결 성공\n");
    else
    {
        printf("MySQL 연결 실패\n");
        return 1;
    }
    
    while(true)
    {
        // printf("1, 2 번 중에 고르세요. ");
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case SELECT:
            fetch_books(conn);
            break;
        case INSERT:
            add_books(conn);
            break;
        case DROP:
            delete_books(conn);
            break;
        case ALTER:
            update_books(conn);
            break;
        case QUERY:
            query_books(conn);
            break;
        case EXIT:
            mysql_close(conn);
            return 0;
        default:
            break;
        }
    }

    mysql_close(conn);
    
    return 0;
}