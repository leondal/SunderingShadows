//road14 - minor changes by Circe to fix mapping problems 12/29/03

#include <std.h>

inherit ROOM;

int flag;

void create()
{
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(RUTTED_TRACK);

    set_indoors(0);
    set_light(2);

    set_short("Rutted road");
    set_long("%^MAGENTA%^Twisting Rutted Road%^RESET%^\n\This is a rutted road twisting to the north and east away from Shadow or south and west toward Shadow. The road is fairly well traveled. The  trees here are thinner then in the deep forest to the south and west.  Yet here there are trees. To the east the land turns to scrub and then to desert or mountains. The road shows signs of heavy wagon travel along with many mounted units traveling both north and south. To the north here stands an old keep that looks to have recently been rennovated. It is rumoured that it once more holds the Alliance of Light.");
    set_listen("default", "The winds create a rustling in the heavy underbrush of this young forest.");
    set_smell("default", "The fresh smells of underbrush reach your nose.");

    set_items(([
                   "ruts" : "These ruts come from the travel of heavy wagons followed by heavy rains.",
                   "underbrush" : "This is heavy grasses, small bushes and some brambles.",
                   "keep" : "This large masonry effort stands watching over the road. It's drawbridge currently stands shut.",
               ]));
    set_exits(([
                   "south" : "/d/shadow/room/pass/road13",
                   "east" : "/d/shadow/room/pass/road15",
                   "north" : "/d/guilds/alliance/hall/bridge",
               ]));

    //set_invis_exits(({"north"}));

    //set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    //set_post_exit_functions(({"north"}),({"gone_north"}));
}

/*int GoThroughDoor() {
   if(query_verb() == "north") {

    tell_room(TO,"The bridge creeks and groans in a mournful tone.");
   return 1;
   if (flag) {
      return 1;
   }
   write("You cannot go that way.");
   return 0;
   }
   }*/

/*void gone_north(){
   tell_object(TP,"You feel a heavy oppressive feeling fall upon you, one of loss and futility.");
   return;
   tell_object(TP,"The drawbridge begins to close after you.");
   tell_room(TO,"The drawbridge closes.");
   flag = 0;
   set_invis_exits(({"north"}));
   }*/


void init()
{
    ::init();

    add_action("open", "open");
}

int open(string str)
{
    if (member_array("Alliance of Light", TP->query_guild()) == -1) {
        return 0;
    }
    if (!str) {
        return notify_fail("Open what?\n");
    }

    if (lower_case(str) != "drawbridge") {
        return notify_fail("Open what?\n");
    }

    TP->force_me("yell Brethren, open the drawbridge.");
    tell_room(TO, "The draw bridge lowers.");
    flag = 1;
    remove_invis_exit("north");
    return 1;
}
