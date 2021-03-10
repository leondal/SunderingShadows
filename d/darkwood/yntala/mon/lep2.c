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
   set("aggressive","aggfunc");
   set_mlevel("mage",11);
   set_guild_level("mage",11);
   set_spell_chance(85);
   set_spells(({"lightning bolt","fireball","dispel magic","lower resistance","fireball"}));
   set_mob_magic_resistance("average");
   if(random(10) < 1){
      ob = new("/d/magic/scroll");
      ob->set_av_spell(5-random(3));
      ob->move(TO);
   }
   if(random(10) < 1){
      new(OBJD+"amulet1.c")->move(TO);
      command("wear amulet");
   }
   if(random(15) < 1){
     ob=new(LGSW+"dagger.c");
     ob->set_property("enchantment",2);
     ob->set_long("%^BOLD%^%^WHITE%^This is a pretty, decorative little dagger that has been crafted of some sort"
" of %^GREEN%^emer%^WHITE%^a%^GREEN%^ld green %^WHITE%^material.  The pommel of the dagger has been formed into"
" the shape of a %^GREEN%^four leaf clover, %^WHITE%^carved from pure %^GREEN%^emerald.  %^WHITE%^The blade"
" itself is short and slender, ending in a fine point that would make any weaponsmith proud to have made.%^RESET%^");
     ob->set_obvious_short("%^BOLD%^%^GREEN%^An emerald green dagger%^RESET%^");
     ob->set_short("%^BOLD%^%^GREEN%^Dagger of L%^RESET%^%^GREEN%^u%^BOLD%^c%^RESET%^%^GREEN%^k%^RESET%^");
     ob->move(TO);
     command("wield dagger");
   }
}
int aggfunc() {
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
