#include <std.h>
inherit "/std/armour";

void create(){
  ::create();
  set_name("steel helm");
  set_short("%^RESET%^%^CYAN%^Polished steel helm%^RESET%^");
  set("id",({"polished steel helm","helmet","helm","steel helm"}));
   set_long("This great helm is polished to a high shine but only seems to reflect the dancing images of flames in any light.");
set_weight(5);
  set_type("helm");
  set("value",100);
  set_limbs(({"head"}));
  set_ac(1);
  set_size(3);
set_property("enchantment",1 + random(2));
}
