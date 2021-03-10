#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^Entrance to side path.%^RESET%^\n"
"The air flowing the path is ice cold. Small noise can be heard in the "
"distance. Though you don't actually see anything you are fearful for "
"what the noises might be. You still can't make out what the shady looking "
"characters since they are behind the trees. The path continues eastwards. "
"To the west you see a road.\n"
);
    set_exits( ([
                "east" : "/d/darkwood/dforest/df4",
                "west" : "/d/darkwood/dforest/df2"
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"characters" : "You still can see them fully, but you notice they are short in height."
,"path" : "The side path looks like an adventure waiting for you."
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You hear the shuffle of little feet deep behind the trees.");
}
