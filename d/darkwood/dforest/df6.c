#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^A dark path.%^RESET%^\n"
"The trees seem to be getting thicker, slowly closing in around "
"you. It is getting harder for you to see your surroundings. You "
"feel as though you are being watched, but you dont see anything "
"when you look around. The path goes on the the northeast. You "
"wonder if you should go on or turn back while you can.\n"
);
    set_exits( ([
                "south" : "/d/darkwood/dforest/df5",
                "northeast" : "/d/darkwood/dforest/df7",
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"path" : "The side path looks like an adventure waiting for you."
,"dirt" : "You notice little footprints throughout the area."
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You shuffle of little feet deep behind the trees.");
}
