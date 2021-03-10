#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit ROOM;
string myguard, myroom;
int orb_activated, count;
object *vics;

void create() 
{
 	::create();
   	set_property("no teleport",1);
    	set_property("light",0);
    	set_property("indoors",1);
	set_property("no sticks", 1);
    	set_name("marble corridor");
    	set_short("%^BOLD%^%^BLACK%^A metal room");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);

	set_long((:TO, "longdesc":));  

     	set_smell("default","%^BOLD%^A strong aroma of magic hangs heavily here.");
    	set_listen("default","%^BOLD%^A tangible silence greets you.%^RESET%^");

	set_items(([({"orb", "glowing orb", "large orb", 
	"large glowing orb"}) : "%^BOLD%^%^CYAN%^This large "+
	"glowing orb hovers here - propelled by some "+
	"unseen force - just glancing at you have the sudden "+
	"urge to walk up and %^BOLD%^%^WHITE%^touch"+
	"%^BOLD%^%^CYAN%^ it.", 
	({"ceiling", "vaulted ceiling"}) : "%^BOLD%^%^WHITE%^"+
	"The ceiling hangs so far overhead that it looks like "+
	"nothing more than a tiny dot on a distant "+
	"horizon.%^RESET%^", 
	({"walls", "wall", "east wall", "north wall", 
	"south wall", "west wall"}) : "%^BOLD%^%^RED%^The "+
	"walls here are completely devoid of anything, they are "+
	"entirely smooth and composed from a "+
	"%^BOLD%^%^BLACK%^dark metallic material%^BOLD%^%^RED%^."+
	"%^RESET%^", 
	({"dark material", "material", "metallic material", 
	"dark metallic material", "dark material"}) : "%^BOLD%^%^BLACK%^The "+
	"strange material that creates this room is of unknown "+
	"origin, though it appears to be metallic, it is unlike "+
	"anything you have ever seen before.%^RESET%^",
   	] ));

	set_property("room lore", 
	([({"orb", "glowing orb", "large orb", 
	"large glowing orb"}) : ({"%^BOLD%^%^CYAN%^This orb is enchanted "+
	"by a vastly powerful magic - almost beyond anything within the "+
	"scope of the weave.  You are certain that it functions as some "+
	"type of summoning device - though exactly what it might summon - "+
	"eludes you.  You feel that interacting with it could be very "+
	"dangerous.%^RESET%^", 50}),
	({"dark material", "dark metal", "material", "room"}) : ({"%^BOLD%^%^BLACK%^"+
	"The dark metallic material here is nothing "+
	"more than typical iron, however, some ancient and dark "+
	"power has imbued it with a very strong magic.  You can "+
	"tell that all typical methods of magical "+
	"movement are blocked here because of it.%^RESET%^", 45}) ]) ); 
	myguard = RA_MON+"spec_ser_thief";
	myroom = base_name(TO);
    	set_search("default","You find no place for anything to be concealed.");
}

void init() 
{
        ::init();
        add_action("touch_function","touch");
}

void reset() 
{
	::reset();
	if(!orb_activated) return;
	if(count >= 4)
	{
		count = 0;
		orb_activated = 0;
		TO->add_item(({"orb", "glowing orb", "large orb", 
		"large glowing orb"}), "%^BOLD%^%^CYAN%^This large "+
		"glowing orb hovers here - propelled by some "+
		"unseen force - just glancing at you have the sudden "+
		"urge to walk up and %^BOLD%^%^WHITE%^touch"+
		"%^BOLD%^%^CYAN%^ it.");
		return;
	}
	count++;
}

string longdesc()
{
	string tmp;
	tmp =	"%^BOLD%^%^BLACK%^This massive chamber is a perfect "+
	"square, as far as you can ascertain.  The %^BOLD%^%^WHITE%^vaulted "+
	"ceiling%^BOLD%^%^BLACK%^ hangs so far overhead that it "+
	"looks like nothing more than a dot on a distant horizon.  "+
	"The walls here are perfectfly smooth - %^BOLD%^%^RED%^flawless"+
	"%^BOLD%^%^BLACK%^ - in design.  Nothing adorns them, "+
	"not a mark or an ornament of any kind - it as if this "+
	"places rests forgotten and abandoned, void of any life.  "+
	"As you've come to expect this room is composed "+
	"entirely of a %^BOLD%^"+
	"%^WHITE%^dark metallic material%^BOLD%^%^BLACK%^, except "+
	"for perhaps the ceiling.%^RESET%^";
	if(!orb_activated || member_array("orb", keys(query_items())) != -1)
	{
		tmp += "%^BOLD%^%^BLACK%^  The only thing of interest "+
		"here at all in fact is a "+
		"%^BOLD%^%^CYAN%^large glowing orb%^BOLD%^%^BLACK%^ "+
		"hovering in what you assume to be the direct "+
		"center of this room.%^RESET%^";
	}	
	return tmp;
}

int not_true_invis(object ob)
{
	if(!objectp(ob)) return 0;
	if(ob->query_true_invis()) return 0;	
	return 1;
}

void angered4()
{
	string gname, gshort;
	object guard;
	guard = new(myguard);
	if(!objectp(guard)) 
	{
		tell_room(TO, "%^BOLD%^%^MAGENTA%^A voice thunders through the room:  "+
		"%^RESET%^BUG REPORT THIS OR MAIL SAIDE - MY GUARDIAN IS MISSING!");
	}
	else
	{
		gname = guard->QCN;
		gshort = guard->query_short();	
		tell_room(TO, "%^BOLD%^%^MAGENTA%^A voice thunders through the room:  %^RESET%^"+
		"Step forth "+gname+ " and destroy THESE PUNY INSECTS!!!!!");
		tell_room(TO, gshort+"%^BOLD%^%^BLACK%^ steps out from the portal and "+
		"the portal blinks out of existence behind "+guard->QO+"!%^RESET%^");
		guard->move(TO);
	}
	
	vics = filter_array(vics, "not_true_invis", TO);
	vics->set_paralyzed(0);
	tell_room(TO, "%^BOLD%^%^CYAN%^You feel the sonic force holding you "+
	"in place ebb and fade away!%^RESET%^");
}

void angered3()
{
	tell_room(TO, "%^BOLD%^%^MAGENTA%^A voice thunders through the room:  %^RESET%^"+
	"I should have DESTROYED your pathetic world EONS ago - but NAY "+
	"and for my MERCY I am to receive uninvited guests????");
	tell_room(TO, "%^BOLD%^%^BLACK%^You see the outline of a creature forming "+
	"just inside the portal.....%^RESET%^");
	call_out("angered4", 10);
}

void angered2()
{
	tell_room(TO, "%^BOLD%^%^MAGENTA%^A voice thunders through the room:  %^RESET%^"+
	"WHY ARE YOU HERE????????  BY WHAT RIGHT DO YOU INTRUDE UPON MY "+
	"SANCTUM????");
	tell_room(TO, "%^BOLD%^%^BLACK%^A glowing dark portal opens on the western wall of this room - "+
	"stretching up as far as you can see!%^RESET%^");
	call_out("angered3", 10);
}

void angered()
{
	TO->remove_item(({"orb", "glowing orb", "large orb", 
	"large glowing orb"}));
	tell_room(TO, "%^BOLD%^%^YELLOW%^The large "+
	"orb suddenly explodes - releasing a powerful "+
	"%^CYAN%^sonic wave%^BOLD%^%^YELLOW%^ - "+
	"that radiates outward and engulfs you!%^RESET%^"); 
	vics = filter_array(all_living(TO), "not_true_invis", TO);
	vics->set_paralyzed(10000, "%^BOLD%^%^CYAN%^"+
	"The sonic wave has left you completely "+
	"unable to move!%^RESET%^");
	call_out("angered2", 10);
}

int touch_function(string arg)
{
	if(!objectp(TP)) return 0;
	if(!arg) return 0;
	if(arg != "orb" && arg != "large orb"
	&& arg != "glowing orb" && arg != "large glowing orb")
	{
		return 0;
	}
	if(orb_activated) return 0;
	orb_activated = 1;
	tell_room(TO, TPQCN + "%^BOLD%^%^WHITE%^ "+
	"walks up to the %^BOLD%^%^CYAN%^"+
	"large glowing orb%^BOLD%^%^WHITE%^ "+
	"and touches it.%^RESET%^", ({TP}));
	tell_object(TP, "%^BOLD%^%^WHITE%^You "+
	"walk up to the %^BOLD%^%^CYAN%^"+
	"large glowing orb%^BOLD%^%^WHITE%^ "+
	"and touch it.%^RESET%^");
	tell_object(TP, "%^BOLD%^%^YELLOW%^Your hands are suddenly "+
	"%^BOLD%^%^RED%^HOT%^BOLD%^%^YELLOW%^!%^RESET%^");
	call_out("angered", 3);
	return 1;
}	
	
void fight_ends4(object vics)
{
	object MoveMeWhere;
	MoveMeWhere = find_object_or_load(myroom);
	if(!objectp(MoveMeWhere)) 
	{
		tell_room(TO, "%^B_CYAN%^%^YELLOW%^Destination room not "+
		"found - please do <bug here> from this room - Saide.");
		vics->set_temporary_blinded(0);
		vics->set_paralyzed(0);
		return;
	}
	tell_room(TO, "%^BOLD%^%^WHITE%^You feel things starting "+
	"to materialize around you again.... and you find yourself "+
	"somewhere drastically different as your vision slowly returns "+
	"and you are again able to move.");
	all_inventory(TO)->move(MoveMeWhere);
	vics->set_paralyzed(0);
	vics->set_temporary_blinded(0);
	return;
}

void fight_ends3(object vics)
{
	
	tell_room(TO, "%^BOLD%^%^MAGENTA%^A voice thunders in your head: "+
	"%^RESET%^I await your intrusion into my inner sanctum, "+
	"should you make it that far, I will devour your mortal shell and "+
	"raise you as one of my many servants, before I finally "+
	"turn my gaze to your puny little world and send it into "+
	"OBLIVION!!!");
	call_out("fight_ends4", 15, vics);	
}	

void fight_ends2(object vics)
{
	tell_room(TO, "%^BOLD%^%^RED%^You feel as if you are "+
	"weightless and nothing is real....%^RESET%^");
	tell_room(TO, "%^BOLD%^%^MAGENTA%^A voice thunders in your head: "+
	"%^RESET%^I HAVE NOT FINISHED WITH YOU YET!!!  YOUR JOURNEY "+
	"IS ONLY STARTING!!!!");
	call_out("fight_ends3", 15, vics);
}

void fight_ends()
{
	object *vics;
	tell_room(TO, "%^BOLD%^%^BLACK%^The world around you suddenly "+
	"simply ceases to be... your vision fails....");
	vics = filter_array(all_living(TO), "is_non_immortal_player", FILTERS_D);
	vics->set_temporary_blinded(1000);
	vics->set_paralyzed(1000, "You are completely helpless and unable to move.");
	call_out("fight_ends2", 15, vics);
}
