//	_lockpick.c
//	from the Nightmare mudlib
//	Rogue ability
//	created by Descartes of Borg 211092
//	You will be assimilated.

#include <std.h>

inherit DAEMON;

int cmd_lockpick(string str) {
    string what;
    int which, i, skip, locks;
    int resist;
    object ob;
    object *inv;

    if(!str) {
        notify_fail("Lockpick what?\n");
	return 0;
    }
    ob = present(str, this_player());
    if(!ob) ob = present(str, environment(this_player()));
    if(!ob) ob = environment(this_player());
    if(!ob->id(str)) {
	notify_fail("You cannot lockpick that.\n");
	return 0;
    }
    ob->set_disable();
    if(!ob->query_locked(str)) {
	notify_fail("The "+str+" is not locked!\n");
	return 0;
    }
    locks = (int)this_player()->query_skill("locks");
    inv = all_inventory(this_player());
    for(i=0; i<sizeof(inv); i++) {
	locks += (int)inv[i]->query_property("lockpicking tool");
    }
    resist = (int)ob->query_property("magic hold");
    if(locks < (random(101) + resist)) {
	this_player()->add_hp(-5);
	write("You fail to pick the lock.\n");
	if((int)this_player()->query_stats("dexterity") < random(101)) {
	    write("You cut yourself on the lock!\n");
        this_player()->cause_typed_damage(this_player(), this_player()->return_target_limb(), random(10), "untyped");
	    say(this_player()->query_cap_name()+" gets cut picking the lock.\n");
	    this_player()->add_skill_points("locks", random(5));
	    return 1;
  	}
        this_player()->add_skill_points("locks", random(7));
	say(this_player()->query_cap_name()+" fails to pick the lock.\n", this_player());
	return 1;
    }
    if(!ob->pick_lock(str)) {
	this_player()->add_hp(-5);
	write("A magic force prevents you from picking the lock.\n");
	say("A magic force prevents "+this_player()->query_cap_name()+" from the picking the lock.\n");
	this_player()->add_skill_points("locks", random(resist));
	return 1;
    }
    write("You pick the lock.\n");
    say(this_player()->query_name()+" successfully picks the lock.\n", this_player());
    this_player()->add_skill_points("locks", 10 + resist);
    return 1;
}

void help() {
    write("Syntax: <lockpick [(item)]>\n\n"+
	"This command is an attempt to pick the lock on an item if an item\n"+
	"is specified, or a lock in the room if no item is specified.\n");
}
