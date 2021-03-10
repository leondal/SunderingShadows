//forest179
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_long("%^RESET%^%^GREEN%^You have walked into the thicker part"
" of the Yntala Forest. This is a thick forest whose dense canopy"
" allows only a few rays of %^RESET%^surreal %^GREEN%^light"
" through, creating an almost magical presence around you. The"
" underbrush is thick and full of life here, as ivy climbs the"
" trees in abundance and ferns seem to reach out towards one"
" another, their delicate and lacy leaves brushing against"
" everything around them.%^RESET%^");
set_exits(([
"northeast":INRMS+"forest150",
"south":INRMS+"forest33"
]));
}