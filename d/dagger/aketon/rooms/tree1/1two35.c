#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Infantry headquarters");
   set_long("%^BOLD%^Headquarters of the infantry%^RESET%^
You have entered the headquarters of the local infantry. This is the place "
      "where all the leaders of the local infantry regiment gather, discuss "
      "and workout their plans and tatics. Some simple furnitures are "
      "here and some guards here to protect their leader from enemies "
      "and intruders. Some racks of weapons and armours is placed near "
      "the wall.");
   set_items( (["headquarter":"The headquarter of local infantry.",
      "furnitures":"Some desk, chairs and cabinets are here.",
      "guards":"They are assigned by their supperior as bodyguards.",
      "weapons":"These are the favourite weapons of the infantry.",
      "armours":"These are the standard armours used by the infantry."]) );
   set_smell("default","You smell rust.");
   set_listen("default","Sounds of metal clinking fills your ear.");
   set_exits( (["northeast":RPATH1+"1two29"]) );
}

void reset() {
   ::reset();
   if( !present("goginet") )
      new(MPATH+"goginet")->move(TO);
   if( !present("infantry") ) {
      new(MPATH+"infantry")->move(TO);
      new(MPATH+"infantry")->move(TO);
      new(MPATH+"infantry")->move(TO);
   }
   else if( !present("local infantry 2") ) {
      new(MPATH+"infantry")->move(TO);
      new(MPATH+"infantry")->move(TO);
   }
   else if( !present("local infantry 3") )
      new(MPATH+"infantry")->move(TO);
   return;
}
