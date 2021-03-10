#include <std.h>
inherit NPC;

void create(){
   ::create();
   set_name("clover");
   set_short("Clover the hedgehog");
   set_id(({"clover","Clover","hedgehog"}));
   set_long("%^RESET%^%^ORANGE%^This disgruntled little hedgehog is rarely seen without her companion, Verity Gallo. Covered in dark brown spines tipped with %^RESET%^white%^ORANGE%^, Clover has a small pig-like snout and tiny %^BOLD%^%^BLACK%^black eyes%^RESET%^%^ORANGE%^. She tends to follow Verity around, studiously not begging for treats and occasionally making her annoyance known.%^RESET%^");
   set_race("hedgehog");
   set_body_type("quadruped");
   set_size(1);
   set_class("fighter");
   set_mlevel("fighter",5);
   set_guild_level("fighter",5);
   set_hd(5,4);
   set_max_hp(query_hp());
   set_exp(12);
   remove_std_db();
   set_need_addressed(0);
   set_emotes(1,({
      "The chittering hedgehog runs darts along the ground with a burst of speed.",
      "The hedgehog curls up into a ball and gives a tiny yawn.",
      "The hedgehog blinks its eyes and peers up at the sky.",
      "The hedgehog catches a crawling insect and munches on it contentedly."
   }),0);}