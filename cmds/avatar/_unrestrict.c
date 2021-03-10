//Changed by ~Circe~ 6/13/07 to allow for use with psionics
// /cmds/avatar/_unrestrict.c
// allows a player to use a restricted cleric or mage spell
// or removes the restriction on spell level
#include <std.h>
#define TS_D "/daemon/treesave_d.c"
inherit DAEMON;

int help();

int cmd_unrestrict(string str) {
    string name, type, spell, spellfile;
    int level;
    int res_level;
    string *res_spells;
    object who;

    string posxxx; 
    if(!objectp(TP)) { return 0; }
    posxxx = lower_case((string)TP->query_position());
    if(posxxx == "builder" || posxxx == "apprentice") {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
    }

    level = -1;
    if (!str) return help();
    if (sscanf(str,"%s %s %s", name, type, spell) != 3)
        if (sscanf(str,"%s %s", name, type) != 2) return help();

    if (!who = find_player(name)) return notify_fail("Cannot find "+name+" to unrestrict.");
    if(!who->is_class(type)) return notify_fail(capitalize(name)+" cannot cast spells as a "+type+".\n");

    if (!spell) {
        who->set_spell_level_restricted(type,0);
        TS_D->add_value_to_array("notes",who->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+type+" spells unrestricted");
        tell_object(TP,capitalize(name)+" can now memorize all levels of "+type+" spells.");
        return 1;
    }
    if (member_array(spell,who->query_spells_restricted(type)) == -1 && spell != "all")
        return notify_fail(capitalize(name)+" is not currently restricted from the "+type+" spell "+spell+".");
    who->unrestrict_spell(type,spell);
    TS_D->add_value_to_array("notes",who->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+type+" spell "+spell+" unrestricted");
    tell_object(TP,capitalize(name)+" is no longer restricted from memorizing the "+type+" spell "+spell+".");
    return 1;
}


int help() {
    write(
@HELP
Syntax:    unrestrict <player> <class> <spellname>
           or unrestrict <player> <class> all
           or unrestrict <player> <class>

This command will allow the player to use formerly restricted spells.
If a spell name is given, the player will be able to pray for or
memorize that particular spell. If no spell name is given, the player 
will be able to pray for or memorize spells of any level. 

Valid types are: wizard, psionic, and cleric

EX. <unrestrict fred cleric> means that fred can pray for all levels of
cleric spells
<unrestrict fred mage finger of death> means that fred can memorize
the spell finger of death
<unrestrict fred mage all> will allow fred to cast any spell, unless
he has had whole levels restricted.  In that case, see example 1.
HELP
    );
    return 1;
}
