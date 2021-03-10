#include <std.h>
inherit "/d/common/obj/weapon/scythe.c";


void create() 
{
    ::create();
    set_name("bitter harvest");
    set_id(({"scythe", "harvest", "green scythe",
    "bitter harvest"}));
	
    set_obvious_short("%^RESET%^%^GREEN%^"+
    "A rusty green scythe%^RESET%^");
		
    set_short("%^RESET%^%^GREEN%^B%^BOLD%^"+
    "i%^RESET%^%^GREEN%^tt%^BOLD%^e%^RESET%^"+
    "%^GREEN%^r H%^BOLD%^a%^RESET%^%^GREEN%^rv%^BOLD%^"+
    "e%^RESET%^%^GREEN%^st%^RESET%^");
	
    set_long("%^BOLD%^%^GREEN%^This long scythe looks as "+
    "if it were pieced together quickly, as a last resort. "+
    "The curved blade is quite %^MAGENTA%^rusted%^BOLD%^"+
    "%^GREEN%^, with strange %^RESET%^%^GREEN%^dull%^BOLD%^"+
    " symbols barely visible beneath. The symbols glow "+
    "periodically with an %^RESET%^eerie %^BOLD%^"+
    "%^GREEN%^green light. The handle is made from a "+
    "%^RESET%^%^GREEN%^deep green %^BOLD%^%^GREEN%^"+
    "wood with patches of lighter and darker "+
    "hues of green throughout it. The handle is "+
    "scratched badly and some of them are deep. "+
    "They appear to be intentionally but whatever their "+
    "purpose is or might have been is not apparent. "+
    "A lone %^BOLD%^%^RED%^spider fang%^BOLD%^"+
    "%^GREEN%^ has been inserted into the end of the handle. "+
    "The point of the fang is chipped off and a "+
    "%^RESET%^%^GREEN%^dark green%^BOLD%^ is visible within "+
    "it.%^RESET%^");

    set_value(3000);
    set_property("lore difficulty", 15);

    set_lore("%^BOLD%^%^GREEN%^This scythe is one of the "+
    "last known items forged by the half-orc Feyren before "+
    "he lost his mind. It was put together quickly and the "+
    "pieces assembled from various other weapons that "+
    "were available. It is said that the fang in the "+
    "handle of it was the remaining fang from the spider "+
    "that killed his wife. Feyren named is so because to "+
    "him life had provided him with a bitter harvest in that "+
    "the spiders came and he lost his family all at once.%^RESET%^");

    set_property("enchantment",2);

    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
    set_item_bonus("damage bonus", 2);
}

int wield_me()
{
    tell_object(ETO, "%^BOLD%^%^GREEN%^Your are "+
    "overwhelmed with a sense of urgency as you "+
    "take up the scythe!%^RESET%^");
    return 1;
}

int unwield_me()
{
    tell_object(ETO, "%^RESET%^%^GREEN%^You feel at "+
    "ease as the feeling of urgency leaves you.%^RESET%^");
    return 1;
}

int special(object targ) 
{
    string tlim;
    int dam;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(100) < 75) return 0;
    tlim = targ->return_target_limb();

    tell_object(ETO, "%^BOLD%^%^RED%^You feel the handle of "+
    "your scythe %^BOLD%^%^WHITE%^P%^RESET%^%^WHITE%^U"+
    "%^BOLD%^%^WHITE%^L%^RESET%^%^WHITE%^S%^BOLD%^%^WHITE%^E "+
    "%^BOLD%^%^RED%^ rapidly as the blade sinks into "+
    targ->QCN+"%^BOLD%^%^RED%^'s "+tlim+"!%^RESET%^");

    tell_object(targ, "%^BOLD%^%^GREEN%^The blade of "+
    ETOQCN+"%^BOLD%^%^GREEN%^'s scythe sinks into your "+
    tlim+" and you can feel acid pumping into the wound!%^RESET%^");    
    tell_room(EETO, "%^BOLD%^%^GREEN%^The handle of "+ETOQCN+
    "%^BOLD%^%^GREEN%^'s scythe pulses rapidly as "+ETO->QS+
    " sinks the blade into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+
    tlim+"!%^RESET%^", ({targ, ETO}));
	
    targ->cause_typed_damage(targ,tlim,roll_dice(2,6),"acid");
    return 1;
}
