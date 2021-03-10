// Coded by Bane
// gskeleton.c
#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"skeleton","giant","giant skeleton","undead"}));
    set_name("giant skeleton");
    set_short("A giant Skeleton");
    set_long(
	"This beast stands roughly 12 feet tall and looks to be "+
	"made from the bones of giants.  It is armed with a massive "+
	"spear made from wood and bone.  A magical fire burns in "+
	"its chest, a by-product of the magics that are "+
	"used to make it.  The flames begin above the pelvis "+
	"and reach upward to lick at the collar bones.  Mysteriously "+
	"no burning or scorching occurs where the flames touch the bone."
    );
    set_body_type("human");
    set_race("skeleton");
    set_gender("male");
    set_size(3);
    set_alignment(5);
    set_class("fighter");
    set_mlevel("fighter",7);
    set_hd(6,8);
    set_hp(80);
    set_exp(1200);
    set_overall_ac(1);
    set_property("weapon resistance",1);
    set_property("strength","fire");
    set_property("strength","cold");
    set_property("no death",1);
    set_property("no dominate",1);
    set("aggressive",19);
    set_stats("strength",18);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/ravenloft/obj/bspear")->move(TO);
    command("wield spear");
    set_attack_bonus(5);
    set_funcs(({"fireball"}));
    set_func_chance(102);
}
void fireball(object targ){
    tell_object(targ,"%^BOLD%^RED%^The giant Skeleton reaches into its chest, grabs a ball of flame and throws it at you!");
    tell_room(ETO,"%^BOLD%^RED%^The giant Skeleton reaches into its chest, grabs a ball of flame and throws it at "+targ->query_cap_name()+"!",targ);
    set_func_chance(0);
    call_out("reset_func",250,TO);
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^B_WHITE%^RED%^\nThe ball explodes into you!");
	tell_room(ETO,"%^B_WHITE%^RED%^\nThe ball explodes into "+targ->query_cap_name()+"!",targ);
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(8, 6), "fire");
	return 1;
    }
    tell_room(ETO,"%^RED%^The ball flies off and slams into the ground exploding with a roar!");
    return 1;
}
void reset_func(){set_func_chance(102);}
