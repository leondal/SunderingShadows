//Made by Essyllis: Feb 2015
#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create() {
    	::create();
	set_name("asgardshield");
  	set_id(({"shield","Shield"}));
	set_obvious_short("A shield with Asgard's sigil%^RESET%^");
  	set_short("Shield of Asgard");
    	set_long("This large %^BOLD%^%^BLACK%^b%^RESET%^o%^BOLD%^%^BLACK%^dy-sh%^RESET%^i%^BOLD%^%^BLACK%^eld "+
		"%^RESET%^is still in remarkably good condition considering the beatings it must have "+
		"taken. The front does have some wear and tear but the %^YELLOW%^C%^WHITE%^i%^ORANGE%^ty "+
		"S%^WHITE%^i%^ORANGE%^gil of %^WHITE%^A%^ORANGE%^sg%^WHITE%^a%^ORANGE%^rd %^RESET%^stands "+
		"clear and unharmed. The %^BOLD%^%^BLACK%^sh%^RESET%^i%^BOLD%^%^BLACK%^eld %^RESET%^itself "+
		"is made of steel and could possibly be of dwarven making. Two adjustable leather straps "+
		"make it easy to adjust the shield to the wearer's arm.%^RESET%^");
	set_lore("This %^BOLD%^%^BLACK%^sh%^RESET%^ie%^BOLD%^%^BLACK%^ld %^RESET%^belonged to a "+
			"Knight of Torm called '%^BOLD%^Carnac Stigfredsson%^RESET%^'. Carnac was born and "+
			"raised in the city of Asgard and raised quickly through the ranks due to his skills "+
			"as a fighter and leadership abilities. At the height of his career he became %^BOLD%^%^RED%^Captain "+
			"%^ORANGE%^of the %^WHITE%^A%^ORANGE%^sg%^WHITE%^a%^ORANGE%^rd "+
			"%^WHITE%^C%^ORANGE%^omm%^WHITE%^a%^ORANGE%^nd%^WHITE%^o%^ORANGE%^s %^RESET%^and with them "+
			"successfully defended %^YELLOW%^Asgard %^RESET%^against many Troll attacks. This "+
			"%^BOLD%^%^BLACK%^sh%^RESET%^ie%^BOLD%^%^BLACK%^ld %^RESET%^was rewarded to Carnac after such a "+
			"Troll incursion by the %^YELLOW%^King of Asgard%^RESET%^.");
	set_property("lore",15);
  	set_struck((:TO,"strikeme":));
  	set_wear((:TO,"wearme":));
  	set_value(2500);
        set_property("enchantment",3);
}
int strikeme(int damage, object what, object who){
  	tell_object(ETO,"%^BOLD%^The S%^ORANGE%^i%^WHITE%^g%^ORANGE%^i%^WHITE%^l on the shield suddenly glows br%^ORANGE%^i%^WHITE%^ghtl%^ORANGE%^y %^WHITE%^as "+who->QCN+"%^BOLD%^ strikes at you!");
   	tell_object(who,"%^BOLD%^%^WHITE%^The sigil on "+ETO->QCN+"'s shield suddenly glows with a %^YELLOW%^bright light%^WHITE%^, blinding you!%^RESET%^");
   	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The sigil on "+ETO->QCN+"'s "+
		"shield suddenly flashes brightly, blinding  "+who->QCN+" as "+who->QS+" %^BOLD%^%^BLACK%^tries to attack!",({who,ETO}));
  return (-1)*(damage/2);
}

int wearme(){
  if((int)ETO->query_highest_level() <15){
  	write("%^GREEN%^The shield refuses you!");
   	  return 0;
  }
  	write("%^GREEN%^You cannot help to think of Asgard's destruction as you wear the shield.");
   	  return 1;  	
}
