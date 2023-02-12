List Bst2List(BST *bst)
{
	List L;
	int *trav, temp;

	L.elemPtr = -1;
	L.VH = bst->VH;

	for ( ; bst->elemPtr != -1; bst->VH->heap[temp].prev = -1){
		for (trav = &bst->elemPtr; bst->VH->heap[*trav].next != -1; trav = &bst->VH->heap[*trav].next){}
		temp = *trav;
		bst->VH->heap[temp].next = L.elemPtr;
		L.elemPtr = temp;
		*trav = bst->VH->heap[*trav].prev;
	}

	return L;
}