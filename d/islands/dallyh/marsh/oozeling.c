#include <std.h>
#include "/d/islands/dallyh/fways.h"
inherit WEAPONLESS;

mixed forget_string;
int delay;

void create()
{
    ::create();
    set_name("glob of sizzling ooze");

    set_id(({"ooze", "glob", "glob of sizzling ooze", "glob of ooze", "dallyhallyevil"}));

    set_short("%^BOLD%^%^GREEN%^Gl%^YELLOW%^o%^GREEN%^b of S%^YELLOW%^i%^GREEN%^"+
    "zzl%^YELLOW%^i%^GREEN%^ng %^YELLOW%^O%^GREEN%^oz%^YELLOW%^e%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This bubbling glob of ooze is approximately one foot in "+
    "circumference. It seems to be composed of a slimy and thick ac%^YELLOW%^i%^GREEN%^d "+
    "that is almost boiling continually and chaotically, as if it might explode in a shower "+
    "of goo at any moment. You realize that it is sentient, but whatever power gives it "+
    "life is a mystery. There are also no visible appendages or any method that you can discern "+
    "that affords it awareness of its surroundings. However, it moves purposefully as if "+
    "guided by something, you are just not sure of what that might be.%^RESET%^");

    set_hd(55,2);
    set_hp(1000+random(2000));
    set_max_hp(query_hp());
    set_body_type("ooze");
    set_damage(2,20);
    set_attacks_num(4);
    set_attack_limbs(({"glob"}));
    set_base_damage_type("bludgeoning");
    set_gender("neuter");
    set_race("ooze");
    set_new_exp(48, "high");
    set_alignment(5);
    set_overall_ac(-15);
    set("aggressive", 30);
    set_stats("strength", 30);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 30);
    set_stats("dexterity", 12);
    set_stats("charisma", 6);
    set_property("full attacks", 1);
    set_resistance("acid", 1500);
    set_resistance("bludgeoning", 1000);
    set_resistance("cold", -100);
    set_hit_funcs((["glob" : (:TO, "acid_splash":)]));
    set_moving(1);
    set_speed(55);
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    DYN_UP_D->dynamic_update(TO);
    return;
}

int acid_splash(object targ)
{
    if(!objectp(targ)) return roll_dice(4,8);
    tell_object(targ, TO->QCN+"%^BOLD%^%^GREEN%^ splashes acidic goo on you!%^RESET%^");
    tell_room(ETO, TO->QCN+"%^BOLD%^%^GREEN%^ splashes acidic goo on "+targ->QCN+
    "%^BOLD%^%^GREEN%^!%^RESET%^", targ);
    targ->cause_typed_damage(targ, 0, roll_dice(4,8), "acid");
    return 1;
}

void die(object ob)
{
    if(!objectp(TO) || !objectp(ETO)) return ::die(ob);
    tell_room(ETO, TO->query_short()+" %^BOLD%^%^GREEN%^explodes in a shower of "+
    "thick %^YELLOW%^goo%^BOLD%^%^GREEN%^!%^RESET%^");
    TO->move("/d/shadowgate/void");
    if(objectp(TO)) TO->remove();
    return;
}
