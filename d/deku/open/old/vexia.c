//facelift by Styx 9/01
#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

int open, move;
object obj;

void create() {
    ::create();
    set_short("Vexia's Room");
    set_long(( :(TO,"long_descr"): ));
    set_smell("default","The smell of dust, death and decay are strong here.");
    set_exits(([ "east" : "/d/deku/open/cave_r8" ] ));
    set_items(([
       "cauldron" : "The cauldron is empty.",
       "bed" : "The bed has been crudely made and left to gather dust.",
       "depression" : "You'll have to get a closer look to see much.",
    ] ));
}

string long_descr(string str) {
  if(!move) {
    return("The darkness in the room is thick, and the dust seems to have "
    "settled long ago.  Standing in the center of the odd-shaped room is a "
    "rusted iron kettle positioned on a circular tripod.  Beneath the cauldron "
    "is a small depression in the worked stone of the floor.  In the far south "
    "corner is a large bed, apparently made of sawdust and furs with wooden "
    "beams for a frame.");
  } else {
    return("The darkness in the room is thick, and the dust seems to have "
    "settled long ago.  In the center of the odd-shaped room is a small "
    "depression in the worked stone of the floor where the cauldron might "
    "have once stood.  The cauldron seems to have been upset and moved aside.  "
    "In the far south corner is a large bed, apparently made of sawdust and "
    "furs with wooden beams for a frame.");
  }
}

void reset() {
  ::reset();
  open = 0;
  move = 0;
  if(!random(5) && !present("vexia")) {
    obj = find_object_or_load("/d/deku/monster/vexia.c");
    obj->move(TO);
  }
}


void init() {
  ::init();
  add_action("search","search");
  add_action("move_it","move");
}

int move_it(string str) {
  if(!str) {
    write("What would you like to move?");
    return 1;
  }
  if(str != "cauldron") {
    write("You cannot move that!");
    return 1;
  }
  if(move) {
    write("It's already been turned upside down.");
    return 1;
  }
  if(TP->query_stats("strength") < 11) {
    write("The "+str+" weighs about 350lbs!  You're not strong enough.");
    return 1;
  }
  write("You pick up the "+str+" and toss it to the side.");
  tell_room(ETP, TPQCN+" picks up the "+str+" and tosses it to the side.", TP);
  move = 1;
  return 1;
}

int search(string str) {
  object note, money;
  if(!str) {
    write("Search what?");
    return 1;
  }
  if (str == "cauldron" && move == 0) {
    write("You search the cauldron and find nothing.");
    return 1;
  }
  if(str == "cauldron" && move == 1) {
    write("You search the upside down cauldron and find nothing.");
    return 1;
  }
  if(str == "depression") {
    if(!move) {
      write("How can you search the "+str+" with the cauldron in the way?");
      return 1;
    }
    if(open) {
      write("You search the "+str+" but find nothing this time.");
      tell_room(ETP, TPQCN+" searches the "+str+" but finds nothing.", TP);
      return 1;
    }
    write("You search the "+str+", and find something!");
    tell_room(ETP, TPQCN+" searches the "+str+" and finds something!", TP);
    switch(random(3)) {
      case 0: 
         money = new("/std/obj/coins");
         money->set_money("gold",random(100));
         money->move(TO);
      case 1:
         note = new("/d/deku/misc/deku_note");
         note->move(TO);
         break;
      case 2:
         new("/d/deku/misc/purple")->move(TO);
         break;
      }   
    open = 1;
    return 1;
  }
  write("You search the "+str+" but find nothing.");
  return 1;
}
  
