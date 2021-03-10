#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("Amber Ring");
   set_id(({"ring","amber ring","amber"}));
   set_short("Amber Ring");
   set_long("This ring was molded from the finest platinum.  An %^YELLOW%^amber stone%^RESET%^ has been set "
"in the ring.  A tiny scarab is imprisoned in the amber for all eternity.  You see a barely preceptible "
"%^BOLD%^glow%^RESET%^ emanating from the gem.  From the delicate crafting and the quality of the stone, "
"the ring would obviously be worth quite a large sum.");
   set_type("ring");
   set_ac(0);
   set_weight(1);
   set_value(2000);
   set_limbs(({"right hand","left hand"}));
}
