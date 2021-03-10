#include <std.h>
inherit "/d/common/obj/armour/chain";
create() {
    ::create();
    set_name("armour");
   set_id(({"armour","mesh","mesh armour","armor"}));
    set_short("%^RESET%^%^BLUE%^Mesh armour%^RESET%^");
    set_long(
	"This fine mesh armour is commonly used by the Drow of the "
	"Underdark in which to protect their bodies. It appears to "
	"be magical and is forged from pure adamantite."
    );
    set_value(100);
    set_property("enchantment",2);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
   if((string)TP->query_race() != "Drow" && (string)TP->query_race() != "drow"){
        write(
            "You feel a %^BOLD%^%^YELLOW%^shock%^RESET%^ run through your "
	    "body as you wear the armour!"
        );
        TP->do_damage("torso",roll_dice(3,4));
      TP->add_attacker(TO);
      TP->continue_attack();
      TP->remove_attacker(TO);
        return 1;
    }
    return 1;
}
int removeit() {
    tell_object(TP,
	"%^BOLD%^%^BLACK%^You feel a shadow leave your body as you "
	"remove the fine mesh armor."
    );
     return 1;
}
