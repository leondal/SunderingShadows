#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("handbill");
      set_id(({ "handbill", "embossed handbill","paper"}));
      set_short("%^CYAN%^An embossed paper handbill%^RESET%^");
      set_long("%^CYAN%^This long and narrow folded "+
		"handbill features an intricate image on it's cover."+
		"  A %^MAGENTA%^purple%^CYAN%^ silhouette of a female"+
		" rests against a diamond field of%^BLUE%^ marbled "+
		"dark blue%^CYAN%^.  A round halo crowns the female's"+
		" head, gilded with %^BOLD%^%^WHITE%^silver%^RESET%^"+
		"%^CYAN%^ leaf.  In a thick but elegantly flowing "+
		"script it reads %^MAGENTA%^Hivetta's Harmony%^CYAN%^."+
		"  The inside of the handbill lists the performers next"+
		" to their character's names.");
      set_read("\n\n\t%^BOLD%^%^BLUE%^Written/Produced/Directed"+
		" by %^RESET%^%^CYAN%^Ixi Desterl\n"+
		"\t%^BOLD%^%^RED%^A Desert Sun Theater Production"+
		"%^RESET%^\n"+
		"%^MAGENTA%^\t\t\tHivetta's Harmony%^RESET%^\n"+
		"\t%^BOLD%^%^CYAN%^Zahara Rezbet %^WHITE%^=~=~=~=~="+
		" %^BLUE%^Hivetta\n"+
		"%^RESET%^%^BLUE%^\tDaleric Pelgand%^WHITE%^ =~=~=~=~="+
		"%^GREEN%^ Lord Daeranth Ompelic%^RESET%^\n"+
		"\t%^BOLD%^%^CYAN%^Magdelana Mere%^WHITE%^ =~=~=~=~="+
		" %^MAGENTA%^Nightcloak Usuki%^RESET%^\n"+
		"%^RESET%^\t%^BLUE%^Orden Jar'Zellem %^WHITE%^=~=~=~=~="+
		" %^GREEN%^Sir Roderick Lamon\n"+
		"%^RESET%^\t%^BOLD%^%^CYAN%^Persethapina Yataz%^WHITE%^ "+
		"=~=~=~=~= %^MAGENTA%^Ramzalina%^RESET%^\n"+
		"\t%^BLUE%^Theordan Kelthems %^WHITE%^=~=~=~=~= "+
		"%^GREEN%^Yathar%^RESET%^\n"+
		"\t%^BOLD%^%^CYAN%^Grisham Malarik%^WHITE%^ =~=~=~=~="+
		" %^BLUE%^ Laeol Pold%^RESET%^\n\n");
      set_language("common");
      set_weight(1);
      set_value(30);
}
