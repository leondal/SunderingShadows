#include <std.h>
#include "../tharis.h"

inherit STORAGE"trade";
inherit "/std/rquestroom.c";

void create(){
   ::create();
    set_long("%^RESET%^%^CYAN%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^BLUE%^Shadovar %^CYAN%^fortress, far in the sky above. It casts the entire city under "
"a pall of unrelenting %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^. Below, the citizens of the city go "
"about their day-to-day activities, a constant stream of feet passing over the well-kept "
"%^ORANGE%^cobblestones%^CYAN%^. To either side rise what appear to be relatively new buildings, some "
"not even quite complete and clearly still under construction. Above them rise the impressive spires of "
"the city cathedral to the east, while to the west lies the far shorter, but no less impressive, half-arc "
"of the mage tower. A bit further southwards, the city comes up short against a series of %^BLUE%^mountains"
"%^CYAN%^, barely more than hills at first, but growing progressively more impressive as they recede into "
"the distance. Just a little further north, the main city bazaar opens up into a scene of semi-organized "
"%^MAGENTA%^chaos%^CYAN%^.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"tharis_church1",
      "west" : ROOMS"tharis_mage_outside",
      "north" : ROOMS"square5",
      "south" : ROOMS"north6",
   ]));
   add_item("buildings","%^CYAN%^The buildings here seem to be quite new, some not even entirely "
"complete just yet. It looks as though this section of the city is being gradually rebuilt. A few "
"sections of rubble still remain between the existing structures, likely remnants of whatever "
"buildings once stood here and are now being replaced. A few teams of builders can be spotted "
"in and around some of the structures, hard at work even as you watch. Above them all rise "
"the majestic spires of the cathedral, which lies directly opposite the shorter, but equally "
"impressive half-arc of the city mage tower. Their stature is not even remotely approached by the "
"lesser buildings nearby.%^RESET%^");

    set_quest_daemon("/daemon/quests_mid");
    if (!clonep(TO) && !present("deku board", TO))
    {
        object ob;

        ob = new("std/bboard");
        ob->set_name("board");
        ob->set_id(({"board","bulletin board"}));
        ob->set_board_id("union_board");
        ob->set_queue();
        ob->set_max_posts(30);
        ob->set_location("/d/tharis/newtharis/rooms/north5");
        ob->set_short("%^RESET%^%^GREEN%^Arcane Bulletin Board%^RESET%^");
        ob->set_long("This is an aging wooden board where adventurers sometimes leave notes "
        "related to their travels or business..\n");
    }
}

void reset()
{
    ::reset();
    if(!present("golem")){new(MOBS"bladegolem.c")->move(TO);}
    if(!present("golem 2")){new(MOBS"bladegolem.c")->move(TO);}
    if(!present("golem 3")){new(MOBS"bladegolem.c")->move(TO);}
}
