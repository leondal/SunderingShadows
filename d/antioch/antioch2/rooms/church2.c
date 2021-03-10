#include <std.h>
#include "../antioch.h"
inherit ROOM;

int found;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("%^BOLD%^Grand Church of Antioch");
    set_long(
        "%^WHITE%^This is a quiet little room. The normal prayers of the acolytes can't be heard here and there is a sense of peace. There are stone %^BOLD%^%^BLACK%^she%^WHITE%^l%^BLACK%^ves%^RESET%^%^WHITE%^ on the left and right sides of the room that hold sacred statues. On the right hand shelf there are three statues. One is of Ignatius, demi-god and once the supreme ruler and protector of Antioch. A little ways away from him, in the center of the shelf, is the statue of a deformed creature that is mostly hidden beneath dark cloaks. That is probably whatever evil force took over Antioch. On the far side of it is a statue of Kelemvor, god of the dead, garbed in a long flowing robe with a scythe in his hand. On the left hand shelf is a symbol of Jarmila. Spaced out from it is a replica of a fortified town, probably Antioch. Beyond that is a delicate statue of a unicorn, the symbol of purity and innocence. The only thing on the %^BOLD%^%^WHITE%^southern %^BLACK%^wall%^RESET%^%^WHITE%^ is a %^BOLD%^%^ORANGE%^cross.%^RESET%^
"
        );
    set_smell("default", "There is a slightly dusty scent in the room.");
    set_listen("default", "If you listen carefully you can hear a" +
               " faint splashing of water.");
    set_items(([
                   ({ "shelf", "shelves" }) : "Two large stone shelves that seems to come" +
                   " out of the walls themselves are here. One is on the right hand" +
                   " side of the room and the other on the left. Both hold statues.",
                   ({ "right shelf", "right hand shelf", "shelf 1" }) : "The shelf on the right" +
                   " hand side of the room holds three statues. One is of Ignatius," +
                   " demi-god and once the supreme ruler and protector of Antioch." +
                   " A little ways away from him, in the center of the shelf, is the" +
                   " statue of a deformed creature that is mostly hidden beneath dark" +
                   " cloaks. That is probably whatever evil force took over Antioch." +
                   " On the far side of it is a statue of Kelemvor, god of the dead," +
                   " garbed in a long flowing robe with a scythe in his hand.",
                   ({ "left shelf", "left hand shelf", "shelf 2" }) : "The shelf on the left hand" +
                   " side of the room holds three statues. The first is a symbol of" +
                   " Jarmila. Next to it is a replica of a fortified town," +
                   " probably Antioch. Beyond that is a delicate statue of a unicorn," +
                   " the symbol of purity and innocence.",
                   "south wall" : "The only thing on the southern wall" +
                   " is a slightly tilted cross.",
                   "cross" : "This cross hangs on the south wall and has been" +
                   " carelessly left tilted.",
                   ]));
    set_exits(([
                   "north" : ROOMS + "church1",
                   ]));
}

void reset()
{
    ::reset();
    found = 0;
}

void init()
{
    ::init();
    add_action("straighten", "straighten");
    add_action("peer", "peer");
    add_action("peer", "lpeer");
}

int straighten(string str)
{
    if (TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (str == "cross") {
        if (found) {
            notify_fail("The cross does not need to be straightened!\n");
            return 0;
        }
        write("%^BOLD%^You reach over and straighten out the cross.\n\n");
        say("" + TP->query_cap_name() + " reaches over and straightens" +
            " out the cross.\n");
        write("There is a clicking sound and the stone floor below the" +
              " cross disappears into the wall to reveal a narrow stair case" +
              " leading down.\n");
        say("There is a clicking sound and the stone floor below the" +
            " cross disappears into the wall to reveal a narrow stair case" +
            " leading down.\n");
        add_exit("/d/antioch/cguilds/cleric/cleric1", "down");
        add_item("cross", "There is an antique cross on the southern" +
                 " wall that is perfectly aligned.");
//                set_pre_exit_functions(({"down"}),({"GoThroughDoor"}));
        found = 1;
        return 1;
    }else {
        notify_fail("What is it you want to straighten?\n");
        return 0;
    }
}

int GoThroughDoor()
{
    if (avatarp(TP) || wizardp(TP)) {
        return 1;
    }
    if (!TP->is_class("cleric")) {
        write("%^BOLD%^%^CYAN%^A mystical light appears over" +
              " the stair way and prevents you from going down there.");
        return 0;
    }else {
        write("You carefully walk down the narrow stairs.");
        return 1;
    }
}

void peer(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "north" && str != "n") {
        write("You can't see down there.\n");
        return 1;
    }
}
