#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit WATER;
int searched;

void create(){
    ::create();
   set_terrain(DEEP_WATER);
   set_travel(FRESH_BLAZE);
}

void init(){
    ::init();
    if(query_property("search place"))
      add_action("search_fcn", "search");
}

void reset(){
    ::reset();
}

int search_fcn(string str){
    int i;

    if(!str) return 0;
    if(str != "sand") return 0;

    if(searched) return notify_fail("There's nothing else here.\n");

    tell_object(TP, "You find somthing in the sand.");
    for(i = 0;i<random(4)+1;i++){
      (LAKE_D->get_item())->move(TO);
    }
    searched = 1;
}

void add_stuff(){
    string tmp;

    if(!random(5)){
      set_property("search place", 1);
      add_item("sand", "The sand here looks strange.");
      tmp = query_long(0);
      set_long(tmp + "Somthing in the sand catches your eye.");
    }
}
