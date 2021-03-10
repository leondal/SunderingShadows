#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("indoors",1);
  set_short(
  "Pig shack."
  );
  set_long(
  "Pig shack.\n"
  "  This low, dimmly lit building is normally supposed to be a haven of shade for the pigs."
  "  Now its swealtering with heat and smells foul from many days of not being cleaned."
  "\n"
  );
  set_smell("default",
  "You smell a dry sickly oder of animal left in the heat."
  );
  set_listen("default",
  "The air hangs heavy and oppressive."
  );
  set_items(([
  "walls":"Heavy wooden walls to keep out the sun and chill of winter when need be.",
  "floor":"Hard packed mud with straw overlay.",
  "straw":"Well used by the pigs for buisiness you'ld rather not get into.",
  ]));
  set_exits(([
  "south":ROOMS"v41.c",
  ]));
}
