#include <std.h>

#define QN query_name()

inherit MONSTER;

object caster, *foes;

void defend();

void create()
{
    ::create();
    set_name("undead creature");
    set_id( ({ "creature", "undead creature", "undead" }) );
    set_gender("male");
    set("short", "An undead creature");
    set("long", "A creature of the undead.");
    set_level(1);
    set_body_type("human");
    set_class("fighter");
    set_alignment(9);
    set_size(2);
    set_hd(2, 1);
    set_exp(50);
    set_stats("intelligence",6);
    set_stats("wisdom",4);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity",8);
    set_stats("constitution",7);
    set_max_hp(query_hp());
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_exp(0);
    set_property("undead",1);
}

void serve(object controller)
{
    caster=controller;
    
    if(!objectp(caster)) { return 1; }
    if(!present(caster,environment(TO))) { return 1; }

    tell_object(caster,"%^CYAN%^"+query_short()+" rises from the ground and is now yours to command.");
    tell_room(environment(caster),"%^CYAN%^"+query_short()+" rises from the ground and stands "
        "at "+caster->QCN+"'s side.",caster);
    caster->add_follower(TO);
    foes=caster->query_attackers();
    call_out("check", 2);
}

int check()
{
    int i, wherefound;
    object *newfoes;
   
    if(!objectp(caster)) return 1;

    call_out("check",2);
    caster->add_protector(TO);

    if(!present(caster,environment(TO))) { return 1; }

    foes = caster->query_attackers();

    for(i=0;i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }
        if(!present(foes[i],environment(TO))) { continue; }
        if(member_array(foes[i],(object*)TO->query_attackers()) != -1) { continue; }
        
        TO->kill_ob(foes[i]);
    }
}

void defend()
{
    int num3, randnum, numfoes;
    numfoes=sizeof(foes);
    if(foes == ({ }))
        return;
    for(num3=0;num3<numfoes;num3++)
    {
    if(!objectp(foes[num3])) continue;
        TO->kill_ob(foes[num3]);
//        spell_kill(TO,foes[num3]);
    }
    randnum=(random(numfoes));
    if(objectp(foes[randnum])&&present(foes[randnum], environment(caster)))
    {
        TO->kill_ob(foes[randnum]);
//        spell_kill(TO,foes[randnum]);
    }
    return;
}

void set_caster(object ob)
{
    caster=ob;
    return;
}

void remove()
{
    object *inven=({});
    int i;
    inven = all_inventory(TO);
    for(i=0;i<sizeof(inven);i++)
    {
        if(!objectp(TO)) { continue; }
        if(!objectp(ETO)) { continue; }
        if(!objectp(inven[i])) { continue; }
        inven[i]->move(ETO);
    }    
    if(objectp(caster)) 
    {
        i = (int)TO->query_property("raised");
        caster->set_property("raised",(-1)*i);
    }  
    return ::remove();
}

void die(object ob)
{
    object *inven=({});
    int i;     
    tell_room(ETO,"%^RED%^As "+query_short()+" dies, the battered carcass turns to dust.");
    remove();
    if(objectp(TO)) { destruct(TO); }
}

void __internal_add_exp(int x)
{
    if(objectp(caster)) { caster->__internal_add_exp(x); }
    return;
}

void add_exp(int exp)
{
    if(objectp(caster)) { caster->add_exp(exp); }
    return;
}
