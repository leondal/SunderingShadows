// Hallway  - Merchant Exchange - LoKi - 31-05-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"

inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("A Hallway");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^A Hallway%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The opulence of the foyer continues along "+
"this hallway. The glow from the Foyer still reaches here, illuminating the "+
"%^RESET%^%^RED%^plush red carpet %^RESET%^%^ORANGE%^and wood panelled walls."+
" Several paintings have with obvious reverence. To the north is %^RESET%^"+
"%^WHITE%^a solid wood %^RESET%^%^ORANGE%^door with a sign over it. To the"+
" south you see a %^RESET%^%^WHITE%^small desk%^RESET%^%^ORANGE%^. %^RESET%^");
    set_exits(([
        "west" : ROOMS"foyer",
        "south" : ROOMS"healer",
        "east" : ROOMS"hallway2",
        "north" : ROOMS"meeting",
    ]));  
    set_items(([
        ({"paintings"}) : "%^RESET%^%^ORANGE%^Paintings depicting various victories"+
" of the Dragoons adorn the walls.%^RESET%^",
({"floor","carpet"}) : "%^RESET%^%^BOLD%^%^RED%^The floor is covered in a deep "+
"rich red carpet. Even though people walk back and forth constantly the carpet "+
"is perfectly clean and without any tears%^RESET%^",
({"sign"}) : "%^RESET%^%^ORANGE%^A small sign hangs beside the door to the north\n\n "+
"%^RESET%^%^YELLOW%^**************************************************\n%^RESET%^%^ORANGE%^"+
"The meeting rooms in the Exchange are provided at no charge for negotiations "+
"and meetings. Your privacy is important to us, however, any sign of violence "+
"within will result in immediate reaction from the Dragoons.\n"+
"                     %^RESET%^%^BOLD%^%^WHITE%^The Management",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell polished wood.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^The sounds of the exchange are muted here.%^RESET%^");



    set_door("wooden door",ROOMS"meeting","north",0);
    set_door_description("wooden door","%^RESET%^%^BOLD%^Formed from solid wood, this door looks very"+
" heavy. An %^BLACK%^%^BOLD%^iron ring%^RESET%^%^BOLD%^ hands from it to allow it to be opened.");
    set_string("wooden door", "open", "%^RESET%^%^BOLD%^The heavy door opens quietly.%^RESET%^");
    set_string("wooden door", "close", "%^RESET%^%^BOLD%^The heavy door closes without a sound%^RESET%^%^BOLD%^.");
}

void reset(){
    ::reset();
//     if(!present("belanos")){new(MOBS"belanos.c")->move(TO);}
}
