#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;
int searched;
void create(){
  
  ::create();
  set_name("Squire's Trial Hidden Room");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  This hidden room appears to be storage for all the tools " +
            "used to build this place.  Picks, wheelbarrows, tools for " +
            "smoothing cut stone and more lie all over.  "
          );
          

  set_search("default","Behind one of the wheelbarrows by the wall is a pile " +
                       "of work clothes."
  );

  set_exits(([
            "out" : SQUIREROOMS+"room14",
  ]));
  searched = 0;
}

void init(){
   ::init();
   add_action("searchit","search");
}

int searchit(string str){
   object found;
   if(!str) return 0;
   if((str == "pile") && (searched == 0)){
     tell_object(TP,"You search through the pile and shake " +
            "some coins out of a glove!");
     tell_room(ETP,TPQCN+" searches through the pile and shakes " +
            "some coins out of a glove!",TP);
     
     found = new("/std/obj/coins");
     found->add_money("gold",random(250) + 250);
     found->add_money("silver",random(200));
     found->move(TO);
     searched = 1;
     return 1;
   }
}

void reset(){
   ::reset();
   searched = 0;
}
