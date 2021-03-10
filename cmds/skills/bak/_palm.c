//	_palm.c
//	Monk ability
//	Written 081092 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_palm(string str) {
    object tp, ob;
    int faith;
    int attack, wisdom, skip, which, i;
    string what;
    object *inv;

    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if(environment(tp)->query_property("no magic")) {
	notify_fail("Something seems to be blocking your concentration.\n");
	return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 25) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
  	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Palm what?\n");
	    return 0;
	}
    }
    else {
	ob = present(str, environment(tp));
        if(!ob) ob = parse_objects(environment(tp), str);
        if(!ob) {
		notify_fail("No "+str+" here!\n");
		return 0;
	}
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing!\n");
	return 0;
    }
    if(ob == tp) {
	notify_fail("Not a very bright thing to do.\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    attack = (int)tp->query_skill("magic attack");
    faith = (int)tp->query_skill("faith");
    wisdom = (int)ob->query_stats("wisdom");
    attack = (attack/2 + faith) - (2*wisdom);
    if(attack < 1) attack = 0;
    if(faith < 25) {
        notify_fail("You are not skilled enough for that.\n");
        return 0;
    }
    if(!tp->kill_ob(ob, 0)) return 1;
    write("You let go with a quivering palm!\n");
    tell_room(environment(tp), tp->query_cap_name()+" says a prayer and lets go with quivering palms!\n", ({ tp, ob }) );
    tell_object(ob, tp->query_cap_name()+" uses "+tp->query_possessive()+" quvering palm against you!\n");
    tp->set_casting( attack/3 );
    tp->add_skill_points( attack/3);
    tp->add_mp(-(random(26)));
    return 1;
}

void help() {
    write("Syntax: <palm [(living)]>\n"+
        "Uses holy powers in battle with a quivering palm that\n"+
        "strikes out at the object named as an arg, or, if in\n"+
	"battle and no arguments are used, at your current opponent.\n");
}
