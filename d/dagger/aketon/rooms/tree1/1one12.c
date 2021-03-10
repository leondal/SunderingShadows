#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("Aketon Alchemy");
   set_long("%^BOLD%^Aketon Alchemy%^RESET%^
This is one of the most welcomed shops around Aketon. As the prosperous "
      "use of magic and spells here, many citizens come here for some "
      "components they need for their spells. The shop is large and is "
      "detailly decorated. You see a counter standing to the north. Some "
      "test tubes and vials are spread all over it. All fashions of "
      "customers are here buying components they need.\nThere is a large "
      "sign on the wall.");
   set_items( (["shop":"This is a spell shop, you can buy all sorts of "
      "components here.",
      "counter":"A rose wood counter.",
      "components":"Don't eat them!",
      ({"test tubes","vials"}):"They are for chemical experiments.",
      ({"people","customers"}):"They are looking for the components they "
      "want.",
      "sign":"<help shop> will give you a list of commands."]) );
   set_smell("default","You smell the odor of chemicals.");
   set_listen("default","You hear the sounds of bubbling liquids.");
   set_exits( (["south":RPATH1+"1one21"]) );
}

void reset() {
   ::reset();
   if( !present("vourolyx") )
      new(MPATH+"vourolyx")->move(TO);
}
