#include <std.h>
#include "../defs.h"
inherit "/std/psion_vend.c";

void create(){
   ::create();
   set_name("grafkai");
   set_short("Grafkai, duergar merchant");
   set_id(({"grafkai","Grafkai","merchant","duergar merchant"}));
   set_long("Before you stands a dwarf, but a strange looking one at that.  His lean frame is covered in gray "
"skin the color of stone, leaving him to blend in remarkably well with his surroundings.  Humorless black eyes "
"peer out upon his small world with a cold, bitter gaze, set within a face that is framed by a bald head and a "
"gray beard and moustache.  If asked, he can <shape> a psionic gem to be attuned to your image, or sell you "
"the basics of his trade.");
   set_race("duergar");
   set_body_type("human");
   set_gender("male");
   set_class("psion");
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_spells(({"mind thrust","mind thrust","mind thrust","energy bolt","energy bolt"}));
   set_spell_chance(70);
   set_alignment(3);
   remove_std_db();
   set_spoken("undercommon");
}

void init(){
   ::init();
   add_action("shape_em","shape");
}

int shape_em(){
   object ob;
   command("emoteat "+TPQN+" glances up at $N for a moment.");
   command("say You wish a gem that resonates with your spirit, hmm?");
   command("emoteat "+TPQN+" draws forth a gem from a pouch and "+
      "studies $N through it.");
   if(!TP->is_class("psion") && !avatarp(TP)){
      command("say I will not do it.  Your mind does not hold the "+
         "capacity to use such a thing, and my time is precious.");
      return 1;
   }
   if(!TP->query_funds("gold",2000))  {
      command("say You lack the funds to pay me.  For "+
         "you, it will cost two thousand gold coins.");
      command("emote slips the gem back into a pouch.");
      return 1;
   }
   TP->use_funds("gold",2000);
   command("emote allows the crystal to hover in the air before "+
      "him as he summons power.");
   tell_room(ETO,"%^BOLD%^%^WHITE%^The crystal flashes with a brilliant "+
      "light before the duergar plucks it from the air.");
   ob = new("/d/magic/obj/exigency_gem");
   ob->set_weight(0);
   ob->move(TP);
   ob->move(TO);
   ob->set_weight(10);
   command("give exigency gem to "+TPQN+"");
   return 1;
}