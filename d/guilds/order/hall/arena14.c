
#include <std.h>
#include <arena.h>
inherit ROOM;


void create() {
   object ob;
   :: create();
   set_terrain(STONE_BUILDING);
   set_travel(RUTTED_TRACK);

   set_short("Caved in Arena Entrance");
   set_property("light",2);    
   //set_property("no teleport",0);
   set_property("indoors",1);
   set_long(
@OLI
      This was once the entrance to the training and sparring area. Once 
grand knights and great mages practiced and worked their skills preparing 
for the battle against evil. This is towards the rear of the stronghold. 
When the sappers broke through the back wall they must have broken a
support for this chamber is entirely caved in. One can only guess, what is
left beyond the mound of rubble.
OLI
            );

   set_items(([
              ]));

   set_exits(([
              "north" : "/d/guilds/order/hall/main.c",

              ]));

   set_smell("default", "It smells of blood here.");

   set_listen("default","You can hear the soothing sounds made by the water in the pool.");
   //set_enter_room("/d/guilds/order/hall/arena1.c");
}
