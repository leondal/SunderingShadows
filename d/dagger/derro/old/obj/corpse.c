#include <std.h>
#include "../derrodefs.h";
inherit "/std/bag_logic";
void create(){
  ::create();
  set_id(({"corpse","melting corpse"}));
  set_short("Melting corpse");
  set_long("  The massive corpse of the lava para-elemental melts quickly back into lava!");
  set_weight(100000);
  set_property("no animate",1);
  set_value(1);
  new(OBJ"emerald.c")->move(TO);
  set_max_internal_encumbrance(30);
}
