// Chernobog (1/23/21)
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
    set_name("The Duchal Suite");
    set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^h%^BOLD%^e D%^RESET%^%^ORANGE%^u%^BOLD%^"+
        "%^BLACK%^ch%^RESET%^%^ORANGE%^a%^BOLD%^l S%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^"+
        "i%^RESET%^%^ORANGE%^t%^BOLD%^e%^RESET%^");
    set_long("%^RESET%^The massive %^ORANGE%^canopy bed %^WHITE%^draws attention, "+
        "easily taking up half the room. A %^BOLD%^sil%^RESET%^k%^BOLD%^en %^RESET%^c"+
        "%^BOLD%^an%^RESET%^o%^BOLD%^py %^RESET%^drapes from the four thick posts "+
        "of the bed, and piles of %^YELLOW%^p%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^llo"+
        "%^RESET%^%^ORANGE%^w%^BOLD%^s %^RESET%^and %^YELLOW%^b%^RESET%^%^ORANGE%^l"+
        "%^BOLD%^%^BLACK%^anke%^RESET%^%^ORANGE%^t%^BOLD%^s %^RESET%^cover its "+
        "expanse. It rests upon a thick %^BOLD%^%^BLACK%^ebon rug %^RESET%^that "+
        "covers most of the %^ORANGE%^flo%^RED%^o%^ORANGE%^r %^WHITE%^and silences "+
        "most footfalls. Gazing up at the ceiling, you see a plethora of tiny %^BOLD%^"+
        "%^CYAN%^s%^RESET%^l%^BOLD%^%^CYAN%^i%^WHITE%^v%^CYAN%^e%^RESET%^r%^BOLD%^"+
        "%^CYAN%^s %^RESET%^of %^BOLD%^%^CYAN%^cr%^WHITE%^y%^CYAN%^st%^RESET%^a"+
        "%^BOLD%^%^CYAN%^l%^RESET%^, quietly illuminating the room like the stars in "+
        "a %^MAGENTA%^night sky%^RESET%^.\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is pleasantly quiet in here.");
    set_items(([
        "bed" : "%^RESET%^%^CYAN%^This bed is absolutely gigantic. Supported on a "+
            "platform that requires a %^ORANGE%^small %^BOLD%^c%^RESET%^%^ORANGE%^u"+
            "%^BOLD%^%^BLACK%^shion%^RESET%^%^ORANGE%^e%^BOLD%^d %^RESET%^%^ORANGE%^"+
            "step %^CYAN%^stool to mount, the mattress is large enough to suit easily "+
            "half a dozen guests. The soft downy bed is covered in smooth %^BOLD%^"+
            "%^BLACK%^sil%^WHITE%^k%^RESET%^e%^BOLD%^%^BLACK%^n %^RESET%^%^CYAN%^"+
            "sheets and thick comforters, and a mound of pillows rests before the "+
            "headboard. All are in the official %^YELLOW%^T%^RESET%^%^ORANGE%^o"+
            "%^BOLD%^%^BLACK%^no%^RESET%^%^ORANGE%^v%^BOLD%^i H%^RESET%^%^ORANGE%^o"+
            "%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^l %^RESET%^%^CYAN%^livery, "+
            "%^BOLD%^%^BLACK%^ebon black %^RESET%^%^CYAN%^with glimmering %^ORANGE%^g"+
            "%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^n %^BOLD%^t%^WHITE%^r"+
            "%^ORANGE%^i%^RESET%^%^ORANGE%^m%^CYAN%^. The headboard itself is an "+
            "impressive piece of art, a solid piece of %^ORANGE%^oak %^CYAN%^that has "+
            "a been carved with a relief of a quiet forest glade. The four posts of "+
            "the bed rise up at the primary corners, supporting a grand %^WHITE%^s"+
            "%^BOLD%^i%^RESET%^l%^BOLD%^ken c%^RESET%^a%^BOLD%^n%^RESET%^o%^BOLD%^py"+
            "%^RESET%^%^CYAN%^.%^RESET%^",
        ({"wardrobe", "chest", "drawers"}) : "%^RESET%^%^CYAN%^The wardrobe has been "+
            "crafted carefully, opening and closing silently on %^ORANGE%^o%^BOLD%^i"+
            "%^WHITE%^l%^ORANGE%^e%^RESET%^%^ORANGE%^d %^CYAN%^hinges. Next to it, a "+
            "large chest of drawers is waiting to be filled by the next guest. Both "+
            "have been crafted from warm %^ORANGE%^m%^RED%^a%^ORANGE%^hog%^RED%^a"+
            "%^ORANGE%^ny%^CYAN%^, and have a similar scrollwork carved into their "+
            "frame.%^RESET%^",
        ({"floor", "rug"}) : "%^RESET%^%^CYAN%^The floors are a warm %^ORANGE%^ma%^RED%^"+
            "h%^ORANGE%^oag%^RED%^a%^ORANGE%^ny%^CYAN%^, polished and burnished to a "+
            "shine. Central to the room and supporting the massive %^ORANGE%^canopy bed"+
            "%^CYAN%^, a thick rug spreads to cover most of the floor. It is a %^BOLD%^"+
            "%^BLACK%^deep black%^RESET%^%^CYAN%^, with an intricate and flowing border "+
            "picked out in %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^"+
            "n t%^BOLD%^hr%^WHITE%^e%^ORANGE%^a%^RESET%^%^ORANGE%^d.%^RESET%^",
        ({"glowstones", "crystals", "ceiling"}) : "%^RESET%^%^CYAN%^A myriad of "+
            "%^BOLD%^t%^WHITE%^i%^CYAN%^n%^RESET%^y %^BOLD%^%^CYAN%^cr%^WHITE%^y"+
            "%^CYAN%^s%^RESET%^t%^BOLD%^%^CYAN%^a%^WHITE%^l%^CYAN%^s %^RESET%^%^CYAN%^"+
            "hover near the ceiling, shedding a soft %^BOLD%^%^WHITE%^il%^RESET%^l"+
            "%^BOLD%^um%^RESET%^a%^BOLD%^nes%^RESET%^c%^BOLD%^en%^RESET%^c%^BOLD%^e "+
            "%^RESET%^%^CYAN%^to the room from above like the stars of the %^BOLD%^"+
            "%^BLACK%^night sky%^RESET%^%^CYAN%^. The same magic that holds them "+
            "aloft also cause them to respond to your %^BOLD%^gesture%^RESET%^"+
            "%^CYAN%^s.%^RESET%^",
        ]));
    set_exits(([
        "east" : ROOMS "drawing_room",
        "bathroom" : ROOMS "bathroom",
        ]));
}

void init(){
    ::init();
    add_action("gesture_fun", "gesture");
}

int gesture_fun(str){
    if((str!="upwards") && (str!="downwards")){
        write("%^RESET%^The lights seem to respond when you %^BOLD%^gesture upwards "+
            "%^RESET%^or %^BOLD%^downwards%^RESET%^.");
        return 1;
    }        
    switch(str){
        case "upwards":
            if((int)TO->query_property("light") > 5){
                write("The crystals do not seem able to go any brighter.");
                return 1;
            }
            else{
                tell_object(TP,"%^BOLD%^%^BLACK%^The crystals %^WHITE%^inc%^RESET%^r"+
                    "%^BOLD%^ea%^RESET%^s%^BOLD%^e %^BLACK%^their %^WHITE%^rad"+
                    "%^RESET%^i%^BOLD%^an%^RESET%^c%^BOLD%^e %^BLACK%^at your gesture."+
                    "%^RESET%^");
                tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^gestures, "+
                    "and the crystals %^WHITE%^inc%^RESET%^r%^BOLD%^ea%^RESET%^s"+
                    "%^BOLD%^e %^BLACK%^their %^WHITE%^ra%^RESET%^d%^BOLD%^ia%^RESET%^"+
                    "n%^BOLD%^ce%^BLACK%^.%^RESET%^",TP);
                set_property("light",1);
                return 1;
            }
            break;
        case "downwards":
            if((int)TO->query_property("light") < 1){
                write("The crystals do not seem able to go any darker.");
                return 1;
            }
            else{
                tell_object(TP,"%^BOLD%^%^BLACK%^The crystals %^RESET%^%^MAGENTA%^d"+
                    "%^BOLD%^e%^RESET%^%^MAGENTA%^cr%^BOLD%^ea%^RESET%^%^MAGENTA%^se "+
                    "%^BOLD%^%^BLACK%^their %^WHITE%^ra%^RESET%^d%^BOLD%^ia%^RESET%^n"+
                    "%^BOLD%^ce %^BLACK%^at your gesture.%^RESET%^");
                tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^gestures, "+
                    "and the crystals %^RESET%^%^MAGENTA%^d%^BOLD%^e%^RESET%^"+
                    "%^MAGENTA%^cr%^BOLD%^ea%^RESET%^%^MAGENTA%^se %^BOLD%^%^BLACK%^"+
                    "their %^WHITE%^ra%^RESET%^d%^BOLD%^ia%^RESET%^n%^BOLD%^ce"+
                    "%^BLACK%^.%^RESET%^",TP);
                set_property("light",-1);
                return 1;
            }
            break;
        default:
            return 0;
    }
}

