#include <std.h>
inherit WEAPONLESS;

object caster;
string castname, fname;

void create(){
    ::create();
    set_name("chest");
    set_id(({"chest","secret chest","floating wooden chest","greater summon"}));
    set_short("%^RESET%^%^CYAN%^Floating %^ORANGE%^wooden %^BOLD%^c%^RESET%^%^ORANGE%^h%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^t%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is an %^BOLD%^%^ORANGE%^iro%^BLACK%^n%^ORANGE%^-bound%^RESET%^%^ORANGE%^ wooden chest that appears to float. It is quite large and could probably fit a lot of things inside.%^RESET%^");
    set_attacks_num(1);
    set_exp(1);
    set_gender("neuter");
    set_hp(40);
    set_hd(4,1);
    set_race("chest");
    set_stats("constitution",24);
    set_stats("dexterity",2);
    set_stats("strength",24);
    set_body_type("humanoid");
    remove_limb("left hand");
    remove_limb("right hand");
    remove_limb("left foot");
    remove_limb("right foot");
    remove_limb("left leg");
    remove_limb("right leg");
    add_limb("chest",0,0,0,0);
    set_attack_limbs(({"chest"}));
    setenv("MIN", "$N floats in.");
    setenv("MOUT", "$N floats off to the $D.");
}

void setup_chest(object invoker)
{
    caster = invoker;
    castname = caster->query_name();
    fname = "/d/save/summons/"+castname+"/"+query_name();
    "/daemon/yuck_d"->load_inventory(this_object(),fname);

    drop_containers();
}

void die(object obj)
{
    if (objectp(caster)) {
        caster->remove_property("has_elemental");
    }
    remove();
}

int remove()
{
    drop_containers();
    save_chest();
    all_inventory(TO)->remove();
    ::remove();
}

void drop_containers()
{
    object invitem;
    object* myinven;
    string* ids;

    if (!objectp(ETO)) {
        return;
    }

    myinven = all_inventory(TO);

    foreach(invitem in myinven)
    {
        if (!invitem->is_container()) {
            continue;
        }

        if (sizeof(all_inventory(invitem))) {
            ids = invitem->query_id();
            force_me("drop " + ids[0]);
        }
    }
}

void save_chest()
{
    /* seteuid(getuid()); */
    if(!objectp(TO))
        return;
    if(!objectp(ETO))
        return;

    mkdir("/d/save/summons/"+castname);
    mkdir(fname);
    "/daemon/yuck_d"->save_inventory(this_object(),fname);
}

void receive_given_item(object obj)
{
    string * ids;

    if (!obj->is_container()) {
        return;
    }

    if (sizeof(all_inventory(obj))) {
        ids = obj->query_id();
        force_me("drop " + ids[0]);
    }
}
