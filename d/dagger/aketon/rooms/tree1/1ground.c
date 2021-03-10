#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Below a giant tree");
   set_long("%^GREEN%^Below a giant tree%^RESET%^
You are before a tree. It is so huge that you cannot see its crown. Of a "
      "few thousand feets in diameter, looking upward you see shapes of "
      "houses upon the tree branches. Many shadows moving around. There "
      "are steps carved on the trees that allows you move up. You realize "
      "you have arrived at the elven civilization in the Kilkean forest, "
      "the elven city of Aketon.");
   set_items( ([ ({"city","aketon"}):"It stays high above the huge tree "
      "before you, a place where the highly civilized elven kind lives.",
      "tree":"This is a huge tree. The city of Aketon is built on it.",
      "houses":"You can see the shape of houses upon the tree branches "
      "high above you.",
      "branches":"These are the strong branches that the great elven city "
      "is built on.",
      ({"forest","kilkean"}):"The dense Kilkean forest is all around you.",
      "shadows":"Many shadows is moving around upon the branches above.",
      "steps":"These steps twist up around the tree trunk."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of a city coming from above the "
      "tree.");
   set_exits( (["south":RPATH+"path11",
      "steps":RPATH1+"1step1"]) );
   set_pre_exit_functions( ({"steps"}),({"GoThroughDoor"}) );
}

int GoThroughDoor() {
   object obj;
   if( (string)TP->query_race() != "elf" ) {
      if(obj = present("gate guard")) {
         obj->force_me("kill "+TPQN);
         obj->force_me("say You shall not try to get pass me!");
      }
      else write("A strong magic prevents you from accessing the steps.\n"+
         "You must use other gates.");
      if(obj = present("gate guard 2")) {
         obj->force_me("kill "+TPQN);
         obj->force_me("say And me! Now pay the price!");
      }
      return 0;
   }
   return 1;
}

void reset() {
   if(!present("gate guard")) {
      new(MPATH+"guardE")->move(TO);
      new(MPATH+"guardE")->move(TO);
   }
   else if(!present("gate guard 2"))
      new(MPATH+"guardE")->move(TO);
   else
      return;
}
