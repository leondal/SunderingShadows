//	_keep.c
//	mage spell
//	created by Descartes of Borg 921116

#include <std.h>

inherit DAEMON;

int cmd_keep(string str) {
    object ob;
    string who, what, which;
    int con, cost;

    if(!str) {
        notify_fail("Keep what?\n");
        return 0;
    }
    if(sscanf(str, "%s for %s", what, who) != 2) {
        notify_fail("Keep what from whom?\n");
	return 0;
    }
    who = lower_case(who);
    ob = present(what, environment(this_player()));
    if(!ob) ob = present(what, this_player());
    if(!ob) ob = parse_objects(environment(this_player()), what);
    if(!ob) ob = parse_objects(this_player(), what);
    if(!ob) {
        notify_fail("No "+what+" to cast a keep on!\n");
	return 0;
    }
    if(ob->query_property("keep") || environment(this_player())->query_property("no magic")) {
        notify_fail("A magical force prevents you from casting that spell.\n");
  	return 0;
    }
    con = (int)this_player()->query_skill("conjuring");
    if(con < 10) {
        notify_fail("You are not skilled enough to cast such a spell.\n");
	return 0;
    }
    cost = random(con*2);
    if((int)this_player()->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    write("You cast a spell to keep the "+what+" in "+capitalize(who)+"'s possession.\n");
    say(this_player()->query_cap_name()+" casts a spell of keeping.\n", this_player());
    ob->set_property("keep", who);
    this_player()->add_skill_points("conjuring", cost);
    this_player()->add_exp(random(cost));
    call_out("remove_keep", 6*cost, ob);
    return 1;
}

void remove_keep(object ob) {
    if(!ob) return;
    ob->remove_property("keep");
}

void help() {
    write("Syntax: <keep [what] for [player]\n\n"+
	"This spell makes it impossible for anyone to carry an object other\n"+
	"than the person named by the spell caster.  The duration of the spell\n"+
 "is based on the spell casters ability to cast conjuring spells.\n"
 "See also: hold, brand\n"
 );
}
