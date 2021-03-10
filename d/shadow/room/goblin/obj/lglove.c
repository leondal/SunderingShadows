#include <std.h>
inherit "/std/armour";
create() {
    ::create();
    set_name("glove");
    set_id(({"glove","left glove","goblin glove","left goblin glove"}));
    set_short("a left goblin glove");
    set_long(
	"This is a dirty, smelly leather goblin glove worn on the left hand. "
	"Goblins are obviously crude creatures to wear such dirty and smelly gear."
    );
    set_weight(1);
    set_value(1);
    set_type("clothing");
    set_limbs(({"left arm"}));
    set_ac(0);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    write(
        "You slip on the left glove."
    );
    return 1;
}
int removeit() {
    write(
	"You remove the left glove."
    );
    return 1;
}
