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
    set_name("Tejas");
    set_short("%^BOLD%^%^RED%^Tejas, the master of flame%^RESET%^");
    set_id(({ "tejas", "Tejas", "master", "master of flame", "genasi" }));
    set_long("%^RESET%^%^GREEN%^Tejas stands proudly with head high and shoulders back, a woman in the prime of her life "
             "and with no hint of fear or submission about her.  She looks almost human, except for the crown of %^ORANGE%^auburn hair "
             "%^GREEN%^that encircles her head like a halo and ripples fiercely as though caught %^BOLD%^%^RED%^a%^YELLOW%^f%^RED%^la"
             "%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^GREEN%^.  Her eyes are as chips of %^BOLD%^emerald%^RESET%^%^GREEN%^, while a "
             "splash of %^RED%^scarlet color %^GREEN%^stains her lips, all of these colorful highlights contrasting starkly with her "
             "%^RESET%^pale skin%^GREEN%^.  Her surprisingly tall figure is wrapped in a kimono of %^BOLD%^%^RED%^vivid crimson"
             "%^RESET%^%^GREEN%^, matching the hue of the glowing orb that she almost negligently passes from one hand to the "
             "other.%^RESET%^");
    set_race("fire genasi");
    set_body_type("human");
    set_class("mage");
    set_class("cleric");
    set_mlevel("mage", 21);
    set_guild_level("mage", 21);
    set_mlevel("cleric", 21);
    set_guild_level("cleric", 21);
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
    set_property("spell penetration", 100);
    set_spoken("wizish");
    command("speech announce clearly");
    talking = 0;
    opponent = "";
    set_funcs(({ "flames", "flames" }));
    set_func_chance(20);
    set_spell_chance(85);
    set_spells(({ "fireball", "fireball", "meteor swarm", "meteor swarm", "flame strike", "flame strike" }));
    equipment = new(OBJ "spellorb");
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
            force_me("emoteat " + TPQN + " %^RESET%^%^RED%^$M considers $N with a hint of irritation.%^RESET%^");
            write("");
            force_me("say %^BOLD%^%^RED%^'%^RESET%^We are... busy.  No interruptions!%^BOLD%^%^RED%^'%^RESET%^");
            force_me("emoteat " + TPQN + " %^RESET%^%^RED%^$M makes a negligent gesture towards $N, who disappears!%^RESET%^");
            TP->move_player("/d/shadowgate/void");
            TP->remove();
            return;
        }else {
            force_me("emoteat " + TPQN + " %^RESET%^%^RED%^$M turns her %^BOLD%^%^GREEN%^gleaming%^RESET%^%^RED%^ gaze upon $N"
                     ".%^RESET%^");
            write("");
            force_me("say %^BOLD%^%^RED%^'%^RESET%^We are... busy.  You may offer challenge when I am done with this one."
                     "%^BOLD%^%^RED%^'%^RESET%^");
            force_me("emoteat " + TPQN + " %^RESET%^%^RED%^$M waves her hand towards $N, and $S suddenly find $Oself in the main "
                     "chamber!%^RESET%^");
            TP->move_player(ROOMS + "centre");
            return;
        }
    }
}

void punt()
{
    force_me("emoteat " + TPQN + " %^RESET%^%^RED%^$M lifts a hand before her lips as she laughs.%^RESET%^");
    write("");
    force_me("say %^BOLD%^%^RED%^'%^RESET%^Not a chance, petty adventurer.  Come back when you're stronger.%^BOLD%^%^RED%^'%^RESET%^");
    force_me("emoteat " + TPQN + " %^RESET%^%^RED%^$M flicks her fingers fingers at $N, and $S suddenly find $Oself in the main "
             "chamber!%^RESET%^");
    TP->move_player(ROOMS + "centre");
    mylevel = 21;
}

void speech1()
{
    force_me("emoteat tejas %^RESET%^%^RED%^$M turns her gaze upon you, and her eyes %^BOLD%^%^GREEN%^gleam%^RESET%^"
             "%^RED%^ like emerald flames.%^RESET%^");
    write("");
    force_me("say %^BOLD%^%^RED%^'%^RESET%^So, another comes forth to be tested.  Let us hope you are more worthy than "
             "my last opponent.%^BOLD%^%^RED%^'%^RESET%^");
    force_me("emoteat tejas %^RESET%^%^RED%^A sly smile creeps its way across $M's lips as she catches the glowing orb "
             "in one swift motion and stands poised for combat.%^RESET%^");
    force_me("wield Sphere of Elemental Wrath");
    write("");
    force_me("say %^BOLD%^%^RED%^'%^RESET%^Your move, stranger.%^BOLD%^%^RED%^'%^RESET%^");
    talking = 0;
}

void die(object ob)
{
    object foe;
    foe = find_player(opponent);
    if (foe && userp(foe) && present(foe, ETO)) {
        set_hp(query_max_hp());
        remove_paralyzed();
        force_me("emoteat tejas %^RESET%^%^RED%^$M staggers and nearly falls, but manages to keep herself kneeling with the "
                 "fingertips of one hand supporting her upon the floor.  She lifts her head as her %^BOLD%^%^GREEN%^glowing eyes %^RESET%^"
                 "%^RED%^fade back to their normal emerald hue, and nods with grudging respect.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^RED%^'%^RESET%^Your skills are impressive.  Go, you have bested the flames.%^BOLD%^%^RED%^"
                 "'%^RESET%^");
        force_me("emoteat tejas %^RESET%^%^RED%^$M waves her hand towards you, and you suddenly find yourself in the main "
                 "chamber again!%^RESET%^");
        foe->move_player(ROOMS + "centre");
        if (!present("dojofiretoken", foe)) {
            tell_object(foe, "%^BOLD%^%^RED%^A gleaming crimson token flashes into existance in your hand.%^RESET%^");
            new(OBJ "firetoken")->move(foe);
        }
    }
    opponent = "";
    mylevel = 21;
    set_my_difficulty(mylevel);
    force_me("unwield orb");
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
    if (!TO->query_property("fire shield")) {
        new("/cmds/spells/f/_fire_shield")->use_spell(TO, 0, mylevel, 100, "cleric");
    }
    if (waiting == 1 && (member_array(foe, TO->query_attackers()) == -1) && present(foe, ETO)) {
        force_me("emoteat tejas %^RESET%^%^RED%^$M scowls darkly.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^RED%^'%^RESET%^You waste my time.  Come back when you are prepared.%^BOLD%^%^RED%^"
                 "'%^RESET%^");
        force_me("emoteat tejas %^RESET%^%^RED%^$M waves her hand towards you, and you suddenly find yourself in the main "
                 "chamber again!%^RESET%^");
        foe->move_player(ROOMS + "centre");
    }
    if (opponent != "" && (!foe || !present(foe, ETO))) {
        force_me("emoteat tejas %^RESET%^%^RED%^$M relaxes her stance and a sassy smirk graces her lips.%^RESET%^");
        opponent = "";
        mylevel = 21;
        set_my_difficulty(mylevel);
        force_me("unwield orb");
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
        force_me("emoteat tejas %^RESET%^%^RED%^With a motion of $M's hand, you suddenly find yourself fully "
                 "recovered!%^RESET%^");
        force_me("emoteat tejas %^RESET%^%^RED%^$M passes the orb casually to her offhand as she turns away, her "
                 "interest in $N gone.%^RESET%^");
        write("");
        force_me("say %^BOLD%^%^RED%^'%^RESET%^Ah well, another failure.%^BOLD%^%^RED%^'%^RESET%^");
        foe->move_player(ROOMS + "centre");
        foe->general_exp_adjust_perc(-5); //exp loss here, 5%; only half a death
        tell_object(foe, "%^BOLD%^%^WHITE%^You feel weary from your attempt!  %^BOLD%^%^RED%^You feel you have lost some experience.%^RESET%^");
    }
}

int flames(object targ)
{
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(targ)) {
        return 0;
    }
    force_me("emoteat tejas %^RESET%^%^RED%^$M spreads her feet and casts both hands wide, lowering her head as she mutters "
             "an incantation.  In the air behind her, gleaming runes of fire flare to life in a blazing circle, and the full force of "
             "the flame suddenly roars past her at you as she flings her hands forward with a shout!%^RESET%^");
    TO->set_property("magic", 1);
    targ->do_damage("torso", (roll_dice(mylevel, 8)) + mylevel);
    TO->set_property("magic", -1);
    return 1;
}

void set_my_difficulty(int mylevel)
{
    set_mlevel("mage", mylevel);
    set_guild_level("mage", mylevel);
    set_mlevel("cleric", mylevel);
    set_guild_level("cleric", mylevel);
    set_hd(mylevel, 12);
    set_max_hp(mylevel * 25);
    set_hp(query_max_hp());
    set_overall_ac(10 - mylevel);
    if (TO->query_property("magic resistance")) {
        remove_property("magic resistance");
    }
    set_mob_magic_resistance("high");
}
