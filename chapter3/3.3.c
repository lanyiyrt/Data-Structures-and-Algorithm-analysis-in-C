//假设交换X元素和相邻后面元素的位置
/*单链表实现*/
void SwapListElement(List L, ElementType X){
  List P, tmpCell;
  //找到X元素前面的一个节点
  P = FindPrevious(L, X);
  //错误检测
  if(P == NULL){
    printf("No X Element");
    return;
  }
  if(P->Next == NULL){
    printf("X is the last Element!");
    return;
  }
  //交换
  TmpCell = P->Next;
  P-Next = TmpCell->Next;
  TmpCell->Next = P->Next->Next;
  P->Next->Next = TmpCell;
}


/*双链表实现*/
void SwapListElement(List L, ElementType X){
    List PreL, P, AftL; //分别指向X前面的节点，X节点和X后面的节点
    P = Find(X, L);
    PreL = FindPre(X, L);
    AftL = P-Next;
    
    if(P == NULL || P->Next == NULL){
        printf("Can not swap!");
        return;
    }
    
    //先对后向指针进行处理
    P->Next = AftL->Next;
    PreL->Next = P->Next;
    AftL->Next = P;
    //对前向指针进行处理， 和后向指针处理的方法类似；
    P->Next->Pre = P;
    P->Pre = AftL;
    AftL->Pre = PreL; 
    
}
