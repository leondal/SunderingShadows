//room for storing regeneration and rejuvenation spells
//no clean so they don't get vaped, so hopefully the 
//spells will stop bugging.  ~Circe~ 6/1/08

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_name("Regeneration Room");
   set_short("Regeneration Room");
   set_long("This is a room for storing regeneration objects.  "+
      "Be gone.\n");
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_indoors(1);
   set_no_clean(1);
}