#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_name("Healing room of the %^RED%^Iron Fist.%^RESET%^");
   set_short("Arena Entrance");
   set_long(
@GUILD
This was the entrance to the great Arena of the Iron Fist.
The spirits of brave warriors of the guild are said to haunt
these walls.
GUILD
   );
   set_property("indoors",1);
   set_light(2);
   set_listen("default","You hear the ghostly whispering of long dead warriors of the %^RED%^Iron Fist.");
   set_smell("default","You smell the odor of the old blood that has long since dried into the fine brown patina on the floor.");
   set_exits( ([
      "south" : "/d/guilds/fist/hall/guild2",
      "north" : "/d/guilds/fist/hall/guild4",
   ]) );
}
