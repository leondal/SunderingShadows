#include <std.h>
#include "keep.h"
inherit VAULT;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Guard's Lounge");
   set_long(
   "This room was once probably a lounge room for the keep guards, although it is hard"+
   " to tell for sure because the room is in such ruins. There is a broken table in"+
   " one corner with several smashed chairs around it. Two couches are in the room,"+
   " but they are both rather torn up and covered in mildew and mud. A few kegs of"+
   " ale lay smashed in another corner, along with a small cabinet of broken dishes."
   );
   set_smell("default","The scent of mildew permeats the room.");
   set_listen("default","You hear the scrabbling of tiny claws across stone.");
   set_items(([
   "floor" : "The floor is caked in mud, dirt, and grime. The occupants of the room"+
   " were none too neat, and judging from a few tracks you can make out, they were"+
   " also rather small.",
   "ceiling" : "The ceiling has a few cobwebs clinging to it in places but appears"+
   " as though it will hold up.",
   ({"wall","walls"}) : "The walls of the room appear fairly sturdy and have no"+
   " large cracks in them.",
   ({"couch","couches"}) : "The two couches in the room have seen better days. They"+
   " were once a deep burgundy color you believe, but they have been ripped and torn"+
   " and covered in mud, dust, and mildew.",
   "table" : "There is a smashed table in the southwestern corner that was once"+
   " probably used for dice and other games of chance.",
   "chairs" : "The chairs surrounding the table are mostly smashed, two are still"+
   " standing although they appear rather wobbly and probably wouldn't hold much weight.",
   "cabinet" : "The remains of a small wooden cabinet are in the southeastern corner,"+
   " it once held a few mugs and plates that are now smashed on the floor.",
   ({"dishes","broken dishes"}) : "Broken dishes surround the tiny cabinet that once"+
   " held them in the southeastern corner.",
   ({"keg","kegs"}) : "A few kegs that once probably held ale lay smashed near the"+
   " cabinet in the southeastern corner.",
   "door" : "The door to the north appears sturdy enough, despite many scratches and"+
   " some decay.",
   ]));
   set_exits(([
   "north" : ROOMS+"keep25",
   ]));
   set_door("door",ROOMS+"keep25","north","keep master_key");
   set_string("door","open","The door squeaks open.");
   set_string("door","close","The door squeaks shut.");
}

void reset()
{
   ::reset();
   if(!present("xvart")) {
      switch(random(3) && !random(2)) {
         case 0:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
         case 1:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
         case 2:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
      }
   }
}
