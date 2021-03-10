#include <std.h>
#include "/d/darkwood/yntala/yntala.h"
inherit MONSTER;
object ob;


void create (){

::create ();
   set_name("leprechaun");
   set_id(({"leprechaun","leprachaun","fey"}));
   set_short("%^RESET%^%^GREEN%^A small little leprechaun%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This is a small little creature"
" most commonly known as a leprechaun.  He wears a small green"
" jacket decorated with clovers embroidered on it, and a pair"
" of plain green pants with a %^ORANGE%^brown %^GREEN%^belt to"
" hold them up.  %^BOLD%^%^BLACK%^Shiny black shoes"
" %^RESET%^%^GREEN%^adorn his small feet, and a funny looking"
" hat rests on his head.  He is quite portly in build, with a"
" small pot belly that shakes whenever he laughs.%^RESET%^");
   set_race("leprechaun");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(13,2);
   set_overall_ac(-2);
   set_size(1);
   set_stats("intelligence",18);
   set_stats("strength",18);
   set_stats("wisdom",15);
   set_stats("dexterity",15);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("gold",random(1000));
   set_money("silver",random(1500));
   set_money("copper",random(50));
   set_money("electrum",random(1000));
   set_class("mage");
   set_exp(3000);
   set_max_level(15);
   set_alignment(9);
   set_hp(random(250)+150);
   set_max_hp(query_hp());
   set_property("full attacks",1);
   set_func_chance(40);
   set_funcs(({"rainbow"}));
   set("aggressive","aggfunc");
   set_mlevel("mage",11);
   set_guild_level("mage",11);
   set_spell_chance(85);
   set_spells(({"lightning bolt","fireball","dispel magic"}));
   set_mob_magic_resistance("average");
   ob = new("/d/magic/scroll");
   ob->set_av_spell(5-random(3));
   ob->move(TO);
      if(random(10) < 1){
      new(OBJD+"amulet1.c")->move(TO);
      command("wear amulet");
      }
}
int aggfunc() {
   if(TP->query_level() < 20) {
      if(TP->is_class("thief")){
        force_me("emoteat "+TPQN+ " turns to $N.");
        force_me("say %^GREEN%^Ah, ye've come to get me gold!");
        command("emoteat "+TPQN+ " looks at $N suspiciously.");
        force_me("kill "+TPQN+ "");
      }
      if(TP->is_class("mage")){
        force_me("emoteat "+TPQN+ " cackles as he looks at $N.");
        force_me("say %^GREEN%^Nobodies magic is stronger than me own!");
        force_me("kill "+TPQN+ "");
}
   if(TP->is_class("bard")){
force_me("emoteat "+TPQN+ " grins at $N evilly.");
force_me("say Come, join me in the land of the leprechauns, dance for me!");
force_me("kill "+TPQN+ "");
     }
      if(TP->is_class("ranger")){
        force_me("emoteat "+TPQN+ " grins at $N evilly.");
        force_me("say %^GREEN%^This forest belongs to me!");
        force_me("kill "+TPQN+ "");
      }
      if (TP->is_class("fighter")){
        force_me("emote laughs");
        force_me("say %^GREEN%^You will never be able to take me!");
        force_me("kill "+TPQN+ "");
      }
   return 1;
   }
   else if(TP->query_level()>=20) {
      force_me("say %^GREEN%^Ahhh! I need help!");
      force_me("emote starts screaming like a madman...");
      if(!present("maklakia",ETO)){
      tell_room((ETO),"%^YELLOW%^Suddenly! A bright rift opens and another leprechaun steps through!");
      new("/d/darkwood/yntala/mon/lepking.c")->move(ETO);
      }
      force_me("emote %^YELLOW%^jumps through the rift and disappears, leaving the king to fight you!");
      call_out("dest_effect",1); //added this in to prevent fights with the king that possibly could sway the fight
   return 1;
   }
}

void rainbow(object target){
   tell_room((ETO),"%^RESET%^%^GREEN%^The leprechaun points his fingers at "+target->query_cap_name()+" and "+target->query_subjective()+" disappears!",target);
   tell_object(target, "%^RESET%^%^GREEN%^The leprechaun points a finger at you and you are whisked somewhere else!");
   target->move_player(INRMS+"eor");
}
void dest_effect(){
   if(!objectp(TO)) return;
   TO->move("/d/shadowgate/void");
   remove();
}
