//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

object ob;
void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Excalibur roadfork");
    set_short("Excalibur roadfork");
    set_long(
	"%^BOLD%^Excalibur roadfork%^RESET%^
You are on Asgard's main city road.  The cobblestone street leads west "+
   "to the residential area and east towards the city park.  Asgard's "+
	"inner city lies east past the city park.  You can see the backs of "+
	"the buildings in the residential area from here as well as a few "+
	"back alleys on either side of the road."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","A peaceful quiet settles on the area.");
    ob=new(BBOARD);
    ob->set_name("board");
    ob->set_id(({"board","asgards board"}));
    ob->set_board_id("asboard");
    ob->set_max_posts(30);
    ob->set_location("/d/laerad/parnelli/asgard/as08");
    ob->set_short("Asgard's city board");
    ob->set_long("This is Asgard's city board.  People can posts their thoughts about anything here. ");
*/
   set_long(::query_long()+"\nThis was once the hub of Asgard, where "
      "roads met and various citizens discussed events and posted "
      "notices.  Now the city board lies among the rubble, still "
      "covered with bits of parchment.\n");
    set_property("training",1);
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as07",
	"east":"/d/laerad/parnelli/asgard/as09",
	"northeast":"/d/laerad/parnelli/asgard/as11",
	"southeast":"/d/laerad/parnelli/asgard/as12"
    ]) );
}
