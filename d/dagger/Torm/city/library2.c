#include <std.h>
inherit VAULT;

void create()
{
   ::create();
   set_short("Gwenhwyfar's Office");
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("light",3);
   set_property("indoors",1);
   set_long(
   "Smaller and lighter this office houses additional book cases filled with"+
   " volumes of half-elven lore. In the center sits a large rosewood desk and"+
   " upon it sits a small guilded picture frame, and a crystal ink pot with"+
   " plumed quill.  A well cushioned chair sits across from the desk for a"+
   " guest to sit in. On the wall behind the desk hangs a picture.");
   set_smell("default","A slight scent of roses mingles with the parchment.");
   set_listen("default","This is a quiet room, ideal for reading.");
   set_items(([
   "desk" : "This desk is made of fine rosewood and has delicate carvings"+
   " around the outer edges.  There are several drawers with crystal handles."+
   " You notice the desk is neat and tidy.",
   "chair" : "This high backed chair is well cushioned with rosewood arms."+
   " The fabric is a soft looking rose colored velvet, which matches the color"+
   " of the carpet.",
   "floor" : "%^BOLD%^%^RED%^The floor is covered with a large circular rose"+
   " colored carpet patterned with %^WHITE%^white flowers%^RED%^.%^RESET%^",
   "picture" : "This is a portrait of an adorable chubby little toddler"+
   " dressed in a %^BOLD%^%^BLUE%^blue jumper%^RESET%^.  He has a thatch of"+
   " %^BOLD%^%^BLACK%^raven black hair%^RESET%^, bright"+
   " %^BOLD%^silver eyes%^RESET%^, coppery skin and a dimple in his chin.",
   ]));
   set_exits(([
   "out" : "/d/dagger/Torm/city/library1",
   ]));
}
