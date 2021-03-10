#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("A wooden room");
    set_short("A wooden room");
    set_property("no sticks",1);

    set_long("%^YELLOW%^You find yourself in a very strangely designed "+
    "room.  The southern half is square and the northern half forms "+
    "a flawless semi-circle.  Suprisingly, the design of the room is "+
    "flawless, melding together perfectly, and made entirely "+
    "from %^BOLD%^%^GREEN%^oak slabs%^YELLOW%^.  The %^RED%^floor "+
    "%^YELLOW%^of this room is swept and kept always in order, "+
    "lacking even the smallest amounts of dust.  It rises three "+
    "%^RED%^steps%^YELLOW%^ at the start of the semi-circle part of "+
    "the room.  Several %^BOLD%^%^WHITE%^silver brackets%^YELLOW%^ "+
    "attach to the south part of the east and west walls and proudly "+
    "display lit %^RESET%^torches%^YELLOW%^.  The %^RED%^ceiling"+
    "%^YELLOW%^ here is some dozen feet overhead and rises with "+
    "the floor.  A %^RESET%^throne %^YELLOW%^made from %^RESET%^"+
    "tarnished silver%^YELLOW%^ sits near the northern wall of the "+
    "semi-circle portion of the room.  An %^BOLD%^%^GREEN%^oak "+
    "door%^YELLOW%^ is set in the center of the southern wall."+
    "%^RESET%^");
    
    set_items(([
    ({"oak","oak slabs"}) : "%^BOLD%^%^GREEN%^These thick oak boards "+
    "have been carefully pieced together to construct this room, "+
    "with even the design differences seeming to meld together "+
    "flawlessly.%^RESET%^",
    ({"floor","oak floor","stained floor"}) : "%^RED%^The floor "+
    "is made from the same oak slabs that constructs the rest of "+
    "this room.  It rises three steps at the start of the semi-"+
    "circle portion of the room and then levels off again.  It has "+
    "been kept swept and in order.%^RESET%^",
    "ceiling" : "%^RED%^The ceiling here is some dozen feet overhead "+
    "and made from the same oak slabs.  It has been designed so that "+
    "it rises and then levels off along with the floor.%^RESET%^",
    ({"torch","torches"}) : "These lit torches line the south part of "+
    "the east and west walls.  They are held proudly by %^BOLD%^"+
    "%^WHITE%^silver brackets%^RESET%^ and provide the room with its "+
    "exceptional light.",
    ({"brackets","silver brackets","bracket",
    "silver bracket"}) : "%^BOLD%^%^WHITE%^These are attached to the "+
    "south part of the east and west walls of this room.  Each of "+
    "them proudly displays a lit torch.%^RESET%^",
    "steps" : "%^RED%^There are three of these steps in the floor, "+
    "they begin with the semi-circle portion of the room and provide "+
    "a means of stepping up safely.%^RESET%^",
    ({"throne","silver throne","tarnished throne",
    "tarnished silver throne"}) : "%^BOLD%^%^WHITE%^This throne is "+
    "the approximate size for a human to sit comfortably and is made "+
    "entirely from a tarnished silver.  The top of its back is lined "+
    "with %^GREEN%^emeralds%^WHITE%^ and several %^RED%^rubies"+
    "%^WHITE%^ are set into the armrests.%^RESET%^",
    ]));
    
    set_exits(([
    "south": BH_ROOMS+"hideout3",
    ]));

    set_door("oak door",BH_ROOMS+"hideout3", "south");
    set_locked("oak door",0);
    set_door_description("oak door","%^GREEN%^This door is made "+
   "from four slabs of oak that have been tightly bound together "+
   "with a thick and coarse rope.%^RESET%^");
  
    set_listen("default","The floor above creaks and sounds echo off the walls.");
    set_smell("default","You smell leather and lantern oil.");
    set_search("default","%^RED%^This room has been kept "+
    "remarkably clean, there is simply no place for anything "+
    "to be hidden.%^RESET%^");
}

void reset() {
  int i;
  ::reset();
  if(!present("leader") && random(5) >= 3) {
     new("/d/deku/monster/bandit_l.c")->move(TO);
  }
  if(!present("bandit") && random(5) >= 3) {
    for(i = 0;i < random(3) + 1;i++) {
      new("/d/deku/monster/bandit.c")->move(TO);
    }
  }
}


