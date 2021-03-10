#include <std.h>
#include "../kildare.h"

inherit OBJECT;
// object ob;  // only need to be local in the smash function
// object ob2;

void create(){
   ::create();
   set_id(({"vial","black vial","peryton vial","sphere","essence","peryton essence"}));
   set_name("peryton vial");
   set_obvious_short("%^BOLD%^%^BLACK%^A black vial%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Peryton Essence%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^This glass vial is a sphere about three "+
      "inches diameter.  A strange substance swirls and churns inside - "+
      "it seems half-liquid, half darkness itself.  The black vapor "+
      "rises near the cork and seems to be struggling for freedom.  "+
      "Perhaps you could smash the vial, though surely the vapor "+
      "would escape forever then.%^RESET%^");
   set_lore("This vial contains the distilled essence of the foul "+
      "beast, the peryton.  The beast's spirit has been contained, "+
      "and it will now serve whoever it is that releases it from "+
      "this prison of glass.");
   set_property("lore difficulty",10);
   set_weight(5);
   set_value(200);
}

void init(){
   ::init();
   add_action("break_func","smash");
}
int break_func(string str){
   object ob, ob2;
   if ( !str || str !="vial") {
      notify_fail ("Smash what?\n");
      return 0;
   }
        if(TP->query_bound() || TP->query_unconcious() ||
TP->query_paralyzed() ||
TP->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
   }
   switch(random(5)) {
      case 0..2:
         tell_object(ETO,"%^BOLD%^%^BLUE%^You smash the vial on the ground and the "+
            "the black vapor rises, forming into a winged beast!");
         tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" smashes the vial on the ground "+
            "and the black vapor rises, taking the form of a winged beast!",TP);
         tell_object(ETO,"%^RESET%^%^RED%^Peryton stands in defense of you!");
         tell_room(ETP,"%^RESET%^%^RED%^Peryton stands in defense of "+TPQCN+"!",TP);
         ob=new(MON"peryguard.c");
         ob->move(environment(ETO));
         TP->add_follower(ob);
         TP->add_protector(ob);
         break;
      case 3..4:
         tell_object(ETO,"%^BOLD%^%^BLUE%^You smash the vial on the ground and the "+
            "the black vapor churns and splits, forming into two winged beasts!");
         tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" smashes the vial on the ground "+
            "and the black vapor churns and splits, taking the form of two winged beasts!",TP);
         tell_object(ETO,"%^RESET%^%^RED%^Peryton stands in defense of you!");
         tell_object(ETO,"%^RESET%^%^RED%^Peryton stands in defense of you!");
         tell_room(ETP,"%^RESET%^%^RED%^Peryton stands in defense of "+TPQCN+"!",TP);
         tell_room(ETP,"%^RESET%^%^RED%^Peryton stands in defense of "+TPQCN+"!",TP);
         ob=new(MON"peryguard.c");
         ob2=new(MON"peryguard.c");
         ob->move(environment(ETO));
         ob2->move(environment(ETO));
         TP->add_follower(ob);
         TP->add_follower(ob2);
         TP->add_protector(ob);
         TP->add_protector(ob2);
         break;
      }
         TO->remove();
         return 1;
}
