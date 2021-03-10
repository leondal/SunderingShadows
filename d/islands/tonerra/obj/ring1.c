//ring1.c

#include <std.h>

inherit OBJECT;

void create(){
   ::create();

   set_name("Silver ring of the North");
   set_short("%^BOLD%^Silver ring of the north");
   set_id(({"ring","silver ring","north","ring1"}));
   set_long(
@OLI
   This is the north or top ring in the symbol of Ibrandul.
OLI
   );
   set_weight(3);
   set_value(1);
}
