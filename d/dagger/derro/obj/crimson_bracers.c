//Added lore - Also tweaked them just a bit
//where the emerald guardian changes based on 
//alignment in reflection of what was listed 
//on the alignment of the make_em
//function - Cythera 9/05
#include <std.h>
#include <daemons.h>
#define WAIT_TIME 14400

inherit "/d/common/obj/armour/bracers";
int used_time;
int is_metal() { return 0; }

void create(){
    ::create();
    set_name("%^RESET%^%^RED%^C%^BOLD%^%^RED%^r"+
    	"%^RESET%^%^RED%^i%^BOLD%^%^RED%^m%^RESET%^%^RED%^"+
   	"s%^BOLD%^%^RED%^o%^RESET%^%^RED%^n Bracers%^RESET%^");
    set_id(({ "bracers", "bracer", "crimson bracers",
    "crimson bracer","red bracer","red bracers"}));
    set_short("%^RESET%^%^RED%^C%^BOLD%^%^RED%^r"+
    	"%^RESET%^%^RED%^i%^BOLD%^%^RED%^m%^RESET%^%^RED%^"+
   	"s%^BOLD%^%^RED%^o%^RESET%^%^RED%^n Bracers%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^Ruby bracers%^RESET%^");
    set_long("%^RED%^Each of these bracers are formed from a "+
    	"%^BOLD%^%^WHITE%^shining%^RESET%^%^RED%^ and flawless ruby.  "+
    	"They are less than one inch thick and are very light.  The"+
    	" inside of the bracers are lined with %^BOLD%^r%^RESET%^"+
    	"%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y colored silk, "+
    	"adding some comfort and padding.    "+
    	"Engraved deep into the rubies on each bracers is a small "+
    	"%^BOLD%^%^WHITE%^inscription%^RESET%^%^RED%^ that could "+
    	"easily be read.%^RESET%^");
    set_lore("Created by the Crimson Sorcerer Hulron Elric over "+
       "two decades ago, the Crimson Bracers have become a true marvel."+
       "  The Crimson Sorcerer delved into abjuration and conjuration/"+
       "summoning magic.  Wanting to find a way to offer protection to "+
       "himself he was able to infuse his ruby bracers with a guardian "+
       "spell.  This allowed Hulron to be able to summon guardians to him"+
       " when ever he needed them, being the cautious wizard that he was.  "+
       "In time the Crimson Sorcerer used his famous bracers to buy himself "+
       "alliances and protection from those bent on stealing his secrets of "+
       "magic from him.  His Crimson Guardians were each outfitted with a pair"+
       " of these bracers.  Some claim that these bracers were further enchanted"+
       " to allow Hulron to not only summon his emerald guardians but also"+
       " anyone who wore these bracers.  Hulron sent his Crimson Guardians to"+
       " aid his old friend King Ravhas with an uprising of derro savants and"+
       " their lava para-elemental.  Sadly, none of the Crimson Guardians "+
       "survived in the battle.  Hulron was deeply affected by this loss, to"+
       " the point of secluding himself away from the outside world.  No one "+
       "is sure where or what happened to the Crimson Sorcerer.");
    set_property("lore",13);
    set("read",
@AVATAR
%^BOLD%^%^WHITE%^Protection is given if only you request...%^RESET%^
%^BOLD%^%^WHITE%^Guards await day by day to do for their master the best.%^RESET%^
AVATAR
    );
    set_value(5000);
    set_property("enchantment",3);
    set_weight(10);
    if(TO->query_property("repairtype")) TO->remove_property("repairtype");
    set_property("repairtype",({ "jewel","armorsmith" }));
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}

void init(){
    ::init();
    if(living(ETO)) {
        add_action("make_em","request");
    }
}

void failure() {
    tell_object(ETO,"%^BOLD%^%^RED%^The bracers fail to respond.\n",EETO);
    return 1;
}

int make_em(string str){

	int align;

	align = ETO->query_alignment();

 	if (ETO->query_bound() || EETO->query_unconscious() 
    || EETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
    }
   	
  	if(!str) {
        tell_object(ETO,"Request what?\n");
        return 1;
    }	
    if(!(query_worn())){
		failure();
		return 1;
	}

    if(WAIT_TIME > (time() - used_time)) {
        failure();
        return 1;
    }
        
    if(str == "guards" || str == "protection"){
        used_time = time();
        ETO->force_me("emote begins softly caressing "+ETO->QP+" ruby "+
        "bracers and chanting loudly");
		switch(align){
		    case 1: case 4: case 7:
     new("/cmds/spells/f/_faithful_phantom_guardians.c")->use_spell(ETO,"warriors",26,100,"mage");
			    return 1;
			case 2: case 5: case 8:
   new("/cmds/spells/f/_faithful_phantom_guardians.c")->use_spell(ETO,"centaurs",26,100,"mage");
				return 1;
			case 3: case 6: case 9:
                           new("/cmds/spells/f/_faithful_phantom_guardians.c")->use_spell(ETO,"bats",26,100,"mage");
				return 1;
			default:
			    tell_object(ETO,"See a Wiz about this, your alignment "+
                "is whacked.");
                return 1;
        }
	}
     
  	failure();	
    return 1;
}

int wear_func(){
    int align = ETO->query_alignment();
    if(::check() != 1) {
        return 0;
    }
    if((int)ETO->query_lowest_level() < 20) {
        write("The magic of the bracers refuses you!");
        return 0;
    }
    if(!ETO->query_invis()) {        
        tell_room(EETO,"%^RED%^"+ETOQCN+" wears the perfectly "+
        "fitted ruby bracers!%^RESET%^",ETO);
    }
	switch(align) 
	{
        case 1: case 4: case 7:
            tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" "+
            "slips on a pair of ruby bracers.%^RESET%^",ETO);
            tell_object(ETO,"%^RED%^You slip on a pair of ruby bracers. "+
            "Images of four %^BOLD%^%^GREEN%^emerald%^RESET%^ "+
            "%^RED%^warriors with long swords in their hands glow "+
            "brightly within the bracers.%^RESET%^");
            set_long("%^RED%^Each of these bracers are formed from a "+
            "%^BOLD%^%^WHITE%^shining%^RESET%^%^RED%^ and flawless ruby.  "+
            "They are less than one inch thick and are very light.  The"+
            " inside of the bracers are lined with %^BOLD%^r%^RESET%^"+
            "%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y colored silk, "+
            "adding some comfort and padding.  Impressed deep into"+
            " the bracers are %^BOLD%^%^GREEN%^four emerald "+
            "warriors%^RESET%^%^RED%^, each wielding a longsword.  "+
            "Engraved deep into the rubies on each bracers is a small "+
            "%^BOLD%^%^WHITE%^inscription%^RESET%^%^RED%^ that could "+
            "easily be read.%^RESET%^");
            break;
        case 2: case 5: case 8:
        tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" "+
        "slips on a pair of ruby bracers.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^You slip on a pair of ruby bracers. "+
        "Images of two %^BOLD%^%^GREEN%^emerald%^RESET%^ "+
        "%^RED%^centaurs with long swords in their hands glow "+
        "brightly within the bracers.%^RESET%^");
        set_long("%^RED%^Each of these bracers are formed from a "+
        "%^BOLD%^%^WHITE%^shining%^RESET%^%^RED%^ and flawless ruby.  "+
        "They are less than one inch thick and are very light.  The"+
        " inside of the bracers are lined with %^BOLD%^r%^RESET%^"+
        "%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y colored silk, "+
        "adding some comfort and padding.  Impressed deep into"+
        " the bracers are %^BOLD%^%^GREEN%^two emerald "+
        "centaurs%^RESET%^%^RED%^, each wielding a longsword.  "+
        "Engraved deep into the rubies on each bracers is a small "+
        "%^BOLD%^%^WHITE%^inscription%^RESET%^%^RED%^ that could "+
        "easily be read.%^RESET%^");
        break;
    case 3: case 6: case 9:
        tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" "+
        "slips on a pair of ruby bracers.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^You slip on a pair of ruby bracers. "+
        "Images of eight %^BOLD%^%^GREEN%^emerald%^RESET%^ "+
        "%^RED%^bats glow brightly within the bracers.%^RESET%^");
        set_long("%^RED%^Each of these bracers are formed from a "+
        "%^BOLD%^%^WHITE%^shining%^RESET%^%^RED%^ and flawless ruby.  "+
        "They are less than one inch thick and are very light.  The"+
        " inside of the bracers are lined with %^BOLD%^r%^RESET%^"+
        "%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y colored silk, "+
        "adding some comfort and padding.  Impressed deep into"+
        " the bracers are %^BOLD%^%^GREEN%^eight emerald "+
        "bats%^RESET%^%^RED%^.  "+
        "Engraved deep into the rubies on each bracers is a small "+
        "%^BOLD%^%^WHITE%^inscription%^RESET%^%^RED%^ that could "+
        "easily be read.%^RESET%^");
        break;

        default:
        tell_object(ETO,"See a Wiz about this armor.  Your alignment "+
        "is whacked.");
        return 0;
	}
    	return 1;
}

int remove_func(){
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^RED%^"+ETOQCN+"%^RED%^ slowly removes the "+
        "perfectly fitted ruby bracers!%^RESET%^",ETO);
    }
        
    	tell_object(ETO,"%^RED%^You slowly remove the perfectly "+
    		"fitted ruby bracers, the images inside fade away!%^RESET%^",EETO);
	set_long("%^RED%^Each of these bracers are formed from a "+
    		"%^BOLD%^%^WHITE%^shining%^RESET%^%^RED%^ and flawless ruby.  "+
    		"They are less than one inch thick and are very light.  The"+
    		" inside of the bracers are lined with %^BOLD%^r%^RESET%^"+
    		"%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y colored silk, "+
    		"adding some comfort and padding.    "+
    		"Engraved deep into the rubies on each bracers is a small "+
    		"%^BOLD%^%^WHITE%^inscription%^RESET%^%^RED%^ that could "+
    		"easily be read.%^RESET%^");
	return 1;
}

void set_used_time(int x) {
    used_time = x;
}
