#include <std.h>
#define TEMP "/d/av_rooms/"+

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(3);
   set_indoors(1);
   set_name("Warehouse in Tharis");
   set_short("Warehouse in Tharis");
   set_long("This is a room.  Yay, room!");
   set_smell("default","A dusty and dirty area brings dust and dirt.");
   set_listen("default","An occasional drunk sings loudly and a security guard yells.");
   set_exits(([
      "west" : TEMP"lurue_tharis1"
   ]));
}