typedef struct {
    QueuePtr front;
    QueuePtr rear;
    int num;
}LinkQueue;

bool InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front)
        exit(false);
    Q.front->next = NULL;
    Q.num = 0;
    return true;
};

bool EnQueue(LinkQueue &Q, int carNumber) {
    Q.num++;
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) {
        return false;
    }
    else {
        p->carNumber = carNumber;
        p->next = NULL;
        Q.rear->next = p;
        Q.rear = p;
        return true;
    }
};

bool DeQueue(LinkQueue &Q, int &carNumber) {
    if(Q.front == Q.rear) 
        return false;
    QueuePtr p = Q.front->next;
    carNumber = p->carNumber;
    Q.front->next = p->next;
    Q.num--;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
};

bool QueueEmpty(LinkQueue Q) {
    return (Q.front == Q.rear);
};

int QueueLength(LinkQueue Q) {
    int length = 0;
    QueuePtr p;
    p = Q.front;
    for(; p->next != NULL; ) {
        p = p->next;
        length++;
    }
    return length;
};