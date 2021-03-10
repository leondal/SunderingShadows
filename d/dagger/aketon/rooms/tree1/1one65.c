#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Avenue of Magiciana");
   set_long("%^GREEN%^Avenue of Magiciana%^RESET%^
You are walking on one of the main broad avenues of the city of Aketon. "
      "The branch of the tree connects to the adjacent tree towards the "
      "southeast. To the northwest is the down town area and the city "
      "center where all the important government structures are located.");
   set_items( ([ ({"avenue","road"}):"A broad road built on the branches "
      "of the tree.",
      "branch":"This branch is connected to the adjacent tree.",
      "northwest":"Down town area is there."]) );
   set_exits( (["northwest":RPATH1+"1one58",
      "southeast":RPATH3+"3one4"]) );
   set_pre_exit_functions( ({"southeast"}),({"no_go"}) );
}

int no_go() {
   if((string)TPQN == "sopzil") return 0;
   return 1;
}
