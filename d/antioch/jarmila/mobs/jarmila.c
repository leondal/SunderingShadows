//Avatar of Jarmila
#include <std.h>
#include <daemons.h>
#include "../jarmila.h"

inherit WEAPONLESS;

int fate_counter;

object bork_control;

void create()
{

    ::create();
    set_name("Avatar of Jarmila");
    set_id(({ "great golden pheonix", "pheonix", "avatar", "jarmila" }));
    set_short("%^C226%^Gre%^C196%^a%^C226%^t G%^C230%^"+
		"o%^C226%^lden Phoe%^C230%^n%^C226%^ix%^C226%^, "+
		"%^C160%^Av%^C124%^a%^C160%^tar of J%^C124%^"+
		"a%^C160%^rmila%^CRST%^");
    set_long("%^C197%^This immense beast is almost beyond "+
	    "all mortal %^C088%^comprehension%^C197%^ and %^C226%^power%^C197%^. "+
	    "Its entire body is formed from %^124%^blazing divine fire%^C197%^ "+
        "and looks like a giant bird. Its %^C166%^two feet%^C197%^ are each "+
	    "the size of %^C058%^large wagons%^C197%^ and extend to "+
	    "%^C244%^wicked claws%^C197%^ each the size of a man. "+
	    "Its %^C124%^two wings%^C197%^ extend two hundred feet in "+
	    "either direction and when they beat the whole area is "+
	    "bathed in %^C220%^insufferable heat%^C197%^. Long tendrils "+
	    "of %^C124%^flame%^C197%^ extend to form a tail. The most "+
	    "%^C124%^ferocious fire%^C197%^ is reserved for its face, "+
	    "where two eyes as %^C228%^bright as the sun%^C197%^ regard "+
	    "the area with unknowable amounts of wisdom. Overall this "+
	    "avatar is a beast none but the most daring would dare to "+
	    "face.%^CRST%^\n");

    set_gender("female");
    set_race("phoenix");
    set_body_type("fowl");
    set_attack_limbs(({ "right claw", "left claw", "mouth", "tail", "beak", "left wing", "right wing"}));
   
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_guild_level("fighter", 80);
    set_guild_level("mage", 80);
    set_guild_level("cleric", 80);
    set_mlevel("fighter", 80);
    set_mlevel("mage", 80);
    set_mlevel("cleric", 80);
   set_alignment(1);
    set("aggressive",100);
    set_property("full attacks",1);
    set_true_seeing(1);

    set_hd(80, 10);
    set_hp(125000);
    set_new_exp(80, "boss");
    set_overall_ac(-55);

    set_damage(10, 20);
    set_base_damage_type("slashing");
			    set_property("weapon resistance", 10);
    set_mob_magic_resistance("high");
    set_property("no death", 1);
    set_property("no knockdown", 1);
    set_property("no trip", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 0);
    set_property("no stun", 0);
    set_property("no bows", 1);

    set_monster_feats(({
	        "spell penetration", "greater spell penetration", "perfect caster"
    }));

   set_funcs(({
      "flare",
      "comet",
      "fire",
      "light",
      "reinforce",
      "holy",
      "clear",

   }));
   set_func_chance(100);

    set_skill("perception", 50);

    set_resistance("holy", 80);
    set_property("cast and attack", 1);
    set_property("function and attack", 1);
    set_property("add quest", "%^BOLD%^%^RED%^Faced the Avatar of Jarmila!%^RESET%^");
    set_property("quest exp", 10000000);

    fate_counter = 0;

}


int query_paralyzed()
{
    return 0;
}

int query_tripped()
{
    return 0;
}


void flare (object targ){
new("/cmds/spells/s/_sunburst.c")->use_spell(TO, targ, 80, 100, "cleric");
   fate_counter++;
         check_fate();
   return;
}

void comet (object targ){

int dam;
//dam = random(500)+100;
dam = roll_dice(25, 20) + 100;

   if(!"/daemon/saving_throw_d.c"->dex_save(targ,40)){

   tell_room(ETO,"%^C178%^The phoenix spreads its massive wings wide "+
   "and calls down a single massive commet on "+targ->QCN+"%^C178%^ which "+
   "engulfs them!%^CRST%^",targ);
   tell_object(targ,"%^C178%^The phoenix spreads its wings and it calls a "+
   "massive comet that plummets towards you!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"fire");
   return;

   fate_counter++;
   check_fate();
   return;
      
}

   else{
   
   dam = dam/2;
   tell_room(ETO,"%^C178%^The phoenix spreads its massive wings wide and "+
   "calls down a single massive commet on "+targ->QCN+"%^C178%^!%^CRST%^",targ);
   tell_object(targ,"%^C178%^The phoenix spreads its wings and it calls a "+
   "massive comet that plummets towards you!%^CRST%^");
   tell_object(targ,"%^C178%^You jump out of the way just in time, "+
   "but still feel fire lick across you!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"fire");
   return;

   fate_counter++;
   check_fate();
   return;
}
}

void fire (object targ){
   tell_room(ETO,"%^C197%^With a scream the phoenix bursts forth with "+
   "several spells all at once!%^CRST%^");

   new("/cmds/spells/m/_meteor_swarm.c")->use_spell(TO,targ,40,100,"mage");
   new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ,40,100,"mage");
   new("/cmds/spells/w/_wall_of_fire.c")->use_spell(TO,targ,40,100,"mage");
      fate_counter++;
      check_fate();
   return;
}


void light (object targ){

int dam;
//dam = random(300)+100;
dam = roll_dice(15, 20) + 100;

   if(!"/daemon/saving_throw_d.c"->will_save(targ,40)){

   tell_room(ETO,"%^C127%^The phoenix grabs "+targ->QCN+"%^C127%^ "+
   "and lifts them up to their face. It's eyes blaze "+
   "and "+targ->QCN+"%^C127%^ is left dazed!%^CRST%^",targ);
   tell_object(targ,"%^C127%^You are lifed up suddenly "+
   "in the claws of the phoenix and crushed!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"piercing");
   tell_object(targ,"%^C127%^The phoenix lifts you "+
   "until you're in front of its eyes which flash. "+
   "You cant turn away in time and are stunned.%^CRST%^");
    targ->set_paralyzed(random(30)+30,"%^C127%^You are "+
	"stunned from the daze of the phoenix!%^CRST%^");
           return;

   fate_counter++;
   check_fate();
   return;
      
}

   else{
   
   tell_room(ETO,"%^C127%^The phoenix grabs "+targ->QCN+" "+
   "%^C127%^and lifts them up to their face. It's eyes "+
   "blaze and "+targ->QCN+" %^C127%^is left dazed!%^CRST%^",targ);
   tell_object(targ,"%^C127%^You are lifted up suddenly "+
   "in the claws of the phoenix and crushed!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam / 2,"piercing");
   tell_object(targ,"%^C127%^The phoenix lifts you until "+
   "you're in front of its eyes which flash. You turn "+
   "away just in time.%^CRST%^");
           return;

   fate_counter++;
   check_fate();
   return;
}
}

void reinforce(object ob){
   int i, num;
   num=random(4)+3;
   if(!objectp(TO)) return;
   tell_room(ETO,"%^C222%^For a moment the glow intensifies and "+
   "creates rush into the area to defend the phoenix!%^CRST%^");

                 for(i=0;i<num;i++){
                    ob=new(MOBS"foo");
                        ob->move(ETO);
                        TO->add_follower(ob);
                 }
   fate_counter++;
   check_fate();
   return;
}

void holy (object targ){

int dam;
//dam = random(500)+100;
dam = roll_dice(25, 20) + 100;

   if(!"/daemon/saving_throw_d.c"->fort_save(targ,40)){

   tell_room(ETO,"%^C225%^A blast of holy energy from the phoenix's "+
   "eyes blasts towards "+targ->QCN+"%^C225%^ which "+
   "engulfs them!%^CRST%^",targ);
   tell_object(targ,"%^C225%^You are flooded with holy energy "+
   "that blasts from the phoenix!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"divine");
   return;

   fate_counter++;
   check_fate();
   return;
      
}

   else{
   
   dam = dam/3;
   tell_room(ETO,"%^C225%^A blast of holy energy from the phoenix's "+
   "eyes blasts towards "+targ->QCN+"%^C225%^ which "+
   "engulfs them!%^CRST%^",targ);
   tell_object(targ,"%^C225%^You are flooded with holy energy that "+
   "blasts from the phoenix!%^CRST%^");
   tell_object(targ,"%^C225%^You grit your teeth and feel "+
   "the worst of the attack fade!%^CRST%^");
   targ->cause_typed_damage(targ, targ->return_target_limb(), dam,"divine");
   return;

   fate_counter++;
   check_fate();
   return;
}
}
void clear (object targ){
   tell_room(ETO,"%^C196%^The phoenix chants an ancient holy prayer!%^CRST%^");
   new("/cmds/spells/g/_greater_dispel_magic.c")->use_spell(TO,targ,80,100,"mage");
   return;
      fate_counter++;
      check_fate();
}


void check_fate(){
   if(fate_counter > 9) {unbork();}
   if(fate_counter == 5) {bork();}
}  

void bork (object targ){

   bork_control =find_object_or_load(ROOMS"top.c");
   bork_control->func_bork();    
   tell_room(ETO,"%^C153%^With a flash of the Phoenix's eyes "+
   "a heavy mist fills the area!%^CRST%^");
   return;
}
void unbork (object targ){

   bork_control =find_object_or_load(ROOMS"top.c");
   bork_control->func_unbork();
   fate_counter = 0;    
   tell_room(ETO,"%^C153%^The massive phoenix flaps "+
   "its wings and the mist clears from the area!%^CRST%^");
   return;
}


void die(object ob) {
    int i;
    object *att;

    ETO->lockdown();
    tell_room(ETO, "%^C160%^The phoenix bursts into an explosion "+
	"of epic proportions and disappears, though the force of its "+
	"death has cracked open one of the larger sunstones.%^CRST%^");
    message("broadcast", "   %^C160%^A great plume of %^C124%^"+
	"fire%^C160%^ erupts on the horizon and for a moment the "+
	"entire realm is basked in a %^C226%^g%^C166%^o%^C226%^lden "+
	"gl%^C166%^o%^C226%^w%^C160%^, then it fades.%^CRST%^", users());
    att = all_living(ETO);
    for(i=0;i<sizeof(att);i++){
      if(!interactive(att[i])) continue;
      att[i]->set_mini_quest("Challenged the Avatar of "+
	  "Jarmila", 1000000,"%^C160%^Challenged the Avatar of Jarmila%^CRST%^");
      tell_object(att[i], "%^C160%^You accomplished: Challenged the Avatar of Jarmila.%^CRST%^\n");

    }
   TO->remove();
   new(OBJ"cracked_sunstone")->move(TO);
}
