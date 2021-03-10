// Rubicant's shop key

inherit  "/std/armour";

void create() {
  ::create();
  set_name("darksteel key");
  set_id(({"key", "darksteel key", "shop key" }));
  set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^darksteel%^BOLD%^%^BLACK%^ "
	"key on a chain%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This key is longer than usual and has 16 "
	"indentations for tumblers, 8 on each side of the key. It has been "
	"formed from %^RESET%^%^MAGENTA%^darksteel%^BOLD%^%^BLACK%^ and the "
	"grip has an intricate %^RESET%^%^RED%^angel%^BOLD%^%^BLACK%^ "
	"carved into either side of it.%^RESET%^");
  set_weight(1);
  set_property("no animate", 1);
  set_weight(2);
  set_value(10);
  set_type("ring");
  set_limbs( ({"neck"}) );
}

/**************
%^RESET%^BOLD%^%^BLACK%^A black iron key%^RESET%^
%^RESET%^%^BOLD%^%^BLACK%^This key is longer than usual and has 16 indentations for tumblers, 8 on each side of the key. It has been formed from black iron and the grip has an intricate %^RESET%^%^RED%^angel%^BOLD%^%^BLACK%^ carved into either side of it.%^RESET%^

%^RESET%^%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^darksteel%^BOLD%^%^BLACK%^ key%^RESET%^

%^RESET%^%^BOLD%^%^BLACK%^This key is longer than usual and has 16 indentations for tumblers, 8 on each side of the key. It has been formed from %^RESET%^%^MAGENTA%^darksteel%^BOLD%^%^BLACK%^ and the grip has an intricate %^RESET%^%^BLUE%^raven%^BOLD%^%^BLACK%^ carved into either side of it.%^RESET%^
*****************/