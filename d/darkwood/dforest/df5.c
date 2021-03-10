#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^A dark path.%^RESET%^\n"
"You have stepped onto a winding path. As you peer ahead, it seems "
"as if the path winds on forever. An eerie feeling grips you, but "
"you see nothing that could harm you. The path goes on to the north, "
"you wonder what lies ahead.\n"
);
    set_exits( ([
                "south" : "/d/darkwood/dforest/df4",
                "north" : "/d/darkwood/dforest/df6"
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"path" : "The side path looks like an adventure waiting for you."
,"dirt" : "You notice little footprints throughout the area."
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You shuffle of little feet deep behind the trees.");
}
