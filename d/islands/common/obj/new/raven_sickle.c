#include <std.h>

inherit "/d/common/obj/weapon/sickle.c";


void create()
{
    ::create();
    set_id(({"sickle","wing","raven's wing","raven"}));

    set_name("raven's wing");

    set_obvious_short("%^BOLD%^%^BLACK%^A blackened sickle%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^Raven's Wing%^RESET%^");

    set_long(
        "The blade of this sickle curves wickedly in a semi-circle.  "+
        "The edges are razor sharp, and the blade has been etched with "+
        "images of %^BOLD%^%^BLACK%^ravens %^RESET%^in flight against "+
        "an empty sky.  The handle has been wrapped in thin %^BOLD%^%^BLACK%^"+
        "black leather cording %^RESET%^to prevent the wielder from cutting himself.  "+
        "The %^BOLD%^%^BLACK%^blackened blade %^RESET%^glitters dully, "+
        "seeming to drink up the light.");

    set_value(130000);

    set_property("no curse",1);
    set_property("enchantment", 7);

    set_item_bonus("intelligence",6);
    set_item_bonus("caster level",3);

    set_wield((:TO,"wield_me":));
    set_unwield("%^BOLD%^%^BLACK%^You feel the raven recede as you lower the sickle.");
    set_hit((:TO,"hit_me":));

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wield_me()
{
    tell_object(ETO,"%^BOLD%^%^BLACK%^The call of the raven rushes through you "+
        "as you wield the darkened sickle.");
    tell_room(EETO,"%^BOLD%^%^BLACK%^The whoosh of wings fills the air as "+
        ""+ETO->QCN+" takes the sickle in hand.",ETO);
    return 1;
}


int hit_me(object targ)
{
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;

    if(random(2)) { return roll_dice(1,6); }

    switch(random(5))
    {
    case 0..3:

        tell_object(ETO,"%^BOLD%^%^RED%^You slash "+targ->QCN+" "+
            "viciously across the face with your sickle!");
        tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" slashes you "+
            "across the face with "+ETO->QP+" sickle!");
        tell_room(EETO,"%^BOLD%^%^RED%^Blood flies through the air "+
            "as "+ETOQCN+" slices "+targ->QCN+" across the face "+
            "with "+ETO->QP+" sickle!",({targ,ETO}));
        targ->do_damage("torso",random(18)+33);
        break;

    case 4:

        tell_object(ETO,"%^BOLD%^%^RED%^You open "+targ->QCN+"'s "+
            "chest in one slicing motion with your sickle!");
        tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" opens your chest "+
            "in one slice with "+ETO->QP+" sickle!");
        tell_room(EETO,"%^BOLD%^%^RED%^"+targ->QCN+"'s chest opens "+
            "with a gaping wound from "+ETOQCN+"'s sickle!",({targ,ETO}));
        targ->do_damage("torso",random(18)+37);
        targ->set_tripped(3,"You are trying to catch your breath from your chest being sliced!");
        break;
    }

    return roll_dice(2,6);
}
