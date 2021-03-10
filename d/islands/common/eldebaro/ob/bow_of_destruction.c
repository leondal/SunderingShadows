#include <std.h>
inherit "/d/common/obj/lrweapon/longbow";

void create() {
    ::create();
    set_name("a gleaming longbow");
    set_id(({"bow", "gleaming longbow", "longbow", "bow of destruction"}));
    set_obvious_short("%^BOLD%^%^CYAN%^gl%^BOLD%^%^WHITE%^ea%^BOLD%^%^CYAN%^"+
    "ming longbow%^RESET%^");
    
    set_short("%^BOLD%^%^BLACK%^L%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^"+
    "ngb%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^w "+
    "of D%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^str%^BOLD%^%^RED%^u%^BOLD%^%^BLACK%^"+
    "ct%^BOLD%^%^RED%^io%^BOLD%^%^BLACK%^n%^RESET%^");
    
    set_long("%^BOLD%^%^CYAN%^The upper and lower limbs of this longbow are "+
    "constructed from a %^BOLD%^%^BLACK%^dark mahogany%^BOLD%^%^CYAN%^. There "+
    "are multitudes of %^BOLD%^%^WHITE%^runes%^BOLD%^%^CYAN%^ carved into "+
    "both limbs. The %^BOLD%^%^WHITE%^runes%^BOLD%^%^CYAN%^ shift around "+
    "constantly and give off a faint gl%^BOLD%^%^WHITE%^ea%^BOLD%^%^CYAN%^m. "+
    "The grip of the bow is made from a %^BOLD%^%^WHITE%^lighter%^RESET%^%^RED%^ "+
    "mahogany%^BOLD%^%^CYAN%^ that has several strange symbols carved into it. "+
    "The string of the bow appears to be made from some very thin and very durable "+
    "substance and is quite thick, except for the mocking point, which is "+
    "almost translucent. A low pitched hum is constantly coming from the "+
    "string when the bow is not in use.%^RESET%^");
    
    set_lore("%^BOLD%^%^BLACK%^This longbow was rumored to have been one of the "+
    "most powerful weapons ever wielded by Arsheeva Wyndar. It was said to have been "+
    "a gift from Lysara himself, but whether or not that is true is a matter of debate. "+
    "What is known about the bow is that it bestows an incredible dexterity on the "+
    "wielder and is said to possess the ability to reign down destruction during "+
    "combat, the likes of which have rarely ever been seen before.%^RESET%^");
    
    set_property("lore difficulty",25);
    set_value(12000);
    set_ammo("longbow arrows");
    set_property("enchantment",5);
    set_item_bonus("dexterity", 6);
    set_wield((:TO,"wieldme":));
    set_decay_rate(0);
    set_unwield("%^BOLD%^%^CYAN%^You release your hold on the longbow "+
    "and feel the power granted to you, from it, fade away as the "+
    "humming from the string begins anew.%^RESET%^");
       
    set_lrhit((:TO,"extra_lrhit":));
}

int wieldme()
{
   if((int)ETO->query_lowest_level() < 35)
   {
      tell_object(ETO, "You are far too weak to harness the power of the longbow!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^CYAN%^You raise the longbow and the humming from "+
   "the string ceases as you feel its power mingle with your own!%^RESET%^");
   tell_room(EETO,ETOQCN+"%^BOLD%^%^CYAN%^ raises the longbow!",ETO);
   return 1;
}

int extra_lrhit(object targ)
{
    object *vics, env;
    int x, hits;
    string tlim;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(random(1000) < 400)
    {
        vics = ETO->query_attackers();
        if(!sizeof(vics)) return 0;
        tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ suddenly aims his bow into the air and releases "+
        "a hail of arrows!%^RESET%^", ETO);
        tell_object(ETO, "%^BOLD%^%^CYAN%^You suddenly aim your bow into the air and release a "+
        "hail of arrows!%^RESET%^");
        
        for(x = 0;x < sizeof(vics);x++)
        {
            if(!objectp(vics[x])) continue;
            if(!objectp(env = environment(vics[x]))) continue;
            if(env != EETO) continue;
            tlim = vics[x]->return_target_limb();
            tell_room(EETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+" is pierced by one of the falling "+
            "arrows!%^RESET%^", vics[x]);
            
            tell_object(vics[x], "%^BOLD%^%^BLACK%^Your "+tlim+" is pierced by one of the "+
            "falling arrows!%^RESET%^");
            
            vics[x]->cause_typed_damage(vics[x], tlim, roll_dice(3, 12), "piercing");
            continue;
        }
    }
    return 0;
}
