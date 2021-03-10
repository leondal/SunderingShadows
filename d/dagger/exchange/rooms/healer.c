// Healer  - Merchant Exchange - LoKi - 19-02-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"


inherit HEALER;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("Rorn");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^A Hallway%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This small room is furnished "+
"with expensive furniture. A %^RESET%^%^WHITE%^small desk %^RESET%^"+
"%^ORANGE%^dominates the room and the walls are lined in mahogany "+
"shelves filled with %^RESET%^%^MAGENTA%^bottles %^RESET%^%^ORANGE%^"+
"and %^RESET%^%^YELLOW%^boxes%^RESET%^%^ORANGE%^. On the back wall "+
"is a %^RESET%^%^BOLD%^%^BLACK%^large black banner%^RESET%^%^ORANGE%^"+
". Several implements of a doctor sit on a %^RESET%^%^BOLD%^%^WHITE%^"+
"silver tray %^RESET%^%^ORANGE%^on the desk. The same %^RESET%^%^RED%^"+
"lush red carpet %^RESET%^%^ORANGE%^continues to this room, and even "+
"though this is obviously a place of healing, it is immaculate.%^RESET%^");
    set_exits(([
        "north" : ROOMS"hallway",
    ]));  
    set_items(([
        ({"banner"}) : "%^RESET%^%^BOLD%^%^BLACK%^A large black banner "+
"has been hung carefully on the back wall. The material seems to be a fine"+
" black silk. Embroidered in the center of the banner is the %^RESET%^%^BOLD%^"+
"%^WHITE%^ensignia of a white dragon's head in profile%^RESET%^%^BOLD%^%^BLACK%^"+
", it's jaw open. Along the bottom is a motto stiched in %^RESET%^%^RED%^red "+
"%^RESET%^%^BOLD%^%^BLACK%^'%^RESET%^%^BOLD%^%^RED%^Honor to the Brothers of "+
"the Dragoons'%^RESET%^",
({"floor","carpet"}) : "%^RESET%^%^BOLD%^%^RED%^The floor is covered in a deep "+
"rich red carpet. Even though people walk back and forth constantly the carpet "+
"is perfectly clean and without any tears%^RESET%^",
({"bottles","boxes"}) : "%^RESET%^%^ORANGE%^The shelves lining the walls are "+
"lined with %^RESET%^%^MAGENTA%^bottles %^RESET%^%^ORANGE%^and %^RESET%^"+
"%^YELLOW%^boxes%^RESET%^%^ORANGE%^. Each one has been %^RESET%^%^WHITE%^labelled"+
" carefully %^RESET%^%^ORANGE%^and the bottles seem to hold balms and powders of"+
" a hundred different types.\n%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell the thick smell of oils and balms.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^The medic's office is quiet.%^RESET%^");


}

void reset(){
    ::reset();
    if(!present("rorn")){new(MOBS"rorn.c")->move(TO);}
}
