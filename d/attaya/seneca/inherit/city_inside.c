//city_outside - inheritable file for Seneca's city streets.
//Hopefully this will make upgrades to the city easier.  ~Circe~ 5/31/07
#include <std.h>

inherit VAULT;

void create(){
   ::create();
   set_name("An Unnamed Room!");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_listen("default","The call of a seagull rises above the bustle of the streets.");
   set_smell("default","A faint hint of the sea stirs on the breeze.");
}