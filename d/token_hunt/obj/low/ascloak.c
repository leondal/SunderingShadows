#include <std.h>
inherit "/d/common/obj/armour/cloak_hooded.c";

void create(){
	::create();
	set_name("hooded cloak");
	set_id(({"cloak","hooded cloak","velvet cloak"}));
	set_short("%^BOLD%^%^BLACK%^hooded velvet cloak%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This sensuous cloak feels and looks "+
	   "exquisite against the flesh. The weightless folds of the soft "+
	   "velvet accent the curve of the wearer's form. A large black hood "+
	   "can be raised to leave conceal the face in shadows.%^RESET%^");
	set_value(0);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_overallStatus(220);
   set_property("no disenchant",1);
}