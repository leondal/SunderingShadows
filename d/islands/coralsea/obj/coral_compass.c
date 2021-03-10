#include <std.h>
inherit OBJECT;

// Coral Sea Area - Created January 2009 by Ari

void create(){
    ::create();
		set_name("brass compass");
        set_id(({"compass","brass compass","cscompriin"}));
        set_short("%^RESET%^%^ORANGE%^a brass compass%^RESET%^");
        set_obvious_short("%^RESET%^%^ORANGE%^a brass compass%^RESET%^");        
		set_long("%^RESET%^%^ORANGE%^Made of brass, this small device "+
			"sits easily within the palm of one's hand.  A %^CYAN%^"+
			"glass cover %^ORANGE%^seals the top and within you can "+
			"see a %^BOLD%^%^BLACK%^sliver of iron %^RESET%^%^ORANGE%^"+
			"floats upon the surface of some type of clear looking "+
			"%^CYAN%^liquid%^ORANGE%^.  Below, painted on the "+
			"interior of the compass is a %^GREEN%^green starburst "+
			"%^ORANGE%^with eight points laid out as a compass rose.  "+
			"No other markings present themselves on the interior, "+
			"but on the exterior there are words etched in a fluid, "+
			"flowery %^GREEN%^script%^ORANGE%^.%^RESET%^");
        set_weight(1);
        set_value(100);
		
		set_lore("As long as men have sailed the seas they have "+
			"found means by which to guide themselves home.  From "+
			"the sun, moon and stars to clever devices such as this "+
			"one, the goal has always been to find ones way back "+
			"to land when all that surrounds you is a horizon to "+
			"horizon view of open water.");
		set_property("lore difficulty",5);
		
		set("read","%^RESET%^%^ORANGE%^Try as you might, you just "+
				"cannot make out the flowery writing on the side "+
				"of the compass.");
}
