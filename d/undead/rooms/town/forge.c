#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Inside the barracks of Graez");
    set_short("%^RESET%^%^RED%^Inside the barracks of Graez%^RESET%^");
    set_long("%^RESET%^%^RED%^Inside the barracks of Graez%^RESET%^\n"
"Two massive mechanical guardians stoke a %^RED%^massive furnace %^RESET%^and "
"maintain the heated forge that takes up the majority of this enclosed room.  "
"Their hulking forms seem patched together from hundreds of different pieces of "
"armor, weapons and other less identifiable items.  Across the room lie a "
"series of %^CYAN%^steel tools%^RESET%^, neatly set out on a scarred wooden "
"counter that ends at a mammoth %^BOLD%^%^BLACK%^anvil%^RESET%^.%^RESET%^\n");
    set_smell("default","The smell of smoke and iron fills the air.");
    set_listen("default","The building is filled with the constant clang of metal on metal.");

    set_exits( ([
        "north":TOWN"weapons",
        "south":TOWN"smith"
    ]) );
    set_property("smithy",1); 
}
