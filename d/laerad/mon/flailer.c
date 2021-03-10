//Updated description and mechanics - Octothorpe 11/7/09
//updated by Circe to be a psion 8/29/05
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"flailer","Flailer","laeradmon","magical beast"}));
    set_name("flailer");
    set_short("%^RESET%^c%^BOLD%^%^BLACK%^a%^RESET%^m%^BOLD%^%^BLACK%^"+
	   "ou%^RESET%^fl%^BOLD%^%^BLACK%^a%^RESET%^g%^BOLD%^%^BLACK%^"+
	   "e%^RESET%^d fl%^BOLD%^%^BLACK%^ai%^RESET%^l%^BOLD%^%^BLACK%^"+
	   "e%^RESET%^r");
    set_long("%^BOLD%^%^BLACK%^This fairly small, tortoise-like "+
	   "creature is about four feet long.  Unlike normal tortoises "+
	   "though, this beast has six legs that are mostly concealed "+
	   "inside its hardened torso.  Its shell is similar looking "+
	   "to the blasted, rocky terrain of the Gods Plains.%^RESET%^");
    set_body_type("quadruped");
    set_race("flailer");
    set_gender("male");
    set_size(1);
    set_hd(15,28);
    set_max_level(22);
    set_hp(200);
    set_attack_bonus(6);
    set_alignment(5);
    set_exp(12500);
    set_class("psion");
    set_mlevel("psion",22);
    set_guild_level("psion",22);
    set_overall_ac(-3);
    set("aggressive",8);
    add_limb("right middle leg","torso", 0, 0, 0);
    add_limb("left middle leg","torso", 0, 0, 0);
    add_limb("shell","torso", 0, 0, 0);
    add_limb("right middle paw","torso", 0, 0, 0);
    add_limb("left middle paw","torso", 0, 0, 0);
    set_attack_limbs(({"right forepaw","left forepaw","head","right middle paw","left middle paw"}));
    set_attacks_num(5);
    set_base_damage_type("slashing");
    set_damage(3,6);
    set_stats("dexterity",12);
//    set_funcs(({"psionic"}));
//    set_func_chance(20);
    set_spell_chance(70);
    set_spells(({"mind thrust","timeless body","ultrablast","id insinuation","energy retort"}));
    set_moving(1);
	set_speed(99);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
}

/*
void psionic(object targ){
     if(!objectp(targ)) return 0;
    if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^MAGENTA%^The Flailer psionically penetrates your mind ravaging your thoughts!");
	tell_room(ETO,"%^BOLD%^MAGENTA%^"+targ->query_cap_name()+" grabs "+targ->query_possessive()+" head and shrieks in pain!",targ);
        set_property("magic",1);
targ->do_damage("torso",roll_dice(2,10));
    remove_property("magic");
	return 1;
	}
    if(!objectp(targ)) return 0;
    tell_object(targ,"%^BOLD%^MAGENTA%^The Flailer attempts to penetrate your mind psionically but you resist!");
    tell_room(ETO,"%^BOLD%^MAGENTA%^"+targ->query_cap_name()+" shakes "+targ->query_possessive()+" head momentarily.",targ);
    return 1;
}
*/
