// Chernobog (3/3/21)
// Shadow Coliseum

#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Thoroughfare");
    set_short("Thoroughfare to the Coliseum");
    set_long("%^RESET%^The %^ORANGE%^wooden %^WHITE%^and st%^BOLD%^o%^RESET%^ne buildings of Shadow give way to this thoroughfare, with a broad roadway that offers plenty of room for foot and cart traffic. Each side of the %^BOLD%^%^BLACK%^c%^WHITE%^o%^BLACK%^bb%^RESET%^l%^BOLD%^e%^BLACK%^st%^WHITE%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^street has been lined with %^GREEN%^t%^BOLD%^r%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^s%^RESET%^, their %^ORANGE%^b%^GREEN%^r%^ORANGE%^an%^GREEN%^c%^BOLD%^h%^RESET%^%^GREEN%^e%^ORANGE%^s %^WHITE%^reaching towards the other side of the street to form a relaxing %^GREEN%^c%^BOLD%^a%^RESET%^%^GREEN%^n%^BOLD%^op%^RESET%^%^GREEN%^y %^WHITE%^of vegetation.\n\n%^CYAN%^This thoroughfare leads from the West Wall Road towards a large construction project to the northeast. There is a near constant flow of stone and mortar being delivered, with all manner of lifts, cranes, and scaffolding in place.%^RESET%^\n");
    set_smell("default","Your nose catches the miasma of thousands of humanoids in close proximity.");
    set_listen("default","You hear the dull roar of conversations as pedestrians and wagons rumble past.");
    set_items(([
        ({"street","avenue","road","roadway","pavers"}) : "The wide street allows for four horse-drawn wagons to travel abreast of each other. Thousands of octagonal pavers carved out of a fairly mundane dark stone compose the surface of the road. The center of the street is crested, with the edges slightly graded to provide runoff during inclement weather.",
        ]));
    set_exits(([
        "south" : "/d/shadow/city/room/shadway5.c",
        ]));
}

