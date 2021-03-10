#include <std.h>
inherit ROOM;

#define Jewl "/d/darkwood/camps/obj/"

void create() {
   ::create();
   set_property("no teleport",1);
   set_short("Elf jewelry storage");
   set_long("This is that lady's jewelry storage. Watch out for squirrels.");
}
void reset() {
   ::reset();
   if(!present("jewelry 1"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
   if(!present("golden flower circlet"))
   new(Jewl+"elfcirclet.c")->move(TO);
   if(!present("jewelry 2"))
   new(Jewl+"c_elven_jewelry.c")->move(TO);
   if(!present("earcuff"))
    new(Jewl+"earcuff.c")->move(TO);
   if(!present("anklets of leaves"))
    new(Jewl+"leafanklets.c")->move(TO);
   if(!present("rose anklet"))
    new(Jewl+"roseanklet.c")->move(TO);
   if(!present("rose laurel"))
    new(Jewl+"roselaurel.c")->move(TO);
   if(!present("jewelry 3"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
   if(!present("jewelry 4"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
  if(!present("jewelry 5"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
  if(!present("jewelry 6"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
   if(!present("water lily circlet"))
    new(Jewl+"waterlilycirclet.c")->move(TO);
   if(!present("jewelry 7"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
   if(!present("jewelry 8"))
    new(Jewl+"c_elven_jewelry.c")->move(TO);
}
