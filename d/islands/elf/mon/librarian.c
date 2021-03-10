#include <std.h>
inherit NPC;

void create(){
   ::create();
   set_name("Gwesadorion");
   set_short("Gwesadorion, Librarian of Ashata'Rathai");
   set_id(({"gwesadorion","librarian","Gwensadorion"}));
   set_long("This young looking elf is actually middle-aged."+
   "  Like his fellow elves he doesn't show his age and "+
   "continues to look young.  Some things are obvious "+
   "like slight lines by his eyes and the way he "+
   "carries himself.  But to the untrained eye he "+
   "looks as young as most of the elves.  He is "+
   "in fact a gold elf.  He has blonde hair and "+
   "golden eyes with a slight bronze skin tone. "+
   " He dresses brightly like a normal gold elf "+
   "would in shades of white and gold.  However his "+
   "clothing is simple to allow him to get books needed"+
   " for those that wish to use the library. \n\n  He can"+
   " help you <research> someone, or you can see"+
   " <help library> for important commands to use.");
   set_race("elf");
   set_gender("male");
   set_class("mage");
   set_level(25);
   set_alignment(1);
   set_emotes(10,({
   "Gwesadorion tends to the books.",
   "Gwesadorion walks around keeping an eye on the library.",
   "Gwesadorion dusts some shelves.",
   "Gwesadorion talks seriously with some of the other elves in the area.",
   "Gwesadorion accepts a book from an passerby.",
   "Gwesadorion makes a note in his log as an elf checks out a book.",
   }),0);
   set_new_exp(30,"very low");
   set_max_level(35);
   set_base_damage_type("bludgeoning");
}