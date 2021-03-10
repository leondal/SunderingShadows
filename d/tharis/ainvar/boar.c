inherit "/std/monster";

void create() {
        ::create();
        set_name("boar");
        set_id(({"boar", "wild boar"}));
        set("short", "a wild boar");
        set("long", 
@BAMF
        A large mass of hooves and tusks rushes forward towards you from 
the underbrush. 
BAMF
        );
        set("race", "boar");
        set_gender("female");
        set_body_type("quadruped");
        set("level", 8);
        set_hd(8, 3);
        set_stats("strength", 18);
        set_stats("constitution", 17);
        set_stats("dexterity", 17);
        set_stats("intelligence", 7);
        set_stats("wisdom", 7);
        set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_overall_ac(9);
	set_size(2);
	set("aggressive", 20);
//      set_wielding_limbs (({"right hand", "left hand"}));
//	new("/realms/bamf/brigweap")->move(this_object());
//	new("/realms/bamf/brigarm")->move(this_object());
//	command("wield dagger in right hand");
//	command("wear armor");
}
