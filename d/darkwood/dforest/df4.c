#include <std.h>
#include <dirs.h>
inherit ROOM;

    void create() {
    ::create();
   set_properties( ([ "light" : 2, "indoors" : 1 ]) );
   set_short("A road");
    set_long(
"%^BOLD%^A dark path.%^RESET%^\n"
"The path turns into a fork here. You have the strangest feeling "
"as if someone is watching you. You also notice something different "
"about the dirt here. There is also a weird metal sign nailed to "
"to one of the huge trees. As far as you can see the path narrows into "
"the darkness of the trees southwards. The path twist and turns north.\n"
);
    set_exits( ([
                "west" : "/d/darkwood/dforest/df3",
                "north" : "/d/darkwood/dforest/df5"
    ]) );
    set_items ( ([
"trees" : "The huge leafless trees tower above you. You feel small and insignificant compared to the giant trees."
,"path" : "The side path looks like an adventure waiting for you."
,"dirt" : "You notice little footprints throughout the area."
,"metal sign" : 
"This sign has seen better days.\n"+
" ________________________________________\n"+
"/                                       \ \n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"|                                       |\n"+
"\                                       /\n"+
" ----------------------------------------\n"
]) );
set_smell("default", "The air is stale and old.");
set_listen("default", "You shuffle of little feet deep behind the trees.");
}
