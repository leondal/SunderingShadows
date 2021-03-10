#include <std.h>

inherit "/d/common/obj/armour/bracers";
string owner;

void create(){
    ::create();
    set_id(({"bracers"}));
    set_name("bracers");
    set_short("bracers");
    set_obvious_short("bracers");
   set_long("A set of high quality bracers. They look to be well cared for and seem lighter than their heft would indicate.");
    set_value(500);
    set_wear( (:TO,"check":) );
}

int check(){
   int level;
    if(interactive(TP) && owner != (string)TPQN) {
    write("The magic repels you!");
    return 0;
    }

   if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("thief") || query_ac() <= 0)
      return 1;
   else
      if(TP->is_class("ranger")){
         level = TP->query_highest_level();
         if(TO->query_property("enchantment"))
            if(level/5 < (TO->query_property("enchantment")+1)) {
               tell_object(TP,"You are not experienced enough to utilize this equipment");
               return 0;
            }
      }
      else{
         write("Your class does not allow you to use these.");
         return 0;
      }
   return 1;
}



void init(){
    ::init();
    if(stringp(owner)) return;
    if(interactive(TP) && TP == ETO){
        owner = TPQN;
    }
}
