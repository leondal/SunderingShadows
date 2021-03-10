#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^A small hut blocks your way.  It is small and round, yet blocks the path as the thorn bushes around it will not allow passage any other way.");
set_smell("default", "%^CYAN%^\nYou smell damp earth and heavy scented flowers");
set_listen("default", "%^BLUE%^You can hear insects and the odd scurrying small animal, and your own heavy breathing.");
set_exits( ([
  "hut" : "/d/hm_quest/rooms/quest25",
  "southeast" : "/d/hm_quest/rooms/quest23"
]) );
set_items(([
"hut" : "Perhaps you should take a closer look"
]) );
}
