#include <std.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/armour/leather";
int chance;
object ActiveWorm;

void create() 
{
    ::create();
    set_name("deep purple leather");
    set_id(({"leather armor", "purple leather", "deep purple leather", 
    "purple armor", "leather", "deep purple armor", "guise", "deep purple guise", 
    "worm guise", "guise of the purple worm", "purple worm leather", "purple worm armor", "armor"}));
    
    set_short("%^RESET%^%^MAGENTA%^G%^BOLD%^ui%^RESET%^%^MAGENTA%^s%^BOLD%^e "+
    "o%^RESET%^%^MAGENTA%^f th%^BOLD%^e%^RESET%^%^MAGENTA%^ p%^BOLD%^"+ 
    "u%^RESET%^%^MAGENTA%^rpl%^BOLD%^e %^RESET%^%^MAGENTA%^w%^BOLD%^"+
    "o%^RESET%^%^MAGENTA%^rm%^RESET%^");
    
    set_obvious_short("%^RESET%^%^MAGENTA%^A suit of deep purple leather armor%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^This armor is made from very "+
    "thin strips of leather that have been carefully stitched "+
    "together.  The strips have each been dyed with a dull "+
    "black substance.  The outter surface of the armor "+
    "is continually interrupted by the numerous stitches "+
    "in their task of connecting the strips.  The inside of the "+
    "armor has been covered tightly with a thin and dark gray "+
    "fabric that offers a slight relief from the bumpier outter "+
    "surface.  In spite of the many seams, the armor makes almost "+
    "no sound.%^RESET%^");
    
    set_long("%^RESET%^%^MAGENTA%^This armor is made from "+
    "several layers of %^BOLD%^deep purple%^RESET%^%^MAGENTA%^ "+
    "material. The material looks like it has been cured by simply "+
    "sitting for a very long time. It has dried and cracked open in "+
    "multiple spots, though none of the cracks are deep enough to "+
    "go all the way through it. It has been stiched together carefully "+
    "with a %^BOLD%^%^BLACK%^dark gray%^RESET%^"+
    "%^MAGENTA%^ thread. There is a curious %^BOLD%^%^GREEN%^emblem"+
    "%^RESET%^%^MAGENTA%^ sewn into the front of it. It depicts a "+
    "large %^BOLD%^%^GREEN%^tree%^RESET%^%^MAGENTA%^, in full blossom, with numerous %^BOLD%^purple"+
    " worms%^RESET%^%^MAGENTA%^ bursting forth from within it "+
    "quite %^BOLD%^%^RED%^ch%^RESET%^%^RED%^ao%^BOLD%^%^RED%^t%^RESET%^%^RED%^"+
    "i%^BOLD%^%^RED%^c%^RESET%^%^RED%^a%^BOLD%^%^RED%^lly%^RESET%^%^MAGENTA%^. "+
    "The inside of the armor is padded with a layer of "+
    "material that is a %^BOLD%^slightly lighter%^RESET%^%^MAGENTA%^ shade.%^RESET%^");
    
     set_lore("%^RESET%^%^MAGENTA%^It is said that some years ago "+
     "a ranger of Silvanus, known simply as Howne, became obsessed with "+
     "purple worms, after fighting and being swallowed by one somewhere "+
     "in the Charu Mountains. It is rumored that his obsession eventually "+
     "led to madness. However, he was said to have never left the service "+
     "of Silvanus or at least he never thought that he did. This armor was "+
     "rumored to be a gift from the deity or perhaps that is only what the "+
     "crazed ranger believed. Either way it is said to have been made from "+
     "the hide of more than a few purple worms and some suggest that "+
     "it is somehow linked to them.%^RESET%^");
    
    set_property("lore difficulty", 14);
    
    set_value(4000);
    set_property("enchantment",2);
   
    set_item_bonus("attack bonus", 1);
    set_item_bonus("damage bonus", 1);
    
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    chance = 25 + random(46);    
    
}

int wearme() 
{
    tell_object(ETO, "%^RESET%^%^MAGENTA%^You feel more assured of your "+
    "ability to hit and inflict damage as you wear the deep purple leather!%^RESET%^");
    return 1;
}

int removeme() 
{
    tell_object(ETO, "%^RESET%^%^MAGENTA%^You feel the assurance granted "+
    "to you by the deep purple leather fade away.%^RESET%^");   
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;
    damage -= 2;
    tell_object(ETO, "%^RESET%^%^MAGENTA%^Your deep purple armor seems to absorb "+
    "some of the force of "+who->QCN+"%^RESET%^%^MAGENTA%^'s blow!%^RESET%^");
    
    tell_object(who, "%^RESET%^%^MAGENTA%^You feel the force of your blow "+
    "slightly weakened by "+ETOQCN+"%^RESET%^%^MAGENTA%^'s deep purple armor!%^RESET%^");
    
    if(objectp(ActiveWorm))
    {
        if(environment(ActiveWorm) != EETO)
        {
            tell_room(environment(ActiveWorm), ActiveWorm->query_short()+"%^RESET%^%^MAGENTA%^ simply "+
            "fades away!%^RESET%^");
            ActiveWorm->move("/d/shadowgate/void");
            if(objectp(ActiveWorm)) ActiveWorm->remove();
        }
        return damage;
    }
    else if(roll_dice(1, 100) > chance) return damage;
    else
    {
        ActiveWorm = new(WMON+"spectral_purple_worm");
        if(!objectp(ActiveWorm)) return damage;
        
        tell_object(ETO, "%^BOLD%^%^MAGENTA%^You feel a pulse of energy flow out from your "+
        "deep purple armor as "+ActiveWorm->query_short()+"%^BOLD%^%^MAGENTA%^"+
        " materializes between you and "+who->QCN+"%^BOLD%^%^MAGENTA%^, attacking "+
        who->QO+"!%^RESET%^");
        
        tell_object(who, "%^BOLD%^%^MAGENTA%^As you hit "+ETOQCN+", "+ActiveWorm->query_short()+
        "%^BOLD%^%^MAGENTA%^ materializes between you and "+ETO->QS+" and attacks you!%^RESET%^");
        
        tell_room(EETO, "%^BOLD%^%^MAGENTA%^As "+who->QCN+"%^BOLD%^%^MAGENTA%^ hits "+ETOQCN+", "+ActiveWorm->query_short()+
        "%^BOLD%^%^MAGENTA%^ materializes between them and attacks "+who->QO+"!%^RESET%^", ({ETO, who}));
        
        ActiveWorm->move(EETO);
        ActiveWorm->set_property("minion", ETO);
        ETO->add_follower(ActiveWorm);
        ETO->add_protector(ActiveWorm);
        ActiveWorm->force_me("kill "+who->query_name());
        ActiveWorm->swallow(who);
        return damage;       
    }
    return damage;    
}
    
   