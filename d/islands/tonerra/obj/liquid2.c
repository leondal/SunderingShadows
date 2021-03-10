#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("%^BLUE%^blue liquid");
   set_short("Vial containing %^BLUE%^blue liquid%^RESET%^");
   set_id(({"liquid2","liquid","blue","blue liquid","vial"}));
   set_long(
@OLI
   This clear blue liquid sparkles before you.  No telling what chemical is in it.
OLI
   );
   set_value(2000);
   set_weight(10);
}
