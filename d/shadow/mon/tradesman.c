inherit "/std/monster";
create(){
::create();
set_name("tradesman");
set_id( ({"Tradesman", "tradesman", "man"}) );
set("short", "a Tradesman");
set("long", "He is a man looking to trade his goods.");
set("race", "human");
set_gender("male");
set_body_type("human");
set_max_hp(5);
set_hp(4);
set_overall_ac(10);
set_size(2);
set_stats("strength",10);
set_stats("intelligence",13);
set_stats("dexterity",7);
set_stats("charisma",10);
set_stats("constitution",8);
set_stats("wisdom",10);
set_money("gold",random(100));
set_max_sp(8);
set_sp(8);
set_exp(15);
set("aggressive",5);
}
