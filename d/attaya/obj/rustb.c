#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";
create() {
    ::create();
    set_name("rusted blade");
    set_id(({"rusted blade","rusted","blade","sword"}));
    set_short("%^RESET%^%^RED%^r%^ORANGE%^u%^RED%^st%^ORANGE%^e%^RED%^d bl%^ORANGE%^a%^RED%^d%^ORANGE%^e%^RESET%^");
    set_long(
      "An old rusted out steel sword.  It is still sharp and is quite jagged.  You can only imagine the horrible ripping of flesh resulting from being run through by this rusted blade."
    );
    set_property("enchantment",1);
    set_unwield("You release the rusty sword and wipe the oxidized ferric dust from your hands.");
    set_wield((: TO,"curse" :));
}

int curse() 
{
    if(ETO->query_level() < 10) 
    {
        tell_object(ETO, "NO YOU CANNOT WIELD THIS...  Sure, you want to, who wouldn't?  A weapon of such "+
        "fine craftsmanship just gives you a happy feeling when you tear people apart with it.  But alas, you are too little and puny.");
        return 0;
    }	
    if(!ETO->is_class("fighter")) 
    {
        tell_object(ETO, "You get a shard of rust in your wrist and you start to bleed!");
        ETO->do_damage("head",roll_dice(2,6));
        ETO->add_attacker(TO);
        ETO->continue_attack();
        if(objectp(ETO)) ETO->remove_attacker(TO);	
    }
    return 1;
}
