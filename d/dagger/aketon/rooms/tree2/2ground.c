#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Below a giant tree");
   set_long("You are before a tree. It is so huge that you cannot see its "
      "crown. Of a few thousand feets in diameter, looking upward you "
      "see shapes of houses upon the tree branches. Many shadows moving "
      "around. There are steps carved on the trees that allows you move "
      "up. A large statue stands before you. You realize you have arrived "
      "at the elven civilization in the Kilkean forest, the elven city of "
      "Aketon.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of a city coming from above the "
      "tree.");
   set_exits( (["southeast":RPATH+"path11",
      "steps":RPATH2+"2step1"]) );
   set_pre_exit_functions( ({"steps"}),({"GoThroughDoor"}) );
}

void reset(){
   if(!present("statue of guardian"))
      new(OPATH+"guardian_statue1")->move(TO);
}

int GoThroughDoor(){
   object sog;
   if((string)TP->query_race() == "elf") return 1;
   if(sog = present("statue of guardian")) sog->start(TP);
   if((string)TP->query_race() == "half-elf") return 1;
   if(!present("guardian statue"))
   tell_object(TP,"A strong magic prevents you from accessing the steps.");
   return 0;
}
