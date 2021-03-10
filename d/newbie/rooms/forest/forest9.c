//forest9.c - Oak tree

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^GREEN%^Massive Oak Tree%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(GAME_TRACK);
   set_long(
@STYX
You've reached a rather quiet spot with a massive, ancient oak tree shading a large part of the area.  There are remnants of acorns scattered all around.  The lower limbs are as thick as a firbolg's thigh and at least fifteen foot from the ground.  The grass under the tree is a little thin from too much shade.  %^ORANGE%^Rocks and gnarled roots have worked their way to the surface along a steep slope to the west and south that leads down to the bank of the nearby lake.%^RESET%^
STYX
   );
   set_smell("default","A faint nutty smell wafts on the breeze.");
   set_listen("default","You hear the chatter of squirrels up in the tree.");
   set_items( ([ 
   	"tree":"There are knobby places on the tree's lower trunk where older limbs have broken off.  The scars left an indentation that you might be able to use for footing to climb.", 
      ({"acorns", "remnants"}):"%^ORANGE%^Pieces of acorns, some partially rotted and old, others still somewhat green and intact, are scattered about.  Mostly you see the woody caps and stems without the nut and they almost look like odd little hats.%^RESET%^",
	({"limb", "limbs"}):"The lowest limbs have broken off over the years but left pieces jutting out or scars that could be used for footing and handholds.",
	({"bank", "grass"}):"%^GREEN%^The grass is thin under the tree and toward the forest.  It becomes thicker and healthier further down the slope to the lake bank where it gets more light.%^RESET%^" ]) );
   set_exits(([
       "northeast":FOREST"forest2",
       "north":FOREST"forest1",
       "southeast":FOREST"forest18",
       "east":FOREST"forest10",
       "south":"/d/newbie/rooms/lake/lake1",
   ]));
}
   void init()
{
        ::init();
        add_action("climb", "climb");
}

int climb(string str)
{
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() ||
TP->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }
        if(!str) {
                write("Climb what?");
                return 1;
        }
        if(str != "tree" && str !="up") {
                write("The only thing to climb here is a tree.");
                return 1;
        }
        else {
                write("You manage to get handholds and footholds enough to climb up to the first limb.");
                tell_room(ETP,""+TPQCN+" uses the limb stumps for handholds and footholds and begins to climb.",TP);
                TP->move_player(FOREST"forest9a");
                return 1;
        }
}
