#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("ruby");
    set_id(({"gem","jewel"}));
    set_short("%^BOLD%^%^RED%^"
	"Ruby"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^RED%^"
	"The ruby is a excellent rough specimen of a regular size. "
	"It is "
	"likely valuable even in its rough state, and exceptional "
	"when finished by a gem cutter. You like the unfinished look and "
	"are torn between keeping it for your own collection, or selling it "
	"for the unfinished gold value."
        "%^RESET%^"
    );
    set_weight(1);
    set_value(175);

}
void save_me(string file) { return 1; }			
