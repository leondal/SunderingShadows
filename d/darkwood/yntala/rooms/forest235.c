//forest235
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest234"
]));
}
void reset() {
  object ob;
  int r;
  ::reset();
  if(!present("direwolf")){
     new(TMONDIR+"direwolf.c")->move(TO);
  }
  if(!present("chest")){
    r = random(2);
    if(r==0)
      new("/d/hm_quest/chests/chest2")->move(TO);
    else
      new("/d/hm_quest/chests/chest29")->move(TO);
  }
}

//commented this out - as far as I know there is no hint to it existing 
//furthermore the rooms that it leads to have no descriptions/short descriptions, etc. - Saide, May 2017
/*void init(){
  ::init();
  add_action("pull","pull");
}
int pull(string str){
   if(str == "branch down"||str=="down on the branch"){
   tell_object(TP,"%^RESET%^%^GREEN%^You take hold of the branch and are magically transported somewhere else!%^RESET%^");
   tell_room(TO,""+TPQCN+" reaches for a branch and disappears!",TP);
   this_player()->move_player(INRMS+"sec1");
   return 1;
   }
}*/
