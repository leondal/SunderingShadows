//	Truce
//	Thorn@Shadowgate
//	10/5/94
//	Wizard commands
//	_truce.c
//recoded and cleaned up by Saide@ShadowGate, August 2017 

#include <std.h>
inherit DAEMON;

int cmd_truce(string str) 
{
    object *inv;
    int faith, i;

    if(!objectp(TP) || !avatarp(TP)) return 0;
    tell_object(TP, "%^BOLD%^%^WHITE%^You enforce a truce!%^RESET%^");    
    tell_room(ETP, "%^FLASH%^%^BOLD%^%^WHITE%^"+ capitalize(TP->query_true_name())+ " raises "+TPQP+" hands to the sky and compels a truce!%^RESET%^%^RESET%^", TP);
    
    foreach(object liv in all_living(ETP))
    {
        if(!objectp(liv)) continue;
        liv->cease_all_attacks();
        continue;
    }
    return 1;
}

void help() {
    write("Syntax: <truce>\n\n"+
        "This command causes all fighting to cease in an area.\n");
}
