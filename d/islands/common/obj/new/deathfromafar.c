//Reskinned Bonestripper by Odin - turned into a longbow
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/lrweapon/longbow";

void create()
{
    ::create();
    set_obvious_short("%^BOLD%^%^BLACK%^aged %^RESET%^%^ORANGE%^y%^RED%^e%^ORANGE%^w longbow%^RESET%^");
    set_name("Liluminel - Death from Afar");
    set_short("%^RESET%^%^ORANGE%^L%^RED%^i%^ORANGE%^lum%^RED%^i%^ORANGE%^nel - %^BOLD%^%^BLACK%^D%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^%^BLACK%^h %^RESET%^%^ORANGE%^From Afar%^RESET%^");
    set_id(({ "bow", "longbow", "yew longbow", "death bow", "liluminel", "liluminel - death from afar", "klauthbow", "death arrow" }));;
    set_long("%^RESET%^This is a mastercrafted longbow made from a single piece of carefully carved %^BOLD%^%^BLACK%^aged %^RESET%^%^ORANGE%^y%^RED%^e%^ORANGE%^w%^RESET%^.  It bears a %^RESET%^%^MAGENTA%^gentle %^RESET%^curve to its center, and where it curls back upon itself at each end  When properly strung, its total length is just under five feet from tip to tip.  The bow grows in thickness towards the center, allowing a proper balance between %^RESET%^%^RED%^tension %^RESET%^and %^BOLD%^%^RED%^compression%^RESET%^.  %^YELLOW%^Ornate bands %^RESET%^of very thin %^BOLD%^%^WHITE%^mithril %^RESET%^are positioned on either side of the grip as well atop either end where it is strung.  The bands themselves are engraved with ornate, %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^WHITE%^-%^RESET%^%^GREEN%^l%^BOLD%^i%^RESET%^%^GREEN%^k%^BOLD%^e %^RESET%^motifs that crawl their way along the metal.  The reverse-twisted bowstring, made from a combination of %^BOLD%^%^GREEN%^hemp %^RESET%^and %^BOLD%^%^WHITE%^linen%^RESET%^, appears %^BOLD%^%^MAGENTA%^enchanted %^RESET%^against %^BOLD%^%^BLUE%^moisture%^RESET%^.  Overall this weapon is one of the highest quality bows you have ever laid eyes upon.");
    set_lore("Legends say this longbow was made by the elven bowyer Daratrine Glynmyar in the year 450SG.  She was widely regarded as a once-in-a-generation talent when it came to shaping wood into instruments of death.  This is one of her finest works, supposedly made for Thasinia Elalee, an Arcane Archer in the corps at Ashta'Rathai.  Thasinia went missing sometime around the year 537SG, rumored to have been taken down by a swarm of invaders.  Neither her body nor her weapon were ever found.  Legends also state that enchantments placed on the bow allow its weilder to %^BOLD%^%^WHITE%^<configure> %^RESET%^its ammunition to either be %^BOLD%^%^RED%^normal%^RESET%^, %^BOLD%^%^WHITE%^silver%^RESET%^, or %^BOLD%^%^BLACK%^cold iron%^RESET%^.");
    set_value(250000);
    set_property("enchantment", 7);
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    set_item_bonus("dexterity", 6);
    set_property("lore difficulty", 27);
    set_property("no alter", 1);
    set_property("no curse", 1);
    set_property("able to cast", 1); //elven weapon, get over it
    set_lrhit((: TO, "hitme" :));
    set_wield((: TO, "wieldme" :));
    set_unwield((: TO, "unwieldme" :));
    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_ammo("death arrow");
}

void init()
{
    ::init();
    add_action("ammo_fun", "configure");
    if (!userp(ETO)) {
        return;
    }
}

int use_shots()
{
    return 1;
}

int query_shots()
{
    return -1;
}

string query_ammo_type()
{
    return "death arrow";
}

int wieldme()
{
    if (ETO->query_property("master weapon")) {
        tell_object(ETO, "You find it impossible to lift two such mighty weapons!", ETO);
        return 0;
    }
    tell_room(EETO, ETOQCN + " %^RESET%^%^ORANGE%^wields the longbow and seems filled with a %^BOLD%^%^RED%^hunter's instinct%^RESET%^%^ORANGE%^.%^RESET%^", ETO);
    tell_object(ETO, "%^RESET%^%^ORANGE%^As you wield the longbow, you are filled with a %^BOLD%^%^%^RED%^hunter's instinct%^RESET%^%^ORANGE%^.%^RESET%^");
    ETO->set_property("master weapon", 1);
    return 1;
}

int unwieldme()
{
    tell_room(EETO, "%^RESET%^%^ORANGE%^" + ETOQCN + " unwields the longbow and the %^BOLD%^%^RED%^hunter's instinct %^RESET%^leaves " + ETO->QO + ".", ETO);
    tell_object(ETO, "%^RESET%^%^ORANGE%^As you unwield the longbow, you feel the %^BOLD%^%^RED%^hunter's instinct %^RESET%^%^ORANGE%^imparted by the bow leave.%^RESET%^");
    ETO->set_property("master weapon", -1);
    return 1;
}

int special_damage()
{
    int sdamage;
    sdamage = roll_dice(TO->query_wc_num(), TO->query_wc_dice()) + (int)TO->query_property("enchantment") + (int)ETO->query_damage_bonus() + (int)BONUS_D->new_damage_bonus(ETO, ETO->query_stats("dexterity"));
    return sdamage;
}

int hitme(object targ)
{
    object* attackers, room;
    int i;
    attackers = ETO->query_attackers();
    attackers = filter_array(attackers, "is_non_immortal", FILTERS_D);

    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }
    if (random(1000) > 600) { //this might need tweaking
        switch (random(10)) {
        case 0..4:  //Causes a free extra hit that ignores 10 DR.
            tell_room(EETO, "%^BOLD%^%^RED%^" + ETOQCN + "'s arrow %^WHITE%^pierces %^WHITE%^through armor and flesh, coming %^WHITE%^clean out %^RED%^the other side!%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^%^RED%^Your arrow %^WHITE%^pierces %^RED%^through " + targ->QCN + "'s armor and flesh, coming %^WHITE%^clean out %^RED%^the other side!%^RESET%^");
            TO->set_property("magic", 1);
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            TO->set_property("magic", -1);
            break;

        case 5..6: //double damage special, ignores 10 DR. really short trip duration
            tell_room(EETO, "%^BOLD%^%^CYAN%^" + ETO->QCN + " quickly knocks two arrows and looses them at " + targ->QCN + ". The shots land true and knock " + targ->QO + " off balance.", ETO);
            tell_object(ETO, "%^BOLD%^%^CYAN%^You quickly knock two arrows and loose them at " + targ->QCN + ". The shots land true and knock " + targ->QO + " off balance.");
            TO->set_property("magic", 1);
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            TO->set_property("magic", -1);
            targ->set_tripped(random(4) + 1, "%^RED%^You are trying to get back to the feet after taking two arrows at once!%^RESET%^");
            break;

        case 7..8:  //Esentially a free cleave attack that ignores 10DR, help from Yves on this
            tell_room(EETO, "%^ORANGE%^" + ETOQCN + " drops low and unleashes a flurry of shots from " + ETO->QP + " bow in a wide arc, %^BOLD%^%^RED%^striking %^RESET%^%^GREEN%^multiple targets at once!%^RESET%^", ETO);
            tell_object(ETO, "%^ORANGE%^You drop low and unleash a fury of shots in a wide arc, %^BOLD%^%^RED%^striking %^RESET%^%^GREEN%^multiple targets!%^RESET%^");
            for (i = 0; i < sizeof(attackers); i++) {
                TO->set_property("magic", 1);
                attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), TO->special_damage(), TO->query_damage_type());
                TO->set_property("magic", -1);
            }
            break;

        case 9:
            tell_room(EETO, "%^RESET%^%^CYAN%^%^" + ETOQCN + " moves with the uncanny speed and begins performing a string of furious shots!%^RESET%^", ETO);
            tell_object(ETO, "%^RESET%^%^CYAN%^The insight granted by the bow grants you uncanny speed, and you let loose a series of furious shots!%^RESET%^");
            ETO->execute_attack();
            if (!random(2)) {
                ETO->execute_attack();
            }
            if (!random(20)) {
                ETO->execute_attack();
            }
            break;
        }
    }
    return 1;
}

int ammo_fun(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "silver" && str != "cold iron" && str != "normal") {
        return notify_fail("The bow cannot use that type of ammunition!");
    }
    if (!TO->query_wielded()) {
        return notify_fail("You must wield the bow to configure its ammunition!");
    }
    set_special_mat(str);
    tell_object(ETO, "%^ORANGE%^You ready your bow to use %^BOLD%^%^WHITE%^" + str + " %^RESET%^%^ORANGE%^arrows.%^RESET%^");
    return 1;
}

void set_special_mat(string ammostring)
{
    switch (ammostring) {
    case "silver":
        TO->set_special_material_type("silver");
        break;

    case "cold iron":
        TO->set_special_material_type("cold iron");
        break;

    case "normal":
        TO->set_special_material_type("piercing");
        break;
    }
}
