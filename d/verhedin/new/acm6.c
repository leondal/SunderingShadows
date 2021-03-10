// Sixth Legion Square, Verhedin
// Thorn@ShadowGate
// 001127
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^RED%^Sixth %^BLACK%^Legion%^YELLOW%^ Square%^WHITE%^, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^RED%^Sixth %^BLACK%^Legion%^YELLOW%^ Square%^WHITE%^, Verhedin%^RESET%^
You are in what appears to be a busy intersection of roads in the city. 
This section of cobbled street looks like it might be busy at all times
of day.  Everywhere, you see wagons, boxes and teamsters rolling in and
out, mostly to the north and south.  This makes sense as you can make
out a large gate a short distance to the north. 

In the center of the intersection, you can see a great golden obelisk
with a crescent moon attached to the pointed tip.  There is a plaque on
the obelisk.  There is also what looks like a signpost placed in front
of the monument.

You can go east, north, south, or west from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm7",
    "west" : VNEW+"acm5",
    "north" : VNEW+"sol1",
    "south" : VNEW+"sol2"
   ]));
  set_listen("default","You hear the sounds of carts and wagons travelling by.");
  set_smell("default","You detect the scent of incense in the air.");
  set_items( ([
    "obelisk"  : "A tapered, four-sided golden shaft that rises to a point.  "
	            "This obelisk has a crescent at the point and a plaque on "
				"the base.",
    "monument" : "A tapered, four-sided golden obelisk.  "
	            "This monument has a crescent at the point and a plaque on "
				"the base that you could look at.",
    "plaque"   : "%^WHITE%^BOLD%^                          *\n"
                 "                        **#**\n"
                 "                  *      * *     *\n"
                 "                **#**          **#**\n"
                 "                 * *            * *\n"
                 "           *                           *\n"
                 "         **#**                       **#**\n"
                 "          * *                         * *\n"
                 "\n"
                 "%^YELLOW%^      #*      %^RED%^To the brave soldiers of%^YELLOW%^     #\n"
                 "      ##*        %^RED%^Legion VI Verhedin%^YELLOW%^       ##\n"
                 "      ####                              *###\n"
                 "      a####*                           *####\n"
                 "       ######*                      **#####a\n"
                 "       a########**               *#########\n"
                 "         ############********############a\n"
                 "          ##############################a\n"
                 "           a##########################a\n"
                 "              a#####################a\n"
                 "                 aaa###########aaa\n"
                 "                        aaa\n",
    "signpost" : "%^MAGENTA%^BOLD%^Welcome to the city of Verhedin.\n"
	           "Capital of the Imperial Province of Verhedin\n\n"
	           "%^GREEN%^Imperial laws strictly enforced.%^RESET%^\n\n"
	           "%^RED%^BOLD%^North - South:%^WHITE%^ Street of the Legions\n"
	           "%^RED%^BOLD%^East - West:  %^WHITE%^ Avenue of the Crescent Moon",
  ]) );
}

void reset(){
	::reset();
}
