#include "/d/antioch/areadefs.h"
#include <std.h>
inherit WEAPON;
 
void create() {
  ::create();
  set_name("an elemental wand");
   set_property("no animate",1);
  set_id(({"wand","a wand","elemental wand"}));
  set_short("An elemental wand");
    set_long(
@ANTIOCH
The handle of the wand fits perfectly into the palm of your hand.
The wand seems to have lost its touch, but you can still sense that
it is, or at least was, very powerful.  If you look closely, you 
can see that there is room for something to be <joined> to the
crystal handle of the wand.
It looks very fragile, you should be careful not to drop it.
ANTIOCH
    );
  set_weight(4);
  set_type("bludgeoning");
  set_wc(1,4);
  set_large_wc(1,6);
}

void init() {
  ::init();
  add_action("join_element","join");
}

int drop(){
  if(!interactive(ETO)){
    ::drop();
    return 1;
  }
  tell_object(TP,"%^BOLD%^%^BLUE%^You drop the wand and it shatters!!!");
  tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" drops the wand and it shatters!!!\n",TP);
  destruct(TO);
  return 1;
}

int join_element(string str){
  int count = 0;
  object ob1, ob2, ob3, ob4, ob5, ob6, ob7, ob8, ob9, ob10;

  if(!str){
    notify_fail("Join what?\n");
    return 0;
  }
  if((str!="wand") && (str!="elements")){
    notify_fail("You can't join that!\n");
    return 0;
  }
  else{
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
      if(!(ob1 = present("red element",TP))){
      tell_object(TP,"You do not have the %^RED%^red %^RESET%^element!\n");
      count++;
    }
       if(!(ob2=present("green element",TP))){
      tell_object(TP,"You do not have the %^GREEN%^green %^RESET%^element!\n");
      count++;
    }
      if(!(ob3=present("water element",TP))){
      tell_object(TP,"You do not have the water element!\n");
      count++;
    }
      if(!(ob4=present("blue element",TP))){
      tell_object(TP,"You do not have the %^BLUE%^blue %^RESET%^element!\n");
      count++;
    }
      if(!(ob5=present("crystelic element",TP))){
      tell_object(TP,"You do not have the crystelic element!\n");
      count++;
    }
      if(!(ob6=present("yellow element",TP))){
      tell_object(TP,"You do not have the %^YELLOW%^yellow %^RESET%^element!\n");
      count++;
    }
    if(!(ob7=present("undead element",TP))){
      tell_object(TP,"You do not have the undead element!\n");
      count++;
    }
      if(!(ob8=present("golden element",TP))){
      tell_object(TP,"You do not have the %^YELLOW%^golden %^RESET%^element!\n");
      count++;
    }
      if(!(ob9=present("demonic element",TP))){
      tell_object(TP,"You do not have the %^BOLD%^demonic %^RESET%^element!\n");
      count++;
    }
      if(!(ob10=present("lust element",TP))){
      tell_object(TP,"You do not have the lust element!\n");
      count++;
    }
    if(count == 0){
      tell_object(TP,"%^GREEN%^As you join the elements, you feel a surge of energy run through the wand!\n");
      ob1->remove();
      ob2->remove();
      ob3->remove();
      ob4->remove();
      ob5->remove();
      ob6->remove();
      ob7->remove();
      ob8->remove();
      ob9->remove();
      ob10->remove();
      new(OBJT+"wand2")->move(TP);
      remove();
      return 1;
    }
    else{
      tell_object(TP,"You are missing "+count+" elements, "+TPQCN+"!\n");
        return 1;
    }
  }
}
