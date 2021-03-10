//Made by Lurue!!
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create()
{
    ::create();
    set_name("glass shard");
    set_short("%^RESET%^%^CYAN%^Sh%^BOLD%^a%^GREEN%^t%^RESET%^%^GREEN%^t"+
    "%^RESET%^e%^CYAN%^red S%^GREEN%^k%^CYAN%^y D%^GREEN%^a"+
    "%^BOLD%^g%^RESET%^%^GREEN%^g%^CYAN%^er%^RESET%^");
    set_obvious_short("%^RESET%^a %^GREEN%^g%^BOLD%^r%^RESET%^"+
    "%^CYAN%^e%^GREEN%^en piece of g%^BOLD%^l%^RESET%^"+
    "%^CYAN%^a%^GREEN%^ss%^RESET%^");
    set_id(({"green glass","shard","glass shard","glass","shattered sky dagger","dagger","glass dagger"}));
    set_long("%^RESET%^This small %^GREEN%^green hued dagger "+
    "%^RESET%^appears, on first inspection, to be little "+
    "more then a %^GREEN%^jagged shard %^RESET%^of %^CYAN%^"+
    "broken glass%^RESET%^. Cool and glossy to the touch, "+
    "the surface of the blade is %^CYAN%^beveled %^RESET%^from"+
    " the thick nearly opaque center down to a %^RED%^razor sharp"+
    " %^RESET%^edge on either side. A piece of %^BOLD%^%^RED%^bright"+
    " red cloth %^RESET%^has been wrapped around the thick base "+
    "and affixed tightly in place with bindings of pounded "+
    "%^ORANGE%^copper bands%^RESET%^. One at the top and a"+
    " second at the base of the hilt portion. Though the "+
    "weapon looks well made and cared for, there is an odd "+
    "sort of %^BOLD%^%^BLACK%^oxidation %^RESET%^and"+
    " %^CYAN%^discoloration %^RESET%^apparent on the bands, as"+
    " well as a faint scent of %^BOLD%^%^WHITE%^ozone %^RESET%^that"+
    " lingers about the dagger itself.\n%^RESET%^"); 
    set_lore("During violent storms, the fair-folk often abandon their"+
    " homes amongst meadows and natural glades to seek the more "+
    "solid shelter of caves and, occasionally, buildings. During "+
    "one such storm in 285 SG, a pixie clan attempted to take refuge"+
    " in the remains of an old abandoned building. Much to their "+
    "dismay they soon learned that a pack of vicious rats had been"+
    " calling the building home for some time. Pressed on one side "+
	"by the sharp teeth of the rats and on the other by the raging "+
    "storm, the pixies were trapped until lightning struck the building"+
    ", shattering one of the few remaining windows into hundreds of "+
    "small pixie sized shards. These shards were quickly gathered by "+
    "the pixies and used to defend themselves against the hungry rats.");
    set_property("lore difficulty",15);
    set_value(1900);
    set_property("enchantment",3);
    set_item_bonus("damage bonus",1);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
}
int wield_func()
{
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" vibrates with %^RED%^expectation"+
    " %^GREEN%^as "+ETO->QS+" takes hold of the %^RESET%^dagger%^RESET%^%^BOLD%^"+
    "%^GREEN%^.%^RESET%^ ",ETO);
    tell_object(ETO,"%^BOLD%^%^GREEN%^The %^RESET%^%^CYAN%^glass %^BOLD%^%^GREEN%^"+
    "of the %^RESET%^dagger %^RESET%^%^BOLD%^%^GREEN%^vibrates with"+
    " %^RED%^expectation %^GREEN%^as you take it firmly in your "+
    "grasp.%^RESET%^");
    return 1;
}
int unwield_func(){
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" looks less %^RED%^expectant"+
    " %^GREEN%^as "+ETO->QS+" puts the %^RESET%^dagger %^RESET%^"+
    "%^BOLD%^%^GREEN%^aside.%^RESET%^ ",ETO);
    tell_object(ETO,"%^BOLD%^%^GREEN%^The %^RED%^expectant %^GREEN%^energy "+
    "fades as you release your hold on %^RESET%^dagger%^RESET%^%^BOLD%^"+
    "%^GREEN%^.%^RESET%^");
    return 1;
}

int hit_func(object targ){
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;

    if(!random(10)) 
    {
        tell_object(ETO,"%^BOLD%^%^GREEN%^The hairs on the back of your neck"+
        " stand on edge as %^YELLOW%^lightning flares %^BOLD%^%^GREEN%^"+
        "across the %^RESET%^%^CYAN%^glass blade %^BOLD%^%^GREEN%^of "+
        "the %^RESET%^dagger %^RESET%^%^BOLD%^%^GREEN%^and strikes "+
        ""+targ->QCN+"!%^RESET%^ ");
        tell_room(environment(ETO),"%^BOLD%^%^GREEN%^A thunderous clap sounds as"+
        " %^YELLOW%^lightning %^GREEN%^flashes across the two %^RESET%^"+
        "%^ORANGE%^copper bands %^BOLD%^%^GREEN%^of "+ETO->QCN+"'s %^RESET%^"+
        "dagger %^RESET%^%^BOLD%^%^GREEN%^bathing the "+
        "%^RESET%^%^CYAN%^glass blade %^BOLD%^%^GREEN%^in electric %^RED%^fire"+
        " %^GREEN%^that arcs outward and strikes "+targ->QCN+"!%^RESET%^",({ETO,targ}));
        tell_object(targ,"%^BOLD%^%^GREEN%^The crackle of %^WHITE%^ozone %^GREEN%^"+
        "is the only warning you have before %^YELLOW%^lightning %^GREEN%^arcs"+
        " from "+ETO->QCN+"'s %^RESET%^dagger%^RESET%^%^BOLD%^%^GREEN%^ and"+
        " strikes you!%^RESET%^");
        targ->do_damage(targ->return_target_limb(),random(4)+3);
        return 1;
    }
    if(!random(20)) 
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^Your dagger begins to vibrate before"+
        " it releases a thunderous boom at "+targ->QCN+".");
        tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s dagger releases a "+
        "thunderous boom that tosses you through the air!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+targ->QCN+" is hurdled "+
        "back through the air after "+ETO->QCN+"'s dagger releases a "+
        "thunderous boom!",({ETO,targ}));
        targ->do_damage("torso",random(3)+3);
        targ->set_paralyzed(7,"%^BOLD%^%^BLACK%^You are still picking yourself up after that fall");
        return 1;
    }
}