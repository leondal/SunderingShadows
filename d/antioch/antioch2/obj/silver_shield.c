#include <std.h>
//Updated for armor feats Octothorpe 5/11/09
inherit "/d/common/obj/armour/shield.c";

void create()
{
	::create();
	set_name("silver shield");
	set_short("%^BOLD%^%^WHITE%^Silver Shield%^RESET%^");
	set_id(({"shield","silver shield","Silver Shield"}));
	set_long(
	"This is a shield that has been highly polished with silver dust to give"+
	" it a silver sheen. Engraved into the center of the shield is the"+
	" image of a pegasus with spread wings, a sign of the Antioch guard."
	);
        //set_weight(15);
   set_value(50);
        //set_type("shield");
        //set_limbs(({"right hand"}));
        //set_ac(1);
	if(!random(5)) {
     set("no curse",1);
		set_property("enchantment",1);
	}
}
