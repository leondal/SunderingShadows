//field20.c - Circe 11/9/03 - new description based on the ritual performed by the Lathanderites.  Will change again
#include <std.h>
#include "../../koenig.h"

inherit ROOM;
int count;

void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(RUTTED_TRACK);
    set_property("light",3);
    set_property("indoors",0);
    set_name("A clearing in the corn field");
    set_short("A clearing in the corn field");
    set_long(
      "To the north and west, %^YELLOW%^corn %^RESET%^grows up all around "+
      "you.  Here, however, the land has been cleared and grass allowed "+
      "to grow.  An %^BOLD%^%^RED%^apple tree %^RESET%^grows here, standing "+
      "just higher than the %^BOLD%^%^GREEN%^cornstalks %^RESET%^around it.  "+
      "This patch of earth is pleasant and the grass fragrant.  Here, it seems, "+
      "you would be hidden from view and could probably relax for awhile.  To "+
      "the east and south, an aged fence blocks passage further.  A plaque has "+
      "been set into the nearest fence post."+
      "\n"
    );
    set("night long","The moonlight reflects off the tall %^BOLD%^%^GREEN%^"+
      "cornstalks %^RESET%^in the field, making them seem to sparkle with "+
      "a %^BOLD%^silvery light%^RESET%^.  They close in around you, seeming "+
      "to block out everything but this small clearing.  The apple tree stands "+
      "dark against the sky, the light reflecting off its slender arms and "+
      "occasionally dancing off the %^BOLD%^%^RED%^ripe red apples%^RESET%^.  "+
      "Here in this small clearing, the world seems at peace."+
      "\n"
   );
    set_items(([
       ({"fence","old fence","aged fence"}) : "The ancient wooden fence is "+
          "bleached nearly white and covered with patches of moss.  From here, "+
          "you can see five fence posts that seem to have strange carvings.",
       ({"posts","post","weathered posts","fence posts"}) : "Weathered symbols "+
          "have been etched into the gnarled wood.  The symbols look very old.  "+
          "The first is that of a sunburst, while on the second post there is "+
          "a symbol that looks sort of like a horse's head.  The third post "+
          "bears an oak leaf.  The fourth has a worn triangle shape.  On "+
          "the fifth post two symbols have been carved, that of a waterfall with "+
          "something surrounding it, though that has faded in time, and a teardrop shape.",
       ({"tree","apple tree","fruit tree"}) : "%^BOLD%^%^RED%^The apple tree "+
          "grows as tall as the corn stalks, standing proud against the sky.  "+
          "Many juicy apples hang suspended from it.  You might be able to pick one.",
       "plaque" : "The wooden plaque has been carved and preserved before it was "+
          "set into the ancient post.  Perhaps you could read it.",
       ({"grass","ground"}) : "The grass here is lush and green, shorn close "+
          "to the earth as though this area were tended by caring hands.  It is "+
          "soft and frangrant, its scent mingling with that of the apples."
    ]));
    set_smell("default","The sweet frangrance of apples and grass reaches you.");
    set_listen("default","The wind through the tree creates a gentle melody.");
    set_read(
@CIRCE
%^BOLD%^%^GREEN%^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
%^WHITE%^This land was hallowed and freed of its taint by
        the church of the %^YELLOW%^Lady of Light%^WHITE%^.
We return it once more to the farmers who should 
             rightfully tend it.  
%^YELLOW%^          Be at peace, gentle souls.
%^BOLD%^%^GREEN%^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^%^RESET%^
CIRCE
   );
    set_exits(([
       "north" : KFIELD"field19",
       "west" : KFIELD"field15"
    ] ));
count = random(2)+2;
}

void init() {
  ::init();
   add_action("pick","pick");
}

void reset() {
  ::reset();
}

int pick(string str)
{
   if(str != "apple" && str != "apples") {
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(count < 1) {
      tell_object(TP,"There don't seem to be any apples left to pick.");
      return 1;
   }
   else {
      tell_object(TP,"%^BOLD%^%^MAGENTA%^You pick a ripe apple from the tree.");
      tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" picks an apple from the tree.",TP);
      new("/d/darkwood/obj/apple")->move(TP);
      count -= 1;
      if(count < 1) {
         add_item("apple tree","The apple tree stands tall against the "+
            "cornstalks, but there seems to be no ripe apples left.");
         add_item("tree","The apple tree stands tall against the "+
            "cornstalks, but there seems to be no ripe apples left.");
         add_item("fruit tree","The apple tree stands tall against the "+
            "cornstalks, but there seems to be no ripe apples left.");
         add_item("apples","It appears as though all the ripe apples"+
         " have been picked.");
         add_item("apple","It appears as though all the ripe apples"+
         " have been picked.");
      }
      return 1;
   }
}
