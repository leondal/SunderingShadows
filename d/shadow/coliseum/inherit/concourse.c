// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Shadow Coliseum");
    set_short("%^BOLD%^M%^ORANGE%^ai%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^C%^ORANGE%^onco%^RESET%^%^ORANGE%^urse%^WHITE%^");
    set_long("%^RESET%^%^ORANGE%^The main concourse of the coliseum wraps around the body of the arena, though the best view is from the stands up above. Concave ceilings run the course, propped by a%^BOLD%^r%^WHITE%^ch%^ORANGE%^e%^RESET%^%^ORANGE%^s, %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^lum%^RESET%^n%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^, and clever architecture. Every surface has been decorated and embellished with attention to detail. The floors are %^BOLD%^%^BLACK%^smo%^RESET%^o%^BOLD%^%^BLACK%^th on%^RESET%^y%^BOLD%^%^BLACK%^x%^RESET%^%^ORANGE%^, with the walls shifting from shades of %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^to %^WHITE%^gray %^ORANGE%^to %^BOLD%^%^WHITE%^white %^RESET%^%^ORANGE%^as they rise up to meet the ceiling. Scenes have been carved into the walls at even intervals, spaced between %^BOLD%^%^WHITE%^m%^RESET%^a%^BOLD%^rbl%^RESET%^e %^BOLD%^b%^RESET%^e%^BOLD%^nch%^RESET%^e%^BOLD%^s %^RESET%^%^ORANGE%^along the periphery. %^CYAN%^G%^BOLD%^l%^WHITE%^owston%^CYAN%^e%^RESET%^%^CYAN%^s %^ORANGE%^hang suspended from the apex of each archway, offering a cool brilliance in the hall.%^RESET%^");
    set_smell("default","The stink of large crowds and stale sweat seems to permeate these halls.");
    set_listen("default","You can hear the echoes of footsteps further down the hall.");
    set_items(([
        "arches" : "%^BOLD%^%^BLACK%^Arches are spaced periodically along the ceiling, the stone bricks wedged together in an impressive feat of engineering. A larger oblong capstone rest at the apex of each arch.%^RESET%^",
        "columns" : "%^BOLD%^%^BLACK%^These columns have a square block of onyx for the plinth and capital, with a rounded cylinder of s%^RESET%^m%^BOLD%^o%^RESET%^ke%^BOLD%^%^BLACK%^y g%^RESET%^r%^BOLD%^a%^BLACK%^y %^RESET%^m%^BOLD%^ar%^BLACK%^b%^WHITE%^l%^RESET%^e %^BOLD%^%^BLACK%^between top and bottom.%^RESET%^",
        ({"floor","floors"}) : "%^BOLD%^%^BLACK%^Square tiles of onyx line the floors. They are s%^RESET%^m%^BOLD%^oo%^RESET%^t%^BOLD%^%^BLACK%^h and %^RESET%^%^CYAN%^cool %^BOLD%^%^BLACK%^beneath your feet.%^RESET%^",
        ({"carvings","scenes"}) : "%^BOLD%^%^BLACK%^These scenes are all different but they share similar themes. Each pits a %^RESET%^%^CYAN%^g%^BOLD%^la%^WHITE%^d%^CYAN%^ia%^WHITE%^t%^CYAN%^o%^RESET%^%^CYAN%^r %^BOLD%^%^BLACK%^in combat against a %^RESET%^%^RED%^downed foe%^BOLD%^%^BLACK%^, raising his weapons in %^ORANGE%^tr%^WHITE%^i%^ORANGE%^um%^WHITE%^p%^ORANGE%^h%^BLACK%^. The array of different weapons is amazing, as some favor tridents or a gladius and shield, while others seem completely unarmed until you notice the spellbooks and pouches at their sides. Truly, all are welcome to test their vast array of skills here at the coliseum.%^RESET%^",
        "benches" : "%^BOLD%^%^BLACK%^These benches are simple in design, with a long flat slab of marble balanced on two blocky supports. They are smooth and beveled, though designed more for appearance than for any sort of comfort. The marble is a %^RESET%^smokey gray %^BOLD%^%^BLACK%^with black spidery veins, contrasting nicely with the %^WHITE%^fl%^RESET%^a%^BOLD%^%^BLACK%^gs%^RESET%^t%^BOLD%^on%^RESET%^e%^BOLD%^%^BLACK%^s of the plaza.%^RESET%^",
        "walls" : "%^BOLD%^%^BLACK%^Shallow bl%^RESET%^oc%^BOLD%^ks %^BLACK%^of st%^RESET%^o%^BOLD%^ne %^BLACK%^line the walls, layered in gradients from ebon black, rising through a multitude of %^RESET%^gray %^BOLD%^%^BLACK%^hues and gradually culminating in %^WHITE%^stark white %^BLACK%^ceilings that arch along the concourse.%^RESET%^",
        "glowstones" : "%^BOLD%^%^BLACK%^Large oblong %^RESET%^st%^BOLD%^on%^RESET%^es %^BOLD%^%^BLACK%^hang from the top of each archway, held in place by strong i%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^n %^BOLD%^%^BLACK%^c%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^i%^BOLD%^%^BLACK%^ns. Each stone has been %^RESET%^%^CYAN%^e%^BOLD%^n%^WHITE%^chant%^CYAN%^e%^RESET%^%^CYAN%^d %^BOLD%^%^BLACK%^to %^CYAN%^g%^WHITE%^lo%^CYAN%^w%^BLACK%^, shedding a peaceful light down into the concourse.%^RESET%^",
        ]));
}

