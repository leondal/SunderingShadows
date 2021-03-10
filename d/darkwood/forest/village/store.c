
#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;


void create() 
{
  room::create();
  set_light(3);
  set_property("no attack", 1);
  set_property("no bump",1);
  set_indoors(1);
  set_short("Mr. Hauder's General Store");
  set_long(
@STORE
%^ORANGE%^Mr. Hauder's General Store%^RESET%^
You have entered Mr. Hauder's General Store. This is the largest 
building in town, and a cursory inspection reveals that it is
probably the sturdiest. A stone veranda hugs the building on
two sides, and rough-hewn chairs are strewn about it. Two or
three older gentlemen are lounging here, trading stories.
Currently Mr. Hauder only carries food supplies for adventurers
and has a list tacked up of what he carries.
STORE
  );
  set_smell("default", "The strong odor of dried meats and fresh fruits fills the air.");
  set_listen("default", "You can hear some of the people trading stories.");
  set_items( ([ 
     "list" : "*************************************\n"
              "*      Mr. Hauder's Food Supply     *\n"
              "*                                   *\n"
              "*    apple   10g      pear   10g    *\n"
              "*    peach   10g      plum   10g    *\n"
              "*    jerky   20g      fish   30g    *\n"
              "*          bag of nuts   20g        *\n"
              "*                                   *\n"
              "*        type buy <food name>       *\n"
              "*************************************\n",
  ]) );
  set_exits( ([
     "out" : "/d/darkwood/forest/village/str6"
  ] ));
}

void init(){
  ::init();
  add_action("buy", "buy");
}

void buy(string str) 
{
  if(str == "apple") {
    if((int)TP->query_money("gold") < 10) {
      tell_object(TP, "You don't have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/apple.c")->move(TP);
    tell_object(TP, "Mr. Hauder takes your gold and gives you an apple.");
    tell_room(environment(TP),TPQCN+" buys an apple.",TP);
    TP->add_money("gold", -10);
    return 1;
  }
  if(str == "pear") { 
    if((int)TP->query_money("gold") < 10) {
      tell_object(TP, "You don't have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/pear.c")->move(TP);
    tell_object(TP, "Mr. Hauder takes your gold and gives you a pear.");
    tell_room(environment(TP),TPQCN+" buys a pear.",TP);
    TP->add_money("gold", -10);
    return 1;
  } 
  if(str == "peach") {
    if((int)TP->query_money("gold") < 10) {
      tell_object(TP, "You don't have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/peach.c")->move(TP);
    tell_object(TP, "Mr. Hauder takes your gold and gives you a peach.");
    tell_room(environment(TP),TPQCN+" buys a peach.",TP);
    TP->add_money("gold", -10);
    return 1;
  }
  if(str == "plum") {
    if((int)TP->query_money("gold") < 10){
      tell_object(TP, "You don't have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/plum.c")->move(TP);
    tell_object(TP,"Mr. Hauder takes your gold and gives you a plum.");
    tell_room(environment(TP),TPQCN+" buys a plum.",TP);
    TP->add_money("gold", -10);
    return 1;
  } 
  if(str == "jerky") {
    if((int)TP->query_money("gold") < 20){
      tell_object(TP, "You don't have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/jerky.c")->move(TP);
    tell_object(TP, "Mr. Hauder takes your gold and gives you some jerky.");
    tell_room(environment(TP),TPQCN+" buys some jerky.");
    TP->add_money("gold", -20);
    return 1;
  }
  if(str == "nuts"){
    if((int)TP->query_money("gold") < 20){
      tell_object(TP,"You don't have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/nuts.c")->move(TP);
    tell_object(TP,"Mr. Hauder takes your gold and gives you a bag of nuts.");
    tell_room(environment(TP),TPQCN+" buys a bag of nuts.");
    TP->add_money("gold", -20);
    return 1;
  } 
  if(str == "fish") {
    if((int)TP->query_money("gold") < 30){
      tell_object(TP,"You dont have enough money!");
      return 1;
    }
    new("/d/darkwood/obj/fish.c")->move(TP);
    tell_object(TP,"Mr. Hauder takes your gold and gives you some dried fish.");
    tell_room(environment(TP),TPQCN+" buys some dried fish.",TP);
    TP->add_money("gold", -30);
    return 1;
  }
}







