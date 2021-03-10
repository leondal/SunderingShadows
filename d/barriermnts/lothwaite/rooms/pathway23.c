//pathway23.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEND;

void create(){
   ::create();
   set_long( ::query_long()+"  This seems to be the main pathway through the town.  "+
      "The path runs straight here for awhile, and a %^YELLOW%^large inn "+
      "%^RESET%^%^GREEN%^stands just "+
      "north of the path.  A %^ORANGE%^wooden sign %^GREEN%^has been nailed "+
      "just beside the door.  Another %^ORANGE%^building %^GREEN%^stands to "+
      "the south.\n");
   add_item("inn","A large wooden building much like the others of Lothwaite.  "+
      "Its massive wooden door stands closed against the weather.  A puff of deep "+
      "gray smoke rises from the round chimney in the center of the roof.  This "+
      "building bears a sign proclaiming it the %^YELLOW%^Golden Perch Inn"+
      "%^RESET%^, and it seems to have people constantly coming and going.");
   add_item("building","The building to the south seems to be a shop "+
      "of some sort.  There are no windows, but a small plaque above "+
      "the door bears the sign of a needle and thread.");
   add_item("sign",(:TO,"signdesc":));
   set_exits(([
      "west" : PATHEXIT"pathway22",
      "east" : PATHEXIT"pathway24",
      "north" : PATHEXIT"inn1",
      "south" : PATHEXIT"clothing"
   ]));
   set_door("door",PATHEXIT"inn1","north",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
   set_door("pine door",PATHEXIT"clothing","south",0);
   set_door_description("pine door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

void signdesc(){
   write(
"\n"
"      %^YELLOW%^            .:%^RESET%^%^ORANGE%^/ \n"
"               %^YELLOW%^,,%^RESET%^%^ORANGE%^///%^YELLOW%^;,   ,%^RESET%^%^ORANGE%^// \n"
"        %^BOLD%^%^BLUE%^      o%^YELLOW%^:::::::;;%^RESET%^%^ORANGE%^/// \n"
"          %^RESET%^%^ORANGE%^   >%^YELLOW%^:%^RESET%^%^RED%^))%^YELLOW%^:::::;;%^RESET%^%^ORANGE%^\\\\\\  \n"
"         %^YELLOW%^      ''%^RESET%^%^ORANGE%^\\\\\\\\%^YELLOW%^''  '%^RESET%^%^ORANGE%^\\\\ \n"
"                   \\\\ \n"
"                     `%^YELLOW%^\n"
"    __               _          ___\n"
"   /__ _ | _| _ ._  |_)_ .__|_   | ._ ._\n"
"   \\_|(_)|(_|(/_| | | (/_|(_| | _|_| || |\n"
"\n"
"%^RESET%^%^ORANGE%^~ %^BOLD%^%^BLUE%^Where all weary travellers may find rest %^RESET%^%^ORANGE%^~"
   );
}