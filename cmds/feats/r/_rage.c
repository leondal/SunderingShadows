#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

// Flags to determine rage type
string rage_class;
int tireless_rage = 0;
int spirit_warrior = 0;
int unstop = 0;

object* exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Rampage");
    feat_name("rage");
    feat_syntax("rage");
    feat_prereq("Barbarian L1");
    feat_classes("barbarian");
    feat_desc("This feat allows the barbarian to enter a fit of furious rage, boosting their attack, damage, max health, will save and fortitude save. The ability will last longer, and grow stronger, as the barbarian gains levels. Rage can be turned off by typing rage again. By the end of raging the barbarian will become fatigued. Rage will be interrupted if the barbarran becomes fatigued and exhausted.

%^BOLD%^N.B.%^RESET%^ Being enraged means that you are maddened uncontrollably. This is *not* a state in which you can calmly participate in a normal conversation, undertake delicate tasks, cast offensive spells, solve problems, or pretty much do anything other than shout obscenities and kill things. This power won't work in conjunction with similar magical effects, such as rally, transformation, rage, berserker and fell flight.

%^BOLD%^N.B.%^RESET%^ Rage status can be set using prompt. Please see help prompt for more information.

%^BOLD%^See also:%^RESET%^ rage *spells, satus effects, prompt");
    allow_blind(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("barbarian")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_rage(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);

    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "red and black");
}

void execute_feat()
{
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "rage")) {
        obj = query_active_feat("rage");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        return;
    }

    if (caster->query_property("using instant feat")) {
        tell_object(caster, "%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
        dest_effect();
        return;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You can't rage while you're casting a spell.%^RESET%^");
        dest_effect();
        return;
    }

    if (caster->query_property("effect_exhausted") || caster->query_property("effect_fatigued")) {
        tell_object(caster, "%^BOLD%^You are fatigued or exhausted and cannot rage.%^RESET%^");
        dest_effect();
        return;
    }

    tell_object(caster, cm("You gather strength as you prepare to go into frenzy."));
    caster->set_property("active_feats", ({ TO }));


    if (FEATS_D->usable_feat(caster, "mighty rage")) {
        rage_class = "mighty rage";
    } else if (FEATS_D->usable_feat(caster, "greater rage")) {
        rage_class = "greater rage";
    } else {
        rage_class = "simple rage";
    }

    if (FEATS_D->usable_feat(caster, "tireless rage")) {
        tireless_rage = 1;
    }

    if (FEATS_D->usable_feat(caster, "spirit warrior")) {
        spirit_warrior = 1;
    }

    caster->set_property("raged", 1);
    caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
    caster->set_property("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
    call_out("enable_rage", ROUND_LENGTH);

    ::execute_feat();
    return;
}

void enable_rage()
{
    int duration;

    activate_rage(1);
    tell_object(caster, cm("The world takes on a tinge of red as you are overcome by an insatiable desire to see your enemies rendered into a bloody pulp."));
    tell_room(place, cm(caster->QCN + " growls fiercely as " + caster->QS + " transforms into a homicidal maniac."), caster);

    duration = ROUND_LENGTH * (flevel * 4);

    if (!FEATS_D->usable_feat(caster, "persistent rage")) {
        call_out("dest_effect", duration);
    }
}

void activate_rage(int direction)
{
    switch (rage_class) {
    case "simple rage":
        simple_rage(direction);
        break;

    case "greater rage":
        greater_rage(direction);
        break;

    case "mighty rage":
        mighty_rage(direction);
        break;
    }

    if(!unstop)
        unstop = FEATS_D->usable(caster, "unstoppable") * 2;

    //MOON TOTEM
    if(FEATS_D->usable_feat(caster, "moon totem"))
    {
        caster->add_sight_bonus(direction * 8);

        if(direction > 0)
            caster->set_property("darkvision", 1);
        else
            caster->remove_property("darkvision");
    }

    if (direction == -1 && caster->query_hp() > caster->query_max_hp()) {
        caster->set_hp(caster->query_max_hp());
    }

    if (spirit_warrior) {
        spirit_warrior(direction);
    }

    if (!tireless_rage) {
        if (direction < 0) {
            "/std/effect/status/fatigued"->apply_effect(caster, 24); // 24 rounds - two minutes
        }
    }
}

void simple_rage(int direction)
{
    int amount;

    amount = 2 + FEATS_D->usable_feat(caster, "reckless abandon");
    /*
    caster->add_stat_bonus("strength", 4 * direction);
    caster->add_stat_bonus("constitution", 4 * direction);
    */
    caster->add_attack_bonus(amount * direction);
    caster->add_damage_bonus(2 * direction);
    caster->add_max_hp_bonus((flevel * 2) * direction);
    caster->add_saving_bonus("will", 2 * direction);
    caster->add_saving_bonus("fortitude", 2 * direction);
    caster->add_ac_bonus(-amount * direction);
}

void greater_rage(int direction)
{
    int amount;

    amount = 3 + FEATS_D->usable_feat(caster, "reckless abandon");
    /*
    caster->add_stat_bonus("strength", 6 * direction);
    caster->add_stat_bonus("constitution", 6 * direction);
    */
    caster->add_attack_bonus(amount * direction);
    caster->add_damage_bonus(3 * direction);
    caster->add_max_hp_bonus((flevel * 3) * direction);
    caster->add_saving_bonus("will", 3 * direction);
    caster->add_saving_bonus("fortitude", 3 * direction);
    caster->add_ac_bonus(-amount * direction);
}

void mighty_rage(int direction)
{
    int amount, save_bonus;
    amount = 4 + FEATS_D->usable_feat(caster, "reckless abandon");
    save_bonus = FEATS_D->usable_feat(caster, "indomitable will") * 2;
    /*
    caster->add_stat_bonus("strength", 8 * direction);
    caster->add_stat_bonus("constitution", 8 * direction);
    */
    caster->add_attack_bonus(amount * direction);
    caster->add_damage_bonus(4 * direction);
    caster->add_max_hp_bonus((flevel * 4 + unstop) * direction);
    caster->add_saving_bonus("will", (4 + save_bonus) * direction);
    caster->add_saving_bonus("fortitude", 4 * direction);
    caster->set_property("fast healing", 2 * direction);
    caster->add_ac_bonus(-amount * direction);
}

void spirit_warrior(int direction)
{
    caster->set_missChance(caster->query_missChance() + 33 * direction);
}

void execute_attack()
{
    object* attackers = ({ });
    object* allies = ({ });
    object target;
    int i, dam, enchant;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (caster->query_ghost() || caster->query_unconscious())
    {
        dest_effect();
        return;
    }

    if (!caster->query_property("raged")) {
        dest_effect();
        return;
    }

    if(caster->query_bound() || caster->query_paralyzed())
        return;

    place = environment(caster);
    attackers = caster->query_attackers();

    if (spirit_warrior) {
        if (sizeof(attackers)) {
            tell_object(caster, cm("Your insatiable bloodlust quickens your reflexes offering you the opportunity to make another attack!"));
            tell_room(place, cm(caster->QCN + "'s attacks become a frenzied blur."), caster);
            caster->execute_attack();
        }
        if (!random(20)) {
            tell_room(place, "%^BOLD%^%^WHITE%^" + caster->QCN + " takes on an ethereal appearance.", caster);
            tell_object(caster, "%^BOLD%^%^WHITE%^You feel the spirit realm as your rage continues.");
        }
    }

    if(FEATS_D->usable_feat(caster, "animal fury"))
    {
        target = caster->query_current_attacker();
        enchant = COMBAT_D->unarmed_enchantment(caster) + BONUS_D->query_stat_bonus(caster, "strength");

        if(target && thaco(target, enchant))
        {
            switch(random(4))
            {
                case 0:
                tell_object(caster, "%^RESET%^%^RED%^A %^BOLD%^f%^MAGENTA%^e%^RED%^r%^MAGENTA%^a%^RED%^l snarl %^RESET%^%^RED%^escapes your lips as you drive your %^BOLD%^%^WHITE%^teeth %^RESET%^%^RED%^into " + target->QCN + "%^RESET%^%^RED%^!%^RESET%^");
                tell_object(target, "%^RESET%^%^RED%^" + caster->QCN + " %^RESET%^%^RED%^lets out a %^BOLD%^f%^MAGENTA%^e%^RED%^r%^MAGENTA%^a%^RED%^l snarl %^RESET%^%^RED%^as he drives his %^BOLD%^%^WHITE%^teeth %^RESET%^%^RED%^into you!%^RESET%^");
                tell_room(place, "%^RESET%^%^RED%^" + caster->QCN + " %^RESET%^%^RED%^lets out a %^BOLD%^f%^MAGENTA%^e%^RED%^r%^MAGENTA%^a%^RED%^l snarl %^RESET%^%^RED%^as he drives his %^BOLD%^%^WHITE%^teeth %^RESET%^%^RED%^into " + target->QCN + "%^RESET%^%^RED%^!%^RESET%^", ({ caster, target }));
                break;

                case 1:
                tell_object(caster, "%^RESET%^%^MAGENTA%^As you close in combat, you take %^BOLD%^%^BLACK%^advantage %^RESET%^%^MAGENTA%^and %^BOLD%^%^WHITE%^bi%^RESET%^t%^BOLD%^e %^RESET%^%^MAGENTA%^into " + target->QCN + " %^BOLD%^%^RED%^viciously!%^RESET%^");
                tell_object(target, "%^RESET%^%^MAGENTA%^As " + caster->QCN + " %^RESET%^%^MAGENTA%^closes with you, they take %^BOLD%^%^BLACK%^advantage %^RESET%^%^MAGENTA%^with a %^BOLD%^%^RED%^vicious %^WHITE%^bi%^RESET%^t%^BOLD%^e%^RED%^!%^RESET%^");
                tell_room(place, "%^RESET%^%^MAGENTA%^As " + caster->QCN + " %^RESET%^%^MAGENTA%^closes with " + target->QCN + "%^RESET%^%^MAGENTA%^, they take %^BOLD%^%^BLACK%^advantage %^RESET%^%^MAGENTA%^with a %^BOLD%^%^RED%^vicious %^WHITE%^bi%^RESET%^t%^BOLD%^e%^RED%^!%^RESET%^", ({ target, caster }));
                break;

                case 2:
                tell_object(caster, "%^BOLD%^%^BLACK%^You lock with " + target->QCN + "%^BOLD%^%^BLACK%^, %^RESET%^%^RED%^lunging %^BOLD%^%^BLACK%^forward to drive your %^WHITE%^tee%^RESET%^t%^BOLD%^h %^BLACK%^into %^RESET%^%^ORANGE%^soft flesh%^BOLD%^%^BLACK%^!%^RESET%^");
                tell_object(target, "%^BOLD%^%^BLACK%^" + caster->QCN + " %^BOLD%^%^BLACK%^locks with you, %^RESET%^%^RED%^lunging %^BOLD%^%^BLACK%^forward to drive their %^WHITE%^tee%^RESET%^t%^BOLD%^h %^BLACK%^into %^RESET%^%^ORANGE%^soft flesh%^BOLD%^%^BLACK%^!%^RESET%^");
                tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " %^BOLD%^%^BLACK%^locks with " + target->QCN + "%^BOLD%^%^BLACK%^, %^RESET%^%^RED%^lunging %^BOLD%^%^BLACK%^forward to drive their %^WHITE%^tee%^RESET%^t%^BOLD%^h %^BLACK%^into %^RESET%^%^ORANGE%^soft flesh%^BOLD%^%^BLACK%^!%^RESET%^", ({ caster, target }));
                break;

                default:
                tell_object(caster, "%^RESET%^%^ORANGE%^You sink your %^BOLD%^%^WHITE%^tee%^RESET%^t%^BOLD%^h %^RESET%^%^ORANGE%^into " + target->QCN + "%^RESET%^%^ORANGE%^, %^RED%^ripping %^ORANGE%^free with a %^BOLD%^%^RED%^go%^MAGENTA%^u%^RED%^t of %^MAGENTA%^b%^RED%^lo%^MAGENTA%^o%^RED%^d %^RESET%^%^ORANGE%^in the air!%^RESET%^");
                tell_object(target, "%^RESET%^%^ORANGE%^" + caster->QCN + " %^RESET%^%^ORANGE%^sinks thier %^BOLD%^%^WHITE%^tee%^RESET%^t%^BOLD%^h %^RESET%^%^ORANGE%^into you, %^RED%^ripping %^ORANGE%^free with a %^BOLD%^%^RED%^go%^MAGENTA%^u%^RED%^t of %^MAGENTA%^b%^RED%^lo%^MAGENTA%^o%^RED%^d %^RESET%^%^ORANGE%^in the air!%^RESET%^");
                tell_room(place, "%^RESET%^%^ORANGE%^" + caster->QCN + " %^RESET%^%^ORANGE%^sinks thier %^BOLD%^%^WHITE%^tee%^RESET%^t%^BOLD%^h %^RESET%^%^ORANGE%^into " + target->QCN + "%^RESET%^%^ORANGE%^, %^RED%^ripping %^ORANGE%^free with a %^BOLD%^%^RED%^go%^MAGENTA%^u%^RED%^t of %^MAGENTA%^b%^RED%^lo%^MAGENTA%^o%^RED%^d %^RESET%^%^ORANGE%^in the air!%^RESET%^", ({ caster, target }));
                break;
            }

            dam = (roll_dice(1, 6) * (1 + flevel /  10)) + enchant;
            caster->cause_typed_damage(target,target->return_target_limb(),dam ,"piercing");
        }
    }

    if(FEATS_D->usable_feat(caster, "beast totem"))
    {
        target = caster->query_current_attacker();
        enchant = COMBAT_D->unarmed_enchantment(caster);

        if(target && thaco(target, enchant))
        {
            tell_object(caster, "%^YELLOW%^You rake your claws across " + target->QCN + "'s chest!");
            tell_object(target, caster->QCN + " rakes " + caster->QP + " claws across your chest!");
            tell_room(place, caster->QCN + " rakes " + caster->QP + " claws across " + target->QCN + "'s chest!", ({ caster, target }));
            dam = (roll_dice(1, 6) * (1 + flevel / 10)) + enchant;
            caster->cause_typed_damage(target, target->return_target_limb(), dam, "slashing");
        }
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    } else {
        dest_effect();
    }
}

void dest_effect()
{
    if (objectp(caster)) {
        if (FEATS_D->is_active(caster, "rage")) {
            tell_object(caster, cm("You struggle to catch your breath as you try to yank yourself away from your murderous reverie."));
            caster->remove_property_value("active_feats", ({ TO }));
            caster->remove_property("raged");
            caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^RED%^ (%^RESET%^%^RED%^enraged%^BOLD%^)%^RESET%^" }));
            activate_rage(-1);
        }
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
