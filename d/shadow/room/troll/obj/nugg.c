#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("nugget");
    set_id(({"gold nugget"}));
    set_short("%^BOLD%^%^YELLOW%^"
	"Gold Nugget"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^YELLOW%^"
	"A nice size chunk of gold that should fetch a few coins "
	"in your pocket or trade for some simple weapons or armor in "
	"the common marketplace. It would also be a quick ticket to "
	"a hot meal, ale and bed for the night in a local inn."
        "%^RESET%^"
    );
    set_weight(2);
    set_value(50);

}
void save_me(string file) { return 1; }			
