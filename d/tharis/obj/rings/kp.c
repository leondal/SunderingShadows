//updated by Circe 9/18/04
inherit "/std/armour";

void create() {
  ::create();
  set_name("ring");
  set_id(({"ring","platinum band","band","king's platinum band"}));
  set_short("%^BOLD%^%^WHITE%^king's pla%^CYAN%^t%^WHITE%^inum band%^RESET%^");
//  set("long", "This is a king's platinum band.\n");
  set_long("%^BOLD%^This wide band is made of thick, well-formed "+
    "pla%^CYAN%^t%^WHITE%^inum that is smooth and cool to the touch.  "+
    "Though the design is simple, the cost of making such a ring makes "+
    "it quite prestigious indeed, and as such, it is often called "+
    "a 'king's band'.%^RESET%^");
  set_type("ring");
  set_limbs(({"left hand"}));
  set_weight(1);
  set_value(2000);
}
