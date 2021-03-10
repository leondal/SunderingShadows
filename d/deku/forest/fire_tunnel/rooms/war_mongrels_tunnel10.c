#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;
int max_resets = 15, resets_so_far = 0;

void do_my_stuff(object ob)
{
	if(!objectp(ob)) return;
	ob->move(TO);
	ob->set_moving(0);
	ob->set_speed(0);
}

void create() 
{
	object ob, mon;
    	::create();
    	set_long(TO->query_long()+"%^RED%^ The tunnel dead ends here, leaving "+
	"you the only option of heading back eastward.%^RESET%^");

    	set_exits(([
    		"east" : FTUN_ROOMS"war_mongrels_tunnel9"
    	] ));
	mon = new(DEKU_MON"war_mongrel");
	mon->move(TO);
	ob = new(DEKU_MON"fire_imp");
	do_my_stuff(ob);
	mon->add_protector(ob);
	ob = new(DEKU_MON"fire_elemental");
	do_my_stuff(ob);
	mon->add_protector(ob);
	ob = new(DEKU_MON"hellfire_golem");
	do_my_stuff(ob);
	mon->add_protector(ob);
	ob = new(DEKU_MON"hellhound");
	do_my_stuff(ob);
	mon->add_protector(ob);	
}

//For when the War Mongrel Dies
void add_portal()
{
	resets_so_far = 0;
	tell_room(TO, "%^BOLD%^%^BLACK%^With a thunderous ripping sound, "+
	"a portal opens in the center of this room.  A cool, crisp breeze "+
	"flowing in from the other side!%^RESET%^");	
	add_exit(F_ROOMS"32-16", "portal");
	remove_item("portal");
	add_item(({"portal"}), "%^BOLD%^%^BLACK%^This glowing black portal "+
	"leads out into the shadowlord forest.%^RESET%^");
}
void remove_portal()
{
	tell_room(TO, "%^BOLD%^%^BLUE%^The air is suddenly sucked from "+
	"the room and the portal slams shut!%^RESET%^");
	remove_exit("portal");
	remove_item("portal");
}


void reset()
{
	object mon, ob;
	resets_so_far++;
	if(resets_so_far >= max_resets)
	{
		resets_so_far = 0;
		if(member_array("portal", TO->query_exits()) != -1) 
		{
			remove_portal();
		}
		if(!objectp(mon = present("war mongrel", TO))) 
		{
			mon = new(DEKU_MON"war_mongrel");
			mon->move(TO);
		}	
		if(!objectp(ob = present("fire imp", TO)))
		{
			ob = new(DEKU_MON"fire_imp");
			do_my_stuff(ob);
		}
		mon->add_protector(ob);
		if(!objectp(ob = present("fire elemental", TO))) 
		{
			ob = new(DEKU_MON"fire_elemental");
			do_my_stuff(ob);
		}
		mon->add_protector(ob);
		if(!objectp(ob = present("hellhound", TO)))
		{
			ob = new(DEKU_MON"hellhound");
			do_my_stuff(ob);
		}
		mon->add_protector(ob);
		if(!objectp(ob = present("hellfire golem", TO)))
		{
			ob = new(DEKU_MON"hellfire_golem");
			do_my_stuff(ob);
		}
		mon->add_protector(ob);
	}
	::reset();
	return;
}
