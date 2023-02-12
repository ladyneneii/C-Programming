ArrayList getFemale(LinkList *head)
{
    ArrayList new;
    new.count = 0;
    LinkList temp, *trav;

    for (trav = head; *trav != NULL; ){
        if ((*trav)->person.gender = 'F'){
            temp = *trav;
            *trav = (*trav)->next;
            new.people[new.count] = temp->person;
            free(temp);
            new.count++;
        } else {
            trav = &(*trav)->next;
        }
    }

    return new;
}