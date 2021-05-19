
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("on a bridge over the reflection pool.");
    set_long("
    You are at the center span of the bridge now.  The world around you seems unusually serene up here over the reflection pool.  A large brass bench sits upon a small raised area near the railing where you can sit and think.  The waters below are completely clear and are magnificent as the surface reflects the scene above you.
    Not far to the south is the guarded entrance to the south wall fortress.
");
      set_listen("default","It is very tranquil here...  for now..");

    set_exits( ([
    "south" : "/d/attaya/base/lookout3",
    "north" : "/d/attaya/base/lookout1",
        ]) );
    set_items(([
    "ceiling" : "It is just a faint grey shadow far, far away.",
    "platforms" : "The crystal platfroms hang in mid air all over the room.  Some are close to others, some are distant.",
     "water" : "The crystal clear waters of the reflection pool reflect everything above you like a mirror.  If you tune your eyes just right, however, you can see a maze beneath their surface!",
      "pool" : "The crystal clear waters of the reflection pool reflect everything above you like a mirror.  If you tune your eyes just right, however, you can see a maze beneath their surface!",
      "enterance" : "It is heavily guarded.",
     "walls" : "The walls are made from thousands of glass panels held together by posts of worked steel and bronze.",
      "pool" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
      "bridge" : "The bridge is lavishly carved with marble and black walnut.  It is high above the reflection pool.",
    ]));
}

