#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Cavalry headquarters");
   set_long("%^BOLD%^Headquarters of the cavalry%^RESET%^
You have entered the headquarters of the local cavalry. This is the place "
      "where all the leaders of the local scout regiment gather, discuss "
      "and workout their plans and tatics. Some simple furniture is "
      "here along with some guards that are here to protect their leader from enemies "
       "and intruders. The room is very large and it can contain some "
      "large animals like the hippogriffs used by the cavalry.");
   set_items( (["headquarter":"The headquarter of local cavalry.",
      "furnitures":"Some desk, chairs and cabinets are here.",
      "guards":"They are assigned by their supperior as bodyguards.",
      "room":"The room is very large and can contain some mounts.",
      "animals":"These hippogriffs are the favourite mounts of the Aketon "
      "cavalry regiment."]) );
   set_smell("default","You smell the bad smells of hippogriffs.");
   set_listen("default","You hear noises from outside.");
   set_exits( (["southwest":RPATH1+"1two18"]) );
}

void reset() {
   ::reset();
   if( !present("lugabet") )
      new(MPATH+"lugabet")->move(TO);
   if( !present("heavy cavalry") )
      new(MPATH+"cavalry")->move(TO);
   if( !present("local infantry") ) {
      new(MPATH+"infantry")->move(TO);
      new(MPATH+"infantry")->move(TO);
   }
   else if( !present("local infantry 2") )
      new(MPATH+"infantry")->move(TO);
   return;
}
