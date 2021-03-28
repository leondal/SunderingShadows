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
    set_name("Hotel Main Hall");
    set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e"+
        "%^BOLD%^l M%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^i%^ORANGE%^n H%^RESET%^"+
        "%^ORANGE%^a%^BOLD%^%^BLACK%^l%^ORANGE%^l%^RESET%^");
    set_long("%^RESET%^The main hall of the hotel features an arched ceiling, "+
        "showcasing an opulent %^BOLD%^cr%^RESET%^y%^BOLD%^s%^CYAN%^t%^WHITE%^all"+
        "%^RESET%^i%^BOLD%^n%^CYAN%^e %^WHITE%^c%^CYAN%^h%^WHITE%^a%^RESET%^n%^BOLD%^"+
        "d%^CYAN%^e%^WHITE%^l%^RESET%^i%^BOLD%^er%^RESET%^. A %^BOLD%^%^RED%^d"+
        "%^RESET%^%^RED%^a%^BOLD%^rk r%^RESET%^%^RED%^e%^BOLD%^d c%^RESET%^%^RED%^a"+
        "%^BOLD%^rp%^RESET%^%^RED%^e%^BOLD%^t %^RESET%^runs the length of the room, "+
        "from the %^YELLOW%^f%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^"+
        "e%^BOLD%^r %^RESET%^all the way to the %^YELLOW%^g%^RESET%^%^ORANGE%^r"+
        "%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n%^BOLD%^d s%^RESET%^%^ORANGE%^t%^BOLD%^"+
        "%^BLACK%^airca%^RESET%^%^ORANGE%^s%^BOLD%^e %^RESET%^at the southern end of "+
        "the hall. An archway to the west leads into a proper %^YELLOW%^r%^RESET%^"+
        "%^ORANGE%^e%^BOLD%^%^BLACK%^staura%^RESET%^%^ORANGE%^n%^BOLD%^t%^RESET%^, "+
        "while another archway to the east appears to lead into a %^YELLOW%^l%^RESET%^"+
        "%^ORANGE%^o%^BOLD%^%^BLACK%^un%^RESET%^%^ORANGE%^g%^BOLD%^e%^RESET%^. "+
        "%^GREEN%^P%^BOLD%^a%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^n%^RESET%^%^CYAN%^t"+
        "%^BOLD%^i%^WHITE%^n%^CYAN%^g%^RESET%^%^CYAN%^s %^WHITE%^continue to decorate "+
        "the %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne w%^RESET%^a%^BOLD%^"+
        "%^BLACK%^lls%^RESET%^, and the accompanying %^GREEN%^p%^BOLD%^l%^RESET%^"+
        "%^ORANGE%^a%^GREEN%^n%^BOLD%^t%^RESET%^%^GREEN%^s %^WHITE%^break the monotony"+
        " from their %^ORANGE%^ce%^RED%^ra%^ORANGE%^mi%^RED%^c p%^ORANGE%^ot%^RED%^s"+
        "%^RESET%^.\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","You hear the gentle susurrus of patrons coming and going.");
    set_items(([
        ({"wall", "walls"}) : "%^RESET%^%^CYAN%^Uneven %^BOLD%^%^BLACK%^stones "+
            "%^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^WHITE%^"+
            "d%^BOLD%^%^BLACK%^a%^RESET%^rk %^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^"+
            "%^BLACK%^y %^RESET%^%^CYAN%^comprise these walls. The black stone is a "+
            "common element of Tonovi construction, mined from the north. %^BOLD%^"+
            "%^MAGENTA%^P%^WHITE%^a%^MAGENTA%^i%^RED%^n%^RESET%^%^RED%^t%^ORANGE%^in"+
            "%^BOLD%^g%^WHITE%^s %^RESET%^%^CYAN%^and large potted %^GREEN%^f%^BOLD%^e"+
            "%^RESET%^%^ORANGE%^r%^GREEN%^n%^BOLD%^s %^RESET%^%^CYAN%^partially "+
            "obfuscate the expanse of the walls.%^RESET%^",
        "paintings" : "%^RESET%^%^CYAN%^Fine paintings are spaced along the walls, "+
            "offering a point of interest among the %^BOLD%^%^BLACK%^da%^RESET%^r"+
            "%^BOLD%^%^BLACK%^k st%^RESET%^o%^BOLD%^%^BLACK%^ne w%^RESET%^a%^BOLD%^"+
            "%^BLACK%^lls%^RESET%^%^CYAN%^. Though often %^GREEN%^l%^BOLD%^a%^RESET%^"+
            "%^ORANGE%^n%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^sc%^BOLD%^%^CYAN%^a"+
            "%^WHITE%^p%^CYAN%^e%^RESET%^%^GREEN%^s %^CYAN%^of the great city of Tonovi"+
            " or the outlying fields of the Tonovi plantations, there are a few %^RED%^"+
            "b%^BOLD%^a%^RESET%^%^RED%^t%^MAGENTA%^t%^RED%^l%^BOLD%^e%^RESET%^%^RED%^f"+
            "%^BOLD%^ie%^RESET%^%^RED%^l%^MAGENTA%^d %^CYAN%^depictions of soldiers "+
            "%^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^a%^RESET%^s%^BOLD%^%^BLACK%^h%^RESET%^"+
            "i%^BOLD%^n%^RESET%^g%^CYAN%^. Of particular favor with these are victories"+
            " over Tormish ranks.%^RESET%^",
        "floor" : "%^RESET%^%^CYAN%^Solid %^ORANGE%^m%^RED%^a%^ORANGE%^h%^RED%^o"+
            "%^ORANGE%^g%^RED%^a%^ORANGE%^ny %^CYAN%^floorboards lay beneath your feet"+
            ", the %^ORANGE%^r%^RED%^e%^ORANGE%^dd%^RED%^i%^ORANGE%^sh %^CYAN%^hue of "+
            "the wood polished to an impressive %^BOLD%^%^BLACK%^sh%^RESET%^ee%^BOLD%^n"+
            "%^RESET%^%^CYAN%^.%^RESET%^",
        ({"plants", "ferns"}) : "%^RESET%^%^CYAN%^Large, expansive %^GREEN%^f%^BOLD%^e"+
            "%^RESET%^%^ORANGE%^r%^GREEN%^n%^BOLD%^s %^RESET%^%^CYAN%^are located along"+
            " the walls. They have been planted in large %^RED%^sp%^ORANGE%^he%^RED%^"+
            "ri%^ORANGE%^ca%^RED%^l p%^ORANGE%^ot%^RED%^s%^CYAN%^, which have been "+
            "painted in alternating bands of %^ORANGE%^ochre %^CYAN%^and %^RED%^red"+
            "%^CYAN%^.%^RESET%^",
        "carpet" : "%^RESET%^%^RED%^De%^BOLD%^e%^RESET%^%^RED%^p %^CYAN%^and %^RED%^d"+
            "%^BOLD%^a%^RESET%^%^RED%^rk r%^BOLD%^e%^RESET%^%^RED%^d%^CYAN%^, this "+
            "thick carpet runs the length of the room and into the adjourning hall. An "+
            "intricate %^YELLOW%^g%^WHITE%^o%^ORANGE%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n "+
            "p%^WHITE%^a%^ORANGE%^t%^RESET%^%^ORANGE%^t%^BOLD%^e%^WHITE%^r%^ORANGE%^n "+
            "%^RESET%^%^CYAN%^has been set into the borders of the carpet, a woven "+
            "series of swirls and wave-like ripples.%^RESET%^",
        "chandelier" : "%^RESET%^%^CYAN%^Suspended from the arched ceiling of the "+
            "main hall, this grandiose %^BOLD%^%^WHITE%^ch%^RESET%^a%^BOLD%^n%^ORANGE%^"+
            "d%^WHITE%^el%^RESET%^i%^BOLD%^er %^RESET%^%^CYAN%^has been fashioned from "+
            "hundreds of small %^BOLD%^%^WHITE%^c%^RESET%^r%^BOLD%^y%^CYAN%^s%^WHITE%^t"+
            "%^RESET%^a%^BOLD%^l s%^CYAN%^h%^WHITE%^ar%^RESET%^d%^BOLD%^s%^RESET%^"+
            "%^CYAN%^. Each shard is about the size of a coin, and has been ensnared "+
            "in a clever enchantment to lazily swirl around a gently %^WHITE%^g"+
            "%^BOLD%^l%^ORANGE%^o%^WHITE%^win%^RESET%^g %^CYAN%^spherical centerpiece. "+
            "The chandelier %^BOLD%^sparkles %^RESET%^%^CYAN%^and %^BOLD%^glitters "+
            "%^RESET%^%^CYAN%^as the light is %^BOLD%^%^WHITE%^fr%^RESET%^a%^BOLD%^gm"+
            "%^RESET%^e%^BOLD%^nt%^RESET%^e%^BOLD%^d %^RESET%^%^CYAN%^and %^BOLD%^"+
            "%^RED%^r%^ORANGE%^e%^RESET%^%^ORANGE%^f%^BOLD%^%^GREEN%^r%^CYAN%^a%^BLUE%^"+
            "c%^MAGENTA%^t%^RED%^e%^ORANGE%^d %^RESET%^%^CYAN%^through each glimmering "+
            "%^BOLD%^%^WHITE%^c%^RESET%^r%^BOLD%^y%^CYAN%^s%^WHITE%^t%^RESET%^a%^BOLD%^"+
            "l%^RESET%^%^CYAN%^.%^RESET%^",
        ]));
    set_exits(([
        "foyer" : ROOMS "foyer",
        "restaurant" : ROOMS "restaurant",
        "lounge" : ROOMS "lounge",
        "staircase" : ROOMS "stairs1",
        ]));
}

