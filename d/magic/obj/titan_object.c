#include <std.h>
#include <clock.h>

inherit WEAPONLESS;

object titan, caster, controller,feat;

void create()
{
    ::create();
    set_name("Armored Titan");
    set_id(({"titan","armored titan","Titan","Armored Titan"}));
    set("magic",1);
    set_race("human");
    set_size(4);
    set_short("Armored Titan");
    set_long("%^RESET%^Before you stands a suit of %^BOLD%^%^BLACK%^gleaming titanium "
        "armor%^RESET%^.  Taller than a firbolg, you imagine it would only fit a giant of "
        "massive proportions.  Grossly oversized gauntleted fists lie clenched at its "
        "sides, supported by riveted arms to allow for movement.  A pair of metal-booted "
        "feet lie beneath the %^RED%^solid %^RESET%^legs of armor that hold the entire "
        "suit upright.  Atop the bulky chest rests a %^BLUE%^dark visored helm%^RESET%^, "
        "from within which glow %^BOLD%^%^CYAN%^pi%^WHITE%^n%^CYAN%^points %^RESET%^of light "
        "that are eerily reminiscent of eyes gazing out.  Occasionally as it moves, glowing "
        "%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^une%^BOLD%^s %^RESET%^light up at various points "
        "across its great armored frame, leaving little doubt that the construct is powered "
        "by some form of magic.%^RESET%^");
    seteuid(geteuid(TO));
   set_property("knock unconscious",1);
}

void heart_beat()
{
    string party;
    
    ::heart_beat();

    if(!objectp(caster)) { remove(); }

    if(!objectp(TO)) { return; }

    TO->remove_attacker(0);

    if(!TO->query_party())
    {
        party = (string)caster->query_party();
        if(!party) 
        { 
            party = ""+caster->query_name()+" party"; 
            "/adm/daemon/party_d.c"->add_member(caster,party);
            "/adm/daemon/party_d.c"->add_member(TO,party);
        }
        else
        {
            "/adm/daemon/party_d.c"->add_member(TO,party);
        }
    }

    if(query_hp() < query_max_hp())
    {
        add_hp(query_max_hp() / 25);
    }
}

void die(object ob)
{
    if(!objectp(TO)) { remove(); }

    tell_room(ETO,"%^BOLD%^"+TO->query_short()+" winks out of existance!%^RESET%^");

    if(sizeof(all_inventory(TO))) { all_inventory(TO)->move(ETO); }

    if(objectp(caster)) 
    {
        caster->remove_property_value("active_feats",({feat}));
        if(objectp(feat)) { feat->dest_effect(); }
        caster->set_property("armoredtitan_timer", time() + HOUR); 
    }

    if(objectp(controller))
    {
        controller->move("/d/shadowgate/void");
        controller->remove();
    }
    if(objectp(TO))
    {
        TO->move("/d/shadowgate/void");
        TO->remove();        
    }   
}

void set_feat(object ob)
{
    if(objectp(ob)) { feat = ob; }
    return;
}

void set_titan(object ob)
{
    if(objectp(ob)) { titan = ob; }
    return;
}

void set_caster(object ob)
{
    if(objectp(ob)) { caster = ob; }
    return;
}

void set_controller(object ob)
{
    if(objectp(ob)) { controller = ob; }
    return;
}

object query_feat() { return feat; }

object query_controller() { return controller; }

object query_caster() { return caster; }

object query_object() { return titan; }
