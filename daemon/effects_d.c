#include <std.h>
inherit DAEMON;

int spell_effect(object caster, object device, string command)
{
    string spell, who, cspell, stype;
    int level;
    object target, obj;

    spell = device->query("spell");
    level = device->query("level");
    cspell = "/cmds/spells/" + spell[0..0] + "/_" + replace_string(spell, " ", "_");
    stype = device->query("spell type");
    if (!stype) {
        stype = "mage";
    }

    if (!file_exists(cspell + ".c")) {
        write("%^BOLD%^ERROR unknown spell specified " + cspell + ".\n");
        error("ERROR unknown spell specified " + cspell);
        return 0;
    }

    if (command) {
        if (sscanf(command, "on %s", who) != 1) {
            return notify_fail("use <object> on <target>\n");
        }
    }else {
        who = caster->query_name();
    }

    /* if (!(target = present(who, environment(caster)))) { */
    /*     return notify_fail("No such target.\n"); */
    /* } */
    obj = new(cspell);
    caster->set_property("spell_casting", obj);
    obj->use_spell(caster, who, level, 100, stype);
    return 1;
}
