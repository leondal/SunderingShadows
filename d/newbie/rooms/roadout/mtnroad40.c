//mtnroad40.c - second gate from Offestry toward Shadow area

#include <std.h>
#include "../../newbie.h"
#define MIN_DESC_LENGTH 180

inherit VAULT;

object ob;
string dest;
string str;

void create(){
  ::create();
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
		({"pine needles", "leaves" }):"%^ORANGE%^The fallen leaves and pine needles are brown and decaying.",
		({"path"}):"%^ORANGE%^The path is comfortably wide and easy to traverse here." 
		]) );
   set_exits(([
       "gate":ROADOUT"mtnroad39",
       "northeast":ROADOUT"mtnroad41",
   ]));
   set_pre_exit_functions( ({"northeast"}), ({"GoThroughDoor"}) );
   set_door("gate",ROADOUT"mtnroad39","gate",0);
  	dest = ROADOUT"mtnroad39";
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
       if (!present("sign on the gate",TO))
            new(ROADOUT"obj/gatesign")->move(TO);
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
The nearest city is that of Shadow and it lies to the east along the
Quiet Forest Road.  Not all are welcome there, but even the most hated 
races may find it possible to survive doing some business there while 
they seek another place to call home.  There is also a city called Juran
that is more suited to naturally evil races.  Once you are sure you are 
ready, go through the gate to begin your wider adventure.  You will be 
able to return if you wish.  However, this is your last warning -
%^BOLD%^Your newbie status and all protection from aggressive acts 
will be completely gone once you go through this gate!\n
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

/* old wording for non-newbies when newbie protection was by rule only
As a non-newbie reading this sign, you are on notice that the area to
the north is the newbie area.  The newbies there are afforded 
protection from all non-newbies, but only to the extent they do not 
provoke a conflict.  If they steal, attack, or otherwise enter a RP 
conflict situation, they have forfeited that protection for the extent 
of that situation.  However, we expect you to use sound judgement as to 
the intent of the rule and not provoke such situations with your actions.  
The journey over the mountain is quite long.  Once they have passed this 
point south they will have lost their newbie status.  However, true
newbies should be given a fair chance to get oriented before being 
killed and looted.
*/
