//updated by Circe 9/18/04
inherit "/std/armour";

void create() {
  ::create();
  set_name("ring");
  set_id(({"ring","heavily jeweled ring","jeweled ring"}));
  set_short("%^YELLOW%^heavily %^RED%^j%^WHITE%^e%^CYAN%^w"+
     "%^WHITE%^e%^BLUE%^l%^WHITE%^e%^GREEN%^d %^YELLOW%^ring%^RESET%^");
//  set("long", "This ring is heavily jeweled.\n");
  set_long("%^YELLOW%^A wide gold band forms the base of this "+
     "ring.  The top of the ring features a wide platform decorated "+
     "with scrollwork and flourishes designed to look like %^GREEN%^"+
     "vines%^YELLOW%^.  Each '%^GREEN%^leaf%^YELLOW%^' is in fact a "+
     "small %^RED%^j%^WHITE%^e%^CYAN%^w%^WHITE%^e%^GREEN%^l%^YELLOW%^!  "+
     "The glittering gems and detailed scrollwork come together to "+
     "create a dazzling ring.%^RESET%^");
  set_type("ring");
  set_limbs(({"right hand"}));
  set_weight(1);
  set_value(350);
}
