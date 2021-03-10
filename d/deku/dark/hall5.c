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
You are moving through the core of darkness. This is a long hallway
of natural caverns.  There are many passages going in many directions.
KAYLA
    	);
    	set_exits(([
       	"west" : "/d/deku/dark/hall6",
       	"east" : "/d/deku/dark/hall4",
       	"north" : "/d/deku/dark/elf4"
    	] ));
	set_trap_functions(({"east","west","north"}),({"poke_em","stick_em","gas_em"}),({"east","west","north"}));
}
int poke_em(string str){
	toggle_trap("east");
	tell_object(TP,"As you move step to the east you feel a stone give "+
		"beneath your weight and then you hear an ominous click.");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^RED%^A small hole opens in the south wall.");
	tell_room(TO,"%^BOLD%^%^RED%^A spear shoots out with great velocity!");
	tell_object(TP,"The spear flies directly at you with deadly accuracy!");
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,"%^BOLD%^%^RED%^"+TPQCN+" dodges at the last moment and "+
			"the spear flies into the far wall and explodes violently in a "+
                        "loud F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!", TP);
		return 0;
	}
	tell_room(TO,"%^BOLD%^%^RED%^The spear flies into "+TPQCN+" and explodes in a loud "+
		"F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!",TP);
	tell_object(TP,"%^BOLD%^%^RED%^The spear flies into you and explodes in a loud "+
		"F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!");
	TP->do_damage("torso",roll_dice(3,10));
	TP->add_attacker(TO);
	TP->continue_attack();
	return 0;
}
int gas_em(string str){
	int poison;
    	if(interactive(TP)){
		toggle_trap("north");
		tell_object(TP,"As you attempt to leave the room hear an audible "+
			"click as the rock beneath your foot gives a little!");
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
int stick_em(string str){
	int poison;
	toggle_trap("west");
	tell_object(TP,"As you step toward the east you feel one of the stones in "+
		"the floor give a little then you hear an audible click!");
	TP->force_me("emote gulps");
	tell_room(TO,"%^BOLD%^%^RED%^Four small holes open in the south wall.");
	tell_room(TO,"%^BOLD%^%^RED%^Four arrows shoot out suddenly with great velocity!");
	tell_object(TP,"The arrows fly directly at you with deadly accuracy!");
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,"%^BOLD%^%^RED%^"+TPQCN+" dodges at the last moment and "+
			"the arrows fly into the far wall and shatter into splinters!");
		return 0;
	}
	tell_room(TO,"%^BOLD%^%^RED%^The arrows fly into "+TPQCN+" and stick with a "+
		"sickly thud!",TP);
	tell_object(TP,"%^BOLD%^%^RED%^The arrows slam into you and pierce your flesh deeply!");
	TP->do_damage("torso",roll_dice(1,8));
	TP->do_damage("torso",roll_dice(1,8));
	TP->do_damage("torso",roll_dice(1,8));
	TP->do_damage("torso",roll_dice(1,8));
	TP->add_attacker(TO);
	TP->continue_attack();
      if((int)TP->query_stats("constitution")>random(25)){
      	tell_object(TP,"You feel the arrows burn as they pierce your flesh.");
      	return 0;
      }
      poison = roll_dice(10,10);
	TP->setPoisoner(TO);
      TP->force_me("emote %^BOLD%^%^GREEN%^coughs and chokes as the poison from the "+
      	"arrows works its way to "+TP->query_possessive()+" system.%^RESET%^\n");
	TP->add_poisoning(poison);
	return 0;
}
void reset(){
        ::reset();
        if(!trapped("east"))
                toggle_trap("east");
        if(!trapped("west"))
                toggle_trap("west");
        if(!trapped("north"))
                toggle_trap("north");
}
