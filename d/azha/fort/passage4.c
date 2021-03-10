// Main Passageway of Azha Keep
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
	set_short("Main Passageway of Azha Keep.");
  set_long(
@AZHA
In this part of the passageway, armor and helms are being cleaned
by soldiers sitting on the ground, a never-ending task that eats
up the time.  Some of the mail shirts are being hung from hooks
in the wall, while others are being looked over for possible mending.
The main passage continues east-west through the keep, while there
are some living quarters for the enlisted men to the north and 
south.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/fort/barracks1",     
	"south" : "/d/azha/fort/barracks2",     
	"west" : "/d/azha/fort/stair1",     
	"east" : "/d/azha/fort/passage3"
  ] ));     
	set_smell("default","This part of the hall smells of dust, dirt and "+
	"the other things that accompany a frontier soldier.");
	set_listen("default","You hear the sounds of soldiers talking and of "+
	"armor being cleaned and oiled.");
	set_items(([
		"shirts" : "You notice some gaping tears in these shirts on the "+
		"wall, probably the work of bandits or orcs in a recent skirmish.",
		] ));
}
