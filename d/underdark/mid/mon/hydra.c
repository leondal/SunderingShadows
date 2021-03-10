#include <std.h>
#include "../../defs.h"
inherit WEAPONLESS;

int breed, flagme;

void create() {
    int i;
    ::create();
    breed = random(3);
    set_id(({"hydra"}));
    set_name("hydra");
    set_short("%^RESET%^%^ORANGE%^A many-headed hydra%^RESET%^");
    set_long("%^ORANGE%^Dull, leathery %^BOLD%^%^BLACK%^gray-brown skin %^RESET%^%^ORANGE%^encases the hide of "
"this reptilian beast.  It looks like some sort of large lizard, except for the fact that it has six "
"heads, all moving and peering about atop long necks that extend from its broad chest.  Each head sports a "
"sharp beaked nose above its %^WHITE%^fanged maw%^ORANGE%^, leading back to three %^RED%^blunt spikes "
"%^ORANGE%^along the crest of its skull.  The massive body is supported upon four muscled limbs, all sporting "
"%^BOLD%^%^BLACK%^razor-sharp claws %^RESET%^%^ORANGE%^at their ends.  A long, constantly lashing tail "
"completes the thirty-foot long creature.%^RESET%^");
    set_race("hydra");
    set_body_type("dragon");
    if (random(2)) set_gender("male");
    else set_gender("female");
    set_alignment(5);
    remove_limb("left wing");
    remove_limb("right wing");
    remove_limb("head");
    add_limb("first head","torso", 0, 0, 0);
    add_limb("second head","torso", 0, 0, 0);
    add_limb("third head","torso", 0, 0, 0);
    add_limb("fourth head","torso", 0, 0, 0);
    add_limb("fifth head","torso", 0, 0, 0);
    add_limb("sixth head","torso", 0, 0, 0);
    set_nogo(({MID+"tunnel09","/d/dagger/kinaro/mines/lower2q"}));
    set_speed(100);
    set_moving(1);
    set_class("fighter");
    set_hd(32,8);
    set_guild_level("fighter",32);
    set_mlevel("fighter",32);
    set_max_hp(600);
    set_hp(600);
    set_property("swarm",1);
    set_stats("strength",16);
    set_stats("dexterity",15);
    set_exp(7000);
    set_overall_ac(-20);
    set("aggressive",25);
    set_attack_limbs(({"first head","second head","third head","fourth head","fifth head","sixth head","left foreclaw","right foreclaw"}));
    set_attacks_num(8);
    set_base_damage_type("slashing");
    set_damage(2,4);
    set_hit_funcs( (["first head":(:TO,"breath_fun":),
                     "second head":(:TO,"breath_fun":)]) );
}

int kill_ob(object victim, int which) {
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold && !flagme) {
      tell_room(ETO,"%^GREEN%^The hydra snarls and advances forward, its heads writhing towards its "
"new victim.%^RESET%^");
      flagme = 1;
    }
    return hold;
}

void breath_fun(object targ) {
    object *pplz;
    int i,freeze;
    if(!objectp(TO)) return;
    pplz = all_living(ETO);
    if(breed) { tell_room(ETO,"%^ORANGE%^The hydra rears back one of its heads and unleashes a breath of "
"%^RED%^blazing fire%^ORANGE%^!%^RESET%^"); }
    else { tell_room(ETO,"%^ORANGE%^The hydra rears back one of its heads and unleashes a breath of "
"%^CYAN%^freezing ice%^ORANGE%^!%^RESET%^"); }
    TO->set_property("magic",1);
    for(i=0;i<sizeof(pplz);i++) {
     if (!objectp(pplz[i])) continue;
     if (pplz[i] == TO) continue;
     if (pplz[i]->query_true_invis()) continue; 
     if("daemon/saving_d"->saving_throw(pplz[i],"breath_weapon")) {
       if(breed) {
         tell_object(pplz[i],"%^RED%^You manage to avoid the worst of the attack!%^RESET%^");
         pplz[i]->do_damage("torso",roll_dice(1,8));
       }
       else {
         tell_object(pplz[i],"%^CYAN%^You manage to avoid the worst of the attack!%^RESET%^");
         pplz[i]->do_damage("torso",roll_dice(1,8));
       }
     }
     else {
       if(breed) {
         tell_object(pplz[i],"%^RED%^You take the full force of its burning breath!%^RESET%^");
         pplz[i]->do_damage("torso",roll_dice(3,8));
       }
       else {
         tell_object(pplz[i],"%^CYAN%^You take the full force of its icy breath!%^RESET%^");
         pplz[i]->do_damage("torso",roll_dice(2,8));
         freeze = pplz[i]->query_stats("constitution");
         freeze = 20-freeze;
         pplz[i]->set_paralyzed(freeze,"%^CYAN%^The icy breath has chilled you to the bone!%^RESET%^");
       }
     }
   }
   TO->remove_property("magic");
   return;
}

void heart_beat() 
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!sizeof(TO->query_attackers())) flagme = 0;
}
