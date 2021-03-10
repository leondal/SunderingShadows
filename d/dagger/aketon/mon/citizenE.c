#include "/d/dagger/aketon/short.h";

#define ITEMS ({OPATH+"de_ring",OPATH+"hj_ring",OPATH+"kp_band",\
   OPATH+"sg_band",OPATH+"so_ring"})

inherit WANDER;

void create() {
   ::create();
   set_name("rich citizen");
   set_id( ({"citizen","rich citizen"}) );
   set("race","elf");
   set_gender(random(2)?"male":"female");
   set("short","a rich citizen");
   set("long","This is a citizen who appears to be rich and lives in "
      "Aketon.");
   set_body_type("human");
   set_class("cleric");
   set_mlevel("cleric",8);
   set_guild_level("cleric",8);
   set_hd(8,4);
   set_spells( ({"call lightning",
      "limb attack",
      "cause blindness"}) );
   set_spell_chance(100);
   set_alignment(2);
   set_size(2);
   set_stats("intelligence",13);
   set_stats("wisdom",16);
   set_stats("strength",10);
   set_stats("charisma",16);
   set_stats("dexterity",8);
   set_stats("constitution",8);
   set_max_hp(query_hp());
   add_money("silver",random(800));
   add_money("gold",random(1000));
   add_money("copper",random(1000));
   add_money("electrum",random(100));
   new( ITEMS[ random( sizeof(ITEMS) ) ] )->move(TO);
   command("wearall");
   call_out("hippo",0);
}

void hippo() {
   new(MPATH+"hippogriff")->move(ETO);
   command("mount hippogriff");
}

int test_heart() {
   return 1;
}

int kill_ob(object victim,int which) {
   int hold;
   hold = ::kill_ob(victim,which);
   if(hold)
      command("sic "+victim->query_name());
   return hold;
}
