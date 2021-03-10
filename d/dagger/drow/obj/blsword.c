#include <std.h>
inherit "/d/common/obj/weapon/longsword";
create() {
    ::create();
    set_name("longsword");
    set_id(({"longsword","black longsword","long sword","black sword","sword"}));
    set_short("%^BLUE%^Black longsword%^RESET%^");
    set_long(
	"This is one of the standard %^BOLD%^%^BLACK%^black "
	"longswords%^RESET%^ used by the lower ranks of the Drow "
	"Regime. However it still is an amazingly crafted weapon and "
	"emanates magical properties."
    );
    set_property("enchantment",1);
    set_wield((: TO,"drow" :));
}
int drow() {
    if(TP->query_highest_level() < 5) {
        write(
	    "This weapon is to complex for one of your level to wield!"
	);
	return 1;
    }	
   if((string)TP->query_race() != "Drow" && (string)TP->query_race() != "drow"){
        write(
            "You feel a %^BOLD%^%^YELLOW%^shock%^RESET%^ run through your "
	    "body as you wield the sword!"
        );
  
        TP->cause_typed_damage(TP, TP->return_target_limb()
         ,random(13), "electricity");
        return 1;
    }
    return 1;
}
