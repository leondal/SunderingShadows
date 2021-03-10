inherit "/std/monster";

void create() {
  ::create();
  set_name("Smilodon");
  set_id(({"smilodon","cat","great cat","Smilodon"}));
  set("race","smilodon");
  set_gender("female");
  set("short","Smilodon, a great cat");
  set("long","This is Vexia's pet smilodon, a giant cat with six inch, razor "
    "sharp fangs.  The outline of her ribcage shows through her coarse, "
    "lusterless, rusty-orange and black striped coat.   She is used to being "
    "fed by the ogres who toss meat to her from the doorway.  But it seems "
    "that they haven't done so in awhile, for you see hunger within her golden "
    "eyes.  From the number of bones scattered around, it looks like she may "
    "bring her catches here in addition to the scraps the ogres toss her.");
  set_level(7);
  set_body_type("quadruped");
  set_class("fighter");
  set("aggressive", 18);
  set_size(2);
  set_alignment(8);
  set_hd(7,2);
  set_overall_ac(2);
  set_stats("strength",19);
  set_stats("dexterity",17);
  set_hp(55);
  set_exp(300);
}
