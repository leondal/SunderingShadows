#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^A dark path.%^RESET%^\n"
"The trees are so thick, they are blocking most of the sunlight, "
"making it almost impossible to see anything beyond a few feet "
"away. The path leads on to the west.\n"
);
    set_exits( ([
                "north" : "/d/darkwood/dforest/df8",
                "west" : "/d/darkwood/dforest/df10",
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"path" : "The side path looks like an adventure waiting for you."
,"dirt" : "You notice little footprints throughout the area."
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You shuffle of little feet deep behind the trees.");
}
