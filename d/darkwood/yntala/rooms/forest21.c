//forest21
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
   set_exits(([
"west":INRMS"forest22"
]));
   set_items(([
   "undergrowth":"RESET%^%^GREEN%^That's strange, there seems to be %^ORANGE%^thorns %^GREEN%^sticking out from between the leaves of the undergrowth.",
   ({"floor","forest floor"}):"%^BOLD%^%^BLACK%^Shadows dance across the forest floor, making it difficult to see much. Though for some reason, the %^RESET%^%^GREEN%^undergrowth %^BOLD%^%^BLACK%^catches your eye.%^RESET%^",
   ({"tree","trees"}):"%^RESET%^%^ORANGE%^The trees here are old and gnarled, twisted in deformed ways that give off a %^BOLD%^%^BLACK%^spooky %^RESET%^%^ORANGE%^feeling.%^RESET%^",
   ({"light","lights"}):"%^RESET%^%^BLUE%^The only %^RESET%^light %^BLUE%^that manages to make its way through the dense %^GREEN%^canopy %^BLUE%^looks more like fine %^RESET%^spiderwebs %^BLUE%^falling from the sky.",
   "fallen trees":"%^GREEN%^Many fallen trees litter the ground here, most are %^ORANGE%^rotting %^GREEN%^and covered with moss.%^RESET%^",
   "thorns":"RESET%^%^ORANGE%^The thorns look out of place.%^RESET%^",
   "thornbushes":"%^RESET%^%^ORANGE%^They are very thick, but one particular patch looks to be slightly thinner.%^RESET%^",
]));
   set_search("thorns","%^ORANGE%^You notice that there are many thornbushes planted in this part of the %^GREEN%^forest. %^ORANGE%^That seems odd...%^RESET%^");
   set_search("thornbushes","%^ORANGE%^There seems to be a path through the thornbushes, perhaps you can %^RESET%^enter %^ORANGE%^the %^RESET%^path?");
   set_search("default", "%^RESET%^%^ORANGE%^The thornbushes catch your attention.%^RESET%^");
}
void init()
{
       ::init();
       add_action("enter","enter");
}
int enter(string str){
   if(str == "path"){
       tell_object(TP,"%^BOLD%^%^BLACK%^You make your way through the thornbushes.%^RESET%^");
       tell_room(TO,""+TP->query_cap_name()+" disappears into the forest!%^RESET%^",TP);
       this_player()->move_player(INRMS+"thornroom");
   return 1;
   }
}
