#include <std.h>
inherit "/d/common/obj/weapon/whip.c";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	set_name("sharkskin whip");  
	set_id(({"whip","sharkskin whip","weapon"}));
	set_short("%^BLUE%^%^BOLD%^Sh%^RESET%^%^CYAN%^ar%^RESET%^k%^CYAN%^"+
		"sk%^BOLD%^%^BLUE%^in W%^RESET%^%^CYAN%^h%^WHITE%^i%^BOLD%^"+
		"%^BLUE%^p%^RESET%^");  
	set_obvious_short("%^RESET%^a %^BLUE%^%^BOLD%^sh%^RESET%^%^CYAN%^"+
		"ar%^RESET%^k%^CYAN%^sk%^BOLD%^%^BLUE%^in %^RESET%^whip");
	
	set_long("%^RESET%^%^CYAN%^The long braided length of this whip is "+
		"made from strips of rough, %^BOLD%^%^BLUE%^leathery sharkskin"+
		"%^RESET%^%^CYAN%^.  This gives the lash an added viciousness "+
		"when struck against unprotected skin as the hide snags and "+
		"grates when pulled.  Each strip varies in coloration from a "+
		"%^RESET%^pale gray %^CYAN%^to %^BOLD%^%^BLUE%^blue %^RESET%^"+
		"%^CYAN%^to even %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^in "+
		"some spots, giving the whip a colorful appearance despite its "+
		"dangerous purpose. To further enhance its beauty a hollowed "+
		"tube of %^ORANGE%^coral %^CYAN%^has been fit at the base and "+
		"secured by two %^RESET%^clam shells %^CYAN%^on either side.  "+
		"Through this tube the leathery sharkskin has been fed, leaving "+
		"a %^BLUE%^%^BOLD%^tasseled ruff %^RESET%^%^CYAN%^extending "+
		"from the pommel.%^RESET%^");
	
	set_value(300);
	set_property("enchantment",3);
		
	set_lore("When at sea for long periods of time, common materials "+
		"found on land such as cow hide, wood and metal are harder to "+
		"come by.  What is available is usually kept for repairs to "+
		"ship and protecting goods.  So it came to be that several "+
		"sailors developed alternate means and supplies for keeping "+
		"weapons in good repair.  Amongst those supplies things like "+
		"sharkskin, whale hide, coral, shell, driftwood and fish bone "+
		"became standard for making weapons and armor.  In the case of "+
		"this whip, shark hide was dried on deck then cut into thin "+
		"strips and braded together.  Once finished, enchanted pieces "+
		"of coral, blessed by priests of Istishia or Auril were "+
		"hollowed and fitted as handles to further enhance the magic "+
		"of the weapon.");
	set_property("lore difficulty",15);
	
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	
	set_hit((:TO,"hit_function":));
}

// for room stuff, +ETO->QCN+ = user name capatalized

int wieldme(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^The smooth %^RESET%^%^ORANGE%^"+
		"coral %^BOLD%^%^BLACK%^feels cool against your hand.%^RESET%^");
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" takes "+
		"hold of the smooth %^RESET%^%^ORANGE%^coral%^BOLD%^%^BLACK%^ "+
                "handle of their whip.%^RESET%^",ETO);
	return 1;
}

int removeme(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You loop up the coil of your "+
		"whip and store it away.%^RESET%^");
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" loops "+
		"up the coils of their whip and stores it away.%^RESET%^",ETO);
	return 1;
}

// for messages in hit function
// +targ->QO+ is target, i.e. $T
// +ETO->QCN+ is wielder, i.e. $N

int hit_function(object targ){
	if(random(1000) < 150) {
		switch(random(10)){
		
	case 0..5:
		tell_object(ETO,"%^BOLD%^%^RED%^Your lash leaves a raise "+
			"welt across "+targ->QCN+"'s skin!%^RESET%^");
		tell_object(targ,"%^BOLD%^%^RED%^You feel the burn "+
			"of "+ETO->QCN+"'s lash as it strikes you!%^RESET%^");
		tell_room(environment(ETO),"%^BOLD%^%^RED%^A raised welt "+
			"appears where "+ETO->QCN+"'s whip struck "+targ->QCN+"!"+
			"%^RESET%^",({targ,ETO}));
		set_property("magic",1);
		targ->do_damage("torso",random(6)+6);
		remove_property("magic");			
	break;	
		
	case 6..9:
		tell_object(ETO,"%^BOLD%^%^BLACK%^The whip lashes "+
			"around "+targ->QCN+"'s neck, choking them!");
		tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s whip "+
			"circles around your neck, choking you!%^RESET%^");
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s "+
			"whip circles around "+targ->QCN+"'s neck, choking "+
			"them!",({targ,ETO}));
		targ->set_paralyzed(10,"%^BOLD%^%^BLACK%^You've been "+
			"choked!%^RESET%^");
	break;			
		}
	return 1;
	}
}
