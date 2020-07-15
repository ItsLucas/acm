node *selectSort(struct node *head) {
    node *head1, *max, *premax, *t, *pret;
    head1 = NULL;
    while (head) // find max in orig list
    {
        max = head;
        premax = NULL;
        pret = head;
        t = head->next;
        // 1、寻找最大结点
        while (t) {
            if (t->data > max->data) {
                max = t;
                premax = pret;
            }
            pret = t;
            t = t->next;
        }
        // 2、让这个结点离开原链表
        if (max == head)       //如果找到的结点是第一个结点
            head = head->next; //让头指针向后移一位就行
        else
            premax->next = max->next;
        // 3、把此结点头插法插入新链表
        max->next = head1;
        head1 = max;
    }
    return head1;
}