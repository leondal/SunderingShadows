
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("on a bridge over the reflection pool.");
    set_long("
    This small bridge connects the main platform to the south wall fortress.  You begin to have second thoughts about going there, as the archers in the fortress that left you alone until now may decide to attack.
    The bridge itself is stunningly constructed of walnut and marble.
    The sunlight pouring through the numerious crystal and glass structures creates brilliant patterns over everything!
");
      set_listen("default","You can hear the howl of several large creatures echoing through the immense chamber.");

    set_exits( ([
    "south" : "/d/attaya/base/lookout2",
    "staircase" : "/d/attaya/base/base47",
        ]) );
    set_items(([
    "ceiling" : "It is just a faint grey shadow far, far away.",
    "platforms" : "The crystal platfroms hang in mid air all over the room.  Some are close to others, some are distant.",
     "water" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
     "walls" : "The walls are made from thousands of glass panels held together by posts of worked steel and bronze.",
      "pool" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
      "bridge" : "The bridge is lavishly carved with marble and black walnut.  It is high above the reflection pool.",
    ]));
}

