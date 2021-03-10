//griffon.c - New mount (helm) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_flying_mount.c";

void create(){
   ::create();
   set_name("griffon");
   set_vehicle_short("griffon");
   set_short("%^RESET%^%^ORANGE%^a regal golden griffon%^RESET%^");
   set_id(({"mount","griffon","golden griffon"}));
   set_race("griffon");
   set_long("%^ORANGE%^This magnificent creature has the forequarters of an eagle, and the hindquarters of a "
"lion.  Standing at about six feet at the shoulder, it has an impressive wingspan of nearly twenty-five feet "
"when fully stretched.  Its sharp %^YELLOW%^amber eyes %^RESET%^%^ORANGE%^reveal a predator's intense gaze and "
"alertness.  Deep brown feathers cover its wings, chest and forelegs, which end in %^WHITE%^wickedly sharp "
"talons%^ORANGE%^.  From its midsection flows a coat of dusky tan fur, beneath which are visible great "
"rippling leonine muscles, extending to clawed paws and a lion's tail.  This creature of myth and legend could "
"only be a griffon, and is probably quite dangerous to approach by anyone but its owner.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_exit_room("leaves riding a regal griffon.");
   add_limb("beak","head",0,0,0);
   set_attack_limbs(({"beak","right forepaw","left forepaw"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in treads in, its talons clicking on the ground.");
   TO->force_me("message out treads out $D.");
}

void special(object target) {
   tell_room(ETO,"%^ORANGE%^The griffon rears up with a flap of its massive wings, lashing out at "
+target->QCN+" with its beak and talons!%^RESET%^",target);
   tell_object(target,"%^ORANGE%^The griffon rears up with a flap of its massive wings, lashing out at you "
"with its beak and talons!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}