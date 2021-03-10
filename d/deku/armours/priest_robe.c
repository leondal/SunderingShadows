#include <std.h>
inherit "/d/common/obj/armour/robe";
#define R_COLORS ({"an azure","a crimson","an emerald","an ashen"})
#define D_COLORS ({"%^BLUE%^","%^RED%^","%^BOLD%^%^GREEN%^","%^BOLD%^%^WHITE%^"})

string color, des_color, ray;
int which_color;

void create() 
{
	 ::create();
    which_color = random(sizeof(R_COLORS));
    color = R_COLORS[which_color];
    des_color = D_COLORS[which_color];
    set_name("robe");
    set_id(({"robe","priest robe"}));
    set_short(des_color + capitalize(color)+" colored priest "+
    "robe%^RESET%^");
    set_obvious_short(des_color + capitalize(color)+" colored "+
    "robe%^RESET%^");
    
    set_long(des_color+"This robe is made from a soft cloth that "+
    "has been dyed "+color+" hue.  It has been stitched "+
    "together carefully in an attempt to sustain its life for as "+
    "long as possible.  A %^RESET%^%^GREEN%^dark green%^RESET%^"+
    des_color+" sash ties around the waist, to prevent the the "+
    "robe from fluttering open when worn.  It is suprisingly "+
    "clean and remarkably simple, with even the grain of the "+
    "thread going in the same direction.%^RESET%^");

    set_weight(5);
    set_value(100 + random(200));
    set_property("enchantment",3);
    set_item_bonus("divine resistance", 5);
    //set_item_bonus("bonus_spell_slots_3", 1);
    set_wear((:TO,"wearit":));
    set_remove(des_color+"You loosen the sash of your soft "+
    "cloth robe.%^RESET%^");
    set_struck((:TO,"strike_me":));
}

int wearit() {  
    //no longer restricting based on class, since 
    //armor + robe doesn't stack AC anymore - Saide, December 2016
    /*if(!ETO->is_class("cleric") && !ETO->is_class("paladin") 
    && !ETO->is_class("ranger") && !ETO->is_class("antipaladin")) {
        tell_object(ETO,des_color+"The robe rejects you!");
        return 0;
    }*/
 
    if(ALIGN->is_good(ETO)) {
        ray = "%^YELLOW%^burned by an intense light%^RESET%^";
	}
    if(ALIGN->is_evil(ETO)) {
        ray = "%^BOLD%^%^BLACK%^zapped by a bolt of pure darkness%^RESET%^";
    }
    if(ALIGN->is_neutral(ETO)) {
        ray = "%^BOLD%^%^WHITE%^bathed in a sickly green light%^RESET%^";
    }

    tell_object(ETO,des_color+"You tie the sash of your soft cloth robe.%^RESET%^");
    return 1;
}

int strike_me(int damage, object what, object who){
    if(random(1000) > 850  && (int)TO->query_property("enchantment") >= 1) {
    
        tell_room(EETO,des_color+"As "+who->QCN+des_color+ " strikes "+
        "the robe worn by "+ETO->QCN+ " "+des_color+who->QS+" is "+
        ray+des_color+" that comes forth from the robe!"+
        "%^RESET%^",({who,ETO}));

        tell_object(ETO,des_color+"As "+who->QCN+des_color+ " strikes "+
        "your robe, "+who->QS+" is "+ray+des_color+" that spews "+
        "forth from your robe!%^RESET%^");
    
        tell_object(who,des_color+"As you strike the robe worn by "+
        ETO->QCN+des_color+" you are "+ray+des_color+" that comes "+
        "forth from it!%^RESET%^");
    
        who->do_damage(who->return_target_limb(),roll_dice(1,8));
    }
}
