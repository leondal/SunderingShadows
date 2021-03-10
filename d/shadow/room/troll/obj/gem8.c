#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("sapphire");
    set_id(({"gem","jewel"}));
    set_short("%^BOLD%^%^BLUE%^"
	"Sapphire"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^BLUE%^"
	"The sapphire is a excellent rough specimen of a regular size. "
	"It is "
	"likely valuable even in its rough state, and exceptional "
	"when finished by a gem cutter. You like the unfinished look and "
	"are torn between keeping it for your own collection, or selling it "
	"for the unfinished gold value."
        "%^RESET%^"
    );
    set_weight(1);
    set_value(125);

}
void save_me(string file) { return 1; }			
