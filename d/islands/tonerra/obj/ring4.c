//ring1.c

#include <std.h>

inherit OBJECT;

void create(){
   ::create();

   set_name("Silver ring of the East");
   set_short("%^BOLD%^Silver ring of the West");
   set_id(({"ring","silver ring","west","ring4"}));
   set_long(
@OLI
   This is the west or left ring in the symbol of Ibrandul.
OLI
   );
   set_weight(3);
   set_value(1);
}
