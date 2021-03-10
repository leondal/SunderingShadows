//ring1.c

#include <std.h>

inherit OBJECT;

void create(){
   ::create();

   set_name("Silver ring of the East");
   set_short("%^BOLD%^Silver ring of the East");
   set_id(({"ring","silver ring","east","ring3"}));
   set_long(
@OLI
   This is the east or right ring in the symbol of Ibrandul.
OLI
   );
   set_weight(3);
   set_value(1);
}
