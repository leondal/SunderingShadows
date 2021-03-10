#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit ROOM;
void create() 
{
    	::create();
    	set_short("%^BOLD%^%^RED%^A massive brick chamber%^RESET%^");
    	set_name("A massive brick chamber");
    	set_property("light",0);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	if(!random(2)) 
	{
		set_property("no sticks", 1);
	}

	set_long("%^BOLD%^%^RED%^This massive chamber spans "+
	"several dozen feet in each direction.  It looks ancient, "+
	"yet it is somehow in remarkably good condition.  "+
	"The northern half of it is composed of "+
	"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ "+
	"that have somehow, miraculously, withstood "+
	"the test of time.  The southern half of this "+
	"chamber is an entirely different story, it is "+
	"created from some %^RESET%^%^BLUE%^strange blue"+
	"%^BOLD%^%^RED%^ substance, that gives off a "+
	"constant, eerie %^CYAN%^glow%^BOLD%^%^RED%^.  "+
	"It is the same substance that the entry of this "+
	"place was created from, however, you "+
	"are almost nauseous in this room, just from "+
	"being in the light of the %^CYAN%^glow%^BOLD%^%^RED%^.  "+
	"You are almost sure that you can feel a "+
	"%^BOLD%^%^MAGENTA%^hideous prescence%^BOLD%^%^RED%^ "+
	"inside your head, but you are unable to determine "+
	"from where it came, or even if it is real.  The "+
	"%^CYAN%^floor%^BOLD%^%^RED%^ near the southern "+
	"wall of this room appears "+
	"to be rippling, not unlike the surface of water "+
	"caught in a soft constant breeze.  "+
	"An opening, in the center of the north wall, "+
	"leaves this chamber and becomes a "+
	"much more worn and unstable %^RESET%^%^RED%^"+
	"brick tunnel%^BOLD%^%^RED%^.%^RESET%^");


	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dust and decay, making "+
	"it hard to breath.");    

    	set_items(( [
		({"substance", "blue substance"}) : "%^BLUE%^This "+
		"strange blue substance forms the southern half "+
		"of this chamber.  It is giving off a constant, eerie "+
		"%^BOLD%^%^CYAN%^glow%^RESET%^%^BLUE%^.  You "+
		"are almost nauseous just being in the light "+
		"of the glow.%^RESET%^",
		({"glow", "eerie glow"}) : "%^BOLD%^%^CYAN%^"+
		"This eerie glow is being given off by the "+
		"%^RESET%^%^BLUE%^substance%^BOLD%^%^CYAN%^ "+
		"that forms the southern half of this chamber.  "+
		"You are almost nauseous just from being "+
		"in its light.%^RESET%^", 
		({"dark red bricks", "red bricks", "bricks"}) : 
		"%^RED%^These bricks form the northern half "+
		"of this chamber.  They look ancient, but they have "+
		"managed to withstand the test of time.%^RESET%^",
		({"tunnel", "brick tunnel", "opening"}) :
		"%^BOLD%^%^RED%^An opening in the center of "+
		"the north wall leads out to this tunnel.  "+
		"It looks in a state of disarry, obviously "+
		"much more worn and unstable.%^RESET%^", 
		({"floor"}) : "%^BOLD%^%^CYAN%^The floor of "+
		"this room is mostly unremarkable and strangely "+
		"free of debris.  However, near the "+
		"southern wall, in the part of it that has "+
		"been created from the strange %^RESET%^"+
		"%^BLUE%^blue substance%^BOLD%^%^CYAN%^ "+
		"it appears to be rippling, much like "+
		"the surface of water caught in a "+
		"constant soft breeze.  You could "+
		"%^RESET%^observe%^BOLD%^%^CYAN%^ "+
		"it, if you wanted to.%^RESET%^",
     	] ));

set_exits(([
		"north" : CAT_ROOMS"cat_hw_first_23",
	] )); 

}

void init()
{
	::init();
	add_action("observe_floor", "observe");
	add_action("dive_floor", "dive");
}

int observe_floor(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(str != "floor" && str != "south floor") return 0;
		
	tell_object(TP, "%^BOLD%^%^CYAN%^You kneel down near "+
	"the rippling part of the floor... and suddenly "+
	"it dawns on you!  IT IS water!  You could easily "+
	"%^RESET%^%^BLUE%^dive%^BOLD%^%^CYAN%^ into it!%^RESET%^");

	tell_object(TP, "%^BOLD%^%^CYAN%^You are suddenly standing "+
	"again... as if you never kneeled... you did, didn't you?  "+
	"You might as well go for a %^RESET%^%^BLUE%^dive%^BOLD%^"+
	"%^CYAN%^ into the refreshing water...%^RESET%^");

	tell_room(TO, TPQCN +"%^BOLD%^%^CYAN%^ suddenly kneels "+
	"down near the rippling part of the floor, then "+
	"just as suddenly stands back up and grins "+
	"%^RESET%^%^RED%^strangely%^BOLD%^%^CYAN%^ "+
	"while staring down at it.%^RESET%^", TP);
	return 1;
}


int dive_floor(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(str != "floor" && str != "water") return 0;
	tell_object(TP, "%^BOLD%^%^CYAN%^You decide to "+
	"dive on into the.... floor???  WHAT ARE YOU DOING?  "+
	"This thought comes to you in mid-air -- it is "+
	"too late -- you remember the %^BOLD%^%^MAGENTA%^"+
	"hideous presence%^BOLD%^%^CYAN%^ "+
	"you felt in your head.%^RESET%^");

	tell_object(TP, "%^BOLD%^%^RED%^You ready your body "+
	"for the pain that is sure to come... but you feel "+
	"none as you pass into the floor and find yourself "+
	"somewhere else!%^RESET%^");

	tell_room(TO, "%^BOLD%^%^RED%^You watch in disbelief "+
	"as "+TPQCN+"%^BOLD%^%^RED%^ runs and dives into the "+
	"south part of the floor -- you are further shocked as "+
	TP->QP+" body disappears into it!%^RESET%^", TP);
	TP->move(CAT_ROOMS"cat_sec_entry");
	return 1;
}

