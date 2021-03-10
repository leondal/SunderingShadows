#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

int ench, enabled;
object bro, wielder;

void set_ench(int x) {
    ench = x;
}

void normal(object ob) {
    enabled = 0;

    while((int)ob->query_property("enchantment") != ench) {
        ob->set_property("enchantment", -1);
    }
    if(ob->query_wielded()) {
        tell_object(wielder,"%^RED%^The hilt of the ruby scimitar "+
        "cools.%^RESET%^");
    }
    bro = 0;
    wielder = 0;
    ench = 0;
}

void enable() {
    tell_object(ETO,"%^RED%^The hilt of the ruby scimitar "+
    "grows strangely warm as a bolt of red energy leaps "+
    "from its blade and arcs to slam into the blade of the "+
    "%^BOLD%^%^GREEN%^jade scimitar%^RESET%^%^RED%^!%^RESET%^");
        
    tell_room(EETO,"%^RED%^A bolt of red energy "+
    "leaps from the blade of the ruby scimitar wielded by "+ETOQCN+
    "%^RED%^ and arcs to slam into the blade of "+ETO->QP+
    "%^BOLD%^%^GREEN%^ jade scimitar%^RESET%^%^RED%^!"+
    "%^RESET%^",ETO);
}


void create() {
    ::create();
   set_id(({ "scimitar","sword","ruby sword","ruby scimitar", 
   "strike", "furious strike" }));
   set_name("scimitar");
   set_obvious_short("A ruby scimitar");
   set_short("%^RED%^Drakkan's Fur%^YELLOW%^i%^RED%^ous "+
   "Str%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^k%^BOLD%^%^WHITE%^e"+
   "%^RESET%^");

   set_long("%^RED%^The first glance at this curved scimitar "+
   "gives the impression that it is quite fragile.  It is "+
   "forged entirely from a flawless and smooth ruby.  "+
   "The blade, hilt, and pommel meld together almost perfectly "+
   "and only the vast differences in shape reveal "+
   "the specific purpose of each piece of the weapon.  "+
   "The blade is curved back, beginning at approximately the "+
   "center of its strangely sharpened edge and continuing to "+
   "the tip where it almost touches the back of itself.  The "+
   "edge of the blade is a slightly lighter red hue, perhaps "+
   "because of the method of sharpening that was used on it.  "+
   "The handle of the scimitar is broader and designed more "+
   "to allow for a somewhat comfortable and sturdy grip on the "+
   "weapon.  An eternal impression lingers on the hilt, "+
   "resembling the tight grip of a hand.  The pommel has been "+
   "chiseled into an almost completely circular shape and offers an "+
   "even more brilliant shine than the rest of the weapon.  "+
   "Strangely this weapon is not only perfectly balanced "+
   "but extremely light weight.%^RESET%^");
   
   set_lore("Forged for the ranger drakkan, this scimitar "+
   "is one of the brother blades that he has been known to "+
   "wield.  Both of the scimitars were created by a weapon "+
   "smith and then enchanted by a powerful magic.  The legends "+
   "suggest that this one was enchanted to lend magical strength "+
   "to the wielder, enabling him to land a more solid strike.  "+
   "The magic of the weapon has been rumored to be something "+
   "divine, likely a blessing bestowed upon drakkan because of "+
   "his fierce loyalty to the forest father silvanus.");

   set_property("enchantment",2);
   set_item_bonus("damage bonus", 1);
   set_value(1000);
   set_wield((:TO,"wield_me":));
   set_unwield((:TO,"unwield_me":));
   set_hit((:TO,"special":));
   set_heart_beat(1);
}

void heart_beat() {
    if(enabled == 1 && !TO->query_wielded()) {
        if(objectp(bro)) bro->normal(bro);
        normal(TO);
    }
}

void bonus(object ob) {
    wielder = ETO;
   
    if(objectp(ob)) bro = ob;
    while(query_property("enchantment") < ench + 1) {
        set_property("enchantment",1);
    }
    enabled = 1;
    enable();
}

int wield_me() {
    object *weapons;
    int x;
	if((int)ETO->query_highest_level() < 20) { 
		write("%^RED%^The magic of the scimitar is too great.%^RESET%^");
		return 0;
	}
    weapons = ETO->query_wielded();
    if(TO->query_property("enchantment") > 0) {
        for(x = 0;x < sizeof(weapons);x++) {
            if(weapons[x]->id("perfect strike")
            && weapons[x]->query_property("enchantment") > 0) {
                ench = TO->query_property("enchantment");
                bonus(weapons[x]);
                weapons[x]->set_ench(weapons[x]->query_property("enchantment"));
                weapons[x]->bonus(TO);
                return 1;
            }
        }
    }
        
	tell_object(ETO,"%^RED%^The hilt of the ruby scimitar is "+
    "cool to the touch.%^RESET%^");
    return 1;
}

int unwield_me() {
    if(enabled == 1) {
        if(objectp(bro)) bro->normal(bro);
        normal(TO);
        return 1;
    }
    tell_object(ETO,"%^RED%^Your hand quickly warms as you release "+
    "the hilt of the ruby scimitar.%^RESET%^");
    return 1;
}

int special(object targ) {
	int chance, x;
	chance = random(1001);
    if(!objectp(targ)) return random(9);

	if(chance > 490 && chance < 620) {
        if(enabled != 1) x = 0;
        if(enabled == 1) x = random(3);
        switch(x) {
		    case 0:
                tell_object(ETO,"%^RED%^You thrust your ruby "+
                "scimitar into "+targ->QCN+"%^RED%^ and feel it "+
                "contact %^BOLD%^%^WHITE%^bone%^RESET%^%^RED%^!%^RESET%^");

        	    tell_object(targ,ETO->QCN+"%^RED%^ thrusts "+ETO->QP+
                " ruby scimitar deep into you, causing you to wince in pain "+
                "as its blade clips a bone!%^RESET%^");			
		    
                tell_room(EETO,ETO->QCN+"%^RED%^ thrusts "+ETO->QP+
                " ruby scimitar into "+targ->QCN+"%^RED%^, causing "+
                targ->QO+" to visibly wince in pain!%^RESET%^",
                ({targ,ETO}));
                return 4 + random(4);						
            case 1:
                tell_object(ETO,"%^BOLD%^%^BLACK%^You slice deep "+
                "into "+targ->QCN+"%^BOLD%^%^BLACK%^ with your "+
                "%^RED%^ruby scimitar%^BOLD%^%^BLACK%^ and "+
                "issue a growl of fury as the blade cuts "+
                "through %^BOLD%^%^WHITE%^bone"+
                "%^BOLD%^%^BLACK%^!%^RESET%^");
                
                tell_object(targ,ETO->QCN+"%^BOLD%^%^BLACK%^ "+
                "issues a loud growl of %^RED%^fury%^BOLD%^%^BLACK%^ "+
                "as "+ETO->QP+" %^RED%^ruby scimitar%^BOLD%^%^BLACK%^ "+
                "slices deep into you, cutting through some of "+
                "your %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^!%^RESET%^");
                
                tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ "+
                "issues a loud growl of %^RED%^fury%^BOLD%^%^BLACK%^ "+
                "as "+ETO->QP+"%^RED%^ ruby scimitar%^BOLD%^%^BLACK%^ "+
                "slices deep into "+targ->QCN+"%^BOLD%^%^BLACK%^!"+
                "%^RESET%^",({targ,ETO}));
                ETO->set_property("magic",1);
                targ->do_damage(targ->return_target_limb(),3 + random(4));
                ETO->set_property("magic",-1);
                break;
             case 2:
                tell_object(ETO,"%^BLUE%^You stab "+targ->QCN+
                "%^BLUE%^ in the torso with your %^RED%^"+
                "ruby scimitar%^BLUE%^ and then tear the blade "+
                "free, causing "+targ->QO+" to scream in pain!%^RESET%^");

                tell_object(targ,"%^BLUE%^You scream out in pain "+
                "as "+ETO->QCN+"%^BLUE%^ stabs you in the chest "+
                "with "+ETO->QP+"%^RED%^ ruby scimitar%^BLUE%^ and "+
                "then tears the blade free!%^RESET%^");

                tell_room(EETO,targ->QCN+"%^BLUE%^ screams out in "+
                "pain as "+ETO->QCN+"%^BLUE%^ stabs "+targ->QO+
                " in the chest with a %^RED%^ruby scimitar%^BLUE%^ "+
                "and quickly tears the blade free!%^RESET%^",
                ({targ,ETO}));
                return 3 + random(5);
          }        
	}

}
