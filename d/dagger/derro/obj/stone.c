//updated to coding standards ~Circe~ 7/30/19

#include <std.h>

inherit "/std/Object";

void create() {
   ::create();
   set_name("stone");
   set_id(({"large stone","stone"}));
   set_short("Large stone");
   set_long("This is a very large stone.");
   set_weight(50);
   set_value(0);
}
