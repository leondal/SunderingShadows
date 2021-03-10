//Coded by Lujke//
#include <std.h>
#include "../tecqumin.h"
inherit ROOM;

void create(){
  object jetstone;
  ::create();
  set_storage(1);
  set_short("A bland storeroom");
  set_long(("Yeah, somewhere to put things"));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_property("indoors",1);
  set_property("light",2);
  
  set_smell("default","This room smells of immortal trickery");

  set_listen("default","You can hear someone plotting in the background");
  jetstone = new (OBJ + "jetstone");
  jetstone->move(TO);
  jetstone = new (OBJ + "head");
  jetstone->move(TO);
}

void reset(){
  object jetstone;
  ::reset();
  jetstone = present("jetstone", TO);
  if (!objectp(jetstone)&&random(2)>0){
    jetstone = new (OBJ + "jetstone");
    jetstone->move(TO);
  }
  jetstone = present("shrunken head", TO);
  if (!objectp(jetstone)&&random(2)>0){
    jetstone = new (OBJ + "head");
    jetstone->move(TO);
  }

}
