#include <std.h>

inherit VAULT;

void create() {
    	::create();
	set_name("hallway");
    	set_property("light",1);
    	set_property("indoors",1);
    	set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    	set_short("Gateway to the Abyss");
    	set_long(
@KAYLA
You are moving through the core of darkness.  Upon entering this room,
you notice the light from your torch dancing across the natural stone
walls of this cavern.  The darkness continues east and west.
KAYLA
    	);
    	set_exits(([
       	"west" : "/d/deku/dark/hall2",
       	"east" : "/d/deku/dark/elf2",
    	] ));
    	set_items(([
    	] ));
	
	set_trap_functions(({"east","west"}),({"gas_em","gas_em2"}),({"east","west"}));
}
int gas_em(string str){
	int poison;
    	if(interactive(TP)){
		toggle_trap("east");	
		tell_object(TP,"As you attempt to leave the room hear an audible click!");
		tell_room(ETP,""+TPQCN+" starts to leave the room and you hear an "+
			"audible click!",TP);	
		tell_object(TP,"%^BOLD%^%^GREEN%^You hear a hissing as a cloud of "+
			"sickly green gas issues from the walls around that exit.\n");
		TP->force_me("emote %^YELLOW%^gulps!%^RESET%^");
		tell_room(TO,"%^BOLD%^%^GREEN%^A sickly green mist issues from "+
			"the walls around that exit!",TP);
      	if((int)TP->query_stats("dexterity")>random(25)){
			tell_object(TP,"%^BOLD%^%^GREEN%^You manage to turn away and "+
				"the spray misses your eyes, but you are unable to "+
				"avoid the gas entirely.");
			TP->force_me("emote turns away from the gas and avoids taking it "+
				"directly in the face!");
			tell_room(ETP,""+TPQCN+" writhes as the gas "+
				"burns the exposed flesh!",TP);
			tell_object(TP,"%^BOLD%^%^RED%^The gas burns your exposed flesh badly!");
			TP->do_damage("torso",roll_dice(3,10));
			return 0;
		}
		tell_room(ETP,"%^BOLD%^%^GREEN%^The mist sprays directly "+
			"into "+TPQCN+"'s face!",TP);
		TP->set_temporary_blinded(1);
		tell_object(TP,"%^BOLD%^%^GREEN%^The mist hits you right in the face and "+
			"starts burning into your skin and eyes causing immense pain!");
		TP->add_attacker(TO);
		TP->continue_attack();
      	if((int)TP->query_stats("constitution")>random(25)){
      		tell_object(TP,"You get a whiff of the deadly vapor, but hopefully not "+
      			"enough to cause you permanent damage.");
      		TP->force_me("emote coughs as he inhales a little bit of gas.\n");
      		return 0;
      	}
      	poison = roll_dice(10,10);
      	TP->force_me("emote coughs and gags as the gas works its way "+
      		"to through the body!\n");
		TP->add_poisoning(poison);
		TP->setPoisoner(TO);
		return 0;
	}
	return 1;
}
int gas_em2(string str){
	int poison;
    	if(interactive(TP)){
		toggle_trap("west");	
		tell_object(TP,"As you attempt to leave the room hear an audible click!");
		tell_room(ETP,""+TPQCN+" starts to leave the room and you hear an "+
			"audible click!",TP);	
		tell_object(TP,"%^BOLD%^%^GREEN%^You hear a hissing as a cloud of "+
			"sickly green gas issues from the walls around that exit.\n");
		TP->force_me("emote %^YELLOW%^gulps!%^RESET%^");
		tell_room(TO,"%^BOLD%^%^GREEN%^A sickly green mist issues from "+
			"the walls around that exit!",TP);
      	if((int)TP->query_stats("dexterity")>random(25)){
			tell_object(TP,"%^BOLD%^%^GREEN%^You manage to turn away and "+
				"the spray misses your eyes, but you are unable to "+
				"avoid the gas entirely.");
			TP->force_me("emote turns away from the gas and avoids taking it "+
				"directly in the face!");
			tell_room(ETP,""+TPQCN+" writhes as the gas "+
				"burns the exposed flesh!",TP);
			tell_object(TP,"%^BOLD%^%^RED%^The gas burns your exposed flesh badly!");
			TP->do_damage("torso",roll_dice(3,10));
			return 0;
		}
		tell_room(ETP,"%^BOLD%^%^GREEN%^The mist sprays directly "+
			"into "+TPQCN+"'s face!",TP);
		TP->set_blind(1);
		tell_object(TP,"%^BOLD%^%^GREEN%^The mist hits you right in the face and "+
			"starts burning into your skin and eyes causing immense pain!");
		TP->add_attacker(TO);
		TP->continue_attack();
      	if((int)TP->query_stats("constitution")>random(25)){
      		tell_object(TP,"You get a whiff of the deadly vapor, but hopefully not "+
      			"enough to cause you permanent damage.");
      		TP->force_me("emote coughs as he inhales a little bit of gas.\n");
      		return 0;
      	}
      	poison = roll_dice(10,10);
      	TP->force_me("emote coughs and gags as the gas works its way "+
      		"to through the body!\n");
		TP->add_poisoning(poison);
		TP->setPoisoner(TO);
		return 0;
	}
	return 1;
}
void reset(){
        ::reset();
        if(!trapped("east"))
                toggle_trap("east");
        if(!trapped("west"))
                toggle_trap("west");
}
