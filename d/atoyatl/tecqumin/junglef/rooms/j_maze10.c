#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  set_monsters(({MOB +"quali"}), ({1})); 
  set_repop(100);
}


void reset(){
  ::reset();
  if (present("quali 2", TO))
  {
    if (!userp(present("quali", TO)) && !userp(present("quali 2", TO)))
    {
      present("quali", TO)->move("/d/shadowgate/void");
    }
  }
}
