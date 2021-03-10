#include <std.h>
#include "../dragon.h";

inherit OBJECT;

void create() {
   ::create();
   set_name("paper");
   set_id(({"paper"}));
   set_short("%^RESET%^%^GREEN%^A sheet of paper%^RESET%^");
   set_value(0);
   set_weight(0);
   set_long(
   "%^RESET%^%^YELLOW%^You look over the paper and read:\n"+
   "%^BOLD%^%^RED%^The Monolith project is running well. We have"+
   " recently taken Sanctuary with relative ease. It appears the town"+
   " was recovering from an attack made by a dragon not long ago. We"+
   " did not see the need to use real force on a town that could not fight"+
   " back. Instead, we unleashed some of our test constructs free on the city"+
   " to see how they would preform in battle and then followed this up by using"+
   " apprentice necromancers to let the dead tear the survivors apart. We were"+
   " able to recover many of the bodies for testing and have turned out a number"+
   " of exceptional undead warriors to use in the upcoming war against Illskin."+
   " We have also successfully collected enough souls after our invasion of"+
   " Sanctuary and placed them into the large malachite that"+
   " Malverin sent us. We have sent the stone back and only await its return,"+
   " after the appropiate enchantments are laid upon the stone, so that we may"+
   " take part in the six point summoning for the project, Monolith."
   );
}
