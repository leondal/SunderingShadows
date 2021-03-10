#include <std.h>
#include "../valley.h"
inherit ROOM;

int BERRIES;

void create()
{
   ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
   set_property("light",3);
   set_short("A wild garden");
   set_long(
   "%^GREEN%^You have come across a section of the wild garden that is near the edge"+
   " of the %^BOLD%^%^BLUE%^lake%^RESET%^%^GREEN%^ and the ground is a bit "+
   "%^ORANGE%^sandier%^GREEN%^ here. There is a %^BOLD%^%^WHITE%^stone%^RESET%^%^GREEN%^"+
   " bench in the center with %^BOLD%^%^MAGENTA%^flowers%^RESET%^%^GREEN%^ growing "+
   "around it. %^MAGENTA%^Moss phlox%^GREEN%^ covers"+
   " the ground around the bench. You notice %^YELLOW%^sundrops%^RESET%^%^GREEN%^ along the edge of"+
   " the path as well as clumps of %^CYAN%^mountain mint%^RESET%^%^GREEN%^. Thickly covering the"+
   " rest of the area is a spread of %^BOLD%^%^MAGENTA%^rose mallow%^RESET%^%^GREEN%^. On the west near the"+
   " sandier ground are several bushes of wild %^BOLD%^%^RED%^strawberries%^RESET%^%^GREEN%^. A small dirt"+
   " path stretches to the east and south into more of this wondrous garden.\n"
   );
   set_smell("default","The faint scent of wild strawberries tantalizes your nose.");
   set_listen("default","The rush of a waterfall can barely be heard.");
   set_items(([
   ({"bench","stone bench"}) : "%^BOLD%^There is a well worn stone bench off to"+
   " one side of the garden. One could sit and relax here while listening"+
   " to the waterfall crashing in the distance and the waves lapping at"+
   " the shore not far away. It is a very pleasant spot.",
   ({"strawberries","wild strawberries"}) : "%^BOLD%^%^RED%^The wild"+
   " strawberries appear to like the sandier soil. There are several small"+
   " bushes of them on the west side, usually with juicy berries just"+
   " waiting to be picked.%^RESET%^",
   ({"moss phlox","phlox","moss"}) : "%^MAGENTA%^The moss phlox"+
   " lies low to the ground, and you can't really see much more than an"+
   " abundant amount of the pretty purple-pink blossoms. The flowers have"+
   " five heart-shaped petals and are flat faced, every now and then you"+
   " can see some wiry %^GREEN%^green stems%^MAGENTA%^ sticking up through"+
   " the flowers.%^RESET%^",
   ({"mallow","rose mallow"}) : "The rose mallow covers a wide area of"+
   " land at the edges of the garden. It has %^GREEN%^dark green%^RESET%^"+
   " leaves with %^BOLD%^%^MAGENTA%^pink flowers%^RESET%^ that are lighter"+
   " on the backs of the petals than the front. They have five petals that"+
   " all curve together to form a circle. The flowers tend not to last very"+
   " long but they bloom frequently.",
   "sundrops" : "%^YELLOW%^The sundrops have a bright yellow bloom with"+
   " several yellow stamen in the center, one of which is lighter and"+
   " reaches higher than the rest in a star pattern. The plant has %^RESET%^%^GREEN%^dark"+
   " green leaves%^YELLOW%^ and it stays fairly low to the ground.%^RESET%^",
   ({"mint","mountain mint"}) : "%^CYAN%^The mountain mint has numerous"+
   " long, thin, dark green leaves. The flowers sprout from a thick stalk"+
   " that rises just above the rest of the plant and has a cluster of"+
   " %^BOLD%^%^WHITE%^small white blossoms%^RESET%^%^CYAN%^ that are"+
   " speckled with %^MAGENTA%^purple%^CYAN%^.%^RESET%^",
   ]));
   set_exits(([
   "east" : ROOMS+"v61",
   "west" : ROOMS+"shore14",
   "northwest" : ROOMS+"shore15",
   "north" : ROOMS+"rb1",
   "south" : ROOMS+"v57",
   ]));
   BERRIES = 0;
}

void init()
{
   ::init();
   add_action("pick","pick");
}

void pick(string str)
{
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(str != "strawberries" && str != "berries") {
      return notify_fail("You can pick berries here.");
   }
   if(BERRIES > 6) {
      tell_object(TP,"It looks like all the ripe strawberries have been"+
      " picked already, you'll have to get some another time.");
      return 1;
   }
   tell_object(TP,"%^RED%^You pick a handful of ripe strawberries.");
   tell_room(ETP,"%^RED%^"+TPQCN+" picks a handful of ripe strawberries.",TP);
   new(OBJ+"strawberries")->move(TP);
   BERRIES += 1;
   return 1;
}
