//Portal coded by Bane for use with the Hordlings//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"portal","Portal","dark portal","Dark Portal"}));
    set_name("Dark Portal");
    set_short("The Dark Portal");
    set_long("A massive 20 foot portal made from onyx.");
    set_body_type("snake");
    set_race("portal");
    set_size(3);
    set_hd(300,100);
    set_hp(2500);
    set_overall_ac(0);
    set_exp(0);
    remove_limb("mouth");
    remove_limb("head");
    remove_limb("tail");
    remove_limb("torso");
    add_limb("pillar","FATAL",0,0,0);
    set("aggressive",0);
    set_emotes(15,({"The portal moans as if alive.","The portal seems to shift its form."}),0);
}
void heart_beat(){
    ::heart_beat();
    if(random(100) < 10){
	tell_room(ETO,"A Hordling jumps out from the portal.");
	new("/d/shadow/invasion/hordling")->move(ETP);
	return 1;
    }
}
