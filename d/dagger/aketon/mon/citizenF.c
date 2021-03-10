#include "/d/dagger/aketon/short.h";

inherit WANDER;

void create() {
   ::create();
   set_name("poor citizen");
   set_id( ({"citizen","poor citizen"}) );
   set("race","elf");
   set_gender(random(2)?"male":"female");
   set("short","a poor citizen");
   set("long","This is a poor citizen who lives in Aketon.");
   set_body_type("human");
   set_class("thief");
   set_mlevel("thief",12);
   set_guild_level("thief",12);
   set_hd(12,4);
   set_thief_skill("pick pockets",95);
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   set_scrambling(1);
   add_search_path("/cmds/thief");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_property("swarm",1);
   set_stats("intelligence",8);
   set_stats("wisdom",10);
   set_stats("strength",16);
   set_stats("charisma",8);
   set_stats("dexterity",16);
   set_stats("constitution",10);
   set_max_hp(query_hp());
   add_money("copper",random(20));
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( (string)TP->query_race() == "human" )
      call_out("bad_func",2,TP);
}

void bad_func(object vic) {
   object *inven,*list;
   string *ids;
   int i;
   inven = ({});
   list = ({});
   if( !present(vic->query_name(),ETO) )
      return;
   inven = all_inventory(vic);
   if( (inven) && sizeof(inven) ) {
      for(i = 0;i < sizeof(inven);i++){
         if( !inven[i]->query_worn() && !inven[i]->query_wielded() )
            list += ({inven[i]});
      }
   }
   if( random(2) || !sizeof(list) )
      command("pp "+vic->query_name());
   else {
      ids = list[random(sizeof(list))]->query_id();
      command("steal "+ids[0]+" from "+vic->query_name());
   }
   call_out("bad_func",5,vic);
}

int test_heart() {
   return 1;
}
