#include <std.h>
#include "../tormdefs.h"
inherit TANARN;
void create()
  {
  ::create();
  set_long(TO->query_long() + "  The dreaded %^RED%^gallows"+
  "%^RESET%^ are just north of here, nestled between "+
  "the road and the north wall of the city.%^RESET%^");
  set("night long",TO->query("night long") + "  The dreaded "+
  "%^RED%^gallows%^RESET%^ are just north of here, nestled between "+
  "the road and the north wall of the city.  A much thicker "+
  "blanket of fog hangs heavily over them.%^RESET%^");
  set_exits(([
  "north":TCITY+"gallows",
  "east":TCITY+"c6",
  "west":TCITY+"c4",
  ]));
}
