//  A nice little baby crocodille
// Pator@ShadowGate
// 04/12/95

inherit "/std/monster";

create() {
      ::create();
      set_name("crocodile");
      set_id(({"crocodile","green crocodile","baby crocodile"}));
      set_short("A baby crocodile");
      set_long("A baby crocodile swimming all alone in the moat here.\n"+
               "You look around to see if its parents are around.  Your\n"+
               "knowledge of biology tells you that it is a tough creature\n"+
               "to kill.  Low level could have difficulties trying to kill\n"+
               "this crocodile!");
      set("race","reptile");
      set_gender("male");
      set_body_type("quadruped");
      set_alignment(3);
      set_level(4);
      set_hd(4,0);
      set("aggressive",4);
      set_size(1);
      set_stats("intelligence",2);
      set_stats("wisdom",2);
      set_stats("strength",10);
      set_stats("dexterity",6);
      set_stats("constitution",12);
      set_max_hp(query_hp());
      set_max_sp(query_hp());
      set_sp(query_max_sp());
      set_max_mp(0);
      set_mp(query_max_mp());
      add_money("silver",random(5));
}
