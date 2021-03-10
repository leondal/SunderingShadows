#include <std.h>
#include <objects.h>

inherit VAULT;

void create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    	set_short("Gateway to the Abyss ");
    	set_long(
@KAYLA
This room is somewhat lit, from a neon web that spans across the
cavern.  Rotting bones and bits of flesh are scattered all over
the web. You wonder to yourself, 'What sort of creature could
create a web this size?'  Beyond the web to the east you see 
only darkness.
KAYLA
    	);
    	set_exits(([
       	"up" : "/d/deku/dark/stair2",
       	"east" : "/d/deku/dark/room7"
    	] ));
    	set_pre_exit_functions(({"east"}),({"go_east"}));
    	set_items(([
       	"web" : "The web spans the passage to the east, what could do this.."
    	] ));
    	
	set_trap_functions(({"east"}),({"drop_em"}),({"east"}));
}
int drop_em(string str){
	TP->force_me("emote yelps!\n");
	TP->set_paralyzed(5000,"You are unable to do that!");
	tell_object(TP,"You move east and feel the floor give way beneath you.\n");
	tell_room(TO,""+TPQCN+" pitches forward!",TP);
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,""+TPQCN+"leaves to the east!\n",TP);
		TP->move("/d/deku/dark/room7");
		tell_object(TP,"You avoid stepping onto the fragile covering of a darkpit.\n");
		tell_room(("/d/deku/dark/room7"),""+TPQCN+" stumbles into the room.\n",TP);
	}else{
		tell_room(TO,""+TPQCN+" screams and disappears into the floor to the east!\n",TP);
		TP->move("/d/deku/dark/pit0");
		tell_object(TP,"%^BOLD%^%^RED%^You tumble into a dark pit\n!");
		TP->do_damage("torso",roll_dice(3,10));
		tell_object(TP,"%^BOLD%^%^RED%^You come to a sudden painful stop at the "+
			"bottom of the pit\n!");
		tell_room (("/d/deku/dark/pit0"),"%^BOLD%^%^MAGENTA%^"+TPQCN+" lands with a thud"+
			"!\n",TP);
      	tell_room(("/d/deku/dark/pit0"),""+TPQCN+" %^BOLD%^%^MAGENTA%^groans!\n",TP);
      	tell_object(TP,"%^BOLD%^%^MAGENTA%^You groan in pain from your fall!\n");
	}
	TP->set_paralyzed(0);
	TP->force_me("look");
	return 1;
}
void reset() {
  ::reset();
  if(!present("drider")) {
  new("/d/deku/monster/drider")->move(this_object());
    return 1;
  }
}

int go_east() {
  if(!present("drider")) {
    return 1;
  } else {
    write("The drider with his web is blocking your way.");
    return 0;
  }
}