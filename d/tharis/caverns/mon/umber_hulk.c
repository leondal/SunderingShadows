#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"umber hulk","hulk"}));
    set_short("An Umber hulk");
    set_name("An Umber hulk");
    set_long(
	"This monster stands over 8 feet tall and is about 5 feet wide. "+
	"Muscles bulge underneath its thick scaly skin. Its monsterous head "+
	"is very strange, it has 4 eyes upon its forehead and it has two "+
	"very large mandibles protruding from the side of its mouth."
    );
    set_body_type("human");
    set_race("umber hulk");
    set_gender("male");
    set_size(2);
    set_hd(8,8);
    set_hp(80);
    set_exp(900);
    set_overall_ac(2);
    set("aggressive",16);
    set_class("fighter");
    set_guild_level("fighter",10);
    add_money("gold",random(50));
    remove_limb("right hand");
    remove_limb("left hand");
    add_limb("teeth","head",0,0,0);
    add_limb("right claw","right arm",0,0,0);
    add_limb("left claw","left arm",0,0,0);
    set_attack_limbs(({"right claw","left claw","teeth"}));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(3,4);
    set_funcs(({"gaze"}));
    set_func_chance(30);
}
void gaze(object targ){
    tell_object(targ,"%^BOLD%^BLUE%^The Umber Hulk gazes into your eyes!");
    tell_room(ETO,"%^BOLD%^BLUE%^The Umber Hulk gazes into "+targ->query_cap_name()+"'s eyes!",targ);
    if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^You are confused by the Umber Hulk's gaze!");
	tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" looks confused.",targ);
	targ->set_paralyzed(40,"You stand confused.");
	return 1;
	} else {
	tell_object(targ,"%^BOLD%^You turn your head from the Umber Hulk's gaze!");
	tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" turns his head from the Umber Hulk's gaze!",targ);
	return 1;
    }
}
