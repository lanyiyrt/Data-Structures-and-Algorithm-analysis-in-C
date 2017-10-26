void printf(List L){
  List P;
  P = L->Next;
  if(P == NULL){
    printf("No data!");
    return;
  }
  while(P != NULL){
    printf("%d ", P->Element);
    P = P->Next;
  }
}
