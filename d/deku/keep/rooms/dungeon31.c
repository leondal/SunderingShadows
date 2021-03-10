#include <std.h>
#include "../keep.h"
inherit DUNGEON;
string original_long;

void original_configuration() 
{
	set_long(original_long + "  %^BOLD%^%^WHITE%^This corridor "+
    	"slopes downward to the northwest and sharply upward to "+
    	"the southeast.  You may travel in either direction, but you "+
    	"must brave the unknown danger of the thick %^BOLD%^"+
    	"%^BLACK%^darkness%^BOLD%^%^WHITE%^.%^RESET%^");	
}

void create() 
{
	::create();
    	original_long = TO->query_long();
    	original_configuration();
    	set_exits(([
        "southeast": KEEPR + "dungeon32",
        "northwest" : KEEPR + "dungeon30"
    	] ));
    	remove_search("bones");
    	set_search("bones",(:TO,"un_bones_search":));
}

void un_bones_search() 
{
	object where;
	if(!objectp(TP)) return;
    	if(member_array("tunnel",TO->query_exits()) != -1) 
	{    
      	tell_room(TO,TPQCN+"%^BOLD%^%^WHITE%^ digs through a pile of bones.%^RESET%^",TP);
        	tell_object(TP,"You dig through the bones but find nothing else of value.");
		return;
	}
	TO->set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  An "+
    	"entrance to a %^YELLOW%^tunnel%^BOLD%^%^WHITE%^ has been "+
    	"revealed underneath a pile of bones.%^RESET%^");
	tell_object(TP,"You dig through the bones and find the "+
    	"entrance to a %^YELLOW%^tunnel%^RESET%^!");
	tell_room(TO,TPQCN+"%^BOLD%^%^WHITE%^ digs through a pile "+
    	"of bones and finds a hidden "+
	"%^YELLOW%^tunnel%^BOLD%^%^WHITE%^ entrance!%^RESET%^",TP);
	TO->add_exit(KEEPR +"tunnel1","tunnel");
    	where = find_object_or_load(KEEPR + "tunnel1");
    	where->add_exit(KEEPR + "dungeon31","tunnel");
    	tell_room(where,"%^RED%^Bones begin falling away from the large "+
	"pile!%^RESET%^");
    	where->set_long(where->query_long() + "%^YELLOW%^  An entrance to "+
	"a %^BOLD%^%^WHITE%^tunnel%^YELLOW%^ has been revealed underneath "+
	"the pile of %^BOLD%^%^WHITE%^bones%^YELLOW%^.%^RESET%^");
    	return;
}

void reset() 
{
	object room;
    	::reset();
    	if(sizeof(query_exits()) < 1) return;
    	if(member_array("tunnel",TO->query_exits()) != -1) 
	{
      	remove_exit("tunnel");
        	original_configuration();
    	}
    	room = find_object_or_load(KEEPR+"tunnel1");
    	if(member_array("tunnel",room->query_exits()) != -1) 
	{
      	room->remove_exit("tunnel");
        	room->original_configuration();
    	}
}
