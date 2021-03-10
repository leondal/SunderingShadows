#include <std.h>
inherit WEAPON;
void create(){
  ::create();
  set_id(({"bar","pry bar","prybar"}));
  set_name("prybar");
  set_short("metal bar");
   set_long("  It's a metal bar about 3 feet long that's bent to an angle on one end and flattened on the other.  Looks like it could be useful somewhere.");
  set_weight(5);
  set_size(2);
  set_value(1);
  set_wc(3,3);
  set_large_wc(3,3);
  set_type("bludgeoning");
}
