#include <std.h>
#include <daemons.h>

inherit FEAT;

int FLAG;

#define FEATTIMER 35

// Three things are necessary to set in create in all feats.  First, the type of feat
// either instant or duration or permanent.  The type of feat will tell the inherit
// how to interact with it.  Second, the category of the feat.  This will tell the
// mortal command _feats.c, what to display the feat as in the list.  And finally the
// name of the feat.  This is also used in the display of the feat's name in the feats
// command and for farious functions related to the feat in the feat daemon
void create()
{
    ::create();
    feat_type("instant");
    feat_category("WeaponAndShield");
    feat_name("shieldbash");
    feat_syntax("shieldbash [TARGET]");
    feat_desc("Shieldbash is an instant effect feat that  can be used to slam a shield into the target and stun them for  a brief time. In addition, if the target fails to make a  fortitude save, they will be unable to cast spells for a brief time  after the shieldbash.

If used without an argument this feat will pick up a random attacker.");
    // Sets the type of saving throw to use, same as used in spell.c
    set_save("fort");
    // This tells the feat daemon what feats this one is required for, it's needed for
    // removing feats from players so they don't remove one that they are going to need
    set_required_for(({ "shieldwall", "deflection", "reflection", "counter" }));
}

int allow_shifted()
{
    return 0;
}

// This is the function that tells the feat if the player is able to buy/gain it.  It
// also gets called every time the feat is used.  If at any time the player fails to
// meet the prerequisites, they will be unable to use the feat.  For example, if a feat
// requires an 18 strength, and a monster drains their strength so it's at 16, they will
// not be able to use the feat until they recover their strength.
// ***** NOTE *****  Each feat in a chain should only have the feat before it as a
// prerequisite.  For example.. two weapon fighting requires ambidexterity, improved
// two weapon fighting requires ambidexterity and two weapon fighting.  Only add
// the last feat in the chain to the list of prerequisites because the feat daemon
// will loop through the whole list every time the feat is called. (many, many, many times)
int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    return ::prerequisites(ob);
}

// For instant feats, you need the int cmd_command_name(string str) structure.  This is to
// make sure that the correct arguments get passed along to the feat.  Instant feats are those
// feats that act like commands.  They usually will have targets and will do something directly
// to either the target, or to the caster
int cmd_shieldbash(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    // After you get TP, which will be caster, you can pass it along to setup_feat.  MUST BE
    // an object IE feat = new(base_name(TO)).  **If it's not an object, it will error**  This
    // will be the case with all instant type feats that act like commands.  str is optional,
    // and is only needed if there is a target required for the feat.  If there is not a target
    // simply pass an empty string along to setup_feat.  IE. setup_feat(TP, "")
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

// execute_feat() is where the work of the feat begins to take place.  execute_feat() is called
// from setup_feat() so you don't have to call it directly.  You must make a call to ::execute_feat()
// inside of your execute_feat() function in order to make sure it goes through all the checks
// needed to make sure the caster is capable of using the feat, and make sure the target gets
// assigned.  Once you've called ::execute_feat(), the rest of the feat will work like any ordinary
// command.  You MUST CALL dest_effect() when you want the feat to end, or it will error.
void execute_feat()
{
    mapping tempmap;
    // ::execute_feat This handles assigning single targets for feats with one target.
    // It also runs through prerequisite checks to make sure the caster is able to use the feat.
    ::execute_feat();

    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (target == caster) {
        tell_object(caster, "You cannot shieldbash yourself!");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using shieldbash");

    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to shieldbash.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    if (!(int)caster->is_wearing_type("shield")) {
        tell_object(caster, "You need to be wearing a shield in order to shieldbash "
                    "someone!");
        dest_effect();
        return;
    }
    if (!objectp(target)) {
        tell_object(caster, "%^BOLD%^Nobody to shieldbash.%^RESET%^");
        dest_effect();
        return;
    }
    tell_object(caster, "%^YELLOW%^You let out a fierce growl and lunge at " + target->QCN + " with your "
                "full weight behind your shield!%^RESET%^");
    tell_object(target, "%^RED%^" + caster->QCN + " lets out a fierce growl and lunges at you with "
                "" + caster->QP + " shield!%^RESET%^");
    tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + " lets out a fierce growl and lunges "
              "at " + target->QCN + " with " + caster->QP + " shield!%^RESET%^", ({ target, caster }));
    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    return;
}

// execute_attack() will run on it's own automatically if you have not yet made a call to dest_effect()
// For instant type feats, it's best to put the damage or action part of the feat here.  That will give
// a 1 combat round delay before the action takes place.
void execute_attack()
{
    int dam, mod, i, timerz, res;
    object* keyz;
    mapping tempmap, newmap;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack(); //please try to ensure trackers are removed before execute attack or they may get lost.

    if (!objectp(target) || !present(target, place)) {
        tell_object(caster, "Your target is no longer here!");
        // It's very important that dest_effect() is called when the feat ends.  If not, it
        // will break combat in the room where the feat was used
        caster->remove_property("using shieldbash");
        dest_effect();
        return;
    }

    if (!caster->is_wearing_type("shield")) {
        tell_object(caster, "%^BOLD%^You need to be wearing a shield to "
                    "do shieldbash someone!%^RESET%^");
        caster->remove_property("using shieldbash");
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using shieldbash"); // adding per-target tracking. -N, 9/10.
    if (!mapp(tempmap)) {
        tempmap = ([]);
    }
    if (tempmap[target]) {
        map_delete(tempmap, target);
    }
    newmap = ([]);
    keyz = keys(tempmap);
    if (sizeof(keyz)) {
        for (i = 0; i < sizeof(keyz); i++) {
            if (objectp(keyz[i])) {
                newmap += ([ keyz[i] : tempmap[keyz[i]] ]);
            }
        }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target:timerz ]);
    delay_subject_msg(target, FEATTIMER, "%^BOLD%^%^WHITE%^" + target->QCN + " can be %^CYAN%^shieldbashed%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using shieldbash");
    caster->set_property("using shieldbash", newmap);

    if (!(res = thaco(target))) {
        tell_object(caster, "%^RED%^" + target->QCN + " sidesteps your shieldbash at the "
                    "last instant and you scramble to stay on your feet!%^RESET%^");
        tell_object(target, "%^BOLD%^%^GREEN%^You sidestep " + caster->QCN + "'s attempt "
                    "to hit you with " + caster->QP + " shield, leaving " + caster->QO + " off balance!%^RESET%^");
        tell_room(place, "%^BOLD%^" + target->QCN + " sidesteps at the last instant, avoiding "
                  "" + caster->QCN + "'s shieldbash and leaving " + caster->QCN + " off balance!", ({ target, caster }));
        if (!FEATS_D->usable_feat(caster, "improved shieldbash")) {
            caster->set_paralyzed(roll_dice(4, 6), "%^MAGENTA%^You're struggling to stay on your feet!%^RESET%^");
        }
        // It's very important that dest_effect() is called when the feat ends.  If not, it
        // will break combat in the room where the feat was used
        dest_effect();
        return;
    }else if (res == -1) {
        if (stringp(caster->query("featMiss"))) {
            tell_object(caster, caster->query("featMiss") + " " + query_feat_name() + "!");
            caster->delete("featMiss");
        }else {
            tell_object(caster, "%^RED%^" + target->QCN + " is totally unaffected!%^RESET%^");
            tell_room(place, "%^RED%^" + target->QCN + " is totally unaffected!%^RESET%^", ({ target, caster }));
        }
        dest_effect();
        return;
    }
    dam = clevel;

    tell_object(caster, "%^YELLOW%^You slam your shield full force into " + target->QCN + " "
                "battering " + target->QO + " painfully!%^RESET%^");
    tell_object(target, "%^RED%^You are unable to avoid " + caster->QCN + "'s shieldbash and "
                "get slammed painfully!%^RESET%^");
    tell_room(place, "%^BOLD%^" + target->QCN + " is unable to avoid " + caster->QCN + "'s shieldbash "
              "and staggers back in pain as " + target->QS + " is slammed hard!%^RESET%^", ({ target, caster }));
    target->set_paralyzed(roll_dice(6, 4), "%^MAGENTA%^You are trying to regain your senses!%^RESET%^");
    target->cause_typed_damage(target, "head", dam, "bludgeoning");

    if (!objectp(target)) {
        dest_effect();
        return;
    }

    mod = dam;
    mod += clevel - (int)target->query_highest_level();
    mod = mod * -1;
    // You have to calculate your opposed modifiers for the new saving throws manually.
    // In this case, I use the damage of the shieldbash, plus or minus the level difference.
    // NEGATIVE modifiers will help the caster, which is what we want because target modifiers
    // are already added in the saving throw daemon.
    if (!do_save(target, mod)) {
        FLAG = 1;
        if (interactive(target)) {
            target->set_static("spell interrupt", "%^RED%^Your head is still hazy from being "
                               "slammed with " + caster->QCN + "'s shield!%^RESET%^");
        }else {
            target->spell_interrupt("spell interrupt", "%^RED%^Your head is still hazy from being "
                                    "slammed with " + caster->QCN + "'s shield!%^RESET%^");
        }
        call_out("dest_effect", roll_dice(4, 6));
        return;
    }
    // It's very important that dest_effect() is called when the feat ends.  If not, it
    // will break combat in the room where the feat was used
    dest_effect();
    return;
}

// dest_effect() needs to be called any time a feat ends to make sure the object gets cleaned out
// of memory and removed from the room's combat cycle.  The call to ::dest_effect() makes sure that
// the caster and the feat are both still valid objects.  remove_feat(TO) will dest the feat and make
// sure that combat doesn't break.
void dest_effect()
{
    if (FLAG && objectp(target)) {
        if (interactive(target)) {
            target->set_static("spell interrupt", 0);
        }else {
            target->remove_property("spell interrupt");
        }
    }
    ::dest_effect();
    // You need to remove the feat in your dest_effect() function, to make sure it cleans
    // up any additional combat code.  If not, it can break combat.
    remove_feat(TO);
    return;
}
