// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"concourse";
inherit VAULT;

void create(){
    ::create();
    set_long(::query_long()+" %^RESET%^%^ORANGE%^A massive %^WHITE%^gate %^ORANGE%^leading into the arena proper looms to the southwest, and an %^WHITE%^o%^BOLD%^r%^RESET%^n%^YELLOW%^a%^RESET%^t%^BOLD%^e %^BLACK%^d%^RESET%^o%^BOLD%^o%^RESET%^r %^ORANGE%^has been set into the outer wall of the concourse.%^WHITE%^\n%^RESET%^");
    add_item("gate","%^RESET%^%^ORANGE%^Rich mahogany planks %^BOLD%^%^BLACK%^have been fashioned into this %^RESET%^o%^BOLD%^r%^RESET%^n%^YELLOW%^a%^RESET%^t%^BOLD%^e %^BLACK%^d%^RESET%^o%^BOLD%^o%^RESET%^r%^BOLD%^%^BLACK%^. %^RESET%^Iron panels %^BOLD%^%^BLACK%^reinfornce it, and a %^ORANGE%^b%^RESET%^%^ORANGE%^r%^BOLD%^ass p%^RESET%^%^ORANGE%^l%^BOLD%^aq%^RESET%^%^ORANGE%^u%^BOLD%^e %^BLACK%^has been set into it. The words seem to shift into a familiar tongue: %^WHITE%^T%^MAGENTA%^h%^RESET%^%^MAGENTA%^e %^BOLD%^%^WHITE%^M%^MAGENTA%^agist%^RESET%^%^MAGENTA%^rate's %^BOLD%^%^WHITE%^V%^MAGENTA%^iew%^RESET%^%^MAGENTA%^ing %^BOLD%^%^WHITE%^B%^MAGENTA%^o%^RESET%^%^MAGENTA%^x%^BOLD%^%^BLACK%^.%^RESET%^");
    add_item("door","%^RESET%^%^ORANGE%^Rich mahogany planks %^BOLD%^%^BLACK%^have been fashioned into this %^RESET%^o%^BOLD%^r%^RESET%^n%^YELLOW%^a%^RESET%^t%^BOLD%^e %^BLACK%^d%^RESET%^o%^BOLD%^o%^RESET%^r%^BOLD%^%^BLACK%^. %^RESET%^Iron panels %^BOLD%^%^BLACK%^reinforce it, and a %^ORANGE%^b%^RESET%^%^ORANGE%^r%^BOLD%^ass p%^RESET%^%^ORANGE%^l%^BOLD%^aq%^RESET%^%^ORANGE%^u%^BOLD%^e %^BLACK%^has been set into it. The words seem to shift into a familiar tongue: %^WHITE%^T%^MAGENTA%^h%^RESET%^%^MAGENTA%^e %^BOLD%^%^WHITE%^M%^MAGENTA%^agist%^RESET%^%^MAGENTA%^rate's %^BOLD%^%^WHITE%^V%^MAGENTA%^iew%^RESET%^%^MAGENTA%^ing %^BOLD%^%^WHITE%^B%^MAGENTA%^o%^RESET%^%^MAGENTA%^x%^BOLD%^%^BLACK%^.%^RESET%^");
    set_exits(([
        "west" : ROOMS"concourse4",
        "south" : ROOMS"concourse3",
        "southwest" : ROOMS"arena",
        "up" : ROOMS"viewing_box",
        ]));
    set_door("iron gate", ROOMS"arena", "southwest", 0);
    set_door_description("iron gate","%^BOLD%^%^BLACK%^The massive gate is formed of woven bands of %^RESET%^iron %^BOLD%^%^BLACK%^in vertical and horizontal intersections, creating an %^RESET%^%^RED%^imposing %^BOLD%^%^BLACK%^and impressive barrier to the arena.%^RESET%^");
    set_door("mahogany door", ROOMS"viewing_box", "up", 0);
    set_door_description("mahogany door","%^RESET%^%^ORANGE%^Rich mahogany planks %^BOLD%^%^BLACK%^have been fashioned into this %^RESET%^o%^BOLD%^r%^RESET%^n%^YELLOW%^a%^RESET%^t%^BOLD%^e %^BLACK%^d%^RESET%^o%^BOLD%^o%^RESET%^r%^BOLD%^%^BLACK%^. %^RESET%^Iron panels %^BOLD%^%^BLACK%^reinforce it, and a %^ORANGE%^b%^RESET%^%^ORANGE%^r%^BOLD%^ass p%^RESET%^%^ORANGE%^l%^BOLD%^aq%^RESET%^%^ORANGE%^u%^BOLD%^e %^BLACK%^has been set into it. The words seem to shift into a familiar tongue: %^WHITE%^T%^MAGENTA%^h%^RESET%^%^MAGENTA%^e %^BOLD%^%^WHITE%^M%^MAGENTA%^agist%^RESET%^%^MAGENTA%^rate's %^BOLD%^%^WHITE%^V%^MAGENTA%^iew%^RESET%^%^MAGENTA%^ing %^BOLD%^%^WHITE%^B%^MAGENTA%^o%^RESET%^%^MAGENTA%^x%^BOLD%^%^BLACK%^.%^RESET%^");
}

