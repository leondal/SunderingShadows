inherit "/std/monster";

void create() {
        ::create();
        set_name("bear");
        set_id(({"bear", "black bear"}));
        set("short", "a black bear");
        set("long", 
@BAMF
        A giant black bear which makes its home here in the forest.
BAMF
        );
        set("race", "bear");
        set_gender("male");
        set_body_type("quadruped");
        set("alignment", 6);
	set("level", 7);
        set_hd(7, 1);
        set_stats("strength", 17);
        set_stats("constitution", 14);
        set_stats("dexterity", 10);
        set_stats("intelligence", 7);
        set_stats("wisdom", 7);
        set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_overall_ac(9);
	set_size(3);
	set("aggressive", 20);
//      set_wielding_limbs (({"right hand", "left hand"}));
//	new("/realms/bamf/brigweap")->move(this_object());
//	new("/realms/bamf/brigarm")->move(this_object());
//	command("wield dagger in right hand");
//	command("wear armor");
}
