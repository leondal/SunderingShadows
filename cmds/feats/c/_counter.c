#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("WeaponAndShield");
    feat_name("counter");
    feat_prereq("Deflection, Must be wearing a shield");
    feat_desc("The Counter feat will give you a high chance to launch a counter attack after you deflect an attack or reflect a spell back at the caster. This feat also causes your weapon to do additional damage when wearing a shield. This damage is further increased by how defensive your shieldwall is");
    permanent(1);
    set_target_required(0);
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!FEATS_D->has_feat(ob, "deflection")) {
        dest_effect();
        return 0;
    }
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
