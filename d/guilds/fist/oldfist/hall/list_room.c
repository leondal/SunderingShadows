#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("%^BOLD%^Listing of Members");
   set_long(
@DESC
%^BLUE%^The Members Listing of the %^RED%^Iron Fist%^RESET%^
%^BLUE%^This is the place where the members of the %^RED%^Iron Fist
%^BLUE%^kept a list of their fellow mercenaries. You can see a large
empty space on one of the walls where the list must have been.
There was a time when you could often hear the older members
starting tales with "Do you remember <name> ..." in here.
DESC
   );
   set_listen("default", "The silence is deafening.");
   set_smell("default", "You smell nothing.");
   set_exits( ([
      "southwest" : "/d/guilds/fist/hall/main.c",
   ]) );
}

