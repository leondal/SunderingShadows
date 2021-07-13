// Chernobog (3/3/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Thoroughfare");
    set_short("Thoroughfare to the Coliseum");
    set_long("The %^ORANGE%^wooden %^WHITE%^and st%^BOLD%^o%^RESET%^ne buildings of Shadow give way to this thoroughfare, with a broad roadway that offers plenty of room for foot and cart traffic. Each side of the %^BOLD%^%^BLACK%^c%^WHITE%^o%^BLACK%^bb%^RESET%^l%^BOLD%^e%^BLACK%^st%^WHITE%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^street has been lined with %^GREEN%^t%^BOLD%^r%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^s%^RESET%^, their %^ORANGE%^b%^GREEN%^r%^ORANGE%^an%^GREEN%^c%^BOLD%^h%^RESET%^%^GREEN%^e%^ORANGE%^s %^WHITE%^reaching towards the other side of the street to form a relaxing %^GREEN%^c%^BOLD%^a%^RESET%^%^GREEN%^n%^BOLD%^op%^RESET%^%^GREEN%^y %^WHITE%^of vegetation. A large %^ORANGE%^structure %^WHITE%^looms in the distance to the northeast.\n%^RESET%^");
    set_smell("default","Your nose catches the miasma of thousands of humanoids in close proximity.");
    set_listen("default","You hear the dull roar of conversations as pedestrians and wagons rumble past.");
    set_items(([
        ({"street","avenue","road","roadway","pavers"}) : "%^BOLD%^%^BLACK%^The wide street allows for four horse-drawn wagons to travel abreast of each other. Thousands of octagonal %^RESET%^p%^BOLD%^av%^RESET%^e%^BOLD%^rs %^BLACK%^carved out of a fairly mundane %^RESET%^d%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^BLACK%^k %^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e %^BOLD%^%^BLACK%^compose the surface of the road. The center of the street is crested, with the edges slightly graded to provide runoff during %^RESET%^%^CYAN%^inclement weather%^BOLD%^%^BLACK%^.%^RESET%^",
        ({"trees","canopy"}) : "%^BOLD%^%^BLACK%^Aged %^RESET%^%^ORANGE%^o%^BOLD%^a%^RESET%^%^ORANGE%^k %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^m%^BOLD%^ap%^RESET%^%^ORANGE%^l%^BOLD%^e %^RESET%^%^GREEN%^t%^BOLD%^r%^RESET%^%^GREEN%^e%^ORANGE%^e%^BOLD%^%^GREEN%^s %^BLACK%^rise up on either side of the %^RESET%^r%^BOLD%^o%^RESET%^a%^BOLD%^dw%^RESET%^a%^BOLD%^y%^RESET%^s%^BOLD%^%^BLACK%^, their enlongated %^RESET%^%^ORANGE%^branches %^BOLD%^%^BLACK%^reaching across the street to provide a %^RESET%^%^CYAN%^cool %^BOLD%^%^BLACK%^and relaxing %^RESET%^%^GREEN%^c%^BOLD%^a%^RESET%^%^ORANGE%^n%^GREEN%^o%^BOLD%^py %^BLACK%^of %^RESET%^%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^en%^RESET%^%^GREEN%^e%^ORANGE%^r%^BOLD%^%^GREEN%^y%^BLACK%^.%^RESET%^",
        "structure" : "%^BOLD%^%^BLACK%^A large %^RESET%^%^ORANGE%^complex %^BOLD%^%^BLACK%^rises up to the northeast, the towering walls curved about in a circular structure. The top is pointed, with %^GREEN%^pe%^MAGENTA%^nn%^RED%^an%^ORANGE%^ts %^BLACK%^rising from flag poles like the tips of a %^ORANGE%^c%^RESET%^%^ORANGE%^r%^BOLD%^o%^RESET%^%^ORANGE%^w%^BOLD%^n%^BLACK%^. Two %^RESET%^%^ORANGE%^massive statues %^BOLD%^%^BLACK%^emerge from the entrance, raising their hands together like %^RESET%^%^RED%^o%^BOLD%^ff%^RESET%^%^RED%^e%^BOLD%^ri%^RESET%^%^RED%^n%^BOLD%^gs %^BLACK%^to the gods.%^RESET%^",
        "pennants" : "%^BOLD%^%^BLACK%^Triangular pennants stand at attention from f%^RESET%^la%^BOLD%^gpo%^RESET%^le%^BOLD%^%^BLACK%^s jutting up from the far wall of the %^RESET%^%^ORANGE%^coliseum%^BOLD%^%^BLACK%^. Each depicts a different %^WHITE%^s%^RESET%^i%^BOLD%^g%^RESET%^i%^BOLD%^l %^BLACK%^on various %^RESET%^%^MAGENTA%^f%^BOLD%^i%^RED%^el%^ORANGE%^d%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^, proclaiming the various %^RESET%^%^CYAN%^guilds %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^organizations %^BOLD%^%^BLACK%^with a vested interest in the coliseum.%^RESET%^",
        ]));
    set_exits(([
        "south" : "/d/shadow/city/room/shadway5.c",
        "northeast" : ROOMS"entrance",
        ]));
}

