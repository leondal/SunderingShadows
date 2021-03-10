#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("On the barrack opens");
   set_long("%^BOLD%^%^RED%^On the barrack opens%^RESET%^
You are on an open area within the barracks of the Aketon military. "
      "There are soldiers marching in double file. Some are practicing "
      "with others using weapons or hand-to-hand combat. There are all "
      "kinds of weapons and armours left on the floor for the soldiers to "
      "choose from. Some archers are here guarding the passage way up to "
      "the elders.");
   set_items( (["area":"This is an open area in the barracks here for the "
      "soldiers to practice their different combat skills.",
      "barracks":"The barracks is large and occupied the whole level of "
      "the tree.",
      "soldiers":"There are quite a number of them here, some marching, "
      "some practicing with each other and some are repairing weapons and "
      "armours.",
      ({"weapons","armours"}):"These weapons and armours are left on the "
      "floor on purpose for the soldiers to choose from for practicing.",
      "floor":"Lots of scratchings by metals are observable.",
      "archers":"These archers are here guarding the passage way up to "
      "the city elders. They will shoot arrows at any intruders."]) );
    set_smell("default","You smell the blood of soldiers who were wounded during "
      "practicing.");
    set_listen("default","You hear the sound of weapons clashing against armour.");
   set_exits( (["north":RPATH1+"1two10",
      "northeast":RPATH1+"1two11",
      "south":RPATH1+"1two1",
      "northwest":RPATH1+"1two9"]) );
}

void reset() {
   if( !present("local archer") ) {
      new(MPATH+"archer")->move(TO);
      new(MPATH+"archer")->move(TO);
   }
   if( !present("local infantry") && !random(3) )
      new(MPATH+"infantry")->move(TO);
   if( !present("local infantry 2") && !random(5) )
      new(MPATH+"infantry")->move(TO);
   if( !present("local scout") && !random(3) )
      new(MPATH+"scout")->move(TO);
   if( !present("heavy cavalry") && !random(3) )
      new(MPATH+"cavalry")->move(TO);
}
