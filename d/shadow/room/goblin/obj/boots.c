#include <std.h>
inherit "/std/armour";
create() {
    ::create();
    set_name("boot");
    set_id(({"boots","boot","goblin boots"}));
    set_short("Goblin Boots of Speed");
    set_long(
	"This is a sparkling pair of leather goblin boots. "
	"You feel dizzy looking at them. A magical aura surrounds the boots."
    );
    set_weight(2);
    set_value(15);
    set_type("clothing");
    set_limbs(({"left foot","right foot"}));
    set_ac(0);
    set_size(1);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    set_item_bonus("dexterity",1);
}
int wearit() {
    tell_object(ETO,"%^BOLD%^%^RED%^You slip on the boots and feel faster!%^RESET%^");
    return 1;
}
int removeit() {
    tell_object(ETO,"%^BOLD%^%^RED%^You remove the boots and begin to slow down.%^RESET%^");
    return 1;
}
