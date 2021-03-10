#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("sapphire");
    set_id(({"gem","jewel","large sapphire"}));
    set_short("%^BOLD%^%^BLUE%^"
	"Large Sapphire"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^RED%^"
	"The large sapphire is a excellent rough specimen. It is "
	"likely quite valuable even in its rough state, and priceless "
	"when finished by a gem cutter. You marvel at its beauty and "
	"are torn between keeping it for your own collection, or selling it "
	"for the unfinished gold value."
        "%^RESET%^"
    );
    set_weight(1);
    set_value(250);

}
void save_me(string file) { return 1; }			
