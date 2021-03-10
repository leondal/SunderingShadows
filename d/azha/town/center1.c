//updated by Circe 9/15/05 with exit for new psion comps shop
// Center Street, Azha
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
   room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);  
   set_name("Center Street, Azha");
   set_short("Center Street, Azha");
  set_long(
@AZHA
%^BOLD%^Center Street%^RESET%^
	You have found yourself at the north end of Center Street,
a short, but busy stretch of road going south from Fortress
Street to the Market Gate in the center of town.  Looking around,
you notice that the houses in this area are the finest in Azha,
probably the dwellings of the merchants who make their living 
in the walled marketplace to the south.  To the west is a 
grand building made of white marble.
	Center Street continues to the north and south.
AZHA
    );
	set_exits(([
	"south" : "/d/azha/town/center2",     
	"north" : "/d/azha/town/fort3",
      "west" : "/d/azha/town/azha_psi_comps"
  ] ));     
	set_smell("default","The smell of perfumes and spices tickles your nose delightfully.");
   set_listen("default","The dull roar of the marketplace south is muted here.");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
