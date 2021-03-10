
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;


void create(){
object ob;
:: create();
   set_terrain(BARREN);
   set_travel(STAIRWAY);
set_light(2);
set_indoors(0);
set_short("
%^BOLD%^%^WHITE%^Stairs to the monastery%^RESET%^
");
set_long(
@SEETH
%^BOLD%^%^WHITE%^Before you are many steps toward an %^RESET%^%^MAGENTA%^ancient monastery%^BOLD%^%^WHITE%^. The steps are made entirely of %^RESET%^stone%^BOLD%^%^WHITE%^. You estimate that there are about fifty steps toward the entrance of the monastery. The monastery seems to be made on the side of a %^BOLD%^%^BLACK%^volcano%^WHITE%^.%^RESET%^

SEETH
);

set_items(([
"steps" : "These steps are made entirely of stone. They seem to be well kept and clean.",
]));

set_exits(([
"steps" : MONASTERY "entrance",
    "out":MOUNTAIN+"mount67",

]));

set_smell("default", "You can smell the pureness of the air.");
set_listen("default", "You can hear the rumbling of the near volcano.");

}
