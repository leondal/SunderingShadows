#include <std.h>
#include "../../newbie.h"
inherit WATER;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void create(){
  ::create();
  set_property("light",0);
  set_terrain(DEEP_WATER);
  set_travel(FRESH_BLAZE);

  set_name("Cor'Alu Lake");
  set_short("%^BOLD%^%^CYAN%^Cor'Alu Lake%^RESET%^");
  set_long("%^BLUE%^It is difficult to see much in deep, muddy "+
"waters of the %^CYAN%^Cor'Alu Lake%^BLUE%^.   Here, %^BOLD%^"+
"%^BLACK%^larger fish %^RESET%^%^BLUE%^swim about, lurking in "+
"the darker waters while waiting for one of the %^RESET%^small "+
"fish %^BLUE%^to swim too low.  Scattered across the bottom, old "+
"%^ORANGE%^logs%^BLUE%^, %^CYAN%^water-weeds %^BLUE%^and other "+
"lake %^CYAN%^flora %^BLUE%^can be found interspersed between "+
"the larger %^RESET%^boulders %^BLUE%^which have tumbled down "+
"from the rocky bank above.  Nearby a the husk of a rotted, water"+
"-swollen %^BOLD%^%^BLACK%^tree %^RESET%^%^BLUE%^can be seen."+
"%^RESET%^");

  set_smell("default","\nThe water is gritty and tastes of mud.");
  set_listen("default","You hear water moving about you as you "+
"swim along.");

  set_items(([
    ({"fish","little fish"}):"%^RESET%^You see there are a number "+
"of small silver, gray and blue-tinged fish that dart about the "+
"rocky edges of the lake, seeking shelter in the nooks and crannies "+
"found there.  A few swim about in the open water, snatching up "+
"bugs that land on the surface, but these fish quickly swim away "+
"soon as you draw near.%^RESET%^",
    ({"large fish"}):"%^BOLD%^%^BLUE%^Looking into the deep water "+
"you can see several larger fish swimming about.  Trout, bass, "+
"an occasional salmon, and a few others you're not sure about. "+
"Like their smaller cousins, as soon as you draw close they "+
"swim away quickly.%^RESET%^",
    ({"water","light"}):"%^CYAN%^Very little light filters down "+
"this low into the water.  Partly due to the depth of the water "+
"and partly due to the amount of muck and grit that swirls about "+
"in the depths.%^RESET%^",
    ({"water-weeds","water weeds","weeds","logs","flora"}):""+
"%^GREEN%^Scraggly plants struggle to grow up from the muddy "+
"bottom of the lake.  Those that manage tangle up through the "+
"piles of boulders or grow out of the occasional water-logged "+
"branch that has found its way to the bottom of the lake."+
"%^RESET%^",
    ({"boulders","rocks","bank","rocks"}):"%^BOLD%^%^BLACK%^"+
"Spilling down from the rocky banks, a few piles of rocks and "+
"the occasional large boulder can be seen along the muddy "+
"bottom of the lake bed.  Most are algae covered and look to "+
"have been down here for some time.%^RESET%^",
    ({"tree"}):"%^RESET%^%^ORANGE%^It would appear that a "+
"storm knocked down one of the trees that surrounds the lake "+
"edge.  It has since sunk to the bottom, where time, water "+
"and the fish have worked away at it till there is little "+
"more then a hollowed out shell.  The dark recesses of the "+
"trunk would make an exceptional hiding spot for someone "+
"or something that could hide under water.  Maybe you "+
"should %^RESET%^search%^ORANGE%^ inside.%^RESET%^",
  ]));


  set_exits(([
    "up":"lake7"
  ]));

  set_search("default","Maybe you could search %^ORANGE%^"+
"inside%^RESET%^ the tree?");
  set_search("inside",(:TO,"search_tree":));
  set_search("tree",(:TO,"search_tree":));
}

int search_tree(string str){
  tell_object(TP,"%^BOLD%^%^BLUE%^You swim closer to the "+
"old tree, eventually venturing inside to have a closer "+
"look.%^RESET%^");
  tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->QCN+" swims down "+
"and into the hollow husk of the old tree.%^RESET%^",TP);
  TP->move("/d/newbie/rooms/lake/lakelog");
  return 1;
}
