//已知两个已经排好序的链表L1 L2，用基本的表操作实现两个链表的交和并
//实现两个链表的交
List InterSect(List L1, List L2){
    List L3, PL1, PL2, PL3, Tmp;
    PL1 = L1->Next;
    PL2 = L2->Next;
    L3 = MakeEmpty(NULL);
    PL3 = L3->Next;
    //错误判断
    if(PL1 == NULL || PL2 == NULL){
        printf("L1 OR L2 are NULL!");
        return L3;
    }
   
    while(PL1 != NULL && PL2 != NULL){
        if(PL1->Element < PL2->Element)
                PL1 = PL1->Next;
        else if(PL1->Element > PL2->Element)
                PL2 = PL2->Next;
             else{
                    Insert(PL1->Element, L3, PL3);
                    PL1 = PL1->Next;
                    PL2 = PL2->Next;
                    PL3 = PL3->Next;
             }
     }
     return L3;
}
              
//实现两个链表的与操作
List Union(List L1, List L2){
List L3, PL1, PL2, PL3, Tmp;
    PL1 = L1->Next;
    PL2 = L2->Next;
    L3 = MakeEmpty(NULL);
    PL3 = L3->Next;

    while(PL1 != NULL && PL2 != NULL){
            if(PL1->Element < PL2->Element){
                Insert(PL1->Element, L3, PL3);
                PL1 = PL1->Next;
                PL3 = PL3->Next;
            }
            else if(PL1->Element > PL2->Element)
                    Insert(PL2->Element, L3, PL3);
                    PL2 = PL2->Next;
                    PL3 = PL3->Next;
            }
            else{
                 Insert(PL1->Element, L3, PL3);
                 PL1 = PL1->Next;
                 PL2 = PL2->Next;
                 PL3 = PL3->Next;
            }
    }

/*  这样操作不行，因为没有申请空间
    if(PL1 == NULL && PL2 != NULL){
        PL3->Next = PL2;
        return L3;
    }
    if(PL1 != NULL && PL2 == NULL){
        L3->Next = PL1;
        return L3;
    }
 */
    while(PL1 != NULL){
        Insert(PL1->Element, L3, PL3);
        PL1 = PL1->Next;
        PL3 = PL3->Next;
    }
    while(PL2 != NULL){
        Insert(PL2->Element, L3, PL3);
        PL2 = PL2->Next;
        PL3 = PL3->Next;
    }
    return L3;
}    



