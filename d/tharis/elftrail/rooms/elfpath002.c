#include <std.h>
#include "../defs.h"
inherit ROOM;

int nuts;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(HEAVY_FOREST);
        set_travel(GAME_TRACK);
        set_name("Along the trail");
        set_short("%^RESET%^%^ORANGE%^Along the trail");
        set_long("%^GREEN%^Barely noticeable as it winds through the trees, this is more of a footpath then a trail. Amongst the conifers grows "
"the occasional %^ORANGE%^nut%^GREEN%^ tree.");
        set_smell("default","%^RESET%^%^ORANGE%^The earthy scents of nature surround you.");
        set_listen("default","%^RESET%^%^ORANGE%^There is the occasional rustle or chirp of wildlife.");
        set_items(([
           ({"nut","nuts","trees"}) : "A variety of nut bearing trees grow here, their fallen fruit simple to gather.",
        ]));
        set_exits(([
           "southwest" : ROOMS"elfpath001",
           "north" : ROOMS"elfpath003",
        ]));
}

void init() {
   ::init();
   add_action("find_fun","gather");
}

int find_fun(string str) {
   object ob;
   if(str == "nuts") {
     if(nuts == 1) {
       notify_fail("The best of them have already been gathered.\n");
       return 0;
     }
     tell_object(TP,"You pause for a moment, gathering fallen nuts.");
     tell_room(ETP,""+TPQCN+" pauses for a moment, gathering fallen nuts.",TP);
     ob = new(OBJ"nuts");
     ob->move(TO);
     nuts = 1;
     return 1;
   }
   return 0;
}