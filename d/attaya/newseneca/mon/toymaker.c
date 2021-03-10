//toymaker.c - by ~Circe~ for new Seneca 11/25/07
//Description by Lurue
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create() {
   ::create();
   set_name("Dolly");
   set_id(({"Toymaker","toymaker","shopkeeper","dolly","Dolly"}));
   set_short("Dolly, the shopkeeper of Seneca's Toy Shop");
   set_long("%^BOLD%^%^WHITE%^Dolly is a plump, happy appearing human "+
      "woman of middle age.  Her once %^RESET%^%^ORANGE%^dark brown hair "+
      "%^BOLD%^%^WHITE%^is dusted with %^RESET%^%^ORANGE%^s%^WHITE%^i"+
      "%^BOLD%^%^WHITE%^l%^RESET%^v%^ORANGE%^ery st%^RESET%^r%^BOLD%^"+
      "%^WHITE%^e%^RESET%^a%^ORANGE%^ks %^BOLD%^%^WHITE%^and is worn "+
      "shoulder short and curly.  Her eyes are a %^RESET%^%^CYAN%^dusty "+
      "blue %^BOLD%^%^WHITE%^and twinkle merrily as she tends to her shop, "+
      "%^CYAN%^Dolly's Treasures%^WHITE%^.  Arranging new toys or winding "+
      "up the delicate music boxes that fill the room with music.  "+
      "A %^BLUE%^blue gown %^WHITE%^covers her large frame, over which "+
      "she wears a frilly %^YELLOW%^yellow %^WHITE%^and %^GREEN%^green "+
      "%^WHITE%^apron that matches the %^GREEN%^green bowed%^WHITE%^, "+
      "%^YELLOW%^yellow slippers %^WHITE%^upon her feet.  A %^GREEN%^"+
      "green velvet bow %^WHITE%^can also be seen in her hair causing "+
      "her to have a great deal of similarity with her name sake.%^RESET%^\n\n"+
      "%^RESET%^%^CYAN%^<%^RESET%^help shop%^CYAN%^> %^RESET%^"+
      "will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_level(30);
   set_hd(30,20);
   set_hp(200+roll_dice(30,20));
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_stats("strength",19);
   set_stats("dexterity",17);
   set_overall_ac(-21); 
   set_max_hp(query_hp());
   set_storage_room(STORAGE"toy_storage.tita.c");
   force_me("speech say cheerfully");
   set_items_allowed("misc");
}