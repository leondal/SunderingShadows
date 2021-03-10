#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/dagger";

int charges, perm;

void create(){
	::create();
	set_name("fire dagger");
	set_id(({ "dagger", "fire dagger", "dagger of fire", "flame dagger" }));
	set_short("%^BOLD%^%^WHITE%^K%^YELLOW%^i%^BOLD%^%^WHITE%^"+
	"n%^YELLOW%^o%^BOLD%^%^WHITE%^rd%^YELLOW%^a%^BOLD%^%^WHITE%^'"+
	"s%^RESET%^ %^RED%^dagger of fl%^YELLOW%^a%^RESET%^"+
	"%^RED%^m%^YELLOW%^e%^RESET%^");
	set_obvious_short("A dagger of flame");
	set_long("%^RED%^This small dagger barely manages to "+
    "reach one foot in length.  It is approximately four inches "+
    "in width and appears to be made entirely from fire.  It "+
    "is impossible to look at it and determine if there is any "+
    "solid substance to it at all and only the different "+
    "colored fire distinguishes the different parts of "+
    "the weapon.  The blade of the weapon is made from "+
    "%^ORANGE%^or%^YELLOW%^a%^ORANGE%^nge%^RESET%^%^RED%^ and "+
    "r%^YELLOW%^e%^RESET%^%^RED%^d flames that leap outward "+
    "from it, hinting at a very chaotic and out of control fire.  "+
    "The cross-piece, hilt, and pommel are all made from a "+
    "softer and more controlled %^BLUE%^bl%^YELLOW%^u%^BLUE%^"+
    "e%^RESET%^%^RED%^ flame that simply flickers and almost "+
    "entirely dies out occassionally.  A soft and barely "+
    "audible %^CYAN%^hum%^RESET%^%^RED%^ is given off from the "+
    "entire weapon.%^RESET%^");

	set_lore("These daggers were said to be made by a "+
    "mysterious and very private magi, known as Kinorda, for "+
    "the legions that served him.  He forged them from a metal "+
    "that was known "+
    "to give off a slight and strange hum and enchanted "+
    "them to continually burn.  They aren't very common and "+
    "some legends suggest the magic might fade after a time.");

	set_property("lore difficulty",10);
	set_property("enchantment",3);
    set_item_bonus("fire resistance", 10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
    
    charges = random(12);
    if(charges == 0) 
	{
        perm = 1;
        //changing fire swords and fire daggers so that only the permanent 
        //ones are actually worth alot. 
        set_value(2500);
    }
    else 
    {
        charges+= 15;
        set_value(100 + random(100));
        set_heart_beat(1);
    }
}

void heart_beat() {
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(!perm && charges < 1) {
        tell_object(ETO,"%^RED%^The fire on your dagger burns out "+
        "and the humming ceases.%^RESET%^");
        tell_room(EETO,"%^RED%^The fire on "+ETOQCN+"%^RED%^'s "+
        "dagger burns out and the humming ceases.%^RESET%^",ETO);
        TO->set_weight(0);
        new("/d/common/obj/weapon/dagger")->move(ETO);
        TO->remove();
        return;
    }
} 


int unwield_func() {
    if(!perm) {
        charges--;
    }
    return 1;
}
        
        

int wield_func(){
    
    tell_object(ETO,"%^RED%^You slowly take hold of the dagger and "+
"wince, but no pain comes, the fire feels strangely cool.%^RESET%^");
    
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"%^RED%^ slowly takes hold of the "+
        "dagger and winces slightly, but then looks relieved.%^RESET%^",ETO);
    }

	return 1;
}

int hit_func(object targ){
    if(!objectp(targ)) return 1;
	if(!random(4)){
        switch(random(18)) {
            case 0..9:
                tell_object(ETO,"%^CYAN%^A sad tune is hummed "+
                "by the dagger as you strike "+
                targ->QCN+"%^CYAN%^!%^RESET%^");
                
                tell_object(targ,ETOQCN+"%^CYAN%^'s dagger hums "+
                "a sad tune as it strikes you!%^RESET%^");

                tell_room(EETO,ETOQCN+"%^CYAN%^'s dagger hums "+
                "a sad tune as it strikes "+targ->QCN+"%^CYAN%^"+
                "!%^RESET%^",({targ,ETO}));

                return roll_dice(1,4) + random(4);
                break;

            case 10:
                tell_object(ETO,"%^BLUE%^The dagger glows "+
                "%^RED%^brilliantly%^BLUE%^ for a second "+
                "and then a massive %^RED%^fireball%^BLUE%^ erupts "+
                "from the end of it!%^RESET%^");

                tell_object(targ,ETOQCN+"%^BLUE%^'s dagger "+
                "glows %^RED%^brilliantly%^BLUE%^ for a moment "+
                "and then a massive %^RED%^fireball%^BLUE%^ "+
                "erupts from the end of it, heading straight "+
                "for you!%^RESET%^");

                tell_room(EETO,ETOQCN+"%^BLUE%^'s dagger glows "+
                "%^RED%^brilliantly%^BLUE%^ for a moment "+
                "and then a massive %^RED%^fireball%^BLUE%^ "+
                "erupts from the end of it, heading straight "+
                "for "+targ->QCN+"%^BLUE%^!%^RESET%^",({targ,ETO}));
                
                if(charges) {
                    charges--;
                }
                new("/cmds/spells/f/_fireball")->use_spell(ETO,targ,8,8,"mage");
                return 1;
                break;

            case 11..16:
                
                tell_object(ETO,"%^BOLD%^%^BLACK%^The dagger "+
                "flashes momentarily to an entirely black "+
                "fl%^YELLOW%^a%^BOLD%^%^BLACK%^me and a "+
                "tendril from it lashes at "+targ->QCN+"%^BOLD%^"+
                "%^BLACK%^!%^RESET%^");

                tell_object(targ,ETOQCN+"%^BOLD%^%^BLACK%^'s dagger "+
                "flashes momentarily to an entirely black "+
                "fl%^YELLOW%^a%^BOLD%^%^BLACK%^me and "+
                "a tendril from it lashes at you!%^RESET%^");

                tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^'s dagger "+
                "flashes momentarily to an entirely black "+
                "fl%^YELLOW%^a%^BOLD%^%^BLACK%^me and "+
                "a tendril from it lashes at "+targ->QCN+"%^BOLD%^"+
                "%^BLACK%^!%^RESET%^",({targ,ETO}));

                return roll_dice(2,2) + random(4);
                break;

            case 17:
                
                tell_object(ETO,"%^YELLOW%^An explosion of "+
                "%^RED%^fire%^RESET%^%^YELLOW%^ from your "+
                "dagger collides with "+targ->QCN+"%^YELLOW%^!"+
                "%^RESET%^");

                tell_object(targ,"%^YELLOW%^An explosion of "+
                "%^RED%^fire%^RESET%^%^YELLOW%^ from "+ETOQCN+
                "%^YELLOW%^'s dagger slams into you, burning "+
                "you horribly!%^RESET%^");
                
                tell_room(EETO,"%^YELLOW%^An explosion of "+
                "%^RED%^fire%^RESET%^%^YELLOW%^ from "+ETOQCN+
                "%^YELLOW%^'s dagger collides with "+targ->QCN+
                "%^YELLOW%^!%^RESET%^",({targ,ETO}));
                if(!SAVING_D->saving_throw(targ,"spell",-1)) { 
                    return roll_dice(3,6) + random(6);
                }
                return roll_dice(2,4) + random(3);
                break;
        }
	}
}
