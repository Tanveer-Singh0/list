#include "linked.h"
int main()
{
    linked<int> list;

    list.add_End(10);
    list.add_End(20);
    list.add_Beg(5);
    list.add_Mid(15, 2);

    list.print_Node();

    list.delete_Node(3);
    list.print_Node();

    return 0;
}