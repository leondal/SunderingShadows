#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
    set_property( "light", 1);
    set_property( "indoors", 1);
	set_property( "no scry", 1); 
	set_property( "teleport proof", 40); 
	//mythal has enough strength left to protect just this one room.
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("mythal alcove");
    set_short("mythal alcove");
    set_long("Mythal Alcove \n"
"%^CYAN%^This is a small area set behind the waterfall."+
"  The rock is carved out into an alcove where"+
" a large pedestal sits.  On top of the pedestal"+
" rests an huge %^MAGENTA%^cracked gem%^CYAN%^.  It %^MAGENTA%^pulsates weakly"+
" %^CYAN%^as if some great magic in it is dying. \n");

        set_items(([
      (({"water","waterfall"})) :
        "The waterfall rushes behind you.",
      (({"alcove"})) : "An ornately etched stone alcove with a gem on a pedestal.",
      (({"gem","cracked gem"})) : "This is a faded blue gem that"+
	  " pulsates with a flickering purple light.",
           ]));

      set_exits(([ "south" : ROOMS"wfall",
          ]));

   set_listen("default","The waterfall splashing down echoes through the area.");
   set_smell("default",
   "This place smells of rock and water.");
}
void reset(){
  ::reset();

  if(!present("carving"))
   new(OBJ"sign3")->move(TO);
  if(!present("ornsul"))
   new("/d/retired/ornsul")->move(TO);
  
  return;
 }
