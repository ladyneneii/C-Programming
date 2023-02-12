// not tested
void insertSorted(queueCB *qptr, VHeap *vptr, personInfo toBeInserted)
{
	int trav;
	int freendx;

	if (vptr->firstAvail != -1){
		freendx = vptr->firstAvail;
		vptr->firstAvail = vptr->node[freendx].next;
		vptr->node[freendx].per = toBeInserted;
		for (trav = &qptr->list; *trav != -1 && strcmp(vptr->node[*trav].per.patientID, toBeInserted.patientID) < 0; trav = &vptr->node[*trav].next){}
		if (strcmp(toBeInserted.patientID, vptr->node[*trav].per.patientID) < 0 || *trav != -1){
			vptr->node[freendx].next = *trav;
			*trav = freendx;
		}
	}
}


CL createComboList(LinkedList *headptr)
{
	CL new = {(Array)malloc(sizeof(struct cell)), NULL, 0};

	new.CISCO1->cnt = 0;
	while (*headptr != NULL){
		if ((*headptr)->stud.admissionExamScore >= 50.0){
			LinkedList del = *headptr;

			new.numQualifiedStudents++;
			if ((*headptr)->stud.course == CISCO1){
                int idx, idx2;
                
				for (idx = 0; idx < new.CISCO1->cnt && strcmp((*headptr)->stud.studID, new.CISCO1->studs[idx].studID) > 0; idx++){}
				for (idx2 = new.CISCO1->cnt; idx2 > idx; idx2--){
					new.CISCO1->studs[idx2] = new.CISCO1->studs[idx2-1];
				}
				new.CISCO1->studs[idx] = (*headptr)->stud;
				new.CISCO1->cnt++;
			} else {
				LinkedList temp = (LinkedList)malloc(sizeof(struct node)), *trav;

				temp->stud = (*headptr)->stud;
				for (trav = &new.CISCO2; *trav != NULL && strcmp((*headptr)->stud.studID, (*trav)->stud.studID) > 0; trav = &(*trav)->link){}
				temp->link = *trav;
				*trav = temp;
			}
			*headptr = (*headptr)->link;
			free(del);
		} else {
			headptr = &(*headptr)->link;
		}
	}

	return new;
}