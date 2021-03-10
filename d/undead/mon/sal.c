#include "../undead.h"
inherit BARKEEP;

void create() {
    ::create();
    set_name("Sal");
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_id(({"Sal","sal","innkeeper"}));
    set_short("Sal, the innkeeper");
    set("aggressive", 0);
    set_level(20);    
    set_long("%^RESET%^%^CYAN%^Sal is an hearty man in his late fourties.  His "
"%^ORANGE%^brown hair %^CYAN%^has begun to show signs of %^RESET%^gray %^CYAN%^"
"at the edges, and his face is worn with lines of near constant worry from many "
"decades on this island of perpetual struggle.  He carries a clean dish cloth "
"with him which he promptly wipes down tables and does his best to clean up "
"after the tired defenders of the besieged city when they come here to "
"relax.%^RESET%^");
    set_alignment(1);
    set_hp(300);
    add_money("gold", random(30));
    set_currency("silver");

    set_menu(
({ "water", "tea", "mead", "cioppino", "wild rabbit stew", "bangers and mash", "meat pie", "bread pudding" }),
({ "water", "soft drink", "alcoholic", "food", "food", "food", "food", "food" }),
({ 2, 5, 10, 10, 20, 15, 35, 25 })
    );
    
    set_my_mess(({
      "The water is sweet and cool.\n",
      "A slight bitter taste remains after the tea is gone.\n",
      "The mead is sweet, even if it is a little diluted.\n",
      "You pass through a variety of mixed seafood flavors in the soup.\n",
      "A light hint of herbs makes the rabbit stew all the more enjoyable.\n",
      "The sausages are heavily spiced, but nicely offset by the bland mash.\n",
      "The pie has a crisp shell and a hearty meat filling, though you're unsure quite what kind.\n",
      "There is enough sugar and honey to make the pudding quite enjoyable.\n",
    }));
    
    set_your_mess(({
      "drinks from the cool glass of water.\n",
      "sips at the hot tea.\n",
      "takes a swallow of the sweet mead.\n",
      "drains the last of the soup and slurps from a shellfish.\n",
      "spoons up the last of the thick stew.\n",
      "takes up the last bite of sausage with a bit of potato mash.\n",
      "scoops out the last meat from the bowl.\n",
      "eats the pudding and licks the sugary remains from their fingers.\n",
    }));

    set_menu_short(({
      "%^BOLD%^%^CYAN%^A glass of water%^RESET%^",
      "%^RESET%^%^RED%^A mug of steaming tea%^RESET%^",
      "%^RESET%^%^ORANGE%^A mug of mead%^RESET%^",
      "%^BOLD%^%^BLUE%^A bowl of seafood soup%^RESET%^",
      "%^RESET%^%^RED%^A bowl of steamy stew%^RESET%^",
      "%^RESET%^%^ORANGE%^A plate of sausages and mash%^RESET%^",
      "%^RESET%^%^RED%^A pastry-topped pot pie%^RESET%^",
      "%^BOLD%^%^WHITE%^A bowl of bread pudding%^RESET%^",
    }));

    set_menu_long(({
      "%^RESET%^%^CYAN%^A short, wide glass of %^BOLD%^clear water%^RESET%^%^CYAN%^.%^RESET%^\n",
      "%^RESET%^%^ORANGE%^The mug is warm to the touch, filled with steaming %^BOLD%^%^BLACK%^dark tea%^RESET%^%^ORANGE%^.%^RESET%^\n",
      "%^YELLOW%^Pale amber liquid %^RESET%^%^ORANGE%^swirls in this mug.  The mead has a faint but sweet scent.%^RESET%^\n",
      "%^RESET%^%^CYAN%^The bowl is filled with a steaming assortment of %^BOLD%^%^BLUE%^seafood%^RESET%^%^CYAN%^, from shellfish split open by the heat of cooking, through to pieces of flesh and shrimp.  A few %^GREEN%^herbs %^CYAN%^are scattered across the top of the broth.%^RESET%^\n",
      "%^RESET%^%^GREEN%^This bowl of thick rabbit stew is scattered with more %^ORANGE%^wild root vegetables %^GREEN%^than meat, but it smells hearty.%^RESET%^\n",
      "%^RESET%^%^ORANGE%^Heavily spiced sausages are laid across a fairly plain base of %^RESET%^mashed potatoes%^ORANGE%^, and covered in thick gravy.%^RESET%^\n",
      "%^RESET%^%^ORANGE%^This small hot bowl is filled with %^RED%^mince%^ORANGE%^, and covered by a sheet of crisp pastry.%^RESET%^\n",
      "%^RESET%^%^CYAN%^In the middle of this bowl rests a lump of rather ugly-looking food, bread mixed with raisins and sugar, spices and milk.  The honey drizzled over it smells %^BOLD%^%^MAGENTA%^sweet %^RESET%^%^CYAN%^and rather appealing.%^RESET%^\n",
    }));
}

void receive_given_item(object ob) {
    if((string)ob->query_short() == "An empty bottle" || (string)ob->query_name() == "bottle") {
      force_me("emote puts away the empty bottle.");
      ob->remove();
    }
}
