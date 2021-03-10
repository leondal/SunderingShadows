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
    set_name("Jala");
    set_short("%^BOLD%^%^CYAN%^Jala, the master of waves%^RESET%^");
    set_id(({ "jala", "Jala", "master", "master of waves" }));
    set_long("%^RESET%^%^GREEN%^Jala seems to strike a middle ground between defense and ease of movement, clad in %^BLUE%^"
             "dark form-fitting leather %^GREEN%^rather than heavier metal armor.  A bodice encircles her torso, with gloved forearms "
             "and knee-high booted feet, although only criss-crossed support straps leave much of the rest of her toned skin visible.  "
             "Her %^RESET%^ice-white hair %^GREEN%^falls in a severe cut, parted far to one side so that only a few strands fall over "
             "her face and left side, while most of its length falls across her right ear and down to her neck.  Beneath this stern "
             "frame are eyes of %^BLUE%^de%^BOLD%^e%^RESET%^%^BLUE%^p s%^BOLD%^ap%^CYAN%^ph%^RESET%^%^CYAN%^ir%^BLUE%^e b%^BOLD%^l"
             "%^RESET%^%^BLUE%^ue%^GREEN%^, marked of a measuring gaze that falls upon her opponents as she absently sways the tip of "
             "the long, barbed whip that trails from a grip in her hand.%^RESET%^");
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
    command("speech convey in smooth, fluid tones");
    talking = 0;
    opponent = "";
    set_funcs(({ "storm", "storm" }));
    set_func_chance(20);
    set_monster_feats(({ "impale", "powerattack", "shatter" }));
    equipment = new(OBJ "chainwhip");
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
            force_me("emoteat " + TPQN + " %^RESET%^%^CYAN%^$M narrows her eyes and cracks the tip of her whip towards $N.%^RESET%^");
            write("");
            force_me("say %^BOLD%^%^CYAN%^'%^RESET%^Alone, I said.%^BOLD%^%^CYAN%^'%^RESET%^");
            force_me("emoteat " + TPQN + " %^RESET%^%^CYAN%^$M smirks a little as $N disappears!%^RESET%^");
            TP->move_player("/d/shadowgate/void");
            TP->remove();
            return;
        }else {
            force_me("emoteat " + TPQN + " %^RESET%^%^CYAN%^$M turns to notice $N.%^RESET%^");
            write("");
            force_me("say %^BOLD%^%^CYAN%^'%^RESET%^You may return later, but at present we are busy.%^BOLD%^%^CYAN%^'%^RESET%^");
            force_me("emoteat " + TPQN + " %^RESET%^%^CYAN%^$M waves her hand towards $N, and $S suddenly find $Oself in the main "
                     "chamber!%^RESET%^");
            TP->move_player(ROOMS + "centre");
            return;
        }
    }
}

void punt()
{
    force_me("emoteat " + TPQN + " %^RESET%^%^CYAN%^$M sneers and waves $N away.%^RESET%^");
    write("");
    force_me("say %^BOLD%^%^CYAN%^'%^RESET%^Far too weak for my likings.%^BOLD%^%^CYAN%^'%^RESET%^");
    force_me("emoteat " + TPQN + " %^RESET%^%^CYAN%^$M snaps her fingers, and $N suddenly find $Oself in the main "
             "chamber!%^RESET%^");
    TP->move_player(ROOMS + "centre");
    mylevel = 21;
}

void speech1()
{
    force_me("emoteat jala %^RESET%^%^CYAN%^$M turns her gaze upon you, and she gives an expectant nod.%^RESET%^");
    write("");
    force_me("say %^BOLD%^%^CYAN%^'%^RESET%^Do not be deceived, stranger.  Even the waters can raise a fierce storm"
             ".%^BOLD%^%^CYAN%^'%^RESET%^");
    force_me("emoteat jala %^RESET%^%^CYAN%^$M's lips are touched with a knowing smirk as she allows the chain whip "
             "to unfurl.%^RESET%^");
    force_me("wield Coiled Fury");
    write("");
    force_me("say %^BOLD%^%^CYAN%^'%^RESET%^You may begin.%^BOLD%^%^CYAN%^'%^RESET%^");
    talking = 0;
}

void die(object ob)
{
    object foe;
    foe = find_player(opponent);
    if (foe && userp(foe) && present(foe, ETO)) {
        set_hp(query_max_hp());
        remove_paralyzed();
        force_me("emoteat jala %^RESET%^%^CYAN%^$M steps back, breathing heavily but still on her feet.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^CYAN%^'%^RESET%^I yield to your skill.  Go, and take the gift of the waves with you"
                 ".%^BOLD%^%^CYAN%^'%^RESET%^");
        force_me("emoteat jala %^RESET%^%^CYAN%^$M waves her hand towards you, and you suddenly find yourself in the main "
                 "chamber again!%^RESET%^");
        foe->move_player(ROOMS + "centre");
        if (!present("dojowatertoken", foe)) {
            tell_object(foe, "%^BOLD%^%^CYAN%^A gleaming azure token flashes into existance in your hand.%^RESET%^");
            new(OBJ "watertoken")->move(foe);
        }
    }
    opponent = "";
    mylevel = 21;
    set_my_difficulty(mylevel);
    force_me("unwield whip");
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
        force_me("emoteat jala %^RESET%^%^CYAN%^$M shakes her head.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^CYAN%^'%^RESET%^Come back when you are ready to challenge me.%^BOLD%^%^CYAN%^'%^RESET%^");
        force_me("emoteat jala %^RESET%^%^CYAN%^$M waves her hand towards you, and you suddenly find yourself in the main "
                 "chamber again!%^RESET%^");
        foe->move_player(ROOMS + "centre");
    }
    if (opponent != "" && (!foe || !present(foe, ETO))) {
        force_me("emoteat jala %^RESET%^%^CYAN%^$M relaxes her stance and lets out a sigh.%^RESET%^");
        opponent = "";
        mylevel = 21;
        set_my_difficulty(mylevel);
        force_me("unwield whip");
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
        force_me("emoteat jala %^RESET%^%^CYAN%^With a motion of $M's hand, you suddenly find yourself fully "
                 "recovered!%^RESET%^");
        force_me("emoteat jala %^RESET%^%^CYAN%^$M folds her arms before her.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^CYAN%^'%^RESET%^You'll have to do better than that. Don't waste my time.%^BOLD%^"
                 "%^CYAN%^'%^RESET%^");
        foe->move_player(ROOMS + "centre");
        foe->general_exp_adjust_perc(-5); //exp loss here, 5%; only half a death
        tell_object(foe, "%^BOLD%^%^WHITE%^You feel weary from your attempt!  %^BOLD%^%^RED%^You feel you have lost some experience.%^RESET%^");
    }
}

int storm(object targ)
{
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(targ)) {
        return 0;
    }
    force_me("emoteat jala %^RESET%^%^CYAN%^Dropping to a low crouch, the chain whip taps a staccato rhythm across the "
             "floor as $M whirls its length in a rising spin around herself.  A surging maelstrom of water picks up around her, flung "
             "out to every corner of the room to rattle the walls and impact you violently!%^RESET%^");
    targ->do_damage("torso", roll_dice(mylevel, 8));
    targ->set_tripped(1, "%^BOLD%^You're struggling to stand after the impact!%^RESET%^", 1);
    return 1;
}

void set_my_difficulty(int mylevel)
{
    set_mlevel("fighter", mylevel);
    set_guild_level("fighter", mylevel);
    set_hd(mylevel, 12);
    set_max_hp(mylevel * 30);
    set_hp(query_max_hp());
    set_overall_ac(10 - mylevel);
    set_attack_bonus(mylevel / 4);
    set_mob_magic_resistance("high");
}
