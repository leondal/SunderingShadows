//updated by Circe 1/9/05 with new description by Lusell
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Tonovi Hotel");
    set_short("Tonovi Hotel");
/*
    set_long(
      "This is the foyer of the grand hotel of Tonovi.  From the giant chandelier hanging from the 20 foot high ceiling to the elegant carpet covering the floor, this hotel has an aura of opulence.  In such a small and new city, you wonder where the money to build and maintain such a high class establishment comes from.  There is a grand staircase leading to the second floor, and a door leading into the dining room in the back of the hotel."
    );
*/
    set_long("%^BOLD%^%^WHITE%^You are standing in the foyer of the "+
       "%^RESET%^%^MAGENTA%^Hotel Grande %^BOLD%^%^WHITE%^of %^BLACK%^"+
       "Tonovi%^WHITE%^.  From the 20 foot high %^YELLOW%^chandelier "+
       "%^WHITE%^to the elegant %^MAGENTA%^carpet %^WHITE%^covering "+
       "the floor, this hotel has an aura of opulence.  In such a small "+
       "city, you wonder where the money to build and maintain such a "+
       "high class establishment comes from.  There is a grand staircase "+
       "coiling along the western wall until it reaches out of sight "+
       "on the second floor, and an intricately carved wooden archway "+
       "in the southern end of the room leads to a dimly lit hallway "+
       "with doors off either side and a smoke filled room at the end.  "+
       "Sharply dressed men in suede %^RESET%^%^ORANGE%^suits %^BOLD%^"+
       "%^WHITE%^bustle about tending to the needs of patrons and "+
       "visitors entering.%^RESET%^\n");
    set_smell("default", "You can smell the perfumes used to keep "+
       "the stench of the city out of the hotel.");
    set_listen("default", "You can hear beautiful, exotic music "+
       "coming from the dining room.");
    set_items( ([
	"chandelier" : "The giant crystal chandelier hangs from the ceiling, giving off a glow keeping the whole foyer bright.",
	"carpet" : "The carpet covering the floor looks ancient, and very expensive.",
	"staircase" : "This giant staircase leads up to the second floor, where the rooms are.",
      ]) );

    set_exits( ([
	"northeast" : RPATH "street5",
	"south" : RPATH "hotel2",
	"up" : RPATH "hotel3"
      ]) );
}
