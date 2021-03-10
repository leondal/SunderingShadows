#include <std.h>
//Updated for armor feats Octothorpe 5/11/09
inherit "/d/common/obj/armour/helm.c";

void create()
{
	::create();
	set_name("silvered helm");
	set_short("%^BOLD%^%^WHITE%^Silvered Helm%^RESET%^");
	set_id(({"helm","helmet","silver helm","silvered helm"}));
	set_long(
	"%^RESET%^This helm has been polished and dusted with a %^BOLD%^silver%^RESET%^ powder"+
	" to give it a pretty silver shine. A ridge runs back down the center"+
	" of the helm, helping to deflect blows to the head. The image of a"+
	" beautiful pegasus has been etched onto the front surface of the helm,"+
	" this is the symbol of the guards of Antioch."
	);
	set_value(20);
        set_size(-1);
        //set_type("armour");
        //set_limbs(({"head"}));
        //set_ac(1);
        //set_weight(10);
	if(!random(5)) {
        set("no curse",1);
        set_property("enchantment",1);
	}
}
