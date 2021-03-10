#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("stone");
  set_id(({"large stone","stone"}));
  set_short("Large stone");
  set_long("This is a very large stone.  It is deep gray in color, "+
     "mottled with black and white, and it is incredibly heavy.");
  set_weight(50);
  set_value(0);
}
