//Added miniquest query in lieu of ownering, clean up some code - Octothorpe 2/2/10
//dhammer.c

#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg.c";

void badStuff();

void create()
{
    ::create();
    set_name("%^RESET%^%^RED%^Great Hammer %^RESET%^%^BOLD%^%^BLACK%^" +
             "of%^RESET%^%^RED%^ Destruction%^RESET%^");
    set_id(({
        "hammer",
        "great hammer",
        "Great Hammer",
        "great hammer of destruction",
        "hammer of destruction"
    }));
    set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^An impressive " +
                      "hammer%^RESET%^");
    set_short("%^RESET%^%^RED%^Great Hammer %^RESET%^%^BOLD%^%^BLACK%^" +
              "of%^RESET%^%^RED%^ Destruction%^RESET%^");
    set_long("%^RESET%^%^BLUE%^This mighty hammer looks incredibly " +
             "%^WHITE%^ancient%^BLUE%^.  The haft of the weapon looks as " +
             "if it were once the %^RED%^heart%^BLUE%^ of a great %^RED%^" +
             "redwood%^BLUE%^ tree.  The %^RED%^redwood%^BLUE%^ has long " +
             "since become petrified, forever immortalizing the intricate " +
             "%^GREEN%^geometric runes%^BLUE%^ that are carefully engraved " +
             "into it.  Each of the %^GREEN%^glowing runes%^BLUE%^ adds to " +
             "this legendary weapon's palpable strength.  The %^BOLD%^" +
             "%^BLACK%^head%^RESET%^%^BLUE%^ of the hammer is as old and as " +
             "impressive as its haft.  An immeasurably %^YELLOW%^dense%^RESET%^" +
             "%^BLUE%^ winding of the same %^RED%^redwood heart%^BLUE%^ is " +
             "bundled together with long %^WHITE%^adamantium%^BLUE%^ rods.  " +
             "The heavy bundle is banded with thick %^BOLD%^%^WHITE%^mithril" +
             "%^RESET%^%^BLUE%^ rings that are engraved with the same " +
             "%^GREEN%^geometric symbols%^BLUE%^ that cover the haft.  " +
             "Centuries of use have flattened and bent the ends of the " +
             "%^BOLD%^%^BLACK%^hammerhead %^RESET%^%^BLUE%^back over the " +
             "bands, creating a mushroom-like shape on both ends.  The whole " +
             "weapon hums with an audible buzz of %^CYAN%^magical power%^BLUE%^.");
    set_lore("Legend has it that centuries ago a warrior named " +
             "Ictootolizot sought to bring an end to the fighting between " +
             "the scattered tribes of Tonerra and bring together all the " +
             "skills of the people to form a better civilization for all.  " +
             "He was a highly skilled warrior and he could easily defeat any " +
             "of the other tribesman in fair combat but the shaman Wicktolooto " +
             "of the island's largest tribe was feared for his use of deadly " +
             "black magics.  Ictootolizot left on a long journey across the " +
             "great waters.  No one knows exactly where he went but when he " +
             "returned he had a hammer of incredible power in his possession.  " +
             "He challenged Wicktolooto to battle and claimed that his mighty " +
             "hammer would destroy any magical protections and <smash> any " +
             "chance that the shaman had for escape.  Wicktolooto took " +
             "Ictootolizot's challenge and a great feast was prepared to " +
             "honor the occasion.  All the warriors of the gathered tribes " +
             "gorged themselves on the food, all except for Wicktolooto.  " +
             "The following day all the villagers except for Wicktolooto " +
             "came down with a horrible illness.  They were very weak and " +
             "unable to do even the most simple of things.  When it came " +
             "time for Ictootolizot and Wicktolooto's duel, the shaman calmly " +
             "explained how he had poisoned the meat and made the warriors " +
             "all sick.  The battle was easily won by Wicktolooto and "
             "some say that Ictootolizot was so enraged at the point of his " +
             "death that his spirit never left this plane and that he still " +
             "haunts the tombs of the monastery looking for items of power " +
             "that he may take his revenge on Wicktolooto with.");
    set_property("lore difficulty", 25);
    set_property("enchantment", 5);
    set_weight(20);
    set_value(50000);
    set_prof_type("hammer");
    set_hit((: TO, "hitem" :));
    set_wield((: TO, "wieldem" :));
    set_unwield((: TO, "unwieldem" :));
    set_property("master weapon", 1);
}

int wieldem()
{
    if (base_name(ETO) == "/d/islands/tonerra/mon/tombt") {
        return 1;
    }
    if ((int)ETO->query_highest_level() < 25 || member_array("Silenced the Spirit of the Catacombs, Defeated Tomb Tapper", ETO->query_mini_quests()) == -1) {
        tell_object(ETO, "You are unable to wield the massive hammer!");
        return 0;
    }
    if (ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
        tell_object(ETO, "You find it impossible to lift two such mighty weapons!", ETO);
        return 0;
    }
    ETO->set_property("master weapon", 1);
    return 1;
}

int unwieldem()
{
    ETO->set_property("master weapon", -1);
    return 1;
}

int hitem(object targ)
{
    if (!objectp(targ)) {
        return roll_dice(1, 4);
    }
    if (random(100) > 37) {
        return roll_dice(1, 4);                // same rate as ragnarok. N, 7/12.
    }
    switch (random(10)) {
    case 0..1:
        tell_room(EETO, "%^RED%^" + ETO->QCN + "'s hammer slams into " +
                  "" + targ->QCN + ", crushing " + targ->QO + " under its weight." +
                  "%^RESET%^", ({ targ, ETO }));
        tell_object(targ, "%^RED%^" + ETO->QCN + "'s hammer slams into " +
                    "you brutally and your entire body goes numb!%^RESET%^");
        tell_object(ETO, "%^RED%^You slam your hammer into " +
                    "" + targ->QCN + ", leaving " + targ->QO + " limp with " +
                    "agony!%^RESET%^");
        targ->set_paralyzed(roll_dice(2, 6), "%^RED%^You can't feel " +
                            "anything at all!%^RESET%^");
        return roll_dice(2, 6);

    case 2..3:
        tell_room(EETO, "%^RESET%^%^BOLD%^" + ETO->QCN + "'s hammer " +
                  "bounces off of " + targ->QCN + " and " + ETO->QS + " quickly " +
                  "brings it down in another brutal attack!%^RESET%^", ({ targ, ETO }));
        tell_object(targ, "%^RESET%^%^BOLD%^" + ETO->QCN + "'s hammer " +
                    "bounces off of you and " + ETO->QCN + " snaps it quickly " +
                    "down in another attack!%^RESET%^");
        tell_object(ETO, "%^RESET%^%^BOLD%^Your hammer bounces off " +
                    "of " + targ->QCN + " and you quickly snap it back down in " +
                    "another attack!%^RESET%^");
        ETO->execute_attack();
        return roll_dice(1, 4);

    case 4..8:
        tell_room(EETO, "%^RESET%^%^BOLD%^%^BLUE%^" + ETO->QCN + " twirls " +
                  "" + ETO->QP + " hammer by the tip of the handle and slams it " +
                  "brutally into " + targ->QCN + "!%^RESET%^", ({ targ, ETO }));
        tell_object(targ, "%^RESET%^%^BOLD%^%^BLUE%^" + ETO->QCN + " " +
                    "quickly twirls " + ETO->QP + " hammer and brutally slams " +
                    "it into you!%^RESET%^");
        tell_object(ETO, "%^RESET%^%^BOLD%^%^BLUE%^You quickly twirl " +
                    "your hammer by the end of the handle and slam it brutally " +
                    "into " + targ->QCN + "!%^RESET%^");
        return roll_dice(3, 6);

    case 9:
        if (targ->query_stoneSkinned()) {
            tell_room(EETO, "%^MAGENTA%^" + ETO->QCN + "'s hammer thunders " +
                      "into " + targ->QCN + " and shatters " + targ->QP + " magical " +
                      "protection!%^RESET%^", ({ targ, ETO }));
            tell_object(targ, "%^MAGENTA%^" + ETO->QCN + "'s hammer slams " +
                        "into you, shattering your magical protection!%^RESET%^");
            tell_object(ETO, "%^MAGENTA%^You smash your hammer into " +
                        "" + targ->QCN + " with so much force that it shatters " +
                        "" + targ->QP + " magical protection!%^RESET%^");
            targ->set_stoneSkinned(0);
            break;
        }else {
            tell_room(EETO, "%^MAGENTA%^" + ETO->QCN + "'s hammer crunches " +
                      "as it strikes " + targ->QCN + ", leaving " + targ->QO + " " +
                      "shaken from the impact!%^RESET%^", ({ targ, ETO }));
            tell_object(targ, "%^MAGENTA%^" + ETO->QCN + "'s hammer " +
                        "crunches painfully as it strikes you, leaving you " +
                        "shaken from the impact!%^RESET%^");
            tell_object(ETO, "%^MAGENTA%^Your hammer crunches as it " +
                        "slams into " + targ->QCN + ", leaving " + targ->QO + " shaken " +
                        "from the impact!%^RESET%^");
            targ->set_paralyzed(roll_dice(1, 6), "%^MAGENTA%^You are " +
                                "trying to regain your senses!%^RESET%^");
            break;
        }
    }
    return 0;
}

void init()
{
    int num;
    ::init();
    if (!objectp(ETO)) {
        return;
    }
    if (base_name(ETO) == "/d/islands/tonerra/mon/tombt") {
        TO->set_size(4);
        return 1;
    }
    if (interactive(ETO) && !avatarp(ETO)) {
        tell_object(ETO, "%^RED%^The hammer magically shifts to fit " +
                    "perfectly in your hands.%^RESET%^");
        num = (int)ETO->query_size() + 1;
        set_size(num);
        switch (num) { //normalizing this as per what a 2h hammer in each size class would be
        case 2:
            set_wc(1, 8);
            set_large_wc(1, 8);
            break;

        case 3:
            set_wc(2, 6);
            set_large_wc(2, 6);
            break;

        case 4:
            set_wc(3, 6);
            set_large_wc(3, 6);
            break;
        }
    }
    add_action("smash", "smash");
    add_action("smash", "pound");
}

int smash(string str)
{
    if (!query_wielded()) {
        return 0;
    }
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    if (!objectp(EETO)) {
        return 0;
    }
    if (str == "sphere") {
        return 0;
    }
    tell_room(EETO, "%^BOLD%^%^BLUE%^" + ETO->QCN + " swings wildly at the " +
              "floor and brings the head of the hammer down onto the floor " +
              "in a thunderous blow.", ETO);
    tell_object(ETO, "%^BOLD%^%^BLUE%^You swing the hammer down with a " +
                "thunderous crash.");
    if (!EETO->query_property("indoors")) {
        tell_room(EETO, "Nothing happens.");
        return 1;
    }
    if (!str) {
        if (!sizeof(EETO->query_exits())) {
            tell_room(EETO, "Nothing happens.");
            return 1;
        }
        tell_room(EETO, "%^RED%^The room trembles with the force of the blow " +
                  "and you turn to see the exits all closed.");
        EETO->collapse_all_exits();
    }else {
        if (member_array(str, EETO->query_exits()) == -1) {
            tell_room(EETO, "Nothing happens.");
            return 1;
        }
        tell_room(EETO, "%^RED%^The room trembles with the force of the " +
                  "blow and the " + str + " is caved in.");
        EETO->collapse_exit(str);
    }
    if (!random(100) && userp(ETO)) {
        badStuff();
        return 1;
    }
}

void badStuff()
{
    tell_room(EETO, "%^RED%^After you realize the exits have closed, the " +
              "trembling gets worse and you realize...");
    call_out("moreBadStuff", 10, ETO);
}

moreBadStuff(object ob)
{
    object* inven;
    int i, j, hp;
    tell_room(environment(ob), "%^RED%^The ceiling of the room colapses " +
              "on you.");
    inven = all_living(environment(ob));
    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i]->query_true_invis()) {
            continue;
        }
        ETO->set_property("magic", 1);
        inven[i]->do_damage("head", roll_dice(50, 10));
        ETO->set_property("magic", -1);
        inven[i]->add_attacker(TP);
        inven[i]->continue_attack();
        inven[i]->remove_attacker(TP);
    }
}
