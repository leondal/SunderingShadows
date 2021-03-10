#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"inner";

void create() {
    ::create();
    set_name("Inner sanctum");
    set_short("%^BLACK%^%^BOLD%^Inner sanctum%^RESET%^");
    set_long("%^CYAN%^Tall marble walls surround the enclosed sanctum here, reaching up to the tiled roof "
"in regularly spaced arches.  Tiny %^ORANGE%^golden%^CYAN%^ veins trail through the "
"%^WHITE%^milky-hued%^CYAN%^ walls, running down into the marble floor and along beneath your feet.  Lit "
"candles line the walls, %^YELLOW%^illuminating%^RESET%^%^CYAN%^ the area so that no shadows can be "
"seen.  To the north, the corridor ends with another wall.  At your feet are several wide-spaced stairs, "
"leading up to a %^RED%^dark altar%^CYAN%^.  A strange, surreal feeling hangs in the air here, as though "
"someone is watching you constantly.%^RESET%^\n");
    add_item(({ "steps","stairs" }),"%^CYAN%^Wide-spaced marble steps lead up from the main floor, to a "
"%^RED%^dark altar%^CYAN%^.%^RESET%^");
    set_exits(([
      "north" : ROOMS+"inner1",
      "south" : ROOMS+"inner3"
    ]));
    set_pre_exit_functions(({"south"}),({"gosouth_fun"}));
}

int gosouth_fun() {
  tell_object(TP,"You slowly ascend the marble stairs.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" slowly ascends the marble stairs, toward the altar.\n",TP);
  }
  return 1;
}
