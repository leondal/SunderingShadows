#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_short("The Great Hall of the Iron Fist");
   set_long(
@FIST
%^BLUE%^This was once the Great Hall of the %^RED%^Iron Fist%^BLUE%^.
Here its members once gathered to revel and share stories of their 
adventures. There is a massive oaken table running the length of the 
hall, lined with hulking great chairs. The ceiling is shrouded in 
shadow, and you can see places on the wall where torches were once hung.
All is covered with dust, with only the footprints on the floor as 
indications that others have been here.
FIST
   );
   set_light(2);
   set_property("indoors",1);
   set_exits(([
              "north" : "/d/guilds/fist/hall/guildheal",
              "out": "/d/guilds/fist/hall/guild1",
//             "east":"/d/guilds/fist/hall/main"
   ]));
   set_smell("default","You catch a faint scent of stale wine underlying the dank smell of aged stone.");
   set_listen("default","You hear the scurrying of tiny feet and nothing more.");
}
