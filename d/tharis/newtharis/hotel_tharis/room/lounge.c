// Chernobog (9/6/21)
// Tharis Hotel

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Hotel Lounge");
    set_short("%^MAGENTA%^H%^BOLD%^%^BLACK%^ote%^RESET%^%^MAGENTA%^l L%^BOLD%^%^BLACK%^oung%^RESET%^%^MAGENTA%^e%^WHITE%^");
    set_long("%^BOLD%^%^BLACK%^This is a comfortable study replete with a well-stocked %^RESET%^bar%^BOLD%^%^BLACK%^, a wall of built-in %^RESET%^bookshelves%^BOLD%^%^BLACK%^, and a large welcoming %^WHITE%^f%^RESET%^i%^BOLD%^r%^RESET%^e%^BOLD%^pl%^RESET%^a%^BOLD%^c%^RESET%^e%^BOLD%^%^BLACK%^. An assortment of %^RESET%^%^MAGENTA%^pl%^BOLD%^u%^BLACK%^s%^RESET%^%^MAGENTA%^h r%^BOLD%^u%^BLACK%^g%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^have been spread about the middle of the room, with a half dozen lounge chairs placed in a semicircle. Each is accompanied by a small ebony wood side table with a coaster and s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er a%^RESET%^s%^BOLD%^h%^BLACK%^tr%^RESET%^a%^BOLD%^%^BLACK%^y. An impressive %^RESET%^portrait %^BOLD%^%^BLACK%^peers down from its place above the mantle. In one corner of the room a fine %^RESET%^stage %^BOLD%^%^BLACK%^has been erected for %^RESET%^%^CYAN%^p%^BOLD%^e%^RESET%^%^CYAN%^rf%^BOLD%^o%^RESET%^%^CYAN%^rm%^BOLD%^a%^RESET%^%^CYAN%^nc%^BOLD%^e%^RESET%^%^CYAN%^s %^BOLD%^%^BLACK%^and live %^RESET%^m%^BOLD%^u%^RESET%^s%^BOLD%^i%^RESET%^c%^BOLD%^%^BLACK%^.%^RESET%^\n");
    set_smell("default","Cigar smoke wafts lazily in the air.");
    set_listen("default","There is the occasional crackle and pop from the fireplace.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
        "rugs" : "%^RESET%^The %^BOLD%^%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^ny fl%^RESET%^o%^BOLD%^o%^BLACK%^rs %^RESET%^have been covered in several thick %^MAGENTA%^r%^BOLD%^u%^BLACK%^g%^RESET%^%^MAGENTA%^s%^WHITE%^, spread throughout the room. They are %^MAGENTA%^luxurious %^WHITE%^and %^BOLD%^%^MAGENTA%^soft%^RESET%^, though faded in the spots that are close to the %^BOLD%^fireplace%^RESET%^.",
        "fireplace" : "%^RESET%^A truly fantastic and grand focal point to the room, the %^BOLD%^fireplace %^RESET%^dominates the corner opposite the stage. Unlike the rest of the walls, the fireplace has been constructed from %^BOLD%^gl%^RESET%^i%^BOLD%^tt%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^ng wh%^RESET%^i%^BOLD%^t%^RESET%^e %^BOLD%^qu%^RESET%^ar%^BOLD%^tz %^RESET%^and features a mantle of %^BOLD%^%^BLACK%^ebony wood%^RESET%^. A large %^BOLD%^portrait %^RESET%^sits above the %^BOLD%^%^BLACK%^mantle %^RESET%^in a place of honor, seeming to dominate the room from its position. Within a broad %^BOLD%^%^BLACK%^iron cage, %^RESET%^a %^BOLD%^%^RED%^f%^ORANGE%^i%^RESET%^%^RED%^r%^BOLD%^e b%^RESET%^%^ORANGE%^u%^RED%^r%^BOLD%^ns %^RESET%^brightly, an occasional %^BOLD%^%^RED%^e%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^b%^RESET%^%^RED%^e%^BOLD%^r %^RESET%^wafting out into the room.%^RESET%^",
        ({"painting", "portrait"}) : "%^RESET%^This %^BOLD%^%^BLACK%^o%^RESET%^i%^BOLD%^%^BLACK%^l p%^RESET%^a%^BOLD%^i%^BLACK%^nt%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^depicts an %^BOLD%^i%^BLACK%^n%^RESET%^t%^BOLD%^i%^BLACK%^m%^WHITE%^i%^RESET%^dat%^BOLD%^i%^BLACK%^n%^RESET%^g figure of %^BLUE%^pure darkness%^WHITE%^. Clad in elaborate and ancient armor this being stands proudly, features of %^BOLD%^%^BLACK%^pure obsidian %^CYAN%^gl%^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^%^CYAN%^i%^BOLD%^ng imp%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^i%^BOLD%^ously %^RESET%^from beneath a jagged %^BOLD%^%^BLACK%^cr%^RESET%^o%^BOLD%^%^BLACK%^wn %^RESET%^of %^BOLD%^%^BLACK%^Adamantine%^RESET%^. Grasped between his %^RED%^cl%^BOLD%^a%^RESET%^%^RED%^w %^WHITE%^like %^BOLD%^%^BLACK%^gauntlets%^RESET%^, point toward the ground, is a %^RED%^d%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^m%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^i%^RESET%^%^RED%^c gr%^BOLD%^%^BLACK%^e%^RED%^a%^RESET%^%^RED%^t sw%^BOLD%^o%^RESET%^%^RED%^rd%^WHITE%^, a vortex of %^BLUE%^dark energy %^WHITE%^rising up around its %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^de%^RESET%^. Below the portrait a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er pl%^RESET%^a%^BOLD%^%^BLACK%^q%^WHITE%^u%^RESET%^e reads in flowing script: %^BOLD%^%^BLACK%^Lord Shadow%^RESET%^",
        ({"books", "bookshelves"}) : "%^RESET%^A truly impressive collection of %^BOLD%^books %^RESET%^lines the %^BOLD%^%^BLACK%^shelves%^RESET%^, their %^ORANGE%^aged covers %^WHITE%^proclaiming a mix of history and fiction. ",
        ({"table", "ashtray", "chairs"}) : "%^RESET%^These %^BOLD%^%^BLACK%^lounge chairs %^RESET%^have been upholstered in %^BOLD%^%^BLACK%^black leather %^RESET%^and set on %^BOLD%^%^BLACK%^ebony frames%^RESET%^. Every chair is accompanied by a three-legged side %^BOLD%^%^BLACK%^table %^RESET%^large enough to accommodate a small %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er a%^RESET%^s%^BOLD%^h%^BLACK%^tr%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^and a drink of choice.%^RESET%^",
        "floor" : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^.",
        "stage" : "%^RESET%^Constructed from %^BOLD%^%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^ny t%^RESET%^i%^BOLD%^%^BLACK%^mb%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^harvested from the %^GREEN%^Th%^BOLD%^a%^RESET%^%^GREEN%^r%^BOLD%^i%^RESET%^%^GREEN%^s F%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^st%^WHITE%^, this raised %^BOLD%^%^BLACK%^dais %^RESET%^provides an area for %^ORANGE%^musicians %^WHITE%^and %^CYAN%^performers %^WHITE%^to entertain the patrons of the lounge. Thick, crushed velvet curtains of %^MAGENTA%^deep violet %^WHITE%^line the stage and provide a private place for preparations, costume changes, and storage.%^RESET%^",
        ]));
    set_exits(([
        "hall" : ROOMS "hall",
        ]));
}

void reset(){
    ::reset();
    if(!present("waitress")) new(MON "natalie")->move(TO);
}

