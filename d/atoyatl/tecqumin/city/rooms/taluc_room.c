#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;
int searched;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A private office");
  set_short( "A private office" );
  set_long( "This small room is unusually well preserved. It is"
    +" cluttered with stacks of books and papers. A small"
    +" writing desk and chair occupy the central position. A window"
    +" looks out onto a garden" );
  set_items( ([ ({"desk", "writing desk"}): "A simple wooden desk."
    +" There are a couple of draws, a sloped writing surface and"
    +" an inkwell. Although simple, it seems somewhat out of place"
    +", not typical of %^CYAN%^Tecqumin%^RESET%^ design",
                   "chair" : "It has four legs and a back, much"
    +" like any chair you could find in Shadow or Tabor.",
      ({"books", "book stacks", "stacks", "stack", "book stack", "papers"}) : 
     "The books stacked in piles here do not appear to be"
    +" %^CYAN%^Tecqumin%^RESET%^ in origin for the most part."
    +" There are atlasses and maps of distant lands, books on"
    +" religion and the familiar faiths you know of the Realms,"
    +" as well as titles dealing with more arcane topics,"
    +" particularly interdimensional communication,"
    +" summoning and travel",
    ({"window", "garden"}) : "The garden has long since grown wild, and"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%"
    +"^%^GREEN%^l%^BOLD%^e %^RESET%^plants have overtaken once"
    +" manicured plant beds"  ]) );
  set_smell("default","The air is still and humid, carrying hints of the perfumes of jungle plants");
  set_listen("default","Faint sounds of the jungle drift in from outside");
  set_exits(([ "south" : CITY_ROOM + "east_corridor1" ]));
  set_door("office door", CITY_ROOM + "east_corridor1", "south", 0);
  set_door_description("office door", "A simple wooden door");
}


void reset(){
  object tal, * tals;
  ::reset();
  if (!present("taluc"), TO){
    tals = children(MOB + "taluc");
    if (sizeof(tals)<1){
      tal = new(MOB + "taluc");
      tal->move(TO);
    }
  }
}

void init() {
   ::init();
   add_action("search_books", "search");
}

int search_books(string str){
  object scroll;
  if (str != "books" && str != "book stacks" && str != "stacks" && str != "stack" && str != "book stack" && str != "papers" && str != "stack of books" && str != "stack of books"){ 
    return notify_fail("The stacks of books look interesting");
  } 
  if (TP->query_skill("academics") + random(10) < 20){
    tell_object (TP, "The %^ORANGE%^books%^RESET%^ are %^BOLD%^%^BLACK%^old%^RESET%^ and %^MAGENTA%^musty%^RESET%^, and all look very complicated and boring. Perhaps if you had nothing better to do, you could build a %^BOLD%^%^WHITE%^fort%^RESET%^ out of them and play soldiers?");
    tell_room(TO, TPQCN + " looks at the stacks of %^ORANGE%^books%^RESET%^, but doesn't seem interested in reading them.", TP);
    return 1;
  }
  if (TP->query_skill("academics") + random(10) < 30){
    tell_object (TP, "The %^ORANGE%^books%^RESET%^ are %^BOLD%^%^BLACK%^old%^RESET%^ and %^MAGENTA%^musty%^RESET%^, but you fear their %^BOLD%^%^BLUE%^arcane%^RESET%^ contents may be beyond your skill to understand.");
    tell_room(TO, TPQCN + " flicks through some of the %^ORANGE%^books%^RESET%^, but gives up after some moments of puzzled concentration.", TP);
    return 1;
  }
  if (searched == 0){
    tell_object(TP, "Your interest is taken by an old tome on interdimensional travel. In amongst fascinating treatises on the arrangements of the planes, and methods of opening gates between them, you find notes on a spell. You take the notes and tuck them in amongst your possessions");
    tell_object(TP, "(You have a new scroll!)");
    scroll = new("/d/magic/scroll");
    scroll->set_spell_name("vacuum breathing");
    scroll->move(TP);
  } else {
    tell_object(TP, "Your interest is taken by an old tome on interdimensional travel. It is fascinating stuff, but you don't have time to read it all now. You do notice that there seems to be a page or two missing, however.");
  }
  tell_room(TO, TPQCN + " settles down to read through some books. You fear that " + TP->QS + " may be distracted for some time.", TP);
} 
