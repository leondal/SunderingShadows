#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
#define SD "/d/common/daemon/randstuff_d"
inherit ROOM;
int searched;
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

	set_long("%^BOLD%^%^RED%^This massive chamber spans several "+
	"dozen feet in each direction.  It is composed entirely of "+
	"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ "+
	"that have somehow, miraculously, withstood the test of time.  "+
	"However, many of them look to have recently been "+
	"forcefully removed from the walls here.  There are "+
	"gaps between the bricks and some of the ones that "+
	"are left intact have %^BOLD%^%^MAGENTA%^enormous "+
	"cracks%^RESET%^%^BOLD%^%^RED%^ in them, some have chunks "+
	"missing, as if some type of blunt force object came into "+
	"vicious contact with them.  The floor here is riddled with "+
	"%^BOLD%^%^MAGENTA%^debris%^BOLD%^%^RED%^, most of which "+
	"are pieces of %^RESET%^%^RED%^brick%^BOLD%^%^RED%^, but you "+
	"spot the occassional %^BOLD%^%^WHITE%^bone%^BOLD%^%^RED%^"+
	" and other, less identifiable, objects.  A tunnel into "+
	"what appears to be more worn and unstable "+
	"%^RESET%^%^RED%^brick hallways%^BOLD%^%^RED%^ "+
	"leads out of this room to the north and to the "+
	"east.%^RESET%^");

     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dusty and decay, making "+
	"it hard to breath.");    

	set_items(( [
		({"tunnels", "brick tunnels", "tunnel", "brick tunnel"}) : 
		"%^RED%^These tunnels appear much older and more "+
		"unstable.  They are in an obvious state of disarray.  "+
		"They meet with this room from the north and the "+
		"east.%^RESET%^",
		({"bricks", "dark red bricks", "brick"}) :
		"%^RED%^These ancient bricks have managed to "+
		"somehow withstand the test of time.  However, "+
		"most of them are now either missing from the "+
		"walls, lined with %^BOLD%^%^MAGENTA%^enormous "+
		"cracks%^RESET%^%^RED%^, or missing "+
		"chunks.  You realize that some type of "+
		"blunk force object has recently "+
		"come into contact with them.%^RESET%^", 
		({"cracks", "enormous cracks"}) : "%^BOLD%^%^MAGENTA%^"+
		"These cracks in the bricks here are obviously the "+
		"result of blunt force, as "+
		"opposed to the result of time wearing them down.%^RESET%^", 
		({"debris", "pile of debris", "bones", "bone"}) :
		"%^BOLD%^%^MAGENTA%^"+
		"These debris litter the floor here, "+
		"mostly they are composed of pieces of brick, "+
		"obviously from the walls.  However, you do spot "+
		"some %^BOLD%^%^WHITE%^bones%^BOLD%^%^MAGENTA%^, "+
		"which appear human, and the occassional "+
		"less identifiable object.%^RESET%^",		
     	] ));

	set_exits(([
		"north" : CAT_ROOMS"cat_hw_first_19",
		"east" : CAT_ROOMS"cat_hw_first_20"
	] )); 

      set_search("default", "%^MAGENTA%^You wonder cautiously if there "+
	"might be something of value hidden within the %^RED%^debris%^RESET%^"+
	"%^MAGENTA%^.%^RESET%^");
	searched = random(2);
	set_search("debris", (:TO, "debris_search":));
}

int debris_search() 
{
	if(!TP->query_invis()) 
	{
      	tell_room(TO,TPQCN+"%^BOLD%^%^WHITE%^ digs through a pile "+
		"of debris, tossing some human bones out of "+TP->QP+ " way!%^RESET%^",TP);
    	}
	tell_object(TP,"%^BOLD%^%^WHITE%^You dig through a pile "+
    	"of debris, tossing some human bones out of your way.%^RESET%^");
    	if(searched == 0 && !random(5)) 
	{
       	tell_object(TP,"%^BOLD%^%^RED%^Your search turns up something "+
        	"of value.%^RESET%^");
        	if(!TP->query_invis()) 
		{
            	tell_room(TO,TPQCN+"%^BOLD%^%^RED%^ finds something of value "+
            	"hidden in the debris.%^RESET%^",TP);
        	}
       	SD->find_stuff(TO,"random");
        	searched = 1;
        	return 1;
    	}
    	tell_object(TP,"%^BOLD%^%^WHITE%^You give up the search after "+
    	"digging through the debris and finding nothing of value.%^RESET%^");    

	if(!TP->query_invis()) 
	{
      	tell_room(TO,TPQCN+"%^BOLD%^%^RED%^ seems to find nothing of "+
        	"interest in the debris.%^RESET%^",TP);
    	}

    	searched = 1;
    	return 1;
}

void reset()
{
	::reset();
	searched = random(2);
	if(!present("husk of zhour")) 
	{
		new(DEKU_MON"zhour_husk")->move(TO);
	}
}
