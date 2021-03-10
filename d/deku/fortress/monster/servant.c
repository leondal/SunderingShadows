
inherit "/std/monster";

create() {
    ::create();
	set_name("servant");
	set_id( ({ "human","servant" }) );
	set("race", "human");
	set_gender("female");
        set("short","Human servant");
         set("long","This a human servant who is a slave within the Shadowlord\n"+
                     "fortress.  You notice that this servant has no eyes\n"+
                      "within her sockets.  You can see into her worthless soul.");
	set_level(2);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
  	set_size(2);
        set_hd(2,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",10);
   	set_stats("charisma",9);
        set_stats("dexterity", 12);
        set_exp(5900);
       set_hp(14);
   	set_stats("constitution",11);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/knife")->move(this_object());
        command("wield knife");
	add_money("silver",random(10));
   
}
