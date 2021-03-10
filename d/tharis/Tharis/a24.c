//a24.c

#include <std.h>
#include "../tharis.h"

inherit CVAULT;

void create(){
   ::create();
    set_terrain(CITY);
    set_travel(BACK_ALLEY);
   set_property("light",1);

   set_short(
@JAVAMAKER
Dark alley in Tharis
JAVAMAKER
   );

   set_long(
@JAVAMAKER
     %^RED%^Dark alley through Tharis%^RESET%^
The high stone walls block most of the sun from the street
in these back alleyways. The ground here is still stone but
uncared for. The broken stone is wet to the step and it seems
that here is where the refuse and offal get thrown. The shadows
move and shake, you never know what it is back in these dark
alleys. There is a door to the south.
JAVAMAKER
   );

   set_smell("default","The smell here is awful. The refuse and the stench make you queasy.");
   set_listen("default","You hear a groan of some unfortunate soul. ");
   set_items(([
      "stone":"The stones here have not been tended since the erection of the walls around them. They are split and dirty.",
      "refuse":"This is awful smelling stuff, it's been piled up over time and slowly is cleared away to the sewers below.",
   ]));
	set_exits(([
	"east":ROOMS"a23",
	"northwest":ROOMS"a25",
	"south":ROOMS"mercs",
	]));
	set_door("door",ROOMS"mercs","south","blah");
	set_open("door",0);
}

