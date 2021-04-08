#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int FEATTIMER = 25;
//check time in magic.h

int allow_shifted() { return 1; }

void create() {
    ::create();
    feat_type("instant");
    feat_category("MeleeDamage");
    feat_syntax("rush [TARGET]");
    feat_prereq("Strength 13");
    feat_desc("The character can attempt to rush at a foe with their weapon, throwing as much force as they can behind it in the hope of dealing damage and knocking them over. Missing, however, will send the character sprawling. This will only work while shapeshifted, or using a standard melee weapon, unless the character has an aptitude in unarmed combat.

If used without an argument this feat will pick up a random attacker.

%^BOLD%^N.B.%^RESET%^ This feat only works with standard melee combat on foot. It takes quite different feats to <charge> from horseback, or to land a <preciseshot> with a ranged weapon.");
    feat_name("rush");
    set_save("fort");
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((int)ob->query_base_stats("strength") < 13) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_rush(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat() {
    object *myweapon;
    mapping tempmap;
    int rtime;
    ::execute_feat();
    if(!objectp(target))
    {
        object * attackers = caster->query_attackers();
        if(sizeof(attackers))
        {
            attackers = filter_array(attackers,(:objectp($1):));
            attackers = filter_array(attackers,(:$1->query_property("rushed at")+FEATTIMER < time():));
            if(!sizeof(attackers))
            {
                tell_object(caster,"%^BOLD%^Nobody to rush.%^RESET%^");
                dest_effect();
                return;
            }
            target = attackers[random(sizeof(attackers))];
        }
    }

    if(!objectp(target))
    {
        tell_object(caster,"%^RESET%^That is not here!");
        dest_effect();
        return;
    }

    rtime = (int)target->query_property("rushed at");
    if(rtime + FEATTIMER > time())
    {
        tell_object(caster,"That target is still wary of such an attack!");
        dest_effect();
        return;
    }

    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(target == caster) {
        tell_object(caster,"Don't rush at yourself!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted")) {
        tell_object(caster,"How can you rush at anyone without a weapon?");
        dest_effect();
        return;
    }
    if(sizeof(caster->query_wielded())) {
        myweapon = caster->query_wielded();
        if(myweapon[0]->is_lrweapon()) {
            tell_object(caster,"That weapon is too flimsy to rush someone with!");
            dest_effect();
            return;
        }
    }
    if(caster->query_in_vehicle()) {
        tell_object(caster,"You need to learn to charge if you want to do that while mounted!");
        dest_effect();
        return;
    }

    caster->use_stamina(roll_dice(1,6));
    rush_mess(caster,target);
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack() {
    int damage, timerz, i, enchant, res;
    object *weapon, *keyz,shape, *myweapon;
    mapping tempmap, newmap;
    string damtype;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target has eluded you!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted") && !FEATS_D->usable_feat(caster,"unarmed combat")) {
        tell_object(caster,"How can you rush at anyone without a weapon?");
        dest_effect();
        return;
    }
    if(sizeof(caster->query_wielded())) {
        myweapon = caster->query_wielded();
        if(myweapon[0]->is_lrweapon()) {
            tell_object(caster,"That weapon is too flimsy to rush someone with!");
            dest_effect();
            return;
        }
    }
    if(caster->query_in_vehicle()) {
        tell_object(caster,"You need to learn to charge if you want to do that while mounted!");
        dest_effect();
        return;
    }

    target->remove_property("rushed at");
    target->set_property("rushed at",time());
    delay_subject_msg(target,FEATTIMER,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^rushed%^WHITE%^ again.%^RESET%^");

    if(sizeof(myweapon))
    {
        enchant = (int)myweapon[0]->query_property("enchantment");
    }
    else
    {
//        enchant = 0;
// combat daemon now has a calc which picks up monk, unarmed & shifted enchantment. Plz to use! N, 1/3/20.
        enchant = COMBAT_D->unarmed_enchantment(caster);
    }
    
    //Improved Rush gives +2 bonus
    enchant += (FEATS_D->usable_feat(caster, "improved rush") * 2);

    if(!(res = thaco(target,enchant)))
    {
        miss_mess(caster,target);
        if (!FEATS_D->usable_feat(caster, "improved rush")) {
            caster->set_tripped(4, "You're recovering from your missed rush!", 4);
        }
        dest_effect();
        return;
    }
    else if(res == -1)
    {
        if(stringp(caster->query("featMiss")))
        {
            tell_object(caster, caster->query("featMiss")+" " +query_feat_name()+"!");
            caster->delete("featMiss");
        }
        else
        {
            tell_object(caster, "%^RED%^"+target->QCN+" is totally unaffected!%^RESET%^");
            tell_room(place, "%^RED%^"+target->QCN+" is totally unaffected!%^RESET%^", ({target, caster}));
        }
        dest_effect();
        return;
    }
    
    //+2 dice to damage for improved rush
    clevel += (FEATS_D->usable_feat(caster, "improved rush") * 2);
    damage = roll_dice(clevel,8); // up to d8 on a trial basis

    if(sizeof(myweapon))
    {
        damage += myweapon[0]->query_damage();
        damtype = myweapon[0]->query_damage_type();
    }
    else if(caster->query_property("shapeshifted"))
    {
        damage += (int)caster->get_hand_damage();
        damtype = caster->get_new_damage_type();
    }
    if(!damtype)
    {
      damtype = "bludgeoning";
    }
    damage += "/daemon/bonus_d"->damage_bonus(caster->query_stats("strength"));
    damage += (int)caster->query_damage_bonus();

    if(target->query_property("weapon resistance"))
    {
        if(enchant < (int)target->query_property("weapon resistance"))
        {
            damage = 0;
        }
    }

    hit_mess(caster,target);
    caster->cause_typed_damage(target,target->return_target_limb(),damage,damtype);

    if(!objectp(target)) {
      dest_effect();
      return;
    }
    target->set_paralyzed(roll_dice(2,6),"You're recovering from that last hit.");

    if(target->is_npc() || userp(target)) {
      if(target->query_deaths_door() && (userp(caster) || caster->query_property("knock unconscious"))) {
        target->cease_all_attacks();
        target->remove_attacker(caster);
        caster->remove_attacker(target);
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" falls unconscious "+
          "after you slam into "+target->QO+"!");
     	  tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" slams "+
          "full force into "+target->QCN+" knocking "+target->QO+" completely "+
          "unconscious due to wounds!",({target,caster}));
        tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" slams full force "+
          "into you, knocking you unconscious.\n");
      }
    }
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}

void rush_mess(object play,object targ){
	string mystyle;
	object etp;
	if(!objectp(play))    { return 0; }
	if(!objectp(targ))    { return 0; }
	mystyle = (string)play->query_fighter_style();
	etp = environment(play);

    if(play->query_property("shapeshifted"))
    {
        tell_object(play,"%^BOLD%^%^GREEN%^You roar and dip your head, sprinting straight at "+targ->QCN+"!");
        tell_object(targ,"%^BOLD%^%^GREEN%^Suddenly, "+play->QCN+" roars and dips "+play->QP+" head, sprinting straight at you!");
        tell_room(etp,"%^BOLD%^%^GREEN%^Suddenly "+play->QCN+" roars and dips "+play->QP+" head, sprinting straight at "+targ->QCN+"!",({play,targ}));
        return;
    }

	switch(mystyle)
	{
	case "peasant":			tell_object(play,"%^BOLD%^%^YELLOW%^You lower "+
								"your shoulder and run straight toward "+
								""+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^%^YELLOW%^Suddenly "+
								""+play->QCN+" lowers "+play->QP+" shoulder and "+
								"runs straight at "+targ->QCN+"!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^YELLOW%^Suddenly, "+
								""+play->QCN+" lowers "+play->QP+" shoulder and "+
								"runs straight at you!");
							break;

    case "swashbuckler":	tell_object(play,"%^BOLD%^%^BLUE%^You "+
								"break from combat and begin tumbling "+
								"rapidly towards "+targ->QCN+"!");
                            tell_room(etp,"%^BOLD%^%^BLUE%^"+play->QCN+" "+
								"breaks from combat, tumbling towards "+
								""+targ->QCN+"!",({play,targ}));
                            tell_object(targ,"%^BOLD%^%^BLUE%^"+play->QCN+" "+
								"breaks from combat, tumbling towards "+
								"you!");
                            break;

    case "thug":			tell_object(play,"%^BOLD%^%^RED%^You bolt "+
								"forward, weaving your way towards "+
								""+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^%^RED%^"+play->QCN+" "+
								"quickly bolts forward, weaving towards "+
								""+targ->QCN+"!",({play, targ}));
							tell_object(targ,"%^BOLD%^%^RED%^"+play->QCN+" "+
								"quickly bolts forward, weaving "+play->QP+" "+
								"way toward you!");
							break;

	case "soldier":			tell_object(play,"%^BOLD%^%^WHITE%^You expertly "+
								"break from combat, rushing straight "+
								"at "+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^%^WHITE%^Suddenly "+
								""+play->QCN+" breaks expertly from combat, "+
								"rushing straight at "+
								""+targ->QCN+"!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^WHITE%^Suddenly "+
								""+play->QCN+" breaks expertly from combat, "+
								"rushing straight at "+
								"you!");
							break;

	case "dervish":			tell_object(play,"%^BOLD%^%^CYAN%^You whirl "+
								"suddenly, gathering momentum as you "+
								"speed toward "+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^%^CYAN%^"+play->QCN+" whirls "+
								"suddenly, gathering momentum as "+play->QS+" "+
								"speeds toward "+targ->QCN+"!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^CYAN%^"+play->QCN+" whirls "+
								"suddenly, gathering momentum as "+play->QS+" "+
								"speeds toward you!");
							break;

	default:				tell_object(play,"%^BOLD%^You break from combat "+
								"and then rush straight at "+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^Suddenly "+play->QCN+" breaks "+
								"from combat and rushes madly into "+
								""+targ->QCN+"!",({play,targ}));
							tell_object(targ,"%^BOLD%^You see "+play->QCN+" break "+
								"from combat and suddenly "+
								"rushes madly toward you!\n");
							break;
	}
   	return;
}

void miss_mess(object play,object targ) {
	string mystyle;
	object etp;
	if(!objectp(play))    { return 0; }
	if(!objectp(targ))    { return 0; }
	mystyle = (string)play->query_fighter_style();
	etp = environment(play);

    if(play->query_property("shapeshifted"))
    {
        tell_object(play,"%^BOLD%^%^GREEN%^"+targ->QCN+" dodges to the side at the last instant and you tumble end over end, loosing your footing!");
        tell_object(targ,"%^BOLD%^%^GREEN%^You dodge to the side at the last instant and "+play->QCN+" tumbles end over end, loosing "+play->QP+" footing!");
        tell_room(etp,"%^BOLD%^%^GREEN%^Suddenly "+targ->QCN+" dodges to the side at the last instant and "+play->QCN+" tumbles end over end, loosing "+play->QP+" footing!",({play,targ}));
        return;
    }

	switch(mystyle)
	{
	case "peasant":			tell_object(play,"%^BOLD%^%^YELLOW%^You trip as "+
								"you run toward "+targ->QCN+" and sprawl on "+
								"ground, gasping for breath!");
							tell_room(etp,"%^BOLD%^%^YELLOW%^"+play->QCN+" "+
								"trips as "+play->QS+" runs, sprawling across "+
								"the ground in front of "+targ->QCN+"!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^YELLOW%^"+play->QCN+" "+
								"trips as "+play->QS+" runs, sprawling across "+
								"the ground in front of you!");
							break;

	case "swashbuckler":	tell_object(play,"%^BOLD%^%^BLUE%^You "+
                               "slip as you land, falling in a heap "+
                               "right in front of "+targ->QCN+"!");
                            tell_room(etp,"%^BOLD%^%^BLUE%^"+play->QCN+" "+
                               "slips as "+play->QS+" lands, falling in "+
                               "a heap in front of "+
                               ""+targ->QCN+"!",({play,targ}));
                            tell_object(targ,"%^BOLD%^%^BLUE%^"+play->QCN+" "+
                               "slips as "+play->QS+" lands, falling in "+
                               "a heap in front of you!");
                            break;

	case "thug":			tell_object(play,"%^BOLD%^%^RED%^You lose your "+
								"footing as you weave towards "+
								""+targ->QCN+", skidding to the ground!");
							tell_room(etp,"%^BOLD%^%^RED%^"+play->QCN+" "+
								"loses "+play->QP+" footing as "+play->QS+" "+
								"weaves towards "+targ->QCN+" and skids "+
								"to the ground!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^RED%^"+play->QCN+" "+
								"loses "+play->QP+" footing as "+play->QS+" "+
								"weaves towards you and skids "+
								"to the ground!");
							break;

	case "soldier":			tell_object(play,"%^BOLD%^%^WHITE%^With horror, "+
								"you trip as you rush towards "+targ->QCN+", "+
								"falling face first on the ground!");
							tell_room(etp,"%^BOLD%^%^WHITE%^A look of "+
								"horror crosses "+play->QCN+"'s face as "+
								""+play->QS+" trips, falling face first on "+
								"the ground in front of "+
								""+targ->QCN+"!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^WHITE%^A look of "+
								"horror crosses "+play->QCN+"'s face as "+
								""+play->QS+" trips, falling face first on "+
								"the ground in front of "+
								"you!");
							break;

	case "dervish":			tell_object(play,"%^BOLD%^%^CYAN%^You begin to "+
								"spin toward "+targ->QCN+" but trip over "+
								"your own feet and fall to the ground!");
							tell_room(etp,"%^BOLD%^%^CYAN%^"+play->QCN+" begins "+
								"to spin toward "+targ->QCN+" but trips over "+
								""+play->QP+" own feet, falling to the "+
								"ground!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^CYAN%^"+play->QCN+" begins "+
								"to spin toward you but trips over "+
								""+play->QP+" own feet, falling to the "+
								"ground!");
							break;

	default:				tell_room(etp,"%^BOLD%^"+play->QCN+" rushes at "+targ->QCN+" "+
								"but "+targ->QS+" side-steps the attack and "+play->QCN+" "+
								"sprawls on the ground!",({targ,play}));
							tell_object(targ,"%^BOLD%^"+play->QCN+" rushes at you but you "+
								"side-step the attack and "+play->QCN+" sprawls on the "+
								"ground!");
							tell_object(play,"%^BOLD%^You rush at "+targ->QCN+" but "+
								""+targ->QS+" side-steps the attack and you sprawl "+
								"on the ground!");
	}
	return;
}

void hit_mess(object play,object targ){
	string mystyle;
	object etp;
	if(!objectp(play))    { return 0; }
	if(!objectp(targ))    { return 0; }
	mystyle = (string)play->query_fighter_style();
	etp = environment(play);

    if(play->query_property("shapeshifted"))
    {
        tell_object(play,"%^BOLD%^%^GREEN%^You stagger "+targ->QCN+" backwards as the full force of your body slams into "+targ->QO+"!");
        tell_object(targ,"%^BOLD%^%^GREEN%^You are staggered backwards as the full force of "+play->QCN+"'s body slams into you!");
        tell_room(etp,"%^BOLD%^%^GREEN%^"+targ->QCN+" staggers backwards as the full force of "+play->QCN+"'s body slams into "+targ->QO+"!",({play,targ}));
        return;
    }

	switch(mystyle)
	{
    case "peasant":			tell_object(play,"%^BOLD%^%^YELLOW%^You knock "+
								""+targ->QCN+" backward as you slam into "+
								""+targ->QO+" with all your momentum!");
							tell_room(etp,"%^BOLD%^%^YELLOW%^"+
								""+play->QCN+" knocks "+targ->QCN+" backward as "+
								""+play->QS+" slams into "+targ->QO+" with all "+
								""+play->QP+" momentum!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^YELLOW%^"+
								""+play->QCN+" knocks you backward as "+
								""+play->QS+" slams into "+targ->QO+" with all "+
								""+play->QP+" momentum, leaving you gasping "+
								"for air!");
							break;

	case "swashbuckler":	tell_object(play,"%^BOLD%^%^BLUE%^You "+
								"end your tumbling right at "+
								""+targ->QCN+"'s feet, striking "+
								"forward with all your might!");
                            tell_room(etp,"%^BOLD%^%^BLUE%^"+play->QCN+" "+
								"lands right at "+targ->QCN+"'s feet, "+
								"striking a solid blow against "+
								""+targ->QO+"!",({play,targ}));
                            tell_object(targ,"%^BOLD%^%^BLUE%^"+play->QCN+" "+
								"lands right at your feet, "+
								"striking you soundly and leaving "+
								"you breathless!");
                            break;

	case "thug":			tell_object(play,"%^BOLD%^%^RED%^You drive your "+
								"blow into a vulnerable spot, using "+
								"all your weight to stun "+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^%^RED%^"+play->QCN+" "+
								"drives "+play->QP+" weight into "+
								""+targ->QCN+", landing a solid blow to "+
								"a vulnerable spot!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^RED%^"+play->QCN+" "+
								"slams into you with "+
								"all "+play->QP+" weight behind the blow, "+
								"leaving you dazed!");
							break;

	case "soldier":			tell_object(play,"%^BOLD%^%^WHITE%^You brace "+
								"yourself as you drive full-force into "+
								""+targ->QCN+", knocking "+targ->QO+" backward!");
							tell_room(etp,"%^BOLD%^%^WHITE%^"+play->QCN+" braces "+
								""+play->QO+"self as "+play->QS+" drives full"+
								"-force into "+targ->QCN+", knocking "+targ->QO+" "+
								"backward!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^WHITE%^"+play->QCN+" braces "+
								""+play->QO+"self as "+play->QS+" drives full"+
								"-force into you, knocking you "+
								"backward!");
							break;

	case "dervish":			tell_object(play,"%^BOLD%^%^CYAN%^Just as "+
								"you reach "+targ->QCN+", you spin in the air, "+
								"planting a devastating blow at a weak spot!");
							tell_room(etp,"%^BOLD%^%^CYAN%^"+play->QCN+" spins "+
								"in the air before "+targ->QCN+", landing a "+
								"devastating blow!",({play,targ}));
							tell_object(targ,"%^BOLD%^%^CYAN%^Pain explodes "+
								"in your body as "+play->QCN+" spins in the "+
								"air, landing a devastating blow on one "+
								"of your weak spots!");
							break;

	default:				tell_object(play,"%^BOLD%^You successfully slam your "+
								"weapon with all your weight behind it into "+
								""+targ->QCN+"!");
							tell_room(etp,"%^BOLD%^"+play->QCN+" slams "+
								"full force into "+targ->QCN+"!",({targ,play}));
							tell_object(targ,"%^BOLD%^"+play->QCN+" slams full force into "+
								"you dealing damage and knocking the wind out of you!");
							break;
	}
	return;
}
