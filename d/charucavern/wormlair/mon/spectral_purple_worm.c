#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

object stomach;

void create()
{
    ::create();
    set_name("a young spectral purple worm");

    set_id(({"worm", "purple worm", "young purple worm", "young spectral purple worm"}));

    set_short("%^RESET%^%^MAGENTA%^young spectral p%^BOLD%^u%^RESET%^%^MAGENTA%^rpl%^BOLD%^"+
    "e%^RESET%^%^MAGENTA%^ w%^BOLD%^o%^RESET%^%^MAGENTA%^rm%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^The back of this creature is a very deep shade of "+
    "purple. Its monstrous body is composed of thick layers of what you would "+
    "almost refer to as %^BOLD%^scales%^RESET%^%^MAGENTA%^. Each scale connects "+
    "seamlessly to the next and would be indistinguisable from one another if "+
    "not for the fact that the underbelly of it is a much lighter and contrasting "+
    "shade of %^BOLD%^%^GREEN%^green%^RESET%^%^MAGENTA%^. You are able to determine "+
    "the front of the creature only because of a %^BOLD%^%^GREEN%^hideous%^RESET%^%^MAGENTA%^ "+
    "mouth that is constantly opening and closing to reveal rows of %^BOLD%^%^WHITE%^fangs"+
    "%^RESET%^%^MAGENTA%^. You are also able to see smaller %^BOLD%^%^WHITE%^fangs"+
    "%^RESET%^%^MAGENTA%^ that seem to continue down the throat of the creature, which "+
    "likely make the process of eating anything that much easier for it and the "+
    "idea of being eaten much more appalling. Approximately eighty feet away, at the other end of the "+
    "creature there is a %^BOLD%^%^GREEN%^stinger%^RESET%^%^MAGENTA%^ which "+
    "drips a foul green substance sporadically. This entire worm is surrounded with "+
    "an almost hazy fog that makes it appear spectral.%^RESET%^");

    set_hd(12,2);
    set_hp(75 + random(25));
    set_max_hp(query_hp());
    set_body_type("worm");
    set_damage(2,6);
    set_attacks_num(2);
    set_attack_limbs(({"mouth", "tail"}));
    set_base_damage_type("piercing");
    set_gender("neuter");
    set_race("worm");
    set_new_exp(14, "normal");
    set_alignment(5);
    set_overall_ac(-7);

    set_stats("strength", 18);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 18);
    set_stats("dexterity", 12);
    set_stats("charisma", 6);
    set_property("full attacks", 1);
    set_func_chance(5);
    set_funcs(({"swallow"}));
    set_resistance("acid", 25);
    set_hit_funcs((["mouth" : (:TO, "vicious_bite":)]));
    set_property("natural poisoner", 1);
    set_property("natural poison", "purple worm poison");
    set_property("poison chance", 5);
}

int vicious_bite(object targ)
{
    if(!objectp(targ)) return roll_dice(2,6);
    tell_object(targ, TO->QCN+"%^BOLD%^%^RED%^ sinks several of its fangs deep into you!%^RESET%^");
    
    tell_room(ETO, TO->QCN+"%^BOLD%^%^RED%^ sinks several of its fangs into "+targ->QCN+
    "%^BOLD%^%^RED%^!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, 0, roll_dice(2,6), "piercing");
}

void swallow(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    
     
    if(targ->reflex_save(18))
    {
        tell_object(targ, me +"%^BOLD%^%^MAGENTA%^ strikes "+
        "quickly but you are able to move just in time and "+
        "its %^BOLD%^%^GREEN%^hideous mouth%^BOLD%^%^MAGENTA%^"+
        " seems to snarl at you!%^RESET%^");
        
        tell_room(ETO, me +"%^BOLD%^%^MAGENTA%^ strikes quickly "+
        "at "+targ->QCN+"%^BOLD%^%^MAGENTA%^ but "+targ->QS+" is "+
        "able to move just in time and its %^BOLD%^%^GREEN%^"+
        "hideous mouth%^BOLD%^%^MAGENTA%^ seems to snarl!%^RESET%^", targ);
        return;
    }

    tell_object(targ, me + "%^RESET%^%^MAGENTA%^ latches onto you "+
    "with several of its %^BOLD%^%^WHITE%^vicious fangs"+
    "%^RESET%^%^MAGENTA%^ and before you realize what "+
    "is happening you are pulled down its %^RED%^spiked%^RESET%^"+
    "%^MAGENTA%^ throat!%^RESET%^");

    tell_room(ETO, me + "%^RESET%^%^MAGENTA%^ latches onto "+targ->QCN+
    "%^%^RESET%^%^MAGENTA%^ with several of its %^BOLD%^%^WHITE%^vicious fangs"+
    "%^RESET%^%^MAGENTA%^ and before you realize what is happening "+
    me+" pulls "+targ->QO+" down its %^RED%^spiked%^RESET%^%^MAGENTA%^"+
    " throat!%^RESET%^", targ);

    if(!objectp(stomach)) 
    {
        stomach = new(WOB+"worm_stomach");
        stomach->set_my_worm(TO, targ);
    }
    targ->cause_typed_damage(targ, 0, roll_dice(2, 12), "piercing");
    targ->move(stomach);
    targ->force_me("look");
    return;
}



