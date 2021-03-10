//mtnroad9.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit VAULT;

object ob;
string dest;

void create(){
	::create();
	set_property("light",3);
// set_property("no teleport",1);
	set_short("%^GREEN%^Gate in the foothills%^RESET%^");
   set_long(
@STYX
This path meanders through forested foothills and runs generally north and south.  To the north you can catch glimpses of a wide gravel trail.  A foreboding mountain range towers to the south but this area seems pretty much deserted for some reason.  A heavy gate blocks your path.  In fact, it hangs from a heavy iron fence running along the base of the mountains here as far as you can see east and west.
STYX
	);
	set_smell("default","The air smells moist and clean.");
	set_listen("default","You hear the wind whistling through the trees.");
	set_items( ([ 
	({"foothills", "forested foothills"}):"%^GREEN%^The foothills seem to be the leading edge of the mountain range.", 
	({"trail", "gravel trail" }):"%^BOLD%^Glints of sun shining off the gravel catch your eye and it looks well-maintained.", 
	({"path"}):"%^ORANGE%^The path is comfortably wide and easy to traverse here.", 
	({"range", "mountain range"}):"The mountains look like they will be very difficult and dangerous to cross.",
	]) );
   set_exits(([
       "north":ROADOUT"mtnroad8",
       "gate":ROADOUT"mtnroad10",
   ]));
   set_pre_exit_functions( ({"north", "gate"}), ({"past_gate", "thru_gate"}) );
   set_door("gate",ROADOUT"mtnroad10","gate",0);	    
  	dest = ROADOUT"mtnroad10";
	set_door_description("gate", 
@STYX
This heavy gate is made of wrought iron and blocks the path entirely.
The gate doesn't appear locked but you'll obviously have to open it to
go on.  A sign hangs on the gate, perhaps warning of dangers to come.
%^BOLD%^You should definitely read it!
STYX
	);
	dest = ROADOUT"mtnroad10";
}

void init(){
	::init();
	add_action("read_sign", "read");
       if (!present("sign on the gate",TO))
            new(ROADOUT"obj/gatesign")->move(TO);
}

int past_gate(){
	if(query_open("gate") && (query_verb() != "gate")) {
		tell_room(TP,"The gate swings shut behind you as you move on.");
		tell_room(TO,"The gate swings shut just as "+TPQCN+" moves on.", TP);
		set_open("gate", 0);
		dest->set_open("gate", 0);
		tell_room(dest, "The gate swings shut with a clang as footsteps fade into the distance.");
		return 1;
	}
	return 1;
}

/* This doesn't seem to work for some reason so I'm going to plan B in mtnroad10
int thru_gate(){
	if(!query_open("gate")) {
		if(newbiep(TP) && (TP->query_level() < 5 || avatarp(TP)) 
		tell_room(TP,"Are you sure you're ready to venture beyond and begin the journey to join the harsher world?  Perhaps you should turn back and gain some more experience in the ways of adventuring first.");
		return 1;
	}	
	return 1;
}
*/

int read_sign(string str){   
	if(str == "sign" || str == "gate") {
		if(newbiep(TP) || avatarp(TP)) {
			write(
@STYX
%^YELLOW%^* * * * * * * * * * C A U T I O N * * * * * * * * * * * *%^RESET%^
This is the first gateway to leaving the relative safety of Offestry 
and its surrounding areas for an even more challenging adventure.  The 
whole world of Shadowgate awaits those who dare venture over the mountain 
to the south.  A land where forces of evil and good are always at odds 
and often in open warfare.  A land where there is no such thing as an 
innocent bystander.  Neutrals find themselves victims and/or forced to 
choose sides in the conflicts to prevent one or the other from forcing 
their beliefs on everyone and the balance being lost forever.  In quieter 
times, the conflict may be limited to skirmishes, kidnappings, scheming, 
and more subtle or political ploys to gain sway, but the conflict is 
certain to be unending.  If you indeed feel ready for this new world, open 
the gate and you can begin your trek up the mountain.
STYX
			);
		} 
		if(!newbiep(TP)) {
			write(
@STYX
%^YELLOW%^* * * * * * * * * * C A U T I O N * * * * * * * * * * * *%^RESET%^
As a non-newbie reading this sign, you are on notice that the area to
the north is the newbie area.  Newbies do have protection from stealing 
and attacks and you are expected to avoid entering into conflict type RP 
situations with them accordingly.  Once they have passed this point
south they will have lost their newbie status.  Non-newbies in the area
are, of course, not afforded protection of any kind.  However, please keep
the RP spirit of the game in mind.  RP is expected, so try to find a way  
to at least interract in some fashion and give true newbies a reasonable 
chance to get oriented or at least RP before being killed and/or looted.
STYX
			);
		}
		tell_room(ETO,TPQCN+" appears to be reading the sign.  You should too!",TP);
		return 1;
	}
	tell_room(TP,"Read what?");
	return 1;
}
