
inherit "/std/monster";

create() {
    ::create();
	set_name("gnome");
	set_id( ({ "gnome","gerack" }) );
	set("race", "gnome");
	set_gender("male");
        set("short", "Gerack, the gnome guardian.");
           set("long"," Gnomes are similar to their larger cousins, dwarves.  This "
                     "creature's hair is medium white with grayish blue eyes.");
	set_level(5);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
  	set_size(1);
        set_hd(5,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
        set_exp(200);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/weapons/longsword1")->move(this_object());
      	command("wield longsword in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
   set_emotes(20, ({"%^MAGENTA%^Gerack says%^RESET%^: It's a fine day today.",
      "%^MAGENTA%^Gerack says%^RESET%^: Are you brave enough to enter the Kobold Caverns?",
      "%^MAGENTA%^Gerack says%^RESET%^: If you're level 5 or under, you may enter.",
      "%^MAGENTA%^Gerack says%^RESET%^: Only the bravest ever come out alive.",
      "%^MAGENTA%^Gerack says%^RESET%^: If you are over 5th level, BEGONE!"}), 0);
   
}
