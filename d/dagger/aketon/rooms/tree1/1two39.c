#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Scout headquarters");
   set_long("%^BOLD%^Headquarters of the scouts%^RESET%^
You have entered the headquarters of the local scouts. This is the place "
      "where all the leaders of the local scout regiment gather, discuss "
      "and workout their plans and tatics. Some simple furniture is "
      "here along with some guards that are here to protect their leader from enemies "
      "and intruders. Lots of tools and ropes are there in the racks "
      "close to the wall at the far end of the room.");
   set_items( (["headquarter":"The headquarter of local scouts.",
      "furnitures":"Some desk, chairs and cabinets are here.",
      "guards":"They are assigned by their supperior as bodyguards.",
      "tools":"The scouts use these tools.",
      "rope":"The scouts use the ropes to climb up a tree for clearer and "
      "further views of the local environment.",
      "racks":"Lots of tools and ropes are placed there."]) );
   set_smell("default","You smell the scent of a female.");
   set_listen("default","You hear people chatting nearby.");
   set_exits( (["northwest":RPATH1+"1two31"]) );
}

void reset() {
   ::reset();
   if( !present("aerotia") )
      new(MPATH+"aerotia")->move(TO);
   if( !present("local scout") )
      new(MPATH+"scout")->move(TO);
   if( !present("local infantry") ) {
      new(MPATH+"infantry")->move(TO);
      new(MPATH+"infantry")->move(TO);
   }
   else if( !present("local infantry 2") )
      new(MPATH+"infantry")->move(TO);
   return;
}
