#include <std.h>
#include "../dagger.h"
inherit CROOM;
//Based on the vote - moved Asgard sewers to Daggerdale
//Cythera 6/07
// Lizards have been moved back to Asgard in preparation for Daggerdale rewrite. N, 4/16.

void create(){
    set_monsters(({MON"ghost"}),({1}));
    ::create();
    set_repop(35);
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("A ruined street");
    set_short("%^BOLD%^%^BLACK%^A ruined street%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand on a ruined street. It was obviously the scene of a %^RESET%^%^RED%^"
"bloody battle%^BOLD%^%^BLACK%^, as the ground is pockmarked with small craters and the fine cobblestones have "
"been mostly ruined  Water runs through a metal grate in the street and splashes into the darkness.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");
/*    set_items(([
        "grate":"Rusted and grimy, the grate looks to cover the entrance to
the sewers.  Perhaps you can lift it."
        ]));
    set_search("grate","%^GREEN%^You see a dirty, rusted and grimy sewer cover.  "+
            "Perhaps you could lift it?"); */
    set_exits(([
      "west" : STREETS"street40",
      "east" : STREETS"street42",
    ]));
}

// moved back to Asgard in preparation for Daggerdale rewrite. N, 4/16.
/*void init() {
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
             tell_object(TP,"%^BOLD%^^%GREEN%^The grate has already been removed!");
            return 1;
            }
     tell_object(TP,"You strain to lift the heavy grate. \n"+
             "You finally break the grate free of its rust and dirt and "+
            "see a hole leading into the dark smelly sewers!  \n");
     tell_room(ETP,""+TPQCN+" strains and lifts the grate to open an "+
            "entrance to the sewers.\n",TP);
     add_exit("/d/laerad/parnelli/asgard/sewer/rooms/sw1","hole");
     tell_room(ETP,"You see a hole leading down into the sewers.\n");
     return 1;
     }
}
*/