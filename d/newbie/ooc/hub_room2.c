#include <std.h>
#include <move.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("light",2);
        set_property("no sticks",1);
	set_property("ooc room", 1);
        set_short("%^MAGENTA%^OOC area hub to info. rooms");
        set_long(
@STYX
This room is a hub to various rooms with posters of information about how to get started and get the most from playing and roleplay (RP) in Sundering Shadows.  When you have reviewed the information and are ready to begin your adventure, %^BOLD%^<out>%^RESET%^ will take you back to the beginning of the ooc area.  You can return here anytime to look for answers to other questions you may have or refresh your memory.
STYX
        );
        set_items(([
        ]));
        set_exits(([
        "basics" : "/d/newbie/ooc/basics_room",
        "char" : "/d/newbie/ooc/char_room",
        "questions" : "/d/newbie/ooc/faq_room",
        "rules" : "/d/newbie/ooc/rules_room",
        "tutorial" : "/d/newbie/ooc/hub_room",
        "out": "/d/newbie/ooc/hub_room3",
        ]));
}
