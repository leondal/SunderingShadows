#include <std.h>
#include "../defs.h"
inherit ROOM;
int FLAG;
void create()
{
  	::create();
   	set_terrain(LIGHT_FOREST);
   	set_travel(FOOT_PATH);
   	set_property("no teleport",1);
   	set_property("no scry",1);
  	set_property("indoors",0);
  	set_property("light",2);
  	set_short("%^GREEN%^Next To A Small Lake%^RESET%^");
  	set_long("%^GREEN%^The %^BOLD%^%^CYAN%^water%^RESET%^"+
		"%^GREEN%^ of this lake seems to stand "+
		"almost perfectly still.  Its surface reflects "+
		"the pine trees around it as well as any mirror "+
		"could.  Despite the peacefulness of the water, this "+
		"area is anything but peaceful.  You stare "+
		"in wonder at what must be a rare site.  Before you "+
		"battles a majestic %^BOLD%^%^WHITE%^unicorn%^RESET%^%^GREEN%^"+
		" and a fiendish %^BOLD%^%^BLACK%^nightmare%^RESET%^%^GREEN%^."+
		"  As you watch them duel, you gradually realize that the "+
		"magical beasts are evenly matched.  Every thrust, nip, "+
		"and kick is dodged and countered easily.  You can not "+
		"help but feel compelled to %^YELLOW%^assist%^RESET%^ "+
		"%^GREEN%^one of these two creatures.  An ally on either side "+
		"could easily tip the balance of the fight.  A small "+
		"%^ORANGE%^dirt path%^GREEN%^ leads away from the "+
		"lake, headed south.\n");
  	set_smell("default","%^BOLD%^%^GREEN%^The smell of pine fills the air.");
  	set_listen("default","%^YELLOW%^The sounds of the two beasts dueling "+
		"echos across the lake.");
  	set_items(([
    		"lake" : "%^BOLD%^%^CYAN%^A small lake stands in the middle of this "+
			"secluded forest.  The top of the waters do not "+
			"seem to move at all, despite the gentle breeze.",
    		"unicorn" : "%^BOLD%^%^WHITE%^This regal looking creature is glistening with "+
			"sweat.  She resembles a large, well groomed horse, with a "+
			"solid white coat.  Aside from her size, the only real "+
			"difference is the large, shimmering %^YELLOW%^horn%^WHITE%^"+
			" that spirals from "+
			"the top of the creatures head.  She does not seem to notice "+
			"your presence as she battles with the hellish creature across "+
			"from her.  You can not guess how long these two have been "+
			"in battle, but from the looks of things, this unicorn looks "+
			"as if she could continue for much longer.  She deftly avoids "+
			"every attack by the nightmare, yet seems to always just miss "+
			"landing a powerful blow.  You feel as if you could %^CYAN%^"+
			"assist the unicorn%^RESET%^ and help her defeat the nightmare.",
    		"nightmare" : "%^BOLD%^%^BLACK%^A large, black steed lashes out"+
			" at the unicorn with %^RED%^flaming%^BLACK%^ hooves.  His"+
			" jet black coat looks as if it "+
			"stretched across the bones of his body.  A pair of glowing "+
			"%^RED%^red eyes%^BLACK%^ can be seen through the clouds of "+
			"smoke that drift up from his nostrils with each deep breath.  "+
			"This creatures oversized head contains a mouth full of sharp "+
			"fangs.  He lashes out at the unicorn, but always just misses "+
			"the nimble creature.  You feel as if you could %^CYAN%^assist "+
			"the nightmare%^RESET%^ and help him defeat the unicorn."
    	]));
  	set_exits( ([ "south" : ROOMS+"forest1"]) );
}

void init()
{
  	::init();
  		add_action("assist","assist");
}

void assist(string str)
{
  	if(!str){
    		tell_room(TP,"And what exactly are you trying to assist?");
    		return 1;
  	}
	if(str != "unicorn" && str != "nightmare"){
    		tell_room(TP,"It looks like you should assist nightmare or unicorn.");
	return 1;
  	}
  	if(str == "nightmare"){
	if(FLAG){ tell_object(TP,"%^YELLOW%^You have already made your choice."); 
		return 1;
	}

    		tell_room(TP,"%^RED%^As you move in to attack the unicorn, "+
				"the nightmare exhales a dark, murky cloud of "+
                                "smoke...disappearing from sight.  "+
				"The unicorn looks around, sniffing the air for"+
				" some sign of the foul creature.  The unicorn"+
				" closes her eyes briefly.\n  "+
   				"Suddenly, her horn begins to glow brightly,"+
				" surrounding her in a "+
				"shimmering light, and appears to be "+
				"revitalizing her.  "+
				"Having restored her energy, the angry beast"+
				" turns her "+
				"attention towards you.");
                tell_room(ETP,"%^RED%^As "+TPQCN+" moves in to attack the "+
				"unicorn, the nightmare "+
				"exhales a dark, murky cloud of smoke..."+
				"disappearing from site.  "+
				"The unicorn looks around, sniffing the air"+
				" for some sign of "+
				"the foul creature.  The unicorn closes her "+
				"eyes briefly.\n  "+
   				"Suddenly, her horn begins to glow brightly,"+
				" surrounding her in a "+
				"shimmering light, and appears to be "+
				"revitalizing her.  "+
				"Having restored his energy, the angry beast"+
				" turns her "+
                                "attention towards "+TPQCN+".",TP);
    		TO->set_long("%^GREEN%^The %^BOLD%^%^CYAN%^water%^RESET%^%^GREEN%^"+
				" of this lake seems to stand "+
				"almost perfectly still.  Its surface reflects "+
				"the pine trees around it as well as any mirror "+
				"could.  Despite the peacefulness of the water, this "+
				"area is anything but peacefull.  A small "+
				"dirt path leads away from the lake, headed south.\n");
    					remove_action("assist","assist");
    					new(MON+"unicorn.c")->move(TO);
    					present("unicorn")->force_me("kill "+TP->query_name()+"");
    					TP->add_align_adjust(-10);
    		tell_room(TP,"%^RED%^Your actions have affected your "+
						"alignment!");
    		FLAG=1;
		return 1;
  }

  if(str == "unicorn")
  {
	if(FLAG){ tell_object(TP,"%^YELLOW%^You have already made your choice."); 
		return 1;
	}
    	tell_room(TP,"%^YELLOW%^As you move in to attack the nightmare, the unicorn "+
                "seems to shimmer briefly, disappearing from sight.  "+
		"The nightmare looks around, sniffing the air for some sign of "+
		"the escaped unicorn.\n  The nightmare rises up on his rear legs "+
		"screaming in an awful, high pitched tone.  He flails his "+
		"flaming fore hooves in your direction.  He locks his eyes "+
		"upon yours, and they glow with pure hatred as he moves "+
		"in to attack.");
        tell_room(ETP,"%^YELLOW%^As "+TPQCN+" moves in to attack the nightmare, the unicorn "+
		"seems to shimmer briefly, disappearing from site.  "+
		"The nightmare looks around, sniffing the air for some sign of "+
		"the escaped unicorn. \n The nightmare rises up on his rear legs "+
		"screaming in an awful, high pitched tone.  He flails his "+
		"flaming fore hooves in your direction.  He locks his eyes "+
                "upon "+TPQCN+", and they glow with pure hatred as he moves "+
		"in to attack.",TP);
    	TO->set_long("%^GREEN%^The %^BOLD%^%^CYAN%^water%^RESET%^%^GREEN%^"+
		" of this lake seems to stand "+
		"almost perfectly still.  Its surface reflects "+
		"the pine trees around it as well as any mirror "+
		"could.  Despite the peacefulness of the water, this "+
		"area is anything but peacefull.  A small "+
		"dirt path leads away from the lake, headed south.\n");
    			remove_action("assist","assist");
    			TP->add_align_adjust(10);
    			new(MON+"nightmare.c")->move(this_object());
    			present("nightmare")->force_me("kill "+TP->query_name()+"");
    			tell_room(TP,"%^BOLD%^%^YELLOW%^Your actions have affected your "+
				"alignment!");
    	FLAG=1;
	return 1;
  }
}
void reset() { 
	::reset(); 
		FLAG=0; 
	return; 
}
