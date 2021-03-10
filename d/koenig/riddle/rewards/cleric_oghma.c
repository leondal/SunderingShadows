//cleric_oghma.c - Cleric reward for Riddle Quest Circe 4/13/04
//Updated since Oghma is no longer craft god - 12/7
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
add_id("buckler");
   set_obvious_short("%^YELLOW%^A %^BOLD%^%^BLACK%^rune etched%^YELLOW%^"+
	" buckler%^RESET%^");
set_short("%^BOLD%^%^WHITE%^Buckler of the %^YELLOW%^R%^BLACK%^u"+
	"%^RESET%^%^MAGENTA%^n%^BOLD%^%^WHITE%^e%^YELLOW%^s%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Forged from %^YELLOW%^gold%^WHITE%^, this "+
	"small round buckler has been lovingly polished.  %^YELLOW%^E"+
	"%^WHITE%^m%^YELLOW%^b%^WHITE%^r%^YELLOW%^o%^WHITE%^i%^YELLOW%^d"+
	"%^WHITE%^e%^YELLOW%^r%^WHITE%^e%^YELLOW%^d %^BOLD%^%^BLACK%^black"+
	" leather%^WHITE%^ straps are riveted into the shield, creating a "+
	"steady and comfortable grip.  The outer edge of the buckler features"+
	" a turned edge, allowing it more ease in fending off blows.  The interior "+
	"of the shield is carved and engraved with numerous %^RESET%^%^MAGENTA%^"
        "runes%^BOLD%^%^WHITE%^.  Some of the runes are common ones still used "+
	"today, but the rest seem oddly foreign.  In the center of the shield "+
	"there is a half sphere shape that rises up higher than the rim of the"
	" shield.  The half sphere is kept free of any adornment, instead looking"+
	" like a blank slate waiting for something.%^RESET%^");
set_lore("This shield is a relic of the faith of Oghma.  It is "+
      "granted only to those most deserving, and it said to "+
      "disappear should the wearer ever prove unfaithful.");
   set_property("lore difficulty",8);
   set_struck((:TO,"strike_func":));
   set_remove("%^YELLOW%^You carefully set the buckler aside.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^YELLOW%^"+ETOQCN+" "+
           "holds "+ETO->QP+" buckler steady as the %^WHITE%^runes%^YELLOW%^"
		" flare to life, blasting "+who->QCN+", with a wave of pure sound.",({ETO,who}));
        tell_object(ETO,"%^YELLOW%^You can the start of a haunting melody.  "+
		"The runes on your buckler light up, blasting "+who->QCN+" with"+
		" a wave of pure sound.");
        tell_object(who,"%^YELLOW%^The runes on "+ETOQCN+"'s shield flare to life.  "+
		"Suddenly a wave of pure sound strikes you!");
        who->do_damage("torso",random(8)+1);
         }
}
