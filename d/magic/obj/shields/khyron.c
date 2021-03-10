//Kyron shield
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create(){
   ::create();
   set_name("%^RESET%^%^RED%^M%^ORANGE%^i%^RED%^g%^BOLD%^h%^RESET%^%^RED%^t of the %^BOLD%^Ra%^RESET%^%^RED%^v%^BOLD%^a%^YELLOW%^g%^RED%^er%^RESET%^");
   set_short("%^RESET%^%^RED%^f%^BOLD%^l%^YELLOW%^a%^WHITE%^m%^YELLOW%^i%^RED%^n%^RESET%^%^RED%^g %^RESET%^%^ORANGE%^dri%^RED%^f%^ORANGE%^two%^RED%^o%^ORANGE%^d %^RED%^shield%^RESET%^");
   set_id(({"shield","driftwood shield","flaming shield","flaming driftwood shield"}));
   set_long("%^RESET%^%^ORANGE%^By all laws of %^GREEN%^nature %^ORANGE%^and %^CYAN%^logic%^ORANGE%^, this shield should offer no protection, but it is somehow sturdier than even the finest steel. This hunk of %^YELLOW%^driftwood %^RESET%^%^ORANGE%^seems to have been lifted straight from the %^CYAN%^beach%^ORANGE%^ before being set %^RED%^a%^BOLD%^f%^YELLOW%^l%^WHITE%^a%^RED%^m%^RESET%^%^RED%^e%^ORANGE%^. Tongues of %^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^ORANGE%^, ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge, %^YELLOW%^ye%^RESET%^%^ORANGE%^l%^YELLOW%^low%^RESET%^%^ORANGE%^, %^BLUE%^b%^BOLD%^l%^RESET%^%^BLUE%^ue%^ORANGE%^, and brilliant %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e %^ORANGE%^f%^YELLOW%^l%^RED%^a%^BLUE%^m%^BOLD%^%^WHITE%^e %^RESET%^%^ORANGE%^dance around its borders, offering protection and never singing the shieldbearer.%^RESET%^");
   set_value(0);
   set_struck((:TO,"strikeme":));
}

int strikeme(int damage, object what, object who){
   if(!random(10)) {
      tell_room(environment(query_worn()),"%^RESET%^%^RED%^The f%^BOLD%^l%^YELLOW%^a%^WHITE%^m%^YELLOW%^e%^RED%^s %^RESET%^%^RED%^on "+ETOQCN+"'s shield f%^BOLD%^l%^YELLOW%^a%^RED%^r%^RESET%^%^RED%^e to life, blocking "+who->QCN+"'s attack!%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^RESET%^%^RED%^The f%^BOLD%^l%^YELLOW%^a%^WHITE%^m%^YELLOW%^e%^RED%^s %^RESET%^%^RED%^on your shield f%^BOLD%^l%^YELLOW%^a%^RED%^r%^RESET%^%^RED%^e to life, blocking "+who->QCN+"'s attack!%^RESET%^");
      tell_object(who,"%^RESET%^%^RED%^The f%^BOLD%^l%^YELLOW%^a%^WHITE%^m%^YELLOW%^e%^RED%^s %^RESET%^%^RED%^on "+ETOQCN+"'s shield f%^BOLD%^l%^YELLOW%^a%^RED%^r%^RESET%^%^RED%^e to life, blocking your attack!%^RESET%^");
      return (-1)*damage;
      return 1;
   }
}
