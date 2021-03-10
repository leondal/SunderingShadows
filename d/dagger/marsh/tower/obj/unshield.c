#include <std.h>
inherit "/std/armour";
inherit "/d/common/obj/armour/shield.c";

void create() {
    ::create();
    set_name("shield");
    set("id", ({ "shield","shield of the order" }) );
    set("short", "Shield of Death");
    set("long", "This is a decorative shield used "
	"by members of the Black Order of Paladins.");
    set_weight(10);
    set_value(800);
    set_type("shield");
    set_limbs( ({ "right hand" }) );
    set_ac(1);
    set_property("enchantment",4);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
if(!ETO->is_class("paladin")) {
	write("You may not wear this shield!\n");
	return 0;
    } else {
        write("%^BLUE%^You feel more protected by the shield!%^RESET%^");
        tell_room(environment(ETO),"%^BLUE%^"+TPQCN+" is surrounded by an Abyssal light!"
	    "%^RESET%^",ETO);
        return 1;
    }
}
int removeit() {
    tell_object(ETO,"You remove the shield and feel less protected.");
    return 1;
}
