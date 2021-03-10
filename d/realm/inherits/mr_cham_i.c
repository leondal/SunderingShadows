#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit ROOM;
string wwall, hidden_room, sexit;
int searched; 

void open_hidden_room()
{
	object hidroom;
	if(searched == 0) 
	{
		searched = 1;
		tell_room(TO, "%^BOLD%^%^RED%^A section of the "+wwall+
		" wall slides to the side, revealing "+
		"an opening!%^RESET%^");
		TO->add_exit(hidden_room, sexit);
		hidroom = find_object_or_load(hidden_room);
		if(!objectp(hidroom)) return;
		hidroom->open_hidden_room();
		return;
	}
}

void close_hidden_room()
{
	object hidroom;
	if(searched == 1)
	{
		tell_room(TO, "%^BOLD%^%^RED%^A section of the "+wwall+
		" wall slides back into place!%^RESET%^");
		searched = 0;
		TO->remove_exit(sexit);
		hidroom = find_object_or_load(hidden_room);
		if(!objectp(hidroom)) return;
		hidroom->close_hidden_room();
		return;
	}
}



void create() 
{
 	::create();
   	set_property("no teleport",1);
    	set_property("light",2);
    	set_property("indoors",1);
	set_property("no sticks", 1);
    	set_name("marble corridor");
    	set_short("%^BOLD%^%^RED%^A large chamber%^RESET%^");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);

	set_long("%^RED%^This chamber fans out before you "+
	"in all directions, it is massive.  It is composed of "+
	"%^BOLD%^bright red bricks%^RESET%^%^RED%^ which appear "+
	"ancient, yet show very few signs of %^BOLD%^%^BLACK%^"+
	"decay%^RESET%^%^RED%^.  The floor beneath your feet is "+
	"created from another, %^BOLD%^%^BLACK%^darker%^RESET%^"+
	"%^RED%^ and slightly smoother brick.  The "+
	"%^BOLD%^%^WHITE%^vaulted ceiling%^RESET%^%^RED%^ "+
	"hangs far overhead and you are unable to determine "+
	"from what material it has been created.  The walls "+
	"around you are painted with %^BOLD%^%^WHITE%^"+
	"a%^BOLD%^%^YELLOW%^w%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^-"+
	"%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^YELLOW%^s"+
	"%^BOLD%^%^WHITE%^p%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^"+
	"r%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^YELLOW%^"+
	"g%^RESET%^%^RED%^ and very l%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^"+
	"f%^BOLD%^%^WHITE%^e%^RESET%^ %^RED%^l%^BOLD%^%^WHITE%^"+
	"i%^RESET%^%^RED%^k%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^ "+
	"%^RESET%^%^WHITE%^m%^BOLD%^%^RED%^u%^RESET%^%^WHITE%^r"+
	"%^BOLD%^%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^RED%^s"+
	"%^RESET%^%^RED%^.  The upkeep here is amazing, "+
	"suggesting that a very %^RESET%^%^MAGENTA%^m%^BOLD%^e%^RESET%^"+
	"%^MAGENTA%^t%^BOLD%^i%^RESET%^%^MAGENTA%^c%^BOLD%^"+
	"u%^RESET%^%^MAGENTA%^l%^BOLD%^o%^RESET%^%^MAGENTA%^"+
	"u%^BOLD%^s%^RESET%^%^RED%^ hand must play a "+
	"role in maintaining this place.  An "+
	"%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^r"+
	"%^BOLD%^%^WHITE%^b%^BOLD%^%^YELLOW%^ of "+
	"light%^RESET%^%^RED%^, several feet in diamater, "+
	"floats effortlessly here, perhaps midway to the "+
	"ceiling, preventing this chamber from falling "+
	"into total %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^.");


     	set_smell("default","The smell of sulfur and singed flesh almost overcomes you.");
    	set_listen("default","The sounds of battle echo all around you.");

	set_search("default", "What do you want to search?");

	set_items(([ ({"brick", "bricks", "bright red brick", 
	"bright red bricks"}) : "%^BOLD%^%^RED%^The walls of "+
	"this hallway are composed of these flawless ancient "+
	"bricks.  They are in very good condition and "+
	"very few signs of decay, as if something has been "+
	"very meticulous in their upkeep.%^RESET%^", 
	({"dark brick", "floor", "darker brick", 
	"smooth brick", "smoother brick", 
	"dark brick"})  : "%^RED%^The floor of this "+
	"chamber is composed of these "+
	"flawless slightly dark red bricks.  They are "+
	"obviously ancient, but show very few signs of "+
	"decay, suggesting that something has "+
	"been very meticulous in their upkeep.%^RESET%^", 
	({"murals", "awe-inspiring murals", 
	"life like murals", "mural"})  : "%^BOLD%^%^YELLOW%^"+
	"The murals are the obvious work of an "+
	"excellent painter.  They are so life like "+
	"that you almost think you are watching "+
	"the scenes that they depict unfold before "+
	"you, as if you were there.  They portray "+
	"giants, minotaurs, ogres, orcs, trolls, hobgoblins, "+
	"and gnolls.  "+
	"For some reason the illustrator has added "+
	"vicious horns to all of them though, as "+
	"if in an attempt to make them appear "+
	"demonic.  They are banded together "+
	"by some powerful creature that stands "+
	"far behind them and directs them to "+
	"ravage all manner of other races.  "+
	"The beauty of the paintings themselves "+
	"does little to make the scenes "+
	"less grim.%^RESET%^", 
	({"wall", "walls"}) : "%^RED%^The walls "+
	"here are made from flawless "+
	"%^BOLD%^bright red bricks%^RESET%^"+
	"%^RED%^ and have been painstakingly "+
	"painted with very exquisite and "+
	"life like murals.%^RESET%^", 
	({"ceiling", "vaulted ceiling"}) : "%^RED%^"+
	"The ceiling here hangs far overhead "+
	"and you are not able to determine its "+
	"state of repair or the material from "+
	"which it was composed.%^RESET%^",
	({"orb", "orb of light", "light orb"}) : "%^BOLD%^"+
	"%^WHITE%^This briliant orb of light hovers "+
	"here effortlessly.  It is large, perhaps "+
	"two feet in diamater, and seems to be "+
	"the only thing keeping this place from "+
	"falling into utter darkness.%^RESET%^", 	
   	] ));

	set_property("room lore", ([({"mural", "murals", 
	"awe-inspiriting murals", 
	"life like murals"}) : ({"%^BOLD%^%^YELLOW%^These "+
	"murals are not painted by an artist hand, rather, "+
	"they have been placed here magically as wards "+
	"to prevent anyone from entering this place "+
	"magically.  They occassionally move around, "+
	"causing the scenes to change slowly over time "+
	"but usually go unnoticed.  The magic that has "+
	"imbued them is what causes the sound of battle "+
	"to echo around you.  The scenes which they depict "+
	"are from a time long ago and from another plane of "+
	"existence.%^RESET%^", 45}), 
	({"bricks", "brick", "bright red brick",
	"bright red bricks", "darker brick", 
	"smoother brick", "smooth brick", "floor", 
	"room"}) : 
	({"%^BOLD%^%^RED%^The bricks are quite old "+
	"and they were formed using a method that is "+
	"not known to you.  The magic in this place "+
	"is what serves to keep them in such a state "+
	"of repair, occassionally a mist is given off "+
	"by the the orb of light, this mist is what "+
	"keeps them strong and what removes any debris.  "+
	"There seems to be no difference in the ones "+
	"that compose the floor here, "+
	"other than a slight variation in color.%^RESET%^", 
	45}), 
	({"orb", "orb of light", "light orb"}) : ({"%^BOLD%^"+
	"%^YELLOW%^This large orb is entirely magical in "+
	"nature, there is no natural component to it.  "+
	"You can determine that its main purpose is to "+
	"release a light mist which settles over the "+
	"chamber repairing it and removing any debris.  "+
	"It does, however, seem to be enchanted with a "+
	"lesser incantation that provides light to the "+
	"chamber.%^RESET%^", 45}),
	]) ); 

	set_search("murals",(:TO,"mural_search":));
	set_search("mural", (:TO,"mural_search":));
	set_search("awe-inspiring murals", (:TO, "mural_search":));
	set_search("life like murals", (:TO, "mural_search":));
	set_search("brick", (:TO, "brick_search":));
	set_search("bricks", (:TO, "brick_search":));
	set_search("light red bricks", (:TO, "brick_search":));
	set_search("dark red bricks", (:TO, "brick_search":));
	set_search("dark bricks", (:TO, "brick_search":));
	set_search("floor", (:TO, "floor_search":));
}

void init()
{
	::init();
	add_action("push_brick", "push");
}



void reset()
{
	::reset();
	close_hidden_room();
}	

int push_brick(string arg)
{
	if(!arg) return 0;
	if(arg != "brick") return 0;
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ pushes one of the bricks "+
	"into the wall, but it comes right "+
	"back out!%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^RED%^You push the brick that was sticking "+
	"out back into the wall, but it slowly slides right back out!"+
	"%^RESET%^");
	if(searched == 0) 
	{
		open_hidden_room();
		return 1;
	}
	if(searched == 1)
	{
		close_hidden_room();
		return 1;
	}
	return 1;
}


int mural_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN + "%^BOLD%^%^YELLOW%^ searches carefully "+
	"around the murals.%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^YELLOW%^You search the murals "+
	"carefully, you notice nothing hidden, but you do "+
	"think that you saw some of the creatures "+
	"in them move a little.%^RESET%^");
	return 1;
}

int brick_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN +"%^BOLD%^%^RED%^ searches carefully over "+
	"the bricks.%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^RED%^You carefully search the bricks "+
	"here and find one that seems like it sticks out a little "+
	"too far, you could probably %^BOLD%^%^WHITE%^push"+
	"%^BOLD%^%^RED%^ it, if you wanted to.%^RESET%^");
	return 1;
}

int floor_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN + " %^RED%^searches carefully along the "+
	"floor.%^RESET%^", TP);
	tell_object(TP, "%^RED%^You search the floor carefully but "+
	"manage to find nothing of consequence.%^RESET%^");
	return 1;
}