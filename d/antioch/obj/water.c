// placed in /d/antioch/village/temple2.c (on healer.c) for quest

inherit "/std/Object";
void create() {
     ::create();
set_name("the element of water");
set_id(({"a water element", "water element", "element"}));
set_short("A water element");
set_long(
"\n"
"It seems to create water.\n");
set_weight(5);
}
