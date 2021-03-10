// Foyer  - Merchant Exchange - LoKi - 19-02-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"

inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("A Comfortable Foyer");
    set_property("light",2);
    set_property("no invis", 1);
    set_short("%^RESET%^%^ORANGE%^A C%^RESET%^%^RED%^o%^RESET%^"+
"%^ORANGE%^mforta%^RESET%^%^RED%^b%^RESET%^%^ORANGE%^le F%^RESET%^"+
"%^RED%^o%^RESET%^%^ORANGE%^yer%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This room is spacious and richly"+
" appointed. A large mahogany desk sits on the western wall, carved"+
" with a motif of a harbor full of ships. The floor is a %^RESET%^"+
"%^RED%^deep red carpet%^RESET%^%^ORANGE%^. A large table sits in "+
"the centre of the room with a large vase of %^RESET%^%^BOLD%^"+
"%^MAGENTA%^f%^RESET%^%^BOLD%^%^GREEN%^lo%^RESET%^%^YELLOW%^w%^RESET%^"+
"%^BOLD%^%^GREEN%^e%^RESET%^%^BOLD%^%^RED%^r%^RESET%^%^BOLD%^%^GREEN%^"+
"s%^RESET%^%^ORANGE%^. A %^RESET%^%^BOLD%^%^WHITE%^cr%^RESET%^%^WHITE%^"+
"y%^RESET%^%^BOLD%^%^WHITE%^stal chand%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^"+
"%^WHITE%^lier %^RESET%^%^ORANGE%^hangs from the ceiling to light the room."+
" Through the north door you can hear a thunderous cacaphony of the trading"+
" floor. To the east is a hallway.%^RESET%^");
    set_exits(([
        "east" : ROOMS"hallway",
        "north" : ROOMS"trading",
        "south" : ROOMS"entrance",
    ]));  
    set_items(([
        ({"desk"}) : "%^RESET%^%^ORANGE%^A large oak desk sits against the wall"+
". A small sign sits on it.%^RESET%^",
({"vase","flowers"}) : "%^RESET%^%^BOLD%^%^WHITE%^A large crystal vase sits on "+
"the table, overflowing with a collection of %^RESET%^%^BOLD%^%^RED%^ro%^RESET%^"+
"%^RED%^s%^RESET%^%^BOLD%^%^RED%^es%^RESET%^%^BOLD%^%^WHITE%^, %^RESET%^%^ORANGE%^"+
"tulips%^RESET%^%^BOLD%^%^WHITE%^, lillies, %^RESET%^%^YELLOW%^daffodils%^RESET%^"+
"%^BOLD%^%^WHITE%^, and more %^RESET%^%^BOLD%^%^MAGENTA%^ex%^RESET%^%^MAGENTA%^o"+
"%^RESET%^%^BOLD%^%^MAGENTA%^tic orchi%^RESET%^%^MAGENTA%^d%^RESET%^%^BOLD%^"+
"%^MAGENTA%^s %^RESET%^%^BOLD%^%^WHITE%^and mixed in with a variety of %^RESET%^"+
"%^BOLD%^%^GREEN%^greenery%^RESET%^%^BOLD%^%^WHITE%^. The flowers are in perfect"+
" health%^RESET%^",
({"floor","carpet"}) : "%^RESET%^%^BOLD%^%^RED%^The floor is covered in a deep "+
"rich red carpet. Even though people walk back and forth constantly the carpet "+
"is perfectly clean and without any tears%^RESET%^",
({"chandelier"}) : "%^RESET%^%^BOLD%^%^WHITE%^A cr%^RESET%^%^WHITE%^y%^RESET%^"+
"%^BOLD%^%^WHITE%^stal chand%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^lier"+
" hangs from the ceiling providing illumination from several g%^RESET%^%^BOLD%^"+
"%^MAGENTA%^l%^RESET%^%^BOLD%^%^WHITE%^owing c%^RESET%^%^BOLD%^%^MAGENTA%^r"+
"%^RESET%^%^BOLD%^%^WHITE%^ysta%^RESET%^%^MAGENTA%^l%^RESET%^%^BOLD%^%^WHITE%^"+
"s. However, the light provided by the crystals is anything but ordinary. As "+
"it touches you, you feel a tingle spread through your body. %^RESET%^",
({"sign"}) : "%^RESET%^%^ORANGE%^A small sign sits on the desk\n\n "+
"%^RESET%^%^YELLOW%^**************************************************\n%^RESET%^%^ORANGE%^"+
"The Free Merchant Exchange does not tolerate violence. Weapons will stay sheathed, and any "+
"violence acted in the Free Merchant's Exchange will be dealt with to the fullest extent "+
"of our resources.\n"+ 
"                     %^RESET%^%^BOLD%^%^WHITE%^Dougan Frost, Commander"+
" %^RESET%^%^BOLD%^%^BLACK%^Dragoon Irregulars%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell dark wood.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^You hear the shouts from the trading floor.%^RESET%^");

    set_door("glass door",ROOMS"entrance","south",0);
    set_door_description("glass door","%^RESET%^%^BOLD%^Although the frame for this"+
" door is %^RESET%^%^ORANGE%^heavy oak%^RESET%^%^BOLD%^, it is dominated by a beautifull"+
" pane of glass that allows light to pass through.");
    set_string("glass door", "open", "%^RESET%^%^CYAN%^The glass door opens silently.%^RESET%^");
    set_string("glass door", "close", "%^RESET%^%^CYAN%^The glass door closes silently.%^RESET%^%^BOLD%^");

}

void reset(){
    ::reset();
    if(!present("dougan")){new(MOBS"dougan.c")->move(TO);}
}
