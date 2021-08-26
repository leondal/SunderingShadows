#include <std.h>

inherit OBJECT;

object spell_ob;
string spell, args;
int prof,level,flag=0;


void create()
{
    ::create();
    set_name("spellstaff");
    set("id", ({ "remotespellstaff"}) );
    set("short", "");
    set("long", "");
    set_property("no animate", 1);
    set_weight(0);
}


int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}


void init()
{
    ::init();
    add_action("now","now");
}


set_prof(int i) { prof = i; }
int get_prof() { return prof; }
set_spell(string xxx) { spell = xxx; }
set_args(string arg) { args = arg; }
set_clevel(int i) { level = i; }
int save_me(string str) { return 1; }
int drop() { return 1; }
int is_detectable() { return 0; }
int query_invis() { return 1; }
void set_spell_ob(object the_spell) { spell_ob = the_spell; }
object query_spell_ob() { return spell_ob; }


int has_staff(object tp)
{
    object *inv=({});
    int i;

    if(!objectp(tp)) { return 0; }

    inv = deep_inventory(tp);

    if(!sizeof(inv)) { return 0; }

    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(inv[i]->query_property("spellstaff_object")) { return 1; }
    }
    return 0;
}


int now()
{
    object spellobj;

    if(!spell) return 0;
    if(flag) return 0;
    flag = 1;

    if(!has_staff(TP))
    {
	    write("The staff you placed your spell into is missing and the power of the spell vanishes.\n");
        remove();
        return 1;
    }

    spellobj = new(spell);

    if(prof >= 100)
    {
        if(!stringp(args))
        {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else
        {
            spellobj->use_spell(TP,args,level, prof);
        }
    }

    else if(prof < random(100))
    {
        if(!stringp(args))
        {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else
        {
            spellobj->use_spell(TP,args,level, prof);
        }
    }
    else
    {
        if(!stringp(args))
        {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else
        {
            spellobj->use_spell(TP,args,level, prof);
        }
    }

    call_out("remove_me",5);
    return 1;
}

void remove_me()
{
    if(objectp(spell_ob)) { spell_ob->dest_effect(); }
    destruct(TO);
}
