//updated by Circe with new desc, lore, etc 6/13/04
//updated by Circe to include new specials to put it in line with other weapons
#include <std.h>
inherit "/d/common/obj/weapon/hhlance";
//inherit "std/weapon";

void create()
{
    ::create();
    set_name("lance of darkness");
    set_id(({ "lance", "darkness", "lance of darkness" }));
    set_obvious_short("%^BOLD%^%^BLACK%^heavy darksteel lance%^RESET%^");
    set_short("%^BLUE%^Lance of Darkness%^RESET%^");
    set_long(
        "%^BOLD%^%^BLACK%^Fashioned of light-weight %^RESET%^" +
        "darksteel%^BOLD%^%^BLACK%^, this exquisite lance has " +
        "been carved with images of dark %^RESET%^%^BLUE%^" +
        "storm clouds %^BOLD%^%^BLACK%^that seem to roll across " +
        "the surface of the lance as if enchanted.  Near the " +
        "tip of the lance, %^YELLOW%^lightning %^BLACK%^appears " +
        "under the surface, flashing and striking against " +
        "the jagged %^WHITE%^mithril tip%^BLACK%^.  The lance is " +
        "couched in a black wooden handle ringed with cabochon-cut " +
        "jet that glit%^WHITE%^t%^BLACK%^ers and seems to suck " +
        "in the light around it.%^RESET%^"
        );
    set_lore("The original Lance of Darkness was made from a " +
             "Lightning Lance corrupted at the hands of a cabal " +
             "of evil clerics.  Since then, they have perfected their " +
             "own version, this being a prime specimen.  The Lance " +
             "of Darkness requires a triumvirate of evil clerics to " +
             "create.  The method is shared between all of them, though " +
             "each faith has only bits and pieces, as none of them " +
             "fully trusts another.  It is said that when complete, " +
             "this lance can channel the malice of a deity.");
//    set_weight(15);
    set_value(1500);
//    set_wc(1,12);
//    set_large_wc(1,21);
//    set_size(1);
    set_property("enchantment", 3);
//    set_type("piercing");
//    set_prof_type("lance");
//    set_property("lance",1);
    set_wield((: TP, "wield" :));
    set_unwield((: TO, "removeme" :));
    set_hit((: TO, "check" :));
    set_special_material_type("silver");
}

int wield()
{
    if ((int)TP->query_alignment() % 3 != 1) {
        tell_room(EETO, "%^RED%^A thunderous cackle fills the air as " + ETOQCN + " wields " + ETO->QP + " lance.%^RESET%^", ETO);
        tell_object(ETO, "%^RED%^A thunderous cackle fills the air as you wield your lance.%^RESET%^");
        ETO->set_property("evil item", 1);
        return 1;
    }
    write("You are thoroughly rejected by this item.");
    return 0;
}

int removeme()
{
    ETO->set_property("evil item", -1);
    return 1;
}

int check(object targ)
{
    string deity;
    ::check(targ);
    if (!objectp(ETO)) {
        return 0;
    }
    if (!objectp(targ)) {
        return 0;
    }

    deity = (string)ETO->query_diety();
    if (!deity || deity == "pan" || deity == "Pan") {
        deity = "evil";
    }
    deity = capitalize(deity);

    if (!random(6)) {
        switch (random(6)) {
        case 0..3:
            tell_room(environment(targ), "%^BOLD%^%^BLACK%^A bolt of pure %^YELLOW%^power "
                      "%^BLACK%^shoots from " + ETOQCN + "'s lance as %^RESET%^thunder "
                      "%^BOLD%^%^BLACK%^crashes overhead!%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the might of %^BOLD%^%^BLUE%^" + deity + " "
                        "%^BLACK%^as a bolt of pure %^YELLOW%^power "
                        "%^BLACK%^shoots from your lance as %^RESET%^thunder "
                        "%^BOLD%^%^BLACK%^crashes overhead!%^RESET%^");
            return random(7);

            break;

        case 4:
            tell_room(environment(targ), "%^BOLD%^%^BLUE%^Your hair stands on end as "
                      "%^YELLOW%^electricity %^BLUE%^gathers in the air around " + ETOQCN + "'s "
                      "lance.  Suddenly the energy is released in a %^CYAN%^flash %^BLUE%^as "
                      "" + ETOQCN + " moves with unearthly speed!%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^%^BLUE%^Your hair stands on end as "
                        "%^YELLOW%^electricity %^BLUE%^gathers in the air around your "
                        "lance.  Suddenly the energy is released in a %^CYAN%^flash %^BLUE%^as "
                        "you move with unearthly speed!%^RESET%^");
            ETO->execute_attack();
            break;

        default:
            tell_room(environment(targ), "%^RESET%^%^CYAN%^Thunder %^YELLOW%^cracks "
                      "%^RESET%^%^CYAN%^from " + ETOQCN + "'s lance, sending a wave of unearthly "
                      "%^BOLD%^%^BLACK%^blackness %^RESET%^%^CYAN%^straight at "
                      "" + targ->QCN + "!%^RESET%^", ({ targ, ETO }));
            tell_object(targ, "%^RESET%^%^CYAN%^Thunder %^YELLOW%^cracks "
                        "%^RESET%^%^CYAN%^from " + ETOQCN + "'s lance, sending a wave of unearthly "
                        "%^BOLD%^%^BLACK%^blackness %^RESET%^%^CYAN%^straight at "
                        "you!%^RESET%^");
            tell_object(ETO, "%^RESET%^%^CYAN%^Thunder %^YELLOW%^cracks "
                        "%^RESET%^%^CYAN%^from your lance and you hear the voice of "
                        "" + deity + " before a wave of unearthly "
                        "%^BOLD%^%^BLACK%^blackness %^RESET%^%^CYAN%^ is released straight at "
                        "" + targ->QCN + "!%^RESET%^");
            set_property("magic", 1);
            targ->do_damage("torso", roll_dice(4, 12));
            remove_property("magic");
            break;
        }
    }
    return 0;
}

int query_size()
{
    if (objectp(ETO) && living(ETO)) {
        return (int)ETO->query_size();
    }
    return ::query_size();
}
