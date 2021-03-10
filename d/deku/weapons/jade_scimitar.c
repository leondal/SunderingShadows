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
        tell_object(wielder,"%^BOLD%^%^GREEN%^The hilt of the jade "+
        "scimitar cools.%^RESET%^");
    }
    bro = 0;
    wielder = 0;
    ench = 0;
}

void enable() {
    tell_object(ETO,"%^BOLD%^%^GREEN%^The hilt of the jade scimitar "+
    "grows strangely warm as a bolt of green energy leaps "+
    "from its blade and arcs to slam into the blade of the "+
    "%^RED%^ruby scimitar%^BOLD%^%^GREEN%^!%^RESET%^");
        
    tell_room(EETO,"%^BOLD%^%^GREEN%^A bolt of green energy "+
    "leaps from the blade of the jade scimitar wielded by "+ETOQCN+
    "%^BOLD%^%^GREEN%^ and arcs to slam into the blade of "+ETO->QP+
    " %^RED%^ruby scimitar%^BOLD%^%^GREEN%^!%^RESET%^",ETO);
}

void create() {
    ::create();
   set_id(({ "scimitar","sword","jade sword","jade scimitar", 
   "strike", "perfect strike" }));
   set_name("scimitar");
   set_obvious_short("A jade scimitar");
   set_short("%^RESET%^%^GREEN%^Drakkan's P%^BOLD%^e%^RESET%^%^GREEN%^rf"+
   "%^BOLD%^e%^RESET%^%^GREEN%^ct Str%^BOLD%^i%^RESET%^%^GREEN%^"+
   "k%^BOLD%^e%^RESET%^");
   
   set_weight(8);
   set_long("%^BOLD%^%^GREEN%^This weapon is made from a thick "+
   "and flawed piece of jade.  The hilt, blade, and pommel meld "+
   "together almost flawlessly and only their distinct shapes "+
   "make them easily identifiable.  The blade of the weapon "+
   "is almost entirely straight but begins curving slightly before "+
   "the point to almost touch the back of itself.  The edge of the "+
   "blade is much %^RESET%^%^GREEN%^darker%^BOLD%^ than the "+
   "rest of the weapon, with the natural blemishes of the jade "+
   "offerering it an occassional lighter fleck.  The hilt of the "+
   "weapon is thicker than normal and slightly rounded with "+
   "the small pommel connecting right below it to quickly "+
   "mushroom out.  The strange design obviously to provide a "+
   "catch in the event of the weapon slipping from the hand "+
   "that wields it.  The same blemishes that offer a lighter "+
   "fleck to the edge of the blade manage to provide a very "+
   "bizarre coloration to the entire weapon and even reflect "+
   "the smallest amount of light that contacts them.%^RESET%^");

   set_lore("Forged for the ranger drakkan, this scimitar "+
   "is one of the brother blades that he has been known to "+
   "wield.  Both of the scimitars were created by a weapon "+
   "smith and then enchanted by a powerful magic.  The legends "+
   "suggest that this one was enchanted to lend magical accuracy "+
   "to the wielder, enabling him to land a more precise and "+
   "disabling strike.  The magic of the weapon has been rumored "+
   "to be something divine, likely a blessing bestowed upon "+
   "drakkan because of his fierce loyalty to the forest father "+
   "silvanus.");

   set_property("enchantment", 2);
   set_item_bonus("attack bonus", 1);
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
            if(weapons[x]->id("furious strike")
            && weapons[x]->query_property("enchantment") > 0) {
                ench = TO->query_property("enchantment");
                bonus(weapons[x]);
                weapons[x]->set_ench(weapons[x]->query_property("enchantment"));
                weapons[x]->bonus(TO);
                return 1;
            }
        }
    }
	tell_object(ETO,"%^BOLD%^%^GREEN%^The hilt of the jade scimitar is "+
    "cool to the touch.%^RESET%^");
    return 1;
}

int unwield_me() {
    if(enabled == 1) {
       if(objectp(bro)) bro->normal(bro);
       normal(TO);
       return 1;
    }
    tell_object(ETO,"%^BOLD%^%^GREEN%^Your hand quickly warms as "+
    "you release the hilt of the jade scimitar.%^RESET%^");
    return 1;
}

int special(object targ) {
	int chance, x;
    string limb;
	chance = random(1001);
    if(!objectp(targ)) return random(9);

	if(chance > 490 && chance < 620) {
        if(enabled != 1) x = 0;
        if(enabled == 1) x = random(50);
        switch(x) {
		    case 0:
                tell_object(ETO,"%^BOLD%^%^GREEN%^You slice "+
                "into "+targ->QCN+"%^BOLD%^%^GREEN%^'s neck "+
                "with ease and perfect precision!%^RESET%^");

        	    tell_object(targ,ETO->QCN+"%^BOLD%^%^GREEN%^ "+
                "slices into your neck with ease and perfect "+
                "precision, leaving a deep and narrow wound!%^RESET%^");
		    
                tell_room(EETO,ETO->QCN+"%^BOLD%^%^GREEN%^ "+
                "slices into "+targ->QCN+"%^BOLD%^%^GREEN%^'s neck "+
                "with ease and perfect precision!%^RESET%^",
                ({targ,ETO}));
                ETO->set_property("magic",1);
                targ->do_damage("neck",3 + random(3));						
                ETO->set_property("magic",-1);
                break;
            case 1:
                tell_object(ETO,"%^BOLD%^%^WHITE%^You land a "+
                "perfect strike on "+targ->QCN+"%^BOLD%^%^WHITE%^ "+
                "and quickly withdraw your %^GREEN%^jade scimitar"+
                "%^BOLD%^%^WHITE%^ to strike again!%^RESET%^");
                
                tell_object(targ,ETO->QCN+"%^BOLD%^%^WHITE%^ strikes "+
                "you with perfect timing, quickly withdraing "+
                ETO->QP+ " %^GREEN%^jade scimitar%^BOLD%^%^WHITE%^ "+
                "to strike again!%^RESET%^");
                
                tell_room(EETO,ETO->QCN+"%^BOLD%^%^WHITE%^ strikes "+
                targ->QCN+"%^BOLD%^%^WHITE%^ with perfect timing "+
                "and quickly withdraws "+ETO->QP+" %^GREEN%^"+
                "jade scimitar%^BOLD%^%^WHITE%^ to only strike again"+
                "!",({targ,ETO}));
                ETO->set_property("magic",1);
                targ->do_damage(targ->return_target_limb(),2 + random(3));
                ETO->set_property("magic",-1);
                ETO->execute_attack();
                break;
             case 2..49:
                limb = targ->return_target_limb();
                tell_object(ETO,"%^MAGENTA%^You bring your "+
                "%^GREEN%^jade scimitar%^MAGENTA%^ down from "+
                "above and slash deep into "+targ->QCN+
                "%^MAGENTA%^'s "+limb+"!%^RESET%^");

                tell_object(targ,ETOQCN+"%^MAGENTA%^ brings "+
                ETO->QP+"%^GREEN%^ jade scimitar%^MAGENTA%^ "+
                "down from above, to slash deep into your "+
                limb+"!%^RESET%^");

                tell_room(EETO,ETOQCN+"%^MAGENTA%^ brings "+
                ETO->QP+"%^GREEN%^ jade scimitar%^MAGENTA%^ "+
                "down from above and slashes deep into "+
                targ->QCN+"%^MAGENTA%^'s "+limb+"!%^RESET%^",
                ({targ,ETO}));
                ETO->set_property("magic",1);
                targ->do_damage(limb,2 + random(3));
                ETO->set_property("magic",-1);
                break;
          }        
	}

}
