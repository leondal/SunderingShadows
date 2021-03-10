#include <std.h>
#include <config.h>

inherit ROOM;
inherit "/std/virtual/compile";

#define BASE "/d/dagger/virtual/sea/"
#define SUFFIX ".sea"
#define DESERT_DAEMON "/d/dagger/virtual/sea_daemon.c"
//#define MONDIR "/d/shadow/mon/"

int x,y;
object ob;

int is_virtual() {return 1;}
int is_water() {return 1;}

void virtual_setup(string arg) {
   int i,x1,x2,y1,y2;
   string north, south, east, west ;
   seteuid(getuid());
   sscanf(arg,"%d,%d",x,y);
   south = BASE + (x+1) +  "," + y       + SUFFIX ;
   east = BASE + x       +  "," + (y+1) + SUFFIX;
   north  = BASE + (x-1) +  "," + y       + SUFFIX;
   west = BASE + x       +  "," + (y-1) + SUFFIX;
   set_property("light", 3);
   set_exits( ({}), ({}) );
   i = (int)DESERT_DAEMON->get_exits(x,y) ;
   if(!(i%2)) {add_exit(west , "west"  );}
   if(!((i/2)%2)) {add_exit(east , "east"  );}
   if(!((i/4)%2)) {add_exit(south, "south" );}
   if(!((i/8)%2)) {add_exit(north, "north" );}
}

string query_short() {
   return(string)DESERT_DAEMON->get_short(x,y);
}

string query_long(string item) {
   if(item) {
      return((string)this_object()->describe(item));
   }
   else {
      return(string)DESERT_DAEMON->get_short(x,y)+"\n"+(string)DESERT_DAEMON->get_long(x,y);
   }
}

string query_smell(string str) {
   if(!str) return 0;
   if(str != "default") return 0;
   /*if(y > )
      return "You can smell the arid desert air blowing from the west.";
   else if(y < 2)
      return "You can smell the fresh scent of earth to the east.";
   else
   */
      return "You can smell the fresh sea air.";
}
string query_listen(string str) {
   if(!str) return 0;
   if(str != "default") return 0;
   
   return "You hear the lapping of waves against the side of the boat.";
   /*if(y > 19)
      return "You can hear the crashing waves to the east.";
   else if(y < 1)
      return "You can hear the crashing waves to the east.";
   else
      return "You hear the silence of the open sea.";
      */
}

void init() {
   ::init();
}
