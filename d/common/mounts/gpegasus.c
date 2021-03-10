//gpegasus.c - New mount (lathander) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_flying_mount.c";

void create(){
   ::create();
   set_name("pegasus");
   set_vehicle_short("pegasus");
   set_short("%^RESET%^%^ORANGE%^a beautiful golden pegasus%^RESET%^");
   set_id(({"mount","pegasus","golden pegasus"}));
   set_race("pegasus");
   set_long("%^ORANGE%^This tall horse is a glorious creature, standing a little over five feet at the "
"shoulder.  It resembles an Arabian stallion, with a proud poise and a muscular build, though it has two large "
"wings of incredibly soft feathers, which when unfolded reach to an impressive span.  Its fur and wings all "
"carry a brilliant %^YELLOW%^golden sheen%^RESET%^%^ORANGE%^, as do the flowing mane and tail that ripple "
"softly with the creature's movements.  Its %^YELLOW%^flawless golden hooves%^RESET%^%^ORANGE%^ traverse the "
"ground effortlessly, as though the horse were lighter than it appears to be, and its intense%^BLUE%^%^BOLD%^ "
"sapp%^CYAN%^h%^BLUE%^ire g%^CYAN%^a%^BLUE%^ze%^RESET%^%^ORANGE%^ reveals its noble spirit and sharp "
"intellect.  This creature is a pegasus, a creature of legend, and a rare sight to behold indeed.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_exit_room("leaves riding a beautiful pegasus.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in trots in with its head held high.");
   TO->force_me("message out trots out $D.");
}

void special(object target) {
   tell_room(ETO,"%^ORANGE%^The pegasus rears up with a flap of its massive wings, and lashes out with both "
"forehooves at "+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^ORANGE%^The pegasus rears up with a flap of its massive wings, and lashes out with "
"both forehooves at you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}