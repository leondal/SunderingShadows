#include <std.h>
inherit "/std/armour";
create() {
    ::create();
    set_name("armour");
    set_id(({"armour","mesh","mesh armour"}));
    set_short("%^RESET%^%^BLUE%^Mesh armour%^BOLD%^%^MAGENTA%^");
    set_long(
	" "
	" "
	" "
    );
    set_weight(10);
    set_value(50);
    set_type("armour");
    set_limbs(({"torso"}));
    set_ac(5);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    write(
        " "
        " "
    );
    return 1;
}
int removeit() {
    tell_object(TP,
	" "
	" "
    );
    return 1;
}
