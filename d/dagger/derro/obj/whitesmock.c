//changed to a common inherit and cleaned up code ~Circe~ 7/30/19

#include <std.h>
inherit "/d/common/obj/clothing/shirt.c";

void create(){
   ::create();
   set_name("smock");
   set_id(({"smock","white smock","chefs smock","white chefs smock","robe"}));
   set_short("White smock");
   set_long("This loose-fitting overcoat is gleaming white with two sets of buttons running down the front.  Dirt and filth (and blood) seem to slide off it as if in a hurry to be away from its surface.");
   set_value(50);
   set_property("enchantment",2);
}
