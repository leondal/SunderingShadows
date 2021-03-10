#include <std.h>
inherit "/std/armour";
create() {
    ::create();
    set_name("bracelet");
    set_id(({"bracelet","golden bracelet"}));
    set_short("%^YELLOW%^Golden bracelet%^RESET%^");
    set_long(
	"%^YELLOW%^This is small golden bracelet that can be worn on the "
	"wrist most likely as a decoration or as a status "
	"symbol.%^RESET%^"
    );
   set_weight(1);
    set_value(700);
    set_type("clothing");
    set_limbs(({"right arm","left arm"}));
    set_ac(0);
}
