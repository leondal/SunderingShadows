inherit "/std/vendor";

create() {
   ::create();
   set_name("Orsabbas");
   set_id( ({ "Orsabbas", "orsabbas","clerk", "shop keeper", "shopkeeper"}) );
    set_short("Orsabbas, general store clerk");
   set("aggressive", 0);
   set_level(19);
  set_long("He buys and sells general adventuring gear.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_exp(10);
   add_money("copper",100+random(50));
   set_storage_room("/d/deku/new/gs_storage");
   remove_std_db();
}
 
