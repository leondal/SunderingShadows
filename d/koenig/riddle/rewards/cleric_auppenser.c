//cleric_auppenser.c - Cleric reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
	set_name("shield of serenity");
	set_id(({ "shield", "auppenser shield","blue shield","shield of serenity"}));
   set_obvious_short("A blue small shield");
   set_short("%^BOLD%^%^BLUE%^Shield of %^RESET%^%^CYAN%^S%^BOLD%^%^CYAN%^e"+
	"%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^"+
	"i%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^y%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^This small blue round shield is "+
      "edged with a %^RESET%^%^ORANGE%^bronze border%^BOLD%^%^BLUE%^.  The blue "+
      "enamel used to color the metal takes on a lustrous quality, "+
      "causing the color to shift shades.  A relief of two %^BOLD%^%^WHITE%^"+
      "couatl%^BLUE%^ intertwined is prominent in the center of "+
      "the shield. The serpentine body of the couatl wrap around a "+
	"%^BOLD%^%^CYAN%^blue topaz%^BLUE%^ set into the center of the shield. "+
	"The straps of the shield are made of leather, dyed blue.%^RESET%^");
   set_lore("This shield is a relic of the faith of Auppenser.  It is granted only "+
      "to those most deserving, and it said to disappear should the wearer "+
      "ever prove unfaithful.");
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
   set_remove("%^BOLD%^%^BLUE%^You feel the serenity in your mind pass as you set the shield aside.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^The blue topaz on"+
		" "+ETOQCN+"'s shield emits a beam of pure force that tears through "+
		""+who->QCN+".",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^CYAN%^The blue topaz on your shield emits a beam"+
		" of pure force that tears through "+who->QCN+".");
        tell_object(who,"%^BOLD%^%^CYAN%^A beam of force is projected from "+
		""+ETOQCN+"'s shield, blasting into you!");
        who->do_damage("torso",(random(8)+1));
         }
}
