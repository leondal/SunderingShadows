
inherit "/std/monster";

create() {
    ::create();
	set_name("dwarf");
	set_id( ({ "dwarf","worker" }) );
	set("race", "dwarf");
	set_gender("male");
        set("short","Dwarven worker");
       set("long","This is a mountain dwarf worker.  He works the mines, \n"+
                  "creating new tunnels for the dwarven kingdom.");
	set_level(6);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
  	set_size(1);
        set_hd(6,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17);
   	set_stats("charisma",3);
        set_stats("dexterity", 15);
        set_exp(100);
       set_hp(50);
   	set_stats("constitution",17);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/pick")->move(this_object());
        command("wield pick");
	add_money("silver",random(10));
	add_money("copper",random(20));
   
}
