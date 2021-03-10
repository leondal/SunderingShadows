#include <std.h>
#include "../tharis.h"
inherit VAULT;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Hotel Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_property("indoors",1);
		set_property("light",3);
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		
		set_name("tharis inn");
		set_short("%^BOLD%^%^MAGENTA%^Tharis Inn%^RESET%^");
		
		set_long("%^BOLD%^%^MAGENTA%^Tharis Inn%^RESET%^\n"+
			"%^RESET%^%^CYAN%^It is hardly unexpected to find "+
			"this surprisingly large guestroom decorated in a "+
			"%^RESET%^%^ORANGE%^f%^RED%^e%^BOLD%^%^BLACK%^l"+
			"%^RESET%^i%^ORANGE%^ne %^RESET%^%^CYAN%^motif. From "+
			"the %^BOLD%^%^MAGENTA%^pink %^RESET%^%^CYAN%^and "+
			"%^RESET%^white %^RESET%^%^CYAN%^bedcover on four "+
			"poster bed, to the delicate %^RESET%^woven-wood "+
			"%^RESET%^%^CYAN%^furniture with its cat-shaped, "+
			"quilted pillows, the whole room seems cloyingly "+
			"cute. %^BOLD%^%^MAGENTA%^Pastel pink %^RESET%^"+
			"%^CYAN%^walls with tiny%^RESET%^ white roses "+
			"%^RESET%^%^CYAN%^painted all over, delicately "+
			"scalloped floor and ceiling boards, along with "+
			"nearly a dozen paintings of what can only be "+
			"%^RESET%^%^ORANGE%^M%^RED%^i%^WHITE%^n%^ORANGE%^x"+
			"%^WHITE%^i%^ORANGE%^'s %^RESET%^%^CYAN%^many capers "+
			"further accent the room, somehow turning one of "+
			"the most spacious of areas in the inn into a "+
			"tight, claustrophobic space.  Not even the large, "+
			"curtained window that looks out over a %^MAGENTA%^"+
			"%^BOLD%^fl%^WHITE%^o%^RED%^w%^MAGENTA%^er %^RESET%^"+
			"%^CYAN%^and %^GREEN%^grass lot%^CYAN%^ helps with "+
			"the sense of being tightly surrounded.%^RESET%^");

		set_smell("default","\nA thick, cloying perfume permeates "+
			"the air.");
		set_listen("default","The room is rather quiet and stuffy.");
		
		set_items(([
		({"bed cover","bed"}):"%^BOLD%^%^MAGENTA%^Painted white, "+
			"the four poster bed occupies about half the room and "+
			"would easily sleep a few guests with room to stretch "+
			"out.  Covering the bed is a bright pink quilt with "+
			"the images of cats playing, sleeping and otherwise "+
			"being cat like, stitched across it.  The needlework "+
			"is actually rather superb and the cover seems warm "+
			"and comfortable.%^RESET%^",
		({"furniture","woven-wood","pillows"}):"%^BOLD%^%^WHITE%^"+
			"Most of the furniture in this room, from the chairs "+
			"to the small desk to the cabinet with the wash "+
			"basin appears to be made out of this woven-style "+
			"wood work, where thin strips of wood have been "+
			"softened, and then woven like cloth strips, back "+
			"into solid pieces of wood.  The method prevents the "+
			"need of nails or other fixtures and makes for rather "+
			"sturdy furniture.  All of which has been painted a "+
			"muted shade of white.  On the chairs and bed, a few "+
			"vaguely cat shapped pillows have been set, giving "+
			"some contrast to the white furniture.%^RESET%^",
		({"walls","roses"}):"%^BOLD%^%^MAGENTA%^The walls are a "+
			"pale pink pastel color, over which someone has "+
			"taken the time to paint thousands of small %^WHITE%^"+
			"rosebuds%^MAGENTA%^.  There appears to have been a "+
			"pattern to it, though the artist got off track at "+
			"one point since a few spots have large clusters, "+
			"while others have very few.%^RESET%^",
		({"floor","ceiling","ceiling boards","floor boards"}):""+
			"%^BOLD%^%^WHITE%^Running along the top and bottom of "+
			"the walls are scalloped boards, painted the same off "+
			"white as the furniture.  These boards seperate the "+
			"%^MAGENTA%^pink%^WHITE%^ walls from the white ceiling "+
			"and %^RESET%^%^ORANGE%^hard wood%^BOLD%^%^WHITE%^ "+
			"floor.%^RESET%^",
		({"paintings","minxi"}):"%^RESET%^%^ORANGE%^From posed "+
			"to naturally capering about, it seems someone has "+
			"tried to capture the complete life of a cat into "+
			"painted form.  Everywhere you look, there is Minxi, "+
			"the %^WHITE%^white %^ORANGE%^and orange tabby that "+
			"lives at the Inn.%^RESET%^",
		({"window","lot"}):"%^RESET%^A large window occupies the "+
			"western wall and looks out over a pretty %^GREEN%^"+
			"grassy field %^RESET%^spotted with wild growing "+
			"%^MAGENTA%^flowers%^RESET%^.  Thick white curtains "+
			"hang to either side, allowing guests to open or close "+
			"the view as desired.",		
		]));
		
		set_exits(([
		"east":ROOMS"tharis_hotel2",
		]));
		
		set_door("pink door",ROOMS"tharis_hotel2","east",0);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}