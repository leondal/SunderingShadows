#include <std.h>

inherit "/d/common/obj/armour/bracers";
int last_cast, castings;

void create(){
    ::create();
    set_id(({"bandages", "wrappings", "wrapping", "bindings", "bindings of the mummy", "bindings of the Mummy", "bandage", "wrappings of the mummy", "wrappings of the Mummy"}));
    set_name("wrappings");
    set_short("%^BOLD%^%^BLUE%^Greater %^WHITE%^wrappings%^BLUE%^ of the"
      +" %^RESET%^%^ORANGE%^Mummy%^RESET%^");
    set_obvious_short("bandage wrappings");
    set_long("Two rolls of linen bandages, inscribed with %^BLUE%^dull"
      +" b%^BOLD%^l%^RESET%^%^BLUE%^ue p%^BOLD%^i%^RESET%^%^BLUE%^ctogr"
      +"%^BOLD%^a%^RESET%^%^BLUE%^ms");
    set_value(500);
    set_wear( (:TO,"wear_it":) );
    set_remove( (:TO,"remove_it":) );
    set_property("quest required", "%^GREEN%^Sealed the %^BLUE%^U%^MAGENTA%^nf"
    +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
    +" %^GREEN%^back into the %^BLUE%^v%^BOLD%^%^BLACK%^o%^RESET%^i%^BLUE%^d");
    set_item_bonus("bludgeoning resistance",25);
    set_item_bonus("enchantment",6);
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
     +" %^MAGENTA%^f%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^sh%^RESET%^\nYou realise"
     +" that if you choose to <embrace undeath>, the magic of the wrappings will"
     +" protect you from death magics for a limited time.");
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

void init(){
    ::init();
   add_action("embrace_undeath", "embrace");
}


int embrace_undeath(string str){
  if (str != "undeath"){
    return notify_fail("Try <embrace undeath>");
  }
  if (ETO->query_property("no death")==1){
    tell_object(ETO, "You are already warded against death magics");
    return 1;
  }
  if (last_cast + 12000 <= time()){
    castings = 2;
    last_cast = time();
  }
  if (castings <1){
    tell_object(TP, "You cannot use the wrappings to provide that"
      +" protection again yet.");
    return 1;
  } 
  tell_object(ETO, "You feel the power of %^BLUE%^undeath%^RESET%^"
    +" envelop you, warding against %^BOLD%^%^BLACK%^death magics");
  if (objectp(EETO)){
    tell_room(EETO, "%^BLUE%^A darkness emerges from the wrappings"
      +" around " + ETO->QCN + "'s%^RESET%^%^BLUE%^ forearms and seeps"
      +" back into " + ETO->QP + " skin.");
  }
  ETO->set_property("no death",1);
  castings --;
  call_out("finish_effect", 300);
  return 1;
}

void finish_effect(){
  tell_object(ETO, "You feel the power of %^BLUE%^undeath%^RESET%^ leave you, making you vulnerable to %^BOLD%^%^BLACK%^death magics%^RESET%^ once more");
  if (objectp(EETO)){
    tell_room(EETO, "%^BLUE%^A darkness leaves " + ETO->QCN + "'s%^RESET%^%^BLUE%^ skin and returns to the wrappings around " + ETO->QP + " forearms.");
  }
  ETO->set_property("no death", -1);
}
