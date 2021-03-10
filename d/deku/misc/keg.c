#include "std.h"
inherit DRINK;

int dosage, heal;
string liquid;

void create() 
{
  ::create();
  set_name("keg");
  set_id(({"keg", "keg of alcohol"}));
  set_short("Keg of Alcohol");
  set_long("This is a keg of alcohol, from the town of Verbobone.\n"+
           "To drink from the keg type %^RED%^tap keg%^RESET%^.");
  set_weight(30);
  set("coin_type","gold");
  set_value("100");
  set_strength(25);
  set_type("alcoholic");
  dosage = 10;
}

void init() 
{
  ::init();
  add_action("tap","tap");
}

int tap(string str) 
{
  int max,hp,heal;

  max = this_player()->query_formula();

  if(!str) 
   {
     write("Usage <%^RED%^tap keg%^RESET%^>");
     return 1;
   }
  if(str != "keg") 
   {
     write("You can't do that.");
     return 1;
   } 
  if(!dosage) 
   {
     write("The keg is empty!\n");
    say(this_player()->query_cap_name()+" tries to drink from an empty keg!");
     return 1;
   }
  if(this_player()->query_intox() > max )
   {
     write("You can't reach the keg to your mouth.");
    say(TPQCN+" can't reach a keg to "+TP->query_possessive()+" mouth.");
     return 1;
   }
  write("You tap from the keg.");
  say(this_player()->query_cap_name()+" taps from a keg of alcohol.");
  dosage -= 1;
  call_out("empty_keg", 1);
  this_player()->add_intox( max / 11);
  hp = (int)this_player()->query_max_hp()-(int)this_player()->query_hp();
  heal = max / 11;
  if( hp > heal )
    this_player()->add_hp(heal);
    else
      this_player()->add_hp(hp);
  if(!dosage) 
   {
     notify_fail("%^RED%^The keg is now empty!%^RESET%^\n");
     return 1;
   }
  return 1;
}

void empty_keg() 
{
  if(dosage == 10) 
   {
     set_short("%^GREEN%^Keg of alcohol <%^RED%^Full%^GREEN%^>");
     set_value(100);
     return 1;
   }
  if(dosage > 5) 
   {
     set_short("%^GREEN%^Keg of alcohol <%^RED%^Almost full%^GREEN%^>");
     set_value(75);
     return 1;
   }
  if(dosage == 5) 
   {
     set_short("%^GREEN%^Keg of alcohol <%^RED%^Half full%^GREEN%^>");
     set_value(50);
     return 1;
   }
  if(dosage > 0) 
   {
     set_short("%^GREEN%^Keg of alcohol <%^RED%^Almost empty%^GREEN%^>");
     set_value(25);
     return 1;
   }
  if(dosage == 0)
   {
     set_short("%^GREEN%^Keg of alcohol <%^RED%^Empty%^RESET%^%^GREEN%^>");
     set_value(5);
     return 1;
   }
  return 1;
}
