// Main Staircase -- First Floor, Azha Keep
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
	set_short("Main Staircase, First Floor");
  set_long(
@AZHA
%^BOLD%^First Floor Landing%^RESET%^
	You are looking at a stone staircase that appears to lead to the
second floor of the keep.  The room that contains these stairs is
wider than the main passageway and is divided by them into 2 halves
to the west.  There are two open portals to the northwest and the
southwest.  The main passage of the keep is to the east.  A banner
hangs down from the ceiling just in front of the staircase, while the
walls are covered with pikes and spontoons as a decorative touch.
AZHA
    );
	set_exits(([
	"up" : "/d/azha/fort/stair2",     
	"northwest" : "/d/azha/fort/servant1",     
	"southwest" : "/d/azha/fort/servant2",     
	"east" : "/d/azha/fort/passage4",     
  ] ));     
	set_smell("default","A strong fragrance seems to be coming from upstairs.");
	set_items(([
		"banner" : "This is a scarlet banner with a silver crescent moon",
		] ));
}
