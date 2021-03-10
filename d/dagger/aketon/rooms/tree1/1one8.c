#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Guard post");
   set_long("%^BOLD%^Guard post%^RESET%^
This is one of the many guard posts scattered in the city of Aketon. Not "
      "much stuff is here. A simple table and a chair sit by the wall at "
      "the far side close to the opening. A lamp lights up the room. Some "
      "weapons are there randomly placed on the floor.");
   set_items( (["post":"This is guard post where guards stations.",
      ({"table","chair"}):"A simple table and a chair.",
      "opening":"Views of the Kilkean forest and the city itself can be "
      "seen outside the opening. It is the place where the guards scan "
      "everyone passing by.",
      "lamp":"This lamp lights up the whole room.",
      "weapons":"They are used by the guards to fight raiders and "
      "intruders."]) );
   set_smell("default","You can smell sweat here.");
   set_listen("default","You hear sounds of the city coming from outside "
      "the guard post.");
   set_exits( (["east":RPATH1+"1one9"]) );
}

void reset() {
   ::reset();
   if( !present("post guard") ) {
      new(MPATH+"guardF")->move(TO);
      new(MPATH+"guardF")->move(TO);
   }
   else if( !present("post guard 2") )
      new(MPATH+"guardF")->move(TO);
   else
      return;
}
