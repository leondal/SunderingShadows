#include <std.h>
inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("road in verbobone");
    set_short("%^BOLD%^%^GREEN%^R%^RESET%^%^GREEN%^oad in %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^");
    set_long("%^BOLD%^%^GREEN%^R%^RESET%^%^GREEN%^oad in %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^
%^GREEN%^This %^WHITE%^road %^GREEN%^in the town of %^BOLD%^V%^RESET%^%^GREEN%^erbobone runs south from the west gates to the once abandoned part of the town. It is made from %^WHITE%^st%^BOLD%^on%^RESET%^es %^BOLD%^o%^RESET%^f va%^BOLD%^rio%^RESET%^us s%^BOLD%^hape%^RESET%^s %^GREEN%^that have been put together in such a way to provide an almost solid and smooth surface, making traveling an ease for both man and animal. Most of the %^ORANGE%^buildings %^GREEN%^in this part of the town still remain %^ORANGE%^uninhabited %^GREEN%^and offer a reminder of the towns once boisterous but now forgotten past.");

}
