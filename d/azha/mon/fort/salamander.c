// Fiery Salamander
// salmander.c

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
   add_limb("left hand","left hand",0,0,0);
   add_limb("right hand","right hand",0,0,0);
   set_gender("male");
   set_hd(14,1);
   set_hp(150);
   set_exp(2000);
   set_overall_ac(-1);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right hand","left hand"}));
   set_damage(2,12);
   set_attacks_num(2);
}

void do_hits(object targ, object current, string target_thing) {
	::do_hits();
	tell_object(current,
      "%^YELLOW%^BOLD%^As you hit the salamander, you are burned by the intense heat!%^RESET%^"
	);
	tell_room(environment(current),
      "%^YELLOW%^BOLD%^As "+current->query_cap_name()+" hits the salamander, they are burned by the intense heat!%^RESET%^",
	({ current }));
	targ->cause_typed_damage(targ, "torso", roll_dice(1, 8), "fire");
}
