#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2a";

void create() {
    ::create();
    set_long("%^ORANGE%^This hallway extends to the east and west, bordered by solid stone walls on both "
"sides.  They rise to meet the ornate borders that edge the roof, spanning high above your head and "
"covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ cushions your "
"steps upon the tiled floor.  Within the wall to the south are regularly-spaced windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass, shedding "
"faint light into the corridor, though their surfaces are %^BLACK%^%^BOLD%^blackened%^RESET%^%^ORANGE%^ "
"with dirt.  Upon the northern wall is the outline of a doorway, etched within the stone.  Soft breaths "
"of wind brush along the corridor, carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past "
"you.%^RESET%^\n");
    add_item(({ "door","doorway","stone doorway" }),"%^ORANGE%^Upon the northern wall is the faint "
"outline of a doorway.  At a closer look you realise it is partially transparent, and you can see a "
"staircase behind, that you could probably go down.%^RESET%^");
    add_item(({ "stair","stairs","staircase" }),"%^ORANGE%^Behind the semi-transparent "
"doorway is a staircase, that you could probably go down.%^RESET%^");
    set_exits(([
      "east" : ROOMS+"u1-4",
      "west" : ROOMS+"u1-2",
      "down" : ROOMS+"8-3"
    ]));
    set_pre_exit_functions(({"down"}),({"godown_fun"}));
}

int godown_fun() {
  tell_object(TP,"You step through the semi-transparent doorway and descend the stairs.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" steps right through the semi-transparent stone doorway.\n",TP);
  }
  return 1;
}
