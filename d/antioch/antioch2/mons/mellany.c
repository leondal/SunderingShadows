#include <std.h>
#include "../antioch.h"
inherit NPC;

void create()
{
   ::create();
   set_name("Mellany");
   set_short("Mellany, a stable hand");
   set_id(({"Mellany","mellany","stable hand"}));
   set_long(
   "Mellany is a pretty young lady, so it is rather odd to see her dressed in"+
   " leather pants and boots for riding. Her shirt is worn and dirty and she"+
   " smells unmistakably of horses. Her sandy blonde hair has been braided back,"+
   " although several tendrils have fallen out here and there. She is obviously a"+
   " bit of a tomboy, but undoubtedly has a deep love for horses if this is the"+
   " path she has chosen for herself. Twinkling green eyes peer at you from"+
   " beneath her long lashes in curiosity, but she simply goes back to work fixing"+
   " and polishing the horses gear."
   );
   set_gender("female");
   set_race("human");
   set_body_type("human");
   set_hd(5,3);
   set_overall_ac(6);
   set_alignment(4);
   set_stats("intelligence",17);
   set_stats("wisdom",18);
   set_stats("dexterity",18);
   set_stats("charisma",13);
   set_stats("strength",8);
   set_stats("constitution",8);
   set_exp(1);
   set("aggressive",0);
   add_money("silver",random(50));
   set_nwp("healing mount",10,500);
   set_emotes(3,({
   "Mellany briskly polishes a piece of leather.",
   "Mellany adds a few suger cubes to her pockets.",
   "Mellany hums a soft tune as she oils down a saddle.",
   "Mellany glances at you briefly and smiles before returning to her work.",
   "%^RESET%^%^MAGENTA%^Mellany says%^RESET%^: Taking good care of the horses gear is almost as important as taking care of the horses themselves.",
   "%^RESET%^%^MAGENTA%^Mellany says%^RESET%^: I have worked with horses my entire life, I can't imagine doing anything else!",
   "%^RESET%^%^MAGENTA%^Mellany says%^RESET%^: Horses are the sweetest animals, and their very sensitive to their riders needs and moods.",
   "%^RESET%^%^MAGENTA%^Mellany says%^RESET%^: I take care of all the horses here, it's important to treat injuries right away.",
   }),0);
}
