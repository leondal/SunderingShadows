#include <std.h>
#include "../derrodefs.h"

inherit ROOM;
void capt(object targ, int num);

void create(){
  ::create();
  set_name("Being captured!");
  set_long("You struggle with your bonds as your vision fades in and out!");
  set_property("light",-100);
  set_property("indoors",1);
  set_property("no teleport",1);
  set_smell("default","The stench of unwashed bodies assails you");
  set_listen("default","You can hear murmuring in the background");
}
void init(){
  ::init();
  call_out("capt",10,TP,0);
}
void capt(object targ, int num)
{
  object ob;

  if(!objectp(TP)) { return; }
  if(!objectp(targ)) { return; }


  switch(num){
  case(0):
  tell_object(targ,
  "\n\n\n"
  "%^RESET%^%^BLUE%^You drift back to consciousness for a second and feel yourself being carried down a long dimly lit corridor.\n"
  "%^BLUE%^   The scene fades back out."
  );
  break;
  case(1):
  tell_object(targ,
  "\n\n\n    "
  "%^RESET%^%^BOLD%^%^BLACK%^The grayness fades again and you find yourself strapped to a table with a few bickering small humanoids arguing over your goods."
  );
  break;
  case(2):
  tell_object(targ,
  "\n\n\n     "
  "%^RESET%^%^RED%^You struggle with your bonds and realize that there is little hope of escape."
  );
  break;
  case(3):
  tell_object(targ,
  "\n\n\n"
  "%^RESET%^%^BLUE%^Things fade out and then back in again and you can hear the voices of the dwarves raised in argument."
  );
  break;
  case(4):
  tell_object(targ,
 "\n\n\n     "
  "%^BOLD%^%^BLACK%^   Three odd looking dwarves are starting to get a little heated in their arguments with much pointing at you and wonder what fate will befall you."
  );
  break;
  case(5):
  tell_object(targ,
   "\n\n\n"
  "%^RED%^ As the two larger dwarves keep arguing the smaller one slides over beside your equipment and eyes it up and the backs of his still arguing friends."
  );
  break;
  case(6):
  tell_object(targ,
  "\n\n\n   "
  "%^RESET%^%^BLUE%^  The evil looking dwarf walks past you and slips a dagger into your hand as he stuffs some stuff in a sack and sneaks out the passage to the north."
  );
  break;
  case(7):
  tell_object(targ,
  "\n\n%^BOLD%^%^WHITE%^ You quickly cut your bonds and gather your remaining equipment to deal with the foul dark dwarves that remain.%^RESET%^"
 );
  TP->add_money("gold",-2000000);
  TP->add_money("platinum",-2000000);
  TP->add_money("electrum",-2000000);
  TP->add_money("silver",-2000000);
  TP->add_money("copper",-2000000);
  new(OBJ"secari.c")->move(TP);
  if(TP->query_invis(1)) TP->set_invis(0);
  TP->move(ROOMS"c21.c");
 return;
  }
  if(!random(4)){
  ob=present("sack",TP);
  if(ob){ob->move(ROOMS"c37.c");}
  ob=present("chest",TP);
  if(ob){ob->move(ROOMS"c37.c");}
  }
  else{}
  num++;
  if(!objectp(targ)) { return; }
  if(!present(targ,TO)) return;
  call_out("capt",10,targ,num);
 return;
}
