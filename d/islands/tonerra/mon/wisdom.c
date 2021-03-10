//strength.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create(){
   ::create();
   set_name("guardian of wisdom");
   set_short("Guardian of wisdom");
   set_id(({"guardian","wisdom","guardian of wisdom"}));
   set_long(
@OLI
   This is the guardian of wisdom. The ancient knowledge and experience
of the monks is guarded by this being. Old and narled by time this does
not appear to be a especially dangerous or formidable oponent. But the
knowledge of the body is this creatures as it is the monks.
OLI
   );
   set_race("guardian");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(-14);
   set_hd(55,1);
   set_class("thief");
   set_mlevel("cleric",90);
   set_hp(550);
   set_exp(45000);
   set_max_level(36);
   set_attack_limbs(({"right hand","left hand"}));
   set_attacks_num(2);
   set_mob_magic_resistance("average");
   set_damage(2,8);
   set_base_damage_type("bludgeoning");
   set_stats("dexterity",100);
   set_funcs(({"breakem"}));
   set_func_chance(15);
   set_stats("wisdom",25);
   set_stats("intelligence",1);
   set_stats("charisma",1);
   new(MONASTERY+"wis")->move(TO);
   set_new_exp(35,"boss");
 }

 void init(){
    ::init();
    if(!TP->query_true_invis() && member_array("guardian",(string *)TP->query_id()) == -1)
       kill_ob(TP,1);
 }

 void set_paralyzed(int time,string message){
    if(PO->is_spell() || PO->query_property("magic")){
       tell_room(ETO,"%^BOLD%^The paralysis has no effect.");
       return;
    }
    ::set_paralyzed(time,message);
 }
 int do_damage(string limb, int dam){
    if(base_name(PO) == "/cmds/assassin/_stab" || base_name(PO) == "/cmds/thief/_stab"){
       return ::do_damage(limb,dam/2);
    }
    if(PO->is_spell()){
       return ::do_damage(limb,dam);

    }

    return ::do_damage(limb,dam);
 }

 int query_watched(){
    return 100;
 }

void breakem(object targ){
    return;
}
