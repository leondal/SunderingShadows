#include <std.h>
inherit ARMOUR;

create() {
    ::create();
set_id(({"necklace","gold necklace"}));
set_name("gold necklace");
set_short("A lovely gold necklace");
set_long(
@GILG
%^YELLOW%^It's a lovely solid 24 carat Gold link necklace.%^RESET%^
%^BOLD%^It has a small wyvern's tooth hanging from it.
GILG
);
set_limbs(({"neck"}));
set_type("clothing");
// leave clothing until balance issues are addressed for jewelry *Styx*  10/13/02
set_ac(0);
set_value(200);
set_weight(5);
set_property("enchantment", 1);
set_wear((:TO,"to_wear":));
}

int to_wear(){
        if((int)TP->query_level() < 5){
        write("You're too inexperienced to use this equipment!");
        return 0;
        }
        return 1;
}
