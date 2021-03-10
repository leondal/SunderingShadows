inherit "/d/common/obj/armour/fullplate";

void create() {
    ::create();
    set_name("shining silver plate armour");
    set("id", ({ "plate", "fullplate", "full plate", "armour", "armor", "silver plate", "shining silver plate" }) );
    set_short("%^BOLD%^%^YELLOW%^s%^WHITE%^hinin%^YELLOW%^g %^WHITE%^s%^YELLOW%^i%^WHITE%^lv%^YELLOW%^e%^WHITE%^r plate %^RESET%^a%^WHITE%^rm%^RESET%^ou%^WHITE%^r");
    set_long("%^BOLD%^%^WHITE%^A suit of sh%^RESET%^i%^BOLD%^%^WHITE%^n%^RESET%^i"
      "%^BOLD%^%^WHITE%^ng s%^RESET%^i%^BOLD%^%^WHITE%^lver plate %^RESET%^a"
      +"%^BOLD%^%^WHITE%^rm%^RESET%^ou%^BOLD%^%^WHITE%^r, tr%^YELLOW%^i%^BOLD%^"
      +"%^WHITE%^mm%^YELLOW%^e%^BOLD%^%^WHITE%^d with %^YELLOW%^g%^RESET%^"
      +"%^ORANGE%^o%^YELLOW%^ld%^BOLD%^%^WHITE%^. Made for use in hot climes,"
      +" the plate covers the wearer's torso, upper arms and thighs to just"
      +" above the knee. This makes it light to wear, and easy to move in, but"
      +" it has %^BOLD%^%^CYAN%^enchantments %^BOLD%^%^WHITE%^that allow it to"
      +" still offer the same protection as %^RESET%^full plate%^BOLD%^%^WHITE%^."
      +" The plates that form the armour are shaped with beautifully%^CYAN%^"
      +" flowing lines%^BOLD%^%^WHITE%^ and %^BLUE%^curves%^BOLD%^%^WHITE%^,"
      +" lending an aura of awe and beauty to both the item and wearer.");
    set_item_bonus("bonus spell slots",1);
    set_item_bonus("spellcraft",2);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
    set_heart_beat(1);
    set_size(-1);

}

int wear_func(){
  string str;
  if (!objectp(ETO) || !interactive(ETO)){ 
    tell_object(TP, "You don't have that.");
    return 0;
  }
  if(member_array("%^RED%^Defeated %^RESET%^%^BLUE%^The"
    +"%^MAGENTA%^ U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt"
    +"%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d",ETO->query_mini_quests())== -1 
                                                       && !ETO->query_true_invis()) {
    tell_object(ETO,"You have not earned the right to make use of this item.");
    return 0;
  }
  if((int)ETO->query_level() < 40) {
    tell_object(ETO,"You aren't experienced enough to handle an item of this power.");
    return 0;
  }
  switch(ETO->query_alignment()){
  case 1:
  case 2:
  case 4:
  case 5:
  case 7:
  case 8:
    tell_object(ETO, "Your %^CYAN%^soul%^RESET%^ %^BOLD%^%^WHITE%^br%^YELLOW%^i"
      +"%^BOLD%^%^WHITE%^ght%^YELLOW%^e%^BOLD%^%^WHITE%^ns %^RESET%^as you strap on"
      +" the Vb%^YELLOW%^e%^BOLD%^%^WHITE%^aut%^YELLOW%^i%^BOLD%^%^WHITE%^f%^YELLOW%^"
      +"u%^BOLD%^%^WHITE%^l pl%^RESET%^a%^BOLD%^%^WHITE%^te"
      +" a%^YELLOW%^r%^BOLD%^%^WHITE%^mo%^YELLOW%^u%^BOLD%^%^WHITE%^r%^RESET%^, and"
      +" your mood is lifted. You may feel more %^CYAN%^compassionate %^RESET%^and"
      +" %^BOLD%^%^WHITE%^elevated%^RESET%^ than you did before.");
    break;
  case 3:
  case 6:
  case 9:
    tell_object("The %^BOLD%^%^WHITE%^a%^YELLOW%^r%^BOLD%^%^WHITE%^mo%^YELLOW%^u"
      +"%^BOLD%^%^WHITE%^r %^RESET%^seems to %^ORANGE%^resist%^RESET%^ you as you put"
      +" it on, and you feel it %^CYAN%^weakening%^RESET%^ your resolve and attempting"
      +" to infect your thoughts with concern for others.");
    break;
  }
}
