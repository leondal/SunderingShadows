#include <std.h>
#include "../inherit/keep.h"
inherit CVAULT;

void create() {
   ::create();
   set_repop(60);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A guard lounge");
   set_short("%^CYAN%^A guard lounge%^RESET%^");
   set_long("%^CYAN%^A guard lounge%^RESET%^\n"
"This room was once probably a lounge room for the keep guards when they were "
"off-duty, judging by its placement and now-ruined furnishings.  The %^BLUE%^"
"floor %^RESET%^is caked with dirt, making the criss-crossing tracks of some "
"small creature more obvious to view.  There is a broken %^ORANGE%^table "
"%^RESET%^in one corner with several smashed %^ORANGE%^chairs %^RESET%^around "
"it.  Two %^RED%^couches %^RESET%^stand against the opposite wall, but they are "
"both rather torn up and covered in mildew and mud.  A few kegs of %^YELLOW%^"
"ale %^RESET%^lay smashed in another corner, along with a small %^BLUE%^cabinet "
"%^RESET%^of broken dishes.\n");
   set_smell("default","The scent of mildew permeats the room.");
   set_listen("default","You hear the scrabbling of tiny claws across stone.");
   set_items(([
     "floor" : "%^BLUE%^The floor is caked in dirt, revealing an array of small "
"clawed footprints that track their way across the room.%^RESET%^",
     ({"table","chairs"}) : "%^ORANGE%^A broken table lies in one corner, "
"leaning sadly on one leg.  A few smashed chairs lie about, some partially "
"intact but obviously none that are serviceable any longer.%^RESET%^",
     "couches" : "%^RED%^The two couches in the room have seen better days.  "
"You suspect they may once have been a deep burgundy color, but they have been "
"ripped and torn, and are covered in a layer of mud, dust, and mildew.%^RESET%^",
     ({"cabinet","dishes"}) : "%^BLUE%^The remains of a small wooden cabinet "
"are in the southeastern corner.  It once held a few mugs and plates that are "
"now smashed on the floor amidst its shattered remains.%^RESET%^",
     ({"ale","kegs"}) : "%^YELLOW%^A few kegs that once probably held ale lay "
"smashed near the cabinet in the southeastern corner.%^RESET%^",
   ]));
   set_exits(([
     "north" : ROOMS"keep12",
   ]));
   set_door("door",ROOMS"keep12","north",0);
   set_door_description("door","%^ORANGE%^A simple wooden door, scratched and "
"grimy from years of abuse, but still intact.%^RESET%^");
   set_string("door","open","The door squeaks open.");
   set_string("door","close","The door squeaks shut.");
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
      if(mons) mons = ([]);
      set_monsters(({MONS"xvart"}),({random(3)+1}));
   }
   ::reset();
}
