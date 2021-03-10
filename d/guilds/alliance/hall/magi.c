// /d/guilds/alliance/magi.c

#include <std.h>

inherit ROOM;

void create(){
   object ob;
   
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no teleport",1);
   set_indoors(1);
   set_light(2);
   set_short("The castle Magi room");
   set_long(
@DESC
%^MAGENTA%^The castle Magi room%^RESET%^
This room looks like nothing you have ever seen before.
It is the place where all the castle magi come to study 
their spells. The walls have many different %^BLUE%^c%^RED%^o%^BOLD%^l%^YELLOW%^o%^GREEN%^r%^MAGENTA%^s%^RESET%^. On the 
floor there is %^GREEN%^grass%^RESET%^ growing and the air is filled with 
%^YELLOW%^butterflies%^RESET%^ that seem to be coming from nowhere. In the 
middle of the room you see an old table filled with scrolls, 
paper and ink. Beside the table you see a large pot and in 
it some strange mixture is boiling. At the north wall you 
notice a shelf filled with many different %^ORANGE%^herbs%^RESET%^ and components, 
and on the wall beside the shelf you see a %^MAGENTA%^painting%^RESET%^ of the 
once well-respected castle mage and you wonder who he might be.
DESC
   );
     set_listen("default","You hear birds singing and water boiling.");
   set_smell("default","You smell grass and herbs.");
   set_exits(([
      "east":"/d/guilds/alliance/hall/dungeon.c",
   ]));
   set_items(([
      "painting":"This is the painting of the once well-known and respected castle mage called Xodor. He provides the Alliance with magical firepower and other tools, but he is mostly known for his messed up testing of new spells that often cause a disaster. This man looks really confused, you notice his bright %^BOLD%^%^BLUE%^blue%^RESET%^ hand that was the result of previous spell testings that went wrong.",
    "pot":"There is a boiling pot on the fire, but one has been moved aside, a conical-shaped sparkling mixture of granite and diamond rock, with dragon scales decorating the outside of it.  This strange construct is perfectly formed, and has a single %^BOLD%^pearl%^RESET%^ at the very top.",
   ]));
}
