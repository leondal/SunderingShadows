//  A nice blackened key is defined here
// Pator@ShadowGate
// 04/07/95

inherit "/std/Object";

create() {
      ::create();
      set_name("blackened key");
      set_id(({"key","blackened key",}));
      set_short("blackened key");
      set_long("A iron key, blackened by coal. You wonder where it could fit ??!");
      set_weight(12);
      set_value(random(5));
         }
