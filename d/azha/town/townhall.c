// Azha Town Hall
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

// object ob;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(1);  
	set_short("Azha Town Hall");
  set_long(
@AZHA
%^BOLD%^Azha Town Hall%^RESET%^
	You are inside the Town Hall of Azha.  The officials appointed to
adminster the town keep their offices here.  This is also where you 
can get permits for various sorts of things most importantly, a permit
to carry a weapon.  If you can find the town clerk, he'd be happy to 
issue one, for a price.
AZHA
    );
	set_exits(([
	"east" : "/d/azha/town/east1"  
  ] ));     
	set_smell("default","The smell of old books and parchment fills the air.");
	set_items(([
		"boxes" : "These boxes probably hold receipts and other such useless things.\n",
		"ledgers" : "These boxes probably record transactions with Customs.\n",
	] ));
/* cleaning up boards, Azha doesn't really need two of the same one *Styx* 10/5/02
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "azha board" }) );
    ob->set_board_id("tsarazhabord");
    ob->set_max_posts(20);
    ob->set_location("/d/azha/town/townhall");
    ob->set("short", "Azha Area Board");
    ob->set("long", "Announcements from the Provincial"
        "Government are posted here.\n");
*/
}
