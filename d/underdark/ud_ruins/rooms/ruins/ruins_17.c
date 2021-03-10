#include "../../ud_ruins.h"
inherit STORAGE"_ruins_base";

void create() {
    ::create();
    set_short(
        "%^CYAN%^a %^ORANGE%^cliffside %^CYAN%^pathway%^WHITE%^"
    );
    set_long(
        "%^CYAN%^This steep %^WHITE%^pathway %^CYAN%^up the cliffside looks to "
        "be well-traveled, the stone worn down over the course of centuries to "
        "provide an easy route with sure footing down to the riverside. From "
        "here, you can see out over the entirety of the %^BOLD%^river "
        "%^RESET%^%^CYAN%^that flows through this enormous "
        "%^BOLD%^%^BLACK%^cavern%^RESET%^%^CYAN%^, from the waterfall pouring "
        "out over the northeastern basin, to where the current suddenly plunges "
        "down into a massive %^BOLD%^%^BLUE%^underwater ravine "
        "%^RESET%^%^CYAN%^in the south. It does not look as if this path has "
        "seen regular use in some time, having become grown over, and the "
        "%^ORANGE%^village %^CYAN%^further up the cliffside looks to be in a "
        "state of disrepair.%^WHITE%^"
    );
    set_exits(([
        "south" : ROOMS"ruins/ruins_14",
        "west" : ROOMS"river/river_5",
        ]));
}
