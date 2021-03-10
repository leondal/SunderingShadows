#include <std.h>
inherit "/std/armour";
create() {
    ::create();
    set_name("robe");
    set_id(({"robe","black robe"}));
    set_short("%^BLUE%^%^BOLD%^a black robe%^RESET%^");
    set_long(
	"This robe is made of an unknown but clearly high quality material. "
	"It seems to shift in "
	"and out of the light and distort visual properties. You "
	"imagine that it would offer good protection as well as creating "
        "a somewhat concealing shadow over your face with its hood."
    );
    set_weight(1);
    set_value(50);
    set_type("clothing");
    set_limbs(({"torso"}));
//    set_ac(1);
    set_property("enchantment",2);  // changing to 2 since moved underground in Underdark *Styx*  11/16/03, last change 7/19/01
}
