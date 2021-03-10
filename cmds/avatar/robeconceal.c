// Robe of Concealment
// Thorn@ShadowGate
// 000922
// Dark Empire Campaign
// robeconceal.c

#include <std.h>

inherit ARMOUR;

string enter, exit, say, sdesc, title, desc, race;

void create() {
  ::create();
  set_name("robe");
  set_id( ({"robe","conceal","robe of concealment"}) );
  set("short","a robe");
  set_long(
@KINNESARUDA
%^BLACK%^BOLD%^This is a jet black robe made of a material that you can't even begin to
identify.  It is very large and it seems to bend light, air and even
reality around it.  This object needs no investigation to show that it
is an item of potent magic upon close inspection.%^RESET%^
KINNESARUDA
  );
  set_weight(4);
  set_type("clothing");
  set_limbs( ({"torso"}) );
  set_ac(1);
  set_property("enchantment",5);
  set_value(300+random(2)*300);
  set_wear( (: TO,"wear_func" :) );
  set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
  object *inven;
  int i;
  
  title = TP->query_disguise();
  enter = TP->query_env("MIN");
  exit = TP->query_env("MOUT");
  say = TP->query("say string");
  sdesc = TP->query("describe string");
  desc = TP->query_description();
  
  inven = all_inventory(ETO);
  for(i=0;i<sizeof(inven);i++) {
    if(inven[i] != TO) inven[i]->set_hidden((int)inven[i]->query_hidden() + 1);
  }
  write("%^BOLD%^BLACK%^You draw the robe around yourself and pull the hood over your head!");
  tell_room(ETP, "%^BOLD%^BLACK%^"+TP->query_cap_name()+
    " pulls on the robe and suddenly looks very different!", ({ TP }));
  TP->set("say string", "say");
  TP->set("describe string", "in a silky tone");
  TP->set_disguise("A shrouded "+TP->query_race());
  TP->setenv("MIN", "A shrouded figure enters the area.");
  TP->setenv("MOUT", "You see a shrouded figure leave toward the $D.");
  TP->set_description("is completely shrouded in a dark robe that covers every inch of"+
    TP->query_possessive()+" body.  You can see nothing else about this person and even"+
    TP->query_possessive()+"their face is disguised beneath the voluminous hood of the robe."
  );
  return 1;
}

int remove_func() {
  object *inven;
  int i;
  
  inven = all_inventory(ETO);
  for(i=0;i<sizeof(inven);i++) {
    if(inven[i] != TO) inven[i]->set_hidden((int)inven[i]->query_hidden() - 1);
  }
  TP->set("say string", say);
  TP->set("describe string", sdesc);
  TP->set_disguise(title);
  TP->setenv("MIN", enter);
  TP->setenv("MOUT", exit);
  TP->set_description(desc);
  write("%^BOLD%^BLACK%^You pull off the robe and reveal yourself as who you are!");
  tell_room(ETP, "%^BOLD%^BLACK%^"+TP->query_cap_name()+
    " pulls on the robe and suddenly looks very different!", ({ TP }));
  return 1;
}
