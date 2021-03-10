inherit "/d/common/obj/armour/mshield.c";
void create() {
    ::create();
	set_name("medium shield");
	set("id", ({ "shield","tsarvani shield","medium shield","medium" }) );
	set("short", "A Tsarvani medium shield");
    	set_long(
@TSARVEN
This shield is made of leather, hardened and shaped into an oval
with the emblem of the Empire of Tsarven burned into it.  It looks
to be of good, if plain, workmanship.
TSARVEN
        );
}
