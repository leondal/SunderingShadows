#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/butchering_axe.c";


void create()
{
    ::create();
    set_name("Battleaxe of the Dominion");
    set_id(({ "Battleaxe of the Dominion", "battleaxe", "axe", "dominion axe", "axe of the dominion", "dominion battleaxe", "double axe", "double bladed axe" }));
    set_short("%^BLUE%^Battleaxe of the %^RED%^Dominion%^RESET%^");
    set_obvious_short("%^BLUE%^a massive dark%^RESET%^-%^RED%^bladed %^RESET%^%^BOLD%^double-%^BLUE%^axe%^RESET%^");

    set_long("%^BLUE%^This massive double-bladed %^RED%^axe%^BLUE%^ is forged from some sort of %^RESET%^material%^BLUE%^ that is almost "
             "impossibly light weight.  It gives the axe a heft that rivals much lighter %^MAGENTA%^blades%^BLUE%^.  Two double-bladed axe heads "
             "rest on either end of a %^RESET%^%^BOLD%^long %^YELLOW%^haft%^RESET%^%^BLUE%^.  Each of the axe heads is a %^RESET%^crecent "
             "%^BOLD%^moon %^RESET%^%^BLUE%^shape, longer towards the point, almost sword-like, while thicker and more rounded towards the "
             "base of the axe head.  The axe heads are thin and are shaped so that %^CYAN%^wind%^BLUE%^ resistance passing over them allows "
             "the wielder the ability to alter the direction of his swings with hardly more than the twist of a wrist.  The %^RESET%^%^BOLD%^shaft "
             "%^RESET%^%^BLUE%^of the axe is made of an %^RESET%^%^BOLD%^%^BLACK%^inky material%^RESET%^%^BLUE%^ that fluctuates between the "
             "darkest black and midnight blue.  Dark shapes can be seen swirling inside the material and it has an almost %^BOLD%^%^BLACK%^oily "
             "%^RESET%^%^BLUE%^texture to the touch.  A %^YELLOW%^handgrip%^RESET%^%^BLUE%^ has been fashioned onto the center of the haft to allow for "
             "a firm grasp of the %^RED%^weapon%^BLUE%^.  The handgrip looks to be made of some kind of ancient "
             "%^YELLOW%^hide%^RESET%^%^BLUE%^.  Even though the hide is clearly %^RESET%^%^BOLD%^ancient%^RESET%^%^BLUE%^, it is still soft and supple "
             "as if it were tanned only yesterday.  Whatever enchantment protects this weapon must be powerful indeed.%^RESET%^");

    set_lore("%^CYAN%^Little is known about this devestating weapon.  "
             "It is said to have once belonged to a great warrior god who lead a "
             "distant empire.  The Battleaxe of the Dominion has changed hands many "
             "times.\n"
             "It has been present at some of the bloodiest battles in history and "
             "carries many memories.");

    set_weight(5);
    set("value", 150000);
    set_property("no curse", 1);
    set_property("enchantment", 6);

    set_item_bonus("strength", 4);
    set_item_bonus("constitution", 4);
    set_item_bonus("armor bonus", 4);

    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
    set_weapon_prof("exotic");
}

void init()
{
    int num;
    ::init();
    if (interactive(ETO) && !avatarp(ETO)) {
        tell_object(ETO, "%^RED%^The axe magically shifts to fit " +
                    "perfectly in your hands.%^RESET%^");
        num = (int)ETO->query_size() + 1;
        set_size(num);
        switch (num) { //normalizing this as per what a double axe
        case 2:
            set_wc(1, 10);
            set_large_wc(1, 10);
            break;

        case 3:
            set_wc(2, 8);
            set_large_wc(2, 8);
            break;

        case 4:
            set_wc(3, 8);
            set_large_wc(3, 8);
            break;
        }
    }
}

int extra_wield()
{
    string quest = "%^RESET%^%^YELLOW%^Returned the Dominion Warrior to eternal rest.%^RESET%^";
    if (!objectp(TO) || !objectp(ETO)) {
        return 0;
    }

    if (avatarp(ETO)) {
        return 1;
    }

    if ((int)ETO->query_level() < 40) {
        tell_object(ETO, "%^BOLD%^%^RED%^A shadowy presence tells you: %^RESET%^You pathetic little fool, you cannot handle such power!");
        return 0;
    }
    if (ETO->query_name() == "Cruiser Tetron") {
        return 1;
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
    tell_object(ETO, "%^BLUE%^Ancient forces are at work here...  Be wary. ");
    tell_object(ETO, "%^RED%^You tightly grasp the ancient double axe.");
    tell_room(EETO, "%^RED%^" + ETO->QCN + " tightly grasps the ancient double axe.%^RESET%^", ETO);
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

    tell_object(ETO, "%^GREEN%^You shudder as you release the ancient double axe.");
    ETO->set_property("master weapon", -1);
    tell_room(EETO, "%^GREEN%^" + ETO->QCN + " shudders as " + ETO->QS + " release the ancient double axe.", ETO);
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
    rand = roll_dice(1, 10);

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
            tell_object(ETO, "%^GREEN%^You spin the heavy axe quickly and turn your body, using the momentum to deliver a devastating blow on " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^GREEN%^" + ETO->QCN + " spins " + ETO->QP + " heavy axe quickly and turns " + ETO->QP + " body, using the momentum to hit you with devastating force!%^RESET%^");
            tell_room(EETO, "%^GREEN%^" + ETO->QCN + " spins " + ETO->QP + " heavy axe quickly and turns " + ETO->QP + " body, using the momentum to hit " + targ->QCN + " with a devastating blow!%^RESET%^", ({ targ, ETO }));
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            break;

        case 4..5: // between 3 and 5 or 30%
            tell_object(ETO, "%^RED%^You roar as you bring one end of the ancient double axe down on " + targ->QCN + " in a deadly overhead chop!%^RESET%^");
            tell_object(targ, "%^RED%^" + ETO->QCN + " roars as " + ETO->QS + " brings one end of " + ETO->QP + " ancient double axe down on you in a deadly overhead chop!%^RESET%^");
            tell_room(EETO, "%^RED%^" + ETO->QCN + " roars as " + ETO->QS + " brings one end of " + ETO->QP + " ancient double axe down on " + targ->QCN + " in a deadly overhead chop!%^RESET%^", ({ targ, ETO }));
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage() * 150 / 100, TO->query_damage_type());
            break;

        case 6..7:
            tell_object(ETO, "%^CYAN%^You twirl the massive axe quickly and send the haft down low, sweeping under " + targ->QCN + " and knocking " + targ->QO + " down!%^RESET%^");
            tell_object(targ, "%^CYAN%^" + ETO->QCN + " twirls the massive axe quickly and sends the haft down low, sweeping under you and knocking you down!%^RESET%^");
            tell_room(EETO, "%^CYAN%^" + ETO->QCN + " twirls the massive axe quickly ands sends the haft down low, sweeping under " + targ->QCN + " and knocking " + targ->QP + " down!%^RESET%^", ({ targ, ETO }));
            targ->set_paralyzed(roll_dice(1, 10) + 10, "%^GREEN%^You are struggling to stand up!%^RESET%^");
            break;

        case 8..9:
            tell_object(ETO, "%^RESET%^%^BOLD%^You snap the flat of one axe blade down atop " + targ->QCN + "'s head and use the force of the rebound to launch another attack!%^RESET%^");
            tell_object(targ, "%^RESET%^%^BOLD%^" + ETO->QCN + " snaps the flat of one axe blade down atop yourhead and uses the force of the rebound to launch two more attacks!%^RESET%^");
            tell_room(EETO, "%^RESET%^%^BOLD%^" + ETO->QCN + " snaps the flat of one axe blade down atop " + targ->QCN + "'s head and uses the force of the rebound to launch two more attacks!%^RESET%^", ({ targ, ETO }));
            if (sizeof(ETO->query_attackers())) {
                ETO->execute_attack();
                ETO->execute_attack();
            }
            break;

        case 10:
            if ((member_array("neck", targ->query_limbs()) != -1) && !random(10) && !targ->reflex_save(50) && !targ->query_property("no death") && !FEATS_D->usable_feat(targ, "death ward")) { //increased DC to 50 to match godslayer
                tell_object(ETO, "%^RED%^You drop to one knee and snap the blade of the massive axe in a deadly upwards arc!%^RESET%^");
                tell_object(ETO, "%^BLUE%^You can see the blade sink cleanly into " + targ->QCN + "'s neck and pass through almost without resistance.%^RESET%^");
                tell_object(ETO, "%^B_RED%^" + targ->QCN + "'s head falls away and " + targ->QP + " body drops lifelessly to the ground.%^RESET%^");
                tell_object(targ, "%^RED%^" + ETO->QCN + " drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^");
                tell_object(targ, "%^BLUE%^You grimace and then open your eyes in sudden stark terror as you feel the bite of the axe entering your neck!%^RESET%^");
                tell_object(targ, "%^B_RED%^Your world thumbles and then stops as you roll to spot on the ground, just in time to see your body fall next to you!%^RESET%^");
                tell_object(targ, "%^B_BLUE%^%^BOLD%^%^BLACK%^" + ETO->QCN + " just cut off your head..  blackness overtakes you as you watch your body twitching on the ground.%^RESET%^");
                tell_room(EETO, "%^RED%^" + ETO->QCN + " drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^", ({ targ, ETO }));
                tell_room(EETO, "%^RED%^You can see the blade of " + ETO->QCN + "'s axe sink cleanly into " + targ->QCN + "'s neck and pass cleanly through!%^RESET%^", ({ targ, ETO }));
                tell_room(EETO, "%^B_RED%^" + targ->QCN + "'s head falls away and " + targ->QP + " body drops lifelessly to the ground!%^RESET%^", ({ targ, ETO }));
                head = new("/std/obj/body_part.c");
                head->set_limb(targ->QCN, "head");
                ETO->set_property("noMissChance", 1);
                targ->set_hp(-1 * roll_dice(100000, 100000));
                targ->cause_typed_damage(targ, "neck", roll_dice(500000, 500000), TO->query_damage_type());
                ETO->set_property("noMissChance", 1);
                head->move(EETO);
                break;
            }
            tell_object(ETO, "%^RED%^You drop to one knee and snap the blade of the massive axe in a deadly upwards arc!%^RESET%^");
            tell_object(ETO, "%^BLUE%^At the last instant, " + targ->QCN + " manages to dodge out of the way, avoiding the fatal strike!%^RESET%^");
            tell_object(ETO, "%^GREEN%^The axe slices across " + targ->QCN + "'s eyes, blinding " + targ->QO + "!%^RESET%^");

            tell_object(targ, "%^RED%^" + ETO->QCN + " drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^");
            tell_object(targ, "%^BLUE%^At the last instant, you manage to dodge out of the way, avoiding the fatal strike!%^RESET%^");
            tell_object(targ, "%^GREEN%^The axe slices across your eyes, blinding you!%^RESET%^");

            tell_room(EETO, "%^RED%^" + ETO->QCN + " drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^", ({ targ, ETO }));
            tell_room(EETO, "%^BLUE%^At the last instant, " + targ->QCN + " manages to dodge out of the way, avoiding the fatal strike!%^RESET%^", ({ targ, ETO }));
            tell_room(EETO, "%^GREEN%^The axe slices across " + targ->QCN + "'s eyes, blinding " + targ->QO + ".%^RESET%^", ({ targ, ETO }));

            targ->set_paralyzed(roll_dice(5, 5) + 25, "%^CYAN%^You are in too much pain to do anything!%^RESET%^");
            if (!targ->will_save(40)) {
                targ->set_temporary_blinded(roll_dice(1, 4));
            }
            break;
        }
    }
    return 0;
}
