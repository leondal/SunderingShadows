#include <std.h>
inherit "/d/common/obj/clothing/shoes";
create() {
    ::create();
    set_name("boots");
    set_id(({"boots","boot","plated boots"}));
    set_short("%^RESET%^%^CYAN%^Plated boots%^RESET%^");
    set_long("%^RESET%^%^CYAN%^These boots are made from the hide "+
            "of a plated monster.  They have many smaller "+
			"%^BOLD%^shells%^RESET%^%^CYAN%^ that "+
			"are attached to the leather hide of the skin.  "+
			"The hide is soft and can form to one's feet.  "+
			"There are several %^BOLD%^straps%^RESET%^%^CYAN%^"+
			" to tighten the boots.%^RESET%^");
	set_property("lore difficulty",15);
	set_lore("These boots are the craftmanship"
	 "of a master skinner who knows also of enchantment.");
    set_value(150);
    set_property("enchantment",2+random(2));
	set_size(3);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
	set_item_bonus("cold iron resistance",1);
}
int wearit() {
    tell_object(ETO,"%^CYAN%^You slide your feet into the plated boots "+
    "and stap the them tight.%^RESET%^");
        return 1;
}
int removeit() {
    tell_object(ETO,"%^CYAN%^You unstrap the boots and pull them off.%^RESET%^");
        return 1;
}
