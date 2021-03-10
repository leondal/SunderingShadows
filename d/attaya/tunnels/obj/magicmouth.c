// Magic mouth template

#include <std.h>

inherit "/std/Object";
int say(string str);


void create() {
  ::create();
  set_name("magicmouth");
  set_id(({"mouth","magic mouth"}));
  set_short("%^RESET%^A magic mouth that has appeared in the wall%^BOLD%^"
+"%^MAGENTA%^");
  set_long(
  "%^BOLD%^%^BLACK%^A huge pair of %^RESET%^stone lips %^BOLD%^BLACK%^,"
+" fully four feet across, have appeared in the wall. They move slightly"
+" and appear to be alive. Occasionally, glimpses of%^BOLD%^%^WHITE%^"
+" bone white teeth%^BOLD%^%^BLACK%^ can be seen peeking out between"
+" them."
  );
  set_weight(1000);
  set_property("no animate",1);
  set_value(0);
}


void init() {
  ::init();
}


