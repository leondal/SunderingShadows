// new description and lore. Nienne, 07/07.
#include <std.h>
inherit PARMOUR;
object ARMO;

void init(){
    ::init();
	if(interactive(ETO))
 	{
		TO->add_item_owner(ETOQN);	
	}
}

void create(){
    ::create();
    set_heart_beat(1);
    set_name("robe");
    set_id(({"robe","stormrobe","storm robe","tatterd robe","torn robe","chain draped stormrobe","draped robe"}));
    set_short("%^BOLD%^%^BLACK%^Cha%^RESET%^i%^BOLD%^%^BLACK%^n-dr%^WHITE%^a%^RESET%^p%^BOLD%^%^BLACK%^ed S%^RESET%^t%^YELLOW%^o%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^m%^CYAN%^r%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^e%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^An old %^RESET%^ta%^BOLD%^%^BLACK%^t%^RESET%^tered %^CYAN%^robe bound in %^BOLD%^%^BLACK%^chains%^RESET%^");
    set_long("%^CYAN%^Hard at first to discern as an article of clothing, "
"this robe is %^RESET%^ta%^BOLD%^%^BLACK%^t%^RESET%^tered %^CYAN%^and "
"frayed almost to the point of falling apart. The %^BOLD%^pale blue "
"%^RESET%^%^CYAN%^material it has been made from is torn and rent by "
"%^BOLD%^%^BLUE%^win%^CYAN%^d%^BLUE%^s %^RESET%^%^CYAN%^that constantly "
"enfold the garment and tear eternally at its tattered threads. Even in a "
"calm environment the robe flaps as if being driven in a gale. The only "
"thing that seems to prevent the cloth from being torn apart are the "
"%^BOLD%^%^BLACK%^bla%^WHITE%^c%^RESET%^k%^BOLD%^%^BLACK%^ened "
"cha%^RESET%^i%^BOLD%^%^BLACK%^ns %^RESET%^%^CYAN%^that encircle it, "
"anchoring the robe to its wearer.%^RESET%^");
    set_lore("The crafting of a robe such as this is attributed to a "
"greatly skilled magus, argued by many to be mad. Theodore LasRadis was a "
"powerful wizard, said to be obsessed with the mastery of greater and "
"greater destructive evocations. He made many such items as this, that "
"only barely contain the dangerous forces imbued within, and are highly "
"sought by other mages of similar inclination, as well as followers of "
"Talos. It was said that his life was brought to an abrupt halt following "
"a similar experiment gone awry, unleashing the full force of his "
"spellcraft upon himself in an unpleasant end.");
    set_property("lore",18);
    set_weight(5);
    set_value(1500);
    set_property("enchantment",2);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_max_internal_encumbrance(21);
    set_wear((:TO,"wear_it":));
    set_remove((:TO,"remove_it":));
    set_struck((:TO,"struck":));
}

int query_size(){
    if(living(ETO)) return ETO->query_size();
    else return 3;
}

int wear_it(){
    if(((ETO->is_class("mage") || ETO->is_class("cleric") 
	|| ETO->is_class("psion"))  &&
      (!ETO->is_class("fighter")) && (!ETO->is_class("thief")))) {
	    
        if((int)ETO->query_highest_level() < 21) { // standard +3 item cap
	        tell_object(ETO,"The robe laughs at the puny one "+
            "who tries to wear it.");
            if(!ETO->query_invis()) {
                tell_room(EETO,ETOQCN+"'s robe seems to mock "+ETO->QO+
                " with a rustling of wind through its folds.",ETO);
            }
	        return 0;
        }


    	if(!TO->query_owns_item(ETOQN)) {
            tell_room(EETO,"%^BOLD%^%^YELLOW%^A bolt of lightning "+
            "strikes the person who dares to wear a stormrobe that "+
            "is not attuned to "+ETO->QO+"!%^RESET%^",ETO);
	        ETO->do_damage("torso",(random(50)+10));
	        return 0;
	    }
    
        if(!ETO->query_invis()) {
            tell_room(EETO,ETOQCN + "%^CYAN%^ wraps blackened chains "+
            "around the tattered windripped robe to keep it in place"+
            ".%^RESET%^",ETO);
        }
        
        tell_room(EETO,"%^BOLD%^%^YELLOW%^Lightning dances across "+
        "the chains as "+ETOQCN+" wears the robe.%^RESET%^",ETO);

        tell_object(ETO,"%^BOLD%^%^YELLOW%^Lightning dances across "+
        "the chains as you wear the robe.%^RESET%^");
	  //Used to be 35% - changed cause of their ease to 
        //acquire - Saide 
	  //Psions can wear the robe - but it doesn't give 
	  //them anymore magic resistance
	  if((!ETO->is_class("psion") && ETO->is_class("mage")) ||
    	  (ETO->is_class("cleric") && !ETO->is_class("psion"))) 
    	  {		
        	ETO->set_property("magic resistance",10);
	  }
	    ETO->add_sight_bonus(5);
	    set_heart_beat(1);
	    return 1;
    }
    
    tell_object(ETO,"%^CYAN%^Bah this robe looks old and "+
    "tattered, you decide against wearing it!%^RESET%^");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"%^CYAN%^ looks at a robe in "+
        ETO->QP+" possession and scoffs at it.%^RESET%^",ETO);
    }
    return 0;
}

int remove_it(){
    
    write("%^CYAN%^The stormwinds around you calm as you remove the "+
    "robe.%^RESET%^");
    
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^CYAN%^The robe stops blowing in "+
        "its own wind as "+ETOQCN+"%^RESET%^%^CYAN%^ removes "+
        "it.%^RESET%^",ETO);
    }
    ETO->add_sight_bonus(-5);
    if((!ETO->is_class("psion") && ETO->is_class("mage")) ||
    (ETO->is_class("cleric") && !ETO->is_class("psion"))) 
    {
    
		ETO->set_property("magic resistance",-10); 
    }
    return 1;
}

int struck(int damage, object what, object who){
    if(objectp(who)) {
        tell_object(ETO,"%^RESET%^%^CYAN%^Stormwinds blast at "+
        who->QCN+"%^RESET%^%^CYAN%^ as "+who->QS+" hits you "+
        "weaking "+who->QP+" blow!%^RESET%^");
    }

    if(!(random(2))) {

        tell_room(EETO,ETO->QCN+"%^RESET%^%^CYAN%^'s robe "+
        "suddenly snaps in its own wind and its flapping "+
        "knocks "+who->QCN+"'s blow off balance!",({who,ETO}));

        tell_object(who,"%^RESET%^%^CYAN%^As you try to hit "+
        ETO->QCN+"%^RESET%^%^CYAN%^ a flapping chain from "+
        ETO->QP+ " robe knocks you off balance, making your "+
        "blow less effective!%^RESET%^");

        if(!random(4)) {
            tell_room(EETO,"%^BOLD%^%^YELLOW%^A great arc crackles "+
            "from the chains at "+who->QCN+" as "+who->QO+
            " touches them!%^RESET%^",who);

            tell_object(who,"%^BOLD%^%^YELLOW%^A great arc of "+
            "lightning hits you as you strike the chains!%^RESET%^");
            
            who->do_damage("torso",random(15)+15);
        }
        return (damage*(1/2));
    }
    return 1;
}

void heart_beat() {
    object owner,env;
    int i,xx,yy;
    env = ETO;
    if(!objectp(ETO)) return;

    if(objectp(env) && living (env)) {
        owner = env;
        env = EETO;
    }

    if((!(TO->query_worn())) || (ETO->query_invis())) {
        return;
    } 

    xx = random(500);
    yy = random(7);
    
    if((xx > 495)) {
        tell_object(owner,"\n%^CYAN%^The robe flaps as the winds "+
        "contained try to escape.%^RESET%^\n");
    
        switch(yy) {
            case 0:
                tell_room(env,"%^CYAN%^"+owner->QCN+"s robe billows about "+
                ETO->QO+" in a storm only it can feel.%^RESET%^",
                owner);
                break;
            case 1:
                tell_room(env,"%^BOLD%^%^YELLOW%^Lightning crackles "+
                "%^BLACK%^along the black chains that encircle "+
                owner->QCN+"'s robe.%^RESET%^",owner);
                break;
            case 2:
                tell_room(env,"%^BOLD%^%^CYAN%^Water drips on the floor "+
                "and pools around "+owner->QCN+"'s feet.%^RESET%^",owner);
                break;
            case 3:
                tell_room(env,"%^BLUE%^"+owner->QCN+" is suddenly a "+
                "backlit shadow as %^BOLD%^%^YELLOW%^lightning%^RESET%^"+
                "%^BLUE%^ crashes behind "+owner->QO+"%^RESET%^!",owner);
                break;
            case 4:
                tell_room(env,"%^CYAN%^As a gust of wind passes through "+
                "the room "+owner->QCN+"'s robe suddenly stops flapping "+
                "and remains calm till the wind passes!%^RESET%^",owner);
                break;
            case 5:
                tell_room(env,"%^BOLD%^BLACK%^Thunder rolls through the "+
                "room shaking everyone!%^RESET%^",owner);
                break;
            case 6:
                tell_room(env,"%^CYAN%^Winds whips at "+owner->QCN+
                "'s robe and the tatters seem held together only "+
                "by the blackened chains that hang around them!"+
                "%^RESET%^",owner);
                break;
          }
    }
}
