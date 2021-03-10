#include <std.h>

int num;
object ob, prev_obj;

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@KAYLA
%^ORANGE%^The path widens here at a bend and just ahead is a peculiar 
structure built atop a small rocky knoll.  The tower widens at 
the top and the walls are encrusted with green moss, giving it a 
passing resemblance to a large mushroom.
KAYLA
    );
    set_exits(([
       "enter" : "/d/deku/open/entrance",
        "west" : "/d/deku/open/forest49",
       "south" : "/d/deku/open/forest48"
    ] ));
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_smell("default","You catch a whiff of something scorched by fire.");
    set_pre_exit_functions(({"enter"}),({"go_enter"}));
    set_items(([
      "tower":"The tower is a beautiful sight, it reaches 40 ft. up into the sky."
    ] ));
  num = 0;

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
