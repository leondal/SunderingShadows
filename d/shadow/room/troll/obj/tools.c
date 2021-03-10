#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("tools");
    set_id(({"mining tools"}));
    set_short("%^BOLD%^%^WHITE%^"
	"Mining Tools"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^WHITE%^"
	"This is an excellent set of mining tools useful for extracting "
	"minerals, gems and other buried treasures from within mountains "
	"and mining areas. They will provide excellent success rates and ease "
	" of use to those wise enough to utilize them."
        "%^RESET%^"
    );
    set_weight(4);
    set_value(20);

}
	
