#include <std.h>
inherit BARKEEP;

void create() {
  ::create();
  set_name("Taath");
     add_dbs(({"tournament"}));
  set_id(({"barkeep","orc","black orc","taath","waitstaff"}));
  set_emotes(3,({
  "Taath mutters and grins toothily at you."
  }),0);
  set_short("Taath, black orc barkeep");
//  set_property("always interact",1); changed by Lujke, to try to make him work with eddb
  set("aggressive", 0);
  set_alignment(9);
  set_level(10);
  set_long(
  "Taath leers across the bar with his little pig eyes as he sees you come in."
  "  Yellow broken tusks jut from his lower lip and he really, really stinks."
   "  He would probably be almost six feet tall, if he bothered to stand up straight."
   "  He has black hair and dark brown eyes that have a faint reddish glow.  Most of his body is covered in course black hair and you can't help but notice the prominent pig-like nose that dominates the center of his face."
   "  One of his hands is just out of sight as if holding something in his hand he doesn't want anyone to see, even as he pours drinks with the other."
  );
  set_gender("male");
  set_race("orc");
  set_hd(10,0);
  set_exp(10);
  set_max_hp(query_hp());
  add_money("copper", random(200));
  set_body_type("human");
  set_currency("gold");
  set_menu(({
  "black orc ale",
  "dark rum",
  "bong water",
  }),({
  "alcoholic",
  "alcoholic",
  "alcoholic",
  }),
  ({
  20,14,75,
  }));
  set_my_mess(({
  "God, that smelled like it was sweated out of an orc!",
  "Urggh, not quite ready for that yet!",
  "%^BOLD%^%^GREEN%^Oooh, look at that, pretty colors..%^RESET%^",
  }));
  set_your_mess(({
  "grimaces as they down a foul smelling ale.",
  "coughs and bangs their chest as they chug a short glass of dark rum.",
  "takes a deep drink out of a strange looking glass and then vacantly gazes about.",
  }));
  set_menu_short(({
  "Black Orc Ale",
  "Dark Rum",
  "Bong Water",
  }));
  set_menu_long(({
  "A foul smelling dark ale that looks like it's sat in the sun long"+
  " enough to lose all its fizz.",
  "A short glass of dark rum.",
  "Odd, slimy looking water in a strange looking glass.  A rim of scum"+
  " has settled around the waters edge.",
  }));
}
