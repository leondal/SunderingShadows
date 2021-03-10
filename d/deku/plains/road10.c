#include <std.h>
inherit "/d/deku/plains/road08i";

void create(){
    ::create();
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_property("no steal",1);
    set_property("no attack",1);
    set_exits(([
        "north" : "/d/deku/plains/road11i",
        "south" : "/d/deku/plains/road09"
   	]));
}

void reset() {
  ::reset();
  if(!present("ranger")) {
   new("/d/deku/monster/ranger.c")->move(TO);
  }
}
int go_north() {
   if(TP->query_level() < 15 && present("ranger")){
   tell_object(TP,"%^MAGENTA%^The Ranger says: %^RESET%^BEWARE little one, the dangers ahead are great. I cannot allow you to pass with good conscious.\n");
   tell_room(ETP,"%^MAGENTA%^The Ranger says:%^RESET%^ The former town of Sanctuary is extremely dangerous to those who can barely handle the drow that poison this island, I cannot allow "+TPQCN+" to pass with good conscious!");
return 0;
  }
   if(TP->query_level() > 149) return 1;
   if(present("ranger")){
   tell_room(ETP,"%^MAGENTA%^The Ranger says:%^RESET%^ Be warned "+TP->query_race()+" for you are not immortal, you cannot escape death without a large group to defeat the evils within.  The dangers ahead are much greater than anything else you've seen on this island!");
   return 1;
   }
   return 1;
}
