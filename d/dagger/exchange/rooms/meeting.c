// Hallway  - Merchant Exchange - LoKi - 31-05-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"

inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("A Lavish Room");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^A Lavish Room%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This large room is lavish and the furnishings "+
"beautiful and expensive. The wood panneled walls are covered in various %^RESET%^"+
"%^WHITE%^maps of the continent%^RESET%^%^ORANGE%^. The %^RESET%^%^RED%^plush red "+
"carpet %^RESET%^%^ORANGE%^is clean, and a %^RESET%^%^YELLOW%^large oak table "+
"%^RESET%^%^ORANGE%^dominates the room. Chairs are placed around the table "+
"waiting for visitors. The overall feel of the room is secure and private.\n%^RESET%^");
    set_exits(([
        "south" : ROOMS"hallway",
    ]));  
    set_items(([
        ({"map","maps"}) : "%^RESET%^%^BOLD%^%^GREEN%^Maps line the walls. "+
"Some are simple surveyor maps and maps showing political divisions. Others "+
"are stunning works of art, with flowing lines and drawings of mythical "+
"beasts. %^RESET%^",
({"floor","carpet"}) : "%^RESET%^%^BOLD%^%^RED%^The floor is covered in a deep "+
"rich red carpet. Even though people walk back and forth constantly the carpet "+
"is perfectly clean and without any tears%^RESET%^",
({"chairs","table"}) : "%^RESET%^%^ORANGE%^The oak table in the center of the "+
"room is massive, easily seating ten people. The surface of the table has been"+
" polished to a perfect mirror shine. The chairs around the table are also oak,"+
" and have been upolstered in %^RESET%^%^RED%^rich red "+
"fabric%^RESET%^%^ORANGE%^.%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell polished wood.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^The sounds of the exchange are muted here.%^RESET%^");

    set_door("wooden door",ROOMS"hallway","south",0);
    set_door_description("wooden door","%^RESET%^%^BOLD%^Formed from solid wood, this door looks very"+
" heavy. An %^BLACK%^%^BOLD%^iron ring%^RESET%^%^BOLD%^ hands from it to allow it to be opened.");
    set_string("wooden door", "open", "%^RESET%^%^BOLD%^The heavy door opens quietly.%^RESET%^");
    set_string("wooden door", "close", "%^RESET%^%^BOLD%^The heavy door closes without a sound%^RESET%^%^BOLD%^.");
}
