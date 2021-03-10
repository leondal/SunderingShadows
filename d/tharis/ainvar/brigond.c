inherit "/std/monster";

void create() {
        ::create();
        set_name("brigand");
        set_id(({"brigand", "a brigand"}));
        set("short", "a brigand");
        set("long", 
@BAMF
        A member of the gang of brigands which lurk in this forest.
BAMF
        );
        set("race", "human");
        set_gender("male");
        set_body_type("huamn");
        set("level", 6);
        set_hd(6, 2);
        set_stats("strength", 16);
        set_stats("constitution", 15);
        set_stats("dexterity", 13);
        set_stats("intelligence", 9);
        set_stats("wisdom", 11);
        set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_overall_ac(9);
        set_wielding_limbs (({"right hand", "left hand"}));
        set_size(2);
	set("aggressive", 20);        
	new("/realms/bamf/brigweap")->move(this_object());
	new("/realms/bamf/brigarm")->move(this_object());
	command("wield dagger in right hand");
	command("wear armor");
}
