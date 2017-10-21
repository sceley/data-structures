typedef struct {
    QueuePtr base;
    QueuePtr top;
    int stacksize;
}SqStack;

bool InitStack(SqStack &S, int _stacksize) {
    S.base = (QueuePtr)malloc(_stacksize * sizeof(QNode));
    if(!S.base)
        return false;
    S.top = S.base;
    S.stacksize = _stacksize;
    return true;
};

bool Push(SqStack &S, int carNumber, int time) {
    S.top->carNumber = carNumber;
    S.top->time = time;
    S.top++;
    return true;
};

int GetLocation(SqStack S, int carNumber) {
    QueuePtr p = S.base;
    int location = 1;
    for(; p->carNumber != carNumber; ) {
        p++;
        location++;
    }
    return location;
};

bool Pop(SqStack &S, LinkQueue &Q, int carNumber, int _time, int &time) {
    if(S.top != S.base) {
        int location = GetLocation(S, carNumber);
        if(S.top - S.base > location) {
            SqStack _S;
            InitStack(_S, S.top - S.base - location);
            for(; S.top - S.base != location; ) {
                S.top--;
                Push(_S, S.top->carNumber, S.top->time);
            }
            S.top--;
            time = S.top->time;
            for(; _S.top - _S.base > 0; ) {
                _S.top--;
                Push(S, _S.top->carNumber, _S.top->time);
            }
        }
        else {
            S.top--;
            time = S.top->time;
            return true;
        }
        if(!QueueEmpty(Q)) {
            int _carNumber;
            DeQueue(Q, _carNumber);
            Push(S, _carNumber, _time);
        }
    }
    else {
        return false;
    }
};
