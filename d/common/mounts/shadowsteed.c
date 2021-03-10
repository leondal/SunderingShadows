//shadowsteed.c - New mount (shar) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_flying_mount.c";

void create(){
   ::create();
   set_name("stallion");
   set_vehicle_short("shadow stallion");
   set_short("%^BLACK%^%^BOLD%^a shadowy black stallion%^RESET%^");
   set_id(({"mount","stallion","black stallion"}));
   set_race("stallion");
   set_long("%^BLACK%^%^BOLD%^This powerful steed has the build and poise of a trained warhorse, though it is "
"strangely insubstancial.  Its dark-furred body is a midnight shade of black, and its mane and tail resemble "
"whisps of shadow as they shift slightly with the creatures movements.  Its hooves resemble darkest obsidian, "
"so black that they seem to drink in the light around them, as they pass soundlessly over the ground.  Its "
"eyes are a striking shade of %^RESET%^%^MAGENTA%^deep violet%^BLACK%^%^BOLD%^, that carry an intense, "
"malignant gaze.  This horse seems to be made of the stuff of shadows, and gives you an uneasy feeling just to "
"watch it.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_exit_room("leaves riding a shadowy stallion.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in trots in, its shadowy hooves moving soundlessly over the ground.");
   TO->force_me("message out trots out $D.");
}

void special(object target) {
   tell_room(ETO,"%^BLACK%^%^BOLD%^The shadowy stallion rears up and lashes out with both forehooves at "
+target->QCN+", which pass straight through "+target->QO+"!%^RESET%^",target);
   tell_object(target,"%^BLACK%^%^BOLD%^The shadowy stallion rears up and lashes out with both forehooves at "
"you, which pass straight through you with a deathly chill!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}