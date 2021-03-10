inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "scourge", "whip", "scourge whip" }));
   set_name("scourge");
   set_short("A scourge whip");
   set_long(
	"This is a wicked whip with metal barbs on the ends of the thongs. "
   );
   set_weight(2);
   set_size(1);
   set_prof_type("whip");
   set("value", 1);
   set_wc(1,4);
   set_large_wc(1,2);
   set_type("lash");
   set_weapon_speed(5);
}
