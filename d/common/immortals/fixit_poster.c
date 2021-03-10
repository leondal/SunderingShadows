#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long("This poster lists topics to help make it more efficient to find "
	"common errors or outdated usage in coding when creating new areas and "
	"in our quest to bring existing ones up to current and consistent "
	"standards.  The %^BOLD%^topics %^RESET%^you will find listed are "
	"each preceded by a letter for easy access.  You can review them according "
	"to that letter <%^YELLOW%^review A%^RESET%^> etc.).  Compliance is expected "
	"and the list may be updated from time to time.\n"
"%^YELLOW%^A  General %^RESET%^- ed, noting changes & backups, inherits\n"
"%^YELLOW%^B  add-actions %^RESET%^- search & read should NOT be (see set below), souls, in general\n"
"%^YELLOW%^C  set_something %^RESET%^- short, long, race, id, read & search, terrain, etc.\n"
"%^YELLOW%^D  set_property(something, what) %^RESET%^- enchantment, light, no teleport...\n"
"%^YELLOW%^E  gear %^RESET%^- wear/wield/remove/unwield, use ETO, not TP\n"
"%^YELLOW%^F  variables %^RESET%^- global versus local\n"
"%^YELLOW%^G  functions %^RESET%^- ignore invis avatar/wiz, bugs, ETO, set('aggressive', int or func) versus using init(), non-combat damage - add attacker\n"
"%^YELLOW%^H  rooms %^RESET%^- no .c on exit filenames, doors\n"
"%^YELLOW%^I  misc %^RESET%^- mobs wielding, use /d/common/obj for mundane items\n"
"%^YELLOW%^J  help info %^RESET%^- list of helpful files to review\n"
"%^YELLOW%^K  area responsibilities %^RESET%^- who covers which areas\n"
"%^YELLOW%^L  wandering mob control %^RESET%^- CROOM\n"
"%^YELLOW%^S  spells%^RESET%^- checklist for making them and start of a help file"
	);
   set_short("%^BOLD%^%^BLUE%^A poster of helpful topics%^MAGENTA%^");
   set_id(({"poster", "posters"}));
   set_name("posters");
   set_weight(10000);
   set_value(0);
}

void init(){
   	::init();
   	add_action("review_func","review");
}

int review_func(string str) {
   string file;
   str = lower_case(str);
   if(!str) {
	write("Review what?");
	return 0;
   }
   switch(str) {
   	case "a" : file = "a-general";		break;
   	case "b" : file = "b-addaction";	break;
	case "c" : file = "c-sets";		break;
	case "d" : file = "d-properties";	break;
	case "e" : file = "e-gear";		break;
	case "f" : file = "f-variables";	break;
	case "g" : file = "g-functions";	break;
	case "h" : file = "h-rooms";		break;
	case "i" : file = "i-misc";		break;
	case "j" : file = "j-helpinfo";		break;
	case "k" : file = "k-areas";		break;
	case "l" : file = "l-croom";		break;
	case "s" : file = "s-spells";		break;
   }
   if(file != "") {
	TP->more("/doc/help/tutorials/poster-"+file);
	return 1;
   }
   write("Sorry, that doesn't seem to be a valid choice to review.");
   return 1;
}
