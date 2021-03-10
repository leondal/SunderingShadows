//	_freeze.c
//	Mage ability
//	Written 14194 by Bohemund

#include <std.h>

inherit DAEMON;

int cmd_freeze(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i, frozen, level;
    string what, *strengths, *weaknesses;
    object *inv;

    this_player()->set_magic_round();
    tp = this_player();
    level = (int)tp->query_level();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() != "mage") {
	write("You mumble in confusion.");
	say(tp->query_cap_name()+" mumbles in confusion.", tp);
	return 1;
    }
    if(level < 10) {
      notify_fail("You are not sufficiently trained in the "
		  "magical arts to cast this spell.\n");
      return 0;
    }
    if(environment(tp)->query_property("no magic")) {
	notify_fail("Something seems to be blocking your concentration.\n");
	return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 20) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
  	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Cast cone of cold at what?\n");
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
	notify_fail(ob->query_cap_name()+" is not alive!\n");
	return 0;
    }
    if(ob == tp) {
	notify_fail("Not a very intelligent thing to do.\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    if(ob->query_property("no cold")) {
        notify_fail(sprintf("%s is immune to cold attacks.\n", 
          ob->query_cap_name()));
        return 0;
    }
    if(!ob->kill_ob(tp, 0)) return 1;
    attack = (int)tp->query_skill("magic attack");
    wisdom = (int)ob->query_stats("wisdom");
    attack -= wisdom;
    weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses))
	weaknesses = ({ });
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths))
	strengths = ({ });
    if(member_array("cold", weaknesses) != -1)
	attack += random( (attack/2)+2 );
    else {
        if(member_array("cold", strengths) != -1)
	    attack -= random(wisdom +5);
    }
    if(member_array("magic", weaknesses) != -1)
	attack += random( (attack/2) + 2 );
    else {
	if(member_array("magic", strengths) != -1)
	    attack -= random(wisdom + 5);
    }
    if(!ob->query_property("no paralyze")) 
      frozen = random(10);
    if(attack < 1) attack = 0;
    if((string)tp->query_class() == "mage") attack++;
    write("%^BOLD%^%^CYAN%^You cast a cone of cold!");
    tell_room(environment(tp), "%^CYAN%^%^BOLD%^"+tp->query_cap_name()+
	      " casts a cone of cold at "+(string)ob->query_cap_name()+".", 
	      ({ ob, tp }));
    tell_object(ob, "%^CYAN%^%^BOLD%^"+tp->query_cap_name()+
		" casts a cone of cold at you.");
    tp->set_casting( ((attack + attack)/50 + attack/20) * 6 );
    if(frozen == 1) {
      ob->set_paralyzed(random(level)+ 20);
      tell_room(environment(tp), "%^CYAN%^%^BOLD%^"+ob->query_cap_name()+
		" is frozen solid!", ({ob, tp}) );
      tell_object(ob, "%^CYAN%^%^BOLD%^You are frozen solid!");
      write("%^BOLD%^%^CYAN%^"+ob->query_cap_name()+" is frozen solid!");
      tp->add_mp(-(random(level)));
    }
    tp->add_skill_points( ((attack + attack)/50 + attack/20) * 5 );
    tp->add_mp(-(20 + random(25)) );
    return 1;
}

void help() {
    write("Syntax: <freeze [(living)]>\n"
	"This incantation casts a frigid cone of cold at the living "
	"object named, or, if in "
	"battle and no arguments are used, at your current opponent.\n");
}






