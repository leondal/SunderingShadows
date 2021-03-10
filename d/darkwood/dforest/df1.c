#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^Walking along a forest road.%^RESET%^\n"
"As you walk down the path you notice the trees start blocking all "
"light in the area. There is a side path to the east, and a cold chill "
"causes you to shiver uncontrollably. There are shady looking characters "
"lurking about the entrance to the path. Perhaps your curiosity gets "
"the best of you, but you wonder what's down the erie path."
);
    set_exits( ([
                "east" : "/d/darkwood/dforest/df2"
    ]) );
    set_items ( ([
"trees" : "The branches of the trees are leafless, and look as if they are grabbing for you."
,"characters" : "You see short shadows behind the trees."
,"path" : "The side path looks like an adventure waiting for you."
]) );
}
