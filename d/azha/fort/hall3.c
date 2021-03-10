// 2nd Floor Passageway of Azha Keep
// Thorn@ShadowGate
// 12/18/95
// Azha Fort

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
	set_light(2);
	set_indoors(1);    
	set_short("2nd Floor Passageway of Azha Keep.");
  set_long(
@AZHA
	This is a passageway that runs east-west through the second floor
of Azha Keep.  The walls are bare here, except for the occasional 
wooden support or stone column.  There is an open door to the south
with a sign to the side of it, written in Common and Tsarvani.  
AZHA
    );
	set_exits(([
	"south" : "/d/azha/fort/alhazen",     
	"west" : "/d/azha/fort/hall4",     
	"east" : "/d/azha/fort/hall2"
  ] ));     
	set_smell("default","You can smell the smoke from lit torches all around.");
	set_items(([
		"torches" : "Fairly common torches, good for lighting.",
		"sign" : "The sign reads: 'Colonel al-Hazen, Azha Garrison Commander'.",
		] ));
}
