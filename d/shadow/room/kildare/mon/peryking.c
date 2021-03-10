#include <std.h>
#include "../kildare.h"
inherit MON "peryton";

void create()
{
    object ob;
    ::create();
    set_name("Peryton King");
    set_short("Peryton King");
    set_id(({ "king", "peryton", "peryton king", "Peryton King", "magical beast"  }));
    set_long(
        "This twisted creature is surely the stuff of nightmares.  Seemingly " +
        "a giant, %^RESET%^%^GREEN%^dark green %^CYAN%^eagle with a twenty foot " +
        "wingspan, he has the head of a %^BLUE%^blue-black %^CYAN%^stag.  His " +
        "unearthly eyes glow an empty %^BOLD%^%^RED%^red-orange%^RESET%^%^CYAN%^, " +
        "while his wickedly sharp horns glitter %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^as " +
        "the abyss.  Contrasting sharply with the dark body, his chest is alight with " +
        "light blue feathers, and his sharp claws are %^BOLD%^%^WHITE%^bone white.  " +
        "%^RESET%^%^CYAN%^Strangely, the beast seems to cast a shadow of a humanoid " +
        "figure rather than his own shape.  This particular beast seems quite " +
        "regal and proud, standing taller than the others and wearing a ruffled " +
        "crown of white feathers on his head."
        );
    set_overall_ac(2);
    set_hd(13, 6);
    set_level(13);
    set_class("fighter");
    set_mlevel("fighter", 13);
    set_hp(random(100) + 150);
    set_max_hp(query_hp());
    set_exp(10000);
    set_max_level(15); // added by *Styx* 9/24/06
    set_mob_magic_resistance("average");
    set_attacks_num(2);
    set_funcs(({ "gore", "screech" }));
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("peryton talon");
    ob->move(TO);
}

void screech(object targ)
{
    if (!"daemon/saving_d"->saving_throw(targ, "spell", -2)) {
        tell_object(targ, "%^MAGENTA%^The peryton screeches with rage, freezing you in place!");
        tell_room(ETO, "%^MAGENTA%^You cringe in terror as the peryton screeches and " +
                  "" + targ->query_cap_name() + " freezes in place!%^RESET%^", targ);
        targ->set_paralyzed(3, "You're frozen in terror from the peryton's screech!");
        return 1;
    }else {
        tell_object(targ, "%^MAGENTA%^The peryton screeches but you steel your nerve and " +
                    "continue the fight!%^RESET%^");
        tell_room(ETO, "%^MAGENTA%^" + targ->query_cap_name() + " looks grim after the " +
                  "peryton's chilling screech.", targ);
        return 1;
    }
}

void die(mixed ob)
{
    object obj;
    switch (random(4)) {
    case 0:  new(OBJ "peryvial")->move(TO);

    //   break;  let them have both on a roll of 0... *Styx* 9/24/06
    case 1:  new(OBJ "talon")->move(TO);   // adding another chance of this 9/24/06
        break;

    case 2:  new(OBJ "heart")->move(TO);

    // break;   let them have both on a roll of 2 *Styx*
    case 3:  new(OBJ "antler")->move(TO);
        break;
    }
    switch (random(5)) {
    case 0:  obj = new("/d/deku/armours/ring_p");
        obj->remove_property("enchantment");
        obj->set_property("enchantment", 1);
        obj->move(TO);
        break;

    case 1:  obj = new("/d/deku/armours/ring_p");
        obj->remove_property("enchantment");
        obj->set_property("enchantment", 2);
        obj->move(TO);
        break;

    case 2:  obj = new("/d/common/obj/armour/bracers");
        obj->set_property("enchantment", 2);
        obj->move(TO);
        break;

    case 3:  obj = new("/d/common/obj/armour/bracers");
        obj->set_property("enchantment", 1);
        obj->move(TO);

    //  break;  swapped the order so +1 bracers have a chance of the crown too
    case 4:  new(OBJ "feathercrown")->move(TO);
        break;
    }
    tell_room(ETO, "%^BOLD%^%^MAGENTA%^The peryton screeches in " +
              "terror as it falls lifeless to the ground!");
    ::die(ob);
}
