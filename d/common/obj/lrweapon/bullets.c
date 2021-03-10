//desc updated by Circe 12/11/04 after adding ability to take arrows
#include <std.h>

inherit "/std/ammo";

void create(){
   ::create();
   set_id(({ "bullets","bullet pouch","pouch of bullets" }));
   set_name("bullet");
   set_short("pouch of bullets");
   set_long("These are small, rounded rocks gathered as ammunition "+
      "for what is commonly known as a sling.  It looks as though "+
      "you could <count bullets> to see how many you have.  You can "+
      "also <take # from bullets> to separate some or <combine bullets "+
      "with bullets> to empty another pouch into this one if you had "+
      "two.");
   set_shots(50);
   set_value(1);
   set_wc(1,4);
   set_large_wc(1,4);
   set_ammo_type("bullet");
   set_property("repairtype",({"woodwork", "weaponsmith"}));
}
