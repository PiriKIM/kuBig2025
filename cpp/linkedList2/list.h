#ifndef LIST_H
#define LIST_H

class LinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        
        Node(int data, Node *next);
    };

    Node *ptr;

public:
    LinkedList();
    LinkedList(const LinkedList& rhs);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& rhs);

    // LinkedList *operator&() { return this; }
    // const LinkedList *operator&() const { return this; }

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);

    void printList() const;
};

#endif


/*
TO DO LIST
복사 생성자, 복사 대입 연산자를 삭제하거나 (= delete)
또는 깊은 복사가 가능하게 정의
LinkedList(const LinkedList&) = delete;
LinkedList& operator=(const LinkedList&) = delete;

생성자에서 멤버 초기화 리스트 사용
더 깔끔하게 쓰면:
LinkedList::Node::Node(int data, Node* next)
    : data(data), next(next) {}

std::endl 남용 줄이기
std::endl은 출력 후 flush까지 하기 때문에 \n보다 느릴 수 있어요.
std::cout << "]\n"; 으로 바꾸는 게 더 효율적입니다.

함수 이름 | 설명
insertFirst(int data) | 맨 앞에 노드 추가
insertLast(int data) | 맨 뒤에 노드 추가
insertAfter(int prevData, int data) | 특정 노드 뒤에 노드 삽입
deleteFirst() | 첫 번째 노드 삭제
deleteLast() | 마지막 노드 삭제
deleteNode(int data) | 특정 값을 가진 노드 삭제
find(int data) | 특정 데이터를 가진 노드 검색
printList() | 전체 노드 출력
isEmpty() | 리스트가 비어있는지 확인
clear() | 모든 노드 삭제
length() | 노드 개수 반환
reverse() | 리스트 뒤집기
getNth(int index) | 인덱스에 해당하는 노드 반환
contains(int data) | 데이터 포함 여부 확인 (true/false)
*/