//Coded by Lujke

#include <std.h>
#include "../tecqumin.h"
inherit ARMOUR;

object bolas;
object hobble;
int worn_time;

void create() {
    ::create();
   set_name("bolas");
   set_id(({ "bolas","weapon", "thong", "hunter's bolas", "thong", "thongs",
             "weighted thong"}));
   set_obvious_short("three weights connected by leather thongs");
   set_short("hunter's bolas");
   set_long("Two heavy obsidian weights are connected by a thong,"
           +" apparently made of some kind of dinosaur hide. A second"
           +" thong is attached to the centre of the first, and one more"
           +" obsidian weight is attached to the end of it.");
   set_weight(5);
   set_type("ring");
   set_limbs(({"left leg", "right leg"}));
   set_ac(1);
   set_property("enchantment",-1);
   set_value(0);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_size(2);
}

void init(){
  ::init();
}

void set_hobble(object ob){
  hobble = ob;
}

object query_hobble(){
  return hobble;
}

void set_bolas(object ob){
  bolas = ob;
}

dest_effect(){
  if (objectp(ETO)){
    if (!objectp(bolas)){
      bolas = new(OBJ + "bolas.c");
    }
    if (objectp(bolas) && objectp(EETO)){
      bolas->move(EETO);
    }
    tell_object(ETO, "The bolas finally unwraps from your legs and drops to"
                    +" the floor");
    if (objectp(hobble)){
      hobble->remove();
    }
  }
  remove();
}

int wear_func(){
  if (!objectp(TP)){
    return 0;
  }
  set_size((int)TP->query_size());
  tell_object(TP, "The " + query_short() + " %^RESET%^wraps itself"
                     +" round your legs. Running anywhere is going to be a"
                     +" bit hard for a while unless you can untie yourself"
                     +".");
  call_out("dest_effect", 60);
  return 1;
}

void remove_func2(object ob){
  ob->remove_paralyzed();
  dest_effect();
}

int remove_func(string str){
  if (!objectp(TP)){
    return 0;
  }
  if (!id(str)){
    return 0;
  }
  call_out("remove_func2", 5, TP);
  TP->set_paralyzed(20, "You are busy removing the " + query_short());
  return 1;
}


