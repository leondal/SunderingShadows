#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("red stone");
   set_id(({"stone","red stone"}));
   set_short("%^BOLD%^%^RED%^A red stone%^RESET%^");
   set_long(
      "This is a red stone with a symbol painted onto it."
   );
   set_weight(1);
   set("value",0);
}