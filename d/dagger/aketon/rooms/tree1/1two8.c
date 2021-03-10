#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Archer headquarters");
   set_long("%^BOLD%^Headquarters of the archers%^RESET%^
You have entered the headquarters of the local archers. This is the place "
      "where all the leaders of the local scout regiment gather, discuss "
      "and workout their plans and tatics. Some simple furniture is "
       "here along with some guards that are here to protect their leader from enemies "
      "and intruders. There is a rack of bows here, and numerous quivers of different types of "
      "arrows are placed in the cupboards by the wall.");
   set_items( (["headquarter":"The headquarter of local archers.",
      "furnitures":"Some desk, chairs and cabinets are here.",
      "guards":"They are assigned by their supperior as bodyguards.",
      ({"rack","bows"}):"These are the favourite weapons of the archers.",
      ({"quivers","arrows"}):"These are the ammunitions for bows.",
      "cupboards":"The weapons are stored in them."]) );
   set_smell("default","You smell the scent of a female.");
   set_listen("default","You hear chatting.");
   set_exits( (["southeast":RPATH1+"1two16"]) );
}

void reset() {
   ::reset();
   if( !present("rotatia") )
      new(MPATH+"rotatia")->move(TO);
   if( !present("local archer") )
      new(MPATH+"archer")->move(TO);
   if( !present("local infantry") ) {
      new(MPATH+"infantry")->move(TO);
      new(MPATH+"infantry")->move(TO);
   }
   else if( !present("local infantry 2") )
      new(MPATH+"infantry")->move(TO);
   return;
}
