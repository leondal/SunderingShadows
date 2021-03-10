#include <std.h>
inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(1);
   set_indoors(1);
   set_short("A Filthy Kitchen");
   set_long("%^RESET%^%^CYAN%^This small kitchen is rather filthy, and it looks like no one really "
      "bothers to clean it. The %^RESET%^%^ORANGE%^wooden counters %^CYAN%^are rough, and a disgusting "
      "%^RED%^rug %^CYAN%^in front of the %^BOLD%^sink %^RESET%^%^CYAN%^has seen better days. "
      "Despite its ramshackle state, the majority of the dishes are %^RESET%^silver%^CYAN%^, "
      "and the goblets are %^YELLOW%^gold%^RESET%^%^CYAN%^, creating an odd disparity. "
      "Across from the entrance is a door that must lead into the pantry.%^RESET%^\n");
   set_items(([
      "dishes" : "They are made of silver, but one wouldn't really notice right "
         "off with as dirty as they are.",
      "goblets" : "These must be worth a small fortune. They are made of gold and set "
         "with jewels. Makes you wonder why no one seems to bother to clean them.",
      "stove" : "It is definitely being used to cook something in a large stew pot. "
         "Whatever is cooking smells delicious.",
      "rug" : "It is impossible to tell what color the woven rug used to be. It is now "
         "mostly covered in mud ... and is that blood?",
      "sink" : "The sink is piled high with dirty dishes, and brown water drips from the tap."
   ]));
   set_smell("default", "You can smell something delicious cooking on the stove.");
   set_listen("default", "You hear the crackling of the fire in the other room.");
   set_exits(([
      "west" : "/d/koenig/town/house2",
      "pantry" : "/d/koenig/town/pantry"
   ]));
   set_door("door","/d/koenig/town/pantry.c","pantry","open_door");
   set_open("door", 0);
   set_string("door", "open", "The door opens, revealing a rather dark pantry.\n");
}

void reset(){
   ::reset();
   if(!present("cook"))new("/d/koenig/town/mon/asscook")->move(TO);
   if(!present("underling"))new("/d/koenig/town/mon/assunder1")->move(TO);
}
