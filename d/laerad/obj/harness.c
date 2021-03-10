//Octothorpe (8/25/09)
//Laerad, Thri-Kreen Harness

#include <std.h>
inherit PARMOUR;

void create(){
   ::create();
   set_id(({"leather harness","harness"}));
   set_name("leather harness");
   set_short("%^RESET%^%^ORANGE%^A weathered leather harness%^RESET%^");
   set_long("%^ORANGE%^This harness is nothing more than a collection "+
      "of weathered, leather straps.  The straps are looped together "+
	  "over a person's chest, causing the straps to cross over the "+
	  "torso in a star pattern.  The harness appears to be quite "+
	  "sturdy, and looks capable of supporting quite a few trinkets "+
	  "in it.%^RESET%^");
   set_value(250);
   set_weight(10);
   set_size(2);
   set_max_internal_encumbrance(15);
   set_limbs(({"torso"}));
   set_type("clothing");
}
