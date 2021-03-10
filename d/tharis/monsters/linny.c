inherit "/std/vendor";

void create() {
   ::create();
   set_name("Linny");
   set_id( ({ "Linny", "linny", "dwarf", "armorer"}) );
   set_short("Linny, dwarven armorer of Tharis");
   set("aggressive", 0);
   set_level(19);
   set_long(
@OLI
   Linny is a short, broad-shouldered dwarf. His long graying beard 
is kept tucked into his thick worn leather belt. His short legs bulge 
strongly through seemingly tight leather trousers. His green loose-fitting
tunic is tied back and covered with a heavy leather apron. With his 
massive smith's hammer he directs others in his shop. When not talking
in his typical animated style with customers, or gossiping with workers,
Linny can make some of the most ornate armor around.
OLI
   );
   set_gender("male");
   set_alignment(3);
   set_race("dwarf");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("d/tharis/Tharis/storage/armor_storage.c");
   set_items_allowed("armor");
   remove_std_db();
}
