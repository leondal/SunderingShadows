#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_property("no pocket space",1);
   set_long(
      "%^BOLD%^%^BLACK%^Here on the top of the mountain, you can see out"+
      " over the entire island and a vast deal of the water. To the far north"+
      ", you can see the outline of a large island and even another to the far"+
      " east. The ground is even here and edges are shielded by the jagged rocks"+
      " of the mountain."
   );
   remove_exit("portal");
   new(MON+"klauth")->move(TO);
}

