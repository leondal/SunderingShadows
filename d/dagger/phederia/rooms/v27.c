#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("indoors",1);
  set_short(
  "Bloody barn."
  );
  set_long(
  "Bloody barn.\n"
  "  This great barn hangs heavy with the stink of death."
  "  The floor looks like a great many animals were torn apart and gutted here."
  "  Flesh and entrails cover the floor and the strawn is heavily matted with blood."
  "\n"
  );
  set_smell("default",
  "The entrails and flesh are starting to rot and the smell of blood fills your nose."
  );
  set_listen("default",
  "You cant hear anything past the horrors which fill your sight."
  );
  set_items(([
  "blood":"Thick and black its clotted to the straw on the floor.",
  "flesh":"As you investigate a little closer you see flesh mixed in with the flesh.   And no farm animals have clear hairless skin like that.   Perhaps its where the villagers have all disapeared to.   But.  Where are their bones?",
  "entrails":"As you investigate a little closer you see flesh mixed in with the flesh.   And no farm animals have clear hairless skin like that.   Perhaps its where the villagers have all disapeared to.   But.  Where are their bones?",
  ]));
  set_exits(([
  "north":ROOMS"v26.c",
  "south":ROOMS"v7.c",
  "up":ROOMS"v27a.c",
  ]));
}
void reset(){
  ::reset();
  if(!present("pskeleton")){
  new(MON"pskeleton.c")->move(TO);
  new(MON"pskeleton.c")->move(TO);
  new(MON"pskeleton.c")->move(TO);
}
}
