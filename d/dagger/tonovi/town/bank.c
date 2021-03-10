#include "/d/dagger/tonovi/town/short.h"

inherit BANK;
string getBankId() { return "tonovi";}

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_short("Bank of Tonovi");
    set_long(
   "%^BOLD%^%^BLACK%^Bank of %^BLACK%^T%^BLACK%^o%^RESET%^%^ORANGE%^novi
%^BOLD%^%^BLACK%^This is a large granite hall with several wooden benches set on the sides. Embedded into walls iron bars separate teller area and the %^RESET%^%^ORANGE%^va%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^lt%^BOLD%^%^BLACK%^ from the hall. Several %^BLACK%^g%^BLACK%^u%^RESET%^%^ORANGE%^ards%^BOLD%^%^BLACK%^ stand by massive doors behind the bars. A lone %^BLACK%^t%^RESET%^%^ORANGE%^eller%^BOLD%^%^BLACK%^ assists visitors through window in the bared walls.%^RESET%^

%^BOLD%^%^BLACK%^There is a %^RESET%^%^ORANGE%^sign,%^BOLD%^%^BLACK%^ telling what to do.%^RESET%^
"
    );
    set_smell("default", "You smell gold.");
    set_listen("default", "You hear the cheerful clink of coins striking each other");
    set_items( ([
      "vault" : "Don't even think about trying to get in there.",
      "guards" : "They're a lot bigger than you.",
      "teller" : "She awaits your every order.",
      "sign" : "Read it?",
    ]) );
    set_exits( ([
      "east" : RPATH "street9",
    ]) );
}
