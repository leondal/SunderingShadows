//graywolf.c - New mount (tyr) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("wolf");
   set_vehicle_short("gray wolf");
   set_short("%^BLACK%^%^BOLD%^a great gray wolf%^RESET%^");
   set_id(({"mount","wolf","gray wolf"}));
   set_race("wolf");
   set_long("%^BLACK%^%^BOLD%^This great wolf is of an impossible size for any normal canine, more than five "
"feet tall at its shoulder.  Its jet-black eyes betray a keen intelligence and a noble spirit, and its "
"powerful form carries the reflexes and skill of a predator.  Its coat is of %^RESET%^%^WHITE%^granite-gray "
"fur%^BLACK%^%^BOLD%^, from the tip of its nose to its thick tail.  Its paws carry it easily across the ground "
"with a measured pace, and its mighty jaws contain many %^WHITE%^long, sharp fangs%^BLACK%^.  This is "
"obviously no ordinary wolf, just to look at the creature leaves a heavy feeling upon you.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_exit_room("leaves riding a great wolf.");
   add_limb("jaws","head",0,0,0);
   set_attack_limbs(({"jaws","right forepaw","left forepaw"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in stalks in with a measured gait.");
   TO->force_me("message out stalks out $D.");
}

void special(object target) {
   tell_room(ETO,"%^BLACK%^%^BOLD%^The great wolf snarls and leaps forward, snapping at "+target->QCN+" with "
"its mighty jaws!%^RESET%^",target);
   tell_object(target,"%^BLACK%^%^BOLD%^The great wolf snarls and leaps forward, snapping at you with its "
"mighty jaws!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
