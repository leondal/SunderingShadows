#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^A dark path.%^RESET%^\n"
"It is too dark to see anything, but you can tell that you are "
"not alone. You can feel something breathing on your neck. You "
"shudder in fright. It may be best to kill it before it kills "
"you.\n"
);
    set_exits( ([
                "east" : "/d/darkwood/dforest/df9",
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"path" : "The side path looks like an adventure waiting for you."
,"dirt" : "You notice little footprints throughout the area."
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You shuffle of little feet deep behind the trees.");
}
