#include <std.h>
#include "../valley.h"
inherit ROOM;

int FREESIA;

void create()
{
   ::create();
   set_terrain(GARDEN);
   set_property("fill waterskin",1); //suitable now to cast reflection spell, per player request, 9 Dec 19, Uriel
   set_travel(FOOT_PATH);
   set_property("light",3);
   set_short("A wild garden");
   set_long(
   "%^GREEN%^You have entered a beautiful garden where all the %^MAGENTA%^flowers%^GREEN%^ are growing"+
   " wild. In the center is a small freshwater %^BOLD%^%^CYAN%^spring%^RESET%^%^GREEN%^ that bubbles up"+
   " and creates a small pool of %^BOLD%^%^BLUE%^water%^RESET%^%^GREEN%^"+
   " that is ringed with %^RESET%^stones%^GREEN%^. There"+
   " is a %^BOLD%^%^WHITE%^stone statue%^RESET%^%^GREEN%^"+
   " in the center of the pool of a blooming rose with"+
   " a tiny fairy inside that is holding a heart in her outstretched hands."+
   " There is a small path around the fountain that also runs to the west"+
   " and south into more of the garden. At the edges here grow %^MAGENTA%^%^BOLD%^"+
   "freesia%^RESET%^%^GREEN%^ and %^BOLD%^%^BLUE%^bluebells%^RESET%^%^GREEN%^.\n"
   );
   set_smell("default","The light scent of freesia clings to the breeze.");
   set_listen("default","The bubbling of the fountain is soothing.");
   set_items(([
   ({"pool","spring"}) : "%^BOLD%^%^CYAN%^A crystal clear pool bubbles"+
   " up from a fresh water spring that surfaces here. A lovely stone"+
   " statue sits in the very center of the pool.%^RESET%^",
   ({"fountain","statue","stone statue"}) : "%^BOLD%^The statue is made from"+
   " soapstone that is well worn and carved in wonderful detail. There"+
   " is a large rose in full bloom and the petals actually look delicate"+
   " and soft, you can even see the grains of pollen in the center that"+
   " a tiny fairy stands upon. The fairy has wildly flowing hair and is"+
   " wearing a crown of flowers and a simple dress that appears to be"+
   " blowing in the breeze, with her wings outstretched behind her. She"+
   " has a wistful expression on her face as she stands with arms"+
   " outstretched high with a heart in her tiny hands.",
   "freesia" : "%^BOLD%^%^WHITE%^The freesia grows along the edges of the"+
   " garden here, the blossoms are delicate and small and are a lovely"+
   " white. They give off a faint scent that some find soothing.",
   "bluebells" : "%^BOLD%^%^GREEN%^The bluebells grow on a larger"+
   " plant with leafy green leaves. A central stalk shoots up and branches"+
   " out with several smaller stalks that hang over from the weight of"+
   " the flowers that dangle from them. The flowers themselves are trumpet"+
   " shaped and hang downwards, like a bell. They are %^WHITE%^white%^GREEN%^"+
   " on the outside with a dash of %^BOLD%^%^BLUE%^blue%^GREEN%^ in the"+
   " center.%^RESET%^",
   "path" : "%^ORANGE%^There is a small path around the fountain that also leads"+
   " to the west and south into more of this wild garden.",
   ]));
   set_exits(([
   "west" : ROOMS+"v60",
   "east" : ROOMS+"rb4",
   "south" : ROOMS+"v58",
   "north" : ROOMS+"rb2",
   "northeast" : ROOMS+"rb3",
   ]));
   FREESIA = 0;
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
   if(str != "freesia") {
      return notify_fail("You can pick freesia here.");
   }
   if(FREESIA > 3) {
      tell_object(TP,"It looks like most of the freesia flowers have"+
      " already been picked.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You pick a few sprigs of freesia.");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" picks a few sprigs of freesia.",TP);
   new(OBJ+"freesia")->move(TP);
   FREESIA += 1;
   return 1;
}
