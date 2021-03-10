#include <std.h>
inherit OBJECT;

object caster, * mons = ({});
string * undead_list = ({ "skeleton", "graveknight", "skelemage", "skelehorse", "vampire_spawn", "vampire_knight", "animus", });
int count;

void save_me(string file)
{
    return 1;
}

void create()
{
    ::create();
    set_name("device");
    set("id", ({ "undead_controller" }));
    set("short", "");
    set("long", "");
    set_weight(0);
}

int move(mixed dest)
{
    if (ETO && objectp(ETO)) {
        if (interactive(ETO)) {
            return 0;
        }
    }
    ::move(dest);
    set_heart_beat(10);
}

set_caster(object ob)
{
    if (objectp(ob)) {
        caster = ob;
    }else {
        remove();
    }
}

object* query_mons()
{
    return mons;
}

object query_caster()
{
    return caster;
}

void add_monster(object obj)
{
    if (!objectp(obj)) {
        return;
    }
    mons += ({ obj });
}

int clean_mons()
{
    object* temp = ({});
    int i;
    int poolsize;

    for (i = 0; i < sizeof(mons); i++) {
        if (!objectp(mons[i])) {
            continue;
        }
        temp += ({ mons[i] });
        poolsize += (int)mons[i]->query_property("raised");
    }
    if (!sizeof(temp)) {
        if (objectp(TO)) {
            TO->remove();
        }
        return 1;
    }

    caster->remove_property("raised");
    caster->set_property("raised", poolsize);

    mons = temp;
    return 0;
}

void heart_beat()
{
    if (!objectp(caster)) {
        remove();
    }
    clean_mons();
}

void remove()
{
    int i;
    for (i = 0; i < sizeof(mons); i++) {
        if (objectp(mons[i])) {
            mons[i]->die();
        }
    }
    if (objectp(caster)) {
        caster->remove_property("raised");
    }
    return ::remove();
}

void init()
{
    ::init();
    add_action("cmd", "command");
    add_action("dismiss", "dismiss");
    add_action("poolsize", "poolsize");
}

int poolsize(string str)
{
    int pool;

    clean_mons();
    pool = (int)caster->query_property("raised");
    if (pool) {
        tell_object(caster, "%^BOLD%^%^BLACK%^YOUR UNDEAD POOL IS FILLED WITH %^WHITE%^" + pool + "%^BLACK%^ UNDEAD.%^RESET%^");
    }else {
        tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^THERE IS NO DEAD THAT FOLLOWS %^BLACK%^Y%^BLACK%^O%^BLACK%^U%^RESET%^%^RESET%^");
    }

    return 1;
}

int cmd(string str)
{
    object ob;
    string what, who, what2, holder;
    int i, flag;

    if (clean_mons()) {
        return 0;
    }

    if (!str) {
        return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^PROVIDE YOUR DEMMANDS%^RESET%^%^RESET%^");
    }

    if (sscanf(str, "%s to %s", who, what) != 2) {
        return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^YOU MUST TELL WHAT TO DO%^RESET%^%^RESET%^");
    }

    if (who != "undead") {
        return 0;
    }

    if (what[0..3] == "kill") {
        flag = 1;
        if (sscanf(what, "kill %s", who) == 1) {
            if (ob = present(who, environment(caster))) {
                if (!caster->ok_to_kill(ob)) {
                    return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^KILLING THAT IS ABOVE YOU%^RESET%^%^RESET%^");
                }
            }
        }
    }

    if (what == "follow") {
        flag = 1;
        for (i = 0; i < sizeof(mons); i++) {
            if (!objectp(mons[i])) {
                continue;
            }
            if (!present(mons[i], environment(caster))) {
                continue;
            }
            caster->add_follower(mons[i]);
            tell_object(caster, "%^BOLD%^%^BLACK%^YOUR " + mons[i]->query_short() + "%^BOLD%^%^BLACK%^ OBEYS TO FOLLOW.%^RESET%^");
        }
        return 1;
    }

    for (i = 0; i < sizeof(mons); i++) {
        if (!mons[i]->force_me(what)) {
            continue;
        }
    }
    return 1;
}

int dismiss(string str)
{
    int i;

    if (!str || str != "undead") {
        return 0;
    }
    tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^THE SOULS %^BLACK%^R%^BLACK%^E%^BLACK%^J%^BLACK%^O%^BLACK%^I%^BLACK%^C%^BLACK%^E%^BLACK%^ IN %^BLACK%^F%^BLACK%^R%^BLACK%^E%^BLACK%^E%^BLACK%^D%^BLACK%^O%^BLACK%^M%^RESET%^%^RESET%^");
    tell_room(environment(caster), "%^BOLD%^%^GREEN%^The undead creature crumble to dust!%^", ({ caster }));
    remove();
    return 1;
}
