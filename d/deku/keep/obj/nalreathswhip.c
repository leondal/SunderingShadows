#include <std.h>
inherit "/d/common/obj/weapon/whip_dagger.c";
void create() 
{
    ::create();
    set_id(({ "whip","slasher","cruel slasher","cruel whip",
    "nalreaths whip","metal whip",
    "nalreaths slasher"}));
    set_name("whip");
    set_obvious_short("A whip made from metal");
    set_short("%^BOLD%^%^YELLOW%^Nal%^BOLD%^%^GREEN%^rea"+
    "%^BOLD%^%^YELLOW%^th's Cr%^BOLD%^%^GREEN%^"+
    "ue%^BOLD%^%^YELLOW%^l %^RED%^Sl%^BOLD%^%^BLUE%^as%^RESET%^"+
    "%^RED%^her%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^The lash of this whip "+
    "is made from a very %^BOLD%^%^WHITE%^thin"+
    "%^BOLD%^%^BLUE%^ and flexible strip of %^CYAN%^adamantium"+
    "%^BOLD%^%^BLUE%^ that has been "+
    "%^BOLD%^%^RED%^sharpened%^BOLD%^%^BLUE%^ by some "+
    "obviously magical method.  From different "+
    "angles the lash %^BOLD%^%^WHITE%^reflects"+
    "%^BOLD%^%^BLUE%^ a wet, %^RESET%^%^RED%^deep red"+
    "%^BOLD%^%^BLUE%^ color, as if it has recently drank "+
    "the blood of some living creature.  "+
    "The handle of the whip is a thick %^MAGENTA%^leather"+
    "%^BOLD%^%^BLUE%^ that has been dyed a "+
    "mysterious %^CYAN%^twi%^BOLD%^%^WHITE%^li"+
    "%^CYAN%^ght%^BOLD%^%^BLUE%^ hue.%^RESET%^");

    set_lore("%^BOLD%^%^BLUE%^Used long ago by the "+
    "murderer Nalreath, this whip was "+
    "thought destroyed after Nalreath was hung.  "+
    "Legend says it was made magically "+
    "at the very spot of one of Nalreath's most "+
    "horrid murders and then, as the victims "+
    "lay rotting and their blood pooled beneath them, "+
    "it was enchanted with their blood, "+
    "so that the crime would forever be remembered.  "+
    "Other legends even suggest that there "+
    "was more than one of them created, its impossible to know, "+
    "as Nalreath commited murders "+
    "for well over a century.%^RESET%^");
    set_property("enchantment",3);
    set("value", 3000);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    //i = query_property("enchantment") + 1;

}

int wield_func()
{
    
    tell_object(ETO,"%^RED%^Your mood is darkened as "+
    "your mind flashes with images of "+
    "%^YELLOW%^torn%^RESET%^%^RED%^ and %^YELLOW%^"+
    "gutted%^RESET%^%^RED%^ corpses.%^RESET%^");

    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),"%^RED%^Shakes "+
        ETO->query_possessive()+ " head quickly, as "+
        "if trying to forget something.%^RESET%^",ETO);
    }
    return 1;
}

int unwield_func()
{
    tell_object(ETO,"%^BOLD%^%^BLUE%^You shake your "+
    "head and decide to release the whip.%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    if(random(100) < 45) 
    {
        tell_object(ETO,"%^CYAN%^Your whip slashes deep into " +
        targ->query_cap_name()+"%^CYAN%^'s "+
        "flesh causing " +ETO->query_objective()+ "%^CYAN%^ "+
        "to scream out in pain!%^RESET%^");

        tell_object(targ,"%^CYAN%^You scream in %^RED%^pain"+
        "%^CYAN%^ as the whip wielded by "+
        ETO->query_cap_name()+" slashes deep into your flesh!%^RESET%^");

        tell_room(environment(ETO),targ->query_cap_name() + 
        "%^CYAN%^ screams out in pain " +
        "as the whip wielded by " +ETO->query_cap_name()+ 
        "%^CYAN%^ slashes deep into "+
        targ->query_possessive()+ "%^CYAN%^ flesh!%^RESET%^",({ETO,targ}));
        return roll_dice(3,3);	
    }
}