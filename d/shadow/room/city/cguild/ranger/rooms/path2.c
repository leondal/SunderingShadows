// protection for guild halls removed per T  *Styx*  10/28/02

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_property("light", 2);
    set_short("%^GREEN%^Path through Tharis forest");
    set_long(query_short() + "\n" +
      "%^RESET%^%^GREEN%^You are on a well-hidden path in Tharis forest.  All around you you can feel the life and beauty in the trees. As you look around, you catch glimpses of movement in the corners of your eyes. Surrounded by %^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^,%^GREEN%^ small %^GREEN%^pa%^BOLD%^%^GREEN%^t%^GREEN%^h%^RESET%^%^GREEN%^ leads to the south. You sense %^GREEN%^mov%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ment%^GREEN%^ in the forest."
    );
    set_items( ([
     "trees" : "As you focus on a tree, nothing happens, but you are sure you can see the movement of others in the corner of your eye.",
      "path" : "The path continues towards a great tree to the northwest",
      "movement" : "Did you see that?  No?  Damn, I thought I just saw that tree move.",
    ]) );
    set_exits( ([
      "south" : "/d/shadow/room/city/cguild/ranger/rooms/path1",
      "northwest" : "/d/shadow/room/city/cguild/ranger/rooms/path3",
    ]) );
    set_smell("default", "You can smell the forest all around you.");
    set_listen("default", "What you thought was the wind through the trees sounds more like voices in the trees.");
//    set_pre_exit_functions( ({"northwest"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
    if(!TP->is_class("ranger") && !wizardp(TP)){
      tell_object(TP, "You are not allowed past this point.");
      return 0;
    } else {
      return 1;
    }
}
