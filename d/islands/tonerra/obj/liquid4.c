#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("%^BOLD%^%^BLACK%^black liquid");
   set_short("Vial containing %^BOLD%^%^BLACK%^black liquid%^RESET%^");
   set_id(({"liquide","liquid","black liquid","vial"}));
   set_long(
@OLI
   This thick black liquid oozes around before you.  No telling what chemical is in it.
OLI
   );
   set_value(2000);
   set_weight(10);
}
