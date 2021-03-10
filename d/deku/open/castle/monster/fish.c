// A nice little fish
// Pator@ShadowGate
// 04/12/95

inherit "/std/monster";

create() {
      ::create();
      set_name("fish");
      set_id(({"fish"}));
      set_short("A nice, coloured fish");
      set_long(
@FISH
This is a little nicely coloured fish. It is swimming in the moat of Marleen's castle and it is very happy here.
FISH
);
      set("race","fish");
      set_gender("male");
      set_body_type("snake");
      set_alignment(3);
      set_level(2);
      set_hd(1,0);
      set("aggressive",0);
      set_size(1);
      set_stats("intelligence",2);
      set_stats("wisdom",2);
      set_stats("strength",4);
      set_stats("dexterity",6);
      set_stats("constitution",2);
      set_hp(6);
      set_max_hp(query_hp());
      set_max_sp(query_hp());
      set_sp(query_max_sp());
      set_max_mp(0);
      set_mp(query_max_mp());
      add_money("copper",random(15));
}
