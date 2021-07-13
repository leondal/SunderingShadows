#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PaleLord");
    feat_name("death touch");
    feat_syntax("death_touch [TARGET]");
    feat_prereq("Pale Lord L7");
    feat_desc("A final step for Pale Lord is to construct a conduit, a point he can release the power of the death itself. To do so he cuts off own hand, treats it with mummifying solutions, then lays a network of fell spells over it and attaches it back. Such hand can release negative energy on demand, ripping the souls of living and healing the undead.

If used without an argument this feat will pick up a random attacker.");
    set_save("will");
}

string get_casting_stat()
{
    string mycastingstat;
    string fname;

    if (!objectp(caster)) {
        return;
    }

    fname = "/std/class/" + caster->query("base_class") + ".c";

    if (!file_exists(fname)) {
        mycastingstat = "intelligence";
    } else {
        mycastingstat = fname->query_casting_stat(caster);
        if (!mycastingstat) {
            mycastingstat = "intelligence";
        }
    }

    return mycastingstat;
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("pale_lord") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_death_touch(string str)
{
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    object *weapons;
    int x;
    ::execute_feat();
    tempmap = caster->query_property("using death touch");

    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (mapp(tempmap)) {
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to affect.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info", caster);
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (caster->query_casting()) {
        tell_object(caster, "%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if (!objectp(place)) {
        tell_object(caster, "You're not there!");
        dest_effect();
        return;
    }
    if (target == caster) {
        tell_object(caster, "There are better ways to kill yourself.");
        dest_effect();
        return;
    }
    if (environment(target) != environment(caster)) {
        tell_object(caster, "That is not here!");
        dest_effect();
        return;
    }

    if (mapp(tempmap)) {
        if (tempmap[target] > time()) {
            tell_object(caster, "That target is still wary of such an attack!");
            dest_effect();
            return;
        }
    }
    caster->set_property("using instant feat",1);

    tell_object(caster, "%^RESET%^%^BLUE%^You point a finger at "+target->QCN+".%^RESET%^");
    tell_room(place, "%^RESET%^%^BLUE%^"+caster->QCN+" points a finger at "+target->QCN+".%^RESET%^", ({ caster }));
    return;
}

void execute_attack()
{
    int damage, timerz, i;
    int bonusdc;
    object *keyz, shape, *weapons, myweapon, qob;
    mapping tempmap;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    caster->remove_property("using instant feat");
    ::execute_attack();

    if (!objectp(target)) {
        dest_effect();
        return;
    }
    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if (!objectp(target) || !present(target, place)) {
        tell_object(caster, "Your target has eluded you!");
        dest_effect();
        return;
    }
    if (target->query_property("negative energy affinity") || FEATS_D->usable_feat(target, "undead graft")) {
        tell_room(place, "%^BLUE%^" + target->QCN + " is healed completely!%^RESET%^", caster);
        target->add_hp(target->query_max_hp());
        return;
    }

    tempmap = caster->query_property("using death touch");

    if (!mapp(tempmap)) {
        tempmap = ([]);
    }
    if (tempmap[target]) {
        map_delete(tempmap, target);
    }
    keyz = keys(tempmap);
    for (i = 0; i < sizeof(keyz); i++) {
        if (!objectp(keyz[i])) {
            map_delete(tempmap, keyz[i]);
        }
        continue;
    }

    timerz = time() + 180;
    delay_subject_msg(target,180,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^death touched%^WHITE%^ again.%^RESET%^");
    tempmap += ([ target : timerz ]);
    caster->remove_property("using death touch");
    caster->set_property("using death touch",tempmap);

    weapons = caster->query_wielded();

    if (sizeof(weapons)) {
        myweapon = weapons[0];
    }

    tell_object(caster,"%^BLUE%^A ray of deadly negative energy releases of your finger and hits "+target->QCN+"!");
    tell_room(place,"%^BLUE%^A ray of death releases of "+caster->QCN+"'s finger and hits "+target->QCN+"!",caster);

    bonusdc = BONUS_D->query_stat_bonus(caster, get_casting_stat());;
    spell_kill(target,caster);
    if((string)target->query_property("no death") ||do_save(target,bonusdc))
    {
        tell_object(target,"%^BOLD%^Your soul struggles, but manages to survive.");
        tell_room(place,"%^BOLD%^%^BLUE%^"+target->QCN+" is harmed but manages to survive the death!",target);
        target->cause_typed_damage(target, target->return_target_limb(),roll_dice(clevel,10),"negative energy");
    } else {
        tell_room(place,"%^BOLD%^%^WHITE%^The soul is pushed beyond %^MAGENTA%^the veil%^WHITE%^ from its coil!");
        tell_room(place,"%^BOLD%^%^WHITE%^The lifeless husk of "+target->QCN+" drops to the ground!",target);
        tell_object(target,"%^BOLD%^%^MAGENTA%^Your soul is ripped from you body!\n");
        target->cause_typed_damage(target, target->return_target_limb(),target->query_max_hp()*2,"negative energy");
    }

    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
