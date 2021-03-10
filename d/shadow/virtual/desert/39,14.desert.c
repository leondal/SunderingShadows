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
To the south, east, and west, you see nothing but sand for miles. 
Strangely, a large %^BOLD%^stone building %^RESET%^rises to the north 
here, though its entrance is not from this side.  Through the %^CYAN%^windows
%^RESET%^you can see a %^BOLD%^%^BLUE%^marble altar%^RESET%^ inside.
MELNMARN
   );

   set_exits(([
	"south":"/d/shadow/virtual/desert/40,14.desert",
	"east":"/d/shadow/virtual/desert/39,15.desert",
      "west":"/d/shadow/virtual/desert/39,13.desert"
   ]));
   set_smell("default","The dry desert air fills your nostrils.");
   set_listen("default","You can hear the breeze blowing over the sand, it is so quiet here.");
   set_items(([
      ({"temple","building","stone building"}) : "The structure "+
         "of the building combined with the altar visible through "+
         "the glass windows suggest that it may be a temple."
   ]));

}

query_weather() { return "%^BOLD%^%^WHITE%^It is oppressively hot and dry."; }