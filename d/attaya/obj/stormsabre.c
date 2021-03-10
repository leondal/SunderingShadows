#include <std.h>
inherit LRWEAPON;
create() {
    ::create();
    set_name("stormsabre");
    set_id(({"stormsabre","sabre","sword","bow"}));
    set_short("%^BOLD%^%^RED%^The Stormsabre%^RESET%^");
    set_long(
      "%^BLUE%^Perhaps the most manaiacal weapon ever conceived, the Stormsabre was given to the Hunter of the Oubliette to defend itself, and demolish all comers.\n It blasts high intensity bolts of red lightning at it's targets and can do massive damage up close as well!"
    );
    set_weight(100);
    set_size(2);
    set_value(3500);
    set_wc(8,16);
    set_large_wc(8,18);
    set_type("slashing");
    set_rate_of_fire(1);
    set_range(5,10,15);
    set_ammo("red lightning");
    set_property("enchantment",1);
    set_property("monsterweapon",1);
    set_wield("%^BOLD%^%^BLUE%^You begin to feel an intense sorrow building within you.  You can hardly stand it.");
    set_unwield("You are happy to unwield this horrible weapon!");
}
int extra_wield() {
    if((int)ETO->query_level() < 30) {
	notify_fail("%^BOLD%^%^RED%^A shadowy presence tells you: %^RESET%^You pathetic little fool, you cannot handle such power!");
	return 0;
    }
    if(!ETO->is_class("thief")) {
	TO->remove();
	return 0;
	write("%^RED%^The gods reclaim their weapon as it flies from your hand and vanishes into the clouds above!");
    }
}
