//salmander.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("salamander");
   set_id(({"salamander","Salamander","Fiery Salamander"}));
   set_short("Fiery Salamander");
   set_long(
@OLI
The heat from this creature itself scorches your face and
hands. The long snakelike body is barbed with glowing red
spikes and the scales glow with the creature's heat.
OLI
   );
   set_race("salamander");
   set_body_type("snake");
   add_limb("left claw","left hand",0,0,0);
   add_limb("right claw","right hand",0,0,0);
   remove_limb("mouth");
   set_gender("male");
   set_hd(14,1);
   set_hp(150);
   set_exp(1);
   set_overall_ac(-1);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right claw","left claw"}));
   set_damage(2,12);
   set_attacks_num(2);
}

