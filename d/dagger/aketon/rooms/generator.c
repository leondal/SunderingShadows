#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void repeat_func();

void create() {
   ::create();
   set_property("light",3);
   set_smell("default","You are assulted by the many smells of the "
      "forest.");
   set_listen("default","You hear the sounds of the city all around you.");
}

void init() {
   ::init();
   if(!interactive(TP))
      return;
   if(random(2) && !present("akemon 3"))
      repeat_func();
}

void reset() {
   ::reset();
   if( !pointerp(TO->query_exits()) || !sizeof(TO->query_exits()) )
      return;
   if( present("akemon 3") )
      return;
   repeat_func();
   return;
}

void repeat_func() {
   object mon;
   switch( random(50) ) {
      case 0..4:
         mon = new(MPATH+"citizenA");
         mon->add_id("akemon");
         mon->move(TO);
         if( random(2) ) repeat_func();
         break;
      case 5..10:
         mon = new(MPATH+"citizenB");
         mon->add_id("akemon");
         mon->move(TO);
         if( random(2) ) repeat_func();
         break;
      case 11..14:
         mon = new(MPATH+"citizenC");
         mon->add_id("akemon");
         mon->move(TO);
         if( random(2) ) repeat_func();
         break;
      case 15..19:
         mon = new(MPATH+"citizenD");
         mon->add_id("akemon");
         mon->move(TO);
         if( random(2) ) repeat_func();
         break;
      case 20..24:
         mon = new(MPATH+"citizenE");
         mon->add_id("akemon");
         mon->move(TO);
         if( random(2) ) repeat_func();
         break;
      case 25..29:
         mon = new(MPATH+"citizenF");
         mon->add_id("akemon");
         mon->move(TO);
         if( random(2) ) repeat_func();
         break;
      case 30..34:
         if( present("akeguard 2") ) {
            repeat_func();
            break;
         }
         mon = new(MPATH+"guardA");
         mon->add_id("akemon");
         mon->add_id("akeguard");
         mon->move(TO);
         if( !random(3) ) repeat_func();
         break;
      case 35..39:
         if( present("akeguard 2") ) {
            repeat_func();
            break;
         }
         mon = new(MPATH+"guardB");
         mon->add_id("akemon");
         mon->add_id("akeguard");
         mon->move(TO);
         if( !random(3) ) repeat_func();
         break;
      case 40..44:
         if( present("akeguard 2") ) {
            repeat_func();
            break;
         }
         mon = new(MPATH+"guardC");
         mon->add_id("akemon");
         mon->add_id("akeguard");
         mon->move(TO);
         if( !random(3) ) repeat_func();
         break;
      case 45..49:
         repeat_func();
         break;
   }
   return;
}
