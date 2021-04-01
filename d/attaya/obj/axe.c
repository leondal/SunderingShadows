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

    set_long("%^BOLD%^%^BLACK%^This %^RESET%^massive %^BOLD%^%^BLUE%^double-bladed %^RED%^axe %^BLACK%^is forged from some sort of material that is almost impossibly light weight. It gives the %^RED%^axe %^BLACK%^a heft that rivals much lighter blades. Two %^BLUE%^double-bladed %^RED%^axe %^BLACK%^heads rest on either end of a long haft. Each of the %^RED%^axe %^BLACK%^heads is a %^RESET%^%^CYAN%^crecent %^BOLD%^%^WHITE%^moon %^BLACK%^shape, longer towards the point, almost %^RESET%^%^CYAN%^sword-like%^BOLD%^%^BLACK%^, while thicker and more rounded towards the base of the %^RED%^axe %^BLACK%^head. The %^RED%^axe %^BLACK%^heads are thin and are shaped so that %^CYAN%^wind %^RESET%^resistance %^BOLD%^%^BLACK%^passing over them allows the wielder the ability to alter the direction of his swings with hardly more than the twist of a wrist. The %^RESET%^%^ORANGE%^shaft %^BOLD%^%^BLACK%^of the %^RED%^axe %^BLACK%^is made of an inky material that %^CYAN%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^u%^RESET%^%^MAGENTA%^c%^BOLD%^%^CYAN%^t%^RESET%^%^MAGENTA%^u%^BOLD%^%^CYAN%^a%^RESET%^%^MAGENTA%^t%^BOLD%^%^CYAN%^e%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^between the darkest black and midnight blue. D%^RESET%^a%^BOLD%^%^BLACK%^rk sh%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^p%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s can be seen %^BLUE%^swirling %^BLACK%^inside the material and it has an almost %^RESET%^o%^BOLD%^%^BLACK%^i%^RESET%^l%^BOLD%^%^BLACK%^y texture to the touch. A handgrip has been fashioned onto the center of the haft to allow for a firm grasp of the weapon. The handgrip looks to be made of some kind of %^RESET%^ancient %^MAGENTA%^hide%^BOLD%^%^BLACK%^. Even though the hide is clearly %^RESET%^ancient%^BOLD%^%^BLACK%^, it is still soft and supple as if it were tanned only yesterday. Whatever %^CYAN%^enchantment %^BLACK%^protects this weapon must be %^MAGENTA%^powerful %^BLACK%^indeed.%^RESET%^");

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
            tell_object(ETO, "%^GREEN%^You %^BOLD%^%^WHITE%^spin %^RESET%^%^GREEN%^the %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^%^BLACK%^y %^RED%^a%^RESET%^%^RED%^x%^BOLD%^e %^WHITE%^q%^RESET%^u%^BOLD%^ic%^RESET%^k%^BOLD%^l%^RESET%^y %^GREEN%^and turn your %^BOLD%^body%^RESET%^%^GREEN%^, using the %^BOLD%^%^CYAN%^mo%^RESET%^%^CYAN%^m%^BOLD%^ent%^RESET%^%^CYAN%^u%^BOLD%^m %^RESET%^%^GREEN%^to %^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^liv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^GREEN%^a %^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^v%^RED%^a%^BLACK%^st%^RED%^a%^BLACK%^t%^RED%^i%^BLACK%^ng %^RESET%^%^RED%^blow %^GREEN%^on " + targ->QCN + "!%^WHITE%^");
            tell_object(targ, "%^GREEN%^" + ETO->QCN + " %^BOLD%^%^WHITE%^spins %^RESET%^%^GREEN%^" + ETO->QP + " %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^%^BLACK%^y %^RED%^a%^RESET%^%^RED%^x%^BOLD%^e %^WHITE%^q%^RESET%^u%^BOLD%^ic%^RESET%^k%^BOLD%^l%^RESET%^y %^GREEN%^and turns " + ETO->QP + " %^BOLD%^body%^RESET%^%^GREEN%^, using the %^BOLD%^%^CYAN%^mo%^RESET%^%^CYAN%^m%^BOLD%^ent%^RESET%^%^CYAN%^u%^BOLD%^m %^RESET%^%^GREEN%^to %^BOLD%^%^BLACK%^h%^RESET%^i%^BOLD%^%^BLACK%^t %^RESET%^%^GREEN%^you with %^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^v%^RED%^a%^BLACK%^st%^RED%^a%^BLACK%^t%^RED%^i%^BLACK%^ng %^RESET%^%^RED%^force%^GREEN%^!%^WHITE%^");
            tell_room(EETO, "%^GREEN%^" + ETO->QCN + " %^BOLD%^%^WHITE%^spins %^RESET%^%^GREEN%^" + ETO->QP + " %^BOLD%^%^BLACK%^h%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^%^BLACK%^y %^RED%^a%^RESET%^%^RED%^x%^BOLD%^e %^WHITE%^q%^RESET%^u%^BOLD%^ic%^RESET%^k%^BOLD%^l%^RESET%^y %^GREEN%^and turns " + ETO->QP + " %^BOLD%^body%^RESET%^%^GREEN%^, using the %^BOLD%^%^CYAN%^mo%^RESET%^%^CYAN%^m%^BOLD%^ent%^RESET%^%^CYAN%^u%^BOLD%^m %^RESET%^%^GREEN%^to %^BOLD%^%^BLACK%^h%^RESET%^i%^BOLD%^%^BLACK%^t %^RESET%^%^GREEN%^" + targ->QCN + " with a %^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^v%^RED%^a%^BLACK%^st%^RED%^a%^BLACK%^t%^RED%^i%^BLACK%^ng %^RESET%^%^RED%^blow%^GREEN%^!%^WHITE%^", ({ targ, ETO }));
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            break;

        case 4..5: // between 3 and 5 or 30%
            tell_object(ETO, "%^RED%^You %^BOLD%^roar %^RESET%^%^RED%^as you bring one end of the %^BOLD%^%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^ci%^RESET%^e%^BOLD%^%^BLACK%^nt %^BLUE%^double %^RED%^axe %^RESET%^%^RED%^down on " + targ->QCN + " in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^d%^BOLD%^l%^RESET%^%^RED%^y %^BOLD%^%^CYAN%^o%^BLACK%^v%^CYAN%^er%^BLACK%^h%^CYAN%^ea%^BLACK%^d %^RESET%^%^CYAN%^chop%^RED%^!%^WHITE%^");
            tell_object(targ, "%^RED%^" + ETO->QCN + " %^BOLD%^roars %^RESET%^%^RED%^as " + ETO->QS + " brings one end of " + ETO->QP + " %^BOLD%^%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^ci%^RESET%^e%^BOLD%^%^BLACK%^nt %^RESET%^%^RED%^double axe down on you in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^o%^BLACK%^v%^CYAN%^er%^BLACK%^h%^CYAN%^ea%^BLACK%^d %^RESET%^%^CYAN%^chop%^RED%^!%^WHITE%^");
            tell_room(EETO, "%^RED%^" + ETO->QCN + " %^BOLD%^roars %^RESET%^%^RED%^as " + ETO->QS + " brings one end of " + ETO->QP + " %^BOLD%^%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^ci%^RESET%^e%^BOLD%^%^BLACK%^nt %^BLUE%^double %^RED%^axe %^RESET%^%^RED%^down on " + targ->QCN + " in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^o%^BLACK%^v%^CYAN%^er%^BLACK%^h%^CYAN%^ea%^BLACK%^d %^RESET%^%^CYAN%^chop%^RED%^!%^WHITE%^", ({ targ, ETO }));
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage() * 150 / 100, TO->query_damage_type());
            break;

        case 6..7:
            tell_object(ETO, "%^CYAN%^You %^BOLD%^%^GREEN%^twirl %^RESET%^%^CYAN%^the %^BOLD%^%^BLACK%^massive %^RED%^axe %^WHITE%^quickly %^RESET%^%^CYAN%^and send the %^ORANGE%^haft %^CYAN%^down %^WHITE%^low%^CYAN%^, %^BOLD%^sweeping %^RESET%^%^CYAN%^under " + targ->QCN + " and %^BOLD%^%^WHITE%^knocking %^RESET%^%^CYAN%^" + targ->QO + " %^BOLD%^%^BLACK%^down!%^RESET%^");
            tell_object(targ, "%^CYAN%^" + ETO->QCN + " %^BOLD%^%^GREEN%^twirls %^RESET%^%^CYAN%^the %^BOLD%^%^BLACK%^massive %^RED%^axe %^WHITE%^quickly %^RESET%^%^CYAN%^and sends the %^BOLD%^%^WHITE%^haft %^RESET%^%^CYAN%^down low, %^BOLD%^sweeping %^RESET%^%^CYAN%^under you and %^BOLD%^%^WHITE%^knocking %^RESET%^%^CYAN%^you %^BOLD%^%^BLACK%^down!%^RESET%^");
            tell_room(EETO, "%^CYAN%^" + ETO->QCN + " %^BOLD%^%^GREEN%^twirls %^RESET%^%^CYAN%^the %^BOLD%^%^BLACK%^massive %^RED%^axe %^WHITE%^quickly %^RESET%^%^CYAN%^ands sends the %^BOLD%^%^WHITE%^haft %^RESET%^%^CYAN%^down low, %^BOLD%^sweeping %^RESET%^%^CYAN%^under " + targ->QCN + " and %^BOLD%^%^WHITE%^knocking %^RESET%^%^CYAN%^" + targ->QP + " %^BOLD%^%^BLACK%^down!%^RESET%^", ({ targ, ETO }));
            targ->set_paralyzed(roll_dice(1, 10) + 10, "%^BOLD%^%^GREEN%^You are %^WHITE%^struggling %^GREEN%^to %^BLACK%^stand %^GREEN%^up!%^RESET%^");
            break;

        case 8..9:
            tell_object(ETO, "%^BOLD%^You %^BLACK%^snap %^WHITE%^the %^RESET%^%^ORANGE%^flat %^BOLD%^%^WHITE%^of one %^BLACK%^axe %^BLUE%^blade %^WHITE%^down atop " + targ->QCN + "'s %^RED%^head %^WHITE%^and use the %^BLACK%^f%^CYAN%^o%^BLACK%^rc%^CYAN%^e %^WHITE%^of the %^RESET%^%^CYAN%^rebound %^BOLD%^%^WHITE%^to %^ORANGE%^launch %^WHITE%^another %^BLACK%^attack%^WHITE%^!%^RESET%^");
            tell_object(targ, "%^BOLD%^" + ETO->QCN + " %^BLACK%^snaps %^WHITE%^the %^RESET%^%^ORANGE%^flat %^BOLD%^%^WHITE%^of one %^BLACK%^axe %^BLUE%^blade %^WHITE%^down atop your %^RED%^head %^WHITE%^and uses the %^BLACK%^f%^CYAN%^o%^BLACK%^rc%^CYAN%^e %^WHITE%^of the %^RESET%^%^CYAN%^rebound %^BOLD%^%^WHITE%^to %^ORANGE%^launch %^WHITE%^two more %^BLACK%^attacks%^WHITE%^!%^RESET%^");
            tell_room(EETO, "%^BOLD%^" + ETO->QCN + " %^BLACK%^snaps %^WHITE%^the %^RESET%^%^ORANGE%^flat %^BOLD%^%^WHITE%^of one %^BLACK%^axe %^BLUE%^blade %^WHITE%^down atop " + targ->QCN + "'s %^RED%^head %^WHITE%^and uses the %^BLACK%^f%^CYAN%^o%^BLACK%^rc%^CYAN%^e %^WHITE%^of the %^RESET%^%^CYAN%^rebound %^BOLD%^%^WHITE%^to %^ORANGE%^launch %^WHITE%^two more %^BLACK%^attacks%^WHITE%^!%^RESET%^", ({ targ, ETO }));
            if (sizeof(ETO->query_attackers())) {
                ETO->execute_attack();
                ETO->execute_attack();
            }
            break;

        case 10:
            if ((member_array("neck", targ->query_limbs()) != -1) && !random(10) && !targ->reflex_save(50) && !targ->query_property("no death") && !FEATS_D->usable_feat(targ, "death ward")) { //increased DC to 50 to match godslayer
                tell_object(ETO, "%^RED%^You %^BOLD%^%^WHITE%^drop %^RESET%^%^RED%^to one knee and snap the %^BOLD%^%^BLACK%^blade %^RESET%^%^RED%^of the %^BOLD%^%^BLUE%^massive %^RED%^axe %^RESET%^%^RED%^in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^upwards %^BLACK%^arc%^RESET%^%^RED%^!%^RESET%^");
                tell_object(ETO, "%^BOLD%^%^BLACK%^You can see the %^BLUE%^blade %^MAGENTA%^sink %^BLACK%^cleanly into " + targ->QCN + "'s %^RED%^n%^RESET%^%^RED%^e%^BOLD%^ck %^BLACK%^and pass through almost %^CYAN%^without %^BLACK%^r%^RESET%^e%^BOLD%^%^BLACK%^si%^RESET%^s%^BOLD%^%^BLACK%^ta%^RESET%^n%^BOLD%^%^BLACK%^c%^RESET%^e%^BOLD%^%^BLACK%^.%^RESET%^");
                tell_object(ETO, "%^B_RED%^" + targ->QCN + "'s head falls away and " + targ->QP + " body drops lifelessly to the ground.%^RESET%^");
                tell_object(targ, "%^RED%^" + ETO->QCN + " %^BOLD%^%^WHITE%^drops %^RESET%^%^RED%^to one knee and snaps the %^BOLD%^%^BLACK%^blade %^RESET%^%^RED%^of the %^BOLD%^%^BLUE%^massive %^RED%^axe %^RESET%^%^RED%^in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^upwards %^BLACK%^arc%^RESET%^%^RED%^!%^RESET%^");
                tell_object(targ, "%^BOLD%^%^BLACK%^You %^CYAN%^grimace %^BLACK%^and then %^WHITE%^open %^BLACK%^your %^MAGENTA%^eyes %^BLACK%^in sudden stark %^CYAN%^t%^BLACK%^e%^CYAN%^rr%^BLACK%^o%^CYAN%^r %^BLACK%^as you feel the bite of the %^RED%^axe %^BLACK%^entering your %^RED%^n%^RESET%^%^RED%^e%^BOLD%^ck%^BLACK%^!%^RESET%^");
                tell_object(targ, "%^B_RED%^Your world thumbles and then stops as you roll to spot on the ground, just in time to see your body fall next to you!%^RESET%^");
                tell_object(targ, "%^BOLD%^%^BLACK%^" + ETO->QCN + " just %^RED%^cut %^BLACK%^off your %^RED%^h%^RESET%^%^RED%^ea%^BOLD%^d%^BLACK%^..  bla%^RESET%^c%^BOLD%^%^BLACK%^kne%^RESET%^s%^BOLD%^%^BLACK%^s overtakes you as you watch your %^RESET%^%^ORANGE%^body %^RED%^twitching %^BOLD%^%^BLACK%^on the ground.%^RESET%^");
                tell_room(EETO, "%^RED%^" + ETO->QCN + " %^BOLD%^%^WHITE%^drops %^RESET%^%^RED%^to one knee and snaps the %^BOLD%^%^BLACK%^blade %^RESET%^%^RED%^of the %^BOLD%^%^BLUE%^massive %^RED%^axe %^RESET%^%^RED%^in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^upwards %^BLACK%^arc%^RESET%^%^RED%^!%^RESET%^", ({ targ, ETO }));
                tell_room(EETO, "%^BOLD%^%^BLACK%^You can see the %^BLUE%^blade %^BLACK%^of " + ETO->QCN + "'s %^RED%^axe %^BLACK%^sink %^CYAN%^cleanly %^BLACK%^into " + targ->QCN + "'s %^RED%^n%^RESET%^%^RED%^e%^BOLD%^ck %^BLACK%^and pass %^CYAN%^cleanly %^BLACK%^t%^RESET%^h%^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ug%^RESET%^h%^BOLD%^%^BLACK%^!%^RESET%^", ({ targ, ETO }));
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
            tell_object(ETO, "%^RED%^You %^BOLD%^%^WHITE%^drop %^RESET%^%^RED%^to one knee and snap the %^BOLD%^%^BLACK%^blade %^RESET%^%^RED%^of the %^BOLD%^%^BLUE%^massive %^RED%^axe %^RESET%^%^RED%^in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^upwards %^BLACK%^arc%^RESET%^%^RED%^!%^RESET%^");
            tell_object(ETO, "%^BOLD%^%^BLACK%^At the last %^WHITE%^instant%^BOLD%^%^BLACK%^, " + targ->QCN + " manages to %^CYAN%^dodge%^BOLD%^%^BLACK%^ out of the way, avoiding the %^RED%^fatal strike!%^RESET%^");
            tell_object(ETO, "%^GREEN%^The axe slices across " + targ->QCN + "'s eyes, blinding " + targ->QO + "!%^RESET%^");

            tell_object(targ, "%^RED%^" + ETO->QCN + " %^BOLD%^%^WHITE%^drops %^RESET%^%^RED%^to one knee and snaps the %^BOLD%^%^BLACK%^blade %^RESET%^%^RED%^of the %^BOLD%^%^BLUE%^massive %^RED%^axe %^RESET%^%^RED%^in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^upwards %^BLACK%^arc%^RESET%^%^RED%^!%^WHITE%^%^RESET%^");
            tell_object(targ, "%^BOLD%^%^BLACK%^At the last %^WHITE%^instant%^BOLD%^%^BLACK%^, you manage to %^CYAN%^dodge%^BOLD%^%^BLACK%^ out of the way, avoiding the %^RED%^fatal strike!%^RESET%^");
            tell_object(targ, "%^GREEN%^The axe slices across your eyes, blinding you!%^RESET%^");

            tell_room(EETO, "%^RED%^" + ETO->QCN + " %^BOLD%^%^WHITE%^drops %^RESET%^%^RED%^to one knee and snaps the %^BOLD%^%^BLACK%^blade %^RESET%^%^RED%^of the %^BOLD%^%^BLUE%^massive %^RED%^axe %^RESET%^%^RED%^in a %^BOLD%^d%^RESET%^%^RED%^e%^BOLD%^a%^RESET%^%^RED%^dl%^BOLD%^y %^CYAN%^upwards %^BLACK%^arc%^RESET%^%^RED%^!%^WHITE%^", ({ targ, ETO }));
            tell_room(EETO, "%^BOLD%^%^BLACK%^At the last %^WHITE%^instant%^BOLD%^%^BLACK%^, " + targ->QCN + " manages to %^CYAN%^dodge%^BOLD%^%^BLACK%^ out of the way, avoiding the %^RED%^fatal strike!%^RESET%^", ({ targ, ETO }));
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