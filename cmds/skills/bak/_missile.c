//	_missile.c
//	Mage ability
//	Written 131092 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_missile(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i;
    string what;
    object *inv;

    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() == "child") {
	notify_fail("You feel confused.\n");
	return 0;
     }
    if(environment(tp)->query_property("no magic")) {
	notify_fail("Something seems to be blocking your concentration.\n");
	return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 9) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
  	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Missile what?\n");
	    return 0;
	}
    }
    else {
	ob = present(str, environment(tp));
	if(!ob) {
	    sscanf(str, "%s %d", what, which);
	    inv = all_inventory(environment(tp));
	    for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
		if(inv[i]->id(what)) {
		    skip++;
		    if(skip == which) ob = inv[i];
		}
	    }
	    if(!ob) {
		notify_fail("No "+str+" here!\n");
		return 0;
	    }
	}
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing!\n");
	return 0;
    }
    if(ob==tp) {
	notify_fail("Not a very bright idea.\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    if(ob->query_property("no missile")) {
      notify_fail(sprintf("%s is immune to such magic.\n",
		  ob->query_cap_name()));
      return 0;
    }
    attack = (int)tp->query_skill("magic attack");
    wisdom = (int)ob->query_stats("wisdom");
    attack -= wisdom;
    if(attack < 1) attack = 1;
    if(!tp->kill_ob(ob, 0)) return 1; /* hack by Val to keep out PK */
    write("%^CYAN%^You cast a magic missile.");
    tell_room(environment(tp), "%^CYAN%^"+tp->query_cap_name()+
	      " casts a magic missile at "+(string)ob->query_cap_name()+".", 
	      ({ ob, tp }));
    tell_object(ob, "%^CYAN%^"+tp->query_cap_name()+
		" casts a magic missile at you.");
    tp->set_casting( attack/20 + 2 );
    tp->add_skill_points("magic attack", attack/20 + 2);
    tp->add_mp(-(random(10)));
    return 1;
}

void help() {
    write("Syntax: <missile [(living)]>\n"
	"Casts a magic missile at the living object named, or, if in "
	"battle and no arguments are used, at your current opponent.\n");
}
