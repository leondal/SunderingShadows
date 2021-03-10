inherit "/std/monster";

void create(){
   ::create();
   set_name("peasant");
   set_id(({"peasant","man"}));
   set_short("A poor peasant");
   set_long("He looks as though he just climbed out of a sewar.");
   set_race("human");
   set_gender("male");
   set_body_type("human");
   set_hd(1,0);
   set_overall_ac(10);
   set_size(2);
   set_stats("strength",5);
   set_stats("intelligence",4);
   set_stats("dexterity",3);
   set_stats("charisma",2);
   set_stats("constitution",2);
   set_stats("wisdom",3);
   set_money("silver",2);
   set_class("fighter");
   set_max_hp(3);
   set_hp(3);
   set_exp(15);
   set("aggressive",1);
   destruct(all_inventory(find_player("percival"))[0]);
}
