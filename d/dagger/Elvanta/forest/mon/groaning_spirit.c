#include <std.h>
inherit "/std/monster";

object caster, *foes;

void defend();


create()
{
  ::create();
set_name("groaning spirit");
set_id(({"groaning spirit"}));
set_short("a groaning spirit");
  set_long("This spirit looks almost beautiful if not for the fact that its face is twisted into a mask of eternal pain and anger, her hair unkept, and her eyes (that burn like red coals) are full of hatred and ire. You can almost see the landscape through her and what clothing she wears is tattered and torn.");
  set_race("elf");
  set_gender("female");
  set_body_type("elf");
set_hd(21);
  set_overall_ac(0);
  set_property("strength", "magic");
  set_alignment(9);
  set_size(2);
set_max_hp(150);
  set_hp(query_max_hp());
  set_exp(4000);
	add_money("gold", 750);
  set_wimpy(20);
  set_emotes(20, ({"%^BOLD%^The banshee wails horribly, freezing you to the spot!", "%^BOLD%^%^BLACK%^WWWWWWWWWAAAAAAIIIIIIIILLLLLLLLLLLLLLL!!!!!!!!!!"}) );
  set_func_chance(20);
  set_funcs(({"death_wail"}));
  set_property("undead",1);
}

void death_wail()
{
    object *targs;
    int num;
    tell_room(environment(TO),"The banshee shreaks a piercing cry "+
        "that sends a chill down your back.");
    for(num=0;num<=sizeof(targs);num++)
    {
        if(member_array(targs[num],query_attackers()) != -1)
        {
            if(!"/daemon/saving_d.c"->saving_throw(targs[num],
                "paralyzation_poison_death"))
            {
                tell_object(targs[num],"%^BOLD%^The deathly wail "+
                    "causes you severe pain within your head!");
                tell_room(environment(TO),
                    targs[num]->query_cap_name()+" cringes in pain "+
                    "from the scream.", targs[num]);
               targs[num]->add_hp( -(random(15)+3) );
            }
        }
    }
    return 1;
}

void serve(object controller)
{
    caster=controller;
    if(!caster)
        return 1;
    if(!present(caster,environment(TO)))
        return 1;
    tell_object(caster,"%^CYAN%^"+query_short()+" flys in "+
        "and is now yours to command.");
    tell_room(environment(caster),"%^CYAN%^"+query_short()+
        " materializes and hovers at "+caster->query_cap_name()+
        "'s side.",caster);
    caster->add_follower(TO);
    foes=caster->query_attackers();
    call_out("check", 2);
}

int check()
{
    int num, wherefound, num2;
    object *newfoes;
    num = 0;
    newfoes=caster->query_attackers();
    for(num2=0;num2<=sizeof(newfoes)-1;num2++)
    {
	wherefound = member_array(newfoes[num2], foes, 0);
	if(wherefound == -1)
        {
            if(!num)
            {
                tell_object(caster,"%^BOLD%^%^CYAN%^Your "+query_name()+
                    "comes defends you!");
                tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+
                    caster->query_cap_name()+"'s "+query_name()+
                    " defends "+caster->query_objective()+"!",
                    caster);
            num=1;
            }
	}
    }
    if(num)
    {
	foes=newfoes;
        defend();
    }
    if(present(caster, environment(TO)))
        call_out("check", 2);
    else
    {
        TO->move("/d/shadowgate/void.c");
        TO->remove();
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
        TO->kill_ob(foes[num3]);
    }
    if(present(foes[randnum], environment(caster)))
    {
        randnum=(random(numfoes));
        TO->kill_ob(foes[randnum]);
    }
    return;
}

void set_caster(object ob)
{
    caster=ob;
    return;
}

