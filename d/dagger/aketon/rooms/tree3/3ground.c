#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Below a giant tree");
   set_long("You are before a tree. It is so huge that you cannot see its "
      "crown. It is a few thousand feets in diameter, looking upward you "
      "see shapes of houses upon the tree branches and many shadows moving "
      "around. There are steps carved in the trees that allow you to move "
      "up. You realize you have arrived at the elven civilization in "
      "the Kilkean forest, the elven city of Aketon.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of a city coming from above the "
      "tree.");
   set_exits( (["southwest":RPATH+"path11",
      "steps":RPATH3+"3step1"]) );
   set_pre_exit_functions( ({"steps"}),({"GoThroughDoor"}) );
}

void reset(){
   if(!present("statue of guardian"))
      new(OPATH+"guardian_statue2")->move(TO);
}

int GoThroughDoor(){
   object sog;
   if((string)TP->query_race() != "human") return 1;
   if(sog = present("statue of guardian")){
      sog->start(TP);
      return 0;
   }
   else return 1;
}
