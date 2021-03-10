#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;
int num;
object ob, prev_obj;

void create() {
    ::create();
    set_short("%^RED%^A tower in the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A peculiar "+
    "tower stands here, hidden deep in this dead wilderness.  "+
    "The tower mushrooms out near the top and the walls are "+
    "encrusted with a thick and sickly green moss.  A "+
    "%^YELLOW%^dirt trail%^BOLD%^%^BLACK%^ here leads south through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"28-8",
       "east" : F_ROOMS"26-8",
       "north" : F_ROOMS"27-9",
       "south" : F_ROOMS"27-7",
       "southeast" : F_ROOMS"26-7",
       "southwest" : F_ROOMS"28-7",
       "northeast" : F_ROOMS"26-9",
       "northwest" : F_ROOMS"28-9",
       "enter" : "/d/deku/open/entrance",
    ] ));
}

void reset() {
  ::reset();
  if(!present("giant fire elemental")) {
    new("/d/deku/monster/fire-elemgd")->move(TO);
  }
  num = 0;
}


int go_enter() {
	if(prev_obj != TP) {      // Code
		num = 0;                // added by 
		prev_obj = TP;          // Thorn -- 950709
	}
  if(!interactive(TP) || avatarp(TP)) return 1;
//  if(TP->query_invis()) return 1;
  if((present("giant fire elemental")) && (num == 0)) {
    tell_room(ETP,"%^MAGENTA%^The elemental says: %^RESET%^What is your purpose here "+TP->query_race()+" and why are you trying to enter the tower?");
    num = 1;
    return 0;
  }
  if((present("giant fire elemental")) && (num == 1)) {
    tell_room(ETP,"%^MAGENTA%^Elemental roars: %^RESET%^NO ONE MAY ENTER UNLESS YOU TELL ME YOUR PURPOSE HERE!!!!");
    tell_room(ETP,"    %^BOLD%^%^RED%^THIS IS YOUR FINAL WARNING, NEXT TIME I WILL BURN YOU!!!");
    num = 2;
    return 0;
  }
  if((present("giant fire elemental")) && (num == 2)) {
	tell_room(ETP,"%^MAGENTA%^The elemental roars: %^RED%^I'M NOT GIVING ANY MORE WARNINGS, YOU MUST DIE!!!");
	if(ob=present("giant fire elemental",TO))
	ob->kill_ob(TP,1);
	num = 0;
	return 0;
  }
  write("You open the doors to the tower, and enter.");
  say(TPQCN+" enters the tower.");
  num = 0;
  return 1;
}
