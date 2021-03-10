#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Duelist");
    feat_name("bladesong");
    feat_desc("With this feat one learns how to use just one hand to channel their spells. The caster can use their spells while wielding a weapon in their second hand. This feat requiers you not to wield a second weapon or shield to work.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    object *weapons;
    if(!objectp(ob)) { return 0; }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
