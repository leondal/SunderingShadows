//bulette.c - New mount (grumbar) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("bulette");
   set_vehicle_short("bulette");
   set_short("%^RESET%^%^ORANGE%^a mass%^WHITE%^i%^ORANGE%^ve bu%^WHITE%^l%^ORANGE%^ette%^RESET%^");
   set_id(({"mount","bulette","massive bulette"}));
   set_long("%^BLACK%^%^BOLD%^This armor-plated beast is called a Bulette, often referred to as a landshark. "
"It is just under seven feet tall, and about twelve feet long.  It looks somewhat like a cross between a giant "
"armadillo and a snapping turtle, with an incredibly hard-shelled, crested back.  Its beak-like maw is filled "
"with %^WHITE%^sharp, dagger-sized teeth%^BLACK%^, and it has %^RESET%^%^WHITE%^huge claws%^BLACK%^%^BOLD%^ on "
"all four feet.  Its armor plates are very thick, and of a %^RESET%^%^WHITE%^gray-blue shade%^BLACK%^%^BOLD%^, "
"slightly duller than the %^RESET%^%^ORANGE%^blue-brown hue%^BLACK%^%^BOLD%^ of the rest of its hide.  It is "
"quite a fearsome creature to behold.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_exit_room("leaves riding a massive bulette.");
   add_limb("jaws","head",0,0,0);
   set_attack_limbs(({"right forepaw","left forepaw","jaws"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in stomps in, its great teeth bared.");
   TO->force_me("message out ambles out $D.");
}

void special(object target) {
   tell_room(ETO,"%^ORANGE%^The bulette lets out a grumbling snarl, opening its great maw of dagger-like teeth "
"to bite at "+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^ORANGE%^The bulette lets out a grumbling snarl, opening its great maw of dagger-like "
"teeth to bite at you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
