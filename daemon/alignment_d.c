//opposed_alignment exists in player_d
//Rest of these can become efuns

//alignment_d.c

#include <std.h>

inherit DAEMON;

int is_evil(object thing){
	if((int)thing->query_alignment() == 3 || (int)thing->query_alignment() == 6 || (int)thing->query_alignment() == 9)
		return 1;
	return 0;
}

int is_good(object thing){
	if((int)thing->query_alignment() == 1 || (int)thing->query_alignment() == 4 || (int)thing->query_alignment() == 7)
		return 1;
	return 0;
}

int is_neutral(object thing){
	if((int)thing->query_alignment() == 2 || (int)thing->query_alignment() == 5 || (int)thing->query_alignment() == 8)
		return 1;
	return 0;
}

int is_lawful(object thing){
    if((int)thing->query_alignment() == 1 || (int)thing->query_alignment() == 2 || (int)thing->query_alignment() == 3)
        return 1;
    return 0;
}

int is_chaotic(object thing){
    if((int)thing->query_alignment() == 7 || (int)thing->query_alignment() == 8 || (int)thing->query_alignment() == 9)
        return 1;
    return 0;
}

int is_law_neutral(object thing){
    if((int)thing->query_alignment() == 4 || (int)thing->query_alignment() == 5 || (int)thing->query_alignment() == 6)
        return 1;
    return 0;
}

int opposed_alignment(object me, object you)
{
    string *opposed;
    int my_align, your_align;
    
    if(!me || !you)
        return 0;
    
    my_align = me->query_true_align();
    your_align = you->query_true_align();
    
    if(my_align == 5 || your_align == 5)
        return 0;
    
    //If you're the polar opposite
    if(my_align - (10 - your_align) == 0)
        return 2;
    
    opposed = ({ "000", "78936", "789", "78914", "369", "000", "147", "12369", "123", "12347" });
    
    if(strsrch(opposed[my_align], your_align + "") >= 0)
        return 1;
    
    return 0;
}
