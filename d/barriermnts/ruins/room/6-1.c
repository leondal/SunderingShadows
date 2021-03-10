#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1c";

void create() {
    ::create();
    set_long("%^ORANGE%^This corridor extends north and south, lined by stone walls on either side.  The "
"roof spans high above your head, supported by curved arches from both walls, decorated ornately but "
"covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  The floor beneath your feet is "
"perfectly flat, without rubble or upturned stones to impede your progress, though it is coated in still "
"more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  No windows mark this length of corridor, making it a "
"little darker here.  The corridor itself continues into darkness in both directions.  It seems very "
"%^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your shoulders, making you feel a "
"little uneasy.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"5-1",
      "south" : ROOMS+"7-1",
    ]));
}
