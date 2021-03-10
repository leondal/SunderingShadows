#include <std.h>
#include "../dragon.h";

inherit BTOWN;
int mob;
int opened;
object ob;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_short("Ruined square");
   set_long(
      "%^BOLD%^%^BLACK%^You are in what used to be the main square of %^RED%^Sanctuary%^BLACK%^."+
      " All around you are corpses of the people that used to be residents to this town."+ 
      " A large statue stands before you here. Despite all of the carnage that apparently"+ 
      " took place here, the statue stands nearly unscratched."+ 
      " There is a golden plaque at the base of the statue with a few words etched onto it."
   );
   set_exits(([ 
      "south": TOWN+"roadS1",
      "north": TOWN+"roadN1",
      "east": TOWN+"roadE1",
      "west": TOWN+"roadW1"
   ]));
   set_pre_exit_functions( ({"stairs"}), ({"GoThroughDoor"}) );
   set_items(([
      "plaque" : "The original words on this plaque have been blurred out and written over in something you can not read.",
      "statue" : "This is a golden statue of a proud standing man who towers at twenty three feet tall.",
      "corpses" : "Bodies are scattered all around the streets, but there is a large number of them in this area.",
      "button" : "There is a button here that can be pushed."
   ]));
   set_search("plaque","You search the plaque and find a small button underneath.");
   opened = 0;
}

void init() {
   ::init();
   add_action("push_button","push");
}

int push_button(string str) {
   if(!str) {
      write("What do you want to push?");
      return 1;
   }
   if(str == "button") {
      if(opened){
      write("The button has been pushed already.");
      return 1;
   }
   tell_room(ETP,""+TPQCN+" pushes a button that reveals a set of stairs that lead down into the sewers.",TP);
   tell_object(TP,"You reveal a set of stairs that lead down into the sewers.");
   tell_object(TP,"As you push the button, the statue comes to life and blocks the way down!");
   tell_room(ETP,"As "+TPQCN+" pushes the button, the statue comes to life and blocks the way down!",TP);
   add_exit(SEWER+"sewer01","stairs");
   ob = new(MON+"gold_golem")->move(TO);
   opened = 1;
   return 1;
   }
}

int GoThroughDoor() {
   if(!userp(TP)) return 1;
   if(avatarp(TP)) return 1;
   if(!present("golem"))
   {
   return 1;
   }
   else
   {
   tell_object(TP,"The golem blocks the way down.");
   return 0;
}
}
  
