inherit "/std/quest_ob";

void create() {
  set_name("chaucer");
  set("id", ({"chaucer", "quest_object"}) );
  set("short", "%^YELLOW%^The Canterbury Tales%^RESET%^");
  set("long", "Something seems to be amiss inside Chaucer's "
      "most famous work. Aid the distraught pilgrims on their way to "
      "Canterbury.\nRating: Easy");
  set_quest_points(15);
}
