#include <std.h>
inherit ROOM;

void create()
{
     ::create();
     set_terrain(ROCKY);
     set_travel(FOOT_PATH);
     set_property("light", 0);
     set_property("outdoors", 1);
     new("/d/koenig/town/items/tapchest.c")->move(this_object());
     set_name("Behind the Tapestry");
     set_short("Behind the Tapestry");
     set_long("%^RESET%^%^BLUE%^This is not good at all! You have been pulled into the tapestry by what ever"+
              " %^RESET%^figure%^RESET%^%^BLUE%^ it was you tried to look upon, and at present you can not determine any"+
              " exits for your escape. There are %^GREEN%^bushes%^RESET%^%^BLUE%^ and %^GREEN%^trees%^RESET%^%^BLUE%^ and %^BOLD%^%^BLACK%^rocks%^RESET%^%^BLUE%^ here, but there is"+
              " no way of knowing where you are in the world. When you look up into the sky"+
              " there is nothing but %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^ there. Darkness so deep and lasting that it"+
              " reminds you of an %^BOLD%^endless%^RESET%^%^BLUE%^ and %^BOLD%^unfathomable%^RESET%^%^BLUE%^ pit. About now, however, I'd be more"+
              " concerned with the thing that pulled you in here!%^RESET%^\n");
     set_smell("default", "It smells of the mountains here.");
     set_listen("default", "There is nothing to meet your listening ears but silence.");
     set_items( ([
                      "rocks" : "Some are large, some are small, and some have large cracks.",
                      "trees" : "There are quite a few trees here but one seems to stand out...a willow tree...",
                      "bushes" : "They are green and plentiful here.",
                      "opening" : "As you look closer, the opening reminds you of a %^BOLD%^portal%^RESET%^...",
                      "willow tree" : "%^RESET%^It is very large and looks to be very old. Some of its roots come up along the grounds surface. It appears to have an %^BOLD%^opening%^RESET%^ in its center that shimmers and occassionally blazes brightly.",
                      "portal" : "There's no saying where it leads, but it cannot be any worse than being stuck here forever... Can it?"
                      ]) );
}
void init() {
     ::init();
     add_action("go_portal", "portal");
}
int go_portal(string str) {
     if(present("spectre")){
          write("%^BOLD%^%^YELLOW%^The spectre blocks your passage!");
          tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" is blocked by the spectre!",TP);
          return 1;
     }
     write("You enter the portal and are blinded by its light briefly.");
     write("When you can see again you find yourself some place else.");
     say(TPQCN+" disappears!");
     TP->move_player("/d/koenig/road/room1.c");
     return 1;
}
void reset()
{
     ::reset();
     if(!present("spectre"))new("/d/koenig/town/mon/spectre.c")->move(this_object());
}
