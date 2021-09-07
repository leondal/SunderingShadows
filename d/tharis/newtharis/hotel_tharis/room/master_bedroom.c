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
    set_name("The Grand Suite");
    set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^e G%^RESET%^%^MAGENTA%^ran%^BOLD%^%^BLACK%^d S%^RESET%^%^MAGENTA%^uit%^BOLD%^%^BLACK%^e%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The massive four poster bed draws attention, easily taking up half the room. A silken canopy drapes from the four thick posts of the bed, and piles of p%^RESET%^i%^BOLD%^%^BLACK%^ll%^RESET%^o%^BOLD%^%^BLACK%^ws and bl%^RESET%^a%^BOLD%^%^BLACK%^nk%^RESET%^e%^BOLD%^%^BLACK%^ts cover its expanse. It rests upon a thick %^RESET%^%^MAGENTA%^violet rug %^BOLD%^%^BLACK%^that covers a majority of the floor and %^RESET%^silences %^BOLD%^%^BLACK%^most footfalls. Gazing up at the ceiling, you see a plethora of tiny sl%^MAGENTA%^i%^BLACK%^vers of %^MAGENTA%^cr%^RESET%^%^MAGENTA%^y%^BOLD%^st%^RESET%^%^MAGENTA%^a%^BOLD%^l%^BLACK%^, like so many st%^MAGENTA%^a%^BLACK%^rs illuminating the %^RESET%^%^BLUE%^night sky%^BOLD%^%^BLACK%^.%^RESET%^\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","It is pleasantly quiet in here.");
    set_items(([
        "bed" : "%^RESET%^This four-poster bed is gigantic and shrouded in a %^BOLD%^%^BLACK%^black silken canopy %^RESET%^that creates a %^MAGENTA%^sensual%^WHITE%^, %^BOLD%^%^BLACK%^mysterious %^RESET%^ambiance. Supported on a %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^rbl%^WHITE%^e %^RESET%^platform that requires a small %^MAGENTA%^cushioned %^WHITE%^step stool to mount, the firm mattress is large enough to easily accommodate half a dozen guests. The bed is dressed in %^BOLD%^%^BLACK%^black silk sheets %^RESET%^and a %^BOLD%^%^BLACK%^black duvet %^RESET%^stuffed with %^BOLD%^d%^RESET%^%^ORANGE%^o%^WHITE%^w%^BOLD%^n f%^RESET%^e%^ORANGE%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^rs%^RESET%^, and a mound of plush %^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^%^BLACK%^ll%^RESET%^o%^BOLD%^%^BLACK%^ws %^RESET%^is piled against the %^BOLD%^%^BLACK%^headboard%^RESET%^. The headboard itself is an impressive piece of art, a solid piece of carved %^BOLD%^%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^ny w%^RESET%^o%^BOLD%^o%^BLACK%^d %^RESET%^that features a relief of the expansive and lush %^GREEN%^Thar%^BOLD%^i%^RESET%^%^GREEN%^s Forest%^WHITE%^.",
        ({"wardrobe", "chest", "drawers"}) : "%^RESET%^This large wardrobe is well-crafted, opening and closing silently on oiled hinges. Next to it, a large chest of drawers is waiting to be filled by the next guest. Both have been crafted from %^RESET%^l%^BOLD%^%^BLACK%^u%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^r%^WHITE%^o%^RESET%^u%^BOLD%^%^BLACK%^s eb%^RESET%^o%^BOLD%^%^BLACK%^ny%^RESET%^, and have the same decorative scrollwork carved into their frames.%^RESET%^",
        ({"floor", "rug"}) : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^. Central to the room and resting beneath the %^BOLD%^%^BLACK%^couches %^RESET%^and %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^WHITE%^f%^BOLD%^f%^RESET%^%^MAGENTA%^e%^BOLD%^e t%^RESET%^%^MAGENTA%^a%^WHITE%^b%^BOLD%^l%^MAGENTA%^e%^RESET%^, a luxuriously thick, %^MAGENTA%^deep violet %^WHITE%^area rug covers most of the %^BOLD%^%^BLACK%^fl%^RESET%^o%^BOLD%^o%^BLACK%^r%^RESET%^. ",
        ({"glowstones", "crystals", "ceiling"}) : "A myriad of tiny %^BOLD%^%^MAGENTA%^ameth%^RESET%^%^MAGENTA%^y%^BOLD%^st cryst%^RESET%^%^MAGENTA%^a%^BOLD%^ls %^RESET%^hover near the ceiling, like so many %^BOLD%^stars %^RESET%^dotting the expanse of the %^BLUE%^midnight sky%^WHITE%^. They add a soft %^MAGENTA%^v%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t %^WHITE%^l%^MAGENTA%^u%^WHITE%^m%^BOLD%^%^MAGENTA%^i%^RESET%^n%^MAGENTA%^e%^WHITE%^s%^BOLD%^%^MAGENTA%^c%^RESET%^en%^BOLD%^%^MAGENTA%^c%^RESET%^e to the room.",
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls.%^RESET%^",
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

