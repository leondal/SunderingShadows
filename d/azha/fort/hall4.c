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
with a sign to the side of it, written in Common and Tsarvani.  You 
see some stairs to the west of you.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/fort/assurya",     
	"west" : "/d/azha/fort/stair2",     
	"east" : "/d/azha/fort/hall3"
  ] ));     
	set_smell("default","You can smell the smoke from lit torches all around.");
	set_items(([
		"torches" : "Fairly common torches, good for lighting.",
		"sign" : "The sign reads: 'Captain as-Surya, Imperial Army'.",
		] ));
}
