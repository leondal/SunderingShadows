//changed to speak wizish so new players wouldn't be lost ~Circe~ 1/3/13
#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_name("Matthew Cinester");
   set_short("Matthew Cinester, caretaker of Offestry Church");
   set_long("Matthew Cinester stands about six feet tall. Brown hair "+
      "with a little bald scalp. His eyes are emerald green shine with "+
      "wisdom. A suit of pure white but simple cloak hides his rather "+
      "slim body. His hands are held together almost always in prayer. "+
      "A thin rope with a simple band of metal hangs around his neck. "+
        "Though he looks knowledgeable about the church and a faithful "+
      "priest, there is a constant expression of grief hanging on his "+
      "face.");
   set_id(({"matthew","cinester","Matthew","Cinester","matthew cinester","caretaker"}));
   set_race("human");
   set_body_type("human");
   set_class("cleric");
   set_hd(60,1);
   set_hp(100000);
   set_spells(({"flame strike","cause blindness","hold person","touchsickle"}));
   set_spell_chance(95);
   set_diety("eldath");
   new("/d/newbie/obj/armor/whitecloak")->move(TO);
   command("wear cloak");
   command("speak wizish");
   new("/d/magic/symbols/eldath_symbol")->move(TO);
   command("wear symbol");
   set_unique(1);
   set_alignment(4);
   remove_std_db();
   set_gender("male");
}

void init(){
   ::init();
   if(TP->query_ghost()){
      call_out("whisper_dead",1,TP);
   }
}

void whisper_dead(object who){
   if(present(who,ETO) && query_attackers() == ({}))
      command("whisper "+who->query_name()+"You may wish to pray, to get a new body.");
}
