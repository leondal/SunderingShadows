#include <std.h>

inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("rakhoz");
    set_id(  ({"rakhoz", "barkeep" })  );
    set_short("%^RESET%^%^ORANGE%^Rakhoz");
    set("aggressive", 0);
    set_level(23);
    set_exp(10);
    set_long("%^BOLD%^%^BLACK%^Rakhoz %^RESET%^%^ORANGE%^is a short, %^RED%^rotund %^ORANGE%^dwarf with %^CYAN%^broad "
       "%^ORANGE%^shoulders, a %^WHITE%^gap-toothed smile %^ORANGE%^and a %^GREEN%^ruddy %^ORANGE%^complexion. "
       "He wears an old l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ath%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r %^BOLD%^"
       "%^BLACK%^a%^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n %^RESET%^"
       "%^ORANGE%^and gladly listens to tall tales and %^MAGENTA%^laughs %^ORANGE%^at %^CYAN%^rough jokes%^ORANGE%^. "
       "He is the %^BOLD%^%^WHITE%^identical twin %^RESET%^%^ORANGE%^brother of %^BOLD%^%^BLACK%^Rakhaz%^RESET%^"
       "%^ORANGE%^, and together they own this %^BOLD%^%^BLACK%^establishment%^RESET%^%^ORANGE%^. They take "
       "turns %^RED%^serving %^ORANGE%^as %^WHITE%^barkeep %^ORANGE%^and %^BOLD%^%^WHITE%^waiter%^RESET%^"
       "%^ORANGE%^, but it is almost %^BOLD%^%^CYAN%^impossible %^RESET%^%^ORANGE%^for the patrons to tell them apart "
       "anyway. When %^BOLD%^%^BLUE%^business %^RESET%^%^ORANGE%^is slow, they %^RED%^argue %^ORANGE%^loudly "
       "across the room about everything and everyone that takes their %^BOLD%^%^MAGENTA%^fancy%^RESET%^%^ORANGE%^.%^RESET%^");
    set_gender("male");
    set_alignment(2);
//	set_diety("grumbar");
    set_race("dwarf");

    set_hp(400);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
      ({
	"dwarven ale", "swamp water", "mystery mix", "water"
      }),
      ({ "alcoholic", "alcoholic", "alcoholic", "water" }),
      ({10, 20, 40, 1})
    );
    set_my_mess(
      ({
	"The ale soothes your nerves as it warms your stomach.\n",
	"The room suddenly fades to black and then reappears in many interesting %^BOLD%^c%^CYAN%^o%^RESET%^%^CYAN%^l%^ORANGE%^o%^BLUE%^r%^BOLD%^s.%^RESET%^\n",
	"The strange liquid sucks all the moisture from your mouth, and you pucker up like a prune.\n",
	"The water tastes a tad bitter.\n",
      })
    );
    set_your_mess(
      ({
"blinks quickly and gets wide-eyed briefly before the eyelids start drooping.\n",
       "blinks several times then stares off into space as if in another world.\n",
	"puckers up like a prune and makes many strange faces.\n",
	"takes a drink of water.\n"
      })
    );
    set_menu_short(
      ({
	"dwarven ale",
	"swamp water",
	"%^CYAN%^M%^BOLD%^y%^RED%^s%^CYAN%^t%^RESET%^%^ORANGE%^e%^BLUE%^r%^RED%^y%^RESET%^ mix",
	"A mug of water"
      })
    );
    set_menu_long(
      ({
	"A dwarven ale in a large wooden stein.\n",
	"This strange drink bubbles and gives off a strange mist.\n",
	"This drink is many differt colors, which seem to mix and seperate randomly.\n",
	"A clear and filtered water, from nearby streams.\n"
      })
    );
}
