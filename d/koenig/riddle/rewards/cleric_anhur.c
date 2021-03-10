//cleric_anhur.c - Cleric reward for Riddle Quest. ~Circe~ 5/23/08
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
	set_name("shield of the righteous storm");
	set_id(({ "shield", "anhur shield","hawk shield","shield of the righteous storm"}));
   set_obvious_short("A blue badge shield");
   set_short("%^BOLD%^%^BLUE%^Shield of the %^RED%^R%^YELLOW%^i"+
      "%^BLUE%^g%^RED%^h%^YELLOW%^t%^BLUE%^e%^RED%^o%^YELLOW%^u"+
      "%^BLUE%^s %^RED%^S%^YELLOW%^t%^BLUE%^o%^RED%^r%^YELLOW%^m%^RESET%^");
   set_long("This badge shield is lacquered %^BOLD%^%^BLUE%^stormy "+
      "blue %^RESET%^and decorated with a raised symbol of a %^BOLD%^"+
      "%^RED%^warhawk %^RESET%^clutching %^YELLOW%^lightning bolts "+
      "%^RESET%^in its %^BOLD%^%^BLACK%^talons%^RESET%^.  Its "+
      "%^YELLOW%^eyes %^RESET%^seem to follow onlookers as though "+
      "it is poised to strike at any moment.  Something about the "+
      "carving is incredibly lifelike, and the shield itself seems "+
      "lighter than its size and thickness would suggest.  Padded "+
      "shield straps are affixed to the back so that the shield "+
      "may be worn comfortably.");
   set_lore("This shield is a relic of the faith of Anhur.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^%^BLUE%^You feel a longing to return to "+
      "battle once more as you put the shield aside.%^RESET%^");
}

int strike_func(int damage, object what, object who){
   if(random(1000) < 250){
      tell_room(environment(query_worn()),"%^YELLOW%^The %^RED%^"+
         "warhawk %^YELLOW%^on "+ETOQCN+"'s shield springs to life, "+
         "clawing at "+who->QCN+"!%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^YELLOW%^The %^RED%^warhawk %^YELLOW%^on "+
         "your shield springs to life, clawing at "+who->QCN+"!%^RESET%^");
      tell_object(who,"%^YELLOW%^The %^RED%^warhawk %^YELLOW%^"+
         "on "+ETOQCN+"'s shield springs to life, clawing at "+
         "you!%^RESET%^");
      who->do_damage("torso",(random(8)+1));
   }
}