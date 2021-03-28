// Chernobog (1/5/21)
// Tonovi Hotel

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
    set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e"+
        "%^BOLD%^l L%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^un%^RESET%^%^ORANGE%^g%^BOLD%^"+
        "e%^RESET%^");
    set_long("%^RESET%^Peering through a vague %^BOLD%^%^BLACK%^haze %^RESET%^of "+
        "%^BOLD%^%^BLACK%^smoke%^RESET%^, you can see a comfortable study repleat with "+
        "stacked bookshelves and a large %^ORANGE%^w%^RED%^e%^BOLD%^l%^RESET%^"+
        "%^ORANGE%^c%^RED%^o%^BOLD%^m%^RESET%^%^ORANGE%^i%^RED%^n%^BOLD%^g f%^ORANGE%^"+
        "i%^RED%^r%^ORANGE%^e%^RED%^pl%^ORANGE%^a%^RED%^c%^ORANGE%^e%^RESET%^. An "+
        "assortment of %^MAGENTA%^ru%^RED%^g%^MAGENTA%^s %^WHITE%^have been spread "+
        "about the middle of the room, with a half dozen %^ORANGE%^lounge chairs "+
        "%^WHITE%^placed in a semicircle. Each is accompanied by a small %^ORANGE%^"+
        "table %^WHITE%^to the side with a %^BOLD%^gl%^RESET%^a%^BOLD%^ss %^RESET%^a"+
        "%^BOLD%^sht%^RESET%^r%^BOLD%^ay%^RESET%^. An impressive %^BOLD%^%^MAGENTA%^p"+
        "%^RED%^o%^MAGENTA%^rtr%^RED%^a%^MAGENTA%^it %^RESET%^peers down from its "+
        "place above the mantle.\n");
    set_smell("default","Cigar smoke wafts lazily in the air.");
    set_listen("default","There is the occasional crackle and pop from the fireplace.");
    set_items(([
        ({"wall", "walls"}) : "%^RESET%^%^CYAN%^Uneven %^BOLD%^%^BLACK%^stones "+
            "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^WHITE%^"+
            "d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^"+
            "%^BLACK%^y %^RESET%^%^CYAN%^comprise these walls. The black stone is a "+
            "common element of Tonovi construction, mined from the north.",
        "rugs" : "%^RESET%^%^CYAN%^The %^ORANGE%^ma%^RED%^h%^ORANGE%^og%^RED%^a"+
            "%^ORANGE%^ny fl%^RED%^o%^ORANGE%^ors %^CYAN%^have been covered in several "+
            "thick rugs, spread throughout the room. They are %^YELLOW%^l%^RESET%^"+
            "%^ORANGE%^u%^BOLD%^xur%^RESET%^%^ORANGE%^i%^BOLD%^o%^RESET%^%^ORANGE%^u"+
            "%^BOLD%^s %^RESET%^%^CYAN%^and %^BOLD%^s%^WHITE%^o%^CYAN%^ft%^RESET%^"+
            "%^CYAN%^, though faded in the spots that are close to the %^BOLD%^%^RED%^"+
            "f%^ORANGE%^i%^RED%^r%^ORANGE%^e%^RED%^pl%^ORANGE%^a%^RED%^c%^ORANGE%^e"+
            "%^RESET%^%^CYAN%^.%^RESET%^",
        "fireplace" : "%^RESET%^%^CYAN%^A truly fantastic and grand focal point to the "+
            "room, the %^BOLD%^%^RED%^f%^ORANGE%^i%^RED%^r%^ORANGE%^e%^RED%^pl"+
            "%^ORANGE%^a%^RED%^c%^ORANGE%^e %^RESET%^%^CYAN%^takes up half of the far "+
            "wall. Comprised of the same %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and "+
            "%^WHITE%^d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e"+
            "%^BOLD%^%^BLACK%^y %^RESET%^stone %^CYAN%^as the walls, it features a "+
            "mantle running the length of it. A large %^BOLD%^%^MAGENTA%^p%^RED%^o"+
            "%^MAGENTA%^rtra%^RED%^i%^MAGENTA%^t %^RESET%^%^CYAN%^sits above the "+
            "mantle in a place of honor, seeming to dominate the room from its "+
            "position. Within a broad %^BOLD%^%^BLACK%^iron cage%^RESET%^%^CYAN%^, "+
            "a %^BOLD%^%^RED%^f%^ORANGE%^i%^RED%^r%^RESET%^%^ORANGE%^e %^CYAN%^burns "+
            "brightly from within the fireplace, with an occasional %^RED%^ember "+
            "%^CYAN%^wafting out into the room.%^RESET%^",
        "chairs" : "%^RESET%^%^CYAN%^These lounge chairs have been upholstered in "+
            "%^BOLD%^%^BLACK%^black leather %^RESET%^%^CYAN%^and set on %^ORANGE%^oak "+
            "frames%^CYAN%^. A collection of small buttons have been scattered along "+
            "the back, giving it some dimension and decor. Generously padded, they "+
            "would be most comfortable, warmed by the nearby fire.%^RESET%^",
        ({"painting", "portrait"}) : "%^RESET%^%^CYAN%^Framed in %^YELLOW%^g%^RESET%^"+
            "%^ORANGE%^i%^BOLD%^ld%^RESET%^%^ORANGE%^e%^BOLD%^d %^RESET%^%^ORANGE%^"+
            "oak%^CYAN%^, this portrait of the Duchess of Tonovi, Aesa Langenberg, "+
            "displays her strength and nobility in full. It hangs central above the "+
            "mantle, a place of %^BOLD%^honor %^RESET%^%^CYAN%^and %^BOLD%^respect"+
            "%^RESET%^%^CYAN%^.%^RESET%^",
        ({"books", "bookshelves"}) : "%^RESET%^%^CYAN%^A truly impressive collection "+
            "of books line the shelves, their %^MAGENTA%^a%^RED%^g%^MAGENTA%^e%^RED%^d "+
            "%^CYAN%^covers proclaiming a mix of %^BOLD%^history %^RESET%^%^CYAN%^and "+
            "fabricated %^BOLD%^%^GREEN%^fiction%^RESET%^%^CYAN%^. However, none of "+
            "them seem to have recently been moved. It is quite possible that this "+
            "grand repository of knowledge is purely for show.%^RESET%^",
        ({"table", "ashtray"}) : "%^RESET%^%^CYAN%^Every %^BOLD%^%^BLACK%^chair "+
            "%^RESET%^%^CYAN%^is accompanied by a three legged %^ORANGE%^table%^CYAN%^"+
            ". Each leg is slender and flares outward before curing in at the foot, "+
            "and the circular top is just wide enough to accommodate a small %^BOLD%^"+
            "%^WHITE%^g%^RESET%^l%^BOLD%^a%^CYAN%^s%^WHITE%^s a%^RESET%^s%^BOLD%^h"+
            "%^CYAN%^t%^WHITE%^r%^RESET%^a%^BOLD%^y %^RESET%^%^CYAN%^and room for a "+
            "drink of choice.%^RESET%^",
        ]));
    set_exits(([
        "hall" : ROOMS "hall",
        ]));
}

void reset(){
    ::reset();
    if(!present("waitress")) new(MON "samantha")->move(TO);
}

