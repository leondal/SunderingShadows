#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit WATER;

void create(){
    ::create();
   set_terrain(DEEP_WATER);
   set_travel(FRESH_BLAZE);
}

void init(){
    ::init();
}

void reset(){
    int i;
    ::reset();

    if(random(3)) return;

    switch(random(4)){
    case 0:
      switch(random(7)){
      case 0:
        new(MPATH "gcrayfish")->move(TO);
        break;
      case 1:
        new(MPATH "ixi")->move(TO);
        break;
      case 2:
        new(MPATH "storm")->move(TO);
        break;
      case 3:
        new(MPATH "merman")->move(TO);
        break;
      case 4:
        new(MPATH "waternaga")->move(TO);
        break;
      default:
        new(MPATH "mermaid")->move(TO);
        break;
      }

    default:
      for(i = 0; i<random(4)+1;i++){
        new(MPATH "fish")->move(TO);
      }
      break;
    }
}
