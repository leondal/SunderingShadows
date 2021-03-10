#include <std.h>
#include "../valley.h"
inherit ROOM;

int PANSY;

void create()
{
   ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
   set_property("light",3);
   set_short("A wild garden");
   set_long(
   "%^GREEN%^This is a beautiful garden that seems to be growing almost completely"+
   " wild. There is a small foot path that you are on which runs to the"+
   " north and east into more of the garden. The garden seems to be in"+
   " complete disarray, yet the mixing of the %^MAGENTA%^flowers%^GREEN%^ is breath taking."+
   " Large sprouts of %^RED%^red ironweed%^GREEN%^ stand about three feet high, adding"+
   " a splash of vibrant color. Dwarf crested %^BOLD%^%^CYAN%^irises%^RESET%^%^GREEN%^ are in full bloom"+
   " as well, but far in the back. %^CYAN%^Blue-eyed%^GREEN%^ grass and %^BLUE%^blue violets%^GREEN%^ are"+
   " sprinkled about, as well as several clumps of %^BOLD%^%^RED%^rose verbena%^RESET%^%^GREEN%^."+
   " %^YELLOW%^Yellow"+
   " lupine %^RESET%^%^GREEN%^stand straight and tall, with a few patches of "+
   "%^BOLD%^%^MAGENTA%^pink spiderworts%^RESET%^%^GREEN%^"+
   " around it. At the edges of the path are beautiful %^MAGENTA%^pansies%^GREEN%^ in"+
   " multiple hues.\n"
   );
   set_smell("default","The scent of roses drifts in from the east.");
   set_listen("default","The rush of a waterfall can barely be heard.");
   set_items(([
   "path" : "%^ORANGE%^A small but worn foot path stretches to the north and east"+
   " into more of this wild garden.",
   ({"grass","blue-eyed grass","blue eyed grass"}) : "%^CYAN%^The"+
   " blue-eyed grass is rather pretty, with stalks of %^GREEN%^dark green"+
   " leaves%^CYAN%^ sticking straight up from which the flowers sprout"+
   " from. The flowers themselves have six %^MAGENTA%^purple%^CYAN%^ petals that open up with"+
   " darker purple veins. The very center of the flower is a %^YELLOW%^bright"+
  " yellow%^RESET%^%^CYAN%^ with a stamen protruding, similar to a hibiscus.%^RESET%^",
   "lupine" : "%^BOLD%^%^GREEN%^The yellow lupine is mainly a very leafy"+
   " plant light green in color with a central stock coming up that is"+
   " covered in %^YELLOW%^tiny yellow flowers%^GREEN%^.%^RESET%^",
   "spiderwort" : "The spiderwort is a rather unusual flower and looks"+
   " like it might be related to the orchid family. Foot long leaves of"+
   " %^BOLD%^%^GREEN%^light green%^RESET%^ branch out in all directions,"+
   " giving it the impression of multiple long legs. To complete the image"+
   " the %^BOLD%^%^MAGENTA%^delicate pink flowers%^RESET%^ have three"+
   " ruffled petals with multiple %^YELLOW%^yellow stamen%^RESET%^ rising"+
   " from their centers, which is similar in pattern to some spiders.",
   ({"rose","rose verbena","verbena"}) : "%^BOLD%^%^MAGENTA%^The rose"+
   " verbena is a rather large bush with several branches that hold"+
   " clusters or large pink flowers with %^WHITE%^white centers%^MAGENTA%^."+
   " The flowers are all star shaped and they give off a light rose scent.%^RESET%^",
   "ironweed" : "%^BOLD%^%^RED%^The ironweed is just that, a weed, but"+
   " here in this garden it is as pretty and fitting as the other flowers."+
   " It stands on a large stalk of %^RESET%^%^GREEN%^dark green%^BOLD%^%^RED%^"+
   " with many slender leaves branching out from it. At the very top is"+
   " a cluster of ten flowers or more that are rather fuzzy and red in"+
   " color.%^RESET%^",
   ({"violets","blue violets"}) : "%^MAGENTA%^The violets are a rather"+
   " dainty looking flower but the wild ones are actually one of the most"+
   " durable. These are a light purple in color with darker purple-blue"+
   " veins running through them.%^RESET%^",
   ({"iris","dwarf iris","crested iris","dwarf crested iris"}) : "%^BOLD%^%^MAGENTA%^The"+
   " dwarf crested iris is named for its smaller stature, hardly reaching"+
   " two feet high. The flowers are very beautiful, though, with three"+
   " larger petals that have %^WHITE%^white rectangles%^MAGENTA%^ with"+
   " %^YELLOW%^yello stripes%^MAGENTA%^ in the center. Three purple"+
   " petals stretch out inbetween the three larger ones, with three smaller"+
   " petals protruding higher from the very center.%^RESET%^",
   "pansies" : "%^MAGENTA%^The pansies that line the path come in all sorts of colors."+
   " You notice purple, blue, white and yellow color combinations. They"+
   " are obviously growing wild but there are many of them, lining the"+
   " path for almost a foot in all directions!",
   ]));
   set_exits(([
   "west" : ROOMS+"v56",
   "east" : ROOMS+"v58",
   "north" : ROOMS+"v60",
   "south" : ROOMS+"g66",
   "northwest" : ROOMS+"shore14",
   ]));
   PANSY = 0;
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
   if(str != "pansy" && str != "pansies") {
      return notify_fail("You can pick pansies here.");
   }
   if(PANSY > 4) {
      tell_object(TP,"Picking any more pansies would ruin the look of this"+
      " pretty garden.");
      return 1;
   }
   tell_object(TP,"%^MAGENTA%^You bend down and gather a small boquet of"+
   " pansies.");
   tell_room(ETP,"%^MAGENTA%^"+TPQCN+" picks a small boquet of pansies.",TP);
   new(OBJ+"pansies")->move(TP);
   PANSY += 1;
   return 1;
}
