//  Made READABLE By FireDragon

#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;


void create() 
{
  room::create();
  set_light(3);
  set_property("no attack", 1);
  set_indoors(1);
set_short("Jehan's House of Healing");
set_long("You have entered Jehan's House of Healing. The odours of various"
           "salves and poultices assault your nose as soon as you enter. "
           "Though the shop seems a bit disorganized, it is extraordinarily "
	"clean.  Many patients lie on cots, as Jehand rushes to tend to"
           "them all. A list is tacked on the wall.");
  set_smell("default", "The strong odor of herbs and balms turns your "
                       "stomach.");
set_listen("default", "You hear occasional moans and growns from Jehan's"
                        "patients.");
set_items( ([ "list" : "Jehan offers these services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
  set_exits( ([
"east" : "/d/dagger/Elvanta/forest/room119"
           ] ));
}


void init() 
{
  ::init();
  add_action("cure_light", "cl");
  add_action("cure_serious", "cs");
  add_action("cure_critical", "cc");
  add_action("neut_poison", "np");
  add_action("buy_potion", "bp");
}


void reset()
{
  ::reset();
if(!present("jehan"))
new("/d/dagger/Elvanta/forest/mon/jehan.c")->move(TO);
}


void cure_light(string str) 
{
  if((int)TP->query_money("gold") < 20) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
tell_object(TP, "Jehan applies a balm that heals your wounds.");
  TP->add_money("gold", -20);
  return 1;
}

void cure_serious(string str) 
{
  if((int)TP->query_money("gold") < 45) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(2,8)+1);
tell_object(TP, "Jehan heals and binds your wounds.");
  TP->add_money("gold", -45);
  return 1;
}


void cure_critical(string str) 
{
  if((int)TP->query_money("gold") < 100) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(3,8)+3);
tell_object(TP, "Jehan covers your wounds with a pungent salve.");
  TP->add_money("gold", -100);
  return 1;
}


void neut_poison(string str) 
{
  if((int)TP->query_money("gold") < 150) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_poisoning(-(int)TP->query_poisoning());
tell_object(TP,"Jehan administers an antidote that cures your poisoning.");
  TP->add_money("gold", -150);
  return 1;
}


void buy_potion(string str) 
{
  if((int)TP->query_money("gold") < 30)
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  new("/realms/tristan/healing.c")->move(TP);
tell_object(TP, "Jehan takes your money and gives you a healing potion.");
   TP->add_money("gold", -30);
  return 1;
}
