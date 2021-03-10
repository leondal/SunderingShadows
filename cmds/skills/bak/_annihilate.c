//	_annihilate.c
//	Mage ability
//	created by Descartes of Borg 18 November 1992

#include <std.h>

inherit DAEMON;

int cmd_annihilate() {
    object *tmp;
    object *attackers;
    int mag, cost, wis;
    int i;

    this_player()->set_magic_round();
    if(this_player()->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if(this_player()->query_casting()) return 1;
    if(environment(this_player())->query_property("no attack")) {
notify_fail("A magic force prevents you from casting your spell.\n");
return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("A magic force prevents your spell.\n");
	return 0;
    }
    attackers = (object *)this_player()->query_attackers();
    if(!attackers || !sizeof(attackers)) {
	notify_fail("You are not in battle!\n");
	return 0;
    }
    mag = (int)this_player()->query_skill("magic attack");
    if(mag < 50) {
	notify_fail("You are not at all skilled enough for such a power spell.\n");
	return 0;
    }
    tmp = ({});
    this_player()->set_disable();
    for(i=0; i<sizeof(attackers); i++) {
        if(!attackers[i]) continue;
	if(member_array(attackers[i], tmp) != -1) continue;
	tmp += ({ attackers[i] });
	if((int)this_player()->query_mp() < (cost = 20+random(100))) {
	    write(attackers[i]->query_cap_name()+": Too low on magic power.");
	    continue;
 	}
	wis = (int)attackers[i]->query_stats("wisdom");
	wis = random(wis*3)+random(wis*2)+random(wis*2);
	mag -= wis;
	mag += ((int)this_player()->query_stats("wisdom"));
	mag += (int)this_player()->query_level();
	if(mag < 1) write(attackers[i]->query_cap_name()+": Too powerful for you!");
	mag = mag*2;
	this_player()->add_mp(-cost);
	this_player()->add_skill_points("magic attack", random(cost));
        attackers[i]->add_hp(-(random(mag)));
	this_player()->set_casting(mag);
	write("%^MAGENTA%^%^BOLD%^A spell of annihilation rips through "
	      +attackers[i]->query_cap_name()+".");
   	say("%^MAGENTA%^%^BOLD%^"+this_player()->query_cap_name()+
	    "'s spell of annihilation rips through "+
	    attackers[i]->query_cap_name()+".", this_player());
    }
    return 1;
}

void help() {
    write("Syntax: <annihilate>\n\n"+
	"This spell does massive damage to all of your attackers. "
	"It also drains a lot of magic power.\n");
}
