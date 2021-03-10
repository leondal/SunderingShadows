#include <std.h>
inherit "/std/armour";
void create(){
::create();
set_name("Amber Ring");
set_id(({"ring","amber ring","amber"}));
set_short("Amber Ring");
set_long(
"%^RESET%^This ring was molded from the finest platinum. "
"An %^YELLOW%^amber stone%^RESET%^ has been set in the ring. "
"A tiny scarab is imprisoned in the amber for all eternity. "
"You see a barely preceptible %^BOLD%^glow%^RESET%^ emanating from the gem." 
);
set_type("clothing");
set_ac(0);
set_weight(1);
set("value",50);
set_limbs(({"right hand","left hand"}));
}
