#include <std.h>

inherit "/d/common/obj/armour/bracers";
int last_cast, castings;

void create(){
    ::create();
    set_id(({"bandages", "wrappings", "wrapping", "bindings", "bindings of the mummy", "bindings of the Mummy", "bandage", "wrappings of the mummy", "wrappings of the Mummy"}));
    set_name("wrappings");
    set_short("wrappings of the Mummy");
    set_obvious_short("bandage wrappings");
    set_long("Two rolls of linen bandages. ");
    set_value(500);
    set_wear( (:TO,"wear_it":) );
    set_remove( (:TO,"remove_it":) );
    set_item_bonus("bludgeoning resistance",10);
    set_item_bonus("enchantment",5);
    set_lore("The %^CYAN%^Tecqumin %^RESET%^were skilled at creating%^ORANGE%^ "
      +"mummies%^RESET%^ to preserve the remains of the %^BOLD%^%^RED%^high"
      +" %^RESET%^and %^BOLD%^%^BLUE%^mighty%^RESET%^ of their race. A few were"
      +" also rumoured to dabble in the creation of the %^BLUE%^undead%^RESET%^"
      +" forms. The %^BOLD%^%^WHITE%^wrappings%^RESET%^ that these%^ORANGE%^"
      +" mummies%^RESET%^ were bound in gave a great resistance to%^BOLD%^"
      +"%^BLACK%^ bludgeoning%^RESET%^ damage. It is unclear what effect they"
      +" might have if applied to the living.");
    set("lore difficulty", 36);
    castings = 2;
    last_cast = time()-12001;
}

int wear_it(){
   if((int)ETO->query_level() < 41){
     tell_object(ETO,"You aren't powerful enough to use these wrappings.");
     return 0;
   }
   tell_object(ETO, "You wrap the %^BOLD%^%^WHITE%^bindings%^RESET%^ around your"
     +" forearms, and feel the power of %^BLUE%^undeath%^RESET%^ seep into your"
     +" %^MAGENTA%^f%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^sh%^RESET%^");
   tell_room(environment(ETO),""+ETO->query_cap_name()+" wraps some bindings"
     +" around " + ETO->QP + " forearms. " + capitalize(ETO->QS) + " looks"
     +" slightly queasy as " + ETO->QS + " fastens them off." ,ETO);
   return 1;
}

int remove_it(){
   tell_object(ETO, "You unwrap the %^BOLD%^%^WHITE%^bindings%^RESET%^ from your"
     +" forearms, and feel the power of %^BLUE%^undeath%^RESET%^ leaving your"
     +" %^MAGENTA%^f%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^sh%^RESET%^");
   tell_room(environment(ETO),""+ETO->query_cap_name()+" unwraps the bindings"
     +" from " + ETO->QP + " forearms. " + capitalize(ETO->QS) + " looks"
     +" somewhat relieved as they come off." ,ETO);
   return 1;
}

