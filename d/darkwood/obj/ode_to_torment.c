#include <std.h>
#include <move.h>
inherit OBJECT;

void clone_empty(object who);

void create(){
   ::create();
   set_name("ode to torment");
   set_short("A mug of black fluid");
   set_long("This drink looks like an ichorous, bubbling black fluid that "+
      "oozes around in the mug as if struggling to live on it's own.");
   set_id(({"mug","ode to torment","black fluid","drink"}));
   set_weight(1);
}

void init(){
   ::init();
   add_action("drink","drink");
}

int save_me(string file){
   return 1;
}

int drink(string str) {
   if(!id(str)) return 0;
   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(ETO != TP) return notify_fail("You must get it first.\n");
   if(!random(2)){
      write("You look at the drink and quickly hold your nose and "+
         "drink it down.");
      say(TPQCN+" drinks down the black, oozing fluid into "+
         TP->query_possessive()+" mouth, and "+TP->query_possessive()+
         " eyes bulge out of "+TP->query_possessive()+" head.",TP);
   }
   else{
      write("You feel your mouth dry out and feel a ravenous thirst "+
         "come over you.");
      say(TPQCN+" looks around, slightly distressed.",TP);
   }
   call_out("effect_func",random(3)+3,TP);
   return 1;
}

void effect_func(object who){
   if(!objectp(who)) return;
   who->add_quenched(-25000);
   who->add_intox(-1*(int)who->query_intox() + 2);
   who->calculate_healing();
   who->do_damage("torso",roll_dice(1,6));
   tell_object(who,"You feel the drink rip away at the alchohol clouding "+
      "your mind, and feel the pain the drink has been inflicting on your "+
      "body all at once.");
   tell_room(environment(who),who->query_cap_name()+" screams in agony as "+
      TP->query_possessive() + " eyes open wide in shock.", who);
   clone_empty(who);
   remove();
   return 1;
}

void clone_empty(object who) {
   object empty;
   empty = new("std/Object");
   empty->set_name("bottle");
   empty->set_short("An empty mug");
   empty->set_long("A mug which used to hold something.\n");
   empty->set_id( ({"mug","empty container","empty mug"}) );
   empty->set_value(0);
   empty->set_weight(1);
   empty->set_destroy(1);
   if(empty->move(who) != MOVE_OK) empty->remove();
}
