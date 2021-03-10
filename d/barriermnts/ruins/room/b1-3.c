#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l0";

void create() {
    ::create();
    set_long("%^BLUE%^This is a dead-end corridor, leading off to the west into pitch-black darkness.  "
"The roof reaches high above your head, barely visible within the "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ that seem almost alive with movement.  Stone walls surround "
"you on either side, blackened with %^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ and "
"%^ORANGE%^grime%^BLUE%^.  The floor beneath your feet feels perfectly flat, without rubble or upturned "
"stones to impede your progress, but a thick layer of %^WHITE%^foggy mist%^BLUE%^ around your feet makes "
"it impossible to see.  The silence is absolute down here, hanging thickly in the air around you.  The "
"only light here is shed by the faint outline of a doorway, upon the wall directly south of "
"you.%^RESET%^\n");
    add_item(({ "door","doorway","stone doorway" }),"%^ORANGE%^Upon the southern wall is the faint "
"outline of a doorway.  It somehow sheds what minimal %^WHITE%^light%^ORANGE%^ there is here.  At a "
"closer look you realise it is partially transparent, and you can see a staircase behind, that you could "
"probably go up.%^RESET%^");
    add_item(({ "stair","stairs","staircase" }),"%^ORANGE%^Behind the semi-transparent "
"doorway is a staircase, that you could probably go up.%^RESET%^");
    set_exits(([
      "west" : ROOMS+"b1-2",
      "up" : ROOMS+"8-3"
    ]));
    set_pre_exit_functions(({"up"}),({"goup_fun"}));
}

int goup_fun() {
  tell_object(TP,"You step through the semi-transparent doorway and ascend the stairs.");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" steps right through the semi-transparent stone doorway.\n",TP);
  }
  return 1;
}
