#include <std.h>
inherit OBJECT;

object caster, mon, *foes, spell, *mons;
int freed, count;

void save_me(string file){return 1;}

int query_my_guardians()
{
    mixed *to_remove;
    int x;
    if(!objectp(TO)) return 0;
    if(!pointerp(mons)) return 0;
    if(!sizeof(mons)) return 0;
    to_remove = ({});
    for(x = 0;x < sizeof(mons);x++)
    {
        if(!objectp(mons[x])) to_remove += ({mons[x]});
        continue;
    }
    mons -= to_remove;
    if(!sizeof(mons))
    {
        TO->remove();
        return 0;
    }
    else return sizeof(mons);
}

void check_guardian_environment()
{
    object casterEnv;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(caster)) return;
    call_out("check_guardian_environment", 10 + random(11));
    if(!query_my_guardians()) return;
    casterEnv = environment(caster);
    if(!objectp(casterEnv)) return;
    for(x = 0;x < sizeof(mons);x++)
    {
        if(!objectp(mons[x])) 
        {
            continue;
        }
        if(!objectp(environment(mons[x])))
        {
            mons[x]->go_to_master();
            continue;
        }
        if(environment(mons[x]) != casterEnv)
        {
            mons[x]->go_to_master();
            continue;
        }
        continue;
    }
    return;
}

void create(){
   ::create();
   set_name("device");
   set("id", ({ "monkeledevice99x" }) );
   set("short", "");
   set("long", "");
   set_weight(0);
   call_out("check_guardian_environment", 10 + random(11));
}

int move(mixed dest)
{
   if(ETO && objectp(ETO))
      if(interactive(ETO))
         return 0;
   ::move(dest);
   set_heart_beat(1);
}

set_caster(object ob)
{
   if(objectp(ob))
      caster = ob;
   else
      remove();
}

object query_caster(){return caster;}

void add_guardian()
{
    object ob;
    if(!objectp(TO)) return;
    if(!objectp(caster)) return;
    if(!pointerp(mons)) mons = ({});
    ob = new("/d/magic/mon/elemental_guardian");
    ob->setup_guardian(caster, (string)caster->query("monk_ele_focus"));    
    ob->set_property("minion", caster);
    mons += ({ob});
    return;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }    
}

void remove()
{
    int x;
    if(!pointerp(mons)) return ::remove();
    for(x = 0;x < sizeof(mons);x++)
    {
        if(!objectp(mons[x])) continue;
        mons[x]->go_away();
        if(objectp(mons[x])) mons[x]->remove();
        continue;
    }   
    return ::remove();
}