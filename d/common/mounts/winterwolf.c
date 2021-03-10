//winterwolf.c - New mount (auril) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("winter wolf");
   set_vehicle_short("winter wolf");
   set_short("%^WHITE%^%^BOLD%^a fierce winter wolf%^RESET%^");
   set_id(({"mount","wolf","winter wolf"}));
   set_race("winter wolf");
   set_long("%^WHITE%^%^BOLD%^This massive wolf is as large as a pony, more than five feet tall at its "
"shoulder.  Its %^CYAN%^icy blue %^WHITE%^eyes betray a keen intelligence and a noble spirit, and its powerful "
"form carries the reflexes and skill of a predator.  Its coat is of stunning %^RESET%^%^WHITE%^silver-white "
"fur%^BOLD%^, from the tip of its nose to its thick tail.  Its paws carry it easily across the ground with a "
"measured pace, and its mighty jaws contain many %^RESET%^%^WHITE%^long, sharp fangs%^BOLD%^.  This is "
"obviously no ordinary wolf, just to look at the fierce creature leaves a heavy feeling upon you.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_exit_room("leaves riding a fierce wolf.");
   set_attack_limbs(({"jaws","right forepaw","left forepaw"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in stalks in with a measured gait.");
   TO->force_me("message out stalks out $D.");
}

void special(object target) {
   tell_room(ETO,"%^WHITE%^%^BOLD%^The massive wolf howls, and unleashes a breath of freezing-cold air at "
+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^WHITE%^%^BOLD%^The massive wolf howls, and unleashes a breath of freezing-cold air at "
"you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
