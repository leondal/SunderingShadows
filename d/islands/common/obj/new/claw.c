#include <std.h>

inherit "/d/common/obj/weapon/claw.c";


void create()
{
    ::create();

    set_id(({"claw","gauntlet","clawed gauntlet","the reaver","reaver"}));

    set_name("clawed gauntlet");

    set_obvious_short("A clawed gauntlet");

    set_short("%^BOLD%^%^BLUE%^Th%^RESET%^%^BLUE%^e %^BOLD%^%^BLACK%^Re%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^v%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^");

    set_long(
        "%^RESET%^%^BLUE%^This gauntlet is is dark blue in color. It is made of supple leather"+
        " which is designed to create a tight fit. The gauntlets are cut off at the knuckles"+
        " in all five finger slots. Set into top of the gauntlets in a set of four"+
        " %^RESET%^%^RED%^wicked%^RESET%^%^BLUE%^ looking %^RESET%^blades%^RESET%^%^BLUE%^."+
        " Each blade is about nine inches and all curve slightly. Overall"+
        " It gives the impression of a weapon that can cut through bone as if it was butter.");

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("armor bonus",5);
    set_item_bonus("damage bonus",7);

    set_value(90000);

    set_wield((:TO,"wieldit":));
    set_hit((:TO,"hitit":));

    set_lore("Who made this claw is not known. Many rumors exist, but none are definate. What is known is that the red dragon "
        "Klauth acquired the claw from a demon after their shaken alliance turned violent. Klauth has kept the claw as a "
        "momento, until it was taken from his lair recently.");

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wieldit()
{
    tell_object(ETO,"%^BOLD%^%^BLUE%^You slide your hand into the gauntlet and get a feel for the %^BOLD%^%^WHITE%^blades%^RESET%^.%^RESET%^");
    return 1;
}


int hitit(object targ)
{
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;

    if(random(1000) < 400)
    {
        switch(random(4))
        {
        case 0:

            tell_object(ETO,"%^BOLD%^%^RED%^You slash deeply across "+targ->QCN+"'s flesh with the %^BOLD%^%^WHITE%^claws %^BOLD%^%^RED%^of the gauntlet!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+" cuts deep into your flesh with the claws of a gauntlet!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^RED%^" +ETO->QCN+" deeply slashes into "+targ->QCN+"'s flesh with "+ETO->QP+" clawed gauntlet!%^RESET%^",({ETO,targ}));
            return roll_dice(6,6)+50;

        case 1:

            tell_object(ETO,"%^BOLD%^%^BLUE%^You clench your fist and jab hard into "+targ->QCN+"'s gut with the %^BOLD%^%^WHITE%^claws %^BOLD%^%^BLUE%^of the gauntlet!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" growls and jabs deep into your gut with the claws of a gauntlet!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLUE%^" +ETO->QCN+" drives the claws deep into "+targ->QCN+"'s gut!%^RESET%^",({ETO,targ}));
            return roll_dice(6,6)+50;

        case 2:

            tell_object(ETO,"%^RESET%^%^RED%^You feel a dark rage come over you as begin to rip, tear, and claw with a ferocity you have never felt before!%^RESET%^");
            tell_object(targ,"%^RESET%^%^RED%^"+ETO->QCN+" is overcome with a dark rage and begins to rip, claw, and tear with fervor!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^RED%^" +ETO->QCN+" is overcome with a dark rage and begins to rip, claw, and tear with fervor!%^RESET%^",({ETO,targ}));
            return roll_dice(6,6)+50;

        case 3:

            tell_object(ETO,"%^RESET%^%^BLUE%^You loose feeling in your hand, then most of your arm, before being revitalized with a boost of strength, almost causing your opponent to loose balance!%^RESET%^");
            tell_object(targ,"%^RESET%^%^BLUE%^"+ETO->QCN+" almost knocks you off your feet with a powerful blow that seemed to come out of nowhere!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^BLUE%^" +ETO->QCN+" almost knocks the target off balance with supernatural strength!%^RESET%^",({ETO,targ}));
            return roll_dice(6,6)+50;
        }
    }
    return roll_dice(3,6);
}
