#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Inside the archer walls");
   set_long("%^%^BOLD%^%^RED%^Inside the archer walls%^RESET%^
You have entered one of the many archer walls of the city of Aketon. Some "
      "archers loaded their bows and are ready anytime for a battle. The "
      "walls have only some slits for the archers to shoot arrows at any "
      "target out there and also act as a protection shielding for the "
      "archers to avoid hand-to-hand combat. There are many broken arrows "
      "on the floor.");
   set_items( (["walls":"These are the archer walls.",
      "archers":"They look mean and are all ready for the coming battles.",
      "slits":"These slits are for the archers to shoot arrows at enemies "
      "outside.",
      "arrows":"They are broken and dumpped on the floor.",
      "bows":"Some standard crossbows.",
      "floor":"Lots of broken arrows are there. There looks like a hole "
      "covered by a grate."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city coming from beneath "
      "your feet.");
   set_exits( (["northwest":RPATH1+"1two32",
      "down":RPATH1+"1one50"]) );
   set_invis_exits( ({"down"}) );
   set_pre_exit_functions( ({"down"}),({"down_func"}) );
}

void reset() {
   if( !present("local archer") ) {
      new(MPATH+"archer")->move(TO);
      new(MPATH+"archer")->move(TO);
   }
   if( !present("local infantry") )
      new(MPATH+"infantry")->move(TO);
}

int down_func() {
   if( (int)SAVE_D->is_member("aketon_list",TPQN) != -1 ) {
      write("You lift up a secret grate and jumps down.");
      return 1;
   }
   else {
      write("You cannot lift up the grate!\n");
      return 0;
   }
}
