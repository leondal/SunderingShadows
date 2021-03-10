#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(HEAVY_FOREST);
        set_travel(GAME_TRACK);
        set_name("A bend in the trail");
        set_short("%^RESET%^%^ORANGE%^A bend in the trail");
        set_long("%^GREEN%^Circling back to the west as it meanders through the trees, the sound of running water can be heard nearby. The "
"trees are tall here, the %^BOLD%^canopy%^RESET%^%^GREEN%^ far above all but obscuring the sky.");
        set_smell("default","%^RESET%^%^ORANGE%^The earthy scents of nature surround you.");
        set_listen("default","%^RESET%^%^ORANGE%^There is the occasional rustle or chirp of wildlife.");
        set_items(([
      ({"canopy","trees"}) : "Reaching up into the sky, the foliage of the trees here grows together, the area perpetually in shadow.",
     "forest":"%^GREEN%^As thick as the forest is, it looks like there might be a way to enter it.",
        ]));
        set_exits(([
           "southwest" : ROOMS"elfpath003",
           "northwest" : ROOMS"elfpath005",
         "forest":"/d/player_houses/silesse/forest6.c",
       ]));
set_invis_exits(({"forest"}));
set_pre_exit_functions(({"forest"}),({"forestmsg"}));
set_post_exit_functions(({"forest"}),({"go_out1"}));
}

int forestmsg() {
  tell_object(TP,"%^RESET%^%^GREEN%^You disappear into the forest.\n");
  if (!TP->query_invis()) tell_room(ETP,"%^RESET%^%^GREEN%^"+TP->QCN+" disappears into the surrounding forest.\n",TP);
  return 1;
}
int go_out1(string str){
   if(avatarp(TP) || (string)TP->query_name()== "silesse" || (string)TP->query_name()== "vicdaerrysn") {
      tell_room(TP,"%^RESET%^%^CYAN%^A faint %^RESET%^gli%^BOLD%^mm%^RESET%^er %^CYAN%^in the %^BOLD%^%^WHITE%^m%^RESET%^is%^BOLD%^t %^RESET%^%^CYAN%^covered %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st floor %^CYAN%^reveals paths headed %^BOLD%^%^GREEN%^southeast, west %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^northeast %^RESET%^%^CYAN%^to you.%^RESET%^",TO);
   return 1;
   }
return 1;
}
