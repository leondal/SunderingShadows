#include <std.h>

inherit "/std/Object";

void create() {
  ::create();
  set_name("stone");
  set_id(({"large stone","stone"}));
  set("short","Large stone");
  set("long","This is a very large stone.");
  set_weight(50);
  set_value(0);
}
