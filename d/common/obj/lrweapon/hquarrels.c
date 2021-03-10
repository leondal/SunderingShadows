//desc updated by Circe 12/11/04 after adding ability to take arrows
#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
   set_id(({ "heavy quarrels","heavy quarrel","quarrels", "bolts", "quiver" }));
   set_name("arrows");
   set_short("A bundle of heavy crossbow bolts");
   set_long(
      "This is a bundle of approximately two foot long quarrels.  "+
      "They are obviously for the heavy crossbow.  When these bolts "+
      "are fired, they can pierce armor and do a lot of damage.  "+
      "It looks like you could <count bolts> to see how many you "+
      "have.  You can also <take # from bolts> to separate them, "+
      "or <combine bolts with bolts> if you have two."
   );
   set_shots(20);
   set_wc(1,10);
   set_large_wc(1,10);
   set_ammo_type("heavy quarrel");
   set_property("repairtype",({"woodwork", "weaponsmith"}));
}
int is_arrows(){return 1;}
