#include <std.h>
#include "../ogres.h"

inherit WEAPONLESS;

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
        tell_room(ETO, "%^RESET%^RED%^The demon glares in your direction. Power flares "+
"as it pulls you violently from your hiding.");
	TP->set_invis();
    }
    kill_ob(TP,1);
}

void create() {
    object ob;
    ::create();
    set_name("ahstuz");
    set_id( ({"demon", "greater demon", "daemon", "ahstuz", "Ahstuz", "general"}) );
    set_short("%^RESET%^%^BOLD%^Ahstuz, General of the Ravaging Hordes%^RESET%^");
    set_long("%^RESET%^%^WHITE%^This demon stands well over twenty feet tall. He is humanoid, "+
"yet besides the placement of normal limbs, the resemblance to any human is a stretch. His torso"+
" is small and g%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^unt and you see evidence of every "+
"single rib. His arms and legs however are freakishly long. His hands drag on the floor and his"+
" legs are bent at extreme angles. Two vesitigial wings drape uslessly on his shoulders. His head "+
"is likewise g%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^unt, the skin pulled tight against "+
"sharp bones. His mouth is filled with %^RESET%^%^BOLD%^%^BLACK%^jagged teeth %^RESET%^%^WHITE%^"+
"and his eyes %^RESET%^%^BOLD%^%^RED%^gl%^RESET%^%^RED%^o%^RESET%^%^BOLD%^%^RED%^w %^RESET%^"+
"%^WHITE%^with an unholy light."
    );
    set_race("demon");
    set_property("magic", 1);
    set_gender("male");
    set_size(3);
    set_class("fighter");
    set_mlevel("fighter", 40);
    set_hd(40,5);
    set_max_hp(1800 + random(501));
    set_new_exp(25,"boss");
    set_hp(query_max_hp());
    set_overall_ac(-10);
    add_limb("left wing","left wing",100,1,6);
    add_limb("right wing","right wing",100,1,6);
    add_limb("barbed tail", "barbed tail",50,1,8);
    add_limb("fangs", "fangs",25,1,7);
    add_limb("right talon", "right talon",50,1,3);
    add_limb("left talon", "left talon",50,1,3);
    set_attacks_num(5);
    set_property("no bows",1);
    set_attack_limbs( ({"barbed tail", "right talon", "left talon", "fangs", "right wing", "left wing"}) );
    set_base_damage_type("slashing");
   set_damage(8,4);
    set_property("swarm",1);
    set_stats("strength",21);
    set_stats("dexterity", 16);
    set_stats("constitution", 17);
    set_stats("intelligence", 12);
    set_stats("wisdom", 12);
    set_stats("charisma", 10);
       new(OBJ"doubletflames")->move(TO);
       new(OBJ"flesh_dagger")->move(TO);
       new(OBJ"stormshatter")->move(TO);
       command("wield dagger");
     command("wear doublet");
    set("aggressive", 20);
    set_mob_magic_resistance("average");
    set_funcs( ({"rip", "heal_up"}) );
    set_func_chance(40);
    set_alignment(9);
    add_money("gold", random(2500));
    add_money("silver", random(2500));
    ob = new("/d/deku/armours/ring_p.c");
    ob->set_property("enchantment", 3);
    ob->move(TO);
command("wear ring");
    set_emotes(2, ({
	"%^RED%^Ahstuz raises his arms to the air and roars at the top of his lungs!%^RESET%^",
	"%^BLUE%^Ahstuz stares deep into your soul.%^RESET%^",
	"%^BOLD%^%^RED%^Ahstuz dives at you, trying to rip your hear from your shoulders!%^RESET%^",
      }),1);
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
    set_resistance("electricity",20);
    set_resistance("acid",10);
    set_resistance("cold",10);
    set_resistance("fire",10);
}

void die(object ob) {
    int i;
    object *att;

    if(ETO->query("alternative world")) { return ::die(ob); }
    ETO->lockdown();
    tell_room(ETO, "%^BOLD%^%^RED%^Ahstuz screams in pain as his "+
       "wounds bleed glowing red blood.\nAhstuz drops to his knees "+
       "and looks into your eyes.");
    command("say You have been worthy opponents, but now I shall "+
       "TAKE YOU TO THE ABYSS!");
    command("cackle");
    tell_room(ETO, "%^BOLD%^%^RED%^\nAhstuz raises his arms in your "+
       "direction and screams and a great wave of %^BLACK%^pure evil "+
       "%^RED%^spreads from his fingers and washes over you!\n\n   "+
       "You feel your heart slow, and stop as you drop to your knees "+
       "unable to breathe!\n\n   Suddenly Ahstuz falls to the ground "+
       "dead, his power gone.\nYou gasp for breath as your heart "+
       "suddenly starts beating again.");
    message("broadcast", "%^BOLD%^%^RED%^   A great pillar of flame can "+
       "be seen in the north sky as the portal to the pits of hell is "+
       "closed.", users());
    att = all_living(ETO);
    for(i=0;i<sizeof(att);i++){
      if(!interactive(att[i])) continue;
      att[i]->set_mini_quest("Ogre Hordes", 1000000,"You defeated Ahstuz, "+
         "and sealed the Gate to Hell, freeing the souls of the Ogres.");
      tell_object(att[i], "%^BOLD%^%^BLUE%^   You have sealed the gate to "+
         "Hell, and have freed the souls of the ogres, so that some day "+
         "they may free their bodies from the grasp of the Abyss.\n");
    }
    ::die(ob);
}

void rip(object targ){
    if(random(30) > targ->query_stats("dexterity")){
	tell_object(targ, "%^BOLD%^%^RED%^Ahstuz grabs you by the "+
         "shoulders and picks you up high into the air!\n  Ahstuz "+
         "leans his head back and roars before suddenly plunging "+
         "his fangs into your neck!!!\n  %^RESET%^%^BOLD%^You can "+
         "feel the poison from his fangs seep into your blood before "+
         "he yanks his head away and rips a large chunk from your neck!!");
	tell_room(environment(targ), "%^BOLD%^%^RED%^Ahstuz grabs "+
         ""+targ->QCN+" by the shoulders lifting "+targ->QO+" high "+
         "into the air!\n  Ahstuz leans his head back and roars before "+
         "driving his fangs deep into "+targ->QCN+"'s neck, then yanks "+
         "away ripping a large chunk from "+targ->QP+" neck!");
	targ->add_poisoning(20);
	targ->do_damage(targ->return_target_limb(), roll_dice(10,15));
	targ->set_paralyzed(roll_dice(1,8), "You are stuck in the great jaws of the demon!");
    } else {
	tell_room(environment(targ), "%^BOLD%^%^RED%^Ahstuz raises his arms "+
         "to the air and roars at the top of his lungs!%^RESET%^");
    if(!targ->will_save(query_level()))
        "/std/effect/status/panicked"->apply_effect(targ,roll_dice(1,6));
    }
}

void heal_up(object targ){
    int dam;

    tell_object(targ, "%^BOLD%^Ahstuz stares you in the eyes, and you can "+
       "feel him trying to pull your soul from you!");
    dam = roll_dice(3,20);
    targ->do_damage("torso", dam);
    TO->heal(dam);
    return;
}
