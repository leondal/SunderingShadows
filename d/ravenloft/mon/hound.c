// Coded by Bane
// hound.c
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"hound","hell","hell hound"}));
    set_name("hell hound");
    set_short("A hell hound");
    set_long(
	"This creature resembles a large hound with "+
	"rust-red fur and red, glowing eyes.  The markings, "+
	"teeth, and tongue are soot black.  It stands about "+
	"three feet high at the shoulder, and has a distinct "+
	"odor of smoke and sulfur."
    );
    set_body_type("quadruped");
    set_race("hell hound");
    set_gender("male");
    set_size(2);
    set_alignment(7);
    set_class("fighter");
    set_mlevel("fighter",9);
    set_hd(random(5)+4,1);
    set_hp(query_hd()*12);
    set_exp(query_hd()*150);
    set_overall_ac(2);
    set_property("strength","fire");
    set("aggressive",random(8)+11);
    set_stats("strength",16);
    set_attack_limbs(({"head"}));
    set_base_damage_type("slashing");
    set_attacks_num(1);
    set_damage(1,10);
    set_attack_bonus(5);
    set_funcs(({"flame"}));
    set_func_chance(102);
}
void flame(object targ){
    if(!SAVING_D->saving_throw(targ,"breath_weapon")){
	tell_object(targ,"%^RED%^The hell hound breathes a cone of flame burning you badly!");
	tell_room(ETO,"%^RED%^The hell hound breathes a cone of flame burning "+targ->query_cap_name()+" badly!",targ);
    targ->cause_typed_damage(targ, targ->return_target_limb(), query_hd(), "fire");
	set_func_chance(0);
	execute_attack();
	set_func_chance(102);
	return 1;
    }
    tell_object(targ,"%^RED%^The hell hound breathes a cone of flame at you but misses!");
    tell_room(ETO,"%^RED%^The hell hound breathes a cone of flame at "+targ->query_cap_name()+" but misses!",targ);
    set_func_chance(0);
    execute_attack();
    set_func_chance(102);
    return 1;
}
