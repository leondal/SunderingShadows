
inherit "/std/monster";

create() {
    ::create();
set_name("Sloridge gnome", "gnome");
set_id(({"Sloridge gnome", "gnome"}));
	set("race", "gnome");
	set_gender("male");
set_short("a Sloridge gnome");
set_long("%^Grimy faces, fur wrinkled and worn, fingers curled and straighten as they gesture, and bits of dirt crumbles and falls from beneath caked nails.  Shabby clothes hang on them, leather and sackcloth, colourless except for some bright feathers stuck in the headbands of their caps.  They appear to be bits of wreckage that has somehow washed upon the shores of life and found its way to the forest.");
	set_property("wimpy", 50);
	set_level(10);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
  	set_size(1);
	set_hd(10,1);
	set_property("swarm", 1);
	set("wimpy", 75);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
        set_exp(100);
	set_hp(75);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/weapons/short1")->move(this_object());
      	command("wield sword in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
   
}
