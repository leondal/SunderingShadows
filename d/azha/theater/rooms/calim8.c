#include <std.h>
#include "../theater.h"
inherit CALIM;
	void create(){ 
	::create();
	set_long("%^ORANGE%^A circular plaza opens up as Calimpur"+
		" street comes to an end.  The plaza seems like at one time"+
		" it was a hustling and bustling place.  Though now weeds and"+
		" grass fight their way through the cracks in the limestone plaza."+
		"  The remains of tents can be seen around the plaza, their weathered"+
		" and rotting wood frames crumbling.  Dull torn, tattered and dingy "+
		"cloth blows in the breeze, giving this plaza a forgotten appearance."+
		"  To the west a large %^YELLOW%^sandstone theater%^RESET%^%^ORANGE%^"+
		" looms over the plaza.  Once majestic buildings circle around the plaza,"+
		" in the same state of disrepair that the rest of the older parts of"+
		" Azha are in. %^RESET%^Limestone obelisks%^ORANGE%^ dot the skyline"+
		" with their %^BOLD%^%^BLUE%^blue quartz%^RESET%^%^ORANGE%^ tops, "+
		"circling around the theater, two of them stationed on either "+
		"side of the entrance to the theater.\n%^RESET%^");
	set("night long","%^BLUE%^This empty plaza seems spooky during the"+
		" night.  The wind blows the ratty and torn tent cloths, giving them"+
		" a ghost-like appearance.  The vacant plaza stands out in the open,"+
		" encircled by the %^BOLD%^%^BLACK%^dark silhouettes%^RESET%^%^BLUE%^"+
		" of the buildings around it.  To the west a theater looms, it's mosaic"+
		" walls bathed by a faint series of %^RESET%^lights%^BLUE%^.  The lights"+
		" are provided by %^RESET%^limestone obelisks%^BLUE%^ that circle "+
		"around the outer edges of the theater. On either side of the "+
		"passageway to the theater, two obelisks stand.  Weeds and grass push up "+
		"through the cracks in the limestone plaza, adding to it's "+
		"forgotten macabre appearance.\n%^RESET%^");
	add_item(({"obelisk","obelisks"}),"%^BOLD%^Resting on a rectangular platform,"+
	" this limestone obelisk rises up nearly  10 feet into the"+
	" air. Carved deep into each limestone side, a symbol of a "+
	"%^BLUE%^warhammer%^WHITE%^ supporting a pair of %^YELLOW%^"+
	"balanced scales%^WHITE%^"+
	" lays.  This"+
	" symbol matches the ones that can be found in Tyr's temple,"+
	" leading you to believe it has some connection to the church."+
	"  Stacked above this symbol are a series of %^RESET%^%^MAGENTA%^"+
	"runes%^BOLD%^%^WHITE%^ carved into"+
	" the obelisk.  Mounted on top of the obelisk is a %^BLUE%^"+
	"blue quartz%^WHITE%^"+
	" pyramid that radiates a steady glow.  For those with knowledge"+
	" of such runes and symbols, it appears these read to be a warding"+
	" spell of sorts.");
	add_item(({"plaza","cloth","wood"}),"%^YELLOW%^The plaza is empty "+
	"now, save for the skeletal frames of the tents left behind.  The"+
	" once colorful tent cloths are faded and tattered now, their "+
	"brilliant colors dingy and gray.  Some of the tent frames have rotted"+
	" away, scattering them across the limestone plaza.");  
	set_exits(([ "northwest" : ROOMDIR"calim5",
			 "southwest" : ROOMDIR"calim7",
			 "west" : ROOMDIR"theater1",
			 "east" : ROOMDIR"cal1",
	]));
	set_pre_exit_functions(({"west"}),({"go_west"}));

}

int go_west()
{
 	write("%^BOLD%^%^BLUE%^Your feel a tingling "+
		"sensation as you pass through a magical ward.");
     	return 1;
}
