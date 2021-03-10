#include <std.h>
#include <daemons.h>
#include <magic.h>


inherit OBJECT;

object owner, * targets, * party_members, my_room;
mapping buffs, party_targets = ([]), special_spells_map = ([]);
string* spells = ({}), * normal_spells = ({}), * targeted_spells = ({}), * special_spells = ({}), * party_target_spells = ({}), * special_target_spells = ({});
string* normal_spells_cast = ({}), * special_target_spells_cast = ({}), * party_target_spells_cast = ({});
string* normal_special_spells = ({}), * normal_special_spells_cast = ({}), * special_specials = ({}), * special_specials_cast = ({}), * party_special = ({});
int party, count;


void create()
{
    ::create();
    party = 0;
    count = 0;
    set_heart_beat(1);
    set_property("no detect", 1);
    set_id(({ "buffobxyz" }));
    set_name("buff object");
}
void init()
{
    ::init();
    add_action("abort", "abort");
    add_action("abort", "stop");
}
void abort()
{
    owner_check();
    tell_object(owner, "Aborting...");
    if (objectp(TO)) {
        TO->remove();
    }
    return;
}
void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }

    if (!objectp(ETO)) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    if (my_room != EETO) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    owner_check();

    if (ETO != owner) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    if (sizeof(owner->query_attackers())) {
        tell_object(owner, "The fighting breaks your concentration, you need to be at peace to buff.");
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    count++;

    if (count > 90) { // delete in 90 heart beats if heart_beat error doesn't stop it from counting - should be deleted next time buff is used anyway
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    if (!sizeof(spells)) {
        if (!mapp(buffs) || !sizeof(keys(buffs))) {
            buffs = (mapping)owner->query("buff_list");
            if (!mapp(buffs) || !sizeof(keys(buffs))) {
                tell_object(owner, "You don't have any buffs to cast.");
                if (objectp(TO)) {
                    TO->remove();
                }
                return;
            }
            spells = keys(buffs);
            sort_spells(); // normal, targeted, special
        }
    }

    if (!objectp(TO)) {
        return;
    }

    cast_normal_spells();

    cast_special_spells();

    return;
}
void cast_special_spells()
{
    object targ;
    string special, spell, myclass, file, my_target, * to_cast = ({}), * been_cast = ({});
    int i, j;

    owner_check();
    if (!sizeof(special_spells)) {
        return;
    }

    if (owner->query_casting()) {
        return;
    }

    if (sizeof(special_spells)) {
        normal_special_spells = ({});
        party_special = ({});
        special_specials = ({});

        for (i = 0; i < sizeof(special_spells); i++) {
            spell = special_spells[i];
            if (!buffs[spell]) {
                continue;
            }
            special = buffs[spell]["special"];
            /* myclass = get_class(spell); */
            myclass = explode(buffs[spell]["special"], " ")[1];

            if (special) {

                if (strsrch(special, "$T") != -1) {
                    party_special += ({ spell });
                    continue;
                }

                if (strsrch(special, "$") != -1) {
                    special_specials += ({ spell });
                    continue;
                }

                if (strsrch(special, "$") == -1) {
                    normal_special_spells += ({ spell });
                    continue;
                }
            }
        }

        if (sizeof(normal_special_spells)) {
            for (i = 0; i < sizeof(normal_special_spells); i++) {
                spell = normal_special_spells[i];

                if (member_array(spell, normal_special_spells_cast) != -1) {
                    continue;
                }

                if (has_spell(owner, spell)) {
                    normal_special_spells_cast += ({ spell });
                    continue;
                }

                special = buffs[spell]["special"];
                if (!special) {
                    tell_object(owner, "Your spell " + spell + " doesn't seem to have a special cast string.  Aborting...");
                    if (objectp(TO)) {
                        TO->remove();
                    }
                    return;
                }

                /* myclass = cast_check(spell); */
                tell_object(owner, "Attempting to: " + special);
                owner->force_me(special);
                normal_special_spells_cast += ({ spell });
                return;
            }
        }

        // these work basically the same as the normal special spells, but with slightly more robust target checking -Ares
        if (sizeof(special_specials)) {
            for (i = 0; i < sizeof(special_specials); i++) {
                spell = special_specials[i];

                if (member_array(spell, special_specials_cast) != -1) {
                    continue;
                }

                // not 100% sure on this, since it's possible for them to have strings with odd targets, may have to remove or make them specify a target with $  -observe for now -Ares
                if (has_spell(owner, spell)) {
                    special_specials_cast += ({ spell });
                    continue;
                }

                special = buffs[spell]["special"];
                if (!special) {
                    tell_object(owner, "Your spell " + spell + " doesn't seem to have a special cast string.  Aborting...");
                    if (objectp(TO)) {
                        TO->remove();
                    }
                    return;
                }

                my_target = parse_special_target(special);

                if (!objectp(targ = present(my_target, environment(owner)))) {
                    if (!objectp(targ = present(my_target, owner))) {
                        tell_object(owner, "Your target " + my_target + " doesn't seem to be here.");
                        if (objectp(TO)) {
                            TO->remove();
                        }
                        return;
                    }
                }

                myclass = cast_check(spell);
                special = replace_string(special, "$" + my_target, my_target);

                tell_object(owner, "Attempting to: " + special);
                owner->force_me(special);
                special_specials_cast += ({ spell });
                return;
            }
        }

        if (sizeof(party_special)) {
            if (party && !sizeof(party_members)) {
                party_members = query_party();
                if (!sizeof(party_members)) {
                    party_members += ({ owner });
                }
            }

            for (i = 0; i < sizeof(party_members); i++) {
                special_spells_map[party_members[i]] = ([ "party_special_spells" : party_special ]);
            }
        }

        if (party) {
            party_members = query_party();
            if (!sizeof(party_members)) {
                party_members += ({ owner });
            }
        }

        if (sizeof(party_special) && sizeof(party_members)) {
            for (i = 0; i < sizeof(party_members); i++) {
                targ = party_members[i];
                if (!objectp(targ)) {
                    continue;
                }

                to_cast = special_spells_map[targ]["party_special_spells"];
                been_cast = special_spells_map[targ]["party_special_spells_cast"];
                if (!pointerp(been_cast)) {
                    been_cast = ({});
                }

                if (sizeof(to_cast) == sizeof(been_cast)) {
                    continue;
                }

                for (j = 0; j < sizeof(to_cast); j++) {
                    spell = to_cast[j];
                    if (environment(targ) != environment(owner)) {
                        been_cast += ({ spell });
                        special_spells_map[targ]["party_special_spells"] = to_cast;
                        special_spells_map[targ]["party_special_spells_cast"] = been_cast;
                        continue;
                    }

                    // not 100% sure on this, since it's possible for them to have strings with odd targets, may have to remove or make them specify a target with $  -observe for now -Ares
                    if (has_spell(targ, spell)) {
                        been_cast += ({ spell });
                        special_spells_map[targ]["party_special_spells"] = to_cast;
                        special_spells_map[targ]["party_special_spells_cast"] = been_cast;
                        continue;
                    }

                    my_target = (string)owner->knownAs((string)targ->query_true_name());
                    special = buffs[spell]["special"];

                    if (!special) {
                        tell_object(owner, "Your spell " + spell + " doesn't seem to have a special cast string.  Aborting...");
                        if (objectp(TO)) {
                            TO->remove();
                        }
                        return;
                    }

                    myclass = cast_check(spell);
                    special = replace_string(special, "$T", my_target);
                    tell_object(owner, "Attempting to: " + special);
                    owner->force_me(special);
                    been_cast += ({ spell });
                    special_spells_map[targ]["party_special_spells"] = to_cast;
                    special_spells_map[targ]["party_special_spells_cast"] = been_cast;
                    return;
                }
            }
        }
    }
}

void cast_normal_spells()
{
    string myclass, first_letter, file, spell;
    int i;

    owner_check();

    if (!sizeof(normal_spells)) {
        return;
    }

    if (owner->query_casting()) {
        return;
    }

    for (i = 0; i < sizeof(normal_spells); i++) {
        spell = normal_spells[i];
        if (member_array(spell, normal_spells_cast) != -1) {
            continue;
        }

        if (has_spell(owner, spell)) {
            normal_spells_cast += ({ spell });
            continue;
        }

        file = get_file(spell);
        myclass = cast_check(spell);

        if (file->query_target_required()) {
            owner->force_me("cast " + myclass + " " + spell + " on " + (string)owner->query_true_name());
            normal_spells_cast += ({ spell });
            return;
        }else  {
            owner->force_me("cast " + myclass + " " + spell);
            normal_spells_cast += ({ spell });
            return;
        }
        return;
    }

    return;
}
// might require tweaking
int has_spell(object target, string spell)
{
    object* spells = ({}), target_object, * owner_spells = ({});
    string spell_name;
    int i, j;

    owner_check();

    if (!stringp(spell) || spell == "" || spell == " ") {
        return 0;
    }
    if (!objectp(target)) {
        target = owner;
    }

    if (pointerp(target->query_property("spelled"))) {
        spells = (object)target->query_property("spelled");
    }
    if (pointerp(target->query_property("dispellable spells"))) {
        spells = spells + (object)target->query_property("dispellable spells");
    }

    if (pointerp(owner->query_property("spelled"))) {
        owner_spells = (object)owner->query_property("spelled");
    }
    if (pointerp(owner->query_property("dispellable spells"))) {
        owner_spells = owner_spells + (object)owner->query_property("dispellable spells");
    }

    if (sizeof(owner_spells)) {
        for (i = 0; i < sizeof(owner_spells); i++) {
            if (!objectp(owner_spells[i])) {
                continue;
            }
            if (!owner_spells[i]->query_target_required()) {
                continue;
            }
            if ((string)owner_spells[i]->query_spell_name() != spell) {
                continue;
            }
            target_object = (object)owner_spells[i]->query_target_object();
            if (target_object == target) {
                return 1;
            }
            continue;
        }
    }

    if (sizeof(spells)) {
        for (i = 0; i < sizeof(spells); i++) {
            if (!objectp(spells[i])) {
                continue;
            }
            spell_name = (string)spells[i]->query_spell_name();
            if (spell_name == spell) {
                if (spells[i]->query_target_required()) {
                    target_object = (object)spells[i]->query_target_object();
                    if (target_object == target) {
                        return 1;
                    }
                    continue;
                }
                return 1;
            }
        }
    }

    return 0;
}
string get_class(string spell)
{
    string* classes, myclass, file;
    int i, level;

    if (!stringp(spell) || spell == "" || spell == " ") {
        return 0;
    }

    owner_check();
    classes = (string)owner->query_classes();
    file = get_file(spell);

    if (sizeof(owner->query_innate_spells()))
        if (member_array(spell, owner->query_innate_spells()) != -1) {
            return "innate";
        }

    for (i = 0; i < sizeof(classes); i++) {
        myclass = classes[i];
        level = (int)file->query_spell_level(myclass);
        if (myclass == "bard" ||
            myclass == "sorcerer" ||
            myclass == "oracle" ||
            myclass == "magus" ||
            myclass == "inquisitor") {
            if (owner->can_memorize(myclass, "level " + level)) {
                return myclass;
            }
        }
        if (owner->can_memorize(myclass, spell)) {
            return myclass;
        }
    }
    return 0;
}
mixed can_cast(string spell)
{
    string* classes, first_letter, myclass, file, improv;
    int i, level;

    owner_check();
    if (!stringp(spell) || spell == "" || spell == " ") {
        return 0;
    }
    classes = (string)owner->query_classes();
    file = get_file(spell);
    if (file == "" || !file_exists(file)) {
        tell_object(owner, "The spell " + spell + " can't be found.");
        return 0;
    }
    if (sizeof(owner->query_innate_spells()))
        if (member_array(spell, owner->query_innate_spells()) != -1) {
            return "innate";
        }
    for (i = 0; i < sizeof(classes); i++) {
        myclass = classes[i];
        level = (int)file->query_spell_level(myclass);
        improv = "level " + level;
        if (MAGIC_D->can_cast(owner, level, myclass, improv, 0)) {
            return myclass;
        }
        if (MAGIC_D->can_cast(owner, level, myclass, spell, 0)) {
            return myclass;
        }
    }
    tell_object(owner, "You can't cast the spell " + spell + ", please make sure you have it prepared.");
    return 0;
}
void sort_spells()
{
    mapping buff;
    string spell;
    int i;
    if (!sizeof(spells)) {
        return;
    }
    for (i = 0; i < sizeof(spells); i++) {
        spell = spells[i];
        buff = buffs[spell];
        if (buff["special"]) {
            special_spells += ({ spell });
        }else {
            normal_spells += ({ spell });
        }
    }
    return;
}
object* query_party()
{
    string my_party;
    object* people;

    my_party = (string)owner->query_party();
    if (!my_party) {
        tell_object(owner, "You aren't in a party.  Aborting...");
        if (objectp(TO)) {
            TO->remove();
        }
        return 0;
    }
    people = "/adm/daemon/party_d.c"->query_party_members(my_party);
    return people;
}
string cast_check(string spell)
{
    string myclass;
    owner_check();
    if (!myclass = can_cast(spell)) {
        tell_object(owner, "You can't seem to cast the spell: " + spell + ".  Aborting...");
        if (objectp(TO)) {
            TO->remove();
        }
        return 0;
    }
    return myclass;
}
string get_file(string spell)
{
    return (string)MAGIC_D->get_spell_file_name(spell);
}
object pick_special_target(string name)
{
    object targ;
    owner_check();
    name = replace_string(name, "$", "");
    targ = present(name, environment(owner));
    if (objectp(targ)) {
        return targ;
    }
    return 0;
}
string parse_special_target(string special)
{
    string* temp, * name;
    if (!stringp(special)) {
        return 0;
    }
    temp = explode(special, "$");
    if (sizeof(temp) < 2) {
        return 0;
    }
    special = temp[1];
    temp = explode(special, " ");
    if (!sizeof(temp)) {
        return 0;
    }
    return temp[0];
}
void set_owner(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    owner = obj;
    my_room = environment(owner);
    return;
}
void do_party(int num)
{
    party = num;
    return;
}
void owner_check()
{
    if (!objectp(owner)) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }
}
void save_me(string file)
{
    return 1;
}
void restore_me(string file)
{
    return 1;
}
