#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("diamond");
    set_id(({"gem","jewel"}));
    set_short("%^BOLD%^%^WHITE%^"
	"Diamond"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^WHITE%^"
	"The diamond is a excellent rough specimen of a regular size. "
	"It is "
	"likely valuable even in its rough state, and exceptional "
	"when finished by a gem cutter. You like the unfinished look and "
	"are torn between keeping it for your own collection, or selling it "
	"for the unfinished gold value."
        "%^RESET%^"
    );
    set_weight(1);
    set_value(200);

}
void save_me(string file) { return 1; }			
