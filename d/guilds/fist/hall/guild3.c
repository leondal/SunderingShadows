#include <std.h>
inherit ROOM;

void create() {
   object ob;

   ::create();
   set_short("The Inner Sanctum of the %^RED%^Iron Fist.");
   set_long(
@FIST
%^MAGENTA%^This was formerly the Inner Sanctum of the %^RED%^Iron Fist%^MAGENTA%^.
Here members came from all across the realms to rest, and renew 
their ties to each other. The wood paneled walls are covered with 
objects that members have brought back from every corner of the world.
There are many comfortable chairs, all worn from continual use. A huge 
fireplace is filled with ashes, no longer warming the room. 
FIST
   );
   set_light(2);
   set_property("indoors",1);
   set_items(([
      "fireplace":"The fireplace is huge, so big you could stand inside.",
      "chairs":"The chairs range from harsh wooden items, to leather covered easy chairs.",
      "walls":"The walls are covered with exotic items ranging from a Drow longbow, to the head of a Thri-Kreen."
   ]));
   set_exits(([
      "west":"/d/guilds/fist/hall/guild2"
   ]));
   set_smell("default","The aroma of whiskey and the soft smell of fine tobacco blend with the dust in the air.");
   set_listen("default","You can almost hear the tinkling of glasses and soft conversation that once filled the room.");
   ob= new(BBOARD);
   ob->set_name("board");
   ob->set_id(({"board","guild board"}));
   ob->set_board_id("fistguild");
   ob->set_max_posts(0);
   ob->set_location("/d/guilds/fist/hall/main.c");
   ob->set_short("Iron Fist guild board");
   ob->set_long("%^RED%^The Iron Fist%^MAGENTA%^ guild board, for Fist members to brag and leave messages for each other");
}

