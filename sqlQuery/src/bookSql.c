#include "bookSql.h"

void print_menu(void)
{
    system("clear");
    printf("=== 도서 관리 시스템 ===\n");
    printf("0. 도서 조회\n");
    printf("1. 도서 추가\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 수정\n");
    printf("4. 쿼리문 입력\n");
    printf("5. 프로그램 종료\n");
}

void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select * from Book");// where price >= 10000 order by price desc");
    
    //쿼리 요청
    if(mysql_query(conn, query))
    {
        printf("쿼리 실패\n");
        return;    //끝나면 메인으로 돌아감. 프로그램이 꺼지진않음.
    }

    res = mysql_store_result(conn);
    if(!res)
    {
        printf("가져오기 실패\n");
        return;
    }

    Book *pBook;
    pBook = (Book *)malloc(sizeof(Book));
    int i = 0;
    // 데이터베이스의 정보를 구조체에 저장 - ORM
    while(row = mysql_fetch_row(res))
    {
        (pBook + i)->bookid= atoi(row[0]);
        strcpy((pBook + i)->bookname, row[1]);
        strcpy((pBook + i)->publisher, row[2]);
        (pBook + i)->price = atoi(row[3]);
        ++i;
        pBook = realloc(pBook, sizeof(Book) * (i + 1));
        // row가 늘어날때마다 동적 할당 크기 조절
    }

    for(int j = 0; j < i; j++)
    {
        printf("%d\t%s\t%s\t%d\n",
            (pBook + j)->bookid, (pBook + j)->bookname,
            (pBook + j)->publisher, (pBook + j)->price);
    }

    free(pBook);
    // TODO : 여기 엔터만 쳐도 넘어가게 변경
    char temp;
    getchar();
    scanf("%c", &temp);
}

void add_books(MYSQL *conn)
{
    printf("----- 도서 추가 -----\n");
    Book newbook;
    char query[255];
    //정보 입력 scanf
    printf("도서ID : ");
    scanf("%d", &newbook.bookid);
    printf("도서명 : ");
    scanf("%s", newbook.bookname);
    printf("출판사 : ");
    scanf("%s", newbook.publisher);
    printf("가격 : ");
    scanf("%d", &newbook.price);
    //query문 작성 strcpy... "insert ...."
    sprintf(query, "insert into Book values (%d, '%s', '%s', %d)",
        newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);
    //query 요청 mysql_query();
    if(mysql_query(conn, query))
        //printf("도서 추가 실패\n");
        printf("데이터 입력 실패 : %s\n", mysql_error(conn));
    else
        printf("도서 추가 완료\n");

    char temp;
    getchar();
    scanf("%c", &temp);

    return;
}

void delete_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char temp;
    char yesNo;
    printf("----- 도서 삭제 -----\n");
    Book newbook;
    char query[255];
    int bookID;
    //정보 입력 scanf
    printf("도서ID : ");
    scanf("%d", &bookID);
    //해당 도서가 있는지 조회
    sprintf(query, "select * from Book where bookid = %d", bookID);
    //조회 쿼리 요청
    if(mysql_query(conn, query))
    {
        printf("쿼리 실패\n");
        getchar();
        scanf("%c", &temp);
        return;    //끝나면 메인으로 돌아감. 프로그램이 꺼지진않음.
    }

    res = mysql_store_result(conn);
    if(res->row_count < 1)
    {
        printf("해당 번호의 도서가 존재하지 않습니다.\n");
        getchar();
        scanf("%c", &temp);
        return;
    }

    // 데이터베이스의 정보를 구조체에 저장 - ORM
    row = mysql_fetch_row(res);
    newbook.bookid = atoi(row[0]);
    strcpy(newbook.bookname, row[1]);
    strcpy(newbook.publisher, row[2]);
    newbook.price = atoi(row[3]);

    printf("\
            도서ID : %d\n\
            도서명 : %s\n\
            출판사 : %s\n\
            가격   : %d\n\
            삭제하려는 도서가 맞나요? [y/n] ",
            newbook.bookid, newbook.bookname,
            newbook.publisher, newbook.price);
    scanf(" %c", &yesNo);

    if(yesNo == 'Y' || yesNo == 'y')
    {
        sprintf(query, "delete from Book where bookid = %d", newbook.bookid);
        // query 요청 mysql_query();
        if (mysql_query(conn, query))
            printf("데이터 삭제 실패 : %s\n", mysql_error(conn));
        else
            printf("도서 삭제 완료\n");
    }
    else if(yesNo == 'N' || yesNo == 'n')
    {
        printf("도서 삭제 취소\n");
    }
    
    getchar();
    scanf("%c", &temp);

    return;
}

void update_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char temp;
    char yesNo, updateYesNo;
    printf("----- 도서 수정 -----\n");
    Book newbook, updatebook;
    char query[255];
    int bookID;
    //정보 입력 scanf
    printf("도서ID : ");
    scanf("%d", &bookID);
    //해당 도서가 있는지 조회
    sprintf(query, "select * from Book where bookid = %d", bookID);
    //조회 쿼리 요청
    if(mysql_query(conn, query))
    {
        printf("쿼리 실패\n");
        getchar();
        scanf("%c", &temp);
        return;    //끝나면 메인으로 돌아감. 프로그램이 꺼지진않음.
    }

    res = mysql_store_result(conn);
    if(res->row_count < 1)
    {
        printf("해당 번호의 도서가 존재하지 않습니다.\n");
        getchar();
        scanf("%c", &temp);
        return;
    }

    // 데이터베이스의 정보를 구조체에 저장 - ORM
    row = mysql_fetch_row(res);
    newbook.bookid = atoi(row[0]);
    strcpy(newbook.bookname, row[1]);
    strcpy(newbook.publisher, row[2]);
    newbook.price = atoi(row[3]);

    printf("\
            도서ID : %d\n\
            도서명 : %s\n\
            출판사 : %s\n\
            가격   : %d\n\
            수정하려는 도서가 맞나요? [y/n] ",
            newbook.bookid, newbook.bookname,
            newbook.publisher, newbook.price);
    scanf(" %c", &yesNo);

    if(yesNo == 'Y' || yesNo == 'y')
    {
        updatebook.bookid = newbook.bookid;
        printf("도서명 : ");
        scanf("%s", updatebook.bookname);
        printf("출판사 : ");
        scanf("%s", updatebook.publisher);
        printf("가격 : ");
        scanf("%d", &updatebook.price);
        
        printf("\
            도서ID : %d\n\
            도서명 : %s >>> %s\n\
            출판사 : %s >>> %s\n\
            가격   : %d >>> %d\n\
            다음과 같이 수정하시겠습니까? [y/n] ",
            newbook.bookid, newbook.bookname, updatebook.bookname,
            newbook.publisher, updatebook.publisher, newbook.price, updatebook.price);
        scanf(" %c", &updateYesNo);

        if(updateYesNo == 'Y' || updateYesNo == 'y')
        {
            sprintf(query, "update Book set bookname = '%s', publisher = '%s', price = %d where bookid = %d",
                updatebook.bookname, updatebook.publisher, updatebook.price, updatebook.bookid);
            // query 요청 mysql_query();
            if (mysql_query(conn, query))
                printf("데이터 수정 실패 : %s\n", mysql_error(conn));
            else
                printf("도서 수정 완료\n");
        }
        else if (updateYesNo == 'N' || updateYesNo == 'n')
        {
            printf("도서 수정 취소\n");
        }
    }
    else if(yesNo == 'N' || yesNo == 'n')
    {
        printf("도서 수정 취소\n");
    }
    
    getchar();
    scanf("%c", &temp);

    return;
}

void query_books(MYSQL *conn)
{
    printf("----- 도서 쿼리문 실행 -----\n");

    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    char tempQuery[255];
    char temp;

    printf("실행할 쿼리문을 입력하세요.\n");
    getchar();
    scanf("%[^\n]s", query);

    strcpy(tempQuery, query);

    //쿼리 요청
    if(mysql_query(conn, query))
    {
        printf("쿼리 실패\n");
        getchar();
        scanf("%c", &temp);
        return;    //끝나면 메인으로 돌아감. 프로그램이 꺼지진않음.
    }

    res = mysql_store_result(conn);
    if(!res)
    {
        printf("가져오기 실패\n");
        getchar();
        scanf("%c", &temp);
        return;
    }

    if(res->row_count < 1)
    {
        printf("요청한 쿼리문에 대한 데이터가 없습니다.\n");
        getchar();
        scanf("%c", &temp);
        return;
    }
    else
    {
        while (row = mysql_fetch_row(res))
        {
            for(int i = 0; i < res->field_count; i++)
            {
                printf("%s\t", row[i]);
            }
            printf("\n");
        }
    }

    // TODO : 여기 엔터만 쳐도 넘어가게 변경
    getchar();
    scanf("%c", &temp);

    return;
}
