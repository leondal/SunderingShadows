//Coded by Bane//
//Moved sewers to Daggerdale - Cythera 6/7
#include <std.h>
//#include "/d/laerad/parnelli/asgard/sewer/lizard.h"
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
    set_name("Back alley");
    set_short("Back alley");
    set_long(
    "%^BOLD%^A back alley%^RESET%^ \n"+
    "You are standing in a back alley.  Trash litters the street and dirty water "+
	"gushes down the sides of the road.  The cobblestone street leads into "+
	"more dark alleys to the west, east and south.  You notice a few homeless people "+
    "wandering through the alley.  Water runs through a metal grate in the street and "+
    "splashes into the darkness."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","The alley is very quiet.");
*/
    set_items(([
        "grate":"Rusted and grimy, the grate looks to cover the entrance to the sewers. Perhaps you can lift it."
    ]));
    set_search("grate","You see a dirty, rusted and grimy sewer cover. Perhaps you could lift it?");

   set_long("You are standing in the ruins of Asgard.  All around you, "
      "buildings have been toppled, leaving rubble strewn about the "
      "streets.  In some places, walls have been reduced to piles of "
      "tiny stones, while in others, they stand largely untouched.  "
      "Here and there, the ground seems compressed, giving the only "
      "clue as to what could have caused such total destruction.  Between "
      "the stones, %^GREEN%^grass%^RESET%^ and %^ORANGE%^moss %^RESET%^have "
      "begun to grow, perhaps a sign of life returning. At your feet, "
      "an old and rusted %^RED%^grate %^RESET%^lies embedded within the "
      "stone.\n");
    set_exits(([
	"east":"/d/laerad/parnelli/asgard/as86",
	"south":"/d/laerad/parnelli/asgard/as78",
	"west":"/d/laerad/parnelli/asgard/as87"
    ]));
}

void init() {
  ::init();
  add_action("lift","lift");
}

int lift(string str) {
    if(!str) {
        tell_object(TP,"Lift what?");
        return 1;
        }
    if((str == "grate") || (str == "rusted grate")){
        if(member_array("hole",TO->query_exits()) != -1) {
             tell_object(TP,"%^GREEN%^The grate has already been removed!%^RESET%^");
            return 1;
            }
     tell_object(TP,"You %^RED%^strain%^RESET%^ to lift the heavy grate. \n"+
             "You finally break the grate free of its rust and dirt and "+
            "see a hole leading into the dark smelly sewers!  \n");
     tell_room(ETP,""+TPQCN+" strains and lifts the grate to open an "+
            "entrance to the sewers.\n",TP);
     add_exit("/d/laerad/parnelli/asgard/sewer/rooms/sw1","hole");
     tell_room(ETP,"You see a hole leading down into the sewers.\n");
     return 1;
     }
}