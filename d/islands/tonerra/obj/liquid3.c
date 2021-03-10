#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("%^BOLD%^bubbly liquid");
   set_short("Vial containing %^BOLD%^bubbly liquid%^RESET%^");
   set_id(({"liquide","liquid","bubbly liquid","vial"}));
   set_long(
@OLI
   This clear whitish liquid bubbles all over the place before
   you. No telling what chemical is in it.
OLI
   );
   set_value(2000);
   set_weight(10);
}
