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
