//revamp of the amazon spear - Cythera 7/05
#include <std.h>

inherit "/d/common/obj/weapon/mspear.c";

void create()
{
    ::create();
    set_name("thunderhead spear");
    set_id( ({"spear", "thunder spear", "thunderhead spear"}) );
    set_short("%^BOLD%^%^BLACK%^Th%^CYAN%^u%^BLACK%^nd%^CYAN%^e"+
    "%^BLACK%^rhead %^CYAN%^S%^YELLOW%^p%^CYAN%^ea%^YELLOW%^r"+
    "%^RESET%^");
    set_obvious_short("%^RESET%^A %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^u"+
    "%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^k%^BOLD%^%^BLACK%^"+
    "y%^RESET%^%^MAGENTA%^ purple%^RESET%^ spear shaft with a"+
    " jagged %^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c"+
    "%^YELLOW%^t%^BOLD%^r%^YELLOW%^u%^WHITE%^m%^RESET%^ spearhead");
    set_long("Crafted from a %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^u"+
    "%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^k%^BOLD%^%^BLACK%^"+
    "y%^RESET%^%^MAGENTA%^ purple%^RESET%^ wood, the shaft of"+
    " this spear is sleek and smooth.  The grain of the wood "+
    "takes on a lighter %^MAGENTA%^p%^RESET%^u%^MAGENTA%^r%^RESET%^"+
    "p%^MAGENTA%^l%^RESET%^e-gray color.  Mounted to the top of"+
    " the wooden shaft is a four sided spearhead made of "+
    "%^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^"+
    "t%^WHITE%^r%^YELLOW%^u%^WHITE%^m%^RESET%^.  The jagged angular"+
    " shape of the metal head bears an uncanny resemblance to a"+
    " %^BOLD%^%^CYAN%^li%^YELLOW%^g%^CYAN%^ht%^YELLOW%^i%^CYAN%^ng"+
    " bolt%^RESET%^.  The outer edges 'bolts' have been sharpened "+
    "to create a deadly serrated edge, which could easily rip "+
    "through flesh and muscle.  The butt of the spear has been "+
    "encased in an %^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c"+
    "%^YELLOW%^t%^WHITE%^r%^YELLOW%^u%^WHITE%^m%^RESET%^ cap.");
    set_lore("The Thunderhead Spear is seen by some as a savage and brutal weapon,"+
    " one that preys on the destructive and vicious side of storms.  Such a "+
    "spear naturally is favored by followers of Talos, who claim the spear "+
    "is a holy relic of the faith.  The spear it seems first arrived on the"+
    " shores of a remove forested island in the hands of a warlord who sought"+
    " to enslave the native women of the island under his control.  The warlord,"+
    " who's name is unknown, though underestimated the warrior women and their"+
    " skill in battle.  The women easily thwarted his and his small band of men's"+
    " attempt to control them, killing them all.  Since that time, the tribe of "+
    "warrior women have learned how to duplicate the spear he wielded and "+
    "proceeded to make copies to aid them in their battles against the dangers"+
    " that were spilling out of a nearby swamp.");
    set_property("lore",15);
    set_value(500);
    // set_size(2);
    // set_wc(1,8);
    // set_large_wc(1,10);
    // set_type("piercing");
    set_hit((:TO,"hit_func":));
    //set_prof_type("spear");
    set_property("enchantment",3);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) 
{
    tell_object(ETO,"%^BOLD%^%^CYAN%^Arcs of lightning dance across the"+
    " jagged tips of the spearhead as your fingers wrap around the"+
    " sleek shaft of the spear.");
    tell_room(environment(ETO),"%^BOLD%^%^CYAN%^Arcs of lightning dance"+
    " across the jagged tip of "+ETO->QCN+"'s spear.",({ETO}));
    return 1;
}
int unwield_func(string str) 
{
    tell_object(ETO,"%^BOLD%^%^CYAN%^The arcs of lightning fade away harmlessly "+
    "as you unwield the spear.");
    return 1;
}


int hit_func(object victim) 
{
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(victim)) return 1;
    if(random(1000) < 220)
    {
        switch(random(36))
        {	
            case 0..20:
                tell_object(ETO,"%^YELLOW%^You swing the butt of the spear around to bash "+
                ""+victim->QCN+" in the gut.");
                tell_object(victim,"%^YELLOW%^"+ETO->QCN+" swings the butt of "+ETO->QP+""+
                " spear around to bash you in the gut.",);
                tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" swings the butt of "+
                ""+ETO->QP+" spear around to bash "+victim->QCN+" in the"+
                " gut.",({ETO,victim}));
                victim->do_damage("torso",random(4)+2);
                break;
            case 21..33:
                tell_object(ETO,"%^BOLD%^%^CYAN%^You jam the spearhead deep into "+
                ""+victim->QCN+" and savagely pull it out.  The serrated tips"+
                " of the spearhead rip through flesh and muscle, creating a "+
                "vicious wound.");
                tell_object(victim,"%^BOLD%^%^CYAN%^"+ETO->QCN+" jams the tip of"+
                " "+ETO->QP+" spear deep into you and then savagely pulls it"+
                " out.  The serrated tips of the spearhead rip through your "+
                "flesh and muscle, creating a very painful wound!",);
                tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" jams the"+
                " tip of "+ETO->QP+" spear deep into "+victim->QCN+" and then"+
                " savagely pulls it out!",({ETO,victim}));
                victim->do_damage("torso",random(6)+3);
                break;
            case 34..35:
                tell_object(ETO,"%^BOLD%^%^BLACK%^You point the spearhead at"+
                " "+victim->QCN+" and release a bolt of %^YELLOW%^lightning"+
                "%^BOLD%^%^BLACK%^ at "+victim->QO+"!");
                tell_object(victim,"%^BOLD%^%^BLACK%^"+ETO->QCN+" points the spearhead at"+
                " you and releases a bolt of %^YELLOW%^lightning%^BLACK%^ at you!",);
                tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" points the"+
                " spearhead at "+victim->QCN+" and releases a bolt of "+
                "%^YELLOW%^lightning%^BLACK%^ at "+victim->QO+"!",({ETO,victim}));
                victim->do_damage("torso",random(10)+5);
                break;	
        }
	}
    return 1;
}