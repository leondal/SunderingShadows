#include <std.h>

inherit "/d/common/obj/armour/hide";
int has_wraith, x;

void init() {
    ::init();
    if(interactive(ETO)) {
		TO->add_item_owner(ETOQN);
    }
}

void create() {
    ::create();
    set_name("black dragon hide");
    set_id(({ "hide", "armor","flesh","dralthoraks flesh",
    "hide armor", "dragon hide","black hide" }));
	set_obvious_short("%^BOLD%^%^BLACK%^A suit of black dragon "+
	"hide armor%^RESET%^");
    
    set_short("%^BOLD%^%^BLACK%^Dr%^WHITE%^a%^BOLD%^%^BLACK%^"+
    "lth%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rak's Fl%^RED%^e"+
    "%^BOLD%^%^BLACK%^sh%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^This marvelous suit of "+
    "armor has been carefully crafted from the hide of a "+
    "black dragon.  The surface of the armor is somewhere "+
    "between shiny and dull, suggesting that the dragon "+
    "from which it came was caught in the process of some type of "+
    "transition.  The armor is thick and padded beneath with "+
    "a lighter colored cloth that was obviously sewn onto "+
    "it sometime after it was originally forged.  The armor "+
    "is exceptionally smooth, fashioned with the pieces of the hide "+
    "all pointing downward, in an attempt to deter downward "+
    "angled cutting blows.  The smooth surface is interrupted "+
    "only by the points at which the segments of hide overlap and "+
    "only briefly then.%^RESET%^");

    set_lore("This armor was fashioned from the hide of the "+
    "young black wyrmling Dralthorak, who once dwelled "+
    "deep in the shadowlord forest and was controlled by the "+
    "vicious shadowlord.  Dralthorak met his end at the hand "+
    "of the ranger drakkan yurnklaw of silvanus and later "+
    "came back to life as this suit of hide.  The creation of "+
    "this armor was rumored to be a troubled one and "+
    "the magic that hid within the dragon has been rumored "+
    "to manifest itself at times.");

    set_property("enchantment",4);
    set_item_bonus("stealth",2);
    set_item_bonus("acid resistance",25);
    //set_item_bonus("sight bonus",2);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    has_wraith = 1;
    set_heart_beat(1);
}

void set_has_wraith(int x) {
    has_wraith = x;
}

int query_x() {
    return x;
}

void heart_beat() {
    object ob;
    if(!objectp(TO) || !objectp(ETO)) return;
    if(!interactive(ETO)) return;
    	if(has_wraith == -1)
    	{
		set_heart_beat(0);
		return;
	}
    if(has_wraith != 1) {
        x++;
        if(x == 2000) {
            x = 0;
            set_has_wraith(1);
            return;
        }
        return;
    }
    if(ETO->query_property("inactive")) return;
    if(has_wraith == 1 && query_worn()) {
        if(random(1001) > 996) {
            tell_object(ETO,"%^RED%^The unseen force that you've "+
            "felt around you for so long suddenly solidifies "+
            "into a monstrous black skinned creature!%^RESET%^");
           
            tell_room(EETO,"%^RED%^A monstrous black skinned "+
            "creature appears near "+ETOQCN+"%^RED%^ and "+
            "attacks "+ETO->QO+"!%^RESET%^",ETO);
            ob = new("/d/deku/monster/blackcreature");
            ob->move(EETO);
            ob->special_attack(ETO);
            set_has_wraith(0);
            return;
        }
        if(random(701) > 696) {
            switch(random(5)) {
                case 0:
                    tell_object(ETO,"%^RED%^A voice tells you:%^RESET%^  "+
                    "You will never be free of me.");
                    break;
                case 1:
                    tell_object(ETO,"%^BLUE%^You feel the lone pulse "+
                    "of a %^RED%^heart%^BLUE%^ vibrate through "+
                    "the armor.%^RESET%^");
                    break;
                case 2:
                    tell_object(ETO,"%^BOLD%^%^BLACK%^You feel "+
                    "the unseen force draw closer to you.%^RESET%^");
                    break;
                case 3:
                    tell_object(ETO,"%^BOLD%^%^WHITE%^An unseen "+
                    "force pushes at you, almost knocking you "+
                    "to the ground!%^RESET%^");
                    if(!ETO->query_invis()) {
                        tell_room(EETO,ETOQCN+"%^RED%^ staggers "+
                        "backward suddenly, as if someone unseen "+
                        "shoved "+ETO->QO+" violently!%^RESET%^",ETO);
                    }
                    break;
                case 4:
                    tell_object(ETO,"%^CYAN%^Someone whispers to "+
                    "you:%^RESET%^ nothing will stop me...");
                    break;
            }
        }
    }
}

int wearme() {
	if(ETO->query_highest_level() < 20)
	{
      	tell_object(ETO,"%^BOLD%^%^BLACK%^The power of the armor "+
	      "is too great for you.%^RESET%^");
      	return 0;
	}
	if(!TO->query_owns_item(ETOQN) && interactive(ETO)) 
	{
		tell_object(ETO, "%^BOLD%^%^BLACK%^The armor does not "+
		"fit you!%^RESET%^");
		return 0;
	}
    tell_object(ETO,"%^BOLD%^%^BLACK%^You feel an unseen force "+
    "surround you and your vision becomes slightly darkened."+
    "%^RESET%^");
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^BLACK%^The presence of "+
    "the unseen force falls away and your vision clears.%^RESET%^");
    return 1;
}
