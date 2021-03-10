#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void set_rope(int rope);

int rope_present;

void create(){
  ::create();
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_property("light",2);
   set_short("Rocky clearing" );
   set_long(
  	"%^BOLD%^Clearing in the mountains. %^RESET%^\n"+
	"This clearing in the mountains has only a few sparse yards where the "
	"sheer rock face and brush doesn't interfere with travel.\n"
  );
  set_smell("default", "You smell the faint odor of sulfur."  );
  set_listen("default", "You hear a faint bubbling far to the east" );
  set_items(([
  "brush":"Small patches of scrubby vegetation make passage difficult off the path.",
  "mountains":"Foreboding looking mountains overshadow this little clearing.",
  "rock face":"It's a sheer rock face with a huge boulder against it.  Maybe "
    "you could climb up if you had the skill or the tools.",
  "boulder":"There are scrapes near its base and the stone looks worn in front of it.",
  ]));
  set_exits(([
  "south":ROOMS+"a2"
  ]));
     	
     	set_climb_exits((["climb":({"/d/player_houses/isaiah/rooms/iscliff",20,6,100})]));
      set_fall_desc("%^BOLD%^%^GREEN%^You lose your grip and fall down the "+
		"rock face bouncing and cursing all the way!%^RESET%^\n");

}
void init(){
  ::init();
  add_action("pass_wall","pass");
}

int pass_wall(){
  if(member_array("Friend of the Stone",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_unconscious()){
    return 0;
    }
  write("You trust the stone and walk through it.  It regonizes you and allows you to pass through.");
  say(""+TPQCN+ " walks up to the stone face and pauses for a second, then walks through it!",TP);
  TP->move_player(ROOMS"b8.c");
  return 1;
  } else {
  write("You smack your head painfully on the rock!");
  say(""+TPQCN+" attempts to walk through the stone wall but just ends up with a sore nose!",TP);
  return 1;
  }
}
