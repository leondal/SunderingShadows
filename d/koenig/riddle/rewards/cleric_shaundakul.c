//cleric_shaundakul.c - Cleric reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit CLERICSHIELD;

void create(){
   ::create();
	set_name("gauntlet of winds");
	set_id(({"shaundakul shield","gauntlet","glove","leather gauntlet","leather glove","shield","gauntlet of winds"}));
   	set_obvious_short("%^BOLD%^%^BLACK%^A dark black leather"+
		" gauntlet%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Gauntlet of %^RESET%^"+
		"%^CYAN%^W%^MAGENTA%^i%^CYAN%^n%^MAGENTA%^d"+
		"%^CYAN%^s%^RESET%^");
   	set_long("%^BOLD%^%^BLACK%^Crafted out of dark black"+
		" leather, this lone gauntlet is enchanted as to "+
		"always fit your hand perfectly.  The long gauntlet"+
		" resembles a glove more than a true gauntlet, coming"+
		" down to the middle of your forearm.  The padded "+
		"leather gauntlet looks well worn, as if its been "+
		"heavily used and well traveled.  On the back of the"+
		" gauntlet stitched in %^WHITE%^s%^RESET%^i%^BOLD%^l"+
		"%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^%^BLACK%^ is an"+
		" upright left hand.  Ripples of %^RESET%^%^CYAN%^blue-"+
		"gray%^BOLD%^%^BLACK%^ and %^RESET%^%^MAGENTA%^deep "+
		"violet%^BOLD%^%^BLACK%^ flow outwards from the glove,"+
		" symbolizing gusts of wind.  The gauntlet-glove is made"+
		" roomy enough to fit over other gloves that you might "+
		"wear, so that you may show the world the sacred symbol "+
		"of Shaundakul.%^RESET%^");
   	set_lore("The Gauntlet of Winds is a sacred item that all "+
		"clerics of Shaundakul strive to locate and find.  The"+
		" ancient gauntlets were common regalia for The Helping "+
		"Hand's followers before his faith dwindled away due to "+
		"the actions of Shar.  The gauntlet-gloves work like a "+
		"shield, but without the bulk that one might experience "+
		"with a shield.  The gauntlets are said to also be enchanted"+
		" to aid the priest in combat when they need it most.");
   	set_property("lore difficulty",12); 
   	set_struck((:TO,"strike_func":));
   	set_remove("%^CYAN%^You pull off the gauntlet-glove slowly, enjoying"+
		" the connection to the faiths past.");
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^CYAN%^A gust of wind is "+
		"issued forth from "+ETOQCN+"'s gauntlet, blowing through"+
		" "+who->QCN+".",({ETO,who}));
        tell_object(ETO,"%^CYAN%^A gust of wind is issued forth from"+
		" your gauntlet, blowing through "+who->QCN+".");
        tell_object(who,"%^CYAN%^A gust of wind is issued forth from"+
		" "+ETOQCN+"'s gauntlet, blowing through you!");
        who->do_damage("torso",(random(8)+1));
      }
}
