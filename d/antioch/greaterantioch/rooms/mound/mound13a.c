#include <std.h>
#include "../../gantioch.h"

inherit ROOM;
void capt(object targ, int num);

void create(){
  ::create();
  set_name("Being captured!");
  set_long("You struggle with the net around you as your vision fades in and out!");
  set_property("light",-100);
  set_property("indoors",1);
  set_property("no teleport",1);
  set_smell("default","%^RESET%^%^ORANGE%^An unknown stench surrounds you.");
  set_listen("default","%^RESET%^%^RED%^Gnarling and barking can be heard all around you.");
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
  "%^BOLD%^%^%^WHITE%^Your feel the sense of being groped at and pulled around. Your vision comes to and you see gnolls tossing your equipment around to each other. You turn your head slightly and see the %^RESET%^%^RED%^evil %^BOLD%^%^WHITE%^grin of a gnoll, looking at you. Everything goes %^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^."
  );
  break;
  case(1):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^WHITE%^You feel yourself getting tossed to the side and moved dragged by another gnoll. You look around briefly to see your things %^BOLD%^%^RED%^argued %^BOLD%^%^WHITE%^over. You feel a claw grab you and everything goes %^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^."
  );
  break;
  case(2):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^GREEN%^You hear a large %^BOLD%^%^YELLOW%^CLANG %^BOLD%^%^GREEN%^jarring you, as if a door of some sort was shut .... everything %^BOLD%^%^BLACK%^fades%^BOLD%^%^GREEN%^..."
  );
  break;
  case(3):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^BLUE%^You look around groggily and see that you are stuck in a %^BOLD%^%^RED%^cage%^BOLD%^%^BLUE%^. You look around and see others in the cages around you...what is this place?"
  );
  break;
  case(4):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^WHITE%^A male elf in %^BOLD%^%^BLACK%^rags %^BOLD%^%^WHITE%^walks over and begins messing with the lock on your cage. '%^BOLD%^%^YELLOW%^It's time for you to prepare...I hope you are ready for what is coming...'"
  );
  break;
  case(5):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^RED%^You hear the %^BOLD%^%^CYAN%^clink %^BOLD%^%^RED%^as the cage is unlocked. You stumble out of the cage, looking about and realize there are many things strung about on the floor..."
  );
  TP->add_money("gold",-2000000);
  TP->add_money("platinum",-2000000);
  TP->add_money("electrum",-2000000);
  TP->add_money("silver",-2000000);
  TP->add_money("copper",-2000000);
  if(TP->query_invis(1)) TP->set_invis(0);
  TP->move(MOUND"mound13");
 return;
  }
  if(!random(1)){
  ob=present("sack",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("powder",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("chest",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("armor",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("robe",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("sword",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("dagger",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("axe",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("hammer",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("staff",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("bracers",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("pants",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("cloak",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("boots",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("helm",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("coif",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("hat",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("pouch",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("robes",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("glaive",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("ring",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("box",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("shorts",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("bracelets",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("sheath",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("band",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("kit",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("shield",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("strap",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("book",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("amulet",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("gauntlets",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("gloves",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("cape",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("greaves",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("claymore",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("sash",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("band",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("holster",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("sleeve",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("bodice",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("skirt",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("circlet",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("orb",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("kilt",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("spear",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("stockings",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("earring",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("band",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("top",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("powder",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("net",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("cape",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("bow",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("quiver",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("mask",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("rope",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("crown",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("gem",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("coat",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("rapier",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("brooch",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("chain",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("bandana",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("vest",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("torc",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  ob=present("basket",TP);
  if(ob){ob->move(MOUND"treasureroom");}
  //return;
}
  else{}
  num++;
  if(!objectp(targ)) { return; }
  if(!present(targ,TO)) return;
  call_out("capt",10,targ,num);
 return;
}
