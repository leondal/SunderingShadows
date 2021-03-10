#include <std.h>
#include "../theater.h"
inherit CROOM;
	void make_creatures();
	void create(){
	make_creatures();
	set_repop(55);
   	::create();
   	set_property("indoors",1);
   	set_property("light",2);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^%^BOLD%^Desert Sun Theater - Orchestra");
   	set_short("%^RED%^%^BOLD%^Desert Sun Theater - Orchestra");
   	set_long("%^ORANGE%^The interior of the large theater opens up"+
		" around you.  %^RED%^Deep red "+
		"%^ORANGE%^ velvet carpeting conceals the floor of the theater.  "+
		"The plush velvet carpet is dotted with a %^YELLOW%^sunburst%^RESET%^"+
		"%^ORANGE%^ pattern.  Matching the theme of the carpet, "+
		"%^BOLD%^%^RED%^red velvet%^RESET%^%^ORANGE%^ drapes cover the walls"+
		" of the theater, to absorb the sound.  %^YELLOW%^Golden "+
		"chestnut%^RESET%^%^ORANGE%^ wooden seats with %^RED%^crimson "+
		"colored%^ORANGE%^ cushions line the inside of the theater."+
		"  Many of the chairs are overturned now, some of the "+
		"cushions are ripped to shreds.  From here you can see the box seats"+
		" on the mezzanine level, where the wealthy observed performances."+
		"  The domed ceiling features ornate carvings of human figures "+
		"supporting %^YELLOW%^gilded gold suns%^RESET%^%^ORANGE%^, framing"+
		" a highly detailed mural.  Filling the western wall of the theater"+
		" are the remains of the stage.  This once mighty stage is now blocked"+
		" off from fallen timber and rubble, preventing access to the backstage"+
		" area.  This once majestic theater lays in tattered ruins, a pale "+
		"imitation of its former opulence.\n");  
   	set_smell("default","%^RED%^A musty stale scent hangs in the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A bewitching melody can be heard.");
  	set_items(([
      	({"seats","chair","chairs"}) : "%^YELLOW%^Golden "+
	"chestnut chairs carved with sweeping lines are set up into rows around"+
	" the interior of the theater.  These armed chairs feature plush %^RED%^"+
	"velvet cushions %^YELLOW%^and padded backs, making it a real treat for"+
	" the audience.  Many of the chairs now are overturned or knocked out of"+
	" their formation, with the velvet cushions ripped to shreds.",
      	({"rug","drapes","carpet","curtains"}) : "%^RED%^Matching dark crimson "+
	"velvet carpet and drapes bathe the theater in a %^BOLD%^fiery%^RESET%^"+
	"%^RED%^ glow.  Burnt into the velvet is a sunburst pattern that has been"+
	" gilded with %^YELLOW%^metallic golden%^RESET%^%^RED%^ threads.  The "+
	"drapes are trimmed with%^YELLOW%^ golden fringe%^RESET%^%^RED%^ and"+
	"%^YELLOW%^ braid%^RESET%^%^RED%^, bringing out the %^YELLOW%^golden "+
	"tones%^RESET%^%^RED%^ of the%^ORANGE%^ chestnut wood%^RED%^.",
		({"figures","ceiling","statues"}) : "%^ORANGE%^Golden chestnut figures of human"+
	" men and women create the border of the ceiling, framing the "+
	"elaborate mural.  These nude classical figures hold gilded %^YELLOW%^gold"+
	" disks%^RESET%^%^ORANGE%^ between each pair.  This type of architecture"+
	" was commonly used for many centuries before it fell out of fashion.",
		({"stage"}) : "%^ORANGE%^Large amounts of rubble and timber block"+
	" the stage off, shattering the wooden planks of the floor.  The %^RED%^"+
	"velvet drapes%^ORANGE%^ that once framed this stage now hang in"+
	" tattered and torn ruins.  With this amount of rubble, it would be "+
	"impossibly dangerous to dig through to the backstage area.",
		({"mural"}) : "%^BOLD%^%^BLUE%^Cast against a %^CYAN%^light blue"+
	" %^BLUE%^sky, two figures dominate this large mural that covers the "+
	"ceiling of the theater.   The first figure is that of a %^YELLOW%^golden"+
	" %^BLUE%^haired young male.  The athletically toned figure is dressed in"+
	" a short %^WHITE%^white toga%^BLUE%^ that highlights his %^RESET%^"+
	"%^ORANGE%^golden skin%^BOLD%^%^BLUE%^.  His short hair curls about his face"+
	" and the %^GREEN%^laurel of leaves%^BLUE%^ worn as a crown.  Looking as if "+
	"he was captured in the middle of plucking a melody on his%^YELLOW%^ gold "+
	"lyre%^BLUE%^, the handsome male stands on %^WHITE%^voluminous clouds%^BLUE%^"+
	".  The other figure, that of a %^RESET%^%^ORANGE%^swarthy complexion%^BOLD%^"+
	"%^BLACK%^ dark haired %^BLUE%^male is seated on a cloud.  His dark hair "+
	"pushed back from his face, this figure's %^RESET%^%^ORANGE%^dark eyes%^BOLD%^"+
	"%^BLUE%^ are clearly defined.  Dressed in loose fitting %^RESET%^%^MAGENTA%^"+
	"purple robes%^BOLD%^%^BLUE%^ and %^BLACK%^s%^RED%^t%^RESET%^%^MAGENTA%^r"+
	"%^BOLD%^%^RED%^i%^BLACK%^pe%^RED%^d %^BLUE%^leggings, his clothing differs "+
	"vastly from the youthful male's.  His right hand supports the neck of a "+
	"%^RED%^rosewood lute%^BLUE%^, while his left hovers over the strings of "+
	"the elegant instrument.",
	]));
}
void make_creatures()
{	
	int monsters;
   	monsters = has_mobs();
		if(!monsters) 
		{
     		if(mons) { mons = ([]); }
        		switch(random(40)){
case 0..10:
break;
case 11..21:
            set_monsters(({MOB"pinksiren"}),({1}));
break;
case 24..34:
            set_monsters(({MOB"purplesiren"}),({1}));
break;
case 35..39:
            set_monsters(({MOB"pinksiren",MOB"purplesiren"}),({1,1}));
break;
			}
		}
	return;
}
void reset()
{
    	::reset();
    	make_creatures();
    	return;
}
