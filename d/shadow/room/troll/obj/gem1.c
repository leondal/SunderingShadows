#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("diamond");
    set_id(({"gem","jewel","large diamond"}));
    set_short("%^BOLD%^%^WHITE%^"
	"Large Diamond"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^WHITE%^"
	"The large diamond is a excellent rough specimen. It is "
	"likely quite valuable even in its rough state, and priceless "
	"when finished by a gem cutter. You marvel at its beauty and "
	"are torn between keeping it for your own collection, or selling it "
	"for the unfinished gold value."
        "%^RESET%^"
    );
    set_weight(1);
    set_value(375);

}
void save_me(string file) { return 1; }			
