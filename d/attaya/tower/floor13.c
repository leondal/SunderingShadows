
#include <std.h>
inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the walls of the Tower of the Black Dawn.");
     set_long("%^BLUE%^Inside the walls of the Tower of the Black Dawn
%^BLUE%^This is the northeast guard tower. %^CYAN%^Ben%^BOLD%^%^BLACK%^c%^RESET%^%^CYAN%^hes%^BLUE%^ are built into all four walls, and %^WHITE%^firing %^WHITE%^slits%^BLUE%^ have been cut in the floor and the walls. An empty %^CYAN%^weapon %^CYAN%^r%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^ck%^BLUE%^ is built into the north wall.");

    set_exits( ([
    "west" : "/d/attaya/tower/floor16",
        ]) );
   set_listen("default", "The sound of rushing water is somewhat muffled in here.");
    set_items(([
    "benches" : "Wooden benches are built into the north, south, and east walls.",
    "slits" : "Looking out, you can see the walkway, and the water far below.",
    "rack" : "All the weapons have been removed from this wooden weapon rack.",
    ]));

}
void init(){
   ::init();
  do_random_encounters(({"/d/attaya/mon/banisher"}),50,1);
  do_random_encounters(({"/d/attaya/mon/banisher"}),50,1);
  do_random_encounters(({"/d/attaya/mon/archer"}),50,1);
  do_random_encounters(({"/d/attaya/mon/uwarrior"}),50,1);
  do_random_encounters(({"/d/attaya/mon/phalanx"}),50,1);
  do_random_encounters(({"/d/attaya/mon/warlock"}),50,1);
  do_random_encounters(({"/d/attaya/mon/archer"}),50,1);
  do_random_encounters(({"/d/attaya/mon/knight"}),50,1);
  do_random_encounters(({"/d/attaya/mon/knight2"}),50,1);
  do_random_encounters(({"/d/attaya/mon/solstice"}),25,1);

   }

