inherit "/std/monster";

void create() {
        ::create();
        set_name("wolf");
        set_id(({"wolf", "rabid wolf"}));
        set("short", "a rabid wolf");
        set("long", 
@BAMF
        The hungry eyes of this beast move up and down your body, sizing 
you up as tonights meal. 
BAMF
        );
        set("race", "wolf");
        set_gender("female");
        set_body_type("quadruped");
        set("level", 7);
        set_hd(7, 3);
        set_stats("strength", 17);
        set_stats("constitution", 16);
        set_stats("dexterity", 18);
        set_stats("intelligence", 12);
        set_stats("wisdom", 12);
        set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_overall_ac(9);
	set_size(2);
	set("aggressive", 15);
//      set_wielding_limbs (({"right hand", "left hand"}));
//	new("/realms/bamf/brigweap")->move(this_object());
//	new("/realms/bamf/brigarm")->move(this_object());
//	command("wield dagger in right hand");
//	command("wear armor");
}
