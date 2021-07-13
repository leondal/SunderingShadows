#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_attack_limbs(({ "fangs", "right fore claw", "left fore claw", "right rear claw", "left rear claw" }));
    set_new_damage_type("piercing");
    set_limbs(({ "fangs", "head", "torso", "right fore claw", "left fore claw", "right rear claw", "left rear claw", "right foreleg", "right forepaw", "left foreleg", "left forepaw", "right rear leg", "right rear paw", "left rear leg", "left rear paw", "tail" }));
    set_attack_functions(([ "fangs" : (: TO, "shape_attack" :), "right fore claw" : (: TO, "shape_attack" :), "left fore claw" : (: TO, "shape_attack" :), "right rear claw" : (: TO, "shape_attack" :), "left rear claw" : (: TO, "shape_attack" :)   ]));
    set_ac_bonus(2);
    set_base_attack_num(6);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("tiger");
    set_shape_profile("weretiger_tiger_999");
    set_shape_bonus("perception", 4);
    set_shape_bonus("survival", 2);
    set_shape_bonus("fire resistance percent", 15);
    set_shape_bonus("silver resistance percent", -33);
    set_shape_bonus("sight bonus", 3);
    set_shape_bonus("damage bonus", 3);
    set_shape_bonus("attack bonus", 3);
    set_shape_bonus("dexterity", 4);
    set_shape_bonus("constitution", 2);
    set_shape_bonus("wisdom", 2);
    set_shape_height(50 + random(12));
    set_shape_weight(200 + random(50));
}

int default_descriptions(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    obj->set_description("'s long feline body is covered in smooth fur from tip of snout to the end of " + obj->QP + " long tail.  The graceful movements of " + obj->QP + " body show " + obj->QS + " to be a dangerous predator.");

    obj->setDescriptivePhrase("%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^an $R w%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^th %^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^r%^WHITE%^");

    obj->set("speech string", "growl");
    obj->set("describe string", "angrily");

    obj->force_me("message in trots in quickly");
    obj->force_me("message out darts quickly to the $D");

    return 1;
}

// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    tell_object(obj, "%^RESET%^%^RED%^%^BOLD%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj, "%^RESET%^%^RED%^You can feel your body beginning to change!");
    tell_object(obj, "%^RESET%^%^RED%^%^BOLD%^Your senses heighten, you can feel the pulse of the night, smell countless scents, you can taste the very air. You are one with the wilds. You are TIGER!");

    tell_room(environment(obj), "%^RESET%^%^BOLD%^" + obj->QCN + " grows very still and appears to concentrate deeply.", obj);
    tell_room(environment(obj), "%^RESET%^%^YELLOW%^" + obj->QCN + " begins to change in front of your very eyes!", obj);
    tell_room(environment(obj), "%^RED%^Where " + obj->QCN + " once stood, is now a large tiger!", obj);

    return 1;
}

// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    tell_object(obj, "%^RESET%^%^RED%^You relax your focus on the wilds.");
    tell_object(obj, "%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj, "%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your body once again.");

    tell_room(environment(obj), "%^RESET%^%^BOLD%^" + obj->QCN + "'s muscles slacken and " + obj->QS + " gets a far-away look in " + obj->QP + " eyes.", obj);
    tell_room(environment(obj), "%^RESET%^%^BLUE%^" + obj->QCN + "'s body begins to change shape, elongating and curving!", obj);
    tell_room(environment(obj), "%^RESET%^%^GREEN%^Where " + obj->QCN + " once stood, now stands a " + obj->query_race() + "!", obj);

    return 1;
}

int can_cast()
{
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    object etp, * attackers;
    string* specials = ({});
    int i, chance, dice;
    string RND_COLORS = ({ "%^ORANGE%^", "%^BOLD%^%^BLACK%^", "%^RED%^" });
    string clr = RND_COLORS[random(sizeof(RND_COLORS))];

    etp = environment(tp);

    if (!objectp(tp)) {
        return 0;
    }
    chance = (int)tp->query_level() + 10;

    if (chance > 70) {
        chance = 70;
    }

    dice = (chance / 4) + 2;

    if (roll_dice(1, 100) > chance) {
        return roll_dice(2, dice);
    }

    specials = ({ "blind",
                  "heal",
                  "trip",
                  "high damage",
                  "stun",
                  "extra attack",
                  "low damage" });

    switch (specials[random(sizeof(specials))]) {
    case "blind":
        tell_object(tp, "%^RESET%^" + clr + "You leap up and savagely tear at " + targ->QCN + "'s eyes, narrowly missing!");
        tell_object(targ, "%^RESET%^" + clr + tp->QCN + " leaps up and tears at your face, nearly ripping your eyes out!");
        tell_room(etp, "%^RESET%^" + clr + tp->QCN + " leaps up and tears at " + targ->QCN + "'s face, nearly ripping out " + targ->QP + " eyes!", ({ tp, targ }));
        if (!targ->reflex_save(chance)) {
            targ->set_temporary_blinded(dice / 2);
        }
        break;

    case "heal":
        tell_object(tp, "%^RESET%^" + clr + "You pull on " + targ->QCN + "'s essence with your attack, draining " + targ->QO + " and restoring some of your vital health!");
        tell_object(targ, "%^RESET%^" + clr + tp->QCN + "'s pulls at your essence, leaving you drained!");
        tell_room(etp, "%^RESET%^" + clr + tp->QCN + "'s wounds look less severe after " + tp->QS + " attacks " + targ->QCN + "!", ({ tp, targ }));
        tp->do_damage(tp->return_target_limb(), (dice * -1 * 2));
        targ->cause_typed_damage(targ, targ->return_target_limb(), dice * 2, get_new_damage_type());
        break;

    case "trip":
        tell_object(tp, "%^RESET%^" + clr + "You dig your fangs into " + targ->QCN + "'s shoulder and drag " + targ->QO + " to the ground!");
        tell_object(targ, "%^RESET%^" + clr + tp->QCN + " digs " + tp->QP + " fangs into your shoulder and drags you to the ground!");
        tell_room(etp, "%^RESET%^" + clr + tp->QCN + " digs " + tp->QP + " teeth into " + targ->QCN + "'s shoulder and drags " + targ->QO + " to the ground!", ({ tp, targ }));
        if (!targ->fort_save(chance)) {
            targ->set_tripped(roll_dice(1, 2), "%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!");
        }
        break;

    case "high damage":
        tell_object(tp, "%^RESET%^" + clr + "You snarl angrily and lunge, tearing deeply into " + targ->QCN + "'s flank!");
        tell_object(targ, "%^RESET%^" + clr + tp->QCN + " snarls angrily and lunges, tearing painfully into your side!");
        tell_room(etp, "%^RESET%^" + clr + tp->QCN + " snarls angrily and lunches, tearing deeply into " + targ->QCN + "'s flank!", ({ tp, targ }));
        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(dice, 4), get_new_damage_type());
        break;

    case "stun":
        if (!random(3)) {
            tell_object(tp, "%^RESET%^" + clr + "You lower your head and circle around " + targ->QCN + " before lunging, "
                        "knocking " + targ->QO + " off balance!");
            tell_object(targ, "%^RESET%^" + clr + tp->QCN + " lowers " + tp->QP + " head and circles around you before "
                        "lunging and knocking you off balance and unable to move!");
            tell_room(etp, "%^RESET%^" + clr + tp->QCN + " lowers " + tp->QP + " head and circles around " + targ->QCN + " "
                      "before lunging and knocking " + targ->QO + " off balance!", ({ tp, targ }));

            targ->set_paralyzed(roll_dice(1, 2) * 8, "%^RESET%^%^YELLOW%^You're struggling to regain your balance!");
        }
        break;

    case "extra attack":

        tell_object(tp, "%^RESET%^" + clr + "You hit the ground and twist, immediately launching another quick attack at " + targ->QCN + "!");
        tell_object(targ, "%^RESET%^" + clr + tp->QCN + " hits the ground and twists, immediately launching another attack at you!");
        tell_room(etp, "%^RESET%^" + clr + tp->QCN + " hits the ground and twists, immediately launching another attack at " + targ->QCN + "!", ({ tp, targ }));
        tp->execute_attack();
        break;

    case "low damage":
        tell_object(tp, "%^RESET%^" + clr + "You quickly snap inside " + targ->QCN + "'s defenses and bite a vulnerable spot!");
        tell_object(targ, "%^RESET%^" + clr + tp->QCN + " quickly snaps inside of your defenses and bites you!");
        tell_room(etp, "%^RESET%^" + clr + tp->QCN + " quickly snaps inside of " + targ->QCN + "'s defenses and bites " + targ->QO + "!", ({ tp, targ }));

        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(dice, 2), get_new_damage_type());
        break;
    }

    return roll_dice(2, dice);
}
