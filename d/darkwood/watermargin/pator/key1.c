//  A nice iron key is defined here
// Pator@ShadowGate
// 04/07/95

inherit "/std/Object";

create() {
      ::create();
      set_name("iron key");
      set_id(({"key","iron key","Krugan's key"}));
      set_short("Iron key");
      set_long("A iron key,probably for a good and solid lock.When you try hard you notice that the name krugan is carved into it.Maybe he wants it back ??!");
      set_weight(12);
      set_value(random(5));
         }
