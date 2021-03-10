#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;


string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("At the start of a truncated quest journey");
  set_short("%^BOLD%^%^CYAN%^At the start of a truncated quest"
           +" journey%^RESET%^");
  set_long( "Welcome to the start of your test journey through Lujke's"
           +" Tecqumin area quest thingy. Branching off from this room are"
           +" a variety of people and places who will be found in different"
           +" places in the finished area. Please walk round, explore, talk"
           +" to NPCs, etc, and see how far you can get with the quest. The"
           +" NPCs have been designed a bit differently to regular ones on"
           +" SG: They have more information to give out, and some of them"
           +" won't reveal all they know right away; some information is"
           +" unlocked by doing something or learning about something else."
           +" In the final version, you would be likely to meet some of"
           +" these people earlier than others, but for the purpose of"
           +" testing it shouldn't matter.\n"
           +" It would be really helpful if you can provide a log of your"
           +" interactions, so Lujke can see how you get on. Also, if you"
           +" try talking to an NPC about something that you think they"
           +" ought to give a response to, but they remain silent, please"
           +" tell Lujke about this - preferably with a suggestion of what"
           +" you think the NPC ought to be saying in response.\n"
           +" As you talk to various of the NPCs, you may notice that you"
           +" acquire new mini quests. Please do not be alarmed, this is"
           +" intentional." );
  set_items(([  ]));
  set_smell("default","There is a damp, musty smell in here.");
  set_listen("default","The only sounds drift in from the jungle outside.");
  set_exits( ([ "north" : TEST + "jont_room",
                "northwest" : TEST + "qual_room",
                "northeast" : TEST + "throne_room",
                "southeast"      : TEST + "meha_room",
                "east" : TEST + "tal_room",
                "south"      : TEST + "guardcham",
                "southwest"  : TEST + "carved_gate",
                "down"      : TEST + "head_room",
                "up"        : TEST + "tower"]) );
}


