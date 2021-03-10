#include <std.h>
#include "../defs.h"
inherit ROOM;

int found = 0;

void create()
{
  ::create();
   set_terrain(VILLAGE);
   set_travel(FOOT_PATH);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^Deep Within Darkwood Forest%^RESET%^");
  set_long("Large crates and barrels lay scattered about the "+
        "forest here.  Somehow, a cart has managed to find its "+
        "way through the dense forest to here, and lays on its "+
        "side, leaning against a tree.  The area is a mess, with "+
        "junk tossed all around the ground.  A few rope hammocks "+
        "have been strung up between the trees, and a couple of "+
        "crude chairs have been made from the old barrels.");
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The trees creak as they sway in the wind.");
  set_items(
    ([
    ({"crates","barrels","chairs"}):"The crates and barrels have "+
        "been picked over long ago.  Most are broken and shattered open, "+
        "and the few that aren't have been made into simple chairs.",
    "hammocks":"These hammocks, while sturdy looking, are covered "+
        "in dirt and grime.  As you near them, you notice they give "+
        "off a soured smell.",
    "cart": "You can't quite figure out how this cart could have "+
        "made it between all these trees.  It looks like something "+
	"could be hidden underneath it."
    ]) );
  set_search("cart",(:TO,"search_cart":));
  set_exits(
    ([
    "east" : ROOMS+"f2",
    "south" : ROOMS+"f6"
    ]) );
}

int search_cart()
{
  if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() ||
TP->query_tripped())
  {
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if(found)
  {
    tell_room(TP,"There doesn't seem to be anything here.");
    return 0;
  }
   if(present("orc chief") || present("orc marauder"))
  {
    tell_room(TP,"An orc steps between you and the cart!");
    return 0;
  }
  else
  {
    tell_room(TP,"You pull something out from under the cart.");
    tell_room(ETP,TPQCN+" tugs something out from underneath the "+
	"overturned cart.",TP);
    found = 1;
    new(OBJ+"finestudded")->move(ETP);
    return 1;
  }
}

void reset()
{
  ::reset();
  if(found) 
  {
    found = 0;
    return 1;
  }
  if(!present("orc chief"))
  {
    new(MONS+"orcchief")->move(this_object());
  }
  if(!present("orc marauder"))
  {
    new(MONS+"orcmarauder")->move(this_object());
    new(MONS+"orcmarauder")->move(this_object());
  }
}
