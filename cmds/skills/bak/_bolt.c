//	_bolt.c
//	Mage ability
//	Written 15194 by Bohemund
//      based upon _fireball.c

#include <std.h>

inherit DAEMON;

int cmd_bolt(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i;
    string what, *strengths, *weaknesses;
    object *inv;

    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() != "mage") {
	write("You mumble in confusion.");
	say(tp->query_cap_name()+" mumbles in confusion.", tp);
	return 1;
    }
    if((int)tp->query_level() < 3) {
      notify_fail("You are not sufficiently trained in the "
		  "magical arts to cast such a spell.\n");
      return 0;
    }
    if(environment(tp)->query_property("no magic")) {
	notify_fail("Something seems to be blocking your concentration.\n");
	return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 18) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
  	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Bolt what?\n");
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
    if(ob == tp) {
	notify_fail("Suicidal are we?\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    if(ob->query_property("no bolt")) {
        notify_fail(sprintf("%s is immune to electrical attacks.\n", 
          ob->query_cap_name()));
        return 0;
    }
    if(!ob->kill_ob(tp, 0)) return 1; /* hack by Val to keep out PK */
    attack = (int)tp->query_skill("magic attack");
    wisdom = (int)ob->query_stats("wisdom");
    attack -= wisdom;
    weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses))
	weaknesses = ({ });
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths))
	strengths = ({ });
    if(member_array("electricity", weaknesses) != -1)
	attack += random( (attack/2)+2 );
    else {
        if(member_array("electricity", strengths) != -1)
	    attack -= random(wisdom +5);
    }
    if(member_array("magic", weaknesses) != -1)
	attack += random( (attack/2) + 2 );
    else {
	if(member_array("magic", strengths) != -1)
	    attack -= random(wisdom + 5);
    }
    if(attack < 1) attack = 0;
    if((string)tp->query_class() == "mage") attack++;
    write("%^YELLOW%^%^BOLD%^You cast a lightning bolt!");
    tell_room(environment(tp), "%^YELLOW%^%^BOLD%^"+tp->query_cap_name()+
	      " casts a lightning bolt at "+(string)ob->query_cap_name()+"!", 
	      ({ ob, tp }));
    tell_object(ob, "%^YELLOW%^%^BOLD%^"+tp->query_cap_name()+
		" casts a lightning bolt at you!");
    tp->set_casting( ((attack + attack - 5)/50 + attack/20) * 5 );
    tp->add_skill_points( ((attack + attack)/50 + attack/20) * 5 );
    tp->add_mp( -( 14 + random(4)) );
    return 1;
}

void help() {
    write("Syntax: <bolt [(living)]>\n"
	"This magical spell hurls a lightning bolt at the living thing "
	"named, or, if in "
	"battle and no arguments are used, at your current opponent.\n");
}
