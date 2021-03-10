#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"inner";

void create() {
    ::create();
    set_name("Inner sanctum");
    set_short("%^BLACK%^%^BOLD%^Inner sanctum%^RESET%^");
    set_long("%^CYAN%^Tall marble walls surround the enclosed sanctum here in all directions but to the "
"south, reaching up to the tiled roof in regularly spaced arches.  Tiny %^ORANGE%^golden%^CYAN%^ veins "
"trail through the %^WHITE%^milky-hued%^CYAN%^ walls, running down into the marble floor and along "
"beneath your feet.  Lit candles line the walls, %^YELLOW%^illuminating%^RESET%^%^CYAN%^ the area so that "
"no shadows can be seen.  Upon the northern wall is the outline of a strangely transparent doorway, "
"through which you can see the outer hallways of the building. To the south you can see stairs leading up "
"to a %^RED%^dark altar%^CYAN%^.  A strange, surreal feeling hangs in the air here, as though someone is "
"watching you constantly.%^RESET%^\n");
    add_item(({ "door","doorway","stone doorway" }),"%^CYAN%^Upon the northern wall is the faint outline "
"of a doorway, through which you can see the outer hallways of the building.  At a closer look you "
"realise it is partially transparent, and you could probably walk north, right through it.%^RESET%^");
    set_exits(([
      "north" : ROOMS+"3-3",
      "south" : ROOMS+"inner2"
    ]));
    set_pre_exit_functions(({"north"}),({"gonorth_fun"}));
}

void reset() {
    ::reset();
    if(!present("spirit")) { new(MON+"advspirit")->move(TO); }
}

int gonorth_fun() {
  tell_object(TP,"You step through the semi-transparent doorway, into the outer hall.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" steps right through the semi-transparent stone doorway.\n",TP);
  }
  return 1;
}
