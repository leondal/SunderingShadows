#include <std.h>
#include "../valley.h"
inherit ROOM;

int RED, WHITE;

void create()
{
   ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
   set_property("light",3);
   set_short("A wild garden");
   set_long(
   "%^GREEN%^This is a beautiful garden that is growing almost completely wild."+
   " There is a large arch of %^RED%^roses%^GREEN%^ here that is quite beautiful, but"+
   " the roses are also growing where ever they want and are obviously"+
   " not kept trimmed. %^BOLD%^%^MAGENTA%^Begonias%^RESET%^%^GREEN%^ and"+
   " %^BOLD%^%^WHITE%^petunias%^RESET%^%^GREEN%^ intermix with the roses."+
   "  There is a small but worn foot path that leads"+
   " into more of the garden to the north or west and has pretty"+
   " begonias and petunias growing around the edges.\n"
   );
   set_smell("default","The scent of the roses is wonderful.");
   set_listen("default","The rush of a waterfall can barely be heard.");
   set_items(([
   ({"arch","roses"}) : "The roses are beautiful and are growing freely"+
   " over the arch, with many smaller vines reaching out to people as"+
   " they pass by. There are large %^BOLD%^%^RED%^red roses%^RESET%^ whose"+
   " scent is wonderful and fills the air, as well as some smaller"+
   " %^BOLD%^white tea roses%^RESET%^ that have mixed themselves in with"+
   " the red.",
   "path" : "%^ORANGE%^There is a small worn dirt path that leads to the west and"+
   " north into more of this wild garden.",
   "begonias" : "%^BOLD%^%^MAGENTA%^The begonias are full and lovely, they are seen in red,"+
   " white, pink, and a few are a pretty shade of coral. They grow wild"+
   " along the edges of the path.",
   "petunias" : "%^BOLD%^The petunias are a pretty flower with lighter green leaves"+
   " and the blossoms are shaped like trumpets almost, but they are"+
   " striped. The main color is white but you see alternating stripes of"+
   " various colors on the different plants, such as red, pink, and purple.",
   ]));
   set_exits(([
   "west" : ROOMS+"v57",
   "east" : ROOMS+"v59",
   "north" : ROOMS+"v61",
   "south" : ROOMS+"g65",
   "northeast" : ROOMS+"rb4",
   ]));
   RED = 0;
   WHITE = 0;
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
   if(str == "red rose") {
      if(RED > 5) {
         tell_object(TP,"You wouldn't really feel right picking any more"+
         " red roses, someone has picked several already and you wouldn't"+
         " want to ruin the pretty arch.");
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^RED%^You reach out and pick a lovely"+
      " red rose from the arch.");
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" pickes a red rose from the"+
      " arch.",TP);
      new(OBJ+"red_rose")->move(TP);
      RED += 1;
      return 1;
   }
   if(str == "white rose") {
      if(WHITE > 5) {
         tell_object(TP,"You wouldn't really feel right picking any more"+
         " white roses, someone has picked several already and you wouldn't"+
         " want to ruin the pretty arch.");
         return 1;
      }
      tell_object(TP,"%^BOLD%^You reach out and pick a pretty"+
      " white tea rose from the arch.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" pickes a white rose from the"+
      " arch.",TP);
      new(OBJ+"white_rose")->move(TP);
      WHITE += 1;
      return 1;
   }
   else if(str == "rose") {
      tell_object(TP,"There are both red roses and white roses, you need"+
      " to specify which one you'd like to pick.");
      return 1;
   }
   if(str != "rose") {
      return notify_fail("You can pick roses here.");
   }

}
