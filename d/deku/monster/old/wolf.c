
//     Created by Grayhawk@Shadowgate
inherit "/std/monster.c";

void create() {
  :: create();  
   set_name("wolf");
   set_id( ({ "wolf" }) );
  set_short("A wolf");
   set_level(2);
    set("long","Wolves are meat-eaters and normally hunt in packs.\n"+
                 "This rather lonesome wolf looks very hungry...");
   set_gender("male");
   set("race", "dog");
   set_body_type("dog");
   set_alignment(7);
   set_size(2);
    set_hd(2,1);
   set_stats("intelligence",5);
   set_stats("wisdom",4);
   set_stats("strength",5);
   set_stats("charisma",3);
   set_stats("dexterity",14);
   set_stats("constitution",7);
   set_max_mp(3);
  set("aggressive",17);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());


}

