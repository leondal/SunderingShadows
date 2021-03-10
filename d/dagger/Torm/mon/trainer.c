// trainer in studying to load in Torm.  Circe 5/23/04
#include <std.h>

inherit NPC;

void create(){
   ::create();
      set_nwp("studying", 16);
   	set_name("Maleena");
	set_id(({"maleena","Maleena","trainer"}));
	set_short("Maleena, a wandering entertainer");
	set_long("%^RESET%^%^CYAN%^Maleena is an exotic looking half-elf "+
         "with %^BOLD%^%^WHITE%^shimmering white hair %^RESET%^%^CYAN%^"+
         "that reaches well past her waist.  Her %^BOLD%^%^BLUE%^"+
         "pie%^WHITE%^r%^BLUE%^cing sap%^CYAN%^p%^BLUE%^hire eyes "+
         "%^RESET%^%^CYAN%^are filled with warmth and curiosity "+
         "tempered by an obvious intelligence.  Slung across her "+
         "back is a bulging %^ORANGE%^leather pack %^CYAN%^filled "+
         "with several books.  She carries a slender %^WHITE%^pine "+
         "walking staff %^CYAN%^with a forked top, into which she "+
         "places a book to study as she goes.  She is dressed "+
         "simply in a long, %^YELLOW%^pale yellow %^RESET%^%^CYAN%^"+
         "gown belted in %^BOLD%^%^WHITE%^platinum%^RESET%^%^CYAN%^, "+
         "and her tiny feet are bare.");
	set_gender("female");
	set_race("half-elf");
   set_body_type("human");
   set_hd(20,15);
   set_max_level(20);
   set_size(2);
   set_alignment(5);
   set_overall_ac(0);
   set_max_hp(random(50)+160);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(20);
   set_class("bard");
   set_mlevel("bard",20);
   set_guild_level("bard",20);
   set_stats("intelligence", 18);
   set_stats("wisdom", 15);
   set_stats("strength", 18);
   set_stats("charisma", 18);
   set_stats("dexterity", 16);
   set_stats("constitution", 15);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_property("alignment adjustment",-5);
   add_money("electrum",random(100));
   set_moving(1);
   set_speed(10);
   set_nogo(({"/d/dagger/Torm/road/path12"}));
   set_spell_chance(90);
   set_spells(({"hold person","powerword stun","hold person","lightning bolt", "magic missile", "meteor swarm"}));
}
