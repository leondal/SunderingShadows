#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(RUINS);
   set_travel(RUTTED_TRACK);

   set_short("A broken and ransacked shop");
   set_long(
@OLI
   %^RED%^A broken and ransaked shop%^RESET%^
This old room was once a shop of some form. Even the ransaking that took
place can not hide the pegs and nooks that have been carefully added to the
room. Some form of artisen once called this room his home away from home.
Now a puddle gathers in the hole in the floor. There is much debris here and one other thing.
OLI
   );
   set_property("light",1);
    //set_property("no teleport", 0);
    set_property("indoors",0);
   set_smell("default","This room has the slight smell of chemicals once used here.");

   set_exits(([
   "east":"/d/guilds/order/hall/main"
   ]));

    new("/d/guilds/order/obj/crest")->move(TO);
}

/*
void init(){
   ::init();
   add_action("request","request");
}


int request(){

   write("The painter takes your armour and with love and care paints the grand crest of the Order on it.");
   new("/d/guilds/order/obj/crest")->move(TP);
   return 1;
}

*/
