#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_room_type("bank");
    set_properties( ([
      "light" : 2,
      "indoors" : 1,
    ]) );
    set_short("Tonovi treasury");
    set_long(
      "This sparse room is where the money of the city of Tonovi is kept.  The treasury handles all income for the city itself, freeing the bank to work with the private accounts.  The great vault of the treasury holds the wealth from the great slave trade that keeps the city so well funded."
    );
    set_listen("default" , "You can hear the coins against each other as someone counts a recent deposit.");

    set_items( ([
      "money" : "You've never seen this much money before!",
      "vault" : "The great vault is sealed tight.  There's no way you're going to get in there.",
    ]) );

    set_exits( ([
      "west" : RPATH "street9",
    ]) );
}
