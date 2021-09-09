//Tlaloc slightly adjusted AC values up 9.3.21
inherit "/std/plate";

void create()
{
    ::create();
    set_max_dex_bonus(3);
    set_armor_prof("heavy");
    set_name("fullplate");
    set_id(({ "armor", "full plate armor", "plate", "medium fullplate" }));
    set("short", "A suit of full plate armor");
    set("long",
        "This is the impressive, high gothic style armor of the late "
        "middle ages and renaissance. It is perfectly forged and fitted. All the  "
        "plates are interlocking and carefully angled to deflect blows. The metal "
        "plates are backed by padding and chainmail. The weight is well "
        "distributed. The armor is hot and extremely expensive."
        );
    set_weight(36);
    set("value", 2000);
    set_type("armour");
    set_limbs(({ "torso" }));
    //set_ac(9);
    set_ac(11);
}

int is_metal()
{
    return 1;
}
