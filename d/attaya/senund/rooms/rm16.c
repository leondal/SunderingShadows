#include <std.h>
#include "../areadefs.h"
inherit ROOM;

void create()
{
        ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_property("light",2);
    set_name("Underground Passage");
    set_short("Underground Passage");
    set_long(
@BRUENOR
%^BOLD%^%^CYAN%^An Underground Passage%^RESET%^
You are wandering down a very worn passageway. To the west you notice a 
dark opening in the wall. It is cloaked in %^BLUE%^shadows%^RESET%^ and you have no idea 
what could be in the room. The walls continue to have strange %^MAGENTA%^runes%^RESET%^
carved every 30 feet or so. The ceiling is rather low and appears
unremarkable. Fortunately a couple of %^ORANGE%^torches%^RESET%^ 
on the wall provide a little bit of illumination in this otherwise
dark hallway. The floor has an old %^RED%^red carpet%^RESET%^ stretching
down all the passageways. It appears rather well used.
BRUENOR
    );
    set_items( ([ "walls": "The wall is a sheet of solid stone.",
       "carpet": "The carpet is a rather nice red felt carpet.",
       "torches": "The torches burn dimly in the dark. They do not "+
       "seem to be burning away the wood though.",
       "ceiling": "The ceiling is rather low and is carved out of "+
       "the rock itself.",
       "runes": "The purpose of these runes is not clear but obviously "+
       "must be the work of some sort of wizard or priest." ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_exits(
    ([
        "northwest" : ROOMS+"rm15",
        "east" : ROOMS+"rm25",
        "southwest" : ROOMS+"rm17",
        "west" : ROOMS+"clericroom"
   
    ]) );

}


void reset()
{
   ::reset();
   if(present("assassin"||"assassinfight"||"assassinrang")) return;
   if(random(4)) return;
   switch(random(5)) {
      case 0:
         new(MON+"assassin")->move(TO);
         break;
      case 1:
         new(MON+"assassinfight")->move(TO);
         break;
      case 2:
         new(MON+"assassinrang")->move(TO);
         break;
      case 3:
         new(MON+"assassin")->move(TO);
         new(MON+"assassin")->move(TO);
         break;
      case 4:
         new(MON+"assassinfight")->move(TO);
         new(MON+"assassin")->move(TO);
         new(MON+"assassinrang")->move(TO);
         break;
   }
}

