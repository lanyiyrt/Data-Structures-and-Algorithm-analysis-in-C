#include <stdio.h>
#include <stdlib.h>
#include"ListMe.h"

List Union(List L1, List L2){
    List ResultL;
    ElementType InsertElement;
    Position L1Pos, L2Pos, ResPos;
    L1Pos = L1->Next;
    L2Pos = L2->Next;
    MakeEmpty(ResultL);
    ResPos = ResultL->Next;
    while(L1Pos != NULL && L2Pos != NULL){
        if(L1Pos->Element < L2Pos->Element){
            InsertElement = L1Pos->Element;
            L1Pos = L1Pos->Next;
        }
        else if(L1Pos->Element > L2Pos->Element){
            InsertElement = L2Pos->Element;
            L2Pos = L2Pos->Next;
        }
        else{
            InsertElement = L1Pos->Element;
            L1Pos = L1Pos->Next;
            L2Pos = L2Pos->Next;
        }
        Insert(InsertElement, ResultL, ResPos);
        ResPos = ResultL->Next;
    }
    while(L1Pos != NULL){
        Insert(L1Pos->Element, ResultL, ResPos);
        L2Pos = L1Pos->Next;
        ResPos = ResultL->Next;
    }
    while(L1Pos != NULL){
        Insert(L2Pos->Element, ResultL, ResPos);
        L2Pos = L2Pos->Next;
        ResPos = ResultL->Next;
    }
    return ResultL;
}

int main()
{

    printf("Hello world!\n");
    return 0;
}
