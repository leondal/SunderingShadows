inherit "/std/weapon";

#include "std.h";


create() 
{
  ::create();
  set_id(({"pincer"}));
  set_name("pincer");
  set_short("nasty looking pincers");
  set_long("spiked at one end for easy injecting ");
  set_weight(0);
set_property("monsterweapon",1);
  set_size(1);
  set("value", 0);
  set_wc(0,0);
  set_large_wc(0,0);
  set_type("piercing");
  add_poisoning(5);
}
