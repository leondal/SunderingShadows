//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("City of Asgard");
    set_short("Asgard's Gate");
    set_long(
   "You stand before Asgard's massive city gates.  The walls surrounding "+
	"the city look to be at least 20 feet tall.  Towers line the walls, every "+
	"now and then someone pokes their head out scoping the terrain and forest "+
	"outside the city.  The gates to the city are cracked open, perhaps "+
	"bidding you welcome, or perhaps trouble."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A clean, fresh wind blows about.");
    set_listen("default","You can hear the rustle of the city inside the gates.");
*/
   set_long(::query_long()+"\nHere, you can see the ruined pillars "
      "of the city gates which once welcomed visitors to Asgard.\n");
   set_exits( ([
	"bridge":"/d/laerad/parnelli/forest/for049",
	"east":"/d/laerad/parnelli/asgard/as02"
    ]) );
//    set_pre_exit_functions( ({"east"}),({"go_east"}) );
}
int go_east(){
   tell_object(TP,"You walk through the city's gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
