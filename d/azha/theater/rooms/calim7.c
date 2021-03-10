#include <std.h>
#include "../theater.h"
inherit CALIM;
	void create(){ 
	::create();
	add_item(({"obelisk"}),"%^BOLD%^Resting on a rectangular platform,"+
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
	" spell of sorts. ");
	set_exits(([ "northeast" : ROOMDIR"calim8",
			 "west" : ROOMDIR"calim6",
		    ]));
}