// originally a ranger command
// reverted to a feat with damage realigned roughly to tabletop as ranger-levels are now irrelevant
// Nienne, 04/10.
#include <std.h>
#include <daemons.h>
inherit FEAT;

void display_messages(object targ,object player);

void create() {
    ::create();
    feat_type("instant");
    feat_category("UnarmedCombat");
    feat_name("spinning kick");
    feat_prereq("Unarmed combad or Monk");
    feat_syntax("spinning_kick");
    feat_desc("Spinning Kick is an instant combat feat. It allows someone skilled in unarmed combat to launch of series of devasting attacks on all enemies within melee range. It requires at least one enemy to work and will use a small amount of stamina.");
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"unarmed combat") && !ob->is_class("monk"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spinning_kick(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    int attack_count;
    object *weapons;

    if((int)caster->query_property("using spinning kick") > time()) {
        tell_object(caster,"You can't use spinning kick again so soon!");
        dest_effect();
        return;
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }
    ::execute_feat();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_attackers()))
    {
      tell_object(caster,"%^YELLOW%^You're not fighting anyone!\n");
      dest_effect();
      return;
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons))
    {
        tell_object(caster,"%^YELLOW%^You must be unarmed to use this feat!\n");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^You center yourself, preparing your body to launch a series of devasting attacks!\n%^RESET%^");
    tell_room(environment(caster),"%^WHITE%^"+caster->QCN+" seems to center "+caster->QO+"self, preparing "+caster->QP+" body!\n%^RESET%^",caster);

    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack()
{
    object *weapons,*attackers;
    int i,dam,num,enchant,hit, res;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }

    attackers = (object *)caster->query_attackers();
    weapons = caster->query_wielded();
    if(!sizeof(attackers))
    {
      tell_object(caster,"%^YELLOW%^You're not fighting anyone!\n");
      dest_effect();
      return;
    }
    if(sizeof(weapons))
    {
        tell_object(caster,"%^YELLOW%^You must be unarmed to use this feat!\n");
        return 1;
    }
    caster->remove_property("using spinning kick");
    caster->set_property("using spinning kick", time() + 35 );
    delay_messid_msg(35,"%^BOLD%^%^WHITE%^You can %^CYAN%^spinning_kick%^WHITE%^ again.%^RESET%^");

    attackers = shuffle(attackers);

    for(i=0;i<sizeof(attackers) && i < 8;i++)
    {
        if(!objectp(attackers[i])) continue;
        enchant = 0;
        if(caster->is_class("monk"))
        {
            enchant = (int)"/std/class/monk.c"->effective_enchantment(caster);
        }
        dam = caster->query_unarmed_damage();
        dam += enchant;
        dam += caster->query_damage_bonus();
        dam += roll_dice((int)caster->query_level(),5)+roll_dice(2,8);

        if(!present(attackers[i],environment(caster)))
        {
            tell_object(caster,"%^RED%^That target is no longer in range!%^RESET%^");
            continue;
        }
        if(!(res = thaco(attackers[i])))
        {
            tell_object(attackers[i],"%^CYAN%^"+caster->QCN+" spins and jumps toward you, launching a series of kicks, but you manage to avoid them!%^RESET%^");
            continue;

        }
        if(attackers[i]->query_property("weapon resistance") || res == -1)
        {
            if(!hit) hit = -1;
            if(stringp(caster->query("featMiss")))
            {
                tell_object(caster, caster->query("featMiss")+" " +query_feat_name()+"!");
                caster->delete("featMiss");
                continue;
            }
            if(enchant < attackers[i]->query_property("weapon resistance"))
            {
                tell_object(attackers[i],"%^BOLD%^"+caster->QCN+" hits you with an ineffective barrage of kicks!%^RESET%^");
                continue;
            }
        }
        display_messages(attackers[i],caster);
        caster->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), dam, "bludgeoning");
        hit = 1;
        continue;
    }
    if(!hit)
    {
	    tell_object(caster,"%^BOLD%^You fail to land a strike on anything and almost fall over in the process!");
	    tell_room(environment(caster),"%^BOLD%^"+caster->QCN+" almost falls over and has to scramble to hold on to it!",caster);
	    caster->set_paralyzed(roll_dice(1,6),"%^BOLD%^You are trying to regain your balance!");
    }
    else if(hit > 0)
    {
        switch(random(5))
        {
            case 0:
                tell_object(caster,"%^BOLD%^%^GREEN%^You land a series of kicks on your foes!");
                tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+" lands a series of kicks on "+caster->QP+" foes!",({target,caster}));
                break;
            case 1:
                tell_object(caster,"%^BOLD%^%^BLUE%^You spin quickly striking your opponents with a series of well placed kicks!");
                tell_room(environment(caster),"%^BOLD%^%^BLUE%^"+caster->QCN+" spins quickly striking "+caster->QP+" opponents with a series of well placed kicks!",({target,caster}));
                break;
            case 2:
                tell_object(caster,"%^RESET%^%^GREEN%^You spin about rapidly picking up speed as you slam into your opponents with a series of kicks!");
                tell_room(environment(caster),"%^RESET%^%^GREEN%^"+caster->QCN+" seems to pick up speed as "+caster->QS+" spins about rapidly and slams "+caster->QP+" opponents with a series of kicks!",({target,caster}));
                break;
            case 3:
                tell_object(caster,"%^BOLD%^%^MAGENTA%^You move around your opponents with a fluid grace launching a series of kicks!");
                tell_room(environment(caster),"%^BOLD%^%^MAGENTA%^"+caster->QCN+" moves around "+caster->QP+" opponents with a fluid grace as "+caster->QS+" launches a series of kicks!",({target,caster}));
                break;
            case 4:
                tell_object(caster,"%^RESET%^%^BLUE%^You focus intently on your enemies... launching one kick after another!");
                tell_room(environment(caster),"%^RESET%^%^BLUE%^"+caster->QCN+" suddenly turns and focuses intently on "+caster->QP+" enemies...  "+caster->QS+" launches one kick after another!",({target,caster}));
                break;
        }
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

void display_messages(object targ,object player)
{
    if(!objectp(targ)) return;
    if(!objectp(player)) return;

    switch(random(5))
    {
        case 0:
            tell_object(target,"%^BOLD%^%^GREEN%^"+player->QCN+" lands a series of kicks on you!");
            break;
        case 1:
            tell_object(target,"%^BOLD%^%^BLUE%^"+player->QCN+" spins quickly striking you with a series of well placed kicks!");
            break;
        case 2:
            tell_object(target,"%^RESET%^%^GREEN%^"+player->QCN+" spins about rapidly picking up speed as "+player->QS+" slam into you with a series of kicks!");
            break;
        case 3:
            tell_object(target,"%^BOLD%^%^MAGENTA%^"+player->QCN+" moves around you with a fluid grace as "+player->QS+" launches a series kicks!");
            break;
        case 4:
            tell_object(target,"%^RESET%^%^BLUE%^"+player->QCN+" focuses intently on you... "+player->QS+" almost seems to blur as "+player->QS+" launches one kick after another!");
            break;
    }
}
