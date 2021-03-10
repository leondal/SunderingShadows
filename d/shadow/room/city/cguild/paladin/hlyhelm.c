#include <std.h>
inherit "/std/armour";
 
void create() {
    ::create();
    set_name("helm");
   set_id(({"helm","helmet","helmet of the order"}));
   set_short("Helmet of the Order");
   set_long("This is a full helmet that covers the wearer's entire head."+
   " It has a visor in the front that may be lifted at times and it bears"+
   " the insignia of the Paladin Order.");
    set_weight(10);
   set_value(30);
    set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    if(!TP->is_class("paladin")) {
	notify_fail("You may not wear this armour!\n");
	return 0;
    } else {
      tell_object(ETO,"%^YELLOW%^You feel more protected by the helmet.%^RESET%^");
      tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+" glows with an inner light!%^RESET%^",ETO);
        return 1;
    }
}
int removeit() {
   tell_object(TP,"You remove the helmet and feel less protected.");
    return 1;
}
