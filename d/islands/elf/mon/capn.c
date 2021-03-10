#include <std.h>
#include "/d/islands/elf/elf.h"
inherit MONSTER;

create (){
::create ();
set_name("Captain Rev");
set_id( ({"rev","undead","captian rev","noble","decayed noble"}) );
set_short("Decayed Noble");
set_long("This is an undead person who is wearing "+
"tattered rags from a bygone era.  Bit of flesh are"+
" partly detached and waver in the water. "+
"  It's eye glow red with hatred.  Unlike some"+
" of the other undead this one has the remains of"+
" fancier clothing.  He might have been someone "+
"important when he was still alive.");
set_gender("male");
set_hd(45,10);
set_hp(750+random(5000));
set("race", "undead");
set_body_type("human");
set_property("swarm",1);
set_class("barbarian");
set_mlevel("barbarian",46);
    level = 46;
set_guild_level("barbarian",46);
set_max_level(47);
set_property("full attacks",1);
set_overall_ac(-35);
set_size(2);
set_stats("strength", 25);
set_stats("intelligence", 6);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set_alignment(4);
set_attacks_num(6);
set_hp(query_max_hp());
set_wielding_limbs( ({"left hand","right hand"}) );
add_money("copper", 200 + random(140));
set_resistance("negative energy",10);
set_resistance("positive energy",-10);
set_resistance_percent("slashing", 70);
set_resistance_percent("bludgeoning", 70);
set_mob_magic_resistance("average");
set_monster_feats(({
    "rage",
    "mobility",
    "mighty rage",
    "dodge",
    "greater rage",
    "spell reflection",
    "mobility",
      })); 
set_property("water breather", 1);
set_property("function and attack",1);
new(OBJ"weed_cloak")->move(TO);
new(OBJ"weed_belt2")->move(TO);
new(OBJ"shield")->move(TO);
new(OBJ"ray_spear")->move(TO);
new(OBJ"bottoms")->move(TO);
new(OBJ"scale_mail")->move(TO);
force_me("wearall"); //need wear first, otherwise shield unequiped
force_me("wield spear");
set_funcs(({"sweep"}));
set_func_chance(75);
set_missChance(25);
add_attack_bonus(20);
add_damage_bonus(20);
set_emotes(10,({
    "Captian Rev says: We must defeat the elves.",
    "A small fish chews on the undead man's flesh",
    "Captian Rev says: We were a proud kingdom once.",
    "Captian Rev says: The only good elf is a dead one.",
    "Captian Rev says: We will destroy the elves.",
    "Captian Rev says: For killing the royals the elves must pay.",
    "Captian Rev say: Even in death I will serve.",
    "Captian Rev looks around fearing some unseen attacker.",
    "Captian Rev frowns looking frusterated.",
    "Captian Rev says: How could they kill even the innocents.",
    "Captian Rev paces around the room..",
    "Captian Rev's eyes open wide!",
    "Captian Rev says: My whole family was killed by those gold bastards...",
    "Captian Rev says: My soul won't rest until every elf is dead."
}),0);
}
void init(){
    ::init();
    if(!query_property("raged"))
        force_me("rage");
    return;
}
void heart_beat(){
    object rev, rev0;
    object some_guys;
    ::heart_beat();
    if(!objectp(TO))return;
    if(!objectp(query_current_attacker())) { return ; }
    if(query_attackers()==({ })) return;
   
    if(!present("revenant 2", ETO) || present("corpse of revenant",ETO)){
    force_me("say To me men!  Your war doesn't end until I say so!");
    tell_room(ETO,"%^BOLD%^%^BLACK%^A nearby dead body rises and attacks!");
    rev = new(MON"rev");
	rev->move(ETO);
	TO->add_protector(rev);
    if(present("corpse of revenant",ETO)){
        rev0 = present("corpse of revenant");
        rev0 -> move("/d/shadowgate/void");
        rev0 ->remove();

    }
    some_guys = query_attackers();
    foreach(object ob in some_guys){
               rev->kill_ob(ob,0);
      }
    }
    return;
}
void sweep(object targ){
    object * critters;
    if(!objectp(TO))return;
    if(!objectp(query_current_attacker())) { return ; }
    if(query_attackers()==({ })) return;
    critters = query_attackers();
    tell_room(ETO,"%^RED%^The dead captain lets out a %^BLUE%^drowning%^RED%^ gurgle!");
    foreach(object ob in critters){
    tell_object(ob, "%^BLUE%^The noise makes you feel like you are drowning!." );
    ob->cause_typed_damage(ob, ob->return_target_limb(),random(200),"mental");
  }
}
