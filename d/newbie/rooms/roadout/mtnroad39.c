/*mtnroad39.c - second gate from Offestry toward Shadow area.  Minor change made by Circe - removed query_long at the bottom because it was causing the items not not be viewable.  Post exit function added to previous room to produce the same effect. 10/23/03*/

#include <std.h>
#include "../../newbie.h"
#include <daemons.h>
#include <security.h>

#define MIN_DESC_LENGTH 180

inherit VAULT;
//inherit DAEMON;

object ob;
string dest;
string str;

void create(){
  ::create();
  set_terrain(OLD_MOUNTS);
  set_travel(FOOT_PATH);
  set_property("light",3);
  // set_property("no teleport",1);
  set_short("%^CYAN%^Gate in the mountain%^RESET%^");
  set_long(
@STYX
%^CYAN%^Gate in the mountain%^RESET%^
This winding path along the southern mountainside seems to travel
generally east/west.  You can get glimpses of a pass to the west that
might allow passage through the mountains to the north.  It appears to
have been made by animals and widened out by human travels.  A variety
of trees grow densely here, including several varieties of pines that
provide year-round shade.  Damp fallen leaves and pine needles blanket
the rich soil to cushion your steps.  The path wanders around boulders
and through the undergrowth.
STYX
	   );
  set_smell("default","You smell the musty damp leaves and rich soil.");
  set_listen("default","You hear the wind whistling through the trees.");
  set_items( ([ 
		({"trees","pine trees"}):"%^CYAN%^The pine trees are tall and sway in the wind as they compete with the deciduous trees for sunlight.", 
		({"pine needles" }):"%^ORANGE%^The fallen leaves and pine needles are brown and decaying.",
		({ "leaves" }) : "%^BOLD%^There seems to be a piece of paper or cloth partially buried in the leaves here.",		
		({"path"}):"%^ORANGE%^The path is comfortably wide and easy to traverse here." 
		]) );
	set_exits(([
		"north":ROADOUT"mtnroad38",
		"gate":ROADOUT"mtnroad40",
	]));
	set_pre_exit_functions(({"gate", "north"}), ({"GoThroughDoor","GoThroughDoor"}));
	set_post_exit_functions( ({ "gate" }), ({ "promote_newbies" }));
	set_door("gate",ROADOUT"mtnroad40","gate",0);	    
	dest = ROADOUT"mtnroad40";
	set_door_description("gate", 
@STYX
This heavy gate is made of ornate wrought iron.  It doesn't appear
locked but it blocks the path entirely.  %^BOLD%^A large sign hangs on
the gate that you should certainly read.
STYX

// Garrett put this here so the unbalanced ' wouldn't mess his editor up.
		       );
  set_open("gate",0);
  find_object_or_load(dest)->set_open("gate");
}

void init(){
	::init();
	add_action("read_sign", "read");
	add_action("search_leaves", "search");
       if (!present("sign on the gate",TO))
            new(ROADOUT"obj/gatesign")->move(TO);
}

int search_leaves(string str) {
	if(str == "leaves") {	
		if(newbiep(TP)) {
			write("You found something that looks like a map!");
			new("/d/shadow/obj/misc/map.c")->move(TP);
			return 1;
		}
	write("It turns out to be just a half-rotted dirty scrap of paper.");
	return 1;
	}
	write("Maybe you should search leaves.\n");
	return 1;
}

int GoThroughDoor(){
  string their_describe;
  if (query_verb() != "gate") {
    if (query_open("gate")) {
      tell_object(TP,"The gate swings shut behind you as you move on.");
      tell_room(TO,"The gate swings shut just as "+TPQCN+" moves on.", TP);
      set_open("gate", 0);
      dest->set_open("gate", 0);
      tell_room(dest, "The gate swings shut with a clang as footsteps fade into the distance.");
    }
  return 1;
  } else {
    their_describe = TP->query_description();
    if( !stringp(their_describe) || strlen(their_describe) < MIN_DESC_LENGTH ) {
      write("Your description is either blank or too short.\n"+
	    "Please create one or add to it in order to be able to proceed"+
	    " out of the newbie area.  Note that a wiz or avatar may still"+
	    " review it and suggest or require changes.\n"
	    "%^BOLD%^Please read <help describe> if you haven't yet.");
      return 0;
    }
    return ::GoThroughDoor();
  }
}

int read_sign(string str){   
  if(str == "sign" || str == "gate") {
    if(newbiep(TP) || avatarp(TP)) {
      write(
@STYX
%^YELLOW%^* * * * * * A R E   Y O U   R E A D Y ?? * * * * * * *%^RESET%^
You have reached the final gateway to leaving your life as a newbie.  
The nearest city is that of Tabor and it lies to the south along the
Quiet Forest Road.  Not all are welcome there, so the more hated races
should seek another place to call home.  A cavern dwelling called 
Muul'daan is northeast of the road junction.  Once you are sure you are
ready, go through the gate to begin your adventure.  You will be able to
return if you wish.  However, this is your last warning -
%^BOLD%^Your newbie status and all protection from aggressive acts by 
non-newbies will be completely gone once you go through this gate!\n
%^GREEN%^Once you step forth, may your name become one that is remembered, 
either feared or revered for your deeds!\n
STYX
	    );
    } if(!newbiep(TP)) {
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
    if(!avatarp(TP))
      tell_room(TO,TPQCN+" appears to be reading the sign",TP);
    return 1;
  }
  tell_room(TP,"Read what?");
  return 1;
}

void promote_newbies(string str) {
  if(newbiep(TP)) {
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" Left newbiehood through the gate.");
    write("You have now been advanced out of newbie status.  Good luck!");
    seteuid(UID_ADVANCE);
    TP->set_position("player");
    seteuid(UID_LOG);
    log_file("newbie", TP->query_name()+" left newbie status via Newbietown's Second Gate at "+ctime(time())+".\n");
    seteuid(getuid());
    TP->update_channels();
    return;
  }
  return;
}
/*
string query_long(string str) {
    str = ::query_long();
    if(newbiep(TP))
    str = str+"%^BOLD%^You catch a glimpse of cloth or paper in the leaves next to the gate.";
    return str;
}
This was causing the room to return the long description whenever anyone looked at anything.  Taken out by Circe 10/23/03
*/
