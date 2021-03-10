#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Telima's Home");
  set("day long",
@HOUSE
%^BOLD%^%^YELLOW%^Telima's Home%^RESET%^
This home is large yet simple in design and cozy. It is the
only home here in the village with a large wooden porch. It
has 5 rooms: 4 bedrooms and a large social room with kitchen.
Telima takes great pride in the simplicity of her home and its
comforts. Telima can cure most any ill and heal most wounds.
For a price she will even sell you some of her potions. A sign
hangs near the door.
HOUSE
  );
  set("night long",
@HOUSE
%^BOLD%^%^YELLOW%^Telima's Home%^RESET%^
Torches light the porch outside while inside a fire crackles
welcomingly in the fireplace. This home is large yet simple in
design and cozy. It has 5 rooms: 4 bedrooms and a large social
room with kitchen. Telima takes great pride in the simplicity
of her home and its comforts. Telima can cure most any ill and
heal most wounds. For a price she will even sell you some of her
potions. A sign hangs near the door.
HOUSE
  );
  set_smell("default","The smells here remind you of home.");
  set_listen("default","A fire blazes welcomingly in the fireplace.");
  set_items( ([
     "sign"  : "***********************************\n"
               "*          Price List             *\n"
               "*                                 *\n"
               "*  cl - cure light%^BOLD%^%^YELLOW%^       20 gold%^RESET%^  *\n"
               "*  cs - cure serious%^BOLD%^%^YELLOW%^     45 gold%^RESET%^  *\n"
               "*  cc - cure critical%^BOLD%^%^YELLOW%^   100 gold%^RESET%^  *\n"
               "*  cp - cure poison%^BOLD%^%^YELLOW%^     150 gold%^RESET%^  *\n"
               "*  bp - healing potion%^BOLD%^%^YELLOW%^   30 gold%^RESET%^  *\n"
               "*                                 *\n"
               "***********************************\n",
     "porch" : "The wooden porch it sturdy indeed and wraps around the entire house.",
     "rooms" : "The rooms are small but definatly comfortable for at least two people at a time.",
     "room" : "This room is large and has overstuffed furniture scattered throughout, centered in front of the fireplace. Like all the homes the kitchen is in the far corner.",
     "kitchen" : "The kitchen is set up so that everything is within easy reach and quickly accessable."
  ]) );
  set_exits( ([
     "out"    : "/d/darkwood/forest/village/str3",
     "east" : "/d/darkwood/forest/village/telparlor"
  ]) );
}

void init(){
  ::init();
  add_action("cure_light","cl");
  add_action("cure_serious","cs");
  add_action("cure_critical","cc");
  add_action("cure_poison","cp");
  add_action("buy_potion","bp");
}

void cure_light(string str){
  if((int)TP->query_money("gold") < 20){
    tell_object(TP,"%^MAGENTA%^Telima says: %^RESET%^I'm sorry, but you don't have enough money for that.");
    return 1;
  }
  TP->add_hp(random(8));
  tell_object(TP,"Telima applies a dressing that heals your wounds.");
  tell_room(environment(TP),"Telima applies a dressing to "+TPQCN+"'s wounds.",TP);
  TP->add_money("gold",-20);
  return 1;
}

void cure_serious(string str){
  if((int)TP->query_money("gold") < 45){
    tell_object(TP,"%^MAGENTA%^Telima says: %^RESET%^I'm sorry, but you don't have enough money for that.");
    return 1;
  }
  TP->add_hp(roll_dice(2,8)+1);
  tell_object(TP,"Telima binds and dresses your wounds.");
  tell_room(environment(TP),"Telima binds and dresses "+TPQCN+"'s wounds.",TP);
  TP->add_money("gold",-45);
  return 1;
}

void cure_critical(string str){
  if((int)TP->query_money("gold") < 100){
    tell_object(TP,"%^MAGENTA%^Telima says: %^RESET%^I'm sorry, but you don't have enough money for that.");
    return 1;
  }
  TP->add_hp(roll_dice(3,8)+3);
  tell_object(TP,"Telima binds and dresses your wounds.");
  tell_room(environment(TP),"Telima binds and dresses "+TPQCN+"'s wounds.",TP);
  TP->add_money("gold",-100);
  return 1;
}

void cure_poison(string str){
  if((int)TP->query_money("gold") < 150){
    tell_object(TP,"%^MAGENTA%^Telima says: %^RESET%^I'm sorry, but you don't have enough money for that.");
    return 1;
  }
  TP->add_poisoning(-(int)TP->query_poisoning());
  tell_object(TP,"Telima removes the harmful poison from your body.");
  tell_room(environment(TP),"Telima cures "+TPQCN+" of poison.",TP);
  TP->add_money("gold",-150);
  return 1;
}

void buy_potion(string str){
  if((int)TP->query_money("gold") < 30){
    tell_object(TP,"%^MAGENTA%^Telima says: %^RESET%^I'm sorry, but you don't have enough money for a potion.");
    return 1;
  }
  new("/realms/tristan/healing.c")->move(TP);
  tell_object(TP,"Telima takes your gold and gives you a bottle of potion.");
  tell_room(environment(TP),"Telima gives "+TPQCN+" a bottle of potion.",TP);
  TP->add_money("gold",-30);
  return 1;
}


