//shadowlisten.c
//Silverwatcher, shadowlistener, and innereye are 
//essentially the same file.  If you make a change to
//one, please check to see if the others need it as well.

#include <std.h>

inherit MONSTER;

object caster, follower;
void self_destruct();
void set_scry_power(int x);
void query_scry_power();
void query_mycaster();

int power;


void create()
{
    ::create();
    set_name("reflection_object");
    set_property("no detect",1);
    set_id(({"reflection_object"}));
    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
}


object query_caster() { return caster; }
void set_scry_power(int x) { power = x; }
void query_scry_power() { return power; }
int is_druid_scry() { return 1; }
int move(mixed dest) { ::move(dest); }
set_caster(object cas) { caster = cas; }
void query_mycaster() { return caster; }
set_target(object ob) { follower = ob; }
void die(object ob) {}
dest_me() { remove(); }
int do_damage(string str, int i) { return 0; }
int is_invincible(){ return 1;}
int is_detectable(){ return 0;}


int id(string str)
{
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}


void set_invis() 
{
    if (TO->query_invis()) { return; }
    else ::set_invis();
    return;
}


void heart_beat()
{
    if(!objectp(TO) || !objectp(caster) || !objectp(follower) || !objectp(ETO))
    {
        self_destruct();    
        return;
    }

    if(objectp(environment(follower)) && ETO != environment(follower)) 
    {
        move(environment(follower));
    }

    if(ETO->query_property("no scry")) 
    {
       self_destruct();
       return;
    }

    if(follower->query_true_invis()) 
    {
        self_destruct();
        return;
    }
   
    if(present("blockerx111", follower)) 
    {
        self_destruct();
        return;
    }
}


catch_tell(string str)
{
    if(!objectp(caster))
    {
        dest_me();
        return;
    }

    tell_room(environment(caster),"%^RESET%^%^BLUE%^[R] %^RESET%^"+str);
}


void self_destruct() 
{
    int i;
    object casterobj,*spells = ({});

    casterobj = find_player(caster);
    
    if(objectp(casterobj))
    {
        spells += casterobj->query_property("dispellable spells");
        
        for(i=0;i<sizeof(spells);i++)
        {  
            if(objectp(spells[i]))
            {
                if(!spells[i]->query_target_object())
                {
                    if((string)spells[i]->query_spell_name() == "reflection")
                    {
                        if(!objectp(spells[i])) 
                        {
                            return notify_fail("The reflection in the pool fades away.\n");
                        }
                        tell_object(casterobj,"The reflection in the pool fades away!", TP);
                        spells[i]->removeSpellFromCaster();
                    }
                }
            }
        }
    }
    if(objectp(TO)) dest_me();
    return;
}