#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
	::create();
	set_name("steel dagger");
	set_id(({ "steel dagger", "dagger", "curved dagger" }));
	set_short("%^RESET%^%^CYAN%^S%^BOLD%^%^BLACK%^t%^RESET%^e%^CYAN%^el of the %^YELLOW%^D%^RESET%^%^ORANGE%^e%^YELLOW%^se%^RESET%^%^ORANGE%^r%^YELLOW%^t Sa%^RESET%^%^ORANGE%^n%^YELLOW%^ds%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^c%^YELLOW%^u%^RESET%^%^CYAN%^rved s%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^eel d%^YELLOW%^a%^RESET%^%^CYAN%^gger%^RESET%^");
	set_long("%^RESET%^%^CYAN%^Curved into a near crescent shape, this "+
	   "steel dagger features an incredibly sharp edge that runs from "+
	   "the %^BLACK%^%^BOLD%^stone lined hilt %^RESET%^%^CYAN%^all the "+
	   "way to the curved tip.  The metal has been treated with an "+
	   "etching reagent that has left tiny %^YELLOW%^golden symbols "+
	   "%^RESET%^%^CYAN%^across every smooth surface.  Looking closely "+
	   "though, it's impossible to make out what they say, yet the way "+
	   "they glow suggests a magical language.  While oddly shaped, "+
	   "when used to slash, the blade cuts quickly and deeply, while "+
	   "the hooked tip can be used to catch and tear. %^RESET%^");
	set_value(0);
	set_lore("Many fighters have employed the use of various kinds of "+
	   "powder to blind and stun their opponent.  Dirt from the ground "+
	   "is as important as anything else, yet the fine grain sands of "+
	   "the desert are often coveted as the grit is difficult to "+
	   "dislodge from the eyes, but does not burn or risk ruining "+
	   "the eyesight the way that some of the more toxic powders can.");
	set_property("lore difficulty",5);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
	set_hit((:TO,"hit_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^YELLOW%^A sudden burst of sand explodes from "+ETOQCN+"'s %^RESET%^"+query_short()+"%^YELLOW%^.  "+targ->QCN+" staggers back furiously rubbing at their eyes to get the grit out.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The golden symbols flare to life and a burst of sand explodes from the surface of your dagger, blinding "+targ->QCN+" and causing them to rub at their eyes to get the grit out!%^RESET%^");
	tell_object(targ,"%^YELLOW%^A burst of sand flies into your face, briefly stunning you as "+ETOQCN+" slashes and cuts through your defenses!%^RESET%^");
	if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-10)){
		targ->set_paralyzed(roll_dice(1,4)+1);
	}
	else
		{
		tell_object(targ,"Your reflexes let you avoid the worst of the sand.");
		}
		
return 0;	}
}