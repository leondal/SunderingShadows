#include <std.h>
inherit "/std/armour";
create() {
    ::create();
    set_name("glove");
    set_id(({"glove","right glove","goblin glove","right goblin glove"}));
    set_short("a right goblin glove");
    set_long(
	"This is a dirty, smelly leather goblin glove worn on the right hand. "
	"Goblins are obviously crude creatures to wear such dirty and smelly gear."
    );
    set_weight(1);
    set_value(1);
    set_type("clothing");
    set_limbs(({"right arm"}));
    set_ac(0);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    write(
        "You slip on the right glove."
    );
    return 1;
}
int removeit() {
    write(
	"You remove the right glove."
    );
    return 1;
}
