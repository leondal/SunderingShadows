#include "/d/dagger/aketon/short.h"

inherit "/std/church";

void create() {
   ::create();
   set_short("Aketon Church");
   set_long("%^BOLD%^Aketon Church%^RESET%^
This church is run by the elven priests of Aketon. Citizens come here to "
      "worship their gods. Dead ones come here to pray for resurrection. "
       "Adventurers visit the place occasionally for purification of their "
      "souls and their companions as well.");
   set_items( (["church":"The home of the Aketon priests.", 
      "chamber":"People come here to pray for resurrection when death "
      "brought upon them.",
      "priests":"They dressed in priest robes and praying to the god."]) );
   set_smell("default","You smell the odor of sweet incense.");
   set_listen("default", "You hear the faint sounds of chanting from the "
      "priests.");
   set_property("light",2);
   set_property("indoors",1);
   set_exits( (["south":RPATH1+"1one28"]) );
}
