//unicorn.c - New mount (selune) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("unicorn");
   set_vehicle_short("unicorn");
   set_short("%^WHITE%^%^BOLD%^a magnificent white unicorn%^RESET%^");
   set_id(({"mount","unicorn","white unicorn"}));
   set_race("unicorn");
   set_long("%^WHITE%^%^BOLD%^A mystical aura radiates from this beautiful creature.  The magnificent steed "
"has a gleaming coat of %^RESET%^%^WHITE%^pristine white hair%^BOLD%^, with intelligent eyes of "
"%^RESET%^%^BLUE%^deep%^CYAN%^e%^BLUE%^st sea b%^CYAN%^l%^BLUE%^ue%^WHITE%^%^BOLD%^.  A single ivory horn "
"extends from its brow, almost two feet long, and strands of its silky white mane fall around it, and down the "
"creature's muscular neck.  Powerful muscles ripple beneath its hide, down to the flowing white tail, and the "
"cloven hooves of smooth %^RESET%^%^WHITE%^yellow-ivory%^BOLD%^.  This creature is the substance of legend, a "
"breathtaking sight to behold.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_exit_room("leaves riding a magnificent unicorn.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in trots in with its head held high.");
   TO->force_me("message out trots out $D.");
}

void special(object target) {
   tell_room(ETO,"%^WHITE%^%^BOLD%^The unicorn lowers its head and charges forward, slashing at "
+target->QCN+" with its horn!%^RESET%^",target);
   tell_object(target,"%^WHITE%^%^BOLD%^The unicorn lowers its head and charges forward, slashing at you with "
"its horn!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
