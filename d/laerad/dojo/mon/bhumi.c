#include <std.h>
#include <magic.h>
#include "../dojo.h"
inherit MONSTER;

int talking, waiting, mylevel;
string opponent;
object equipment;
void set_my_difficulty(int mylevel);

void create()
{
    ::create();
    set_name("Bhumi");
    set_short("%^BOLD%^%^GREEN%^Bhumi, the master of earth%^RESET%^");
    set_id(({ "bhumi", "Bhumi", "master", "master of earth" }));
    set_long("%^RESET%^%^GREEN%^Bhumi is clad in the armor of a %^RED%^warrior%^GREEN%^, but only lightly so as not to "
             "restrict her movements.  A breastplate, moulded bracers and a shield seem sufficient defense enough, over which lie the "
             "drapings of a %^RESET%^soft white tunic%^GREEN%^, while leather sandals lace their way up her calves.  Her thick blonde "
             "hair is tied loosely back in a braid, so as not to obscure her vision, which is blue-eyed and %^ORANGE%^calm %^GREEN%^as "
             "the earth beneath her feet.  A %^YELLOW%^tiny golden hairpin %^RESET%^%^GREEN%^of clustered leaves is the only "
             "extravagance she bears.  In her free hand she holds a gladius in an easy grip, looking more than experienced in its "
             "use.%^RESET%^");
    set_race("human");
    set_body_type("human");
    set_class("fighter");
    set_mlevel("fighter", 21);
    set_guild_level("fighter", 21);
    set_alignment(5);
    set_gender("female");
    set_size(2);
    set_exp(1);
    set_overall_ac(-60);
    set_hd(21, 12);
    set_max_hp(9001);
    set_hp(query_max_hp());
    set("aggressive", 0);
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_property("full attacks", 1);
    set_property("no bows", 1);
    set_property("no death", 1);
    set_property("no disarm", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no knockdown", 1);
    set_property("knock unconscious", 1);
    set_property("no steal", 1);
    set_spoken("wizish");
    command("speech state gently");
    talking = 0;
    opponent = "";
    set_funcs(({ "rumble", "rumble" }));
    set_func_chance(20);
    set_monster_feats(({ "shieldbash", "shieldwall", "deflection", "reflection", "counter" }));
    equipment = new(OBJ "gladius");
    equipment->set_property("monsterweapon", 1);
    equipment->move(TO);
    equipment = new(OBJ "shield");
    equipment->set_property("monsterweapon", 1);
    equipment->move(TO);
}

int query_talking()
{
    return talking;
}

void init()
{
    ::init();
    if (TP->query_true_invis()) {
        return;
    }
    if (!talking && opponent == "") {
        mylevel = (int)TP->query_level();
        if (mylevel < 21) {
            call_out("punt", 3);
        }else {
            talking = 1;
            waiting = 12;
            opponent = TPQN;
            if (mylevel > 40) {
                mylevel = 40;
            }
            set_my_difficulty(mylevel);
            call_out("speech1", 3);
        }
    }
    if (opponent != "" && opponent != (string)TPQN) { //kick out any extras that manage to get in somehow
        if (!userp(TP)) {
            force_me("emoteat " + TPQN + " %^RESET%^%^GREEN%^$M lifts her hand to admonish $N.%^RESET%^");
            write("");
            force_me("say %^BOLD%^%^GREEN%^'%^RESET%^This fight must be done alone. Begone.%^BOLD%^%^GREEN%^'%^RESET%^");
            force_me("emoteat " + TPQN + " %^RESET%^%^GREEN%^A pulse of energy from $M's hand causes $N to vanish!%^RESET%^");
            TP->move_player("/d/shadowgate/void");
            TP->remove();
            return;
        }else {
            force_me("emoteat " + TPQN + " %^RESET%^%^GREEN%^$M turn to consider $N, and shakes her head.%^RESET%^");
            write("");
            force_me("say %^BOLD%^%^GREEN%^'%^RESET%^Only one may challenge me, you must wait.%^BOLD%^%^GREEN%^'%^RESET%^");
            force_me("emoteat " + TPQN + " %^RESET%^%^GREEN%^$M waves her hand towards $N, and $S suddenly find $Oself in the main "
                     "chamber!%^RESET%^");
            TP->move_player(ROOMS + "centre");
            return;
        }
    }
}

void punt()
{
    force_me("emoteat " + TPQN + " %^RESET%^%^GREEN%^$M turn to consider $N, and shakes her head.%^RESET%^");
    write("");
    force_me("say %^BOLD%^%^GREEN%^'%^RESET%^You are too inexperienced. Return when you have more training.%^BOLD%^%^GREEN%^'%^RESET%^");
    force_me("emoteat " + TPQN + " %^RESET%^%^GREEN%^$M waves her hand towards $N, and $S suddenly find $Oself in the main "
             "chamber!%^RESET%^");
    TP->move_player(ROOMS + "centre");
    mylevel = 21;
}

void speech1()
{
    force_me("emoteat bhumi %^RESET%^%^GREEN%^$M sends a soft smile in your direction.%^RESET%^");
    write("");
    force_me("say %^BOLD%^%^GREEN%^'%^RESET%^Come, worthy opponent.  I will offer you my best efforts!%^BOLD%^%^GREEN%^"
             "'%^RESET%^");
    force_me("emoteat bhumi %^RESET%^%^GREEN%^$M's grasp tightens upon the grip of the gladius as she raises her shield in "
             "defense.%^RESET%^");
    force_me("wield Resolve in left hand");
    force_me("wear Temperance");
    write("");
    force_me("say %^BOLD%^%^GREEN%^'%^RESET%^Begin when you are ready.%^BOLD%^%^GREEN%^'%^RESET%^");
    talking = 0;
}

void die(object ob)
{
    object foe;
    foe = find_player(opponent);
    if (foe && userp(foe) && present(foe, ETO)) {
        set_hp(query_max_hp());
        remove_paralyzed();
        force_me("emoteat bhumi %^RESET%^%^GREEN%^$M drops to a crouch, raising her shield defensively as she lowers her "
                 "blade in a sign of defeat.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^GREEN%^'%^RESET%^You have fought well.  Go with the blessing of the earth.%^BOLD%^%^GREEN%^"
                 "'%^RESET%^");
        force_me("emoteat bhumi %^RESET%^%^GREEN%^$M waves her hand towards you, and you suddenly find yourself in the main "
                 "chamber again!%^RESET%^");
        foe->move_player(ROOMS + "centre");
        if (!present("dojoearthtoken", foe)) {
            tell_object(foe, "%^BOLD%^%^GREEN%^A gleaming emerald token flashes into existance in your hand.%^RESET%^");
            new(OBJ "earthtoken")->move(foe);
        }
    }
    opponent = "";
    mylevel = 21;
    set_my_difficulty(mylevel);
    force_me("unwield gladius");
    force_me("remove shield");
    if (waiting) {
        waiting = 0;
    }
}

void heart_beat()
{
    object foe;
    ::heart_beat();
    foe = find_player(opponent);
    if (waiting) {
        waiting--;
    }
    if (waiting == 1 && (member_array(foe, TO->query_attackers()) == -1) && present(foe, ETO)) {
        force_me("emoteat bhumi %^RESET%^%^GREEN%^$M shakes her head.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^GREEN%^'%^RESET%^Go, if you need, and prepare.  I will await your return.%^BOLD%^%^GREEN%^"
                 "'%^RESET%^");
        force_me("emoteat bhumi %^RESET%^%^GREEN%^$M waves her hand towards you, and you suddenly find yourself in the main "
                 "chamber again!%^RESET%^");
        foe->move_player(ROOMS + "centre");
    }
    if (opponent != "" && (!foe || !present(foe, ETO))) {
        force_me("emoteat bhumi %^RESET%^%^GREEN%^$M relaxes her stance and lowers her weapon.%^RESET%^");
        opponent = "";
        mylevel = 21;
        set_my_difficulty(mylevel);
        force_me("unwield gladius");
        force_me("remove shield");
        if (waiting) {
            waiting = 0;
        }
        if (objectp(foe)) {
            foe->remove_attacker(TO);
            TO->remove_attacker(foe);
        }
    }
    if (objectp(foe) && present(foe, ETO) && (int)foe->query_hp() < 1) { // KO, kick them out
        foe->remove_attacker(TO);
        TO->remove_attacker(foe);
        foe->set_hp(foe->query_max_hp());
        foe->remove_paralyzed();
        force_me("emoteat " + foe->query_name() + " %^RESET%^%^GREEN%^With a motion of $M's hand, $N suddenly find $Oself fully "
                 "recovered!%^RESET%^");
        force_me("emoteat bhumi %^RESET%^%^GREEN%^$M shakes her head.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^GREEN%^'%^RESET%^You have more yet to learn before you can defeat me. Return when "
                 "you have improved your skill.%^BOLD%^%^GREEN%^'%^RESET%^");
        foe->move_player(ROOMS + "centre");
        foe->general_exp_adjust_perc(-5); //exp loss here, 5%; only half a death
        tell_object(foe, "%^BOLD%^%^WHITE%^You feel weary from your attempt!  %^BOLD%^%^RED%^You feel you have lost some experience.%^RESET%^");
    }
}

int rumble(object targ)
{
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(targ)) {
        return 0;
    }
    force_me("emoteat bhumi %^RESET%^%^GREEN%^$M brings her blade down in a powerful blow that impacts the wooden floor at "
             "her feet, surprisingly leaving no mark.  For a second, you wonder if she's missed her target entirely, until the ground "
             "beneath your feet shudders and heaves!%^RESET%^");
    targ->set_paralyzed(25, "%^BOLD%^You're struggling to maintain your footing!%^RESET%^");
    return 1;
}

void set_my_difficulty(int mylevel)
{
    set_mlevel("fighter", mylevel);
    set_guild_level("fighter", mylevel);
    set_hd(mylevel, 12);
    set_max_hp(mylevel * 35);
    set_hp(query_max_hp());
    set_overall_ac((-1) * mylevel);
    set_attack_bonus(mylevel / 5);
    set_mob_magic_resistance("high");
}
