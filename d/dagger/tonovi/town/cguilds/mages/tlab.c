// Laboratory in the Marble Academy, Tonovi
// tlab.c

#include <std.h>

inherit "/std/lab";

void create(){
   object ob;
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_property("indoors",1);
   set_property("light",2);
//   set_property("no teleport",1);
   set_name("Mage Laboratory, Marble Academy, Tonovi");
   set_short("Mage Laboratory, Marble Academy, Tonovi");
   set_long("Generic description for the Mage Lab, Marble Academy, Tonovi.");

   set_exits(([
           "south" : "tfloor4",
      ]));
   set_smell("default","Sulfur, carbon, and smoke fill the air around you.");
   set_listen("default","You hear the bubbling of alchemy and the chanting of test casts.");
   set_door("door","tfloor4","south",0);
   set_open("door",0);

   setOwner("none");
   setLabId("tabor");
   ob=new("/d/magic/obj/mirror");
   ob->move(TO);
}
