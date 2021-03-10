#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Stonewell");
  set("day long",
@WELL
%^BOLD%^%^BLUE%^Stonewell%^RESET%^
This is one of two stone wells in the village. It is surrounded
by trees and flowers that speak of its life giving gift and
sweetness.
WELL
  );
  set("night long",
@WELL
%^BOLD%^%^BLUE%^Stonewell%^RESET%^
This is one of two stonewells in the village. It is surrounded by
trees and flowers that speak of its life giving gift and sweetness.
Oddly at night tall torches light path to it and around it, as if
to drive the dark shadows of the forest back.
WELL
  );
  set_smell("default","The air is fresh and smells of the forest and water.");
  set_listen("default","Birds and crickets can be heard deep within the forest.");
  set_items( ([
     "well" : "You could drink from it.",
     "trees" : "Are thick and tall leaving only one way out of here.",
     "flowers" : "They are colorful and fill the air with their sweet scent.",
     "torches" : "The torches are roughly 6 to 7ft tall and are set in the ground. At night they are lit to give light and guidance to and from the well."
  ]) );
  set_exits( ([
     "west" : "/d/darkwood/forest/village/str5"
  ]) );
  }

void init(){
  ::init();
  add_action("drink","drink");
}

int drink(string str){
  if(str != "water" || str != "well" || str != "water from well")
  tell_room(environment(TP),TPQCN+" drinks deeply of the well's refreshing water.",TP);
  tell_object(TP,"You grab a nearby ladel and dip it into the well.");
  tell_object(TP,"%^BOLD%^%^BLUE%^You drink deeply of the refreshing water.");
  TP->add_quenched(5);
  return 1;
}
