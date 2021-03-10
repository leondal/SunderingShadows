#include <std.h>
#include <daemons.h>
//cloned from Battleaxe of the Dominion.  If someone is better at writing specials than I am, feel free to change.  This is meant to be our top end Elven Curved Blade - Odin
//Updated to be base silver damage type.  It's made of mithril, after all
//Updated to use universal special damage function and remove overlapping specials.
inherit "/d/common/obj/weapon/elvencurvedblade.c";


void create()
{
    ::create();
    set_name("Indrasil - The Godslayer");
    set_id(({ "Indrasil - The Godslayer", "elven curved blade", "blade", "sword", "indrasil", "godslayer", "mithril blade", "mithril sword", "mithril elven curved blade", "ornate blade", "ornate sword", "ornate curved blade", "ornate mithril curved blade" }));
    set_short("%^BOLD%^%^BLACK%^Ind%^WHITE%^ra%^BOLD%^%^BLACK%^sil %^BOLD%^%^WHITE%^- %^BOLD%^%^BLACK%^The G%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^d%^RESET%^%^WHITE%^s%^BOLD%^%^BLACK%^l%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^y%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^r%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^An %^BOLD%^%^BLACK%^or%^BOLD%^%^WHITE%^nat%^BOLD%^%^BLACK%^e %^WHITE%^mithril elven curved blade%^RESET%^");
    set_long("%^BOLD%^%^YELLOW%^The sword is elegant, intricate, and ornate.%^RESET%^ The blade is flat and impossibly sharp on its cutting edge, and it curves sharply, almost like a cross between a katana and scimitar. As you turn the surprisingly light blade, the %^RESET%^%^BOLD%^%^WHITE%^mithril%^RESET%^ glimmers blue and silver in the light, and you notice that the entire blade is covered in %^RESET%^%^BOLD%^%^GREEN%^ancient elven calligraphy%^RESET%^. The pommel's grip is wrapped in slightly worn, %^GREEN%^inky green silk%^RESET%^. At the end of the sword's pommel is a %^BOLD%^%^WHITE%^mithril%^RESET%^ snake with flashing %^RESET%^%^BOLD%^%^BLUE%^sapphire%^RESET%^ eyes, seemingly poised to strike.  You are quite sure you've never seen a weapon that's of higher quality.");
    set_lore("%^CYAN%^This sword was made by Niasos Eelvim, perhaps the greatest elven bladesmith the world has ever known.  Eelvim, tired of creating implements of destruction, had gone into retirement and opened a bakery.  He was persuaded to forge this final piece by an elven maiden named Aravae Keymyar, who set out on a quest for revenge against those that had, on her wedding day, murdered her family, husband to be, and unborn child.  Upon presenting the weapon to Keymyar, Eelvim spoke thus:  %^BOLD%^%^WHITE%^'I've done what I swore an oath to the gods one hundred fifty-eight years ago to never do again. I've created something that kills people. And in that purpose, I was a success. I've done this because, philosophically, I'm sympathetic to your aim. I can tell you, with no ego, this is my finest sword. If, on your journey, you should encounter the gods, the gods themselves will be cut.' %^RESET%^%^CYAN%^Eelvim never again made another sword.%^RESET%^");
    set_language("elven");
    set_read("%^RESET%^%^GREEN%^You will be but a mortal, not a god, in the hands of the one that slays you.%^RESET%^");
    set("value", 150000);
    set_property("no curse", 1);
    set_property("enchantment", 7);
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    set_item_bonus("armor bonus", 4);
    set_special_material_type("silver");

    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
}

int extra_wield()
{
    string quest = "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^";
    if (!objectp(TO) || !objectp(ETO)) {
        return 0;
    }

    if (avatarp(ETO)) {
        return 1;
    }

    if ((int)ETO->query_level() < 35) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^As you try to wield the weapon, a presence descends upon you.  It whispers: %^RESET%^%^GREEN%^You are not worthy. %^BOLD%^%^WHITE%^before fading away.%^RESET%^");
        return 0;
    }

    if (ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
        tell_object(ETO, "You find it impossible to lift two such mighty weapons!", ETO);
        return 0;
    }

    if (member_array(quest, ETO->query_mini_quests()) == -1 && member_array("Achieved: " + quest, ETO->query_mini_quests()) == -1) {
        write("%^MAGENTA%^You have not yet earned the right to wield such a weapon.");
        return 0;
    }

    ETO->set_property("master weapon", 1);
    tell_object(ETO, "%^BOLD%^%^WHITE%^You take the ornate elven curved blade in your hands and realize you will never wield a more finely crafted weapon.%^RESET%^");
    tell_room(EETO, "%^WHITE%^" + ETO->QCN + " grasps the ornate elven curved blade.%^RESET%^", ETO);
    return 1;
}

int extra_unwield()
{
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }

    tell_object(ETO, "%^GREEN%^You release the ornate elven curved blade and miss its presence immediately.");
    ETO->set_property("master weapon", -1);
    tell_room(EETO, "%^GREEN%^" + ETO->QCN + " seems sad as " + ETO->QS + " release the ornate elven curved blade.", ETO);
    return 1;
}

int special_damage()
{
    int sdamage;
    string bonus_stat;
    int mysize;
    mysize = (int)ETO->query_size();
    if (mysize == 1) {
        mysize++;             //run small creatures as normal size please.
    }
    mysize -= (int)TO->query_size();
    if (FEATS_D->usable_feat(ETO, "weapon finesse") && (mysize >= 0)) { // if has-feat & weapon is smaller than/equal to user
        bonus_stat = "dexterity";
    }else {
        bonus_stat = "strength";
    }
    sdamage = TO->query_wc() + (int)TO->query_property("enchantment") + (int)ETO->query_damage_bonus() + (int)BONUS_D->new_damage_bonus(ETO, ETO->query_stats(bonus_stat));
    return sdamage;
}

int extra_hit(object targ)
{
    int rand, size;
    object head;
    rand = roll_dice(1, 12);

    if (!objectp(targ)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    if (!objectp(EETO)) {
        return 0;
    }

    if (random(1000) > 600) {
        switch (random(11)) {
        case 0..3:
            tell_object(ETO, "%^BOLD%^You spin the elven curved blade quickly and turn your body, using the momentum to deliver a devastating blow on " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^BOLD%^" + ETO->QCN + " spins " + ETO->QP + " elven curved blade quickly and turns " + ETO->QP + " body, using the momentum to hit you with devastating force!%^RESET%^");
            tell_room(EETO, "%^BOLD%^" + ETO->QCN + " spins " + ETO->QP + " elven curved blade quickly and turns " + ETO->QP + " body, using the momentum to hit " + targ->QCN + " with a devastating blow!%^RESET%^", ({ targ, ETO }));
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            break;

        case 4..5: // between 3 and 5 or 30%
            tell_object(ETO, "%^GREEN%^With uncanny precision, you bring your elven curved blade down on " + targ->QCN + " in a deadly overhead chop!%^RESET%^");
            tell_object(targ, "%^GREEN%^With uncanny precision, " + ETO->QCN + " brings " + ETO->QP + " elven curved blade down on you in a deadly overhead chop!%^RESET%^");
            tell_room(EETO, "%^GREEN%^With uncanny precision, " + ETO->QCN + " brings " + ETO->QP + " elven curved blade down on " + targ->QCN + " in a deadly overhead chop!%^RESET%^", ({ targ, ETO }));
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage() * 2, TO->query_damage_type());
            break;

        case 6..7:
            tell_object(ETO, "%^CYAN%^You twirl the elven curved blade quickly and send the flat of the blade down low, sweeping under " + targ->QCN + " and knocking " + targ->QO + " down!%^RESET%^");
            tell_object(targ, "%^CYAN%^" + ETO->QCN + " twirls the elven curved blade quickly and sends the flat of the blade down, sweeping under you and knocking you down!%^RESET%^");
            tell_room(EETO, "%^CYAN%^" + ETO->QCN + " twirls the elven curved blade quickly and sends the flat of the blade down low, sweeping under " + targ->QCN + " and knocking " + targ->QP + " down!%^RESET%^", ({ targ, ETO }));
            targ->set_paralyzed(roll_dice(1, 10) + 10, "%^GREEN%^You are struggling to stand up!%^RESET%^");
            break;

        case 8..9:
            tell_object(ETO, "%^RESET%^%^BOLD%^%^BLUE%^You snap the flat of one the blade down atop " + targ->QCN + "'s head and use the force of the rebound to launch another attack!%^RESET%^");
            tell_object(targ, "%^RESET%^%^BOLD%^%^BLUE%^" + ETO->QCN + " snaps the flat of the blade blade down atop your head and uses the force of the rebound to launch two more attacks!%^RESET%^");
            tell_room(EETO, "%^RESET%^%^BOLD%^%^BLUE%^" + ETO->QCN + " snaps the flat of the blade down atop " + targ->QCN + "'s head and uses the force of the rebound to launch two more attacks!%^RESET%^", ({ targ, ETO }));
            if (sizeof(ETO->query_attackers())) {
                ETO->execute_attack();
                ETO->execute_attack();
            }
            break;

        case 10:
            if ((member_array("neck", targ->query_limbs()) != -1) && !random(10) && !targ->reflex_save(50) && !targ->query_property("no death") && !FEATS_D->usable_feat(targ, "death ward")) { //increased reflex save to 50 so everyone doesn't autopass it
                tell_object(ETO, "%^BOLD%^%^RED%^You drop to one knee and snap the elven curved blade in a deadly upwards arc!%^RESET%^");
                tell_object(ETO, "%^BOLD%^%^BLUE%^You can see the blade sink cleanly into " + targ->QCN + "'s neck and pass through almost without resistance.%^RESET%^");
                tell_object(ETO, "%^B_RED%^%^BOLD%^%^WHITE%^" + targ->QCN + "'s head falls away and " + targ->QP + " body drops lifelessly to the ground.%^RESET%^");
                tell_object(targ, "%^BOLD%^RED%^%^RED%^" + ETO->QCN + " drops to one knee and snaps the elven curved blade in a deadly upwards arc!%^RESET%^");
                tell_object(targ, "%^BLUE%^You grimace and then open your eyes in sudden stark terror as you feel the bite of the blade entering your neck!%^RESET%^");
                tell_object(targ, "%^B_RED%^%^BOLD%^%^WHITE%^Your world tumbles and then stops as you roll to spot on the ground, just in time to see your body fall next to you!%^RESET%^");
                tell_object(targ, "%^B_BLUE%^%^BOLD%^%^BLACK%^" + ETO->QCN + " just cut off your head...blackness overtakes you as you watch your body twitching on the ground.%^RESET%^");
                tell_room(EETO, "%^RED%^" + ETO->QCN + " drops to one knee and snaps the elven curved blade in a deadly upwards arc!%^RESET%^", ({ targ, ETO }));
                tell_room(EETO, "%^RED%^You can see the blade of " + ETO->QCN + "'s sword sink cleanly into " + targ->QCN + "'s neck and pass cleanly through!%^RESET%^", ({ targ, ETO }));
                tell_room(EETO, "%^B_RED%^%^BOLD%^%^WHITE%^" + targ->QCN + "'s head falls away and " + targ->QP + " body drops lifelessly to the ground!%^RESET%^", ({ targ, ETO }));
                head = new("/std/obj/body_part.c");
                head->set_limb(targ->QCN, "head");
                ETO->set_property("noMissChance", 1);
                targ->set_hp(-1 * roll_dice(100000, 100000));
                targ->cause_typed_damage(targ, "neck", roll_dice(500000, 500000), TO->query_damage_type());
                ETO->set_property("noMissChance", 1);
                head->move(EETO);
                break;
            }
            tell_object(ETO, "%^BOLD%^%^RED%^You drop to one knee and snap the elven curved blade in a deadly upwards arc!%^RESET%^");
            tell_object(ETO, "%^BOLD%^%^BLUE%^%^BLUE%^At the last instant, " + targ->QCN + " manages to dodge out of the way, avoiding the fatal strike!%^RESET%^");
            tell_object(ETO, "%^GREEN%^The blade slices across " + targ->QCN + "'s eyes, blinding " + targ->QO + "!%^RESET%^");

            tell_object(targ, "%^BOLD%^%^RED%^" + ETO->QCN + " drops to one knee and snaps the elven curved blade in a deadly upwards arc!%^RESET%^");
            tell_object(targ, "BOLD%^%^BLUE%^%^BLUE%^At the last instant, you manage to dodge out of the way, avoiding the fatal strike!%^RESET%^");
            tell_object(targ, "%^GREEN%^The blade slices across your eyes, blinding you!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^RED%^%^RED%^" + ETO->QCN + " drops to one knee and snaps the elven curved blade in a deadly upwards arc!%^RESET%^", ({ targ, ETO }));
            tell_room(EETO, "%^BOLD%^%^BLUE%^At the last instant, " + targ->QCN + " manages to dodge out of the way, avoiding the fatal strike!%^RESET%^", ({ targ, ETO }));
            tell_room(EETO, "%^GREEN%^The blade slices across " + targ->QCN + "'s eyes, blinding " + targ->QO + ".%^RESET%^", ({ targ, ETO }));

            targ->set_paralyzed(roll_dice(1, 4) * 8, "%^CYAN%^You are in too much pain to do anything!%^RESET%^");
            if (!targ->will_save(40)) {
                targ->set_temporary_blinded(roll_dice(1, 4));
            }
            break;
        }
    }
    return 0;
}
