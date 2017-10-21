typedef struct QNode {
    int carNumber;
    int time;
    struct QNode * next;
}QNode, *QueuePtr;