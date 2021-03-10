#include <std.h> 
inherit ROOM; 

void create() { 
    ::create(); 
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(RUTTED_TRACK);
    set_name("Office");
    set_short("%^YELLOW%^Office%^RESET%^"); 
    set_long("A large %^BLUE%^b%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^u%^BOLD%^"
"%^BLUE%^e %^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^g "
"%^RESET%^that is surrounded by %^ORANGE%^wooden chairs%^RESET%^. There are "
"two %^YELLOW%^desks%^RESET%^ that dominate the floor of this room, one of "
"which looks to be made for a %^BOLD%^%^CYAN%^human%^RESET%^, and the other "
"much %^MAGENTA%^smaller%^RESET%^. A few torches are set into the walls to "
"bring %^YELLOW%^f%^RESET%^l%^ORANGE%^i%^BOLD%^%^BLACK%^c%^YELLOW%^k%^RESET%^"
"e%^BOLD%^%^WHITE%^r%^BLACK%^i%^YELLOW%^n%^RESET%^%^ORANGE%^g%^RESET%^ light "
"to the area. A few shelves line the walls although they are left mostly "
"empty. This room is quite clean, having been recently swept.");
    set_smell("default","%^ORANGE%^The smell of %^BOLD%^%^BLACK%^ink%^RESET%^ "
"%^ORANGE%^and %^BOLD%^%^WHITE%^paper%^RESET%^%^ORANGE%^ are very heavy in "
"this room."); 
    set_listen("default","The sounds of people can be heard all around here.");
    set_items(([ 
      "desks":"These well made %^BOLD%^ORANGE%^desks%^RESET%^ are covered in "
"papers.",
    ])); 
    set_exits(([ 
      "west":"/d/guilds/order/hall/main"
    ])); 
}
