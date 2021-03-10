//altered 5/30/08 by ~Circe~ for the new temple of Anhur
#include <std.h>

inherit ROOM;

int is_virtual(){ return 1; }

void create(){
   ::create();
   set_terrain(DESERT);
   set_travel(FOOT_PATH);
   set_indoors(0);
   set_light(3);
   set_name("A vast desert");
   set_short("%^ORANGE%^You are in a vast desert.%^RESET%^");
   set_long(
@MELNMARN
%^ORANGE%^You are in a vast desert.%^RESET%^
In most directions, you see nothing but sand for miles.  
A few %^ORANGE%^stones %^RESET%^have been lined up in the 
sand here, leading north and south.
MELNMARN
   );
   set_exits(([
	"east":"/d/shadow/virtual/desert/32,16.desert",
      "west":"/d/shadow/virtual/desert/32,14.desert",
	"north":"/d/shadow/virtual/desert/31,15.desert",
      "south":"/d/shadow/virtual/desert/33,15.desert"
   ]));
   set_smell("default","The dry desert air fills your nostrils.");
   set_listen("default","You can hear the breeze blowing over the sand, it is so quiet here.");
   set_items(([
      "stones" : "The stones are rather large and irregularly "+
         "shaped, and they seem to be laid out in a line rather "+
         "than simply blown here by the wind."
   ]));

}

query_weather() { return "%^BOLD%^%^WHITE%^It is oppressively hot and dry."; }