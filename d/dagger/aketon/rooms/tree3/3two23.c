#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A Serene Shrine");
   set_long("%^GREEN%^A Serene Shrine%^RESET%^\n"+
   "While still encompassed and protected within the rich, dark brown"+
   " branches and natural colors of the trees foliage, this simple but"+
   " inviting room opens up to the South and East giving a clear view of"+
   " the surrounding lands. Perhaps most importantly, the room allows a"+
   " clear view of the %^BOLD%^%^MAGENTA%^dawning sun%^RESET%^ each"+
   " morning. Despite the fact it is open on two sides, even during the"+
   " coldest days and darkest nights the room is warm and well lit, as"+
   " though a magical force provided by Lathander himself were at work."+
   " There is a simple %^BOLD%^%^MAGENTA%^rose quartz altar%^RESET%^ in"+
   " the center of the room, small but completely inviting, at which one"+
   " can kneel and pray or make an offering to the Morninglord. On the"+
   " North wall, are the words Lathander charges his followers with,"+
   " carved into a beautiful %^BOLD%^alabaster quartz plaque%^RESET%^.");
   set_smell("default","You are calmed by the rich splendor of forest smells.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_exits( (["northwest":RPATH3+"3two19"]) );
}
