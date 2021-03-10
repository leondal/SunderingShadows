#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;
void create() {
  ::create();
  set_long(::query_long()+"  A ladder leads down to the lower boardwalk "+
     "below, where there seems to be an office of sorts.");
  set_exits(([
    "west":TCITY+"c69",
    "down":TCITY+"dock_taxes2",
  ]));
}
