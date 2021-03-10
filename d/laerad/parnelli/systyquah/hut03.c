//Stolen from Shadow by Bane ;)//
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>

inherit HEALER;
void create(){
    ::create();
  set_light(3);
   set_property("training",1);
  set_indoors(1);
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_short("Systyquah's healing hut");
  set_long(
	"%^BOLD%^Systyquah's healing hut%^RESET%^
You have walked into Systyquah's healing hut.  The odors of various "+
	"salves and healing potions are quite strong.  The walls of the hut "+
	"are lined with numerous herbs and anti-toxins.  A desk lies to "+
	"the west of the room, on it lies a list of prices for the healing "+
	"services."
    );
  set_smell("default", "The strong odor of herbs and balms turns your "
                       "stomach.");
  set_listen("default","You can hear the screaming of the current patients of the shaman healer.");
  set_items( ([
	"list":"The prices for the healing services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
  set_exits( ([
	"west":"/d/laerad/parnelli/systyquah/sys029"
           ] ));
   set_name("Zargoth");
}


void reset()
{
  ::reset();
    if(!present("shaman")){
	new("/d/laerad/mon/trshaman")->move(this_object());
    }
}
/*
void cure_light(string str) 
{
    if(!present("shaman")){
	write("The healer isnt here!");
	return 1;
  }
  if(!TP->query_funds("gold",20))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
  tell_object(TP,"The Shaman applies a balm that heals your wounds.");
  TP->use_funds("gold", 20);
  return 1;
}
void cure_serious(string str) 
{
    if(!present("shaman")){
	write("The healer isn't here!");
	return 1;
  }
  if(!TP->query_funds("gold",45))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(2,8)+1);
  tell_object(TP,"The Shaman heals and binds your wounds.");
  TP->use_funds("gold", 45);
  return 1;
}
void cure_critical(string str) 
{
    if(!present("shaman")){
	write("The healer isn't here!");
	return 1;
  }
  if(!TP->query_funds("gold",100))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(3,8)+3);
  tell_object(TP,"The Shaman covers your wounds with a pungent salve.");
  TP->use_funds("gold", 100);
  return 1;
}
void neut_poison(string str) 
{
  if(!present("shaman")){
	write("The healer isn't here!");
	return 1;
  }
  if(!TP->query_funds("gold",150))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_poisoning(-(int)TP->query_poisoning());
  tell_object(TP,"The Shaman administers an antidote that cures your poisoning.");
  TP->use_funds("gold", 150);
  return 1;
}
void buy_potion(string str) 
{
object ob;
  int num;
  if(!present("shaman")){
	write("The healer isn't here!");
	return 1;
  }
   if(!str) return notify_fail("bp <amount>\n");
    if(sscanf(str,"%d",num) != 1)
     return notify_fail("bp <amount>\n");
  if(!TP->query_funds("gold",30*num))
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
TP->set_paralyzed(1);
  ob = new("/realms/tristan/healing.c");
   ob->set_uses(num);
  if((string)ob->move(TP) == MOVE_OK){
  tell_object(TP,"The Shaman takes your money and gives you a healing potion.");
      TP->use_funds("gold",30*num);
  return 1;
}
write("You can't carry any more!");
return 1;
}
*/
