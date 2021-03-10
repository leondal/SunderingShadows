#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"path";

void create() {
    ::create();
    set_long("%^GREEN%^The forest clears a little here, along a narrow %^ORANGE%^dirt side-path%^GREEN%^ "
"that winds further up into the mountain range, disappearing from view.  Walls of %^BLACK%^%^BOLD%^stone "
"%^RESET%^%^GREEN%^begin to close in around you, reaching up to the sky.  Large boulders and scatterings "
"of undergrowth cover the mountainsides around you, and a few scattered %^BOLD%^pinetrees "
"%^RESET%^%^GREEN%^dot their edges.  The path itself looks as though it has seen little use for many "
"years.%^RESET%^\n");
   set("night long","%^BLUE%^The forest clears a little here, opening to reveal the night sky above this "
"narrow %^ORANGE%^dirt side-path%^BLUE%^, that winds further up into the mountain range and disappears "
"from view.  %^BLACK%^%^BOLD%^Dark shadows%^RESET%^%^BLUE%^ dot the mountainsides around you, that seem "
"to close in around you in the darkness.  The rising mountains are dotted with sparse %^GREEN%^trees "
"%^BLUE%^and %^BLACK%^%^BOLD%^boulders%^RESET%^%^BLUE%^, leaving no shelter anywhere you can "
"see.%^RESET%^\n");
    set_exits(([
      "north" : "/d/barriermnts/lothwaite/rooms/pathway7",
      "southeast" : ROOMS+"path4"
    ]));
}
