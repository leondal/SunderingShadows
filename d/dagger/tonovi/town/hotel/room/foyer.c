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
    set_name("Hotel Foyer");
    set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^no%^RESET%^%^ORANGE%^v"+
        "%^BOLD%^i H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^"+
        "l F%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^BOLD%^r"+
        "%^RESET%^");
    set_long("%^RESET%^The main entrance to the grand %^YELLOW%^T%^RESET%^%^ORANGE%^o"+
        "%^BOLD%^%^BLACK%^vo%^RESET%^%^ORANGE%^n%^BOLD%^i H%^RESET%^%^ORANGE%^o%^BOLD%^"+
        "%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^l %^RESET%^is a sight to behold. The "+
        "%^BOLD%^%^BLACK%^stone walls %^RESET%^are a %^BOLD%^%^BLACK%^m%^RESET%^o"+
        "%^BOLD%^%^BLACK%^tt%^RESET%^l%^BOLD%^%^BLACK%^ed %^RESET%^mix of black and "+
        "dark gray, mortared together with a sense of ordered chaos. Interspersed along"+
        " the walls are %^ORANGE%^l%^RED%^a%^ORANGE%^rge ur%^RED%^n%^ORANGE%^s "+
        "%^WHITE%^supporting %^GREEN%^e%^BOLD%^x%^RESET%^%^ORANGE%^p%^GREEN%^a%^BOLD%^n"+
        "s%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^e %^BOLD%^f%^RESET%^%"+
        "^ORANGE%^e%^BOLD%^%^GREEN%^rn%^RESET%^%^GREEN%^s%^WHITE%^, and exquisite pain"+
        "tings decorate the empty spaces between. A %^BOLD%^%^RED%^d%^RESET%^%^RED%^a"+
        "%^BOLD%^rk r%^RESET%^%^RED%^e%^BOLD%^d c%^RESET%^%^RED%^a%^BOLD%^rp%^RESET%^"+
        "%^RED%^e%^BOLD%^t %^RESET%^lines the center of the walkway over ruddy "+
        "%^ORANGE%^mahogany floors%^WHITE%^. To the side is a large and intricate front"+
        " desk, complete with a ledger and %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv"+
        "%^RESET%^e%^BOLD%^%^BLACK%^r b%^WHITE%^e%^RESET%^l%^BOLD%^%^BLACK%^l%^RESET%^.\n");
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
        ({"desk", "ledger", "bell"}) : "%^RESET%^%^CYAN%^There is a large %^ORANGE%^oak"+
            "%^RED%^e%^ORANGE%^n front d%^RED%^e%^ORANGE%^sk %^CYAN%^here, with an "+
            "impressive scroll-work carved along the edges at top and bottom. Sitting "+
            "central upon it is a large %^ORANGE%^le%^BOLD%^a%^RESET%^%^ORANGE%^therbou"+
            "%^BOLD%^n%^RESET%^%^ORANGE%^d led%^BOLD%^g%^RESET%^%^ORANGE%^er %^CYAN%^"+
            "for registering guests, with an %^BOLD%^%^WHITE%^i%^BLACK%^nkw%^WHITE%^e"+
            "%^BLACK%^ll %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^q%^RESET%^u%^BOLD%^il"+
            "%^RESET%^l %^CYAN%^set just to the side. A gleaming %^BOLD%^%^BLACK%^s"+
            "%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^b%^BOLD%^e"+
            "%^RESET%^l%^BOLD%^%^BLACK%^l %^RESET%^%^CYAN%^rests at the edge of the "+
            "desk for guests to summon the receptionist.%^RESET%^",
        ]));
    set_exits(([
        "north" : "/d/dagger/tonovi/town/street5",
        "hall" : ROOMS "hall",
        ]));
}

void init(){
    ::init();
    add_action("ring_fun","ring");
}

int ring_fun(string str){
    if((str!="bell") && (str!="the bell"))
        return 0;
    else{
        tell_object(TP,"%^BOLD%^%^BLACK%^You ring the bell a few times, but there "+
            "doesn't seem to be anyone available to help you.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^impatiently "+
            "rings the bell a few times, to no effect.%^RESET%^",TP);
        return 1;
    }
}

