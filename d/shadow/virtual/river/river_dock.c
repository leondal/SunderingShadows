//dock.c

#include <std.h>
#include <daemons.h>
// don't need these since it will only be ferries running on this
// #define BOAT "/d/shadow/virtual/sea/obj/boat.c"
// #define BOAT_DIR "/d/save/boats/saakrune/"
inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

int clean_up() {return 1;}

void create() {
   ::create();
    set_terrain(VILLAGE);
    set_travel(FOOT_PATH);
   set_property("training",1);
   set_property("no teleport",1);
}

string query_long(string str){
   string hold;

   hold = room::query_long();
   hold += "There is a sign here regarding the services, please read it.\n";
   return hold;
}

int __Read(string str){
   if(!str || str != "sign") return 0;
   write("%^CYAN%^This dock is reserved for the use of the ferries "
	"that travel this river.  They stop here "
	"periodically to pick up or drop off passengers as they travel up "
	"and downstream between.  You must buy a ticket for the section of "
	"river the ferry serves before you will be allowed to travel "
	"on it.  Each ferry is each clearly marked indicating "
	"the price of a ticket and what section of river it travels. "
       );
   return 1;
}

   
