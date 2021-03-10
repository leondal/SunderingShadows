#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit WEAPONLESS;
int flag, exps;

void create() {
    ::create();
	set_race("owlbear");
    set_name("owlbear");
    set_id(({"bear","owlbear"}));
    set_short("%^RESET%^%^ORANGE%^A massive %^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^l%^RESET%^%^WHITE%^bear");
    set_long("%^MAGENTA%^This strange creature towers nearly "+
    "ten feet into the air.  Its entire body is covered "+
    "with thick %^BOLD%^%^BLACK%^black%^RESET%^%^MAGENTA%^ fur that has "+
    "grown out and intertwined with a layer of dark brown "+
    "feathers.  Its hands have morphed into "+
    "large and sharpened black claws, its apparent means of "+
    "defense.  Its head is obviously that of a very large "+
    "bird, probably that of an owl, its obtrusive beak an "+
    "almost ivory color, and its dark eyes outlined with a "+
    "thin line of %^RED%^red%^RESET%^%^MAGENTA%^.  An anger that borders "+
    "on madness is readily evident by even the "+
    "most foolish in those eyes.%^RESET%^");
    set_hd(18,1);
    set_hp(325 + random(30));
    set_body_type("humanoid");
    set_size(3);
	set_new_exp(15, "normal");
    set_stats("strength",18);
    set_stats("intelligence",5);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_stats("constitution",19);
    set_stats("dexterity",12);
    set_alignment(9);
    set("aggressive",27);
    set_property("full attacks",1);
    set_damage(2,6);
    add_limb("left claw","left hand",0,0,0);
    add_limb("right claw","right hand",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));
    set_attacks_num(3);
    set_damage_bonus(1);
    set_func_chance(20);
    set_funcs(({"grab"}));
    //set_max_level(20);
    set_overall_ac(0 - random(6));
    FENC->fix_nogo(TO);
    add_money("gold",100);
}

void reset() {
    ::reset();
    flag = 0;
}

void init() {
    ::init();
    if(TP->query_invis()) return;
    if((string)TP->query_race() == "owlbear") return;
    if(flag == 0) {
        force_me(!random(2) ? "emote %^RED%^issues a long and low growl.%^RESET%^" :
        "emote %^BLUE%^emits an angry screech.%^RESET%^");
        flag = 1;
    }
    force_me("kill "+TP->query_name());
    return;
}

void grab(object targ) {
    string limb;
    limb = targ->return_target_limb();
    tell_object(targ,"%^RED%^The massive owlbear slams its clawed "+
    "hand into your "+limb+ "!%^RESET%^");
    tell_room(environment(targ),"%^RED%^The massive owlbear "+
    "slams its clawed hand into "+targ->QCN+"%^RED%^'s "+limb+"!"+
    "%^RESET%^",targ);
    targ->do_damage(limb,roll_dice(10,6));
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death",-2)) {
        tell_object(targ,"%^BOLD%^%^BLACK%^The owlbear holds your "+
        limb+" tightly in its grip!%^RESET%^");
        tell_room(environment(targ),"%^BOLD%^%^BLACK%^The owlbear "+
        "holds "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+limb+" tightly "+
        "in its grip!%^RESET%^",targ);
        targ->set_paralyzed(roll_dice(1,3)*8,"%^BLUE%^You are held "+
        "tightly by the owlbear!%^RESET%^");
        return;
    }
    return;
}
