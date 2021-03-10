//many thanks to Shar for creating this item :)
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak clasp");
	set_id(({"clasp","cloak clasp","dragon clasp","bronze cloak clasp","bronze clasp"}));
	set_short("%^RESET%^%^RED%^A double headed dragon bronze cloak clasp%^RESET%^");
	set_long(
@AVATAR
%^RED%^This semi-circular cloak clasp is in the shape of a double-headed dragon.  The dragons' heads are turned inwards at the bottom of the clasp, facing each other.  The bronze metal has a weathered finish and in some areas is worn smooth with age.  Decorative geometrical patterns have been carved into the body of the dragons.  A thick bronze pin has been secured to the design, looking as if it might pierce even the bulkiest of fabrics.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(250);
	set_lore(
@AVATAR
Evoking images of nature and strength, the residents of Kildare Glen wear totem items like this for good luck.  This one is suppose to bring vigor and strength to any male who wears it, or so the story goes.  Items such as this are often heirlooms in many of Kildare Glen's families.

AVATAR
	);
      set_property("lore difficulty",5);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}


