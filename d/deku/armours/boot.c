#include <std.h>

inherit "/std/armour";

void create() {
  ::create();
   set_id(({"boots","soft boots","high boots","tall boots","high soft boots"}));
  set_name("boots");
  set("short","High soft boots");
   set_long("These are a pair of high, soft boots that are made out of leather. They're very comfortable.");
  set_type("clothing");
  set_limbs("feet");
  set_value(5);
  set_cointype("silver");
}
