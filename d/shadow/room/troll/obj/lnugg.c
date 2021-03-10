#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("nugget");
    set_id(({"gold nugget","large nugget","large gold nugget"}));
    set_short("%^BOLD%^%^YELLOW%^"
	"Large Gold Nugget"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^YELLOW%^"
	"A huge chunk of gold that should fetch a plentitude of coins "
	"in your pocket or trade for some shiny weapons or strong armor in "
	"the common marketplace. It would also be a quick ticket to "
	"a horse, dog or cow for your retirement farmhouse."
        "%^RESET%^"
    );
    set_weight(2);
    set_value(80);

}
void save_me(string file) { return 1; }			
