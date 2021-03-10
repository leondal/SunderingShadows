// placed in /d/antioch/village/hole1.c (on ulord.c) for quest

inherit "/std/Object";
void create() {
  ::create();
  set_name("an undead element");
  set_id(({"an undead element","element","undead element"}));
  set_short("An undead element");
set_long(
"\n"
"This element glows %^BOLD%^%^BLACK%^black%^RESET%^, it also seems to be falling apart.\n");
set_weight(5);
}
