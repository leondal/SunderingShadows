//updated from Shadow's forge for use in Tabor.  Circe 6/2/04
#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("smithy",1); 
  set_name("Lutgehr Brothers' Forge");
  set_short("Lutgehr Brothers' Forge");
  set_long("This large stone room is dominated by the huge "+
     "pile of %^BOLD%^%^BLACK%^coals %^RED%^burning %^RESET%^"+
     "in the %^BOLD%^%^RED%^fi%^YELLOW%^r%^RED%^ep%^YELLOW%^i"+
     "%^RED%^t %^RESET%^in the southwestern corner.  There, "+
     "an encasement of sorts has been built from the stones to "+
     "contain the %^BOLD%^%^RED%^fi%^YELLOW%^r%^RED%^e %^RESET%^"+
     "used to heat the %^BOLD%^metals%^RESET%^.  There are a "+
     "few scraps here and there that you might be able to use "+
     "for repairs, but you would certainly have to provide your "+
     "own %^BOLD%^billets %^RESET%^for crafting a new item.  "+
     "A large %^BOLD%^stone table %^RESET%^is in the center of "+
     "the room, covered with hammers, gloves, aprons, and "+
     "other items necessary in the %^RED%^forge%^RESET%^.  "+
     "Several %^BOLD%^%^BLACK%^anvils %^RESET%^are about as well, "+
     "and it seems the Lutgehr brothers don't mind sharing "+
     "their %^RED%^forge%^RESET%^, so long as they aren't "+
     "using it, of course.\n"
  );
  set_smell("default", "Smoke from the fire irritates your nostrils.");
  set_listen("default", "The coals in the fire pop and crackle.");
  set_exits(([
	"north" : ROOMDIR+"armor",
      "east" : ROOMDIR+"lot-weapon"
  ]));
  set_items( ([
	({"anvil", "anvils"}): "They are large blocks of metal or stone "+
         "in various shapes to form the metal and leather over.",
	({"tools", "stones"}): "Small and large hammers, piercing tools, "+
         "vises to clamp the metal in for bending, as well as rivets "+
         "and other types of hardware.",
	"coals" : "%^BOLD%^%^RED%^It seems to be fueled from both wood "+
         "and coal, with baffles used to pump extra air in at the base "+
         "to make it even hotter when needed.",
  ]) );
}
