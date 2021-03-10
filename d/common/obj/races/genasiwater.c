#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("mark");
   set_id(({"mark","marking","racial mark","blurred mark","blurred marking"}));
   set_short("a small blurred marking");
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
   set_property("enchantment",-1);
   while((int)query_property("enchantment") >= 0){
     remove_property("enchantment");
     set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_fun":));
   tracker = 0;
}

void init() {
   ::init();
   add_action("myracial","racial");
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^The mark adheres to your skin.%^RESET%^\n"
"%^RED%^You can %^YELLOW%^<racial breathe>%^RESET%^%^RED%^ once per SG "
"day (8 hours realtime).%^RESET%^\n");
   return 1;
}

void set_property(string prop, mixed value){
   if(prop == "enchantment" && value > 0) return;
   ::set_property(prop, value);
}

int myracial(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the mark.");
     return 1;
   }
   if(!str || str != "breathe") {
     tell_object(TP,"You can only use <racial breathe> as a water genasi.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used your innate ability today.");
     return 1;
   }
   tracker = time() + 28800;
   new("/cmds/spells/w/_water_breathing")->use_spell(TP,TP,(int)TP->query_level(),100,"mage");
   return 1;
}
