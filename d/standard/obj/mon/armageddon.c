inherit "std/monster";

#include <daemons.h>

void create() {
    ::create();
    set_name("armageddon");
    set_id( ({ "armageddon", "crasher", "game crasher", "armageddon the game crasher" }) );
    set_short("Game crasher Armageddon of Sundering Shadows);
    set_long("He appears once and briefly only to cause doom to the mud.\n");
    set_level(19);
    set_hd(19,0);
    set_stats( "strength", 25);
    set_body_type("human");
}

void init() {
	::init();
	if((int)SHUT_D->query_time_remaining() < 0) {
		this_object()->remove();
	}
}
	
void catch_tell(string str) {
    string who, what, extra;

    if((int)SHUT_D->query_time_remaining() > 180) return;
    if(sscanf(str, "%s %s %s", who, what, extra) != 3) return;
    if(what != "tells") return;
    who = lower_case(who);
    if(!find_living(who)) return;
    find_living(who)->move("/d/standard/supply");
    tell_object(find_living(who), "You are magically teleported
somewhere.\n");
}
