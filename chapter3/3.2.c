void PrintLots(List L, List P){
  List Lpos, Ppos;
  Lpos = L->Next;
  Ppos = P->Next;
  int counter = 1;
  while(Lpos != NULL && Ppos != NULL){
    if(Ppos->Element == count++){
      printf("%?", Lpos->Element);
      Ppos = Ppos->Next;
    }
    Lpos = Lpos->Next;
  }
}
