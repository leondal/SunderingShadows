inherit "/std/vendor.c";

void create() {
    ::create();
   set_name("perfume dealer");
   set_id( ({ "perfume dealer","vendor" }) );
set_short("A perfume dealer");
   set_level(19);
   set("long", "He sells perfume.\n"
	"He is pushing a cart full of various scents of perfume.\n");
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_class("mage");
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_storage_room("/d/tharis/Tharis/carts/perfume_storage.c");
}
