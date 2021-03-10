#include <std.h>
#include "../farm.h"
inherit "/d/antioch/antioch2/obj/old_pipe.c";

void create()
{
        ::create();
      set_name("hildegard's pipe");
     	set_id(({"pipe","A pipe","brass pipe","a pipe","hildegard's pipe"}));
	set_short("%^BOLD%^%^YELLOW%^A brass pipe%^RESET%^");
      set_long("%^YELLOW%^Crafted to look like a dragon in flight "+
		"this brass pipe looks quite expensive.  The long skinny"+
		" pipe is highly detailed in its carving.  The mouthpiece"+
		" of the pipe form the dragon's tail, while the mouth houses"+
		" the well for tobacco.  Miniature scales and wings are carved"+
		" into the brass giving it an almost life like appearance.  "+
		"Two small %^RED%^garnet%^YELLOW%^ are set into the dragon's eyes.\n");
	set_lore("The Flaming Dragon Pipe is a favored item of the bandit"+
		" den mother Hildegard.  The halfling woman is tough as a nail,"+
		"  setting out to lead the chaotic troupe of bandits that"+
		" plagued people around Tabor.  In an attempt to rob the Tabor "+
		"bank, Hildegard lost her right arm when the crossbow she was "+
		"wielding exploded.  Since then the irate woman has only"+
		" gotten grumpier and meaner to the world.  Her boys, the men she"+
		" leads, are loyal to Mother Hildegard, as they refer to her.");
	set_property("lore",7);
}
