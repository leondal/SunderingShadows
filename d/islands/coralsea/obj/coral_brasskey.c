#include <std.h>
#include "../defs.h"
inherit OBJECT;

// Coral Sea Area - Created January 2009 by Ari

void create(){
    ::create();
		set_name("brass key");
        set_id(({"key","brass key","cskeyriin"}));
        set_short("%^RESET%^%^ORANGE%^a brass key%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^This small key is made "+
			"of brass and shows signs of oxidation from having been "+
			"under the waves for so long.  Simple in design you can "+
			"see a capitals %^YELLOW%^'C.Q.'%^RESET%^%^ORANGE%^ are "+
			"pressed into the top of the key.%^RESET%^");
        set_weight(1);
        set_value(0);
}