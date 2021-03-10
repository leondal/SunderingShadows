#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Overgrown path");
   set_short("Overgrown path");
   set_long("%^BOLD%^Overgrown path%^RESET%^\n"
"This little overgrown pathway breaks away from the %^BLACK%^%^BOLD%^cobbled square%^RESET%^ to the south, "
"marking a small trail through the %^GREEN%^bushes%^RESET%^.  Trees and brambles tug at your clothing, "
"making it difficult to walk further.  The %^ORANGE%^path%^RESET%^ itself only makes it a few paces forward "
"however, before disappearing into nothingness amongst the plants.\n");
   set("night long","%^BOLD%^Overgrown path%^RESET%^\n"
"This little overgrown pathway breaks away from the %^BLACK%^%^BOLD%^cobbled square%^RESET%^ to the south, "
"marking a small trail through the %^BLUE%^darkness%^RESET%^ into the %^GREEN%^bushes%^RESET%^.  Trees and "
"brambles tug at your clothing, making it difficult to walk further.  The %^ORANGE%^path%^RESET%^ itself "
"only makes it a few paces forward however, before disappearing into nothingness amongst the plants and the "
"%^BLACK%^%^BOLD%^night's shadows%^RESET%^.\n");
   set_smell("default","The light, salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean to the south.");

   set_items(([
     ({"village","settlement","square","cobbled square"}):"Just to the south, you can make out the buildings "
"of a small settlement.",
     ({"trail","path"}):"The bare traces of the path make their way into the brush, getting lost a few paces "
"forward amongst the shrubbery.",
     ({"plants","shrubbery","trees","bushes"}):"A thick gathering of %^GREEN%^bushes and trees%^RESET%^ line "
"either side of the path, eventually overgrowing the entire trail."
    ]));

   set_exits(([
     "south":COVE"path5",
     "bushes":COVE"thief2"
   ]));
   set_pre_exit_functions(({"bushes",}),({"stopem",}));
   set_invis_exits(({"bushes"}));
}

int stopem() {
   if(avatarp(TP)) return 1;
   if(!TP->is_class("thief") && !TP->is_class("assassin")){
     tell_object(TP,"The bushes are rather thick and interspersed with brambles, passage will be too "
"difficult.");
     return 0;
   }
   tell_object(TP,"You sneak quietly through the bushes.");
   return 1;
}
