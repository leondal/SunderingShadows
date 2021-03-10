#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("CryptStalker");
    feat_name("slay the undead");
    feat_prereq("Crypt Stalker L4");
    feat_desc(""
"Due to the Crypt Stalker's knowledge, training and spiritual focus on the undead, "
"he is able to seek out and strike the weakness of the undead like no other. The "
"Crypt Stalker gains a greater ability to stalk and ambush its prey with the following "
"innate spells:\n\
Rope Trick, Detect Undead, Heart of Metal, Disrupting Weapon, Undeath Ward\n\
Additionally, the Crypt Stalker gets a +2 bonus to Attack and Damage rolls when fighting "
"undead enemies.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("crypt_stalker") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
