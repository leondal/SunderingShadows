//a11.c

#include <std.h>
#include "../tharis.h"

inherit ALLEY;

void create(){
   ::create();
   set_long(
@JAVAMAKER
     %^RED%^Dark alley through Tharis%^RESET%^
The high stone walls block most of the sun from the street
in these back alleyways. The ground here is still stone but
uncared for. The broken stone is wet to the step and it seems
that here is where the refuse and offal get thrown. The shadows
shroud the dead end here. The walls of the next building block 
any passage. The shadows move and shake, you never know what is 
back in these dark alleys.
JAVAMAKER
   );
   set_items(([
      "stone":"The stones here have not been tended since the erection of the walls around them. They are split and dirty.",
      "refuse":"This is awful smelling stuff, its been piled up over time and slowly is cleared away to the sewers below.",
      "walls":"These walls are dark and dank. They clearly are the back of another building.",
   ]));
   set_exits(([
      "southwest":ROOMS"a12",
   ]));
}
