//求减集函数
void Reduce(LinkList &La, LinkList &Lb, LinkList &Lc) {
    int aLen = La.len;
    int bLen = Lb.len;
    bool equal;
    char ae;
    char be;
    for(int i = 1; i <= aLen; i++) {
        GetElem(La, i, ae);
        for(int j = 1; j <= bLen; j++) {
            GetElem(Lb, j, be);
            equal = Equal(ae, be);
            if(equal)
                break;
        }
        if(!equal) {
            ListAppend(Lc, ae);
        }
    }
};

//求并集函数
void Sum(LinkList &La, LinkList &Lb, LinkList &Lc) {
    int aLen = La.len;
    int bLen = Lb.len;
    for(int i = 1; i <= aLen; i++) {
        char e;
        GetElem(La, i, e);
        ListAppend(Lc, e);
    }
    for(int i = 1; i <= bLen; i++) {
        int locate;
        char e;
        GetElem(Lb, i, e);
        locate = FindLocate(Lc, e);
        ListInsert(Lc, locate, e); 
    }
};

//求交集函数
void Intersection(LinkList &La, LinkList &Lb, LinkList &Lc) {
    int aLen = La.len;
    int bLen = Lb.len;
    bool equal;
    char ae;
    char be;
    for(int i = 1; i <= aLen; i++) {
        GetElem(La, i, ae);
        for(int j = 1; j <= bLen; j++) {
            GetElem(Lb, j, be);
            equal = Equal(ae, be);
            if(equal) {
                ListAppend(Lc, ae);
                break;                
            }
        }
    }
};    