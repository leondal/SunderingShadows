#include <std.h>
#include <daemons.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

object ob;

create() {
   ::create();
   set_name("archemond");
   set_id(({ "human","mage","archemond","Archemond","cult leader"}));
   set_short("%^RESET%^%^GREEN%^Archemond, listener of the True Voice%^RESET%^");
   set_long("%^BLUE%^%^BOLD%^Archemond is a tall man, of svelte figure and garbed in long ceremonial "
"robes.  He has fine, blonde hair that he has not bothered to restrain, and it falls loosely around his "
"slender shoulders.  His features are angular, but not overly so, and he would look quite pleasant were "
"it not for the glittering stare of his dark eyes.  A glowing amulet rests around his neck.%^RESET%^");
   set_class("mage");
   set_mlevel("mage",29);
   set_guild_level("mage",29);
   add_search_path("/cmds/wizard");
   set_spells(({"magic missile","magic missile","chain lightning","fireball","fireball","cone of cold","cone of cold","hideous laughter","powerword stun"}));
   set_spell_chance(80);
   set_race("human");
   set_gender("male");
   set_body_type("human");
   set_size(2);
   set_stats("intelligence",18);
   set_stats("wisdom",13);
   set_stats("strength",11);
   set_stats("charisma",16);
   set_stats("dexterity",14);
   set_stats("constitution",12);
   set_alignment(9);
   set_exp(60000);
   set_overall_ac(-2);
   set_hd(40,15);
   set_max_hp(random(200)+1200);
   set_hp(query_max_hp());
   set_attacks_num(1);
   add_money("gold",random(300)+15);
   add_money("platinum",random(100));
   command("speak common");
   command("speech speak resonantly");
   set_property("no bows",1);
   //set_mob_magic_resistance("average");
   set("aggressive","agg_fun");
   set_emotes(1, ({"The mage closes his hands around the amulet at his neck, murmuring softly to it.",
"The mage brushes a lock of blonde hair away from his face.",
"The mage pauses, tilting his head as if to listen to the amulet at his neck."}), 0);
   set_achats(2, ({"The mage snaps his fingers, and a crackle of electricity jumps between them.",
"The mage smiles wickedly at you.",
"The mage spreads his arms wide, as the amulet at his throat glows brightly."}) );
   set_funcs(({"amulet"}));
   set_func_chance(100);
   ob = new(OBJ+"amulet");
   ob->move(TO);
   command("wear amulet");
}

void init() {
    ::init();
    add_action("deflect_fun","throw");
    add_action("deflect_fun","toss");
    if(!TP->query_true_invis()) {
      if(TP->query_invis()) { TP->set_invis(); }
    }
}

int agg_fun() {
   if (sizeof(TO->query_attackers()) < 1) {
     force_me("emoteat "+TPQN+ " $M's gaze falls upon $N, his eyes glowing with the same intensity as "
"the amulet about his neck.");
     force_me("say Now you will pay for your ignorance, let the True Voice show you its power!");
     new("/cmds/spells/w/_wall_of_fire")->use_spell(TO,0,25,100,"mage");
   }
   force_me("kill "+TP->query_name());
}

int amulet(object targ){
   object *pplz;
   int i,damage;
   pplz = all_living(ETO);
   tell_room(ETO,"%^BLACK%^%^BOLD%^The mage's eyes flash as his amulet takes on a life of its own, "
"rising to hover in the air before him.");
   for(i=0;i<sizeof(pplz);i++) {
     if(pplz[i] != TO && !pplz[i]->query_true_invis() && objectp(pplz[i])) {
       if(!"daemon/saving_d"->saving_throw(pplz[i],"spell")) {
         tell_object(pplz[i],"%^BLACK%^%^BOLD%^An aura pulses forth from the amulet, stealing the life "
"from your veins!%^RESET%^");
         damage = roll_dice(5,8);
         pplz[i]->do_damage("torso",damage);
         TO->do_damage((-1)*damage);
       }
       else {
         tell_object(pplz[i],"%^BLACK%^%^BOLD%^An aura pulses forth from the amulet, but you concentrate "
"and resist its pull!%^RESET%^");
       }
     }
   }
   return 1;
}

void die(object ob) {
   object who, *killers;
   int i;
   killers = ({});
   killers = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
      for(i=0;i<sizeof(killers);i++){
      if(!objectp(killers[i])) { continue; }
      killers[i]->set_mini_quest("Killed Archemond");//temporary place setting for party friendly quests. This is worth no experience in itself
      }
   tell_room(ETO,"%^RED%^The mage lets out a dying scream and slumps to the floor");
   switch(random(4)) {
     case 0:
       new(OBJ+"thundergloves")->move(TO);
     break;
     case 1:
       new(OBJ+"rangerglove")->move(TO);
     break;
     case 2:
       new(OBJ+"featheredhat")->move(TO);
     break;
     case 3:
       new(OBJ+"kimono")->move(TO);
     break;
   }
   switch(random(4)) {
     case 0:
       new(OBJ+"butterflycloak")->move(TO);
     break;
     case 1:
       new(OBJ+"battleguards")->move(TO);
     break;
     case 2:
       new(OBJ+"circlet")->move(TO);
     break;
     case 3:
       new(OBJ+"hairpin")->move(TO);
     break;
   }
   switch(random(5)) {
     case 0:
       new(OBJ+"wolfjacket")->move(TO);
     break;
     case 1:
       new(OBJ+"veil")->move(TO);
     break;
     case 2:
       new(OBJ+"vest")->move(TO);
     break;
     case 3:
       new(OBJ+"katar")->move(TO);
     break;
     case 4:
       new(OBJ+"pothelmet")->move(TO);
     break;
   }
   :: die(TO);
}

int deflect_fun(string str) {
   if (strsrch(str,"mage") != -1 || strsrch(str,"archemond") != -1 || strsrch(str,"human") != -1) {
     write("The mage turns and fixes his gaze directly upon you.\nYou find yourself frozen in place.");
     write("%^CYAN%^%^BOLD%^A voice whispers in your mind:%^RESET%^ Now now, that was foolish wasn't it?");
     tell_room(ETP,""+TP->QCN+" goes to move, but suddenly freezes in place as the mage stares pointedly at "+TP->QO+".",TP);
     TP->set_paralyzed(20,"You are held by an unseen force!");
     return 1;
   }
   return 0;
}
