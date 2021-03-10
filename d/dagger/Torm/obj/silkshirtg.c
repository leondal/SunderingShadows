#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("silk shirt");
  set_id(({"silk shirt","shirt",
  "green silk shirt",
  }));
  set_short(
  "%^BOLD%^%^GREEN%^Green silk shirt%^RESET%^"
  );
    set_long(
  "%^BOLD%^%^GREEN%^"
  "  The silk in the shirt makes it a joy to feel against the skin."
    "  It's obviously of the highest quality and of next to no weight at all, although you really doubt it would offer much protection from the elements or attack."
    "  It's slightly open at the neck and the sleeves are puffed out to the wrists where they are clasped back in tightly to leave the hands free from entanglements."
    );
  set_weight(2);
  set_value(100);
    set_type("clothing");
     set_limbs(({"torso"}));
}
