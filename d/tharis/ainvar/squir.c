inherit "/std/monster";

void create() {
        ::create();
        set_name("squirrel");
        set_id(({"squirrel", "a squirrel"}));
        set("short", "a squirrel");
        set("long", 
@BAMF
        A small squirrel jumps from tree to tree gathering nuts.
BAMF
        );
        set("race", "squirrel");
        set_gender("male");
        set_body_type("quadruped");
        set("level", 5);
        set_hd(5, 1);
        set_stats("strength", 13);
        set_stats("constitution", 10);
        set_stats("dexterity", 17);
        set_stats("intelligence", 7);
        set_stats("wisdom", 7);
        set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_overall_ac(7);
	set_size(1);
	set("aggressive", 7);
//      set_wielding_limbs (({"right hand", "left hand"}));
//	new("/realms/bamf/brigweap")->move(this_object());
//	new("/realms/bamf/brigarm")->move(this_object());
//	command("wield dagger in right hand");
//	command("wear armor");
}
