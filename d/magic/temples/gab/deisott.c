#include <std.h>
#include <daemons.h>

#include "../loviatar.h"

inherit MONSTER;

int FLAG;

void create(){
   object ob;
   ::create();
   set_name("Deisott");
   set_short("Deisott, temple guard");
   set_id(({"monster","Deisott","temple guard","deisott",
      "guard","human","antipaladin"}));
   set_long("%^BOLD%^%^BLACK%^"+
      "The man standing before you is wearing the darkened full-plate "+
      "of a knight.  He wears a full helm and shield and stands at least "+
      "six foot tall.  His hair is black as coal and his skin a pale "+
      "alabaster, except for the traces of old scars that stand out even "+
      "whiter.  He stands with his back to the wall and watches the room "+
      "with sword in hand, ever ready, ever prepared."+
      "%^RESET%^"
   );
   set_gender("male");
   set_race("human");
   set_hd(30,10);
   set_class("antipaladin");
   set_guild_level("antipaladin", 30);
   set_mlevel("antipaladin", 30);
   set_alignment(3);
   set_body_type("human");
   set_size(2);
   set_overall_ac(0);
   set_exp(10000);
   set_stats("strength",18);
   set_stats("dexterity",15);
   set_stats("intelligence",12);
   set_stats("wisdom",16);
   set_stats("constitution",18);
   set_stats("charisma",17);
   set_max_hp(200+random(200));
   set_hp(query_max_hp());
   set_emotes(1,({
      "Deisott watches you like a hawk, but only his eyes move.",
      "Deisott stands as still as one of the statues.",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^kneel before "+
         "the altar.\n%^BOLD%^%^RED%^Deisott speaks "+
         "condescendingly: %^RESET%^Show obediance now!",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^worship "+
         "loviatar and feel her blessings upon you.",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^She will "+
         "bless you if only you will accept her.",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^stop breathing "+
         "so loud, this is a place of reverance and "+
         "reflection.\n%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^if you "+
         "must snort like a swine, go visit the temple if Tempus...you are just "+
         "what they are looking for.",
      "Deisott smiles, or is that a sneer?",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^learn to "+
         "take the whip, accept it and grow from the experience.",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^don't whine like an Eldathian",
      "Deisott smirks with derision.",
      "%^BOLD%^%^RED%^Deisott speaks condescendingly: %^RESET%^go visit the "+
         "library to the south, your presence is...upsetting to me."
   }),0);

    ob = new("/d/shadow/room/city/cguild/antipaladin/antiplate");
        ob->set_property("monsterweapon", 1);
        ob->move(TO);
    ob = new("/d/shadow/room/city/cguild/antipaladin/anticoif");
       ob->set_property("monsterweapon", 1);
       ob->move(TO);
//    ob = new("/d/islands/tonerra/obj/Lcloak");  Doesn't look very knightly or loviatan
//       ob->set_property("monsterweapon", 1);
//       ob->move(TO);
    ob = new("/d/deku/keep/obj/gloom_shield");
       ob->set_property("monsterweapon", 1);
       ob->move(TO);
    ob = new("/d/darkwood/equip/desecrator");
       ob->set_property("monsterweapon", 1);
       ob->move(TO);
       command("wield sword");
    ob = new("/d/common/obj/potion/healing");
       ob->move(TO);
       ob->set_uses(40);
   command("wearall");

   set_diety("loviatar");
   ob->new("/d/magic/symbols/loviatar_symbol");
      ob->set_property("monsterweapon", 1);
      ob->move(TO);

   add_search_path("/cmds/antipaladin");
   command("speech speak condescendingly");
   command("speak wizish");
   set_property("knock unconscious",1);
   set_property("full attacks",1);
   set_property("no bows",1);

   set_funcs(({"special_att"}));
   set_func_chance(25);

   set_property("swarm",1);
   add_money("gold",random(500));
   add_money("silver",random(500));
   add_money("copper",random(500));
   
   FLAG = 0;
}
void init(){
   ::init();
   add_action("dismiss_em","dismiss");
   add_action("reassign_em","reassign");
}
int dismiss_em(string str) {
   string pgod = TP->query_diety();

   if(!str) return 1;
   if(FLAG == 1) return 1;
   if(TP->query_invis())return 1;
   if (str == "deisott"){
        if(pgod == "loviatar" && TP->is_class("cleric")){
           tell_object(TP,"%^BOLD%^You dismiss sir Deisott.\n");
           command("north");
           FLAG = 1;
         return 1;
      }else{
         command("sneer "+TP->query_name()+"");
         return 1;
      }
   }
   return 1;
}
int reassign_em(string str) {
   string pgod = TP->query_diety();

   if(!str) return 1;
   if(TP->query_invis())return 1;
   if(FLAG == 0) return 1;
   if (str == "deisott"){
        if(pgod == "loviatar" && TP->is_class("cleric")){
           tell_object(TP,"%^BOLD%^You reassign sir Deisott back to his post.\n");
           command("south");
           FLAG = 0;
         return 1;
      }else{
         command("sneer "+TP->query_name()+"");
         return 1;
      }
   }
   return 1;
}

int special_att() {
   object me = TO;
   object vic = me->query_current_attacker();
       switch(random(3)) {
          case 0:
            tell_object(vic,"%^BOLD%^%^RED%^Deisott's sword slashes through your body!");
            tell_room(ETO,"%^BOLD%^%^RED%^Deisott's sword slashes "+
               "through "+vic->QCN+"'s body!",vic);
            if(!"daemon/saving_d"->saving_throw(vic,"paralyzation_poison_death",0)) {
               tell_object(vic,"%^BOLD%^%^RED%^You feel Deisott's sword "+
                  "tug at your soul!\n");
               vic->do_damage("torso",random(50)+1);
//               vic->add_attacker(TO);
//               vic->continue_attack();
            }else{
               vic->do_damage("torso",random(20)+1);
//               vic->add_attacker(TO);
//               vic->continue_attack();
            }
             return 1;
          case 1:
            tell_object(vic,"%^BOLD%^%^RED%^Deisott smashes you in "+
               "the face with his shield momentarily dazing you!");
            tell_room(ETO,"%^BOLD%^%^RED%^Deisott smashes "+
               ""+vic->QCN+" in the face with his shield!",vic);
              vic->set_paralyzed(random(4)+4,"%^BOLD%^%^RED%^You are struggling to "+
                 "regain your composure!");
            vic->do_damage("torso",random(10)+1);
//            vic->add_attacker(TO);
//            vic->continue_attack();
              return 1;
           case 2:
              command("cause wracking pains "+vic->query_name()+"");
              return 1;
           default:
              return 1;
       }
}

void heart_beat() {
     ::heart_beat();
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   if(present("kit",TO) && query_hp() < ((query_max_hp()/3)*2)){
      command("open kit");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
      command("quaff kit");
      command("offer bottle");
    }
   if(present("bottle",TO)) command("offer bottle");
}