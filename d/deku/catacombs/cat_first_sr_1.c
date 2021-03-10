#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_SR_ONE;
int portal_open;
void add_glyph();
void add_portal();
void create() 
{
	::create();
	set_exits(([
		"north" : CAT_ROOMS"cat_first_room_1",
	] )); 
	remove_gold();
	add_glyph();
}

void init()
{
	::init();
	add_action("observe_glyph", "observe");
	add_action("activate_glyph", "activate");
}

int activate_glyph(string str)
{
	object rkey;
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(portal_open == 1) return 0;
	if(str == "glyph" || str == "the glyph" ||
	str == "magical glyph" || str == "yellow glyph")
	{
		if(!objectp(rkey = present("catyellowrunekey", TP))) 
		{
			tell_object(TP, "%^BOLD%^%^WHITE%^You do not have "+
			"the proper key to activate the glyph!%^RESET%^");
			return 1;
		}
		if(present("rune keeper", TO)) 
		{
			tell_object(TP, "%^BOLD%^%^WHITE%^The rune keeper "+
			"blocks your attempt to activate the glyph!%^RESET%^");
			return 1;
		}
		tell_object(TP, "%^BOLD%^%^WHITE%^You point "+
		rkey->query_short() + "%^BOLD%^%^WHITE%^ "+
		"toward the glyph and feel a surge of power flow out "+
		"of it as a portal bursts open in place of the glyph!"+
		"%^RESET%^");
		
		tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ points "+
		" a "+rkey->query_short() + "%^BOLD%^%^WHITE%^ "+
		"toward the glyph and suddenly a portal bursts "+
		"open in place of the glyph!%^RESET%^", TP);
		add_portal();
		return 1;
	}
	return 0;
}

int observe_glyph(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(portal_open == 1) return 0;
	if(str == "glyph" || str == "the glyph" ||
	str == "magical glyph" || str == "yellow glyph")
	{
		tell_object(TP, "%^BOLD%^%^CYAN%^You circle the glyph, "+
		"observing it closely.  You are on the verge of giving "+
		"up when you realize its meaning.  This glyph is "+
		"serving as an anchor - to hold something here - on "+
		"the prime material plane.  Should you have the "+
		"required key, you believe you could %^BOLD%^"+
		"%^WHITE%^activate%^BOLD%^%^CYAN%^ it - "+
		"opening a doorway to this place.%^RESET%^");

		tell_room(TO, TPQCN +"%^BOLD%^%^CYAN%^ circles "+
		"the glpyh for awhile, before stopping and offering "+
		"a look of apprehension.%^RESET%^", TP);
		return 1;
	}
	return 0;
}

void add_glyph()
{
	if(portal_open == 1)
	{
		tell_room(TO, "%^BOLD%^%^WHITE%^The portal vanishes "+
		"instantly and there is left a strange %^BOLD%^%^YELLOW%^"+
		"glyph%^BOLD%^%^WHITE%^ on the floor in its place!%^RESET%^");
	}
	portal_open = 0;
	TO->add_item(({"glyph", "yellow glyph", "magical glyph"}), 
	"%^YELLOW%^This strange glyph has been inscribed into "+
	"the center of this chamber.  It is a sickly yellow hue, "+
	"and seems to pulse constantly, as if it were alive.  "+
	"You believe that there is some meaning to it, "+
	"and perhaps you can determine it, if you were to "+
	"%^BOLD%^%^CYAN%^observe%^RESET%^%^YELLOW%^ "+
	"closely enough.%^RESET%^");
	TO->remove_item(({"portal", "yellow portal"}));
	TO->remove_exit("portal");
}

void add_portal()
{
	portal_open = 1;
	TO->add_item(({"portal", "yellow portal"}), 
	"%^YELLOW%^This portal it outlined in a sickly yellow "+
	"hue.  It has burst open in the center of this chamber.%^RESET%^");
	TO->remove_item(({"glyph", "yellow glyph", "magical glyph"}));
	TO->add_exit(CAT_ROOMS"cat_secret_healer", "portal");
}

void long_desc() 
{	
	if(portal_open == 0)
	{
		return "%^BOLD%^%^RED%^The massive chamber that you find yourself "+
		"in looks at least several centuries old.  It is composed entirely of "+
		"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ that have somehow, "+
		"miraculously, withstood the test of time.  It looks as if it has "+
		"stood empty for many of those centuries.  The walls, floor, and "+
		"ceiling of this chamber look to still be quite sturdy.  "+
		"A strange %^BOLD%^%^YELLOW%^glyph%^BOLD%^%^RED%^ has been "+
		"inscribed into the center of the floor here.  A "+
		"thick layer of %^BOLD%^%^BLACK%^dust%^BOLD%^"+
		"%^RED%^ cakes everything here.  "+
		"An opening leads out of here to the north.%^RESET%^";
	}
	if(portal_open == 1)
	{
		return "%^BOLD%^%^RED%^The massive chamber that you find yourself "+
		"in looks at least several centuries old.  It is composed entirely of "+
		"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ that have somehow, "+
		"miraculously, withstood the test of time.  It looks as if it has "+
		"stood empty for many of those centuries.  The walls, floor, and "+
		"ceiling of this chamber look to still be quite sturdy.  "+
		"A %^BOLD%^%^YELLOW%^portal%^BOLD%^%^RED%^, outlined in a sickly "+
		"yellow hue, has burst open in the center of this chamber.  "+
		"A thick layer of %^BOLD%^%^BLACK%^dust%^BOLD%^%^RED%^ "+
		"cakes everything here.  "+		
		"An opening leads out of here to the north.%^RESET%^";
	}
	
}


void reset()
{
	object mob, rs;
	::reset();
	if(portal_open == 1)
	{
		add_glyph();
	}
	if(!present("rune keeper", TO)) 
	{
		mob = new(DEKU_MON"rune_keeper");
		mob->move(TO);
		rs = new(DEKU_MISC"glyph_key");
		rs->set_portal(1);
		rs->move(mob);
	}		
}	

