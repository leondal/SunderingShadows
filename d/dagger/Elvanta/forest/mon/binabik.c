inherit "/std/vendor";

int at_shop();

void create() {
   ::create();
set_name("Binabik");
set_id( ({ "binabik", "clerk", "shopkeeper", "shop keeper"}) );
set_short("Binabik, the clerk of Elvanta's Armory");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells armor's.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("armor");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
set_storage_room("/d/dagger/Elvanta/forest/roomar_storage");
}
