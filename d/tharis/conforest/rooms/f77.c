#include <std.h>
#include "../defs.h"
inherit INC+"tharisedge";
//updated min level to enter *Styx*  11/06/04

void create() {
  ::create();
  set_long(TO->query_long()+"\n%^BOLD%^There is a sign here.... READ IT%^RESET%^");
  set("night long", TO->query_long()+"\n%^BOLD%^There is a sign here.... READ IT%^RESET%^");
  set_exits(
    ([
    "east" : ROOMS+"f78",
    "north" : ROOMS+"f74",
    "enter" : "/d/tharis/forest/forest180"
    ]) );
   set_pre_exit_functions( ({"enter"}),({"GoThroughDoor"}) );
}

int __Read_me(string str){
	if(!str || str != "sign")
		return 0;

	tell_room(TO,TPQCN+" reads over the sign. You should too.",TP);
	write(
@OLI
	%^BOLD%^
   %^BOLD%^
   This is meant as a warning.  This area is meant to be extremely difficult.
   Due to abuses, those below level 15 are no longer allowed to enter.
   This area is meant to be difficult and the rewards for higher levels.
   Also this is an area which makes strict use of alignment with
   far-reaching consequences.
OLI
	);
	return 1;
}

void init(){
	::init();
	add_action("__Read_me","read");
}

int GoThroughDoor(){
   if(TP->query_highest_level() < 15) {
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" tried to enter Tharis "
          "forest in spite of the warning sign.");
     write("That forest seems too ominous for someone of your level.\n"
          "Read the sign if you didn't already!");
     return 0;
   }
   return 1;
}
