#include <std.h>
#include <daemons.h>

inherit OBJECT;

void start(object targ);

void init(){
   ::init();
   add_action("read","read");
}

void create(){
   ::create();
   set_name("statue of guardian");
   set_id( ({"statue","guardian statue","guard statue"}) );
   set("short","%^YELLOW%^A statue of a magnificent elf");
   set("long","%^YELLOW%^The Statue of Guardian%^RESET%^\n"
      "This massive statue made of granite stands before you. It is in "
       "the shape of a magnificent elf who is wearing a cloak and holding an "
      "opened book in his right hand. His left hand lifts over his head "
      "and spreads out with the palm facing the ground before the statue "
      "where you are currently standing at. He is looking firmly at the "
      "path before the giant tree. A golden plaque is imbedded in the "
      "base of the statue. As you look closer at the statue, you seem to "
      "notice the eyes are sweeping across the area all the time.");
   set_weight(10000);
   set_value(10000);
   set_property("no animate",1);
}

int read(string str){
   if(!str || str != "plaque") return 0;
   if(!TP->query_invis() && !avatarp(TP))
      tell_room(ETO,TPQCN+" reads over the plaque!",TP);
   tell_object(TP,"%^YELLOW%^In memory of the Eternal Guardian of Aketon: "+
      "Puttask Muc'ougeshe, the Great Wizard\n\n"
       "Once upon a time, our Great Wizard, Puttask defeated the great "
       "red dragon who wrecked the city. May his spirit be among "
      "us for eternity, protecting us from any intruders.");
   return 1;
}

void start(object targ){
   if((string)targ->query_race() == "elf") return;
   else if((string)targ->query_race() == "half-elf"){
      tell_object(targ,"You get a feeling the statue watches you as you "
          "walk passed it.");
      return;
   }
   else{
      tell_object(targ,"test");
   }
   return;
}
