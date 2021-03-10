#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no teleport",1);
   set_property("light",3);
   set_short("%^BOLD%^Entrance of the Paladin's Hall%^RESET%^");
   set_long(
   "You are standing in front of the entrance of Antioch's grand paladin"+
   " hall. A %^BOLD%^%^BLUE%^royal blue%^RESET%^ rug stretches down the"+
   " hallway. On the walls hang tapestries of legendary paladins. Oil lamps"+
   " gilded with %^BOLD%^white gold%^RESET%^ line the walls, shedding"+
   " light on the area."
   );
   set_smell("default","The faint scent of vanilla is in the air.");
   set_listen("default","A respectful silence cloaks the room.");
   set_items(([
   "floor" : "The floor is covered in a fine rug that is %^BOLD%^%^BLUE%^"+
   " royal blue%^RESET%^ trimmed with %^BOLD%^white%^RESET%^.",
   ({"rug","blue rug","royal blue rug"}) : "%^BOLD%^%^BLUE%^The rug is a"+
   " rich royal blue with %^WHITE%^white%^BLUE%^ edges, it stretches down"+
   " the entire hallway.%^RESET%^",
   ({"wall","walls"}) : "Oil lamps and tapestries line the walls here.",
   ({"oil lamps","lamps"}) : "%^BOLD%^%^WHITE%^The oil lamps are gilded"+
   " in white gold, they give off a steady light and a faint scent of vanilla.%^RESET%^",
   "tapestries" : "Four tapestries decorate the hallways here of the"+
   " legendary paladins of the realm.",
   ({"tapestry","tapestry 1","mordred"}) : "The first tapestry is one of the"+
   " strong and proud Mordred upon his rearing steed.",
   ({"tapestry 2","isaac"}) : "%^BOLD%^The second tapestry portrays the"+
   " venerable Isaac, follower of Torm, with his helmet in his hand.",
   ({"tapestry 3","tylorune"}) : "%^YELLOW%^The young paladin of Tyr, Sir"+
   " Tylorune, wearing the crest of the Metallic Dragons is shown with his"+
   " sword held up in the air as he charges his enemies.",
   ({"tapestry 4","baldwin"}) : "%^BLUE%^%^BOLD%^Sir Baldwin is shown with the symbol"+
   " of Helm around his neck, standing next to Kyra at the Antioch Gates with"+
   " the Eye of Helm watching over the city from the sky.",
//sludig of torm, kiri of torm, avalon of helm, gareth?
   ]));
   set_exits(([
   "west" : "/d/antioch/antioch2/rooms/pal6",
   "east" : "/d/antioch/cguilds/paladin/hall2",
   ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

void reset()
{
   ::reset();
   if(!present("vigilant paladin")) {
      new("/d/antioch/antioch2/mons/paladin")->move(TO);
      new("/d/antioch/antioch2/mons/paladin")->move(TO);
   }
}

int GoThroughDoor()
{
   if(present("vigilant paladin")) {
      if(TP->is_class("paladin")) {
         tell_object(TP,"The paladins nod to you as you pass.");
         return 1;
      }
      tell_object(TP,"The paladin will not let you pass.");
      return 0;
   }
   return 1;
}
