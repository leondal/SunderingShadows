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
    set_name("The Violet's Foyer");
    set_short("%^RESET%^%^MAGENTA%^T%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^e %^RESET%^%^MAGENTA%^V%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t's F%^BOLD%^%^BLACK%^oye%^RESET%^%^MAGENTA%^r%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The main entrance to %^RESET%^%^MAGENTA%^The Violet %^BOLD%^%^BLACK%^is a sight to behold. The walls are comprised of large slabs of polished black marble shot through with thick veins of %^WHITE%^wh%^RESET%^i%^BOLD%^t%^RESET%^e%^BOLD%^%^BLACK%^. Interspersed along the walls are large %^WHITE%^wh%^RESET%^i%^BOLD%^t%^RESET%^e %^BOLD%^p%^RESET%^o%^BOLD%^ts %^BLACK%^containing lush %^RESET%^%^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns%^BOLD%^%^BLACK%^, and beautiful %^RESET%^%^RED%^p%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^RED%^g%^ORANGE%^s %^BOLD%^%^BLACK%^decorate the spaces between. A %^RESET%^%^MAGENTA%^dark violet %^BOLD%^%^BLACK%^runner lines the center of the walkway over %^RESET%^polished %^BOLD%^%^BLACK%^ebony wood floors. To the side is a large and intricately carved wooden desk, complete with a ledger and s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er b%^RESET%^e%^BOLD%^l%^BLACK%^l%^RESET%^.\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","You hear the gentle susurrus of patrons coming and going.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with veins of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls. %^RESET%^%^RED%^P%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^RED%^g%^ORANGE%^s %^BOLD%^%^BLACK%^and large %^WHITE%^potted %^RESET%^%^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns %^BOLD%^%^BLACK%^partially obfuscate the expanse of the walls.%^RESET%^",
        "paintings" : "%^RESET%^Fine %^RED%^p%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^RED%^g%^ORANGE%^s %^WHITE%^are spaced out between the large %^BOLD%^potted %^RESET%^%^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns%^WHITE%^; they range from beautiful %^GREEN%^l%^ORANGE%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^ds%^CYAN%^c%^BOLD%^a%^RESET%^%^GREEN%^p%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^s %^WHITE%^of the foreboding %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^rests %^WHITE%^that surround %^BOLD%^%^BLACK%^Tharis %^RESET%^to %^BOLD%^%^CYAN%^br%^RESET%^%^CYAN%^ea%^BOLD%^tht%^RESET%^%^CYAN%^a%^BOLD%^k%^RESET%^%^CYAN%^i%^BOLD%^ng %^RESET%^renderings of %^BOLD%^%^BLACK%^Tenebrosa%^RESET%^, the %^CYAN%^fl%^BOLD%^o%^BLUE%^a%^RESET%^%^CYAN%^t%^BOLD%^i%^RESET%^%^CYAN%^ng %^BOLD%^%^BLACK%^C%^RESET%^i%^BOLD%^%^BLACK%^t%^RESET%^y %^BOLD%^%^BLACK%^of Sh%^RESET%^a%^BOLD%^%^BLACK%^de%^RESET%^.",
        "floor" : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^.",
        ({"plants", "ferns"}) : "%^RESET%^Large, expansive %^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns %^WHITE%^are located along the walls. They have been planted in large %^ORANGE%^ceramic pots%^WHITE%^, which have been painted a %^BOLD%^pristine%^RESET%^, %^BOLD%^m%^RESET%^a%^BOLD%^tt%^RESET%^e %^BOLD%^wh%^RESET%^i%^BOLD%^t%^RESET%^e.%^RESET%^",
        "carpet" : "%^MAGENTA%^Deep %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^dark violet%^BOLD%^%^BLACK%^, this thick %^RESET%^%^MAGENTA%^runner %^BOLD%^%^BLACK%^spans the entire length of the room and into the adjoining hall.%^RESET%^",
        ({"desk", "ledger", "bell"}) : "%^RESET%^There is a large %^BOLD%^%^BLACK%^ebony wood %^RESET%^front desk here, with intricate %^BOLD%^%^BLACK%^scr%^RESET%^o%^BOLD%^%^BLACK%^ll%^RESET%^-work carved along the body. Sitting central upon it is a large %^BOLD%^%^BLACK%^lea%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^herb%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^und %^RESET%^ledger for registering guests, with an %^BOLD%^%^BLACK%^inkwell %^RESET%^and %^BOLD%^q%^BLACK%^u%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^l %^RESET%^set just to the side. ",
        "ceiling" : "%^RESET%^A %^BOLD%^white plaster %^RESET%^tray ceiling compliments the %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^c%^BLACK%^k m%^RESET%^a%^BOLD%^r%^BLACK%^ble %^RESET%^walls and is inlaid with %^BOLD%^%^BLACK%^paneling %^RESET%^made from the same %^BOLD%^%^BLACK%^p%^RESET%^o%^BOLD%^%^BLACK%^l%^RESET%^i%^BOLD%^s%^BLACK%^h%^RESET%^e%^BOLD%^%^BLACK%^d eb%^RESET%^o%^BOLD%^%^BLACK%^ny w%^RESET%^o%^BOLD%^o%^BLACK%^d %^RESET%^as the floors, artfully marrying the various design features %^BOLD%^o%^RESET%^f the room.%^RESET%^",
        ]));
    set_exits(([
        "north" : "/d/tharis/newtharis/rooms/west2",
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

