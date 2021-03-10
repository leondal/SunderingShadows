//dex.c

#include <std.h>

inherit OBJECT;

void create(){
    ::create();

    set_name("%^YELLOW%^A yellow crystal");
    set_short("%^YELLOW%^A yellow crystal");
    set_id(({"dexterity","crystal","yellow crystal","dexterity crystal"}));
    set_long(
@OLI
   %^YELLOW%^This yellow crystal has a bright interior light.
The light %^RESET%^%^ORANGE%^darts%^YELLOW%^ around quickly. Dancing, running, and flickering,
the light entrances you.%^RESET%^
OLI
   );

   set_value(3000);
   set_weight(10);
}

