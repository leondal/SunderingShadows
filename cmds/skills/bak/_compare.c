//	/bin/user/_compare.c
//	from the Nightmare mudlib
//	Fighter ability to distinguish among weapons and armours
//	created by Descartes of Borg 19 november 1992

#include <std.h>

inherit DAEMON;

int cmd_compare(string str) {
    string what1, what2;
    object ob1, ob2;

    if(!str) {
	notify_fail("Compare what to what?\n");
	return 0;
    }
    if(sscanf(str, "%s to %s", what1, what2) != 2) {
	notify_fail("Compare what to what?\n");
	return 0;
    }
    if((string)this_player()->query_class() != "fighter") {
	notify_fail("You do not know enough about weapons and armours.\n");
	return 0;
    }
    if((int)this_player()->query_level() *5 < random(101)) {
	notify_fail("You are not knowledgeable enough about these items.\n");
	return 0;
    }
    ob1 = present(what1, this_player());
    if(!ob1) ob1 = parse_objects(this_player(), what1);
    if(!ob1) {
	notify_fail("You do not have "+what1+".\n");
	return 0;
    }
    ob2 = present(what2, this_player());
    if(!ob2) ob2 = parse_objects(this_player(), what2);
    if(!ob2) {
	notify_fail("You do not have "+what2+".\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 20) {
	notify_fail("You are too tired.\n");
	return 0;
    }
    this_player()->add_mp(-20);
    if(!ob1->query_wc() && !ob2->query_wc()) {
	if(!ob1->query_ac() || !ob2->query_ac()) {
	    write("Those are not comparable items!\n");
	    return 1;
	}
	if((int)ob1->query_ac() > (int)ob2->query_ac()) {
	    write(ob1->query_short()+" looks better.\n");
	    return 1;
	}
	else if((int)ob1->query_ac() < (int)ob2->query_ac()) {
	    write(ob2->query_short()+" looks better.\n");
	    return 1;
        }
	else write("They appear equal.\n");
	return 1;
    }
    if(!ob1->query_wc() || !ob2->query_wc()) {
	write("Those two are not comparable items!\n");
	return 1;
    }
    if((int)ob1->query_wc() > (int)ob2->query_wc()) {
	write(ob1->query_short()+" looks better.\n");
	return 1;
    }
    else if((int)ob1->query_wc() < (int)ob2->query_wc()) {
	write(ob2->query_short()+" looks better.\n");
	return 1;
    }
    else write("They appear equal.\n");
    return 1;
}

void help() {
    write("Syntax: <compare [item 1] to [item 2]>\n\n"+
	"Fighters have the ability to distinguish among the physical\n"+
	"qualities of weapons and armour.  This ability will say nothing\n"+
	"about the items magical characteristics.\n");
}
