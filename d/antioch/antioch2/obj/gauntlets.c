#include <std.h>
//Updated for armor feats Octothorpe 5/11/09
inherit "/d/common/obj/armour/gauntlets.c";

void create()
{
   ::create();
   set_name("gauntlets");
   set_short("A pair of gauntlets");
   set_id(({"gauntlets","pair of gauntlets"}));
   set_long("These are a pair of steel gauntlets, typically worn by knights."+
   " The inside is padded with cotton so as not to hurt one's hands. They"+
   " have been highly polished and are in good shape.");
   //set_weight(2);
   //set_value(10);
   //set_ac(0);
   //set_type("armor");
   //set_limbs(({"right hand","left hand"}));
   set_size(-1);
   set_wear("%^BOLD%^You slip the steel gauntlets onto your hands.");
   set_remove("You slide your hands out of the steel gauntlets.");
}
