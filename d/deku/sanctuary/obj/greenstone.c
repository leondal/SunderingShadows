#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("green stone");
   set_id(({"stone","green stone"}));
   set_short("%^BOLD%^%^GREEN%^A green stone%^RESET%^");
   set_long(
      "This is a green stone with a symbol painted onto it."
   );
   set_weight(1);
   set("value",0);
}