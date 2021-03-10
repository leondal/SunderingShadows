#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;


void create() 
{
  room::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
  set_light(3);
  set_property("no attack", 1);
  set_indoors(1);
    set_property("no teleport",1);
  set_short("The room of the elven elder");
  set_long(
      "%^GREEN%^You have entered a small underground room hidden away from the "
      "prying eyes of the Drow elves. Upon further inspection you realize this "
      "elven elder is here the hopes that he can aid brave heros who have come "
      "defeat the evil Drow. However, the smuggling of potions to this area and "
      "the cost of keeping it secret forces him to charge gold for his services."
      "%^RESET%^"	 		
  );
  set_smell("default", "Strange aromas fill the air.");
  set_listen("default", "It is silent and peaceful here.");
  set_items( ([ "list" : "The elven elder offers these services: \n"
                         "cl : cure light wounds for 30 gold \n"
                         "cs : cure serious wounds for 75 gold \n"
                         "cc : cure critical wounds for 125 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                         "bs : buy a healing stick for 100 gold \n"
           ]) );
  set_exits( ([
	"out" : "/d/dagger/drow/rooms/shack2"
           ] ));
}


void init() 
{
  ::init();
  add_action("cure_light", "cl");
  add_action("cure_serious", "cs");
  add_action("cure_critical", "cc");
  add_action("neut_poison", "np");
  add_action("buy_potion", "bs");
}


void reset()
{
  ::reset();
    if(!present("elven elder")) 
      new("/d/dagger/drow/mon/elfelder.c")->move(TO);
}


void cure_light(string str) 
{
  if(!TP->query_funds("gold",30))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
  tell_object(TP, "The elven elder applies a balm that heals your wounds.");
  TP->use_funds("gold",  30);
  return 1;
}

void cure_serious(string str) 
{
  if(!TP->query_funds("gold",74))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(2,8)+1);
  tell_object(TP, "The elven elder heals and binds your wounds.");
  TP->use_funds("gold", 75);
  return 1;
}


void cure_critical(string str) 
{
  if(!TP->query_funds("gold",125))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(3,8)+3);
  tell_object(TP, "The elven elder covers your wounds with a pungent salve.");
  TP->use_funds("gold", 125);
  return 1;
}


void neut_poison(string str) 
{
if(!TP->query_funds("gold",150))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_poisoning(-(int)TP->query_poisoning());
  tell_object(TP,"The elven elder administers an antidote that cures your
poisoning.");
  TP->use_funds("gold", 150);
  return 1;
}


void buy_potion(string str) 
{
  if(!TP->query_funds("gold",100))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  new("/d/dagger/drow/temple/obj/hlstick.c")->move(TP);
  tell_object(TP, "The elven elder takes your money and give you a "
	"stick of healing.");
  TP->use_funds("gold", 100);
  return 1;
}
   
 
