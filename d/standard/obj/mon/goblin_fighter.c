inherit "/std/monster";

create() {
    ::create();
   set_name("goblin");
    set("id", ({ "goblin", "soldier" }));
    set("short", "a goblin soldier");
   set("aggressive", 17);
  set_level(5);
    set("long", "A warrior of the Daroq goblins.");
    set_class("fighter");
    set_body_type("human");
   set_alignment(-200);
   set("race", "goblin");
   set_hp(300);
    set_mp(200);
}
