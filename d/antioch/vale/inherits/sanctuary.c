//adjusted so players can fill their waterskins here ~Circe~ 7/22/19
#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_property("no teleport",1);
   set_travel(FOOT_PATH);
   set_terrain(MEADOWLANDS);
   set_short("%^BOLD%^A peaceful sanctuary%^RESET%^");
   set_long(
   "%^GREEN%^Druidic Sanctuary%^RESET%^\n"+
   "%^GREEN%^This is a quiet and %^CYAN%^peaceful%^GREEN%^ sanctuary cut off from the"+
   " outside world by a tall wall of %^BOLD%^brambles%^RESET%^%^GREEN%^.  Along the wall,"+
   " fresh vines of %^MAGENTA%^berries%^GREEN%^ thrive in the serenity "+
   "of this sanctuary. In the center is a"+
   " %^BOLD%^%^CYAN%^tranquil pool%^RESET%^%^GREEN%^ that reflects the world around"+
   " it. There is a %^BOLD%^%^WHITE%^stone%^RESET%^%^GREEN%^ bridge in the center that crosses the pool."+
   " The druids come here to pray and build up their power. Wounded"+
   " animals may also come here to be tended, and the area is a complete"+
   " sanctuary with no fighting allowed, even the animals heed this rule.\n"
   );
   set("night long",
   "%^GREEN%^Druidic Sanctuary%^RESET%^\n"+
   "%^BOLD%^%^BLUE%^The sanctuary is quiet and there is a sense of %^RESET%^%^CYAN%^peace%^BOLD%^%^BLUE%^"+
   " that surrounds"+
   " this area. The wall of %^GREEN%^brambles%^BLUE%^ protects it from the outside world,"+
   " allowing this to be a place of communion for the druids. Along the wall, fresh vines"+
   " of %^MAGENTA%^berries%^BLUE%^ thrive.  Wild"+
   " animals may also come here to be tended, and while they remaind"+
   " here there is never any fighting. A %^CYAN%^pool%^BLUE%^ in the"+
   " center reflects the %^WHITE%^moonlight%^BLUE%^, shining a bright %^WHITE%^silver%^BLUE%^ and almost"+
   " resembling a %^WHITE%^moonstone%^BLUE%^. There is a bridge that crosses over the"+
   " center of the pool, and a small path surrounds the edges.\n"
   );
   set_smell("default","The air is fresh and clear.");
   set_listen("default","Everything is peacefully quiet here.");
   set_items(([
   "path" : "%^ORANGE%^There is a small dirt path that winds around the edges"+
   " of the pool.",
   "bridge" : "%^BOLD%^There is a stone bridge that crosses directly over the"+
   " center of the pool. It is arched in the center and has railings"+
   " on either side with stones that have been carved with the shapes"+
   " of wild animals and plants.",
   "berries" : "%^MAGENTA%^Fresh berries grow among the brambles.  "+
   "Everything from blackberries to strawberries can be found.  "+
   "One could %^BOLD%^gather%^RESET%^%^MAGENTA%^ the sweet berries.",
   ({"wall","wall of brambles"}) : "%^GREEN%^The wall of brambles"+
   " circles the sanctuary, protecting it from the outside world.%^RESET%^",
   "pool" : "%^BOLD%^%^CYAN%^The pool in the center is oval shaped and"+
   " completely calm. It reflects the bridge and the sky above and"+
   " instills in you a sense of peace.  The water looks so inviting, as"+
   " if you might be able to %^BLUE%^drink%^CYAN%^ from it.",
   ]));
   set_property("fill waterskin",1);
}
void init() {
    ::init();
    add_action("drink_func", "drink");
    add_action("gather_func", "gather");
}
int drink_func(string str) {
   if(!str) return 0;
   if(str != "water from pool" && str != "from pool")
      return 0;
   if(!TP->add_quenched(20))
      return notify_fail("Your stomach is sloshing already!\n");
   tell_object(TP,"%^BOLD%^%^CYAN%^You drink some of the crystal clear water from the pond
and feel refreshed and rejuvenated.");
   tell_room(TO,TPQCN+" drinks some of the crystal clear water from the
pool.",TP);
   return 1;
}
int gather_func(string str) {
   if(!str) return 0;
   if(str != "berries" && str != "berry")
      return 0;
   tell_object(TP,"%^MAGENTA%^You gather a handful of berries from the vines.");
   tell_room(TO,TPQCN+" carefully gathers a handful of berries from the vines.",TP);
       switch(random(10)){
          case 0: new("/d/guilds/kindred/obj/berries.c")->move(TO);
          break;
          case 1: new("/d/antioch/valley/obj/strawberries.c")->move(TO);
          break;
          case 2: new("/d/darkwood/yntala/obj/wildberries.c")->move(TO);
          break;
          default: new("/d/shadow/room/meadows/obj/berries.c")->move(TO);
          break;
        }
   return 1;
}

void reset()
{
   ::reset();
   if(query_night()) {
      add_item("pool","%^BOLD%^The pool shines like a milky white"+
      " moonstone in the center of the sanctuary, oval shaped and"+
      " depthless it seems serene. Just looking at it causes a sense"+
      " of utter peace to wash over you.%^RESET%^");
   }
}
