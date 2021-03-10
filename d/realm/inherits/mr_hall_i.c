#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit CVAULT;

void create() 
{
	if(base_name(TO) != RA_MR_HALL && 
	base_name(TO) != RA_MR_BH &&
	base_name(TO) != RA_MR_MH &&
	base_name(TO) != RA_MR_FH && !random(4)) 
	{ 
     		switch(random(11)) 
		{
      		case 0:
	        		break;
      		case 1:
       			set_monsters(({RA_MON +"rand_warrior"}),({random(2)+ 1}));
       			set_monsters(({RA_MON +"rand_thief"}),({random(2) + 1}));
       			break;
			case 2:
				set_monsters(({RA_MON +"rand_warrior"}),({1}));
       			set_monsters(({RA_MON +"rand_cleric"}),({random(2) + 1}));
				break;
			case 3:
				set_monsters(({RA_MON +"rand_cleric"}),({1}));
       			set_monsters(({RA_MON +"rand_thief"}),({random(2) + 1}));
				break;
			case 4:
				if(!random(10)) 
				{
					set_monsters(({RA_MON + "sac_ghost"}), ({1}));
				}
				break;
			case 5:
				set_monsters(({RA_MON+"rand_warrior"}), ({1 + random(2)}));
				break;
			case 6:
				set_monsters(({RA_MON+"rand_thief"}), ({1 + random(2)}));
				break;
			case 7:
				set_monsters(({RA_MON+"rand_cleric"}), ({1 + random(2)}));
				break;
			case 8:
				set_monsters(({RA_MON+"rand_warrior"}), ({1 + random(2)}));
				set_monsters(({RA_MON + "sac_ghost"}), ({1}));
				break;
			case 9:
				set_monsters(({RA_MON+"rand_thief"}), ({1 + random(2)}));
				set_monsters(({RA_MON + "sac_ghost"}), ({1}));
				break;
			case 10:
				set_monsters(({RA_MON+"rand_cleric"}), ({1 + random(2)}));
				set_monsters(({RA_MON + "sac_ghost"}), ({1}));
				break;
		}
      	set_repop(30);
 	}

 	::create();
   	set_property("no teleport",1);
    	set_property("light",2);
    	set_property("indoors",1);
	set_property("no sticks", 1);
    	set_name("hallway of a forgotten keep");
    	set_short("%^BOLD%^%^RED%^Hallway of A Forgotten Keep%^RESET%^");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);

	set_long("%^RED%^The massive hallway that you find yourself "+
	"in is composed of %^BOLD%^bright red bricks%^RESET%^%^RED%^.  "+
	"It appears %^BOLD%^%^BLACK%^ancient%^RESET%^%^RED%^, though "+
	"there are very few signs of %^BOLD%^%^BLACK%^decay%^RESET%^%^RED%^, "+
	"as if a very %^RESET%^%^MAGENTA%^m%^BOLD%^e%^RESET%^"+
	"%^MAGENTA%^t%^BOLD%^i%^RESET%^%^MAGENTA%^c%^BOLD%^"+
	"u%^RESET%^%^MAGENTA%^l%^BOLD%^o%^RESET%^%^MAGENTA%^"+
	"u%^BOLD%^s%^RESET%^%^RED%^ hand plays a role in its upkeep.  "+
	"The craftsmanship of this place is astonishing, as if "+
	"each brick was carefully laid in its place.  Every available "+
	"section of wall has been painted with %^BOLD%^%^WHITE%^"+
	"a%^BOLD%^%^YELLOW%^w%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^-"+
	"%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^YELLOW%^s"+
	"%^BOLD%^%^WHITE%^p%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^"+
	"r%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^YELLOW%^"+
	"g%^RESET%^%^RED%^ and very l%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^"+
	"f%^BOLD%^%^WHITE%^e%^RESET%^ %^RED%^l%^BOLD%^%^WHITE%^"+
	"i%^RESET%^%^RED%^k%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^ "+
	"%^RESET%^%^WHITE%^m%^BOLD%^%^RED%^u%^RESET%^%^WHITE%^r"+
	"%^BOLD%^%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^RED%^s"+
	"%^RESET%^%^RED%^.  The floor is composed of "+
	"another slightly %^BOLD%^%^BLACK%^darker%^RESET%^"+
	"%^RED%^ and smoother brick.  Circular %^BOLD%^%^WHITE%^"+
	"g%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^o%^RESET%^"+
	"%^WHITE%^b%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^"+
	"s%^RESET%^%^RED%^ of %^BOLD%^%^YELLOW%^light%^RESET%^"+
	"%^RED%^ hover near, though never touch, the "+
	"%^BOLD%^%^WHITE%^vaulted ceiling%^RESET%^%^RED%^"+
	".%^RESET%^");


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
	"hallway is composed of these "+
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
	"The ceiling here looks as meticulously upkept "+
	"as the rest of this place and appears to be "+
	"made from the same slightly darker bricks "+
	"as the floor.%^RESET%^",
	({"globes", "globe", "globe of light", 
	"globes of light", "light globe"}) : "%^BOLD%^"+
	"%^WHITE%^These brilliant globes of light hover "+
	"near the ceiling effortlessly, though they "+
	"seem to never come in contact with it.  They "+
	"serve as the means by which this place keeps "+
	"from falling into utter darkness.%^RESET%^", 	
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
	"ceiling", "vaulted ceiling", "room"}) : 
	({"%^BOLD%^%^RED%^The bricks are quite old "+
	"and they were formed using a method that is "+
	"not known to you.  The magic in this place "+
	"is what serves to keep them in such a state "+
	"of repair, occassionally a mist is given off "+
	"by the globes of light, this mist is what "+
	"keeps them strong and what removes any debris.  "+
	"There seems to be no difference in the ones "+
	"that compose the ceiling and the floor here, "+
	"other than a slight variation in color.%^RESET%^", 
	45}), 
	({"globes", "globes of light", "globe of light", 
	"light globe", "globe"}) : ({"%^BOLD%^%^YELLOW%^"+
	"These small globes of light are entirely "+
	"magical in nature, there is no natural component "+
	"to them.  You can tell that there main purpose "+
	"is to release a light mist which settles over "+
	"the area, repairing it and removing any "+
	"debris.  They do, however, seem to be enchanted with a "+
	"lesser incantation that provides light to this "+
	"area.%^RESET%^", 45})
	]) ); 

	set_search("murals",(:TO,"mural_search":));
	set_search("mural", (:TO,"mural_search":));
	set_search("awe-inspiring murals", (:TO, "mural_search":));
	set_search("life like murals", (:TO, "mural_search":));
	set_search("brick", (:TO, "brick_search":));
	set_search("bricks", (:TO, "brick_search":));
	set_search("light red bricks", (:TO, "brick_search":));
	set_search("dark red bricks", (:TO, "floor_search":));
	set_search("dark bricks", (:TO, "floor_search":));
	set_search("floor", (:TO, "floor_search":));
}

void reset()
{
	object rand, rack;
	::reset();
	if(!random(25))
	{
		rack = present("weapon_ao_ob_saide");
		if(objectp(rack)) 
		{
			if(rack->is_rack_empty()) 
			{
				rack->remove();
			}
		}
		if(!present("armor_ao_ob_saide", TO) &&
		!present("weapon_ao_ob_saide", TO))
		{
			switch(random(2))
			{
				case 0:
					rand = new(RA_OB+"armor_stand");
					break;
				case 1:
					rand = new(RA_OB+"weapon_rack");
					break;
			}
			rand->move(TO);
		}	
	}
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
	"here - you find nothing that seems hidden or out of place.%^RESET%^");
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