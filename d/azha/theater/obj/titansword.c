#include <std.h>

inherit "/d/common/obj/weapon/bastard.c";

void create(){
   ::create();
   set_name("titan's reign");
   set_id(({"titan's reign","sword","large sword","bastard sword","+
  	""glassteel sword","stained glass sword"}));
   set_obvious_short("%^RESET%^%^CYAN%^A %^GREEN%^s%^BOLD%^t%^WHITE%^a%^YELLOW%^"+
    	"i%^BLUE%^n%^RESET%^%^BLUE%^e%^MAGENTA%^d%^CYAN%^ glassteel bastard"+
    	" sword%^RESET%^");
   set_short("%^RESET%^%^BLUE%^T%^CYAN%^i%^GREEN%^t%^CYAN%^a%^MAGENTA%^"+
    	"n%^BLUE%^'%^GREEN%^s %^BOLD%^R%^BLUE%^e%^CYAN%^i%^GREEN%^g%^BLUE%^"+
    	"n%^RESET%^");
   set_long("%^CYAN%^This bastard sword is an unusual and im"+
    	"pressive piece of work.  Fashioned from %^GREEN%^s%^BOLD%^t%^WHITE%^"+
    	"a%^YELLOW%^i%^BLUE%^n%^RESET%^%^BLUE%^e%^MAGENTA%^d%^CYAN%^ glasst"+
    	"eel, the sword has the luster of %^BOLD%^%^WHITE%^glass%^RESET%^"+
    	"%^CYAN%^ and the strength of tempered steel.  The b"+
    	"lade of the sword flares out below the tip before tapering to it's"+
    	" fine point. %^BOLD%^%^BLACK%^ Black lead%^RESET%^%^CYAN%^ lines "+
    	"crisscross the blade, creating the strange shapes used for the "+
    	"%^GREEN%^s%^BOLD%^t%^WHITE%^a%^YELLOW%^i%^BLUE%^n%^RESET%^%^BLUE%^"+
    	"e%^MAGENTA%^d%^CYAN%^  glass effect. A large male%^BOLD%^ titan"+
    	"%^RESET%^%^CYAN%^ in a %^BOLD%^%^WHITE%^short toga%^RESET%^%^CYAN%^"+
    	" is the most prominent figure on the blade, dwarfing the %^GREEN%^"+
    	"rol%^BOLD%^li%^RESET%^%^GREEN%^ng h%^BOLD%^i%^RESET%^%^GREEN%^lls"+
    	"%^CYAN%^ about him.  Cast against %^BOLD%^%^GREEN%^verdant green hills"+
    	" %^RESET%^%^CYAN%^and an %^BOLD%^%^BLUE%^azure blue sky%^RESET%^%^CYAN%^"+
    	", the %^YELLOW%^blond%^RESET%^%^CYAN%^ titan male with curly locks looks"+
    	" strong and majestic, in a classical way.  A half circle with %^YELLOW%^"+
    	"gold%^RESET%^%^CYAN%^ and %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^ spoke"+
    	"s joins the hilt with the blade.  The hand-hold is made from the same"+
    	" %^GREEN%^s%^BOLD%^t%^WHITE%^a%^YELLOW%^i%^BLUE%^n%^RESET%^%^BLUE%^e"+
    	"%^MAGENTA%^d%^CYAN%^ glassteel as the sword, it's touch smooth and s"+
    	"oft. %^RESET%^\n");
   set_lore("The Titan's Reign is a classical play, one that is part of "+
    	"the curriculum of any college devoted to playwriting.  In the play,"+
    	" Nexdonis is a titan prince from a shattered kingdom.  His kingdom "+
    	"was left in ruins by the dragon Svexlar, an ancient dracolich.  Nex"+
    	"donis fights to gain his family's lands again against the powerful "+
    	"wyrm and to search for the mythical blade - Titan's Reign. The glas"+
    	"steel sword forged by Nexdonis' ancestors.  Set in three acts, the "+
    	"play is one of the best examples of how to write a heroic epic play"+
    	".  Rich with emotions, background stories, and actions this play ha"+
    	"s stood the test of time. The ending is one that to this day does n"+
    	"ot leave a dry eye in the house. - Classical Plays of Yesteryears -"+
    	" Haldor Lemsage  ");
set_property("lore difficulty",13);
set_property("enchantment",random(2)+2);
   	set_value(1356);
   	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
   	set_hit((:TO,"hit_func":));
}
int wield_func(string str) {
   	if((int)ETO->query_lowest_level() < 14) {
      	tell_object(ETO,"%^BOLD%^%^BLUE%^You can't seem to even manage to l"+
      		"ift this sword!%^RESET%^");
      return 0;
   }
   	tell_object(ETO,"%^CYAN%^Light dances off the vibrant and intense colo"+
    		"rs of the stained glass sword.%^RESET%^");
   	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" hefts the b"+
    		"astard sword up with ease, the light dances off of the vibrant and i"+
    		"ntense colors of the stained glass.%^RESET%^",ETO);
	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BLUE%^You release the sword, giving yourself time to"+
    		" recover from wielding such a large blade.");
   	tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" "+
      	"releases "+ETO->QP+" hold of the bastard sword.",ETO);
 	return 1;
}

int hit_func(object targ)
{
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;
  	if(random(1000) < 175)
    {
        switch(random(23))
        {
        case 0..11:
                tell_object(ETO,"%^BOLD%^%^BLUE%^The image of the titan begins to glow "+
                "brighter, fueling your attack on "+targ->QCN+" with his strength.");
              tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s sword begins to glow b"+
                "righer as "+ETO->QS+" tears into you with a savage blow.");
              tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" deals a savage"+
                " blow to "+targ->QCN+".", ({ETO,targ}));
              targ->cause_typed_damage(targ, "torso", roll_dice(1, 4) + 3, "slashing");
            break;
        case 12..19:
                tell_object(ETO,"%^BLUE%^You slash deep into "+targ->QCN+" and quickly bri"+
                "ng the sword back for a second hit!",);
              tell_object(targ,"%^BLUE%^"+ETO->QCN+" slashes deeply into you and brings "+
                "the sword back around for a second hit!");
              tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" slashes deeply into "+targ->QCN+""+
                ", and brings "+ETO->QP+" blade around for a second hit!", ({ETO,targ}));
                    ETO->execute_attack();
            break;
        case 20..22:
                tell_object(ETO,"%^CYAN%^You leap into the air and bring your sword crashing down"+
                " onto "+targ->QCN+".",);
              tell_object(targ,"%^CYAN%^"+ETO->QCN+" leaps into the air, bringing "+ETO->QP+" crashing"+
                " down into you!");
              tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" leaps into the air, bringing"+
                " "+ETO->QP+" sword crushing down onto "+targ->QCN+".", ({ETO,targ}));
              targ->cause_typed_damage(targ, "torso", roll_dice(1, 6) + 9, "slashing");

        default:  
            break;
        }
    return 1;
	}
}
