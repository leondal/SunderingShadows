inherit "/std/vendor";
	create(){
	::create();
set_name("orc");
set_id(({"Orc"}));
set("short","An old Orc");
set("long","He looks as though age has gotten the better of him.");
set("race","orc");
set_gender("male");
set_body_type("human");
set_hd(1,0);
set_overall_ac(6);
set_size(2);
set_alignment(9);
set_stats("strength",17);
set_stats("intelligence",8);
set_stats("dexterity",5);
set_stats("charisma",2);
set_stats("constitution",10);
set_stats("wisdom",5);
set_money("gold",60 + random(10));
set_class("fighter");
set_max_hp(50);
set_hp(50);
set_max_sp(10);
set_sp(10);
set_exp(500);
set_level(12);
set("aggressive",1);
set_wielding_limbs(({"right hand","left hand"}));
new("/d/deku/weapons/short1.c")->move(this_object());
command("wield sword in left hand");
  set_storage_room("/d/antioch/village/vil_storage.c");
  set_items_allowed("all");
  remove_std_db();
}

int __Sell(string str){
  int num;
  int val;
  object ob;
  int x;

  num = random(10);
  if(num>5){
    if(ob = present(str, this_player())){
      val = (int) ob->query_value();
      ob->set_value(random(val)+1);
      x = ::__Sell(str);
      ob->set_value(val);
      return x;
  }
  }
  return ::__Sell(str);
}
