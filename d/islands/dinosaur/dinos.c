#include <std.h>

inherit WEAPONLESS;

string limb;

void create()
{
    ::create();
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(TP->query_property("plant eater") && TO->query_property("meat eater")) {
      if((string)TP->query_race() == (string)TO->query_race()) return;
      TO->force_me("kill "+TP->query_name());
    }
}

void heart_beat()
{
    string *limbs;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!limb) 
    {
        limbs = (string*)TO->query_attack_limbs();
        if(!sizeof(limbs)) { limb = "body"; }
        else limb = limbs[random(sizeof(limbs))];
    }
    if(TO->query_property("plant eater")) return;
    if(TO->query_property("full")) return;
    if(!present("corpse", ETO)) return;
    tell_room(ETO, "%^BOLD%^%^RED%^The "+TO->query_short()+" devours the corpse of the dead beast!");
    present("corpse", ETO)->remove();
    TO->set_property("full", 1);
}
