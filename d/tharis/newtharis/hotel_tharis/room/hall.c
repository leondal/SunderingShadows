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
    set_name("Hotel Main Hall");
    set_short("%^MAGENTA%^H%^BOLD%^%^BLACK%^ote%^RESET%^%^MAGENTA%^l M%^BOLD%^%^BLACK%^ai%^RESET%^%^MAGENTA%^n H%^BOLD%^%^BLACK%^al%^RESET%^%^MAGENTA%^l%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The opulent main hall of the hotel features a tall %^WHITE%^t%^RESET%^r%^BOLD%^%^BLACK%^ay ceili%^RESET%^n%^BOLD%^g%^BLACK%^, showcasing an opulent %^MAGENTA%^cr%^RESET%^%^MAGENTA%^ys%^WHITE%^t%^BOLD%^a%^RESET%^l%^MAGENTA%^li%^BOLD%^ne ch%^RESET%^%^MAGENTA%^an%^WHITE%^d%^BOLD%^e%^RESET%^%^MAGENTA%^li%^BOLD%^er%^BLACK%^. A %^RESET%^%^MAGENTA%^deep violet carpet %^BOLD%^%^BLACK%^runs the length of the room, from the foyer all the way to the grand staircase at the southern end of the hall. An archway to the west leads into a restaurant, while another archway to the east appears to lead into a lounge. %^RESET%^%^RED%^P%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^RED%^g%^ORANGE%^s %^BOLD%^%^BLACK%^decorate the bl%^RESET%^a%^BOLD%^c%^BLACK%^k m%^RESET%^a%^BOLD%^%^BLACK%^rbl%^WHITE%^e %^BLACK%^w%^RESET%^a%^BOLD%^l%^BLACK%^ls, along with %^RESET%^%^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns %^BOLD%^%^BLACK%^potted in %^WHITE%^pristine%^BLACK%^, %^WHITE%^wh%^RESET%^i%^BOLD%^te p%^RESET%^o%^BOLD%^ts%^BLACK%^.\n");
    set_smell("default","The air carries a mix of white tea and vanilla, with a hint of cedar.");
    set_listen("default","You hear the gentle susurrus of patrons coming and going.");
    set_items(([
        ({"wall", "walls"}) : "%^BOLD%^%^BLACK%^Large slabs of %^RESET%^polished %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^r%^BLACK%^bl%^WHITE%^e %^BLACK%^shot through with v%^RESET%^e%^BOLD%^i%^BLACK%^ns of %^WHITE%^wh%^RESET%^i%^BOLD%^te %^BLACK%^comprise these walls. %^RESET%^%^RED%^P%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^RED%^g%^ORANGE%^s %^BOLD%^%^BLACK%^and large %^WHITE%^potted %^RESET%^%^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns %^BOLD%^%^BLACK%^partially obfuscate the expanse of the walls.%^RESET%^",
        "paintings" : "%^RESET%^Fine %^RED%^p%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^BLUE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^RED%^g%^ORANGE%^s %^WHITE%^are spaced out between the large %^BOLD%^potted %^RESET%^%^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns%^WHITE%^; they range from beautiful %^GREEN%^l%^ORANGE%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^ds%^CYAN%^c%^BOLD%^a%^RESET%^%^GREEN%^p%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^s %^WHITE%^of the foreboding %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^rests %^WHITE%^that surround %^BOLD%^%^BLACK%^Tharis %^RESET%^to %^BOLD%^%^CYAN%^br%^RESET%^%^CYAN%^ea%^BOLD%^tht%^RESET%^%^CYAN%^a%^BOLD%^k%^RESET%^%^CYAN%^i%^BOLD%^ng %^RESET%^renderings of %^BOLD%^%^BLACK%^Tenebrosa%^RESET%^, the %^CYAN%^fl%^BOLD%^o%^BLUE%^a%^RESET%^%^CYAN%^t%^BOLD%^i%^RESET%^%^CYAN%^ng %^BOLD%^%^BLACK%^C%^RESET%^i%^BOLD%^%^BLACK%^t%^RESET%^y %^BOLD%^%^BLACK%^of Sh%^RESET%^a%^BOLD%^%^BLACK%^de%^RESET%^.",
        "floor" : "%^RESET%^Solid %^BOLD%^%^BLACK%^ebony floorboards %^RESET%^lay beneath your feet in a %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^r%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^e %^RESET%^pattern, the %^BOLD%^%^BLACK%^black wood p%^RESET%^o%^BOLD%^%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^to a %^BOLD%^reflective %^BLACK%^sh%^RESET%^e%^BOLD%^e%^BLACK%^n%^RESET%^.",
        ({"plants", "ferns"}) : "%^RESET%^Large, expansive %^GREEN%^f%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ns %^WHITE%^are located along the walls. They have been planted in large %^ORANGE%^ceramic pots%^WHITE%^, which have been painted a %^BOLD%^pristine%^RESET%^, %^BOLD%^m%^RESET%^a%^BOLD%^tt%^RESET%^e %^BOLD%^wh%^RESET%^i%^BOLD%^t%^RESET%^e.%^RESET%^",
        "carpet" : "%^MAGENTA%^Deep %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^dark violet%^BOLD%^%^BLACK%^, this thick %^RESET%^%^MAGENTA%^runner %^BOLD%^%^BLACK%^spans the entire length of the room and into the adjoining hall.%^RESET%^",
        "chandelier" : "%^RESET%^Suspended from the arched ceiling of the main hall, this grandiose %^BOLD%^%^MAGENTA%^ch%^RESET%^%^MAGENTA%^an%^BOLD%^%^WHITE%^d%^RESET%^e%^MAGENTA%^li%^BOLD%^er %^RESET%^has been fashioned from hundreds of small %^BOLD%^%^MAGENTA%^am%^RESET%^%^MAGENTA%^e%^BOLD%^th%^RESET%^%^MAGENTA%^y%^BOLD%^st sh%^RESET%^%^MAGENTA%^a%^BOLD%^rds%^RESET%^. Each %^BOLD%^%^MAGENTA%^sha%^RESET%^%^MAGENTA%^r%^BOLD%^d %^RESET%^is about the size of a coin, and has been ensnared in a clever enchantment to lazily %^MAGENTA%^sw%^BOLD%^i%^RESET%^%^MAGENTA%^rl %^WHITE%^around a gently %^BOLD%^%^MAGENTA%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RESET%^%^MAGENTA%^i%^BOLD%^ng %^RESET%^spherical centerpiece. The %^BOLD%^%^MAGENTA%^ch%^RESET%^%^MAGENTA%^an%^BOLD%^%^WHITE%^d%^RESET%^e%^MAGENTA%^li%^BOLD%^er %^WHITE%^sparkles %^RESET%^and %^BOLD%^%^MAGENTA%^glitters %^RESET%^as the light is fragmented and refracted through each %^BOLD%^%^MAGENTA%^gl%^RESET%^%^MAGENTA%^i%^BOLD%^mm%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^i%^BOLD%^ng cr%^RESET%^%^MAGENTA%^y%^BOLD%^st%^RESET%^%^MAGENTA%^a%^BOLD%^l%^RESET%^.",
        "ceiling" : "%^RESET%^A %^BOLD%^white plaster %^RESET%^tray ceiling compliments the %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^c%^BLACK%^k m%^RESET%^a%^BOLD%^%^BLACK%^rbl%^WHITE%^e %^BLACK%^w%^RESET%^a%^BOLD%^l%^BLACK%^ls %^RESET%^and is inlaid with %^BOLD%^%^BLACK%^paneling %^RESET%^made from the same %^BOLD%^%^BLACK%^p%^RESET%^o%^BOLD%^%^BLACK%^l%^RESET%^i%^BOLD%^%^BLACK%^sh%^WHITE%^e%^BLACK%^d eb%^RESET%^o%^BOLD%^%^BLACK%^ny w%^RESET%^o%^BOLD%^o%^BLACK%^d %^RESET%^as the %^BOLD%^%^BLACK%^fl%^RESET%^o%^BOLD%^o%^BLACK%^rs%^RESET%^, artfully marrying the various design features of the room.",
        ]));
    set_exits(([
        "foyer" : ROOMS "foyer",
        "restaurant" : ROOMS "restaurant",
        "lounge" : ROOMS "lounge",
        "staircase" : ROOMS "stairs1",
        ]));
}

