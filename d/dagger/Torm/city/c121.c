#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_long(
  "  This is a smaller pool than the main bathing area."
    "  A definite chill runs through this room from the heat and steam of the rest of the place."
  );
  add_items("pool","This small marble lined pool looks crystal clear and very cold.");
  set_exits(([
  "north":TCITY+"c113",
  ]));
}
