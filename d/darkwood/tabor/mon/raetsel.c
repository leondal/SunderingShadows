//raetsel - Thief for Tabor.  Circe 6/4/04
#include <std.h>
inherit "/std/fence";

void create() {
   ::create();
   set_name("raetsel");
   set_id( ({ "raetsel","Raetsel","shop keeper"}) );
   set_short("Raetsel, a simple rogue");
   set_long("Raetsel is a short, lithe man with long arms.  His "+
      "fingers are thin and dextrous, and at one time it was said "+
      "he could lift anything in the realms.  He now wears a "+
      "patch over his right eye, and he can often be overheard "+
      "telling the story of exactly how that happened.  Since he "+
      "lost his eye, he has taken to a quieter life here, helping "+
      "those who still steal for a living.  His long black hair "+
      "is kept carefully gathered in a topknot, and he still takes "+
      "extra care in his appearance.  He wears a thin black tunic "+
      "with long sleeves that fits snugly against his frame, and his "+
      "legs are clad in skin tight leather leggings that seem formed "+
      "of the shadows themselves.  His soft cloth boots seem to mask "+
      "the sound of any movement he makes, and the deep gray color of "+
      "them matches his stormy gray eyes.");
   set_gender("male");
   set_alignment(5);
   set_level(19);
   set_class("thief");
   set_race("human");
   set_diety("mask");
   add_money("gold", random(500));
   set_property("no bump", 1);
   set_hd(19,3);
   set_exp(10);
}

int should_interact(object ob) { return 1;}
