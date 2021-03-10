inherit "std/monster";

#include <daemons.h>

void create() {
    ::create();
    set_name("armageddon");
    set_id( ({ "armageddon", "crasher", "game crasher", "armageddon the game crasher" }) );
    set_short("Game crasher Armageddon of ShadowGate");
    set_long("He appears once and briefly only to cause doom to the mud.\n");
    set_level(15);
    set_hp(10000);
    set_body_type("human");
}

die() {
	say("You KILLED me?!  That makes me MAD!\n");
	this_object()->set_hp(20000);
}

void catch_tell(string str) {
    string who, what, extra;

    if((int)SHUT_D->query_time_remaining() > 180) return;
    if(sscanf(str, "%s %s %s", who, what, extra) != 3) return;
    if(what != "tells") return;
    who = lower_case(who);
    if(!find_living(who)) return;
/*     find_living(who)->move("/d/standard/supply");  */
    tell_object(find_living(who), "No matter what you say, we are still going to reboot.  Have a nice day!\n");
}
