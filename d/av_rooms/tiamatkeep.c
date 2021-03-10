#include <std.h>
#define TEMP "/d/av_rooms/tiamat/"+
inherit "/cmds/avatar/avatar_room.c";
inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(3);
   set_indoors(1);
   set_name("A Ruined Keep");
   set_short("A Ruined Keep");
   set_long("This is a room.  Yay, room!");
   set_smell("default","It reeks of spoiled food and guano.");
   set_listen("default","The silence is only broken by an occassional screech.");
}
