#include <std.h>
#include "../areadefs.h"
inherit VAULT;

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
You are wandering down a very worn passageway. The walls are very cramped
and the ceiling is not high at all.  The %^ORANGE%^torches%^RESET%^ on the wall provide a bit 
of illumination in this otherwise dark hallway. The floor has an old %^RED%^red 
carpet%^RESET%^ stretching down all the passageways. It appears rather well used. 
A %^BLUE%^large gate%^RESET%^ not unlike the one at the entrance blocks 
further passage east. This one unlike the other ones appears as though 
it can be opened, though it is locked.
BRUENOR
    );
    set_items( ([ "walls": "The wall is a sheet of solid stone.",
       "carpet": "The carpet is a rather nice red felt carpet.",
       "torches": "The torches burn dimly in the dark. They do not
        seem to be burning away the wood though.",
       "ceiling": "The ceiling is rather low and is carved out of 
        the rock itself." ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_door("iron gate",ROOMS+"portalroom","east","gate key");
    set_locked("iron gate",1,"lock");
     (ROOMS+"portalroom")->set_locked("iron gate",1,"lock");
    set_door_description("iron gate","This huge gate is made of rusty "+
                         "steel, thought it looks sturdy for its age.");
    set_string("iron gate","open","The large gate creeks open");
    set_exits(
    ([
        "west" : ROOMS+"rm27",
        "east" : ROOMS+"portalroom"
   
    ]) );

}


void reset()
{
   ::reset();
   if(present("assassin"||"assassinfight"||"assassinrang")) return;
   if(random(2)) return;
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

