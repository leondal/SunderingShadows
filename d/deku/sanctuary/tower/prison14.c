#include <std.h>
#include "../dragon.h";

inherit BPRISON;

int opened;

void create () {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This small cell does not consist of very much."+
      " There is a small cot and a barrel full of waste. Other than that,"+
      " there is nothing here. The %^RESET%^walls%^BOLD%^%^BLACK%^ seem to be cracking in this cell."
   );
   set_items( ([
      "cot" : "This is a small bed that prisoners slept on.",
      "barrel" : "This barrel is full of human waste.",
      "walls" : "The walls seem a lot less stable here, especially the northeastern section.",
      "northeastern wall" : "This wall looks weaker than the rest, you could possibly break your way through.",
   ]) );
   opened = 0;
}

void init() {
   ::init();
   add_action("break_wall","break");
}

int break_wall(string str) {
object ob;
   if(!str) {
      write("What do you want to break?");
      return 1;
   }
    if(opened){
      write("The wall has been broken already.");
      return 1;
   }
   if(str == "wall") {
      tell_room(ETP,""+TPQCN+" takes a few steps back, then runs towards the northeastern wall and breaks it down.",TP);
      tell_object(TP,"You take a few steps back, then run towards the northeastern wall and break it down.");
      add_exit(TOWER+"prison15","northeast");
      ob = find_object_or_load(TOWER+"prison15");
      ob->add_exit(TOWER+"prison14","southwest");
      opened = 1;
      return 1;
   }
}
