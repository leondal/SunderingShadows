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

   set_long("%^YELLOW%^You find yourself in a large room that is almost "+
    "completely square and made entirely from slabs of %^RED%^crimson "+
    "stained %^BOLD%^%^GREEN%^oak%^YELLOW%^.  The %^RED%^floor"+
    "%^YELLOW%^ of this room is much cleaner than the connecting room, "+
    "though a thick layer of %^BOLD%^%^WHITE%^dust%^YELLOW%^ has "+
    "settled uneasily over it.  Several rows of %^BLUE%^beds"+
    "%^YELLOW%^ line the room and each of them is unmade.  "+
    "The room is exceptionally well lit, thanks entirely to the "+
    "%^RESET%^torches%^YELLOW%^ that are held by %^BOLD%^%^WHITE%^"+
    "silver brackets%^YELLOW%^ in each %^RED%^corner%^YELLOW%^.  "+
    "The %^RED%^ceiling%^YELLOW%^ overhead is some dozen feet up "+
    "and does not appear to be very sturdy.  An %^BOLD%^%^GREEN%^oak "+
    "door%^YELLOW%^ is set into the center of the east wall."+
    "%^RESET%^");

   set_items(([
    ({"oak","stained oak","crimson stained oak"}) : "%^BOLD%^%^GREEN%^"+
    "The thick oak boards that have been carefully pieced together to "+
    "construct this room are stained with %^RED%^crimson%^BOLD%^"+
    "%^GREEN%^.%^RESET%^",
    ({"stains","crimson stains"}) : "%^RED%^These stains adorn "+
    "the floor, walls, and even ceiling of this room.  They could "+
    "very well be the last remaining evidence of some massive "+
    "slaughter.%^RESET%^",
    ({"floor","oak floor","stained floor"}) : "%^RED%^The floor of "+
    "this room is made from the same solid and crimson stained oak "+
    "that constructs the rest of this room.  It is covered uneasily "+
    "with a thick layer of dust and several rows of beds line up "+
    "on it.%^RESET%^",
     ({"dust","thick dust"}) : "%^BOLD%^%^WHITE%^This thick layer of "+
    "dust has settled uneasily over the floor.%^RESET%^",
    "ceiling" : "%^RED%^The ceiling here is some dozen feet overhead "+
    "and made from the same crimson stained oak.  Unfortunately, "+
    "unlike the rest of the room, it does not appear to be very "+
    "sturdy.%^RESET%^",
    ({"torch","torches"}) : "One of these torches is held by a "+
    "%^BOLD%^%^WHITE%^silver bracket%^RESET%^ in each corner of the "+
    "room.",
    ({"brackets","silver brackets","bracket",
    "silver bracket"}) : "%^BOLD%^%^WHITE%^One of these has been "+
    "attached half-way up the wall at each corner of the room.  Each "+
    "now proudly displays a lit torch that bathes this room with its "+
    "light.%^RESET%^",
    ({"corner","corners"}) : "%^RED%^A silver bracket has been "+
    "attached half-way up the wall at each corner of the room.  A lit "+
    "torch rests in each bracket, bathing the room with light."+
    "%^RESET%^",
    ({"beds","rows","bed"}) : "%^BLUE%^There are approximately "+
    "twenty beds total.  They have been lined up in rows and span the "+
    "room.  Each of them are unmade, suggesting that they were "+
    "used only recently.%^RESET%^",
    ]));

   set_exits(([
   "east" : BH_ROOMS+"hideout2",
   ]));

   set_door("oak door",BH_ROOMS+"hideout2","east");
   set_door_description("oak door","%^GREEN%^This door is made "+
   "from four slabs of oak that have been tightly bound together "+
   "with a thick and coarse rope.%^RESET%^");
}

void reset() {
  int i;
  ::reset();
  if(!present("bandit") && random(5) >= 3) {
    for(i = 0;i < random(4) + 1;i++) {
      new("/d/deku/monster/bandit.c")->move(TO);
    }
  }
}