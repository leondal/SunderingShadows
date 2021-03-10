#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_short("The Treasury of the Iron Fist");
   set_long(
@FIST
%^BLUE%^This is the entrance to the guild treasury where the %^RED%^Iron Fist%^BLUE%^ members 
once kept their many piles and piles of gold. There is a chair 
behind an empty table, once covered with clutter. The size of the
storage area makes you think that the clerk who once worked here must 
have had a hard time keeping track of all the guild's money. Unfortunately,
they appear to have cleared it out pretty thoroughly.
FIST
   );
   set_light(2);
   set_property("indoors",1);
   set_exits(([
      "west":"/d/guilds/fist/hall/main"
   ]));
}

