#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
  ::create();
  set_name("kather armor");
  set_short("studded kather armor");
  set_id(({"studded","armor","studded kather armor","kather"}));
  set_long("This tough leather is studded with copper and brass and dyed dark brown.");
  set_value(200);
  set_size(1);
  set_property("enchantment",2);
}
