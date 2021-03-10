// /cmds/mortal/_show.c

#include <std.h>

inherit DAEMON;

int cmd_show(string str){
	string who, what;
	object ob,person;

	if(!str) return 0;
	sscanf(str,"%s to %s",what,who);
	if(!who) return 0;
	if(!ob = present(what,TP))
		return notify_fail("You don't have that.\n");
        if(!person = present(who,ETP))
		return notify_fail("That person is not here.\n");
	if(person == TP)
		return notify_fail("Why don't you just look at it?\n");
    if(person->query_blind()) return notify_fail("That person is blind.\n");
	tell_room(ETP,TPQCN+" shows something to "+person->query_cap_name()+".",({TP,person}));
	write("You show "+ob->query_short()+" to "+person->query_cap_name()+".");
	tell_object(person,TPQCN+" shows you "+ob->query_short()+".\n");
	tell_object(person,ob->query_long()+"\n");
	return 1;
}

void help(){
	write(
"
%^CYAN%^NAME%^RESET%^

show - show something to someone

%^CYAN%^SYNOPSIS%^RESET%^

show %^ORANGE%^%^ULINE%^ITEM%^RESET%^ to %^ORANGE%^%^ULINE%^PERSON%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

With this command you can show an %^ORANGE%^%^ULINE%^ITEM%^RESET%^ to %^ORANGE%^%^ULINE%^PERSON%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

look, glance, inventory, report
"
	);

}
