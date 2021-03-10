//Coded for Vicdaerrysn and other Drow of the Ssri tel quessir subrace 
//who were created before the changes to their racial bonuses. ~Circe~ 7/30/13

#include <std.h>
#include <daemons.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("mark");
   set_id(({"mark","marking","racial mark","dark mark","dark marking"}));
   set_short("a small dark marking");
   set_long("%^RESET%^%^ORANGE%^This is a small marking, almost a smudge. "
      "It must be some kind of birthmark.%^RESET%^\n");
   set_type("ring");
   set_limbs(({"left arm"}));
   set_weight(0);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_property("no remove",1);
   set_property("death keep",1);
   set_property("no animate",1);
   set_wear((:TO,"wear_fun":));
}

void init() {
   ::init();
   add_action("myracial","racial");
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^The mark adheres to your skin.%^RESET%^\n"
      "%^RED%^You can %^YELLOW%^<racial commune on [target]>%^RESET%^%^RED%^ to "
      "communicate with other Ssri tel quessir or elves.%^RESET%^\n");
   return 1;
}

void set_property(string prop, mixed value){
   if(prop == "enchantment" && value > 0) return;
   ::set_property(prop, value);
}

int myracial(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the mark.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You can only use <racial commune on [target]> as a Ssri tel quessir drow.");
     return 1;
   }
   if(sscanf(str,"commune on %s",mytarg) == 1) {
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     new("/cmds/spells/c/_commune")->use_spell(TP,present(mytarg,ETP),(int)TP->query_level(),100,"mage");
     return 1;
   }
   tell_object(TP,"You can only use <racial commune on [target]> as a Ssri tel quessir drow.");
   return 1;
}