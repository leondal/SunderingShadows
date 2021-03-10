#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_property("light", 2);
    set_short("%^GREEN%^Path in Tharis Forest");
    set_long(query_short() + "\n" +
      "%^GREEN%^You have stumbled upon a small seldom used path into the Tharis forest. All around you you can feel the joy of life in the %^BOLD%^%^GREEN%^t%^GREEN%^r%^RESET%^%^GREEN%^ees%^BOLD%^%^GREEN%^.%^RESET%^%^GREEN%^ These trees seem to be infused with a life of their own. As a small fawn still bearing its spots looks at you, you can feel the oneness of the forest around you. You notice a %^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^une%^GREEN%^ etched into the ground at your feet."
    );
    set_items( ([
      ({"deer", "fawn"}) : "The spotted fawn looks at you with no fear, and lowers his head to continue eating the plants on the forest floor.",
      "rune" : "The rune on the ground, etched there for all eternity, bears the symbol of the Rangers of this realm.  Just below it you can barely make out some writing.",
      "trees" : "As you look at the trees, you can feel the joy of life in them.",
      ({"writings", "writing", "words", "word", "etchings"}) : "BE WARNED!  Ahead is the abode of the Rangers of this realm.  Proceed further, and you will meet your fate!",
    ]) );
    set_exits( ([
      "south" : "/d/tharis/road/eroad11",
      "north" : "/d/shadow/room/city/cguild/ranger/rooms/path2",
    ]) );
    set_smell("default", "You can smell the forest deeply all around you.");
    set_listen("default", "The sounds you heard before are the sounds of the forest speaking among itself.");
}
