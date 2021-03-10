#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;

#define VQCN vic->query_cap_name()

void create() {
    ::create();
    set_name("claw");
    set_id(({"claw","claw of darkness","monster","claws"}));
    set_short("%^BOLD%^%^BLACK%^claw of darkness%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This is a huge claw formed from an inky"+
	" purple-black darkness.  It reaches out "+
	"from a pool of black formed under it.  "+
	"The thing looks terrifying.%^RESET%^");
    set_overall_ac(3);
    set_race("claw");
	set_property("swarm",1);
    set_body_type("hand");
    add_limb("palm","palm",0,0,0);
    add_limb("index claw","index claw",0,0,0);
    add_limb("middle claw","middle claw",0,0,0);
    add_limb("ring claw","ring claw",0,0,0);
    add_limb("pinky claw","pinky claw",0,0,0);
    add_limb("thumb","thumb",0,0,0);
    set_hd(15,8);
    set_max_hp(150);
    set_hp(150);
    set_size(2);
    set_stats("strength",18);
    set_attacks_num(4);
    set_attack_limbs(({"palm","index claw",
	"middle claw","ring claw","pinky claw","thumb"}));
	set_damage(4,8);
	add_attack_bonus(15); //was 10, but couldn't hit alzar
    set_property("no dominate",1);
    set_alignment(9);
	set_base_damage_type("slashing");
    set_emotes(9,({"The claw grasps for you!",
        "The claw tears at you!",}),1);
    set("aggressive",25);
	set_hit_funcs( (["palm": (: TO,"grab_func" :)]) );
	set_new_exp(30,"normal");
    set_max_level(35);
	set_base_damage_type("cold");
}
int grab_func(object vic) {
   if(!"/daemon/saving_throw_d.c"->reflex_save(vic,-30)){
     vic->set_paralyzed(10+random(20),"%^MAGENTA%^The claw holds you fast.");
   tell_object(vic,"%^MAGENTA%^The claw grasps ahold of you as talons sink into your flesh!");
   tell_room(ETO,"%^MAGENTA%^The claw grasps "+VQCN+" with its "+
      "powerful talons!",vic);

   vic->cause_typed_damage(vic,0,roll_dice(5,10),"cold");
   return 1;}
   else return 0;
}
void die(object ob) {
   tell_room(ETO,"%^RED%^The claw shudders and %^BOLD%^%^BLACK%^disappears!");
    TO->remove();
}
