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
wooden support or stone column.  There is an open door to the north
with a sign to the side of it, written in Common and Tsarvani.  To the 
east, there is a wide doorway which seems to open into some sort of
audience room.  To the south, a door opens on yet another room.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/fort/aldada",     
	"south" : "/d/azha/fort/chancelry",     
	"west" : "/d/azha/fort/hall3",     
	"east" : "/d/azha/fort/audience"
  ] ));     
	set_smell("default","You can smell burning wax of some form to the south.");
	set_items(([
		"torches" : "Fairly common torches, good for lighting.",
		"sign" : "The sign to the north reads: 'Lord al-Dada, Chancellor of Azha Province'.",
		] ));
}
